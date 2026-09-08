import itertools
import unittest
from datasets import generate, SHAPES
from dyn_reference import discover, evaluate, midpoint_cut, paper_cut, plan, signature, tree_stats


class RunTests(unittest.TestCase):
    def test_scanner_exhaustive(self):
        for n in range(7):
            for xs in itertools.product(range(3), repeat=n):
                xs=list(xs)
                rs,c=discover(xs)
                self.assertEqual(sum(rs,[]),xs)
                self.assertTrue(all(r and r==sorted(r) for r in rs))
                self.assertEqual(c,max(0,n-1))
                self.assertEqual(len(rs),0 if not xs else 1+sum(a>b for a,b in zip(xs,xs[1:])))
                for name in ("runs_count","runs_length"):
                    p=evaluate(name,xs)
                    self.assertEqual(p['output'],sorted(xs))
                    self.assertLessEqual(p['comparisons'],p['bound'])
                    self.assertLessEqual(p['comparisons'],c+p['tree_budget'])

    def test_peeksort_integer_midpoint_ties(self):
        self.assertEqual(midpoint_cut([1,2,1]),1)
        self.assertEqual(midpoint_cut([1,3,1]),2)
        for n in range(2,15):
            for mask in range(1,1<<(n-1)):
                points=[0]+[i for i in range(1,n) if mask & (1<<(i-1))]+[n]
                lengths=[b-a for a,b in zip(points,points[1:])]
                self.assertEqual(midpoint_cut(lengths),paper_cut(lengths))

    def test_distinct_strategy_and_hand_count(self):
        xs=[50,30]+list(range(16))
        a,b=evaluate('runs_count',xs),evaluate('runs_length',xs)
        self.assertNotEqual(a['plan'],b['plan'])
        self.assertEqual((a['comparisons'],b['comparisons']),(50,34))
        self.assertEqual((a['tree_budget'],b['tree_budget']),(35,20))

    def test_data_separation(self):
        for smoke in (True,False):
            a,b=generate('calibration',smoke),generate('test',smoke)
            self.assertEqual(a,generate('calibration',smoke))
            self.assertFalse({c['input_sha256'] for c in a}&{c['input_sha256'] for c in b})
            self.assertEqual({c['shape'] for c in a},set(SHAPES))
            self.assertTrue(any(len(discover(c['input'])[0])>4 for c in b))
            self.assertTrue(any(len(c['input'])%4!=0 for c in b))


if __name__=='__main__':
    unittest.main()
