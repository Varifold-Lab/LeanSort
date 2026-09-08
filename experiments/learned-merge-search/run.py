"""One-shot bounded experiment; new result directories, durable stage records."""
import argparse
from collections import defaultdict
from datetime import datetime,timezone
import gc
import json
import os
from pathlib import Path
import platform
import random
import resource
import signal
import statistics
import subprocess
import sys
import time
import traceback
import tracemalloc
import uuid
from build_checks import HERE,ROOT,prepare,preserved,sources
from core import *
from reference import dp,lower_check
from data import generate,diagnostics,audit_splits,digest
from learning import labels,fit
from certificates import Checker,kernel_proof


def now():return datetime.now(timezone.utc).isoformat()
def save(p,o):p.write_text(json.dumps(o,indent=2,sort_keys=True)+'\n')
def append(p,o):
    with p.open('a') as f:f.write(json.dumps(o,separators=(',',':'))+'\n');f.flush()
def write_rows(p,rows):
    with p.open('w') as f:
        for r in rows:f.write(json.dumps(r,separators=(',',':'))+'\n')
def log(out,s):
    with (out/'decisions.zh.log').open('a') as f:f.write(now()+' '+s+'\n')
    save(out/'checkpoint.json',dict(stage=s,time=now(),directory=str(out)))


def alarm(signum,frame):raise TimeoutError('unified request deadline')


def limited(fn,seconds):
    signal.signal(signal.SIGALRM,alarm);signal.setitimer(signal.ITIMER_REAL,seconds)
    try:return fn()
    finally:signal.setitimer(signal.ITIMER_REAL,0)


def measure_reference(ls,rounds):
    ref=None;times=[]
    for _ in range(rounds):
        a=time.perf_counter_ns();ref=dp(ls);times.append(time.perf_counter_ns()-a)
        assert lower_check(ls,ref['table']) and stats(ref['tree'],ls)[1]==ref['budget']
    gc.collect();tracemalloc.start();tracemalloc.reset_peak()
    before=tracemalloc.get_traced_memory()[0];a=time.perf_counter_ns();replay=dp(ls)
    traced_ns=time.perf_counter_ns()-a;current,peak=tracemalloc.get_traced_memory();tracemalloc.stop()
    assert replay==ref
    return dict(**ref,times_ns=times,median_ns=statistics.median(times),peak_python_bytes=peak-before,
        retained_python_bytes=current-before,traced_replay_ns=traced_ns,
        memory_scope='tracemalloc allocation peak of separate full DP+reconstruction replay; not process RSS or formal space')


def summarize_search(row,ref,nodebudgets,wall):
    opt=ref['budget'];events=row['events']
    result=dict(at_nodes={},first_optimal_ns=None,first_target_ns=None,wall_budget=wall)
    for event in events:
        if event['budget']==opt and result['first_optimal_ns'] is None:result['first_optimal_ns']=event['elapsed_ns']
        if 100*event['budget']<=101*opt and result['first_target_ns'] is None:result['first_target_ns']=event['elapsed_ns']
    for n in nodebudgets:
        eligible=[e for e in events if e['nodes']<=n]
        b=eligible[-1]['budget']
        point=next((t for t in row['timeline'] if t['nodes']==n),None)
        result['at_nodes'][str(n)]=dict(budget=b,ratio=b/opt if opt else 1,
            elapsed_ns=point['elapsed_ns'] if point else row['elapsed_ns'],exhausted_before_budget=row['nodes']<n)
    if wall is not None:
        eligible=[e for e in events if e['elapsed_ns']<=wall]
        b=eligible[-1]['budget'] if eligible else None
        result.update(timely_budget=b,timely_ratio=b/opt if b is not None and opt else (1 if b==0 else None),
            overrun_ns=max(0,row['elapsed_ns']-wall))
    return result


def pilot(out,c,lean,env,smoke):
    rows=[];start=time.perf_counter();used={};max_r=0
    for r in c['pilot_rs']:
        if smoke and r>8:continue
        if time.perf_counter()-start>c['pilot_total_seconds']:break
        case=generate('pilot',[c['pilot_seed']],[r],used,False)[0]
        try:
            ref=limited(lambda:measure_reference(case['lengths'],1),c['max_request_seconds'])
            searches={o:limited(lambda o=o:search(case['lengths'],o,128,model={'nodes':[[-1,0,0,0]]}),c['max_request_seconds']) for o in ['fixed','heuristic','learned']}
            tracemalloc.start();tracemalloc.reset_peak()
            memory_replay=search(case['lengths'],'learned',128,model={'nodes':[[-1,0,0,0]]})
            search_peak=tracemalloc.get_traced_memory()[1];tracemalloc.stop()
            peak=max(ref['peak_python_bytes'],search_peak);worst=max(x['elapsed_ns'] for x in searches.values())
            acceptable=worst<1_000_000_000 and ref['median_ns']<500_000_000 and peak<64*1024*1024
            if acceptable:max_r=r
            row=dict(case=case,reference=ref,searches=searches,search_peak_python_bytes=search_peak,accepted=acceptable,status='ok')
        except Exception as e:row=dict(case=case,status='failed',error=str(e),accepted=False)
        rows.append(row);append(out/'pilot.jsonl',row)
    if max_r<4:raise RuntimeError('pilot did not support minimum scope')
    core=[r for r in c['train_rs'] if r<=min(max_r,8 if smoke else 16)]
    extra=[r for r in [24,32] if r<=max_r] if not smoke else []
    protocol=dict(frozen_at=now(),core_rs=core,extrapolation_rs=extra,max_r=max_r,
        node_budgets=c['node_budgets'] if not smoke else [8,16,32],
        wall_budgets_ns=c['wall_budgets_ns'] if not smoke else [1000000],
        request_seconds=c['max_request_seconds'],total_seconds=c['total_search_seconds'],
        memory_mib=c['memory_limit_mib'],rounds=c['rounds'] if not smoke else 1,
        not_executed_rs=[r for r in c['pilot_rs'] if r>max_r],
        selection_basis='pilot time and allocation budget only; no comparison of relative search quality')
    save(out/'formal-protocol.json',protocol);return protocol,rows


def compare(case,model,out,protocol,phase,budget_start,do_wall=True):
    ls=case['lengths'];rows=[];rounds=protocol['rounds']
    # Run search BEFORE calculating the confirmation reference, never hand OPT to core.
    methods=['fixed','heuristic','learned']
    for mode in ['nodes']+(['wall'] if do_wall else []):
        budgets=[None] if mode=='nodes' else protocol['wall_budgets_ns']
        for wall in budgets:
            for repeat in range(rounds):
                order=methods[repeat%3:]+methods[:repeat%3]
                if int(case['input_sha256'][:2],16)%2:order=list(reversed(order))
                for method in order:
                    base=dict(input_id=case['input_id'],phase=phase,mode=mode,wall_limit_ns=wall,method=method,repeat=repeat)
                    if time.perf_counter()-budget_start>protocol['total_seconds']:
                        row=dict(**base,status='not_executed_total_budget',budget=None,elapsed_ns=None)
                    else:
                        try:
                            result=limited(lambda:search(ls,method,max(protocol['node_budgets']) if wall is None else 50000,wall,model),protocol['request_seconds'])
                            row=dict(**base,**result)
                        except TimeoutError as e:row=dict(**base,status='timeout',budget=None,elapsed_ns=None,error=str(e))
                    rows.append(row);append(out/f'search-{phase}.jsonl',row)
    ref=limited(lambda:measure_reference(ls,rounds),protocol['request_seconds'])
    baseline={}
    for name in ['count','length']:
        times=[]
        for _ in range(rounds):
            a=time.perf_counter_ns();tree=plan(ls,name);b=stats(tree,ls)[1];times.append(time.perf_counter_ns()-a)
        baseline[name]=dict(tree=tree,budget=b,times_ns=times,median_ns=statistics.median(times))
    for r in rows:
        if r['status']=='ok':
            assert r['budget']>=ref['budget'] and valid(r['tree'],ls)
            r['quality']=summarize_search(r,ref,protocol['node_budgets'],r['wall_limit_ns'])
    result=dict(case=case,reference=ref,baselines=baseline,searches=rows)
    append(out/f'evaluation-{phase}.jsonl',result);return result


def main():
    args=argparse.ArgumentParser();args.add_argument('--smoke',action='store_true');a=args.parse_args()
    c=json.loads((HERE/'config.json').read_text());mode='smoke' if a.smoke else 'full'
    out=HERE/'results'/(datetime.now(timezone.utc).strftime('%Y%m%dT%H%M%SZ')+'-'+mode+'-'+uuid.uuid4().hex[:6]);out.mkdir(parents=True)
    print(out,flush=True);checker=None
    try:
        original_count=preserved();save(out/'preregistered.json',c)
        save(out/'environment.json',dict(platform=platform.platform(),python=sys.version,branch=subprocess.check_output(['git','branch','--show-current'],text=True).strip(),
            head=subprocess.check_output(['git','rev-parse','HEAD'],text=True).strip(),started=now(),backend='local Python CPU search/DP; unchanged Lean direct List executor for checked samples'))
        log(out,'构建、旧新测试、精化与证书定理重新编译。')
        lean,env,checks=prepare(out);save(out/'build-checks.json',checks)
        protocol,pilots=pilot(out,c,lean,env,a.smoke);log(out,'pilot 后冻结正式资源与段数范围。')
        # Concrete proof pilot is independent, not a test-quality filter.
        first=pilots[0];save(out/'pilot-kernel-proof.json',kernel_proof(first['case'],first['reference'],[first['reference']['tree']],out/'PilotCertificate.lean',lean,env,c['lean_certificate_seconds']))
        freeze_sources=sources();save(out/'source-hashes.json',freeze_sources)
        offset=c['smoke_seed_offset'] if a.smoke else 0
        seeds=lambda key:[x+offset for x in (c[key][:1] if a.smoke else c[key])]
        used={tuple([1]*r):'reserved_equal' for r in protocol['core_rs']+protocol['extrapolation_rs']};train=generate('train',seeds('train_seeds'),protocol['core_rs'],used)
        val=generate('validation',seeds('validation_seeds'),protocol['core_rs'],used)
        write_rows(out/'dataset-train.jsonl',train);write_rows(out/'dataset-validation.jsonl',val)
        save(out/'split-development.json',audit_splits({'train':train,'validation':val}))
        log(out,'仅用训练向量 DP 续接 regret 生成标签并训练两棵 CPU 回归树。')
        training,label_stats=labels(train);write_rows(out/'training-labels.jsonl',training);save(out/'label-cost.json',label_stats)
        models=[fit(training,depth,c['min_leaf']) for depth in c['depths']]
        (out/'models').mkdir()
        for m in models:save(out/'models'/f'depth-{m["hyperparameters"]["depth"]}.json',m)
        valrows=[];validation_start=time.perf_counter();scores=[]
        # Frozen single validation node budget, model never sees reference.
        nb=16 if a.smoke else 128
        for m in models:
            ratios=[];times=[]
            for case in val:
                result=limited(lambda:search(case['lengths'],'learned',nb,model=m),protocol['request_seconds'])
                ref=measure_reference(case['lengths'],1)
                ratios.append(result['budget']/ref['budget']);times.append(result['elapsed_ns'])
                row=dict(input_id=case['input_id'],depth=m['hyperparameters']['depth'],result=result,reference=ref)
                valrows.append(row);append(out/'validation-models.jsonl',row)
            scores.append((statistics.mean(ratios),statistics.mean(times),m['hyperparameters']['depth']))
        validation_wall_seconds=time.perf_counter()-validation_start
        selected=min(range(len(models)),key=lambda i:scores[i]);model=models[selected]
        frozen=dict(frozen_at=now(),model=model,model_sha256=digest(model),validation_scores=scores,
            selected_depth=model['hyperparameters']['depth'],protocol=protocol,source_hashes=freeze_sources)
        save(out/'frozen.json',frozen)
        assert digest(json.loads((out/'frozen.json').read_text())['model'])==frozen['model_sha256']
        log(out,'模型、协议及源码冻结；现在生成全新确认／外推输入。')
        test=generate('confirmation',seeds('confirmation_seeds'),protocol['core_rs'],used)
        extrap=generate('extrapolation',seeds('extrapolation_seeds'),protocol['extrapolation_rs'],used,False)
        diag=diagnostics(protocol['core_rs'])
        allsplits={'train':train,'validation':val,'confirmation':test,'extrapolation':extrap,'structural_diagnostic':diag}
        save(out/'split-final.json',audit_splits(allsplits))
        for phase,rows in [('confirmation',test),('extrapolation',extrap),('structural_diagnostic',diag)]:write_rows(out/f'dataset-{phase}.jsonl',rows)
        checker=Checker(out,lean,env,c['lean_request_seconds']);evaluations=[];certs=[];start=time.perf_counter();counter=0
        requests=[(phase,case) for phase,rows in [('confirmation',test),('extrapolation',extrap),('structural_diagnostic',diag)] for case in rows]
        random.Random(8600009).shuffle(requests)
        # Total search budget excludes certificate/replay time; separate counter clock.
        search_used=0.0;proof_keys=set()
        for phase,case in requests:
            astart=time.perf_counter();entry=compare(case,model,out,protocol,phase,time.perf_counter()-search_used)
            search_used+=time.perf_counter()-astart
            evaluations.append(entry);trees=[entry['reference']['tree']]+[b['tree'] for b in entry['baselines'].values()]
            trees += [s['tree'] for s in entry['searches'] if s['status']=='ok']
            # Include every improvement and checkpoint-reported candidate, not just final winners.
            trees += [e['tree'] for s in entry['searches'] if s['status']=='ok' for e in s['events']]
            unique={json.dumps(t,separators=(',',':')):t for t in trees};trees=list(unique.values())
            execute_case=case['n']<=6000 and ((case['r'],case['family']) not in proof_keys)
            resp=checker.request(case,entry['reference'],trees,execute_case)
            proofkey=case['r']
            # One independently kernel-normalized representative for each observed r.
            kernel=None
            if proofkey not in proof_keys:
                kernel=kernel_proof(case,entry['reference'],trees,out/f'Certificate-{case["r"]}.lean',lean,env,c['lean_certificate_seconds'])
                proof_keys.add(proofkey)
            proof_keys.add((case['r'],case['family']))
            cert=dict(input_id=case['input_id'],trees=len(trees),response=resp,kernel_proof=kernel,
                scope='universal Lean checker soundness + executable acceptance; kernel normalization additionally on listed representatives')
            certs.append(cert);append(out/'certificates.jsonl',cert);counter+=1
            if counter%20==0:log(out,f'已保存 {counter}/{len(requests)} 个确认／外推实例；不调整模型。')
            peak=resource.getrusage(resource.RUSAGE_SELF).ru_maxrss
            if sys.platform=='darwin':peak//=1024
            if peak>protocol['memory_mib']*1024:raise MemoryError('Python process exceeded sampled memory budget')
        # Explicit invalid-ID/reordered tree fallback with the same certified execution.
        badcase=dict(input_id='invalid-fallback',lengths=[1,1,2],source_input=None)
        bad=checker.request(badcase,dp(badcase['lengths']),[(2,(1,0)),[0,0],-1],True,True)
        assert not any(bad['fits']);save(out/'fallback-check.json',bad)
        checker.close();checker=None
        assert sources()==freeze_sources and digest(model)==frozen['model_sha256']
        assert preserved()==original_count
        save(out/'timing-phases.json',dict(validation_wall_seconds=validation_wall_seconds,
            measured_evaluation_including_reference_seconds=search_used,certified_phase_wall_seconds=time.perf_counter()-start,
            training_ns=sum(m['fit_ns'] for m in models),label_cost=label_stats,
            note='No search, label, certification or training time counted as sorting-kernel latency'))
        import reporting
        reporting.report(out,evaluations,certs,frozen,label_stats)
        statuses=defaultdict(int)
        for e in evaluations:
            for r in e['searches']:statuses[r['status']]+=1
        save(out/'acceptance.json',dict(passed=not any(k!='ok' for k in statuses),statuses=dict(statuses),
            original_files_unchanged=original_count,source_and_model_unchanged=True,formal_checks=checks['theorems'],
            cases=len(evaluations),trees_checked=sum(x['trees'] for x in certs),kernel_certified_rs=sorted(x for x in proof_keys if isinstance(x,int)),
            final_no_retuning=True,split=audit_splits(allsplits)))
        log(out,'实验按冻结范围结束；证据已保存，不继续搜索正结果。')
        print('FINISHED '+str(out/'findings.zh.md'),flush=True)
    except Exception:
        save(out/'failure.json',dict(time=now(),error=traceback.format_exc(),checkpoint=str(out/'checkpoint.json')))
        print(traceback.format_exc(),flush=True);raise
    finally:
        if checker:checker.close()

if __name__=='__main__':main()
