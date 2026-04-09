from __future__ import annotations

from dataclasses import asdict, dataclass, field
from pathlib import Path
from typing import Any


@dataclass
class StageResult:
    name: str
    passed: bool | None
    reason: str | None = None
    details: list[str] = field(default_factory=list)

    def to_dict(self) -> dict[str, Any]:
        return asdict(self)


@dataclass
class HLSReport:
    latency: int | None = None
    utilization: dict[str, float] = field(default_factory=dict)
    totals: dict[str, int] = field(default_factory=dict)

    def to_dict(self) -> dict[str, Any]:
        return asdict(self)


@dataclass
class HLSRunResult:
    project_dir: str
    log_path: str
    csim: StageResult
    csyn: StageResult
    cosim: StageResult
    report: HLSReport = field(default_factory=HLSReport)

    @property
    def passed(self) -> bool:
        return bool(self.csim.passed and self.csyn.passed and self.cosim.passed)

    @property
    def failing_stage(self) -> StageResult | None:
        for stage in (self.csim, self.csyn, self.cosim):
            if stage.passed is False:
                return stage
        return None

    def to_dict(self) -> dict[str, Any]:
        return {
            "project_dir": self.project_dir,
            "log_path": self.log_path,
            "passed": self.passed,
            "failing_stage": self.failing_stage.name if self.failing_stage else None,
            "csim": self.csim.to_dict(),
            "csyn": self.csyn.to_dict(),
            "cosim": self.cosim.to_dict(),
            "report": self.report.to_dict(),
        }


@dataclass
class TransformInput:
    mode: str
    project_dir: Path | None
    spec_path: Path | None
    template_dir: Path | None
    kernel_name: str
    top_function: str
    source_file: str


@dataclass
class WorkflowSummary:
    run_dir: str
    project_dir: str
    source_path: str
    transform_mode: str
    validation_attempts: int
    optimization_rounds: int
    passed_validation: bool
    passed_optimization: bool
    final_result: HLSRunResult | None

    def to_dict(self) -> dict[str, Any]:
        data = asdict(self)
        if self.final_result is not None:
            data["final_result"] = self.final_result.to_dict()
        return data
