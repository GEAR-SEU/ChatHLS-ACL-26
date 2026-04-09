from __future__ import annotations

from pathlib import Path

from .adapter import LLMAdapter
from .files import read_text, write_text


class Optimizer:
    def __init__(self, adapter: LLMAdapter) -> None:
        self.adapter = adapter

    def apply(self, source_path: Path, report=None) -> str:
        source = read_text(source_path)
        optimized = self.adapter.optimize(source, report=report)
        write_text(source_path, optimized)
        return optimized
