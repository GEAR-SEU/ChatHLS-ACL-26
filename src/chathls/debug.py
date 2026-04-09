from __future__ import annotations

from pathlib import Path

from .adapter import LLMAdapter
from .files import read_text, write_text
from .models import HLSRunResult


class Debugger:
    def __init__(self, adapter: LLMAdapter) -> None:
        self.adapter = adapter

    def repair(self, source_path: Path, run_result: HLSRunResult, baseline_code: str, use_multi_evaluation: bool = False) -> str:
        code = read_text(source_path)
        failing_stage = run_result.failing_stage
        if failing_stage is None:
            return code
        if use_multi_evaluation:
            repaired = self.adapter.debug_multi(code=code, failure=failing_stage)
        else:
            repaired = self.adapter.debug(code=code, failure=failing_stage, baseline_code=baseline_code)
        write_text(source_path, repaired)
        return repaired
