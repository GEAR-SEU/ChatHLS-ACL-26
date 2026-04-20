from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path

DEFAULT_OPENAI_API_KEY = ""
DEFAULT_OPENAI_API_BASE = ""
DEFAULT_VITIS_HLS_PATH = ""
DEFAULT_TRANSFORM_MODEL = "deepseek-v3.2"
DEFAULT_DEBUG_ANALYSIS_MODEL = "XXXiong/ChatHLS-HLSFixer"
DEFAULT_DEBUG_MODIFY_MODEL = DEFAULT_TRANSFORM_MODEL
DEFAULT_DEBUG_ANALYSIS_MODEL_0 = DEFAULT_DEBUG_ANALYSIS_MODEL
DEFAULT_DEBUG_ANALYSIS_MODEL_1 = DEFAULT_DEBUG_ANALYSIS_MODEL
DEFAULT_DEBUG_ANALYSIS_MODEL_2 = DEFAULT_DEBUG_ANALYSIS_MODEL
DEFAULT_DEBUG_SCORE_MODEL = DEFAULT_TRANSFORM_MODEL
DEFAULT_OPTIMIZE_ANALYSIS_MODEL = "XXXiong/ChatHLS-HLSTuner"
DEFAULT_OPTIMIZE_MODIFY_MODEL = DEFAULT_TRANSFORM_MODEL


@dataclass
class ChatHLSConfig:
    repo_root: Path
    runs_dir: Path
    api_key: str
    base_url: str
    vitis_hls_path: str | None
    timeout_seconds: int
    max_debug_attempts: int
    max_optimization_rounds: int
    adapter_name: str
    analysis_backend: str
    transform_model: str
    debug_analysis_model: str
    debug_modify_model: str
    debug_analysis_model_0: str
    debug_analysis_model_1: str
    debug_analysis_model_2: str
    debug_score_model: str
    optimize_analysis_model: str
    optimize_modify_model: str

    @classmethod
    def from_repo_root(
        cls,
        repo_root: Path,
        *,
        timeout_seconds: int = 1800,
        max_debug_attempts: int = 2,
        max_optimization_rounds: int = 1,
        adapter_name: str = "openai-compatible",
        analysis_backend: str = "api",
        api_key: str = DEFAULT_OPENAI_API_KEY,
        base_url: str = DEFAULT_OPENAI_API_BASE,
        transform_model: str = DEFAULT_TRANSFORM_MODEL,
        debug_analysis_model: str = DEFAULT_DEBUG_ANALYSIS_MODEL,
        debug_modify_model: str = DEFAULT_DEBUG_MODIFY_MODEL,
        debug_analysis_model_0: str = DEFAULT_DEBUG_ANALYSIS_MODEL_0,
        debug_analysis_model_1: str = DEFAULT_DEBUG_ANALYSIS_MODEL_1,
        debug_analysis_model_2: str = DEFAULT_DEBUG_ANALYSIS_MODEL_2,
        debug_score_model: str = DEFAULT_DEBUG_SCORE_MODEL,
        optimize_analysis_model: str = DEFAULT_OPTIMIZE_ANALYSIS_MODEL,
        optimize_modify_model: str = DEFAULT_OPTIMIZE_MODIFY_MODEL,
    ) -> "ChatHLSConfig":
        runs_dir = repo_root / "runs"
        return cls(
            repo_root=repo_root,
            runs_dir=runs_dir,
            api_key=api_key,
            base_url=base_url.rstrip("/"),
            vitis_hls_path=DEFAULT_VITIS_HLS_PATH,
            timeout_seconds=timeout_seconds,
            max_debug_attempts=max_debug_attempts,
            max_optimization_rounds=max_optimization_rounds,
            adapter_name=adapter_name,
            analysis_backend=analysis_backend,
            transform_model=transform_model,
            debug_analysis_model=debug_analysis_model,
            debug_modify_model=debug_modify_model,
            debug_analysis_model_0=debug_analysis_model_0,
            debug_analysis_model_1=debug_analysis_model_1,
            debug_analysis_model_2=debug_analysis_model_2,
            debug_score_model=debug_score_model,
            optimize_analysis_model=optimize_analysis_model,
            optimize_modify_model=optimize_modify_model,
        )
