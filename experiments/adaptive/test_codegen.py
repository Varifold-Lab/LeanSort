import unittest
from audit_codegen import audit


GOOD = """
LEAN_EXPORT lean_object* l_AdaptiveExperiment_checkedRun(void) {
  lean_io_mono_nanos_now();
  l_AdaptiveExperiment_Strategy_run();
  l_AdaptiveExperiment_checksum();
  lean_io_mono_nanos_now();
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_timedFeatures(void) {
  lean_io_mono_nanos_now();
  lean_st_ref_get();
  l_AdaptiveExperiment_features();
  lean_io_mono_nanos_now();
}
"""


class CodegenTests(unittest.TestCase):
    def test_calls_are_inside_timers(self):
        self.assertTrue(all(audit(GOOD)["checks"].values()))

    def test_hoisted_feature_computation_is_rejected(self):
        hoisted = GOOD.replace("  lean_io_mono_nanos_now();\n  lean_st_ref_get();\n  l_AdaptiveExperiment_features();",
                               "  lean_st_ref_get();\n  l_AdaptiveExperiment_features();\n  lean_io_mono_nanos_now();")
        with self.assertRaises(ValueError):
            audit(hoisted)


if __name__ == "__main__":
    unittest.main()
