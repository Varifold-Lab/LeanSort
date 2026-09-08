"""Recheck saved raw records without refitting/reselecting or timing a test again."""
import argparse
import json
from pathlib import Path
from collections import Counter
from core import stats,valid,features,predict,flat_predict
from reference import dp,lower_check,execute,scan
from data import audit_splits,digest
from build_checks import preserved,sources
from run import summarize_search

def load(p):return json.loads(p.read_text())
def rows(p):return [json.loads(x) for x in p.read_text().splitlines()]

def main():
    parser=argparse.ArgumentParser();parser.add_argument('directory',type=Path);a=parser.parse_args();p=a.directory.resolve()
    frozen=load(p/'frozen.json');protocol=frozen['protocol'];m=frozen['model']
    assert digest(m)==frozen['model_sha256']
    current=sources();expected=frozen['source_hashes']
    differences=[k for k in current if current[k]!=expected.get(k)]
    assert set(current)==set(expected)
    assert set(differences)<={'experiments/learned-merge-search/audit_saved.py'},differences
    original=preserved()
    groups={key:rows(p/f'dataset-{key}.jsonl') for key in ['train','validation','confirmation','extrapolation','structural_diagnostic']}
    split=audit_splits(groups);train={c['input_id']:c for c in groups['train']};tables={k:dp(c['lengths'])['table'] for k,c in train.items()}
    labelrows=rows(p/'training-labels.jsonl')
    for r in labelrows:
        c=train[r['input_id']];ls=c['lengths'];i,k,j=r['i'],r['k'],r['j'];w=sum(ls[i:j]);d=tables[c['input_id']]
        assert r['features']==features(ls,i,k,j)
        assert r['target']==1000000*(w+d[i][k]+d[k][j]-d[i][j])//w
        assert predict(m,r['features'])==flat_predict(m['nodes'],r['features'])
    statuses=Counter();inputs=0;searches=0
    for phase in ['confirmation','extrapolation','structural_diagnostic']:
        path=p/f'evaluation-{phase}.jsonl'
        if not path.exists():continue
        ev=rows(path);raw=rows(p/f'search-{phase}.jsonl');rawidx={(r['input_id'],r['method'],r['mode'],r['wall_limit_ns'],r['repeat']):r for r in raw}
        assert len(rawidx)==len(raw)
        for e in ev:
            ls=e['case']['lengths'];ref=e['reference'];truth=dp(ls)
            assert digest({k:ref[k] for k in truth})==digest(truth) and lower_check(ls,ref['table'])
            for r in e['searches']:
                searches+=1;statuses[r['status']]+=1
                saved=rawidx[r['input_id'],r['method'],r['mode'],r['wall_limit_ns'],r['repeat']]
                assert all(r[k]==v for k,v in saved.items())
                if r['status']!='ok':continue
                assert valid(r['tree'],ls) and stats(r['tree'],ls)[1]==r['budget']>=ref['budget']
                assert r['lower_bound']==0
                for event in r['events']:
                    assert valid(event['tree'],ls) and stats(event['tree'],ls)[1]==event['budget']>=ref['budget']
                assert r['quality']==summarize_search(r,ref,protocol['node_budgets'],r['wall_limit_ns'])
                assert all(a['budget']>=b['budget'] for a,b in zip(r['events'],r['events'][1:]))
                assert all(a['elapsed_ns']<=b['elapsed_ns'] for a,b in zip(r['timeline'],r['timeline'][1:]))
            inputs+=1
    reqs=rows(p/'checker-requests.jsonl');responses=rows(p/'checker-responses.jsonl');certified=0;executed=0
    assert len(reqs)==len(responses)
    for req,res in zip(reqs,responses):
        assert req['input_id']==res['input_id'];q=req['request'];ans=res['response'];ls=q['lengths'];d=q['table']
        assert lower_check(ls,d) and ans['lower_checked']
        if req['input_id']=='invalid-fallback':continue
        assert ans['fits']==[True]*len(q['trees'])
        for t,b,op in zip(q['trees'],ans['budgets'],ans['optimal']):
            assert valid(t,ls) and stats(t,ls)[1]==b
            assert op==(b==d[0][len(ls)]);certified+=1
        if q['execute']:
            for t,r in zip(q['trees'],ans['executions']):
                out,c=execute(t,q['runs']);assert out==r['output']==sorted(sum(q['runs'],[]))
                assert c==r['comparisons']<=r['budget'];executed+=1
    result=dict(passed=True,inputs=inputs,search_requests=searches,statuses=dict(statuses),label_rows=len(labelrows),
        split=split,original_files_unchanged=original,source_and_model_unchanged=not differences,audit_only_source_changes=differences,trees_rechecked=certified,
        executed_trees_rechecked=executed,note='Saved evidence only, no timing/retraining/reselection. Lean proof logs remain separate.')
    (p/'saved-data-audit.json').write_text(json.dumps(result,indent=2,sort_keys=True)+'\n')
    print(json.dumps(result,indent=2))

if __name__=='__main__':main()
