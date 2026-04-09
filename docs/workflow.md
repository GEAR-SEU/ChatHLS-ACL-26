# Workflow

## End-to-End Flow

ChatHLS executes the following loop:

1. Transform input into an HLS project.
2. Run `CSIM`.
3. Run `CSYN`.
4. Run `COSIM`.
5. If any stage fails, enter debug and retry within the configured limit.
6. If the first debug repair still fails, escalate to multi-end debug evaluation with multiple analysis agents and a scoring agent before the next repair.
7. After a full pass, apply optimization.
8. Re-run validation after optimization.
9. If optimization introduces a failure, enter debug and retry.
10. If optimization cannot be repaired, restore the last passing design.

## Input Modes

### Existing Project Mode

Use this when you already have an HLS project directory with at least:

- a source file
- a testbench
- `run_hls.tcl`

The workflow copies the project into a new run directory and uses that copy for all subsequent edits.

### Specification Mode

Use this when you have a natural-language specification and a project template.

The template should contain:

- headers
- testbench
- `run_hls.tcl`
- any required data files

The transform step generates the primary source file inside the copied template.

## Artifact Layout

Each run creates:

- `runs/<name>-<timestamp>/project/`
- `runs/<name>-<timestamp>/artifacts/`
- `runs/<name>-<timestamp>/summary.json`

The `artifacts/` directory stores:

- transform metadata
- validation results for each attempt
- repaired source snapshots
- optimization snapshots
- optimization debug snapshots

## Model-Driven Steps

The transform, debug, and optimization stages are LLM-driven.

- Prompt construction is defined in `src/chathls/prompts.py`.
- API calls are handled in `src/chathls/adapter.py`.
- Workflow orchestration is handled in `src/chathls/workflow.py`.

## HLS Execution

Set `--vitis-hls` or `CHATHLS_VITIS_HLS` to a valid executable path.
