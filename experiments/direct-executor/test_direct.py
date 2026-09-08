import itertools
from pathlib import Path
import unittest

from data_protocol import paired, smoke, variants, discover, evaluate
from audit import body, timer_audit, executor_audit


class ProtocolTests(unittest.TestCase):
    def test_fixed_inputs_and_design(self):
        self.assertEqual(len(paired()),98)
        self.assertEqual(len(smoke()),28)
        self.assertEqual(len(variants()),23)
        self.assertEqual(len(set(variants())),23)

    def test_independent_small_costs(self):
        self.assertEqual(discover([1,1,3,0,2,2]),([[1,1,3],[0,2,2]],5))
        for n in range(6):
            for xs in map(list,itertools.product(range(3),repeat=n)):
                for strategy in dict.fromkeys(s for s,_ in variants()):
                    p=evaluate(strategy,xs)
                    self.assertEqual(p['output'],sorted(xs))
                    self.assertLessEqual(p['comparisons'],p['bound'])
                    self.assertEqual(p['comparisons'],p['check_comparisons']+p['merge_or_sort_comparisons'])
                    if p['conditional_applicable']:
                        self.assertLessEqual(p['comparisons'],p['conditional_bound'])

    def test_timer_mutations(self):
        operations=['RunAdaptive_Strategy_program','Direct_runCounted','Direct_run___','Direct_staged']
        source='\n'.join('LEAN_EXPORT lean_object* l_DirectExperiment_timed'+name+'(){'+
            'lean_io_mono_nanos_now();lean_st_ref_get();'+op+'();DirectExperiment_checksum();'+
            'lean_st_ref_set();lean_st_ref_set();lean_io_mono_nanos_now();}'
            for name,op in zip(['Reference','Counted','Plain','Staged'],operations))
        self.assertEqual(len(timer_audit(source)),4)
        with self.assertRaises((ValueError,AssertionError)):
            timer_audit(source.replace('lean_st_ref_get();Direct_runCounted();',
                'lean_st_ref_get();lean_io_mono_nanos_now();Direct_runCounted();'))
        with self.assertRaises((ValueError,AssertionError)):
            timer_audit(source.replace('Direct_run___();','Direct_run___();Direct_runCounted();'))

    def test_function_parser(self):
        self.assertEqual(body('uint8_t abc_x(int a){if(a){return 1;}return 0;}','abc_x'),
            '{if(a){return 1;}return 0;}')


if __name__=='__main__':
    unittest.main()
