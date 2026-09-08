#!/usr/bin/env python3
"""One local command: proof replay -> freeze -> paired/confirmation -> extension."""
import argparse
import csv
import datetime
import hashlib
import json
import os
import platform
import statistics
import sys
import time
import uuid

from data_protocol import config, paired, confirmation, smoke, extension, variants, discover, evaluate, plan, tree_stats
from proofs import ROOT,HERE,save,output,hashes,prepare
from worker_process import Worker,WorkerFailure
from report import report


def validate(case,response,selected,rounds,refs,with_profile=True):
    xs=case['input']
    rs,scan=discover(xs)
    assert response['all_outputs_correct'] is True
    assert response['run_lengths']==list(map(len,rs)) and response['run_count']==len(rs)
    assert scan==max(0,len(xs)-1) and len(rs)<=len(xs)
    assert case['expected']==sorted(xs)
    assert [(m['strategy'],m['mode']) for m in response['measurements']]==selected
    if with_profile:
        profiles={p['strategy']:p['profile'] for p in response['profiles']}
        assert set(profiles)=={s for s,_ in selected}
        for s,p in profiles.items():
            for key,value in refs[s].items():
                if key=='output': continue
                assert p[key]==value,(case['id'],s,key,p[key],value)
    else:
        assert not response['profiles']
    rows=[]
    for measured in response['measurements']:
        s,mode=measured['strategy'],measured['mode']
        ref=refs[s]
        assert ref['output']==case['expected']
        assert ref['comparisons']<=ref['bound']
        assert ref['comparisons']==ref['check_comparisons']+ref['merge_or_sort_comparisons']
        if ref['conditional_applicable']: assert ref['comparisons']<=ref['conditional_bound']
        if s.startswith('runs_'):
            weight,budget,depth=tree_stats(plan(rs,s=='runs_length'))
            assert weight==len(xs) and budget==ref['tree_budget']
            assert ref['comparisons']<=scan+budget<=scan+weight*depth
            if s=='runs_count': assert depth<=max(0,len(rs)-1).bit_length()
            if xs==case['expected']: assert ref['comparisons']==scan
        samples=measured['samples_ns']
        assert len(samples)==rounds and all(type(x) is int and x>=0 for x in samples)
        assert measured['observed_counts']==(None if mode=='plain' else [ref['comparisons']]*rounds)
        rows.append(dict(stage=case['stage'],case_id=case['id'],shape=case['shape'],seed=case['seed'],
            input_sha256=case['input_sha256'],strategy=s,mode=mode,n=len(xs),run_count=len(rs),
            run_lengths=list(map(len,rs)),plan=ref.get('plan',s),comparisons=ref['comparisons'],
            check_comparisons=ref['check_comparisons'],sort_comparisons=ref['merge_or_sort_comparisons'],
            bound=ref['bound'],tree_budget=ref['tree_budget'],
            conditional_applicable=ref['conditional_applicable'],conditional_bound=ref['conditional_bound'],
            cost_source='proved symbolic instrumentation (not maintained)' if mode=='plain' else 'measured and independently checked',
            median_ns=statistics.median(samples),min_ns=min(samples),max_ns=max(samples),samples_ns=samples))
    return rows


def request(case,selected,rounds,index,refs,profile):
    return dict(input=case['input'],expected=case['expected'],variants=selected,
        expected_costs=[refs[s]['comparisons'] for s,_ in selected],rounds=rounds,order_seed=index,profile=profile)


def dataset(directory,stage,cases):
    with (directory/f'dataset-{stage}.jsonl').open('w') as f:
        for case in cases: f.write(json.dumps(case)+'\n')


def measure(directory,stage,lean,env,cases,rounds,cfg,phases):
    dataset(directory,stage,cases)
    start=time.perf_counter_ns()
    worker=Worker(lean,env,directory/f'worker-{stage}.stderr.log',cfg)
    phases[stage+'_worker_startup_ns']=time.perf_counter_ns()-start
    rows=[]
    try:
        with (directory/f'observations-{stage}.jsonl').open('w') as log:
            for index,case in enumerate(cases):
                selected=variants()
                refs={s:evaluate(s,case['input']) for s in cfg['strategies']}
                req=request(case,selected,rounds,index,refs,True)
                try:
                    response=worker.request(req,cfg['main_request_timeout_seconds'])
                except Exception as e:
                    log.write(json.dumps(dict(case_id=case['id'],request=req,error=str(e)))+'\n');log.flush()
                    raise
                log.write(json.dumps(dict(case_id=case['id'],request=req,response=response))+'\n');log.flush()
                rows+=validate(case,response,selected,rounds,refs)
                print(f'{stage} {index+1}/{len(cases)} {case["id"]}',flush=True)
    finally:
        phases[stage+'_worker_peak_sampled_rss_kib']=worker.peak_kib
        worker.close()
    phases[stage+'_wall_with_startup_diagnostics_validation_ns']=time.perf_counter_ns()-start
    return rows


def extensions(directory,lean,env,cfg,phases):
    cases=extension()
    dataset(directory,'extension',cases)
    start=time.monotonic()
    deadline=start+cfg['extension_total_budget_seconds']
    rows,statuses=[],[]
    worker=None
    worker_index=0
    peak=0
    try:
        with (directory/'observations-extension.jsonl').open('w') as log:
            for index,case in enumerate(cases):
                choices=variants(False)
                offset=index%len(choices)
                choices=choices[offset:]+choices[:offset]
                refs={s:evaluate(s,case['input']) for s in cfg['strategies']}
                for selected in choices:
                    status=dict(case_id=case['id'],n=len(case['input']),shape=case['shape'],
                        strategy=selected[0],mode=selected[1])
                    req=request(case,[selected],cfg['extension_rounds'],index,refs,False)
                    record=dict(case_id=case['id'],request=req)
                    try:
                        remaining=deadline-time.monotonic()
                        if remaining<=0: raise WorkerFailure('not_run_total_budget')
                        if worker is None:
                            worker_index+=1
                            worker=Worker(lean,env,directory/f'worker-extension-{worker_index}.stderr.log',cfg,
                                startup_timeout=min(45,remaining))
                        remaining=deadline-time.monotonic()
                        if remaining<=0: raise WorkerFailure('not_run_total_budget')
                        response=worker.request(req,min(cfg['extension_request_timeout_seconds'],remaining))
                        record['response']=response
                        rows+=validate(case,response,[selected],cfg['extension_rounds'],refs,False)
                        status['status']='ok'
                    except WorkerFailure as e:
                        status['status']=str(e)
                        if worker is not None:
                            peak=max(peak,worker.peak_kib);worker.close();worker=None
                    record['status']=status
                    log.write(json.dumps(record)+'\n');log.flush()
                    statuses.append(status)
                    print(f'extension n={status["n"]} {case["shape"]} {selected}: {status["status"]}',flush=True)
    finally:
        if worker is not None:
            peak=max(peak,worker.peak_kib);worker.close()
    phases['extension_wall_ns']=int((time.monotonic()-start)*1e9)
    phases['extension_peak_sampled_rss_kib']=peak
    save(directory/'extension-status.json',statuses)
    return rows,statuses


def main():
    if not __debug__: raise RuntimeError('Do not run acceptance with Python -O')
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--smoke',action='store_true')
    args=parser.parse_args()
    stamp=datetime.datetime.now(datetime.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    directory=HERE/'results'/(stamp+('-smoke-' if args.smoke else '-full-')+uuid.uuid4().hex[:6])
    directory.mkdir(parents=True)
    print('results='+str(directory.relative_to(ROOT)),flush=True)
    cfg=config()
    sources=hashes()
    refs={x:output('git','rev-parse',x) for x in ['HEAD','main','refs/stash']}
    save(directory/'source-hashes.json',sources)
    save(directory/'environment.json',dict(branch=output('git','branch','--show-current'),refs=refs,
        platform=platform.platform(),machine=platform.machine(),logical_cpus=os.cpu_count(),physical_memory_bytes=output('sysctl','-n','hw.memsize'),python=sys.version,
        lean=output('lake','env','lean','--version'),git_status=output('git','status','--short'),
        backend='same lean --run and checked modules for every strategy/mode; no native timing',
        memory_budget='worker RSS sampled every >=0.25s; kill above 3GiB, not instantaneous hard cap',
        worker_stack_limit_mib=cfg['worker_stack_limit_mib'],parent_process_not_in_worker_rss=True))
    phases={}
    try:
        lean,env=prepare(directory,phases)
        assert sources==hashes(),'source changed during preparation'
        frozen=dict(config=cfg,smoke=args.smoke,rounds=3 if args.smoke else cfg['rounds'],sources=sources,
            frozen_at=datetime.datetime.now(datetime.timezone.utc).isoformat(),
            paired_sha256=hashlib.sha256((ROOT/cfg['paired_data']).read_bytes()).hexdigest(),
            all_strategies_preselected=True,no_confirmation_results_seen=True,
            time_unit='ns; sum of per-input medians is descriptive, not independent repetitions',
            primary_comparison='A/B/C within same algorithm; algorithms compared within same mode')
        save(directory/'frozen.json',frozen)
        # Only now generate the independently seeded confirmation inputs.
        stages=[('smoke',smoke())] if args.smoke else [('paired',paired()),('confirmation',confirmation())]
        rows=[]
        for stage,cases in stages:
            rows+=measure(directory,stage,lean,env,cases,frozen['rounds'],cfg,phases)
        ext_status=[]
        if not args.smoke:
            ext_rows,ext_status=extensions(directory,lean,env,cfg,phases)
            rows+=ext_rows
        assert sources==hashes(),'source changed after freeze'
        assert refs=={x:output('git','rev-parse',x) for x in refs},'git refs changed'
        save(directory/'rows.json',rows)
        with (directory/'summary.csv').open('w') as f:
            writer=csv.DictWriter(f,fieldnames=list(rows[0]))
            writer.writeheader()
            for row in rows:
                writer.writerow({k:json.dumps(v) if isinstance(v,(list,dict)) else v for k,v in row.items()})
        report(directory,rows,ext_status)
        save(directory/'validation.json',dict(passed=True,source_hashes_unchanged=True,refs_unchanged=True,
            output_and_counts_checked=True,rows=len(rows),timed_repetitions=sum(len(r['samples_ns']) for r in rows),
            independent_inputs={s:len(c) for s,c in stages},extension_failures_retained=True))
        print('ACCEPTED '+str(directory.relative_to(ROOT)),flush=True)
    except BaseException as e:
        save(directory/'failure.json',dict(error=str(e),type=type(e).__name__))
        raise
    finally:
        save(directory/'phase-wall-times.json',phases)


if __name__=='__main__':
    main()
