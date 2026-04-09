from __future__ import annotations

import json
import os
import shutil
from datetime import datetime
from pathlib import Path


def read_text(path: Path) -> str:
    return path.read_text(encoding="utf-8")


def write_text(path: Path, content: str) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(content, encoding="utf-8")


def write_json(path: Path, payload: dict) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(payload, indent=2), encoding="utf-8")


def copy_tree(source: Path, target: Path) -> None:
    if target.exists():
        shutil.rmtree(target)
    shutil.copytree(source, target)


def make_run_dir(base_dir: Path, run_name: str | None) -> Path:
    stamp = datetime.utcnow().strftime("%Y%m%d-%H%M%S")
    safe_name = run_name or "run"
    path = base_dir / f"{safe_name}-{stamp}"
    path.mkdir(parents=True, exist_ok=False)
    return path


def normalize_path(path: Path | str) -> Path:
    return Path(path).expanduser().resolve()


def to_hls_path(path: Path | str) -> str:
    return normalize_path(path).as_posix()


def to_display_path(path: Path | str) -> str:
    return normalize_path(path).as_posix()


def to_native_path(path: Path | str) -> str:
    return os.fspath(normalize_path(path))
