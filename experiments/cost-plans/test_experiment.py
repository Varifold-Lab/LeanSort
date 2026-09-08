import itertools
from pathlib import Path
import random
import tempfile
import unittest

from catalogue import canonical, cut_at, emit_sources, enumerate_catalogue, guard, leaf, log_weight, ready_depth, shortlist, split, upper
from data import generate
from reference import evaluate, ready


class ExperimentTests(unittest.TestCase):
    def test_catalogue(self):
        entries, baselines = enumerate_catalogue()
        self.assertEqual(len(entries), 100)
        self.assertEqual(len(baselines), 5)
        self.assertEqual(len({canonical(e["plan"]) for e in entries}), 100)
        self.assertEqual(entries, enumerate_catalogue()[0])
        self.assertEqual(shortlist(entries), shortlist(enumerate_catalogue()[0]))
        self.assertGreater(len({str(e["plan"].get("cut")) for e in entries}), 4)

    def test_clipped_and_degenerate_parameters(self):
        self.assertEqual(cut_at(("fraction", 5, 0), 3), 3)
        self.assertEqual(cut_at(("prefix", 9), 3), 3)
        for p in (split(leaf("insertion"), leaf("merge"), ("prefix", 99)),
                  split(guard(leaf("merge")), leaf("hybrid", 0), ("fraction", 0, 0))):
            out, c, s = evaluate(p, [3, 0, 3, 2])
            self.assertEqual(out, [0, 2, 3, 3])
            self.assertLessEqual(c + s, upper(p, 4))

    def test_independent_operation_oracle(self):
        entries, baselines = enumerate_catalogue()
        rng = random.Random(918)
        inputs = [list(xs) for xs in itertools.permutations(range(4))]
        inputs += [[rng.randrange(7) for _ in range(n)] for n in (0, 1, 2, 3, 8, 17, 31)]
        for e in entries + baselines:
            for xs in inputs:
                p = e["plan"]
                out, checks, sorting = evaluate(p, xs)
                self.assertEqual(out, sorted(xs))
                self.assertLessEqual(checks + sorting, upper(p, len(xs)))
                if ready(p, xs):
                    self.assertLessEqual(checks + sorting, upper(p, len(xs), True))

    def test_envelope_not_dominance(self):
        two = split(leaf("insertion"), leaf("insertion"))
        self.assertEqual(upper(two, 8), 20)
        self.assertEqual(upper(leaf("insertion"), 8), 28)
        self.assertEqual(evaluate(two, list(range(8)))[2], 10)
        self.assertEqual(evaluate(leaf("insertion"), list(range(8)))[2], 7)

    def test_sufficient_asymptotic_rules_not_false_labels(self):
        self.assertIsNone(log_weight(leaf("insertion")))
        self.assertEqual(ready_depth(split(guard(leaf("merge")), guard(leaf("insertion")))), 1)

    def test_emission(self):
        entries, baselines = enumerate_catalogue()
        with tempfile.TemporaryDirectory() as tmp:
            dest = Path(tmp) / "Generated"
            emit_sources(entries + baselines, dest)
            proofs = (dest / "Certificates.lean").read_text()
            self.assertEqual(proofs.count(" : Certificate "), 105)
            self.assertNotIn("native_decide", proofs)
            self.assertNotIn("sorry", proofs)

    def test_data_premises(self):
        self.assertEqual(generate(), generate())
        plans = {"2_sorted_blocks": enumerate_catalogue()[0][1]["plan"],
                 "3_sorted_blocks": enumerate_catalogue()[0][5]["plan"],
                 "4_sorted_blocks": enumerate_catalogue()[0][6]["plan"]}
        for case in generate():
            self.assertEqual(case["expected"], sorted(case["input"]))
            if case["shape"] in plans:
                self.assertTrue(ready(plans[case["shape"]], case["input"]))


if __name__ == "__main__":
    unittest.main()
