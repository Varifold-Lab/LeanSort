import itertools
import random
import unittest
from core import *
from reference import dp,postfix_trees,lower_check,execute,scan
from data import generate,audit_splits,canonical
from learning import labels,fit


class SearchTests(unittest.TestCase):
    def test_dp_vs_postfix(self):
        for n in range(7):
            for ls in itertools.product([1,2,3],repeat=n):
                d=dp(ls);trees=list(postfix_trees(ls))
                self.assertEqual(d['budget'],min(x[1] for x in trees))
                self.assertTrue(lower_check(ls,d['table']))
                self.assertEqual(len(trees),[1,1,1,2,5,14,42][n])
                for t,b in trees:
                    self.assertTrue(valid(t,ls));self.assertEqual(stats(t,ls)[1],b)
                    self.assertLessEqual(0,b)
    def test_corrupt_certificates(self):
        ls=[1,8,2,4];d=dp(ls)['table'];d[0][4]+=1
        self.assertFalse(lower_check(ls,d))
        self.assertFalse(valid((0,(2,1)),ls))
        self.assertFalse(valid((0,(1,(2,2))),ls))
    def test_all_orders_and_budgets(self):
        m={'nodes':[[-1,0,0,0]]}
        for ls in [[1],[1,3],[1,1,20],[7,2,9,1,4],[]]:
            for o in ['fixed','heuristic','learned']:
                for n in [0,1,5,10000]:
                    a=search(ls,o,n,model=m)
                    self.assertTrue(valid(a['tree'],ls));self.assertLessEqual(a['nodes'],n)
                    self.assertGreaterEqual(a['budget'],dp(ls)['budget'])
                    if a['termination']=='exhausted':self.assertEqual(a['budget'],dp(ls)['budget'])
    def test_search_has_no_reference_dependency(self):
        import core,inspect
        s=inspect.getsource(core)
        self.assertNotIn('from reference',s);self.assertNotIn('dp(',s)
    def test_execution(self):
        for ls in [[1,1,16],[3,8,2,1],[1],[]]:
            rs=[list(range(sum(ls)-sum(ls[:i+1]),sum(ls)-sum(ls[:i]))) for i in range(len(ls))]
            for t,b in postfix_trees(ls):
                out,c=execute(t,rs)
                self.assertEqual(out,sorted(sum(rs,[])));self.assertLessEqual(c,b)
    def test_training_export_and_grouping(self):
        used={};a=generate('train',[71201],[4,8],used);b=generate('validation',[81201],[4,8],used)
        self.assertTrue(audit_splits({'train':a,'validation':b})['passed'])
        rows,_=labels(a);m=fit(rows,2)
        for c in a+b:
            for k in range(1,len(c['lengths'])):
                f=features(c['lengths'],0,k,len(c['lengths']))
                self.assertEqual(predict(m,f),flat_predict(m['nodes'],f))
    def test_model_error(self):
        a=search([1,9,3,2],'learned',20,model={})
        self.assertGreater(a['model_fallbacks'],0);self.assertTrue(valid(a['tree'],[1,9,3,2]))

if __name__=='__main__':unittest.main()
