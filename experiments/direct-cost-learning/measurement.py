"""Validate streamed repetitions and persist versioned direct-cost records."""
from collections import defaultdict
import json
import statistics

from data_protocol import features,evaluate,discover,config
from learning import predict_raw,resolve,predict_values


def policy_prediction(policy,fs):
    kind=policy['kind']
    if kind=='fixed':return policy['id']
    if kind=='sample_rule':return 1 if fs[0]<=32 else (5 if fs[2]<=125 else 1)
    if kind=='length_rule':return 1 if fs[0]<=32 else 5
    if kind=='learned':return predict_raw(policy['model'],fs)
    return None


def validate(case,response,events,policies,rounds):
    cfg=config();xs=case['input'];fs,fc=features(xs)
    assert response['all_outputs_correct']
    assert response['features']==fs and response['feature_comparisons']==fc
    assert fc<=80
    rs,_=discover(xs);assert response['run_lengths']==list(map(len,rs))
    profiles=response['kernel_profiles'];assert [p['id'] for p in profiles]==list(range(7))
    for p in profiles:
        ref=evaluate(cfg['candidate_ids'][p['id']],xs)
        assert ref['output']==case['expected']==sorted(xs)
        for a,b in [('comparisons','comparisons'),('check_comparisons','check_comparisons'),
            ('sort_comparisons','merge_or_sort_comparisons'),('bound','bound'),
            ('conditional_applicable','conditional_applicable'),('conditional_bound','conditional_bound')]:
            assert p[a]==ref[b],(case['input_id'],p['id'],a,p[a],ref[b])
        assert p['comparisons']<=p['bound']
        if p['conditional_applicable']:assert p['comparisons']<=p['conditional_bound']
    predicted={p['name']:p for p in response['predictions']}
    assert set(predicted)==set(policies)
    for name,policy in policies.items():
        raw=policy_prediction(policy,fs);record=predicted[name]
        assert record['raw_id']==raw and record['chosen_id']==resolve(raw),(name,record,raw)
        assert record['uses_features']==(policy['kind'] in ['sample_rule','learned'])
        if policy['kind']=='learned':assert record['values']==predict_values(policy['model']['tree'],fs)
    grouped=defaultdict(list);seen=set()
    for e in events:
        assert type(e['ns']) is int and e['ns']>0
        key=(e['category'],e['name'],e['round']);assert key not in seen;seen.add(key)
        assert -1<=e['round']<rounds
        if e['category']=='kernel':assert e['chosen_id']==int(e['name'])
        elif e['category'] in ['policy','decision']:assert e['chosen_id']==predicted[e['name']]['chosen_id']
        else:assert e['category']=='features' and e['name']=='features'
        grouped[e['category'],e['name']].append(e)
    expected_keys={('kernel',str(i)) for i in range(7)}|{('features','features')}|{(category,name) for category in ['policy','decision'] for name in policies}
    assert set(grouped)==expected_keys
    for (category,_),values in grouped.items():
        assert {e['round'] for e in values}==set(range(-1 if category in ['kernel','policy'] else 0,rounds))
    def samples(category,name):return [e['ns'] for e in sorted(grouped[category,name],key=lambda e:e['round']) if e['round']>=0]
    kernel_times={i:samples('kernel',str(i)) for i in range(7)}
    record=dict(input_id=case['input_id'],input_sha256=case['input_sha256'],group_id=case['group_id'],
        base_sha256=case['base_sha256'],seed=case['seed'],family=case['family'],family_aliases=case['family_aliases'],
        split=case['split'],n=len(xs),features=fs,feature_samples_ns=samples('features','features'),
        feature_comparisons=fc,run_lengths=response['run_lengths'],status='ok',
        costs_ns=[statistics.median(kernel_times[i]) for i in range(7)],
        kernels=[dict(p,samples_ns=kernel_times[p['id']],median_ns=statistics.median(kernel_times[p['id']]),
            algorithm_id=cfg['candidate_ids'][p['id']],status='ok') for p in profiles],
        policies={})
    for name,policy in policies.items():
        chosen=predicted[name]['chosen_id'];p=profiles[chosen]
        charged=fc if predicted[name]['uses_features'] else 0
        record['policies'][name]=dict(chosen_id=chosen,raw_id=predicted[name]['raw_id'],
            samples_ns=samples('policy',name),median_ns=statistics.median(samples('policy',name)),
            decision_samples_ns=samples('decision',name),
            selected_only_samples_ns=kernel_times[chosen],selected_only_median_ns=record['costs_ns'][chosen],
            feature_comparisons=charged,kernel_comparisons=p['comparisons'],total_key_comparisons=charged+p['comparisons'],
            kernel_bound=p['bound'],total_key_bound=80+p['bound'] if charged else p['bound'],
            status='ok',cost_scope='source-level key <= comparisons; excludes metadata tests, List traversal and machine time')
        assert record['policies'][name]['total_key_comparisons']<=record['policies'][name]['total_key_bound']
    return record


def measure(worker,directory,batch,cases,policies,rounds,versions,deadline):
    import time
    cfg=config();worker.configure(policies)
    records=[]
    raw_path=directory/f'events-{batch}.jsonl'
    with raw_path.open('w') as stream,(directory/f'requests-{batch}.jsonl').open('w') as requests, (directory/f'records-{batch}.jsonl').open('w') as final:
        for index,case in enumerate(cases):
            expected_costs=[evaluate(s,case['input'])['comparisons'] for s in cfg['candidate_ids']]
            req=dict(cmd='bench',input=case['input'],expected=case['expected'],expected_features=features(case['input'])[0],
                expected_costs=expected_costs,policies=list(policies),rounds=rounds,order_seed=index)
            requests.write(json.dumps(dict(batch=batch,input_id=case['input_id'],request=req))+'\n');requests.flush()
            def event(e):
                stream.write(json.dumps(dict(batch=batch,input_id=case['input_id'],event=e))+'\n');stream.flush()
            try:
                remaining=deadline-time.monotonic()
                if remaining<=0:raise RuntimeError('not_run_total_budget')
                response,events=worker.request(req,min(cfg['worker_request_timeout_seconds'],remaining),event)
                row=validate(case,response,events,policies,rounds)
                row.update(batch=batch,versions=versions,measurement_config=dict(backend=cfg['backend'],rounds=rounds,
                    output_consumption='full checksum and IO sink before stop clock',streaming='per-repetition events outside timed region'))
            except BaseException as e:
                failed=dict(batch=batch,input_id=case['input_id'],status=str(e),features=features(case['input'])[0],
                    kernels=[dict(id=i,algorithm_id=s,status='request_failed_or_unreturned',samples_ns=None,median_ns=None)
                        for i,s in enumerate(cfg['candidate_ids'])],policies=None)
                final.write(json.dumps(failed)+'\n');final.flush()
                for pending in cases[index+1:]:
                    final.write(json.dumps(dict(batch=batch,input_id=pending['input_id'],status='not_executed_after_failure',
                        kernels=[dict(id=i,status='not_executed',samples_ns=None,median_ns=None) for i in range(7)]))+'\n')
                final.flush()
                # Completed repetitions are already durable in the event stream.
                raise
            final.write(json.dumps(row)+'\n');final.flush();records.append(row)
            print(f'{batch} {index+1}/{len(cases)} {case["input_id"]}',flush=True)
    return records
