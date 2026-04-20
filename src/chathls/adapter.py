from __future__ import annotations

import json
import re
import urllib.error
import urllib.request
from dataclasses import dataclass
from typing import Any

from .config import ChatHLSConfig
from .models import HLSReport, StageResult
from .prompts import (
    build_bug_fix_agent_prompt,
    build_code_modify_prompt,
    build_debug_analysis_messages,
    build_debug_modify_messages,
    build_debug_score_messages,
    build_dse_prompt,
    build_fixer_prompt,
    build_optimize_analysis_messages,
    build_optimize_modify_messages,
    build_score_prompt,
    build_transform_messages,
)


@dataclass
class LLMAdapter:
    api_key: str
    base_url: str
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
    timeout_seconds: int = 120
    _hf_clients: dict[str, Any] | None = None

    @classmethod
    def from_config(cls, config: ChatHLSConfig) -> "LLMAdapter":
        if not config.api_key or not config.base_url:
            raise RuntimeError("Missing API configuration in config.py")
        return cls(
            api_key=config.api_key,
            base_url=config.base_url.rstrip("/"),
            analysis_backend=config.analysis_backend,
            transform_model=config.transform_model,
            debug_analysis_model=config.debug_analysis_model,
            debug_modify_model=config.debug_modify_model,
            debug_analysis_model_0=config.debug_analysis_model_0,
            debug_analysis_model_1=config.debug_analysis_model_1,
            debug_analysis_model_2=config.debug_analysis_model_2,
            debug_score_model=config.debug_score_model,
            optimize_analysis_model=config.optimize_analysis_model,
            optimize_modify_model=config.optimize_modify_model,
            timeout_seconds=min(config.timeout_seconds, 300),
        )

    def transform(self, spec_text: str, kernel_name: str, top_function: str, project_context: str) -> str:
        messages = build_transform_messages(spec_text)
        return self._extract_code(self._invoke_api(messages, self.transform_model))

    def debug(self, code: str, failure: StageResult, baseline_code: str) -> str:
        error_log = "\n".join(failure.details)
        analysis_prompt = build_bug_fix_agent_prompt(code, error_log)
        analysis_messages = build_debug_analysis_messages(analysis_prompt)
        debug_suggestion = self._invoke_analysis(analysis_messages, self.debug_analysis_model)
        modify_prompt = build_fixer_prompt(code, debug_suggestion)
        modify_messages = build_debug_modify_messages(modify_prompt)
        return self._extract_code(self._invoke_api(modify_messages, self.debug_modify_model))

    def debug_multi(self, code: str, failure: StageResult) -> str:
        error_log = "\n".join(failure.details)
        analysis_prompt = build_bug_fix_agent_prompt(code, error_log)
        analysis_messages = build_debug_analysis_messages(analysis_prompt)
        debug_suggestion_0 = self._invoke_analysis(analysis_messages, self.debug_analysis_model_0)
        debug_suggestion_1 = self._invoke_analysis(analysis_messages, self.debug_analysis_model_1)
        debug_suggestion_2 = self._invoke_analysis(analysis_messages, self.debug_analysis_model_2)
        score_prompt = build_score_prompt(code, debug_suggestion_0, debug_suggestion_1, debug_suggestion_2)
        score_messages = build_debug_score_messages(score_prompt)
        selected_debug_suggestion = self._invoke_api(score_messages, self.debug_score_model)
        modify_prompt = build_fixer_prompt(code, selected_debug_suggestion)
        modify_messages = build_debug_modify_messages(modify_prompt)
        return self._extract_code(self._invoke_api(modify_messages, self.debug_modify_model))

    def optimize(self, code: str, report: HLSReport | None) -> str:
        report_text = self._format_report(report)
        analysis_prompt = build_dse_prompt(code, report_text, "")
        analysis_messages = build_optimize_analysis_messages(analysis_prompt)
        insertion_suggestion = self._invoke_analysis(analysis_messages, self.optimize_analysis_model)
        modify_prompt = build_code_modify_prompt(code, insertion_suggestion)
        modify_messages = build_optimize_modify_messages(modify_prompt)
        return self._extract_code(self._invoke_api(modify_messages, self.optimize_modify_model))

    def _invoke_analysis(self, messages: list[dict[str, str]], model: str) -> str:
        if self.analysis_backend == "hf":
            return self._invoke_huggingface(messages, model)
        return self._invoke_api(messages, model)

    def _invoke_api(self, messages: list[dict[str, str]], model: str) -> str:
        payload = json.dumps({"model": model, "messages": messages, "temperature": 0.2}).encode("utf-8")
        request = urllib.request.Request(
            url=f"{self.base_url}/chat/completions",
            data=payload,
            headers={
                "Content-Type": "application/json",
                "Authorization": f"Bearer {self.api_key}",
            },
            method="POST",
        )
        try:
            with urllib.request.urlopen(request, timeout=self.timeout_seconds) as response:
                body = json.loads(response.read().decode("utf-8"))
        except urllib.error.HTTPError as error:
            message = error.read().decode("utf-8", errors="ignore")
            raise RuntimeError(f"LLM request failed: {message}") from error
        except urllib.error.URLError as error:
            raise RuntimeError(f"LLM request failed: {error}") from error
        choices = body.get("choices", [])
        if not choices:
            raise RuntimeError("LLM response did not contain choices")
        content = choices[0].get("message", {}).get("content")
        if not content:
            raise RuntimeError("LLM response did not contain message content")
        return content

    def _invoke_huggingface(self, messages: list[dict[str, str]], model: str) -> str:
        tokenizer, llm, torch = self._get_hf_client(model)
        prompt = tokenizer.apply_chat_template(messages, tokenize=False, add_generation_prompt=True)
        inputs = tokenizer(prompt, return_tensors="pt")
        model_device = next(llm.parameters()).device
        inputs = {key: value.to(model_device) for key, value in inputs.items()}
        generation_kwargs = {
            "max_new_tokens": 1024,
            "do_sample": True,
            "temperature": 0.2,
            "top_p": 0.95,
            "pad_token_id": tokenizer.eos_token_id,
        }
        with torch.no_grad():
            outputs = llm.generate(**inputs, **generation_kwargs)
        prompt_length = inputs["input_ids"].shape[1]
        generated_tokens = outputs[0][prompt_length:]
        content = tokenizer.decode(generated_tokens, skip_special_tokens=True).strip()
        if not content:
            raise RuntimeError("Hugging Face response did not contain message content")
        return content

    def _get_hf_client(self, model: str) -> tuple[Any, Any, Any]:
        if self._hf_clients is None:
            self._hf_clients = {}
        if model in self._hf_clients:
            return self._hf_clients[model]
        try:
            import torch
            from transformers import AutoModelForCausalLM, AutoTokenizer
        except ImportError as error:
            raise RuntimeError(
                "Hugging Face backend requires `transformers` and `torch` to be installed."
            ) from error

        tokenizer = AutoTokenizer.from_pretrained(model, trust_remote_code=True)
        if tokenizer.pad_token_id is None:
            tokenizer.pad_token = tokenizer.eos_token
        llm = AutoModelForCausalLM.from_pretrained(
            model,
            trust_remote_code=True,
            torch_dtype=torch.float16 if torch.cuda.is_available() else torch.float32,
        )
        if torch.cuda.is_available():
            llm = llm.to("cuda")
        llm.eval()
        client = (tokenizer, llm, torch)
        self._hf_clients[model] = client
        return client

    @staticmethod
    def _extract_code(content: str) -> str:
        pattern = re.compile(r"```(?:cpp|c\+\+|c)?\s*(.*?)```", re.DOTALL)
        match = pattern.search(content)
        if match:
            return match.group(1).strip() + "\n"
        return content.strip() + "\n"

    @staticmethod
    def _format_report(report: HLSReport | None) -> str:
        if report is None:
            return "No report metrics were available."
        lines: list[str] = []
        if report.latency is not None:
            lines.append(f"Latency: {report.latency}")
        for key, value in report.utilization.items():
            lines.append(f"{key}: {value:.4f}")
        for key, value in report.totals.items():
            lines.append(f"{key}: {value}")
        return "\n".join(lines) if lines else "No report metrics were available."
