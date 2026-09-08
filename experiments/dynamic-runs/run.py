#!/usr/bin/env python3
"""Fresh proofs -> independent calibration -> freeze -> unseen evaluation.
Standard library only; no network, model training, commit, or push.
"""
import argparse
import datetime
import hashlib
import json
import os
from pathlib import Path
import platform
import re
import shutil
import statistics
import subprocess
import sys
import time
import uuid

from datasets import generate, SHAPES, THRESHOLDS, TEST_STRATEGIES
from dyn_reference import discover, evaluate, plan, tree_stats
from timer_audit import audit
from report import report

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent.parent
MODULES = [
    'Model.MergeTree', 'Algorithm.RunDiscovery', 'Algorithm.RunMerge',
    'Algorithm.RunLengthPlan', 'Algorithm.RunStrategy',
    'Verification.RunAdaptive.Discovery', 'Verification.RunAdaptive.MergeTree',
    'Verification.RunAdaptive.Correctness', 'Verification.RunAdaptive.Cost',
    'Verification.RunAdaptive.Complexity', 'Verification.RunAdaptive.Structure',
    'Verification.RunAdaptive.Checks', 'Verification.RunAdaptive.Strategy',
]
THEOREMS = [
    'discover_spec', 'discover_cost', 'discover_no_sorting', 'discover_count_le',
    'discover_of_sorted', 'runCount_eq_descents', 'runCount_zero_iff',
    'countPlan_leaves', 'countPlan_depth', 'countPlan_budget', 'lengthPlan_leaves',
    'MergeTree.cost_le_budget', 'MergeTree.budget_le_weight_depth', 'MergeTree.no_checks',
    'count_sort_spec', 'length_sort_spec', 'operational_certificate',
    'cost_decomposition', 'check_cost', 'sorting_cost', 'cost_le_tree_budget',
    'count_cost_le_upper', 'count_cost_le_nlog_envelope', 'empty_case',
    'upper_le_structuralScale', 'count_cost_isBigO_structural', 'count_cost_isBigO_nlog',
    'count_cost_of_sorted', 'sorted_cost_isBigO_linear', 'length_cost_of_sorted',
    'unequal_length_witness', 'Strategy.correct', 'Strategy.cost_bound',
    'Strategy.execution', 'Strategy.phases',
]


def save(path, obj):
    path.write_text(json.dumps(obj, indent=2, sort_keys=True)+'\n')


def output(*args):
    return subprocess.check_output(args, cwd=ROOT, text=True).strip()


def command(args, log, env=None):
    start = time.perf_counter_ns()
    p = subprocess.run(args, cwd=ROOT, env=env, text=True,
                       stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    log.write_text(p.stdout)
    if p.returncode:
        raise RuntimeError(f'failed {args}; {log}\n{p.stdout[-6000:]}')
    return time.perf_counter_ns()-start


def hashes():
    paths = list((ROOT/'LeanSort').rglob('*.lean'))
    for directory in [HERE, HERE.parent/'cost-plans', HERE.parent/'adaptive']:
        paths += [p for p in directory.iterdir() if p.suffix in ('.lean','.py','.md')]
    paths += [ROOT/p for p in ['LeanSort.lean','lean-toolchain','lakefile.toml','lake-manifest.json']]
    return {str(p.relative_to(ROOT)):hashlib.sha256(p.read_bytes()).hexdigest() for p in sorted(set(paths))}


def axioms(log, expected):
    text = log.read_text()
    if re.search(r'\b(sorryAx|native_decide|Lean\.ofReduceBool)\b',text):
        raise RuntimeError('unacceptable certificate axiom')
    found = set()
    groups = re.findall(r'depends on axioms:\s*\[([^]]*)\]',text)
    empty = re.findall(r'does not depend on any axioms',text)
    if len(groups)+len(empty) != expected:
        raise RuntimeError('missing/extra axiom audit entries')
    for group in groups:
        found.update(x.strip() for x in group.split(',') if x.strip())
    if not found <= {'propext','Classical.choice','Quot.sound'}:
        raise RuntimeError(f'unexpected axioms: {found}')
    return sorted(found)


def prepare(directory, phases):
    print('checking Python regressions and Lean builds',flush=True)
    phases['python_checks'] = 0
    for name in ['dynamic-runs','cost-plans','adaptive']:
        phases['python_checks'] += command([sys.executable,'-m','unittest','discover','-s',
            str(HERE.parent/name),'-p','test_*.py'],directory/f'python-{name}.log')
    phases['lake_build'] = command(['lake','build'],directory/'lake-build.log')
    phases['related_build'] = command(['lake','build','LeanSort.Verification.RunAdaptive.Strategy',
        'LeanSort.Verification.CostedPlan.Examples','LeanSort.Verification.Adaptive.Checks',
        'LeanSort.Verification.HybridMerge.Checks'],directory/'related-build.log')
    lean = output('lake','env','which','lean')
    env = dict(os.environ)
    env['LEAN_PATH'] = str(directory/'Replay')+os.pathsep+output('lake','env','printenv','LEAN_PATH')
    # Lean resolves a package root as a whole, not per-module fallthrough.
    # Copy just the existing dependencies into the isolated package root;
    # omit EVERY artifact of the new modules so they must be rebuilt here.
    library = ROOT/'.lake/build/lib/lean/LeanSort'
    new_paths = {str(Path(*m.split('.'))) for m in MODULES}
    for artifact in library.rglob('*'):
        if not artifact.is_file():
            continue
        relative = artifact.relative_to(library)
        module_path = str(relative.parent/relative.name.split('.')[0])
        if module_path in new_paths:
            continue
        target = directory/'Replay/LeanSort'/relative
        target.parent.mkdir(parents=True,exist_ok=True)
        shutil.copyfile(artifact,target)
    phases['fresh_module_proof_checks'] = 0
    for module in MODULES:
        relative = Path('LeanSort',*module.split('.')).with_suffix('.lean')
        dest = (directory/'Replay'/relative).with_suffix('.olean')
        dest.parent.mkdir(parents=True,exist_ok=True)
        print('fresh proof: '+module,flush=True)
        phases['fresh_module_proof_checks'] += command([lean,'-R',str(ROOT),'-o',str(dest),str(ROOT/relative)],
            directory/f'fresh-proof-{module}.log',env)
    start = time.perf_counter_ns()
    acceptance = 'import LeanSort.Verification.RunAdaptive.Strategy\n\n'
    acceptance += '\n'.join('#print axioms LeanSort.RunAdaptive.'+t for t in THEOREMS)+'\n'
    (directory/'Acceptance.lean').write_text(acceptance)
    phases['certificate_source_generation'] = time.perf_counter_ns()-start
    phases['certificate_axiom_check'] = command([lean,str(directory/'Acceptance.lean')],directory/'axioms.log',env)
    allowed = axioms(directory/'axioms.log',len(THEOREMS))
    save(directory/'axiom-audit.json',dict(theorems=THEOREMS,axioms=allowed,all_checked=True))
    phases['worker_check_and_codegen'] = command([lean,'-c',str(directory/'Worker.audit.c'),str(HERE/'Worker.lean')],
        directory/'worker-check.log',env)
    save(directory/'timer-audit.json',audit((directory/'Worker.audit.c').read_text()))
    return lean, env, allowed


def validate(case, response, selected, rounds):
    xs = case['input']
    rs, scan = discover(xs)
    assert response.get('all_outputs_correct'), response
    assert response['run_lengths'] == list(map(len,rs))
    assert response['run_count'] == len(rs)
    assert response['scan_comparisons'] == scan == max(0,len(xs)-1)
    assert len(rs) <= len(xs) and ((len(rs)==0)==(xs==[]))
    assert len(rs) == (1+sum(a>b for a,b in zip(xs,xs[1:])) if xs else 0)
    assert [v['strategy'] for v in response['measurements']] == list(selected)
    rows = []
    for measured in response['measurements']:
        name, record = measured['strategy'], measured['profile']
        ref = evaluate(name,xs)
        assert ref.pop('output') == case['expected'] == sorted(xs)
        for key,value in ref.items():
            assert record[key] == value, (case['id'],name,key,record[key],value)
        assert record['comparisons'] <= record['bound']
        assert record['comparisons'] == record['check_comparisons']+record['merge_or_sort_comparisons']
        if record['conditional_applicable']:
            assert record['comparisons'] <= record['conditional_bound']
        if name.startswith('runs_'):
            weight,budget,depth = tree_stats(plan(rs,name=='runs_length'))
            assert weight == len(xs) and budget == record['tree_budget']
            assert record['comparisons'] <= scan+budget <= scan+weight*depth
            if name=='runs_count':
                assert depth <= max(0,len(rs)-1).bit_length()
            if xs == sorted(xs):
                assert record['comparisons'] == scan
        samples = measured['samples_ns']
        assert len(samples)==rounds and all(type(x) is int and x>=0 for x in samples)
        diag = measured['diagnostics']
        if name.startswith('runs_'):
            assert set(diag)=={'scan_ns','plan_with_consumption_ns','merge_only_ns'}
            assert all(len(a)==rounds and all(type(x) is int and x>=0 for x in a) for a in diag.values())
        else:
            assert diag is None
        rows.append(dict(stage=case['stage'],case_id=case['id'],shape=case['shape'],
            seed=case['seed'],input_sha256=case['input_sha256'],strategy=name,n=len(xs),
            run_count=len(rs),run_lengths=json.dumps(list(map(len,rs))),
            **{k:v for k,v in record.items() if k!='plan'},plan=json.dumps(record['plan']),
            median_ns=statistics.median(samples),min_ns=min(samples),max_ns=max(samples),
            median_scan_ns=statistics.median(diag['scan_ns']) if diag else None,
            median_plan_with_consumption_ns=statistics.median(diag['plan_with_consumption_ns']) if diag else None,
            median_merge_only_ns=statistics.median(diag['merge_only_ns']) if diag else None))
    return rows


def measure(directory,stage,lean,env,cases,selected,rounds,phases):
    start = time.perf_counter_ns()
    rows = []
    with (directory/f'dataset-{stage}.jsonl').open('w') as f:
        for case in cases:
            f.write(json.dumps(case)+'\n')
    stderr = (directory/f'worker-{stage}.stderr.log').open('w')
    worker = subprocess.Popen([lean,'--run',str(HERE/'Worker.lean')],cwd=ROOT,env=env,text=True,
        bufsize=1,stdin=subprocess.PIPE,stdout=subprocess.PIPE,stderr=stderr)
    try:
        line = worker.stdout.readline()
        greeting = json.loads(line)
        if not greeting.get('ready'):
            raise RuntimeError(f'bad worker greeting: {line}')
        phases[stage+'_worker_startup'] = time.perf_counter_ns()-start
        with (directory/f'observations-{stage}.jsonl').open('w') as f:
            for index,case in enumerate(cases):
                request = dict(input=case['input'],expected=case['expected'],strategies=list(selected),
                    rounds=rounds,order_seed=index)
                worker.stdin.write(json.dumps(request)+'\n'); worker.stdin.flush()
                response = json.loads(worker.stdout.readline())
                # Keep even a failing response for diagnosis; never silently drop a case.
                f.write(json.dumps(dict(case_id=case['id'],response=response))+'\n'); f.flush()
                if 'error' in response:
                    raise RuntimeError(f"worker rejected {case['id']}: {response}")
                rows.extend(validate(case,response,selected,rounds))
                print(f"{stage} {index+1}/{len(cases)}: {case['id']}",flush=True)
        worker.stdin.close()
        if worker.wait(timeout=30):
            raise RuntimeError('worker failed on shutdown')
    finally:
        if worker.poll() is None:
            worker.terminate(); worker.wait(timeout=30)
        stderr.close()
    phases[stage+'_wall_including_startup_diagnostics_and_validation'] = time.perf_counter_ns()-start
    return rows


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--smoke',action='store_true')
    parser.add_argument('--rounds',type=int,default=5)
    args = parser.parse_args()
    if not 1<=args.rounds<=21:
        parser.error('rounds must be in [1,21]')
    stamp = datetime.datetime.now(datetime.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    directory = HERE/'results'/(stamp+('-smoke-' if args.smoke else '-full-')+uuid.uuid4().hex[:6])
    directory.mkdir(parents=True)
    print('results='+str(directory.relative_to(ROOT)),flush=True)
    phases, sources = {}, hashes()
    refs = {name:output('git','rev-parse',name) for name in ['HEAD','main','refs/stash']}
    save(directory/'source-hashes.json',sources)
    save(directory/'environment.json',dict(branch=output('git','branch','--show-current'),refs=refs,
        platform=platform.platform(),machine=platform.machine(),processor=platform.processor(),
        logical_cpus=os.cpu_count(),python=sys.version,lean=output('lake','env','lean','--version'),
        git_status=output('git','status','--short'),backend='lean --run; Comparison.Program interpreter',
        initial_work_preserved=True))
    save(directory/'protocol.json',dict(smoke=args.smoke,rounds=args.rounds,shapes=SHAPES,
        thresholds=THRESHOLDS,test_strategies=TEST_STRATEGIES,
        calibration_sizes=[11,25] if args.smoke else [24,80,192],
        calibration_seeds=[101] if args.smoke else [9011,9029],
        test_sizes=[23,47] if args.smoke else [33,97,257],
        test_seeds=[501] if args.smoke else [100003,200003,300007],
        selection='minimize sum of per-input median end-to-end ns on calibration; numeric threshold tie break',
        metrics=['key comparisons (including scan/checks)','per-input median full deployment ns',
                 'paired wins/losses','by-shape totals','non-additive diagnostic replays'],
        timing='clock, IO input read, scan/build/execute, full output checksum/sink, clock',
        excluded='generation, JSON, correctness replays, offline proofs, calibration selection, diagnostics',
        no_test_tuning=True,comparison_scope='key <= only; metadata arithmetic/traversal/allocation unmodeled',
        control='Peeksort Algorithm 1 eager ascending-run split-policy port; not original optimized implementation',
        reference='https://www.wild-inter.net/publications/munro-wild-2018.pdf'))
    try:
        lean,env,allowed = prepare(directory,phases)
        calibration = generate('calibration',args.smoke)
        candidates = ['hybrid_'+str(t) for t in THRESHOLDS]
        rows = measure(directory,'calibration',lean,env,calibration,candidates,args.rounds,phases)
        start = time.perf_counter_ns()
        scores = {t:sum(r['median_ns'] for r in rows if r['strategy']=='hybrid_'+str(t)) for t in THRESHOLDS}
        threshold = min(THRESHOLDS,key=lambda t:(scores[t],t))
        selected = [s if s!='frozen_hybrid' else 'hybrid_'+str(threshold) for s in TEST_STRATEGIES]
        phases['offline_threshold_selection'] = time.perf_counter_ns()-start
        assert hashes()==sources, 'sources changed before freeze'
        save(directory/'frozen.json',dict(threshold=threshold,scores_ns=scores,selected=selected,
            frozen_at=datetime.datetime.now(datetime.timezone.utc).isoformat(),
            source_hashes_sha256=hashlib.sha256((directory/'source-hashes.json').read_bytes()).hexdigest(),
            calibration_hashes=[c['input_sha256'] for c in calibration],test_generated_after_freeze=True))
        start = time.perf_counter_ns()
        frozen = f'''import LeanSort.Verification.RunAdaptive.Strategy
open LeanSort LeanSort.RunAdaptive
def frozenHybrid : Strategy := .fixed (.leaf (.hybrid {threshold}))
theorem frozen_correct (xs : List Nat) : IsSortingResult (· ≤ ·) xs (frozenHybrid.run xs) :=
  frozenHybrid.correct xs
theorem frozen_cost (xs : List Nat) : (frozenHybrid.program xs).eval.time ≤ frozenHybrid.bound xs :=
  frozenHybrid.cost_bound xs
#print axioms frozen_correct
#print axioms frozen_cost
'''
        (directory/'Frozen.lean').write_text(frozen)
        phases['frozen_certificate_generation'] = time.perf_counter_ns()-start
        phases['frozen_certificate_check'] = command([lean,str(directory/'Frozen.lean')],directory/'frozen-axioms.log',env)
        axioms(directory/'frozen-axioms.log',2)
        # Final inputs are generated only now. Unit tests examined deterministic generators,
        # never benchmarked or tuned candidate performance on these final inputs.
        test = generate('test',args.smoke)
        assert not ({c['input_sha256'] for c in calibration}&{c['input_sha256'] for c in test})
        assert not ({c['id'] for c in calibration}&{c['id'] for c in test})
        rows += measure(directory,'test',lean,env,test,selected,args.rounds,phases)
        assert len(rows)==len(calibration)*len(candidates)+len(test)*len(selected)
        assert len({(r['case_id'],r['strategy']) for r in rows})==len(rows)
        assert hashes()==sources, 'source mutation during experiment'
        assert {name:output('git','rev-parse',name) for name in refs}==refs, 'git refs changed'
        summary = report(directory,rows,selected,threshold,phases)
        save(directory/'artifact-hashes.json',{str(p.relative_to(directory)):hashlib.sha256(p.read_bytes()).hexdigest()
            for p in sorted(directory.rglob('*')) if p.is_file()})
        save(directory/'acceptance.json',dict(complete=True,fresh_modules=len(MODULES),
            audited_theorems=len(THEOREMS)+2,axioms=allowed,sources_unchanged=True,git_refs_unchanged=True,
            all_outputs_checked=True,all_count_references_matched=True,all_applicable_bounds_checked=True,
            timer_audit_passed=True,calibration_inputs=len(calibration),test_inputs=len(test),
            input_strategy_pairs=len(rows),deployment_repetitions=len(rows)*args.rounds,
            test_parameters_frozen=True,comparison_model_not_machine_time=True))
        print(json.dumps(summary,indent=2),flush=True)
        print('ACCEPTED: '+str(directory.relative_to(ROOT)),flush=True)
    except BaseException as e:
        save(directory/'failure.json',dict(error=repr(e),phases_ns=phases))
        raise


if __name__=='__main__':
    main()

