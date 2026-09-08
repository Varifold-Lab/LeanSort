import copy
import unittest
from data_protocol import generate,assert_split_integrity,features,config
from learning import fit,predict,best_fixed,near_label,predict_raw
from compiler_audit import audit


class LearningTests(unittest.TestCase):
    def test_grouped_split_and_hashes(self):
        train=generate('train',[24],[1100003])
        val=generate('validation',[24],[2100001])
        self.assertTrue(assert_split_integrity({'train':train,'validation':val})['passed'])
        bad=copy.deepcopy(train[0]);bad['split']='validation';bad['input_id']='different-id'
        with self.assertRaises(AssertionError): assert_split_integrity({'train':train,'validation':[bad]})

    def test_translation_does_not_expose_seed(self):
        xs=[1,8,0,2,3]*20
        self.assertEqual(features(xs),features([x+999999999 for x in xs]))

    def test_feature_hand_cases_and_budget(self):
        self.assertEqual(features([]),([0,0,0,0,0,0],0))
        self.assertEqual(features([2,1]),([2,1,1000,0,0,0],5))
        for n in range(100):
            f,c=features(list(range(n)))
            self.assertEqual(c,5*min(16,max(0,n-1)))
            self.assertLessEqual(c,80)
            self.assertEqual(f[2:5],[0,0,0])

    def test_ties_not_arbitrary_large_errors(self):
        self.assertEqual(near_label([100,101,500],1,.02),1)
        self.assertEqual(near_label([100,105,500],1,.02),0)

    def synthetic(self):
        return [dict(split='train',input_sha256=str(n),features=[n,0,0,0,0,0],
            costs_ns=[100 if n<20 else 500,600,600,600,600,500 if n<20 else 100,700]) for n in range(40)]

    def test_both_models_really_fit(self):
        rows=self.synthetic()
        for kind in ['classifier','cost_ranking']:
            model=fit(rows,kind,2,4)
            self.assertEqual(predict(model,[2,0,0,0,0,0]),0)
            self.assertEqual(predict(model,[30,0,0,0,0,0]),5)
            self.assertGreater(model['training_ns'],0)
        with self.assertRaises(ValueError): fit([dict(rows[0],split='test')],'classifier',2,4)
        with self.assertRaises(ValueError): fit(rows+rows,'classifier',2,4)

    def test_invalid_models_and_ids(self):
        m=fit(self.synthetic(),'classifier',2,4)
        m['tree']={'kind':'leaf','values':[99]}
        self.assertEqual(predict(m,[0]*6),1)
        m['feature_version']='unsupported'
        self.assertIsNone(predict_raw(m,[0]*6))

    def test_timer_mutation(self):
        entries=[('timedKernel',['LearnedSelection_dispatch']),
            ('timedPolicy',['LearnedSelection_select','LearnedSelection_dispatch']),
            ('timedFeatures',['LearnedSelection_features']),('timedDecision',['LearningWorker_featureSelect'])]
        text=''
        for name,ops in entries:
            text+='lean_object* l_LearningWorker_'+name+'(){lean_io_mono_nanos_now();lean_st_ref_get();'
            text+=''.join(op+'();' for op in ops)
            if name!='timedDecision':text+='LearningWorker_checksum();'
            text+='lean_st_ref_set();'
            if name in ['timedKernel','timedPolicy']:text+='lean_st_ref_set();'
            text+='lean_io_mono_nanos_now();}'
        self.assertTrue(audit(text)['passed'])
        with self.assertRaises((ValueError,AssertionError)):
            audit(text.replace('LearnedSelection_select();','lean_io_mono_nanos_now();LearnedSelection_select();'))


if __name__=='__main__':unittest.main()
