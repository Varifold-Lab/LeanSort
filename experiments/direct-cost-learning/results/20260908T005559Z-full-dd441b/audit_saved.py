"""Post-run acceptance of saved evidence; never changes or selects a model.

python3 experiments/direct-cost-learning/results/20260908T005559Z-full-dd441b/audit_saved.py
"""
from collections import defaultdict, Counter
import hashlib
import json
from pathlib import Path
import sys
import time

P = Path(__file__).resolve().parent
HERE = P.parents[1]
ROOT = P.parents[3]
sys.path.insert(0, str(HERE))
from build_checks import hashes
from data_protocol import assert_split_integrity, config
from learning import fit, best_fixed
from measurement import validate
from report import summarize


def read(name): return json.loads((P/name).read_text())
def rows(path): return [json.loads(line) for line in path.read_text().splitlines()]


def main():
    assert __debug__
    sources=read('source-hashes.json')
    assert sources==hashes()
    frozen=read('final-frozen.json')
    assert frozen['sources']==sources
    assert frozen['config']==config()
    for kind,model in frozen['models'].items():
        assert model==read('final-'+kind+'.json')
        assert hashlib.sha256(json.dumps(model,sort_keys=True).encode()).hexdigest()==frozen['model_hashes'][kind]
    datasets={f.stem.removeprefix('dataset-'):rows(f) for f in P.glob('dataset-*.jsonl')}
    split=assert_split_integrity(datasets,set(read('prior-data-exclusion.json')['previous_input_hashes']))
    cases={c['input_id']:c for values in datasets.values() for c in values}
    originals=(HERE/'results/original-worktree.sha256').read_text().splitlines()
    for line in originals:
        digest,path=line.split('  ',1)
        assert hashlib.sha256((ROOT/path).read_bytes()).hexdigest()==digest,path
    train=[]
    for prefix in [2,4,8]:train+=rows(P/f'records-train-prefix-{prefix}.jsonl')
    fixed=best_fixed(train)
    assert fixed==frozen['best_fixed_id']
    rebuilt=0
    for prefix in [2,4,8]:
        manifest=read(f'accumulation-prefix-{prefix}.json')
        pool=[r for r in train if r['input_id'] in manifest['input_ids']]
        assert len(pool)==manifest['training_inputs']
        for filename in manifest['model_files']:
            saved=read(filename)
            h=saved['hyperparameters']
            again=fit(pool,saved['kind'],h['depth'],h['min_leaf'])
            # Retraining is acceptance replay only; timings are naturally different.
            assert {k:v for k,v in again.items() if k!='training_ns'}=={k:v for k,v in saved.items() if k!='training_ns'}
            rebuilt+=1
    statuses=Counter();samples=0;core_repetitions=0;records=0;conditional=0
    for f in sorted(P.glob('records-*.jsonl')):
        batch=f.stem.removeprefix('records-')
        deployed={}
        if batch.startswith('validation-prefix-') or batch in ['test','generalization']:
            deployed=dict(best_fixed=dict(kind='fixed',id=fixed),sample_rule=dict(kind='sample_rule'),length_rule=dict(kind='length_rule'))
            if batch.startswith('validation-prefix-'):
                prefix=batch.removeprefix('validation-prefix-')
                for model in sorted((P/'models'/('prefix-'+prefix)).glob('*.json')):
                    deployed[model.stem]=dict(kind='learned',model=json.loads(model.read_text()))
            else:
                deployed.update({k:dict(kind='learned',model=m) for k,m in frozen['models'].items()})
        streams=defaultdict(list);responses={}
        for wrapper in rows(P/('events-'+batch+'.jsonl')):
            event=wrapper['event'];ident=wrapper['input_id']
            if event['event']=='sample':
                streams[ident].append(event);samples+=1
                core_repetitions+=event['category'] in ['kernel','policy']
            else:
                assert ident not in responses
                responses[ident]=event['result']
        saved_rows=rows(f)
        assert set(responses)=={r['input_id'] for r in saved_rows}
        for r in saved_rows:
            statuses[r['status']]+=1;records+=1
            check=validate(cases[r['input_id']],responses[r['input_id']],streams[r['input_id']],deployed,5)
            assert all(r[k]==v for k,v in check.items()),(batch,r['input_id'])
            conditional+=sum(k['conditional_applicable'] for k in r['kernels'])
            assert r['versions']==frozen['versions']
    assert set(statuses)=={'ok'}
    analysis=read('analysis.json')
    supplement={}
    for stage in ['test','generalization']:
        rr=rows(P/('records-'+stage+'.jsonl'))
        assert summarize(rr)==analysis[stage]
        oracle_ids=[min(range(7),key=r['costs_ns'].__getitem__) for r in rr]
        supplement[stage]=dict(
            oracle_kernel_comparisons=sum(r['kernels'][i]['comparisons'] for r,i in zip(rr,oracle_ids)),
            oracle_chosen_counts=dict(Counter(map(str,oracle_ids))),
            base_groups=len({r['group_id'] for r in rr}),
            note='Oracle chooses smallest measured time, not fewest comparisons or smallest proved bound',
            ratios_by_length={kind:{str(n):sum(r['policies'][kind]['median_ns'] for r in rr if r['n']==n)/sum(r['policies']['best_fixed']['median_ns'] for r in rr if r['n']==n) for n in sorted({r['n'] for r in rr})} for kind in ['classifier','cost_ranking']})
    result=dict(passed=True,source_and_models_unchanged=True,original_files_unchanged=len(originals),
        split=split,models_retrained_identically_without_reselection=rebuilt,validated_records=records,
        recorded_samples=samples,checked_core_repetitions_including_warmups=core_repetitions,
        conditional_applicable_records=conditional,statuses=dict(statuses),supplement=supplement,
        note='Post-test audit only: no refit model exported, no hyperparameter/feature/candidate change, no repeat timing')
    (P/'saved-data-audit.json').write_text(json.dumps(result,indent=2,sort_keys=True)+'\n')
    print(json.dumps(result,indent=2))


if __name__=='__main__':main()
