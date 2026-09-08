"""Read saved measurements, replay validations and fits without any reselection/timing."""
from collections import defaultdict,Counter
import json
from pathlib import Path
import sys

P=Path(__file__).resolve().parent
HERE=P.parents[1]
sys.path.insert(0,str(HERE))
from common import *
from measure import validate_b
from reporting import summarize

def read(name):return json.loads((P/name).read_text())

def main():
    assert __debug__
    assert read('source-hashes.json')==source_hashes()
    assert read('preregistered.json')==config()
    n_original=preserved();frozen=read('B-frozen.json')
    assert jsonhash(frozen['policies'])==frozen['models_hash']
    bysplit={};nrecords=0;nsamples=0;ncore=0;conditional=0;statuses=Counter()
    for batch in ['pilot','A','B-train','B-validation','B-confirmation']:
        cases=load_rows(P/f'dataset-{batch}.jsonl');byid={r['input_id']:r for r in cases}
        bysplit[cases[0]['split']]=cases
        policies=read(f'policies-{batch}.json');rows=load_rows(P/f'records-{batch}.jsonl')
        assert len(rows)==len(cases)
        samples=defaultdict(list);results={}
        for wrapper in load_rows(P/f'events-{batch}.jsonl'):
            ident=wrapper['input_id'];e=wrapper['event']
            if e['event']=='sample':
                samples[ident].append(e);nsamples+=1;ncore+=e['category'] in ['kernel','policy']
            else:
                assert ident not in results;results[ident]=e['result']
        for r in rows:
            nrecords+=1;statuses[r['status']]+=1
            if r['status']!='ok':continue
            validate=prior_measurement.validate if batch in ['pilot','A'] else validate_b
            rr=validate(byid[r['input_id']],results[r['input_id']],samples[r['input_id']],policies,r['rounds'])
            assert all(r[k]==v for k,v in rr.items()),(batch,r['input_id'])
            conditional+=sum(x['conditional_applicable'] for x in r['kernels'])
            assert r['run_lengths']==byid[r['input_id']]['observed_run_lengths']
    split=prior_data.assert_split_integrity(bysplit)
    prior=prior_data.old_hashes()
    for path in (OLD/'results').glob('*/dataset-*.jsonl'):
        prior.update(digest(r['input']) for r in load_rows(path))
    assert not prior.intersection(r['input_sha256'] for r in bysplit['confirmation'])
    train=load_rows(P/'records-B-train.jsonl')
    for path in (P/'models').glob('*.json'):
        m=json.loads(path.read_text());budget=m['feature_kind'];h=m['hyperparameters']
        again=prior_learning.fit([dict(r,features=r['features_by_budget'][budget]) for r in train],m['kind'],h['depth'],h['min_leaf'])
        assert again['tree']==m['tree'] and again['training_hash']==m['training_hash']
    val=load_rows(P/'records-B-validation.jsonl');options=read('B-trained-before-validation.json')
    sums={k:sum(r['policies'][k]['median_ns'] for r in val) for k in val[0]['policies']}
    for key,s in frozen['selection'].items():
        eligible=[k for k in options if k.startswith(key+'-')]
        best=min(eligible,key=lambda k:(sums[k],k))
        assert best==s['source'] and sums[best]==s['validation_e2e_ns']
        assert options[best]==frozen['policies'][key]
    for kind,key in frozen['best_budget'].items():
        assert key==min([k for k in frozen['selection'] if k.endswith('-'+kind)],key=lambda k:(frozen['selection'][k]['validation_e2e_ns'],k))
    a=load_rows(P/'records-A.jsonl');b=load_rows(P/'records-B-confirmation.jsonl');analysis=read('analysis.json')
    assert summarize([r for r in a if r['family'] in FAMILIES])==analysis['A']
    assert summarize(b)==analysis['B']
    old=ROOT/config()['previous_result']
    for kind,m in read('stage-a-frozen-models.json').items():assert m==json.loads((old/f'final-{kind}.json').read_text())
    omitted=[]
    for item in read('formal-protocol.json')['excluded_lengths']:
        for seed in config()['a_seeds']:
            for family in FAMILIES:
                omitted.append(dict(n=item['n'],seed=seed,family=family,input_id=f'diagnostic-{seed}-{item["n"]}-{family}',
                    status=item['status'],candidates=[dict(id=i,status='not_executed',time_ns=None,comparisons=None) for i in range(7)],
                    note='Formal grid excluded by pilot forecast before generation; no performance observation'))
    save_rows(P/'unexecuted-grid.jsonl',omitted)
    save(P/'saved-data-audit.json',dict(passed=True,original_files_unchanged=n_original,source_and_models_unchanged=True,
        records=nrecords,samples=nsamples,checked_core_calls_including_warmups=ncore,statuses=dict(statuses),
        conditional_applicable_records=conditional,split=split,retrained_models_match=16,
        model_and_budget_selection_matches_validation=True,unexecuted_design_cells=len(omitted),
        note='Post-test audit replay only; no new timing, export, parameter change or reselection'))
    print(json.dumps(read('saved-data-audit.json'),indent=2))

if __name__=='__main__':main()
