"""Matched direct-backend measurements with durable partial events and null failures."""
from collections import defaultdict
import json
import statistics
import time
from common import *
from client import Worker,WorkerFailure


def validate_b(case,response,events,policies,rounds):
    xs=case['input'];fs={k:feature(k,xs)[0] for k in BUDGETS};fc={k:feature(k,xs)[1] for k in BUDGETS}
    assert response['features']==list(fs.values()) and response['feature_comparisons']==list(fc.values())
    # Independently validated shared kernel profiles and their old conditional bounds.
    legacy_events=[dict(e,name='features') if e['category']=='features' else e for e in events
        if e['category']=='kernel' or (e['category']=='features' and e['name']=='legacy')]
    kernel_response=dict(response,features=fs['legacy'],feature_comparisons=fc['legacy'],predictions=[])
    row=prior_measurement.validate(case,kernel_response,legacy_events,{},rounds)
    row['features_by_budget']=fs;row['feature_comparisons_by_budget']=fc
    predicted={p['name']:p for p in response['predictions']};assert set(predicted)==set(policies)
    grouped=defaultdict(list);seen=set()
    for e in events:
        assert e['ns']>0
        key=e['category'],e['name'],e['round'];assert key not in seen;seen.add(key)
        grouped[key[:2]].append(e)
    expected={('kernel',str(i)) for i in range(7)}|{('features',k) for k in BUDGETS}|{(cat,n) for n in policies for cat in ['policy','decision']}
    assert set(grouped)==expected
    for (cat,_),ev in grouped.items():assert {e['round'] for e in ev}==set(range(-1 if cat in ['kernel','policy'] else 0,rounds))
    def times(cat,name):return [e['ns'] for e in sorted(grouped[cat,name],key=lambda e:e['round']) if e['round']>=0]
    row['feature_samples_by_budget']={k:times('features',k) for k in BUDGETS}
    for name,p in policies.items():
        kind=p['feature_kind'];raw=predict(p,fs[kind]);chosen=prior_learning.resolve(raw);actual=predicted[name]
        assert actual['raw_id']==raw and actual['chosen_id']==chosen
        uses=p['kind']!='fixed';assert actual['uses_features']==uses
        if p['kind']=='learned':assert actual['values']==prior_learning.predict_values(p['model']['tree'],fs[kind])
        for cat in ['policy','decision']:assert all(e['chosen_id']==chosen for e in grouped[cat,name])
        prof=row['kernels'][chosen];charge=fc[kind] if uses else 0;limit=LIMITS[kind] if uses else 0
        row['policies'][name]=dict(feature_kind=kind,chosen_id=chosen,raw_id=raw,samples_ns=times('policy',name),
            median_ns=statistics.median(times('policy',name)),decision_samples_ns=times('decision',name),
            selected_only_samples_ns=prof['samples_ns'],selected_only_median_ns=prof['median_ns'],
            feature_comparisons=charge,kernel_comparisons=prof['comparisons'],total_key_comparisons=charge+prof['comparisons'],
            kernel_bound=prof['bound'],total_key_bound=limit+prof['bound'],status='ok')
        assert charge+prof['comparisons']<=limit+prof['bound']
    return row


class Session:
    def __init__(self,lean,env,directory,limits):
        self.lean=lean;self.env=env;self.directory=directory;self.limits=limits;self.worker=None;self.serial=0;self.peak=0
    def close(self):
        if self.worker:
            self.peak=max(self.peak,self.worker.peak_kib);self.worker.close();self.worker=None
    def start(self,backend,policies):
        self.close();self.serial+=1
        self.worker=Worker(self.lean,self.env,self.directory/f'worker-{backend}-{self.serial}.stderr.log',self.limits,
            OLD/'Worker.lean' if backend=='A' else HERE/'Worker.lean')
        self.worker.configure(policies)

    def measure(self,batch,cases,policies,rounds,total_seconds,backend='A',request_seconds=20):
        save_rows(self.directory/f'dataset-{batch}.jsonl',cases)
        save(self.directory/f'policies-{batch}.json',policies)
        self.start(backend,policies);deadline=time.monotonic()+total_seconds;rows=[]
        with (self.directory/f'events-{batch}.jsonl').open('w') as raw,(self.directory/f'records-{batch}.jsonl').open('w') as records,(self.directory/f'requests-{batch}.jsonl').open('w') as requests:
            for index,case in enumerate(cases):
                base=dict(input_id=case['input_id'],split=case['split'],family=case['family'],n=case['n'],seed=case['seed'],
                    input_sha256=case['input_sha256'],group_id=case['group_id'],family_aliases=case['family_aliases'])
                if time.monotonic()>=deadline:
                    row=dict(base,status='not_executed_total_budget',costs_ns=None,kernels=None,policies=None)
                else:
                    xs=case['input'];started=time.monotonic()
                    req=dict(cmd='bench',input=xs,expected=case['expected'],expected_costs=[evaluate(s,xs)['comparisons'] for s in prior_data.config()['candidate_ids']],
                        expected_features=prior_data.features(xs)[0] if backend=='A' else [feature(k,xs)[0] for k in BUDGETS],
                        policies=list(policies),rounds=rounds,order_seed=index)
                    requests.write(json.dumps(dict(input_id=case['input_id'],request=req))+'\n');requests.flush()
                    def event(e):raw.write(json.dumps(dict(input_id=case['input_id'],event=e))+'\n');raw.flush()
                    try:
                        if self.worker is None:self.start(backend,policies)
                        remaining=deadline-time.monotonic()
                        if remaining<=0:raise WorkerFailure('not_executed_total_budget')
                        response,events=self.worker.request(req,min(request_seconds,remaining),event)
                        row=(prior_measurement.validate if backend=='A' else validate_b)(case,response,events,policies,rounds)
                        assert row['run_lengths']==case['observed_run_lengths']
                        row.update(observed_runs=len(row['run_lengths']),designs=case['designs'],rounds=rounds,backend=backend,
                            request_wall_seconds=time.monotonic()-started,cost_unit='key <=, not wall time; metadata/traversal excluded')
                    except WorkerFailure as e:
                        row=dict(base,status=str(e),costs_ns=None,kernels=None,policies=None,request_wall_seconds=time.monotonic()-started)
                        self.close()
                    except BaseException as e:
                        row=dict(base,status='validation_error: '+repr(e),costs_ns=None,kernels=None,policies=None)
                        records.write(json.dumps(row)+'\n');records.flush();raise
                rows.append(row);records.write(json.dumps(row)+'\n');records.flush()
                print(f'{batch} {index+1}/{len(cases)} {case["input_id"]} {row["status"]}',flush=True)
        self.close()
        return rows
