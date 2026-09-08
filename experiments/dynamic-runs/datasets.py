"""Frozen synthetic protocol; boundary/shape labels are NEVER sent to Lean."""
import hashlib
import random

SHAPES = ("random", "sorted", "reverse", "duplicates", "unequal_runs",
          "random_boundaries", "short_runs", "long_runs", "perturbed", "skewed_runs")
THRESHOLDS = (1, 4, 8, 16, 24, 64)
TEST_STRATEGIES = ("merge", "frozen_hybrid", "fixed_two", "fixed_three", "fixed_four", "runs_count", "runs_length")


def random_sizes(n, rng, lo, hi):
    out = []
    while n:
        k = min(n, rng.randint(lo, hi))
        out.append(k)
        n -= k
    return out


def sorted_chunks(values, sizes):
    out, at = [], 0
    for size in sizes:
        out.extend(sorted(values[at:at+size]))
        at += size
    assert at == len(values)
    return out


def make(shape, n, rng):
    values = [rng.randrange(max(1, 16 * n)) for _ in range(n)]
    if shape == "random":
        return values
    if shape == "sorted":
        return sorted(values)
    if shape == "reverse":
        # Strictly decreasing, so an ascending-only detector finds n runs.
        offset = rng.randrange(100000)
        return [offset + n - k for k in range(n)]
    if shape == "duplicates":
        return [rng.randrange(5) for _ in range(n)]
    if shape == "perturbed":
        values.sort()
        for _ in range(max(1, n // 25)):
            a, b = rng.randrange(n), rng.randrange(n)
            values[a], values[b] = values[b], values[a]
        return values
    if shape == "short_runs":
        sizes = random_sizes(n, rng, 1, 4)
    elif shape == "long_runs":
        sizes = random_sizes(n, rng, max(2, n // 4), max(3, n // 2))
    elif shape == "unequal_runs":
        sizes = random_sizes(n, rng, 1, max(2, 2 * n // 3))
    elif shape == "random_boundaries":
        boundaries = [0] + [i for i in range(1, n) if rng.random() < 0.11] + [n]
        sizes = [b-a for a,b in zip(boundaries, boundaries[1:])]
    elif shape == "skewed_runs":
        small = max(3, n // 8)
        sizes = [1] * small
        sizes.insert(rng.randrange(len(sizes) + 1), n - small)
    else:
        raise ValueError(shape)
    return sorted_chunks(values, sizes)


def generate(stage, smoke=False):
    assert stage in ("calibration", "test")
    if smoke:
        sizes, seeds = ((11, 25), (101,)) if stage == "calibration" else ((23, 47), (501,))
    else:
        sizes, seeds = ((24, 80, 192), (9011, 9029)) if stage == "calibration" else ((33, 97, 257), (100003, 200003, 300007))
    cases = []
    for seed in seeds:
        for n in sizes:
            for index, shape in enumerate(SHAPES):
                rng = random.Random(seed * 1000033 + n * 101 + index * 17011)
                xs = make(shape, n, rng)
                cases.append(dict(id=f"{stage}-{seed}-{n}-{shape}", stage=stage, shape=shape,
                    seed=seed, input=xs, expected=sorted(xs),
                    input_sha256=hashlib.sha256(repr(xs).encode()).hexdigest()))
    if stage == "test":
        for label, xs in [("empty", []), ("singleton", [7]), ("pair", [2,1]),
                          ("equal", [5]*9), ("odd", [9,1,2,0,5]),
                          ("duplicates", [1,1,2,0,0,3,2]),
                          ("length_witness", [50,30]+list(range(16))),
                          ("not_aligned", [8,9,10,2,3,4,5,0,1,7,6])]:
            cases.append(dict(id="test-edge-"+label,stage=stage,shape="edge_"+label,seed=None,
                input=xs,expected=sorted(xs),input_sha256=hashlib.sha256(repr(xs).encode()).hexdigest()))
    random.Random(1907 if stage=="calibration" else 2909).shuffle(cases)
    return cases
