import unittest
from common import *

class BudgetTests(unittest.TestCase):
    def test_feature_budget(self):
        for n in range(40):
            xs=list(range(n,0,-1))
            for k in BUDGETS:
                fs,c=feature(k,xs)
                self.assertLessEqual(c,LIMITS[k]);self.assertEqual(fs[0],n)
                if k!='legacy':self.assertEqual(c,min(LIMITS[k],max(0,n-1)))
        self.assertEqual(feature('eight',[2,1]),([2,1,1000,0,0,0],1))
    def test_controlled_actual_runs(self):
        for n in [32,97,512]:
            for r in [1,2,4,8,16,32]:
                for skew in [False,True]:
                    xs=controlled(list(range(n)),r,skew)
                    self.assertEqual(len(discover(xs)[0]),r)
                    self.assertEqual(sorted(xs),list(range(n)))
    def test_grouping(self):
        ds={s:generate(s,[32,96],[seed]) for s,seed in [('train',11),('validation',13),('confirmation',17)]}
        self.assertTrue(prior_data.assert_split_integrity(ds)['passed'])
        bad=dict(ds);bad['confirmation']=[dict(ds['train'][0],split='confirmation',input_id='bad')]
        with self.assertRaises(AssertionError):prior_data.assert_split_integrity(bad)
    def test_translation_and_missing_slots(self):
        for k in BUDGETS:
            a=[4,2,3,0,7,7,1];b=[x+100000 for x in a]
            self.assertEqual(feature(k,a),feature(k,b))
            if k!='legacy':self.assertEqual(feature(k,a)[0][3:],[0,0,0])
    def test_models_train_without_metadata(self):
        rows=[dict(split='train',input_sha256=str(i),features=[i,0,0,0,0,0],costs_ns=[5,1 if i<16 else 5,5,5,5,5 if i<16 else 1,5]) for i in range(32)]
        for kind in ['classifier','cost_ranking']:
            m=prior_learning.fit(rows,kind,2,4)
            p=dict(kind='learned',feature_kind='length',model=m)
            self.assertEqual(predict(p,[0,0,0,0,0,0]),1)
            self.assertEqual(predict(p,[31,0,0,0,0,0]),5)
    def test_kernel_source_not_changed_in_worker(self):
        old=(OLD/'Worker.lean').read_text();new=(HERE/'Worker.lean').read_text()
        for start,end in [('def timedKernel','@[noinline] def timedPolicy'),('def kernelProfile','def bench')]:
            self.assertEqual(old[old.index(start):old.index(end)],new[new.index(start):new.index(end)])

if __name__=='__main__':unittest.main()
