"""Fresh proof replay and source versions. Does not modify previous experiments."""
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import sys
import time

from data_protocol import ROOT,HERE
from compiler_audit import audit

OLD=['Algorithm.Direct.Engine','Algorithm.Direct.Executor','Algorithm.Direct.Ablation',
    'Algorithm.Direct.Phases','Algorithm.Direct.Profile','Semantics.Direct','Verification.Direct.Morphism',
    'Verification.Direct.Symbolic','Verification.Direct.Refinement','Verification.Direct.Checks','Verification.Direct.Phases']
NEW=['Algorithm.LearnedSelection.Candidates','Algorithm.LearnedSelection.Features','Algorithm.LearnedSelection.Model',
    'Verification.LearnedSelection.Correctness','Verification.LearnedSelection.Features','Verification.LearnedSelection.Checks']
THEOREMS=['dispatch_correct','arbitrary_selector_correct','run_correct','fallback_correct','invalid_fallback',
    'kernel_bound','kernel_execution','certificate','feature_counted_refines','feature_plain_refines','features_agree',
    'selection_eval','selection_execution','selection_bound','feature_step_cost','feature_fold_cost','feature_cost',
    'probePairs_length_le','feature_cost_le','selection_bound_80']


def save(path,obj): path.write_text(json.dumps(obj,indent=2,sort_keys=True)+'\n')
def output(*args): return subprocess.check_output(args,cwd=ROOT,text=True).strip()


def command(args,log,env=None):
    start=time.perf_counter_ns()
    with log.open('w') as f:p=subprocess.run(args,cwd=ROOT,env=env,stdout=f,stderr=subprocess.STDOUT)
    if p.returncode:raise RuntimeError(f'{args} failed: {log}\n{log.read_text()[-5000:]}')
    return time.perf_counter_ns()-start


def hashes():
    paths=list((ROOT/'LeanSort').rglob('*.lean'))
    for dirname in ['direct-cost-learning','direct-executor','dynamic-runs','cost-plans','adaptive','hybrid-threshold']:
        paths += [p for p in (ROOT/'experiments'/dirname).iterdir() if p.is_file() and p.suffix in ['.py','.lean','.md','.json']]
    paths += [ROOT/p for p in ['LeanSort.lean','lean-toolchain','lakefile.toml','lake-manifest.json']]
    return {str(p.relative_to(ROOT)):hashlib.sha256(p.read_bytes()).hexdigest() for p in sorted(set(paths))}


def prepare(directory,phases):
    for name in ['direct-cost-learning','direct-executor','dynamic-runs','cost-plans','adaptive']:
        phases['tests_'+name]=command([sys.executable,'-m','unittest','discover','-s',str(HERE.parent/name),'-p','test_*.py'],directory/f'tests-{name}.log')
    phases['lake_build']=command(['lake','build'],directory/'lake-build.log')
    phases['related_build']=command(['lake','build','LeanSort.Verification.LearnedSelection.Checks',
        'LeanSort.Verification.Direct.Phases','LeanSort.Verification.CostedPlan.Examples',
        'LeanSort.Verification.Adaptive.Checks','LeanSort.Verification.HybridMerge.Checks'],directory/'related-build.log')
    lean=output('lake','env','which','lean')
    env=dict(os.environ,LEAN_PATH=str(directory/'Replay')+os.pathsep+output('lake','env','printenv','LEAN_PATH'))
    library=ROOT/'.lake/build/lib/lean/LeanSort'
    omitted={str(Path(*m.split('.'))) for m in OLD+NEW}
    for artifact in library.rglob('*'):
        if not artifact.is_file():continue
        relative=artifact.relative_to(library)
        if str(relative.parent/relative.name.split('.')[0]) in omitted:continue
        target=directory/'Replay/LeanSort'/relative
        target.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(artifact,target)
    for module in OLD+NEW:
        relative=Path('LeanSort',*module.split('.')).with_suffix('.lean')
        dest=(directory/'Replay'/relative).with_suffix('.olean');dest.parent.mkdir(parents=True,exist_ok=True)
        print('fresh proof '+module,flush=True)
        phases['fresh_'+module]=command([lean,'-R',str(ROOT),'-o',str(dest),str(ROOT/relative)],directory/f'fresh-{module}.log',env)
    text='import LeanSort.Verification.LearnedSelection.Checks\n'+''.join('#print axioms LeanSort.LearnedSelection.'+t+'\n' for t in THEOREMS)
    text+='#print axioms LeanSort.Direct.run_counted_eq\n#print axioms LeanSort.Direct.correct\n#print axioms LeanSort.Direct.cost_bound\n'
    (directory/'Acceptance.lean').write_text(text)
    phases['axiom_check']=command([lean,str(directory/'Acceptance.lean')],directory/'axioms.log',env)
    log=(directory/'axioms.log').read_text()
    groups=re.findall(r'depends on axioms:\s*\[([^]]*)\]',log)
    assert len(groups)+log.count('does not depend on any axioms')==len(THEOREMS)+3
    found={x.strip() for g in groups for x in g.split(',') if x.strip()}
    assert found<={'propext','Classical.choice','Quot.sound'}
    assert not re.search(r'\b(sorryAx|native_decide|Lean\.ofReduceBool)\b',log)
    save(directory/'axiom-audit.json',dict(theorems=THEOREMS,old_theorems=['Direct.run_counted_eq','Direct.correct','Direct.cost_bound'],axioms=sorted(found),passed=True))
    phases['worker_compile_audit']=command([lean,'-c',str(directory/'Worker.audit.c'),str(HERE/'Worker.lean')],directory/'worker-check.log',env)
    save(directory/'compiler-audit.json',audit((directory/'Worker.audit.c').read_text()))
    new_source='\n'.join((ROOT/Path('LeanSort',*m.split('.')).with_suffix('.lean')).read_text() for m in NEW)
    assert not re.search(r'\b(sorry|admit|axiom)\b',new_source)
    return lean,env
