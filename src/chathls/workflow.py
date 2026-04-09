from __future__ import annotations

from pathlib import Path

from .adapter import LLMAdapter
from .config import ChatHLSConfig
from .debug import Debugger
from .files import make_run_dir, normalize_path, read_text, to_display_path, write_json, write_text
from .models import HLSRunResult, TransformInput, WorkflowSummary
from .optimize import Optimizer
from .runner import HLSRunner
from .transform import Transformer


class ChatHLSWorkflow:
    def __init__(self, config: ChatHLSConfig) -> None:
        adapter = LLMAdapter.from_config(config)
        self.config = config
        self.transformer = Transformer(adapter)
        self.debugger = Debugger(adapter)
        self.optimizer = Optimizer(adapter)
        self.runner = HLSRunner(config)

    def run(self, transform_input: TransformInput, run_name: str | None = None) -> WorkflowSummary:
        run_dir = normalize_path(make_run_dir(self.config.runs_dir, run_name))
        project_dir = self.transformer.prepare_project(transform_input, run_dir)
        source_path = project_dir / transform_input.source_file
        baseline_code = read_text(source_path)
        validation_attempts = 0
        optimization_rounds = 0
        validation_result: HLSRunResult | None = None
        for attempt in range(self.config.max_debug_attempts + 1):
            validation_attempts = attempt + 1
            validation_result = self.runner.run(project_dir)
            write_json(run_dir / "artifacts" / f"validation-attempt-{attempt + 1}.json", validation_result.to_dict())
            if validation_result.passed:
                break
            if attempt == self.config.max_debug_attempts:
                return self._finalize(
                    run_dir=run_dir,
                    project_dir=project_dir,
                    source_path=source_path,
                    transform_input=transform_input,
                    validation_attempts=validation_attempts,
                    optimization_rounds=optimization_rounds,
                    validation_result=validation_result,
                    passed_optimization=False,
                )
            use_multi_evaluation = attempt >= 1
            repaired = self.debugger.repair(
                source_path,
                validation_result,
                baseline_code,
                use_multi_evaluation=use_multi_evaluation,
            )
            write_text(run_dir / "artifacts" / f"debug-attempt-{attempt + 1}.cpp", repaired)
        assert validation_result is not None
        last_passing_code = read_text(source_path)
        optimization_result = validation_result
        passed_optimization = True
        for round_index in range(self.config.max_optimization_rounds):
            optimization_rounds = round_index + 1
            optimized = self.optimizer.apply(source_path, validation_result.report)
            write_text(run_dir / "artifacts" / f"optimization-round-{round_index + 1}.cpp", optimized)
            optimization_result = self.runner.run(project_dir)
            write_json(run_dir / "artifacts" / f"optimization-round-{round_index + 1}.json", optimization_result.to_dict())
            if optimization_result.passed:
                last_passing_code = read_text(source_path)
                continue
            passed_optimization = False
            for debug_index in range(self.config.max_debug_attempts):
                use_multi_evaluation = debug_index >= 1
                repaired = self.debugger.repair(
                    source_path,
                    optimization_result,
                    last_passing_code,
                    use_multi_evaluation=use_multi_evaluation,
                )
                write_text(
                    run_dir / "artifacts" / f"optimization-debug-round-{round_index + 1}-{debug_index + 1}.cpp",
                    repaired,
                )
                optimization_result = self.runner.run(project_dir)
                write_json(
                    run_dir / "artifacts" / f"optimization-debug-round-{round_index + 1}-{debug_index + 1}.json",
                    optimization_result.to_dict(),
                )
                if optimization_result.passed:
                    passed_optimization = True
                    last_passing_code = read_text(source_path)
                    break
            if not passed_optimization:
                write_text(source_path, last_passing_code)
                optimization_result = self.runner.run(project_dir)
                break
        return self._finalize(
            run_dir=run_dir,
            project_dir=project_dir,
            source_path=source_path,
            transform_input=transform_input,
            validation_attempts=validation_attempts,
            optimization_rounds=optimization_rounds,
            validation_result=optimization_result,
            passed_optimization=passed_optimization,
        )

    def _finalize(
        self,
        *,
        run_dir: Path,
        project_dir: Path,
        source_path: Path,
        transform_input: TransformInput,
        validation_attempts: int,
        optimization_rounds: int,
        validation_result: HLSRunResult | None,
        passed_optimization: bool,
    ) -> WorkflowSummary:
        summary = WorkflowSummary(
            run_dir=to_display_path(run_dir),
            project_dir=to_display_path(project_dir),
            source_path=to_display_path(source_path),
            transform_mode=transform_input.mode,
            validation_attempts=validation_attempts,
            optimization_rounds=optimization_rounds,
            passed_validation=bool(validation_result and validation_result.passed),
            passed_optimization=passed_optimization and bool(validation_result and validation_result.passed),
            final_result=validation_result,
        )
        write_json(run_dir / "summary.json", summary.to_dict())
        return summary
