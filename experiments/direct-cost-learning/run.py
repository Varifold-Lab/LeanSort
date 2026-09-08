#!/usr/bin/env python3
"""Accumulate direct timings -> train snapshots -> validate -> freeze -> unseen deployment."""
import argparse
import datetime
import hashlib
import itertools
import json
import os
import platform
import time
import uuid

from data_protocol import ROOT,HERE,config,protocol,generate,old_hashes,assert_split_integrity,features
from build_checks import prepare,save,output,hashes
from worker_client import Worker
from measurement import measure,policy_prediction
from learning import fit,best_fixed,size,quality,describe,resolve
from report import opportunity,summarize,write_report


def json_digest(value):return hashlib.sha256(json.dumps(value,sort_keys=True).encode()).hexdigest()
def dataset(directory,name,rows):
    with (directory/f'dataset-{name}.jsonl').open('w') as f:
        for r in rows:f.write(json.dumps(r)+'\n')


def model_policy(model):return dict(kind='learned',model=model)


def catalogue(directory,sources,versions):
    names=config()['candidate_ids']
    formulas=['ComparisonBounds.mergeSort n','ComparisonBounds.hybrid 8 n',
        'Direct.fixedTwo.upper n','LearnedSelection.fixedThree.upper n','Direct.fixedFour.upper n',
        'n - 1 + n * Nat.clog 2 (Direct.scan xs).length','n - 1 + (lengthPlan (Direct.scan xs)).budget']
    records=[dict(numeric_id=i,algorithm_id=name,parameters={'threshold':8} if i==1 else {},
        executable=f'LearnedSelection.dispatch (some {i}) xs',
        certificate=f'LeanSort.LearnedSelection.certificate {i}',
        correctness='LeanSort.LearnedSelection.dispatch_correct',cost='LeanSort.LearnedSelection.kernel_bound',
        input_precondition='arbitrary finite List with LinearOrder; experiments and learned features use Nat',
        cost_formula=formulas[i],cost_unit='key <= comparison; traversal/allocation/metadata/time not charged',
        versions=versions) for i,name in enumerate(names)]
    save(directory/'catalogue.json',records)


def integration_checks(worker,directory):
    c=config()
    def model(kind,tree,**kw):return dict(schema_version=1,candidate_version=c['candidate_version'],
        feature_version=c['feature_version'],kind=kind,tree=tree,**kw)
    leaf=lambda value:dict(kind='leaf',values=value)
    cases={
        'invalid_json':dict(kind='learned',model=None),
        'invalid_id':model_policy(model('classifier',leaf([99]))),
        'negative_id':dict(kind='fixed',id=-7),
        'missing_feature':model_policy(model('classifier',dict(kind='branch',feature=99,threshold=1,left=leaf([0]),right=leaf([5])))),
        'negative_cost':model_policy(model('cost_ranking',leaf([3,4,-1,5,6,7,8]))),
        'short_cost':model_policy(model('cost_ranking',leaf([1,2]))),
        'unsupported_version':model_policy(dict(model('classifier',leaf([0])),feature_version='unsupported')),
        'cost_choice':model_policy(model('cost_ranking',leaf([5,4,3,2,1,2,3]))),
        'tree_choice':model_policy(model('classifier',dict(kind='branch',feature=0,threshold=3,left=leaf([1]),right=leaf([5]))))}
    worker.configure(cases)
    checks=[]
    for xs in [[],[7],[2,1],[1,1,3,0,2,2],list(range(25,0,-1))]:
        response,_=worker.request(dict(cmd='infer',input=xs))
        assert response['features']==features(xs)[0]
        for r in response['outputs']:
            assert r['output']==sorted(xs)
            expected=4 if r['name']=='cost_choice' else (1 if len(xs)<=3 else 5) if r['name']=='tree_choice' else 1
            assert r['chosen_id']==expected,(r,expected)
        checks.append(dict(input=xs,response=response))
    save(directory/'fallback-and-export-checks.json',dict(passed=True,checks=checks))


def freeze_models(directory,selected,fixed,versions,sources):
    models={kind:selected[kind]['model'] for kind in ['classifier','cost_ranking']}
    for kind,model in models.items():save(directory/f'final-{kind}.json',model)
    frozen=dict(frozen_at=datetime.datetime.now(datetime.timezone.utc).isoformat(),
        config=config(),versions=versions,sources=sources,best_fixed_id=fixed,
        models=models,model_hashes={k:json_digest(m) for k,m in models.items()},
        final_data_not_yet_generated=True,selection='largest training prefix; hyperparameters minimizing validation E2E only')
    save(directory/'final-frozen.json',frozen)
    return frozen


def main():
    if not __debug__:raise RuntimeError('Acceptance requires Python assertions, not -O')
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--smoke',action='store_true')
    args=parser.parse_args();cfg=config();protocol_cfg=protocol(args.smoke)
    stamp=datetime.datetime.now(datetime.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    directory=HERE/'results'/(stamp+('-smoke-' if args.smoke else '-full-')+uuid.uuid4().hex[:6])
    directory.mkdir(parents=True);print('results='+str(directory.relative_to(ROOT)),flush=True)
    sources=hashes();refs={x:output('git','rev-parse',x) for x in ['HEAD','main','refs/stash']}
    frozen_executor={p:h for p,h in sources.items() if p.startswith('LeanSort/') and 'LearnedSelection/' not in p}
    versions=dict(executor_version=json_digest(frozen_executor),feature_version=cfg['feature_version'],
        feature_source_sha256=sources['LeanSort/Algorithm/LearnedSelection/Features.lean'],
        worker_source_sha256=sources['experiments/direct-cost-learning/Worker.lean'],candidate_version=cfg['candidate_version'])
    save(directory/'source-hashes.json',sources);save(directory/'executor-frozen.json',frozen_executor)
    save(directory/'environment.json',dict(branch=output('git','branch','--show-current'),refs=refs,
        platform=platform.platform(),machine=platform.machine(),logical_cpus=os.cpu_count(),
        physical_memory_bytes=output('sysctl','-n','hw.memsize'),
        lean=output('lake','env','lean','--version'),python=output('python3','--version'),
        status=output('git','status','--short'),backend=cfg['backend'],
        memory_monitor='sample worker RSS every >=0.25s; includes Lean process, not algorithm space complexity'))
    save(directory/'protocol-frozen.json',dict(config=cfg,run_protocol=protocol_cfg,smoke=args.smoke,
        fixed_before_any_training_measurement=True,versions=versions))
    catalogue(directory,sources,versions)
    phases={};worker=None
    try:
        lean,env=prepare(directory,phases)
        assert hashes()==sources
        train_cases=generate('train',protocol_cfg['lengths'],protocol_cfg['train_seeds'])
        validation_cases=generate('validation',protocol_cfg['lengths'],protocol_cfg['validation_seeds'])
        collections=dict(train=train_cases,validation=validation_cases)
        save(directory/'split-audit-development.json',assert_split_integrity(collections))
        dataset(directory,'train',train_cases);dataset(directory,'validation',validation_cases)
        prior=old_hashes();save(directory/'prior-data-exclusion.json',dict(previous_input_hashes=sorted(prior),used_as_training_labels=False))
        start=time.perf_counter_ns();worker=Worker(lean,env,directory/'worker.stderr.log',cfg)
        phases['worker_startup_ns']=time.perf_counter_ns()-start
        integration_checks(worker,directory)
        deadline=time.monotonic()+cfg['total_measurement_budget_seconds']
        train_rows=[];seen=set();snapshots=[];base_validation=None
        for prefix in protocol_cfg['prefixes']:
            seeds=set(protocol_cfg['train_seeds'][:prefix])
            chunk=[c for c in train_cases if c['seed'] in seeds and c['input_id'] not in seen]
            batch=f'train-prefix-{prefix}'
            start=time.perf_counter_ns()
            new=measure(worker,directory,batch,chunk,{},protocol_cfg['rounds'],versions,deadline)
            phases[batch+'_wall_ns']=time.perf_counter_ns()-start
            train_rows+=new;seen.update(c['input_id'] for c in chunk)
            if base_validation is None:
                base_validation=measure(worker,directory,'validation-candidate-only',validation_cases,{},protocol_cfg['rounds'],versions,deadline)
            # Opportunity diagnosis never gates whether training happens.
            fixed=best_fixed(train_rows)
            save(directory/f'opportunity-prefix-{prefix}.json',dict(train=opportunity(train_rows,fixed),validation=opportunity(base_validation,fixed)))
            entries=[]
            for kind,depth,minimum in itertools.product(['classifier','cost_ranking'],cfg['tree_depths'],cfg['tree_min_leaves']):
                model=fit(train_rows,kind,depth,minimum)
                name=f'{kind}-d{depth}-l{minimum}'
                path=directory/'models'/f'prefix-{prefix}'/(name+'.json');path.parent.mkdir(parents=True,exist_ok=True)
                save(path,model);path.with_suffix('.txt').write_text(describe(model)+'\n')
                entries.append(dict(name=name,kind=kind,depth=depth,min_leaf=minimum,model=model,model_size=size(model),
                    model_file=str(path.relative_to(directory))))
                print(f'trained {len(train_rows)} inputs {name}: {size(model)}',flush=True)
            snapshots.append(dict(prefix=prefix,training_inputs=len(train_rows),entries=entries))
            save(directory/f'accumulation-prefix-{prefix}.json',dict(training_inputs=len(train_rows),
                input_ids=[r['input_id'] for r in train_rows],input_hashes=[r['input_sha256'] for r in train_rows],
                model_files=[e['model_file'] for e in entries],label_backend='direct plain only'))
        fixed=best_fixed(train_rows)
        save(directory/'training-summary.json',dict(best_fixed_id=fixed,best_fixed_name=cfg['candidate_ids'][fixed],
            unique_inputs=len(train_rows),direct_records=len(train_rows)*7,opportunity=opportunity(train_rows,fixed)))
        learning_curve=[];chosen_per_prefix=[]
        for snapshot in snapshots:
            policies=dict(best_fixed=dict(kind='fixed',id=fixed),sample_rule=dict(kind='sample_rule'),length_rule=dict(kind='length_rule'))
            policies.update({entry['name']:model_policy(entry['model']) for entry in snapshot['entries']})
            batch='validation-prefix-'+str(snapshot['prefix'])
            rows=measure(worker,directory,batch,validation_cases,policies,protocol_cfg['rounds'],versions,deadline)
            summary=summarize(rows);save(directory/(batch+'-summary.json'),summary)
            selected={}
            for kind in ['classifier','cost_ranking']:
                options=[e for e in snapshot['entries'] if e['kind']==kind]
                best=min(options,key=lambda e:(summary['policies'][e['name']]['e2e_sum_ms'],e['depth'],e['min_leaf']))
                selected[kind]=best
                learning_curve.append(dict(prefix=snapshot['prefix'],training_inputs=snapshot['training_inputs'],kind=kind,
                    name=best['name'],depth=best['depth'],min_leaf=best['min_leaf'],model_file=best['model_file'],
                    validation_ratio=summary['policies'][best['name']]['aggregate_ratio'],
                    validation_e2e_ms=summary['policies'][best['name']]['e2e_sum_ms'],
                    fixed_e2e_ms=summary['policies']['best_fixed']['e2e_sum_ms'],quality=quality(best['model'],rows),
                    all_hyperparameter_results={e['name']:summary['policies'][e['name']] for e in options}))
            chosen_per_prefix.append(selected)
            save(directory/'learning-curve.json',learning_curve)
        selected=chosen_per_prefix[-1]
        assert sources==hashes()
        frozen=freeze_models(directory,selected,fixed,versions,sources)
        print('FINAL MODELS FROZEN; now generating final test inputs',flush=True)
        # No final test or length-generalization sequence exists before this line.
        tests=generate('test',protocol_cfg['lengths'],protocol_cfg['test_seeds'])
        collections['test']=tests
        generalization=[] if args.smoke else generate('generalization',cfg['generalization_lengths'],cfg['generalization_seeds'])
        if generalization:collections['generalization']=generalization
        save(directory/'split-audit-final.json',assert_split_integrity(collections,prior))
        final_policies=dict(best_fixed=dict(kind='fixed',id=fixed),sample_rule=dict(kind='sample_rule'),
            length_rule=dict(kind='length_rule'),classifier=model_policy(frozen['models']['classifier']),
            cost_ranking=model_policy(frozen['models']['cost_ranking']))
        final={}
        for stage,cases in [('test',tests)]+([('generalization',generalization)] if generalization else []):
            dataset(directory,stage,cases)
            final[stage]=measure(worker,directory,stage,cases,final_policies,protocol_cfg['rounds'],versions,deadline)
        assert sources==hashes(),'source changed after freeze'
        assert refs=={x:output('git','rev-parse',x) for x in refs},'git references changed'
        for kind,model in frozen['models'].items():
            assert json_digest(json.loads((directory/f'final-{kind}.json').read_text()))==frozen['model_hashes'][kind]
        model_sizes={kind:size(model) for kind,model in frozen['models'].items()}
        write_report(directory,learning_curve,final,model_sizes)
        save(directory/'validation.json',dict(passed=True,source_hashes_unchanged=True,executor_unchanged=True,
            final_models_unchanged=True,refs_unchanged=True,training_inputs=len(train_rows),
            training_candidate_records=len(train_rows)*7,model_snapshots=sum(len(s['entries']) for s in snapshots),
            validation_inputs=len(validation_cases),test_inputs=len(tests),generalization_inputs=len(generalization),
            all_outputs_features_counts_exports_checked=True,all_recorded_statuses='ok',
            grouping_and_hash_leakage_checks_passed=True,final_generation_after_model_freeze=True))
        print('ACCEPTED '+str(directory.relative_to(ROOT)),flush=True)
    except BaseException as e:
        save(directory/'failure.json',dict(error=str(e),type=type(e).__name__,partial_streams_preserved=True));raise
    finally:
        if worker is not None:
            phases['worker_peak_sampled_rss_kib']=worker.peak_kib;worker.close()
        save(directory/'phase-wall-times.json',phases)


if __name__=='__main__':main()
