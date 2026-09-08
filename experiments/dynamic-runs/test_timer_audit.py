import unittest
from timer_audit import audit


def fixture():
    specs = {
        'timedRun':['lean_st_ref_get','RunAdaptive_Strategy_run','RunExperiment_checksum','lean_st_ref_set'],
        'timedScan':['lean_st_ref_get','RunAdaptive_discover','lean_st_ref_set'],
        'timedPlan':['lean_st_ref_get','lean_apply_1','MergeTree_budget','lean_st_ref_set'],
        'timedMerge':['lean_st_ref_get','MergeTree_program','Program_eval','RunExperiment_checksum','lean_st_ref_set'],
    }
    return '\n'.join('LEAN_EXPORT lean_object* l_RunExperiment_'+name+'(void) {\n'+
        'lean_io_mono_nanos_now();\n'+''.join(op+'();\n' for op in ops)+
        'lean_io_mono_nanos_now();\n}' for name,ops in specs.items())


class TimerAuditTests(unittest.TestCase):
    def test_placements(self):
        self.assertTrue(all(audit(fixture())['checks'].values()))

    def test_work_moved_before_clock_rejected(self):
        bad=fixture().replace('lean_io_mono_nanos_now();\nlean_st_ref_get();\nRunAdaptive_Strategy_run();',
            'lean_st_ref_get();\nRunAdaptive_Strategy_run();\nlean_io_mono_nanos_now();',1)
        with self.assertRaises(ValueError):
            audit(bad)

    def test_output_not_consumed_rejected(self):
        with self.assertRaises(ValueError):
            audit(fixture().replace('RunExperiment_checksum();','',1))


if __name__=='__main__':
    unittest.main()
