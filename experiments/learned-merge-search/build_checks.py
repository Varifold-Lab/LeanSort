"""Fresh compiler replay, no dependency install or historic source mutation."""
import hashlib
import importlib.util
import os
from pathlib import Path
import re
import shutil
import subprocess
import sys
import time

HERE=Path(__file__).resolve().parent;ROOT=HERE.parent.parent
MODULES=['Model.MergeSearch','Algorithm.MergeSearch.Certificate','Verification.MergeSearch.Certificate','Verification.MergeSearch.Checks']
THEOREMS=['Fits.indices','checkFits_sound','lower_sound','checkLower_sound','checkOptimal_sound','zero_lower',
 'realize_budget','realize_leaves','safePlan_leaves','safe_correct','safe_cost','discovered_correct','discovered_cost',
 'realize_budget_lengths','certified_budget_minimum']

def command(args,path,env=None,timeout=180):
    a=time.perf_counter_ns()
    with path.open('w') as f:p=subprocess.run(args,cwd=ROOT,env=env,stdout=f,stderr=subprocess.STDOUT,timeout=timeout)
    if p.returncode:raise RuntimeError(f'{args}: {path}\n{path.read_text()[-3000:]}')
    return time.perf_counter_ns()-a

def prepare(out):
    phases={}
    for name in ['adaptive','cost-plans','dynamic-runs','direct-executor','direct-cost-learning','selection-break-even','learned-merge-search']:
        phases['tests_'+name]=command([sys.executable,'-m','unittest','discover','-s',str(HERE.parent/name),'-p','test_*.py'],out/f'tests-{name}.log')
    phases['build']=command(['lake','build'],out/'lake-build.log')
    phases['related']=command(['lake','build','LeanSort.Verification.MergeSearch.Checks',
        'LeanSort.Verification.BudgetSelection.Checks','LeanSort.Verification.Direct.Phases'],out/'related-build.log')
    lean=subprocess.check_output(['lake','env','which','lean'],cwd=ROOT,text=True).strip()
    lp=subprocess.check_output(['lake','env','printenv','LEAN_PATH'],cwd=ROOT,text=True).strip()
    env=dict(os.environ,LEAN_PATH=str(out/'Replay')+os.pathsep+lp)
    # Recompile the direct semantic chain and all new certificate modules.
    mods=['Algorithm.Direct.Engine','Algorithm.Direct.Executor','Algorithm.Direct.Ablation','Algorithm.Direct.Phases',
       'Algorithm.Direct.Profile','Semantics.Direct','Verification.Direct.Morphism','Verification.Direct.Symbolic',
       'Verification.Direct.Refinement','Verification.Direct.Checks','Verification.Direct.Phases']+MODULES
    library=ROOT/'.lake/build/lib/lean/LeanSort'
    omitted={str(Path(*m.split('.'))) for m in mods}
    for artifact in library.rglob('*'):
        if not artifact.is_file():continue
        relative=artifact.relative_to(library)
        if str(relative.parent/relative.name.split('.')[0]) in omitted:continue
        dest=out/'Replay/LeanSort'/relative
        dest.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(artifact,dest)
    for m in mods:
        rel=Path('LeanSort',*m.split('.')).with_suffix('.lean');dest=(out/'Replay'/rel).with_suffix('.olean')
        dest.parent.mkdir(parents=True,exist_ok=True)
        phases[m]=command([lean,'-R',str(ROOT),'-o',str(dest),str(ROOT/rel)],out/f'fresh-{m}.log',env)
    audit='import LeanSort.Verification.MergeSearch.Checks\n'
    audit+=''.join('#print axioms LeanSort.MergeSearch.'+t+'\n' for t in THEOREMS)
    audit+='#print axioms LeanSort.Direct.tree_counted_eq\n#print axioms LeanSort.Direct.tree_execution\n'
    (out/'Axioms.lean').write_text(audit)
    phases['axioms']=command([lean,str(out/'Axioms.lean')],out/'axioms.log',env)
    log=(out/'axioms.log').read_text();groups=re.findall(r'depends on axioms:\s*\[([^]]*)\]',log)
    assert len(groups)+log.count('does not depend on any axioms')==len(THEOREMS)+2
    found={a.strip() for g in groups for a in g.split(',') if a.strip()}
    assert found<={'propext','Quot.sound','Classical.choice'}
    sources='\n'.join((ROOT/Path('LeanSort',*m.split('.')).with_suffix('.lean')).read_text() for m in MODULES)
    assert not re.search(r'\b(sorry|admit|axiom|native_decide)\b',sources)
    phases['worker']=command([lean,'-c',str(out/'Worker.audit.c'),str(HERE/'Worker.lean')],out/'worker-build.log',env)
    c=(out/'Worker.audit.c').read_text()
    # Use the old proven timing-source parser; generated code is only an audit.
    spec=importlib.util.spec_from_file_location('prior_compiler',HERE.parent/'direct-cost-learning/compiler_audit.py')
    mod=importlib.util.module_from_spec(spec);spec.loader.exec_module(mod)
    body=mod.body(c,'MergeSearchWorker_timedTree')
    clocks=[m.start() for m in re.finditer(r'lean_io_mono_nanos_now\(',body)]
    pos=[body.index(x) for x in ['lean_st_ref_get(','Direct_tree','MergeSearchWorker_checksum','lean_st_ref_set(']]
    assert len(clocks)==2 and clocks[0]<min(pos) and max(pos)<clocks[1] and pos==sorted(pos)
    return lean,env,dict(passed=True,phases_ns=phases,axioms=sorted(found),theorems=len(THEOREMS)+2,
        fresh_modules=mods,compiler_timer_body=body,compiler_claim='structural check, not compiler correctness')

def preserved():
    count=0
    for line in (HERE/'original-files.sha256').read_text().splitlines():
        expected,path=line.split('  ',1)
        assert hashlib.sha256((ROOT/path).read_bytes()).hexdigest()==expected,path
        count+=1
    return count

def sources():
    paths=[ROOT/Path('LeanSort',*m.split('.')).with_suffix('.lean') for m in MODULES]
    paths+=[p for p in HERE.iterdir() if p.suffix in ['.py','.lean','.json','.md']]
    return {str(p.relative_to(ROOT)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths}
