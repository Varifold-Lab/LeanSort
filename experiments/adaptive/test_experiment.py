import copy
import json
from pathlib import Path
import tempfile
import unittest

from data import CANDIDATES, FEATURE_NAMES, digest, generate, plan, reference_features
from learning import fit, predict, prepare
from report import percentile, summarize
from run import load_history

CONFIG = json.loads((Path(__file__).parent / "config.json").read_text())


def training_row(n, prefer):
    return {"split": "train", "input_sha256": digest([n]), "length": n,
            "features": [n, 0, 1, 0, n, 0],
            "measurements": [{"strategy": p, "samples_ns": [10, 11, 9] if p == prefer else [100, 101, 99]}
                             for p in CANDIDATES]}


class DataTests(unittest.TestCase):
    def test_reproducible_and_disjoint(self):
        train = generate(CONFIG, "train", 123)
        test = generate(CONFIG, "test", 123)
        self.assertEqual(train, generate(CONFIG, "train", 123))
        self.assertEqual(len(train), 160)
        self.assertEqual(len(test), 80)
        self.assertFalse({r["input_sha256"] for r in train} & {r["input_sha256"] for r in test})
        for r in train + test:
            self.assertEqual(len(r["input"]), r["length"])
            self.assertTrue(all(isinstance(x, int) and x >= 0 for x in r["input"]))

    def test_bad_partition(self):
        with self.assertRaises(ValueError):
            generate({**CONFIG, "test_lengths": [16]}, "train", 0)

    def test_boundary_features(self):
        self.assertEqual(reference_features([]), [0, 0, 0, 0, 0, 0])
        self.assertEqual(reference_features([7]), [1, 0, 1, 0, 0, 0])
        self.assertEqual(reference_features([2, 1, 1]), [3, 500, 2, 500, 1, 333])


class LearningTests(unittest.TestCase):
    def setUp(self):
        self.rows = [training_row(n, "insertion" if n < 20 else "merge") for n in range(10, 30)]

    def test_learns_cost_sensitive_split(self):
        model, _, stats = fit(self.rows, CONFIG)
        self.assertEqual(model["tree"]["kind"], "branch")
        self.assertEqual(predict(model, [12, 0, 1, 0, 12, 0]), "insertion")
        self.assertEqual(predict(model, [25, 0, 1, 0, 25, 0]), "merge")
        self.assertLess(stats["training_tree_plan_only_ns"], stats["training_fixed_ns"])
        self.assertEqual(model["feature_names"], FEATURE_NAMES)

    def test_rejects_test_data(self):
        with self.assertRaises(ValueError):
            fit([{**self.rows[0], "split": "test"}], CONFIG)

    def test_deduplicates_repeated_observations(self):
        self.assertEqual(len(prepare(self.rows * 2)), len(self.rows))

    def test_rejects_conflicting_or_incomplete_data(self):
        conflicting = copy.deepcopy(self.rows[0])
        conflicting["features"][0] = 999
        with self.assertRaises(ValueError):
            prepare([self.rows[0], conflicting])
        with self.assertRaises(ValueError):
            prepare([{**self.rows[0], "measurements": []}])

    def test_history_provenance_and_compatibility(self):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory)
            (path / "metadata.json").write_text(json.dumps({"compatibility": "same"}))
            row = training_row(16, "merge")
            (path / "dataset-train.jsonl").write_text(json.dumps({"input_sha256": row["input_sha256"]}) + "\n")
            (path / "observations-train.jsonl").write_text(json.dumps(row) + "\n")
            self.assertEqual(len(load_history([path], {"compatibility": "same"}, CONFIG)), 1)
            with self.assertRaises(ValueError):
                load_history([path], {"compatibility": "different"}, CONFIG)
            row["split"] = "test"
            (path / "observations-train.jsonl").write_text(json.dumps(row) + "\n")
            with self.assertRaises(ValueError):
                load_history([path], {"compatibility": "same"}, CONFIG)


class ReportTests(unittest.TestCase):
    def test_reports_a_losing_tree_without_discarding_data(self):
        rows = []
        for i in range(4):
            measurements = [{"strategy": p, "samples_ns": [100, 100, 10000]} for p in CANDIDATES]
            measurements += [{"strategy": p, "samples_ns": [t, t, t]} for p, t in
                             [("best_fixed", 100), ("manual_rule", 150), ("decision_tree", 200), ("tree_plan_only", 90)]]
            rows.append({"split": "test", "family": "sample", "measurements": measurements,
                         "feature_samples_ns": [90, 90, 90], "tree_plan": plan("merge")})
        summary = summarize(rows, "merge", {**CONFIG, "bootstrap_resamples": 20})
        self.assertEqual(summary["tree_to_best_fixed_ratio"], 2)
        self.assertEqual(summary["paired_bootstrap_95pct_ratio"], [2, 2])
        self.assertIn("未超过", summary["conclusion"])
        self.assertEqual(rows[0]["measurements"][0]["samples_ns"][-1], 10000)

    def test_percentile(self):
        self.assertEqual(percentile([1, 3], 0.5), 2)


if __name__ == "__main__":
    unittest.main()
