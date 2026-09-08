#!/usr/bin/env python3
"""Run a saved learned policy on one List Nat; invalid models use proved fallback."""

import argparse
import json
from pathlib import Path
import tempfile

from data import FEATURE_NAMES
from run import Worker


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--model", type=Path, required=True)
    parser.add_argument("--input", required=True, help="JSON array of natural numbers")
    args = parser.parse_args()
    xs = json.loads(args.input)
    if not isinstance(xs, list) or not all(type(x) is int and x >= 0 for x in xs):
        parser.error("input must be a JSON array of natural numbers")
    try:
        model = json.loads(args.model.read_text())
    except (OSError, ValueError):
        model = None
    with tempfile.TemporaryDirectory(prefix="leansort-infer-") as directory:
        worker = Worker(Path(directory) / "worker.log")
        try:
            status = worker.request({"cmd": "configure", "model": model})
            result = worker.request({"cmd": "predict", "input": xs})
            assert result["output"] == sorted(xs)
            result["features"] = dict(zip(FEATURE_NAMES, result["features"]))
            result["model_status"] = status
            print(json.dumps(result, indent=2))
        finally:
            worker.close()


if __name__ == "__main__":
    main()
