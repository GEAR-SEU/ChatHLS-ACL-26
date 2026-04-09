from __future__ import annotations

import subprocess
import time
import xml.etree.ElementTree as element_tree
from pathlib import Path

from .config import ChatHLSConfig
from .files import normalize_path, to_display_path, to_hls_path, to_native_path
from .models import HLSReport, HLSRunResult, StageResult


class HLSRunner:
    def __init__(self, config: ChatHLSConfig) -> None:
        self.config = config

    def run(self, project_dir: Path) -> HLSRunResult:
        project_dir = normalize_path(project_dir)
        logs_dir = project_dir / "logs"
        logs_dir.mkdir(parents=True, exist_ok=True)
        log_path = logs_dir / "compilation_log.txt"
        if not self.config.vitis_hls_path:
            raise RuntimeError("Missing Vitis HLS executable path in config.py.")
        script_path = project_dir / "run_hls.tcl"
        if not script_path.exists():
            raise FileNotFoundError(f"Missing HLS script: {to_display_path(script_path)}")
        vitis_hls_path = to_hls_path(self.config.vitis_hls_path)
        hls_script_path = to_hls_path(script_path)
        with log_path.open("w", encoding="utf-8") as handle:
            process = subprocess.Popen(
                [vitis_hls_path, hls_script_path],
                cwd=to_native_path(project_dir),
                stdout=handle,
                stderr=subprocess.STDOUT,
            )
            start = time.time()
            while process.poll() is None:
                if time.time() - start > self.config.timeout_seconds:
                    process.terminate()
                    handle.write("\nTerminated\n")
                    break
                time.sleep(5)
        lines = log_path.read_text(encoding="utf-8", errors="ignore").splitlines()
        return self._build_result(project_dir, log_path, lines)

    def _build_result(self, project_dir: Path, log_path: Path, lines: list[str]) -> HLSRunResult:
        csim = self._parse_csim(lines)
        csyn = self._parse_csynth(lines)
        cosim = self._parse_cosim(lines)
        report = self._parse_report(project_dir)
        return HLSRunResult(
            project_dir=to_display_path(project_dir),
            log_path=to_display_path(log_path),
            csim=csim,
            csyn=csyn,
            cosim=cosim,
            report=report,
        )

    def _parse_csim(self, lines: list[str]) -> StageResult:
        in_csim = False
        details: list[str] = []
        passed: bool | None = None
        reason: str | None = None
        for line in lines:
            if "CSIM start" in line:
                in_csim = True
                passed = False
            elif "Finished Command csim_design" in line:
                break
            elif in_csim:
                details.append(line)
                if "CSim done with 0 errors" in line:
                    passed = True
                    reason = None
                elif "compilation error" in line:
                    reason = "Compilation error"
                elif "CSim failed with errors" in line:
                    reason = "Runtime error"
                elif "Terminated" in line:
                    reason = "Timeout"
        return StageResult(name="csim", passed=passed, reason=reason, details=details)

    def _parse_csynth(self, lines: list[str]) -> StageResult:
        in_csynth = False
        details: list[str] = []
        passed: bool | None = None
        reason: str | None = None
        rtl_generated = False
        fmax_estimated = False
        for line in lines:
            if "Running: csynth_design" in line:
                in_csynth = True
                passed = False
            elif "Finished Command csynth_design" in line and in_csynth:
                passed = rtl_generated and fmax_estimated
                if not passed and reason is None:
                    reason = "Synthesis failed"
                break
            elif in_csynth:
                details.append(line)
                if "Generating Verilog RTL for" in line:
                    rtl_generated = True
                if "Estimated Fmax:" in line:
                    fmax_estimated = True
                if "Top Function" in line and "not found" in line:
                    reason = "Top function not found"
                elif "ERROR" in line and reason is None:
                    reason = "Synthesis failed"
                elif "Terminated" in line:
                    reason = "Timeout"
        return StageResult(name="csyn", passed=passed, reason=reason, details=details)

    def _parse_cosim(self, lines: list[str]) -> StageResult:
        in_cosim = False
        details: list[str] = []
        passed: bool | None = None
        reason: str | None = None
        for line in lines:
            if "Running: cosim_design" in line:
                in_cosim = True
                passed = False
            elif "Finished Command cosim_design" in line and in_cosim:
                if passed is False and reason is None:
                    reason = "Co-simulation failed"
                break
            elif in_cosim:
                details.append(line)
                if "C/RTL co-simulation finished: PASS" in line:
                    passed = True
                    reason = None
                elif "C/RTL co-simulation finished: FAIL" in line:
                    reason = "Co-simulation failed"
                elif "Terminated" in line:
                    reason = "Timeout"
        return StageResult(name="cosim", passed=passed, reason=reason, details=details)

    def _parse_report(self, project_dir: Path) -> HLSReport:
        project_dir = normalize_path(project_dir)
        xml_candidates = list(project_dir.glob("**/*_csynth.xml"))
        if not xml_candidates:
            return HLSReport()
        xml_path = xml_candidates[0]
        try:
            root = element_tree.parse(xml_path).getroot()
        except element_tree.ParseError:
            return HLSReport()
        latency = None
        resources: dict[str, int] = {}
        available: dict[str, int] = {}
        for perf_est in root.findall("PerformanceEstimates"):
            for latency_block in perf_est.findall("SummaryOfOverallLatency"):
                for child in latency_block:
                    if "Best-caseLatency" in child.tag:
                        latency = int(child.text)
        for area_est in root.findall("AreaEstimates"):
            for resource_block in area_est.findall("Resources"):
                for child in resource_block:
                    resources[child.tag] = int(child.text)
            for available_block in area_est.findall("AvailableResources"):
                for child in available_block:
                    available[child.tag] = int(child.text)
        utilization: dict[str, float] = {}
        for name, total in resources.items():
            capacity = available.get(name)
            if capacity:
                utilization[name] = total / capacity
        return HLSReport(latency=latency, utilization=utilization, totals=resources)
