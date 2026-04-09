from __future__ import annotations

from pathlib import Path

from .adapter import LLMAdapter
from .files import copy_tree, normalize_path, read_text, to_display_path, write_json, write_text
from .models import TransformInput


class Transformer:
    def __init__(self, adapter: LLMAdapter) -> None:
        self.adapter = adapter

    def prepare_project(self, transform_input: TransformInput, run_dir: Path) -> Path:
        project_dir = normalize_path(run_dir / "project")
        if transform_input.mode == "project":
            if transform_input.project_dir is None:
                raise ValueError("project mode requires a project directory")
            copy_tree(normalize_path(transform_input.project_dir), project_dir)
            write_json(
                run_dir / "artifacts" / "transform.json",
                {
                    "mode": "project",
                    "project_dir": to_display_path(transform_input.project_dir),
                    "copied_to": to_display_path(project_dir),
                },
            )
            return project_dir
        if transform_input.template_dir is None or transform_input.spec_path is None:
            raise ValueError("spec mode requires a template directory and spec path")
        copy_tree(normalize_path(transform_input.template_dir), project_dir)
        spec_text = read_text(normalize_path(transform_input.spec_path))
        project_context = self._build_project_context(project_dir, transform_input.source_file)
        generated = self.adapter.transform(
            spec_text=spec_text,
            kernel_name=transform_input.kernel_name,
            top_function=transform_input.top_function,
            project_context=project_context,
        )
        source_path = project_dir / transform_input.source_file
        write_text(source_path, generated)
        write_json(
            run_dir / "artifacts" / "transform.json",
            {
                "mode": "spec",
                "spec_path": to_display_path(transform_input.spec_path),
                "template_dir": to_display_path(transform_input.template_dir),
                "generated_source": to_display_path(source_path),
            },
        )
        return project_dir

    @staticmethod
    def _build_project_context(project_dir: Path, source_file: str) -> str:
        context_blocks: list[str] = []
        for path in sorted(project_dir.iterdir()):
            if not path.is_file():
                continue
            if path.name == source_file:
                continue
            if path.suffix.lower() not in {".h", ".hpp", ".cpp", ".cc", ".c", ".tcl", ".md", ".txt"}:
                continue
            text = read_text(path)
            context_blocks.append(f"File: {path.name}\n{text}")
        return "\n\n".join(context_blocks)
