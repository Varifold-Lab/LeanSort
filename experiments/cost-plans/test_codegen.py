import unittest
from audit_codegen import audit


GOOD = """
LEAN_EXPORT lean_object* l_CostPlanExperiment_timedRun(void) {
lean_io_mono_nanos_now(); lean_st_ref_get(); l_LeanSort_CostedPlan_Schema_run();
l_CostPlanExperiment_checksum(); lean_st_ref_set(); lean_io_mono_nanos_now();
}
LEAN_EXPORT lean_object* l_CostPlanExperiment_timedChecks(void) {
lean_io_mono_nanos_now(); lean_st_ref_get(); lp_Schema_checkProgram();
l_LeanSort_Comparison_Program_eval(); lean_st_ref_set(); lean_io_mono_nanos_now();
}
LEAN_EXPORT lean_object* l_CostPlanExperiment_profile(void) {
lean_io_mono_nanos_now(); lean_st_ref_get(); l_LeanSort_CostedPlan_Schema_eval();
lp_Schema_checkProgram(); l_Lean_Json_compress(); lean_st_ref_set(); lean_io_mono_nanos_now();
}
"""


class CodegenTests(unittest.TestCase):
    def test_valid_placement(self):
        self.assertTrue(all(audit(GOOD)["checks"].values()))

    def test_hoisting_rejected(self):
        hoisted = GOOD.replace("lean_io_mono_nanos_now(); lean_st_ref_get(); lp_Schema_checkProgram();",
                               "lp_Schema_checkProgram(); lean_io_mono_nanos_now(); lean_st_ref_get();")
        with self.assertRaises(ValueError):
            audit(hoisted)


if __name__ == "__main__":
    unittest.main()
