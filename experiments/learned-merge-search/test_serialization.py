import json
import unittest
from core import search
from data import digest

class SerializationTests(unittest.TestCase):
    def test_model_hash_ignores_object_key_order(self):
        m={'tree':{'right':1,'left':2},'schema_version':1,'nodes':[[-1,0,0,0]]}
        self.assertEqual(digest(m),digest(json.loads(json.dumps(m,sort_keys=True))))
    def test_corrupt_cycle_bounded_fallback(self):
        r=search([3,4,1,8],'learned',32,model={'nodes':[[0,4,0,0]]})
        self.assertGreater(r['model_fallbacks'],0)
        self.assertEqual(r['status'],'ok')

if __name__=='__main__':unittest.main()
