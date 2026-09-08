"""Deterministic CPU-only corpora; split identity is part of every seed."""

import hashlib
import json
import random

FEATURE_NAMES = ["length", "descent_permille", "ascending_runs",
                 "adjacent_equal_permille", "value_range", "prefix_duplicate_permille"]
CANDIDATES = ["merge", "insertion", "hybrid-1", "hybrid-8", "hybrid-24", "hybrid-64"]


def digest(value):
    return hashlib.sha256(json.dumps(value, sort_keys=True, separators=(",", ":")).encode()).hexdigest()


def plan(name):
    if name in ("merge", "insertion"):
        return {"kind": name}
    if name in CANDIDATES:
        return {"kind": "hybrid", "threshold": int(name.split("-")[1])}
    raise ValueError("unknown candidate: " + name)


def plan_name(p):
    return "hybrid-" + str(p["threshold"]) if p["kind"] == "hybrid" else p["kind"]


def shape(family, n, rng):
    if family == "sorted":
        xs = list(range(n))
    elif family == "reverse":
        xs = list(reversed(range(n)))
    elif family == "nearly_sorted":
        xs = list(range(n))
        for _ in range(max(1, n // 32)):
            i = rng.randrange(max(1, n - 1))
            if i + 1 < n:
                xs[i], xs[i + 1] = xs[i + 1], xs[i]
    elif family == "random":
        xs = [rng.randrange(4 * n + 7) for _ in range(n)]
    elif family == "duplicates":
        cardinality = rng.randrange(2, 9)
        xs = [rng.randrange(cardinality) for _ in range(n)]
    elif family == "runs":
        xs = []
        while len(xs) < n:
            width = min(n - len(xs), rng.randrange(1, max(2, n // 3)))
            xs.extend(sorted(rng.randrange(4 * n + 7) for _ in range(width)))
    elif family == "organ_pipe":
        xs = [min(i, n - 1 - i) for i in range(n)]
    elif family == "skewed":
        xs = [rng.randrange(8) if rng.random() < 0.9 else rng.randrange(n * 64 + 1)
              for _ in range(n)]
    else:
        raise ValueError(family)
    offset, scale = rng.randrange(1000000), rng.randrange(1, 5)
    return [offset + scale * x for x in xs]


def generate(config, split, seed):
    if split not in ("train", "test"):
        raise ValueError("invalid split")
    if set(config["train_lengths"]) & set(config["test_lengths"]):
        raise ValueError("training/test lengths must be disjoint")
    rows, seen = [], set()
    for n in config[split + "_lengths"]:
        for family in config["families"]:
            for index in range(config[split + "_seeds_per_shape"]):
                key = ["adaptive-v1", split, seed, n, family, index]
                case_seed = int(digest(key)[:16], 16)
                xs = shape(family, n, random.Random(case_seed))
                fingerprint = digest(xs)
                if fingerprint in seen:
                    raise ValueError("duplicate generated input; refusing silent reweighting")
                seen.add(fingerprint)
                rows.append(dict(split=split, case_id=digest(key), family=family,
                                 seed=case_seed, length=n, input=xs, input_sha256=fingerprint))
    random.Random(int(digest([split, seed, "order"])[:16], 16)).shuffle(rows)
    return rows


def reference_features(xs):
    """Independent Python check of the Lean feature implementation, never timed."""
    n = len(xs)
    down = sum(a > b for a, b in zip(xs, xs[1:]))
    equal = sum(a == b for a, b in zip(xs, xs[1:]))
    prefix = xs[:32]
    return [n, 1000 * down // max(1, n - 1), down + 1 if n else 0,
            1000 * equal // max(1, n - 1), max(xs) - min(xs) if n else 0,
            1000 * (len(prefix) - len(set(prefix))) // max(1, len(prefix))]
