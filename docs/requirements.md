# Requirements

## Python

- Python 3.10 or newer
- `pip install -e .`

The public package depends only on:

- `psutil>=5.9`

## Vitis HLS

HLS execution requires a working installation of Xilinx Vitis HLS.

Set the executable path in `src/chathls/config.py`:

```python
DEFAULT_VITIS_HLS_PATH = "/path/to/vitis_hls"
```

On Windows, this path will usually point to `vitis_hls.bat`.

## Project Template Requirements

For real validation, the target project or template should include:

- the main kernel source file
- any required headers
- a testbench
- `run_hls.tcl`
- any required test data

## Model Integration

The public release expects an OpenAI-compatible API provider.

Set the API and model values in `src/chathls/config.py`:

```python
DEFAULT_OPENAI_API_KEY = ""
DEFAULT_OPENAI_API_BASE = ""
DEFAULT_TRANSFORM_MODEL = ""
DEFAULT_DEBUG_ANALYSIS_MODEL = DEFAULT_TRANSFORM_MODEL
DEFAULT_DEBUG_MODIFY_MODEL = DEFAULT_TRANSFORM_MODEL
DEFAULT_OPTIMIZE_ANALYSIS_MODEL = DEFAULT_TRANSFORM_MODEL
DEFAULT_OPTIMIZE_MODIFY_MODEL = DEFAULT_TRANSFORM_MODEL
```

Prompt templates are stored in `src/chathls/prompts.py`.

Do not commit real credentials to the repository.
