from __future__ import annotations

import argparse
import json
from pathlib import Path

from .adapter import LLMAdapter
from .config import ChatHLSConfig
from .debug import Debugger
from .files import read_text, write_json, write_text
from .models import HLSRunResult, StageResult, TransformInput
from .optimize import Optimizer
from .runner import HLSRunner
from .transform import Transformer
from .workflow import ChatHLSWorkflow


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(prog="chathls")
    parser.add_argument("--repo-root", default=".", help="Repository root")
    parser.add_argument("--timeout", type=int, default=1800, help="HLS timeout in seconds")
    parser.add_argument("--max-debug-attempts", type=int, default=2, help="Maximum debug attempts")
    parser.add_argument("--max-optimization-rounds", type=int, default=2, help="Maximum optimization rounds")
    subparsers = parser.add_subparsers(dest="command", required=True)

    transform_parser = subparsers.add_parser("transform")
    _add_input_arguments(transform_parser)
    transform_parser.add_argument("--run-name", default="transform", help="Run directory prefix")

    run_parser = subparsers.add_parser("run-hls")
    run_parser.add_argument("--project-dir", required=True, help="Project directory containing run_hls.tcl")

    debug_parser = subparsers.add_parser("debug")
    debug_parser.add_argument("--source-file", required=True, help="Source file to repair")
    debug_parser.add_argument("--failure-stage", required=True, choices=["csim", "csyn", "cosim"])
    debug_parser.add_argument("--failure-reason", default="Manual debug", help="Failure reason")
    debug_parser.add_argument("--baseline-file", required=True, help="Baseline source file")

    optimize_parser = subparsers.add_parser("optimize")
    optimize_parser.add_argument("--source-file", required=True, help="Source file to optimize")

    workflow_parser = subparsers.add_parser("workflow")
    _add_input_arguments(workflow_parser)
    workflow_parser.add_argument("--run-name", default="workflow", help="Run directory prefix")
    return parser


def _add_input_arguments(parser: argparse.ArgumentParser) -> None:
    parser.add_argument("--project-dir", help="Existing HLS project directory")
    parser.add_argument("--spec-file", help="Natural language specification file")
    parser.add_argument("--template-dir", help="Template project directory for spec mode")
    parser.add_argument("--kernel-name", required=True, help="Kernel name")
    parser.add_argument("--top-function", required=True, help="Top function name")
    parser.add_argument("--source-file", required=True, help="Primary source file inside the project")


def _config_from_args(args: argparse.Namespace) -> ChatHLSConfig:
    return ChatHLSConfig.from_repo_root(
        Path(args.repo_root).resolve(),
        timeout_seconds=args.timeout,
        max_debug_attempts=args.max_debug_attempts,
        max_optimization_rounds=args.max_optimization_rounds,
    )


def _transform_input_from_args(args: argparse.Namespace) -> TransformInput:
    if args.project_dir:
        return TransformInput(
            mode="project",
            project_dir=Path(args.project_dir).resolve(),
            spec_path=None,
            template_dir=None,
            kernel_name=args.kernel_name,
            top_function=args.top_function,
            source_file=args.source_file,
        )
    if not args.spec_file or not args.template_dir:
        raise SystemExit("spec mode requires --spec-file and --template-dir")
    return TransformInput(
        mode="spec",
        project_dir=None,
        spec_path=Path(args.spec_file).resolve(),
        template_dir=Path(args.template_dir).resolve(),
        kernel_name=args.kernel_name,
        top_function=args.top_function,
        source_file=args.source_file,
    )


def main() -> None:
    parser = build_parser()
    args = parser.parse_args()
    config = _config_from_args(args)
    if args.command == "transform":
        adapter = LLMAdapter.from_config(config)
        transformer = Transformer(adapter)
        run_dir = config.runs_dir / args.run_name
        run_dir.mkdir(parents=True, exist_ok=True)
        project_dir = transformer.prepare_project(_transform_input_from_args(args), run_dir)
        print(json.dumps({"project_dir": str(project_dir)}, indent=2))
        return
    if args.command == "run-hls":
        result = HLSRunner(config).run(Path(args.project_dir).resolve())
        print(json.dumps(result.to_dict(), indent=2))
        return
    if args.command == "debug":
        adapter = LLMAdapter.from_config(config)
        source_path = Path(args.source_file).resolve()
        baseline_path = Path(args.baseline_file).resolve()
        run_result = HLSRunResult(
            project_dir=str(source_path.parent),
            log_path="manual",
            csim=StageResult("csim", True),
            csyn=StageResult("csyn", True),
            cosim=StageResult("cosim", True),
        )
        if args.failure_stage == "csim":
            run_result.csim = StageResult("csim", False, args.failure_reason, [])
        elif args.failure_stage == "csyn":
            run_result.csyn = StageResult("csyn", False, args.failure_reason, [])
        else:
            run_result.cosim = StageResult("cosim", False, args.failure_reason, [])
        repaired = Debugger(adapter).repair(source_path, run_result, read_text(baseline_path))
        write_json(source_path.parent / "debug_result.json", {"source_file": str(source_path), "repaired": True})
        print(repaired)
        return
    if args.command == "optimize":
        adapter = LLMAdapter.from_config(config)
        source_path = Path(args.source_file).resolve()
        optimized = Optimizer(adapter).apply(source_path, report=None)
        write_text(source_path, optimized)
        print(optimized)
        return
    if args.command == "workflow":
        summary = ChatHLSWorkflow(config).run(_transform_input_from_args(args), run_name=args.run_name)
        print(json.dumps(summary.to_dict(), indent=2))
        return


if __name__ == "__main__":
    main()
