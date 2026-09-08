#!/usr/bin/env python3
"""Bounded pilot -> frozen A diagnosis -> independent B training/freeze/confirmation."""
import argparse
import datetime
import math
import os
import platform
import time
import uuid
from common import *
from checks import prepare
from measure import Session
import build_checks as old_build


def stamp():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def log(p,msg):
    with (p/'decisions.zh.log').open('a') as f:f.write(stamp()+' '+msg+'\n')
    print(msg,flush=True)

def totals(rows):
    assert rows and all(r['status']=='ok' for r in rows),'incomplete B data; cannot train/select silently'
    return {k:sum(r['policies'][k]['median_ns'] for r in rows) for k in rows[0]['policies']}

def integration(session,p):
    policies={}
    for kind in BUDGETS:
        def model(tree,feature_version=None):return dict(schema_version=1,candidate_version='verified-direct-seven-v1',
            feature_version=feature_version or f'budget-{kind}-v1',kind='classifier',tree=tree)
        policies[kind]=dict(kind='rule',feature_kind=kind,length_cut=32,descent_cut=125)
        policies[kind+'-bad']=dict(kind='learned',feature_kind=kind,model=model(dict(kind='leaf',values=[99])))
        policies[kind+'-mismatch']=dict(kind='learned',feature_kind=kind,model=model(dict(kind='leaf',values=[0]),'unsupported'))
    session.start('B',policies);checks=[]
    for xs in [[],[7],[3,2,1],[1,1,2,0,5],list(range(70))]:
        response,_=session.worker.request(dict(cmd='infer',input=xs))
        for r in response['outputs']:
            kind=policies[r['name']]['feature_kind']
            assert r['features']==feature(kind,xs)[0] and r['output']==sorted(xs)
            if r['name']!=kind:assert r['chosen_id']==1
            else:assert r['chosen_id']==predict(policies[r['name']],feature(kind,xs)[0])
        checks.append(dict(input=xs,response=response))
    save(p/'integration.json',dict(passed=True,checks=checks));session.close()


def pilot_protocol(p,session,c,smoke):
    lengths=[32,96] if smoke else c['pilot_lengths']
    cases=generate('pilot',lengths,[9100001 if smoke else c['pilot_seed']],families=['random','reverse'])
    pilot=session.measure('pilot',cases,old_policies(),1,c['pilot_total_seconds'],'A',c['pilot_request_seconds'])
    stats={n:max(r['request_wall_seconds'] for r in pilot if r['n']==n and r['status']=='ok')
        for n in lengths if all(r['status']=='ok' for r in pilot if r['n']==n)}
    assert 32 in stats,'pilot cannot execute minimum input'
    target=[32,96] if smoke else c['core_lengths']
    excluded=[]
    def estimate(n):
        cover=[x for x in stats if x>=n]
        return stats[min(cover)]*c['rounds'] if cover else float('inf')
    if not smoke:
        for n in c['extension_lengths']:
            estimate_all=sum(estimate(x)*len(FAMILIES)*len(c['a_seeds']) for x in target+[n])
            if estimate_all<=c['a_total_seconds']*.75:target.append(n)
            else:excluded.append(dict(n=n,status='not_executed_pilot_budget_forecast',estimated_a_seconds=estimate_all if math.isfinite(estimate_all) else None))
    request=min(c['formal_request_max_seconds'],max(c['formal_request_min_seconds'],math.ceil(max(stats.values())*c['rounds']*3)))
    # All requests share the same limits, independent of selected strategy.
    rss=min(c['pilot_safety_rss_mib'],max(2048,math.ceil(session.peak*1.5/(256*1024))*256))
    result=dict(frozen_at=stamp(),lengths=target,excluded_lengths=excluded,pilot_request_seconds_by_length=stats,
        request_seconds=request,rss_limit_mib=rss,stack_mib=8,a_total_seconds=c['a_total_seconds'],b_total_seconds=c['b_total_seconds'],
        rounds=c['rounds'],selection_basis='request wall/RSS only, never relative candidate/selector performance',
        b_lengths=[32,96] if smoke else [n for n in c['b_lengths'] if n<=max(target)])
    save(p/'formal-protocol.json',result);return result,pilot


def main():
    if not __debug__:raise RuntimeError('Do not disable acceptance assertions')
    parser=argparse.ArgumentParser();parser.add_argument('--smoke',action='store_true');args=parser.parse_args()
    c=config();p=HERE/'results'/(datetime.datetime.now(datetime.timezone.utc).strftime('%Y%m%dT%H%M%SZ')+('-smoke-' if args.smoke else '-full-')+uuid.uuid4().hex[:6]);p.mkdir(parents=True)
    print('results='+str(p.relative_to(ROOT)),flush=True)
    sources=source_hashes();save(p/'source-hashes.json',sources);save(p/'preregistered.json',c)
    old=ROOT/c['previous_result'];old_models={k:json.loads((old/f'final-{k}.json').read_text()) for k in ['classifier','cost_ranking']}
    save(p/'stage-a-frozen-models.json',old_models)
    save(p/'environment.json',dict(branch=old_build.output('git','branch','--show-current'),head=old_build.output('git','rev-parse','HEAD'),
        main=old_build.output('git','rev-parse','main'),stash=old_build.output('git','rev-parse','refs/stash'),platform=platform.platform(),
        python=platform.python_version(),cpus=os.cpu_count(),cpu=old_build.output('sysctl','-n','machdep.cpu.brand_string'),
        memory_bytes=old_build.output('sysctl','-n','hw.memsize'),lean=old_build.output('lake','env','lean','--version')))
    session=None;phases={}
    def checkpoint(stage):
        assert source_hashes()==sources
        save(p/'checkpoint.json',dict(stage=stage,at=stamp(),original_files_preserved=preserved(),source_unchanged=True))
    try:
        checkpoint('before_build');log(p,'开始构建、公理和编译检查；不修改旧文件。')
        lean,env=prepare(p,phases)
        limits=dict(worker_rss_limit_mib=c['pilot_safety_rss_mib'],worker_stack_limit_mib=8)
        session=Session(lean,env,p,limits);integration(session,p)
        proto,pilot=pilot_protocol(p,session,c,args.smoke);session.limits['worker_rss_limit_mib']=proto['rss_limit_mib']
        checkpoint('pilot_done');log(p,'正式资源协议已由独立 pilot 冻结：'+json.dumps(proto,ensure_ascii=False))
        a_seeds=[9200001] if args.smoke else c['a_seeds']
        a_cases=generate('diagnostic',proto['lengths'],a_seeds,structure=not args.smoke)
        # Interleave sizes/families reproducibly to reduce time/temperature confounding.
        random.Random(10001).shuffle(a_cases)
        a=session.measure('A',a_cases,old_policies(),c['rounds'],proto['a_total_seconds'],'A',proto['request_seconds'])
        checkpoint('A_done');log(p,'A 完成；只作诊断，数据不用于 B 训练或确认。')
        training=generate('train',proto['b_lengths'],[9300001,9300011] if args.smoke else c['b_train_seeds'])
        validation=generate('validation',proto['b_lengths'],[9400001] if args.smoke else c['b_validation_seeds'])
        collections=dict(pilot=[dict(r,split='pilot') for r in generate('pilot',[32,96] if args.smoke else c['pilot_lengths'],[9100001 if args.smoke else c['pilot_seed']],families=['random','reverse'])],
            diagnostic=a_cases,train=training,validation=validation)
        save(p/'split-before-confirmation.json',prior_data.assert_split_integrity(collections))
        deadline=time.monotonic()+proto['b_total_seconds']
        train=session.measure('B-train',training,{},c['rounds'],max(0,deadline-time.monotonic()),'B',proto['request_seconds'])
        assert all(r['status']=='ok' for r in train),'missing training labels; retained, not imputed'
        entries={};models_dir=p/'models';models_dir.mkdir()
        for budget in BUDGETS:
            inputs=[dict(r,features=r['features_by_budget'][budget]) for r in train]
            for kind in ['classifier','cost_ranking']:
                for depth in c['depths']:
                    m=prior_learning.fit(inputs,kind,depth,c['min_leaf'])
                    m.update(feature_version=f'budget-{budget}-v1',feature_kind=budget,
                        feature_names=['length','probe_count','descent_permille','unused_0','unused_1','unused_2'] if budget!='legacy' else prior_data.config()['feature_names'])
                    name=f'{budget}-{kind}-d{depth}';save(models_dir/(name+'.json'),m)
                    entries[name]=dict(kind='learned',feature_kind=budget,model=m)
            for lc in c['rule_length_cuts']:
                for dc in c['rule_descent_cuts']:
                    entries[f'{budget}-rule-n{lc}-d{dc}']=dict(kind='rule',feature_kind=budget,length_cut=lc,descent_cut=dc)
        fixed=dict(fixed=dict(kind='fixed',feature_kind='length',id=5),hybrid=dict(kind='fixed',feature_kind='length',id=1))
        save(p/'B-trained-before-validation.json',entries);checkpoint('B_trained')
        val=session.measure('B-validation',validation,dict(fixed,**entries),c['rounds'],max(0,deadline-time.monotonic()),'B',proto['request_seconds'])
        cost=totals(val);selected={};selection={}
        for budget in BUDGETS:
            for kind in ['classifier','cost_ranking','rule']:
                options=[name for name in entries if name.startswith(budget+'-'+kind+'-')]
                best=min(options,key=lambda name:(cost[name],name));key=budget+'-'+kind
                selected[key]=entries[best];selection[key]=dict(source=best,validation_e2e_ns=cost[best])
        best_budget={kind:min([k for k in selection if k.endswith('-'+kind)],key=lambda k:(selection[k]['validation_e2e_ns'],k)) for kind in ['classifier','cost_ranking','rule']}
        # Same frozen historical trees, re-tagged only for the legacy feature dispatcher.
        previous={}
        for kind,m in old_models.items():previous['old_'+kind]=dict(kind='learned',feature_kind='legacy',model=dict(m,feature_version='budget-legacy-v1'))
        previous['old_rule']=dict(kind='rule',feature_kind='legacy',length_cut=32,descent_cut=125)
        deployed=dict(fixed,**selected,**previous)
        frozen=dict(frozen_at=stamp(),sources=sources,protocol=proto,policies=deployed,selection=selection,best_budget=best_budget,
            all_validation_e2e_ns=cost,confirmation_not_yet_generated=True,models_hash=jsonhash(deployed))
        save(p/'B-frozen.json',frozen);checkpoint('B_frozen');log(p,'B 模型／规则／预算配置全部冻结，现在才生成确认输入。')
        confirm=generate('confirmation',proto['b_lengths'],[9500001] if args.smoke else c['b_confirmation_seeds'])
        collections['confirmation']=confirm
        save(p/'split-final.json',prior_data.assert_split_integrity(collections))
        prior=prior_data.old_hashes()
        for path in (OLD/'results').glob('*/dataset-*.jsonl'):
            for r in load_rows(path):prior.add(digest(r['input']))
        assert not prior.intersection(r['input_sha256'] for r in confirm)
        result=session.measure('B-confirmation',confirm,deployed,c['rounds'],max(0,deadline-time.monotonic()),'B',proto['request_seconds'])
        assert all(r['status']=='ok' for r in result),'incomplete confirmation retained, not a successful full acceptance'
        assert jsonhash(json.loads((p/'B-frozen.json').read_text())['policies'])==frozen['models_hash']
        assert old_models=={k:json.loads((old/f'final-{k}.json').read_text()) for k in old_models}
        checkpoint('measurements_done')
        from reporting import report
        report(p,a,val,result,proto,frozen)
        save(p/'acceptance.json',dict(passed=True,original_files=preserved(),source_unchanged=True,models_unchanged=True,
            a_completed=sum(r['status']=='ok' for r in a),a_total=len(a),b_training=len(train),b_validation=len(val),b_confirmation=len(result),
            trained_models=len(list(models_dir.glob('*.json'))),feature_export_counts_outputs_verified=True,
            theorem_recompilation_and_axioms_passed=True,no_test_tuning=True))
        checkpoint('accepted');log(p,'有界实验完成；不根据确认结果继续调参。')
        print('ACCEPTED '+str(p),flush=True)
    except BaseException as e:
        save(p/'failure.json',dict(error=repr(e),at=stamp(),partial_events_preserved=True))
        log(p,'失败已保存：'+repr(e));raise
    finally:
        if session:session.close();phases['peak_sampled_rss_kib']=session.peak
        save(p/'phase-wall-times.json',phases)


if __name__=='__main__':main()
