"""Deterministic, non-learning evaluation data. Full inputs are saved per run."""
import random


def generate(smoke=False):
    cases = []
    sizes = (8, 32) if smoke else (16, 32, 64, 128)
    seeds = (20260906,) if smoke else (20260906, 20261017)
    for seed in seeds:
        for n in sizes:
            rng = random.Random(seed + 1009 * n)
            randoms = [rng.randrange(8 * n) for _ in range(n)]
            shapes = {"random": randoms, "sorted": sorted(randoms),
                      "reverse": sorted(randoms, reverse=True),
                      "duplicates": [rng.randrange(4) for _ in range(n)]}
            # Independently sorted chunks, with overlapping key ranges. These
            # satisfy the stated block premises but need not be globally sorted.
            for blocks in (2, 3, 4):
                if blocks == 3:
                    a = n // 3
                    boundaries = (0, a, a + (n - a) // 2, n)
                else:
                    boundaries = tuple(n * k // blocks for k in range(blocks + 1))
                shapes[f"{blocks}_sorted_blocks"] = sum(
                    [sorted(randoms[a:b]) for a, b in zip(boundaries, boundaries[1:])], [])
            for shape, xs in shapes.items():
                cases.append({"id": f"{seed}-{n}-{shape}", "shape": shape,
                              "seed": seed, "input": xs, "expected": sorted(xs)})
    for label, xs in [("empty", []), ("singleton", [7]), ("pair_reverse", [2, 1]),
                      ("all_equal", [3] * 17), ("odd", [5, 1, 4, 1, 3, 9, 0, 8, 2]),
                      ("sorted_counterexample", list(range(8)))]:
        cases.append({"id": "edge-" + label, "shape": "edge_" + label,
                      "seed": None, "input": xs, "expected": sorted(xs)})
    # Execution order is independent of policy ranks and observed performance.
    random.Random(71831).shuffle(cases)
    return cases
