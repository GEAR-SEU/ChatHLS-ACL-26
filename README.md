# ChatHLS: Towards Systematic Design Automation and Optimization for High-Level Synthesis

[![arXiv](https://img.shields.io/badge/arXiv-2507.00642-b31b1b.svg)](https://arxiv.org/abs/2507.00642)

ChatHLS is an open-source workflow for transforming a source C/C++ project or natural-language HLS specification into optimized HLS-C through a LLM-driven pipeline:

`transform -> CSIM -> CSYN -> COSIM -> debug on failure -> optimize -> debug on optimization failure`

When the first debug repair still fails validation, ChatHLS escalates to a multi-end debug evaluation path that runs multiple analysis agents, scores their suggestions, and then applies the selected repair.

This repository is the public release for the ACL 2026 main conference paper *ChatHLS: Towards Systematic Design Automation and Optimization for High-Level Synthesis*.

## Models

The fine-tuned model weights for ChatHLS are available on Hugging Face: [**HLSFixer**](https://huggingface.co/XXXiong/ChatHLS-HLSFixer), [**HLSTuner**](https://huggingface.co/XXXiong/ChatHLS-HLSTuner).

## Configuration

Edit these defaults there before running ChatHLS:

- `DEFAULT_OPENAI_API_KEY`
- `DEFAULT_OPENAI_API_BASE`
- `DEFAULT_VITIS_HLS_PATH`
- `DEFAULT_TRANSFORM_MODEL`
- `DEFAULT_DEBUG_ANALYSIS_MODEL`
- `DEFAULT_DEBUG_MODIFY_MODEL`
- `DEFAULT_OPTIMIZE_ANALYSIS_MODEL`
- `DEFAULT_OPTIMIZE_MODIFY_MODEL`

## Quickstart

Install dependencies first:

```bash
pip install -r requirements.txt
```

Run the workflow on a C/C++ project with the default API-based analysis backend:

```bash
run_chathls.sh \
  --repo-root . \
  --project-dir examples/projects/vector_mul \
  --kernel-name vector_mul \
  --top-function vector_mul \
  --source-file vector_mul.cpp
```

Run the workflow on a C/C++ project with Hugging Face analysis models:

```bash
run_chathls.sh \
  --repo-root . \
  --analysis-backend hf \
  --project-dir examples/projects/vector_mul \
  --kernel-name vector_mul \
  --top-function vector_mul \
  --source-file vector_mul.cpp
```

Run the workflow from a natural-language specification:

```bash
run_chathls.sh \
  --repo-root . \
  --spec-file examples/specs/wire_assign.md \
  --template-dir examples/projects/wire_assign \
  --kernel-name wire_assign \
  --top-function wire_assign \
  --source-file wire_assign.cpp
```

Run the workflow from a natural-language specification with Hugging Face analysis models:

```bash
run_chathls.sh \
  --repo-root . \
  --analysis-backend hf \
  --spec-file examples/specs/wire_assign.md \
  --template-dir examples/projects/wire_assign \
  --kernel-name wire_assign \
  --top-function wire_assign \
  --source-file wire_assign.cpp
```

On Windows, run the batch wrapper instead. The wrapper always launches `chathls workflow`, so pass workflow arguments directly:

```bat
run_chathls.bat --repo-root . --project-dir examples/projects/vector_mul --kernel-name vector_mul --top-function vector_mul --source-file vector_mul.cpp
```

To enable Hugging Face analysis models on Windows:

```bat
run_chathls.bat --repo-root . --analysis-backend hf --project-dir examples/projects/vector_mul --kernel-name vector_mul --top-function vector_mul --source-file vector_mul.cpp
```

## CLI Commands

- `chathls workflow`
- `chathls transform`
- `chathls run-hls`
- `chathls debug`
- `chathls optimize`

## Outputs

Each workflow run creates a timestamped directory under `runs/` with:

## Requirements

See [Requirements](requirements.md) for the full software setup.

## Workflow

See [Workflow](workflow.md) for the execution flow and artifact layout.

## License

This repository is released under the Apache License 2.0. See [LICENSE](LICENSE).
