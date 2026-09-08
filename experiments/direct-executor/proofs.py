"""Rebuild, isolated proof replay, axiom checks and code-generation inspection."""
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import sys
import time

from audit import audit
from data_protocol import ROOT

HERE=Path(__file__).resolve().parent
MODULES=['Algorithm.Direct.Engine','Algorithm.Direct.Executor','Algorithm.Direct.Ablation',
    'Algorithm.Direct.Phases','Algorithm.Direct.Profile','Semantics.Direct','Verification.Direct.Morphism',
    'Verification.Direct.Symbolic','Verification.Direct.Refinement','Verification.Direct.Checks',
    'Verification.Direct.Phases']
THEOREMS=['symbolic_scanTail','symbolic_discover','symbolic_merge','symbolic_tree','symbolic_strategy',
    'scan_counted_eq','scan_eq','merge_counted_eq','merge_eq','tree_counted_eq','tree_eq',
    'run_counted_eq','run_eq','uncounted_eq_counted','uncounted_execution','execution_iff',
    'scan_execution','merge_execution','tree_execution','correct','cost_bound','execution_bound',
    'count_bound','length_bound','count_sorted_exact','length_sorted_exact',
    'count_isBigO_structural','count_isBigO_nlog','staged_eq','phase_count_eq','phase_partition','diagnostic_bound_eq']


def save(path,obj):
    path.write_text(json.dumps(obj,indent=2,sort_keys=True)+'\n')


def output(*args):
    return subprocess.check_output(args,cwd=ROOT,text=True).strip()


def command(args,log,env=None):
    start=time.perf_counter_ns()
    with log.open('w') as f:
        p=subprocess.run(args,cwd=ROOT,env=env,stdout=f,stderr=subprocess.STDOUT)
    if p.returncode:
        raise RuntimeError(f'{args} failed; {log}\n{log.read_text()[-5000:]}')
    return time.perf_counter_ns()-start


def hashes():
    paths=list((ROOT/'LeanSort').rglob('*.lean'))
    for dirname in ['direct-executor','dynamic-runs','cost-plans','adaptive','hybrid-threshold']:
        paths += [p for p in (ROOT/'experiments'/dirname).iterdir()
                  if p.is_file() and p.suffix in ['.lean','.py','.md','.json']]
    paths += [ROOT/p for p in ['LeanSort.lean','lean-toolchain','lakefile.toml','lake-manifest.json']]
    return {str(p.relative_to(ROOT)):hashlib.sha256(p.read_bytes()).hexdigest() for p in sorted(set(paths))}


def prepare(directory,phases):
    print('builds and regressions',flush=True)
    for name in ['direct-executor','dynamic-runs','cost-plans','adaptive']:
        phases['tests_'+name]=command([sys.executable,'-m','unittest','discover','-s',
            str(HERE.parent/name),'-p','test_*.py'],directory/f'tests-{name}.log')
    phases['lake_build']=command(['lake','build'],directory/'lake-build.log')
    phases['related_build']=command(['lake','build','LeanSort.Verification.Direct.Phases',
        'LeanSort.Verification.CostedPlan.Examples','LeanSort.Verification.Adaptive.Checks',
        'LeanSort.Verification.HybridMerge.Checks'],directory/'related-build.log')
    lean=output('lake','env','which','lean')
    env=dict(os.environ,LEAN_PATH=str(directory/'Replay')+os.pathsep+output('lake','env','printenv','LEAN_PATH'))
    library=ROOT/'.lake/build/lib/lean/LeanSort'
    omitted={str(Path(*m.split('.'))) for m in MODULES}
    for artifact in library.rglob('*'):
        if not artifact.is_file(): continue
        relative=artifact.relative_to(library)
        if str(relative.parent/relative.name.split('.')[0]) in omitted: continue
        target=directory/'Replay/LeanSort'/relative
        target.parent.mkdir(parents=True,exist_ok=True)
        shutil.copyfile(artifact,target)
    for module in MODULES:
        relative=Path('LeanSort',*module.split('.')).with_suffix('.lean')
        dest=(directory/'Replay'/relative).with_suffix('.olean')
        dest.parent.mkdir(parents=True,exist_ok=True)
        print('fresh proof '+module,flush=True)
        args=[lean,'-R',str(ROOT),'-o',str(dest)]
        if module in ['Algorithm.Direct.Engine','Algorithm.Direct.Executor']:
            args+=['-c',str(directory/(module.split('.')[-1]+'.audit.c'))]
        phases['fresh_'+module]=command(args+[str(ROOT/relative)],directory/f'fresh-{module}.log',env)
    acceptance='import LeanSort.Verification.Direct.Phases\n'+''.join(
        '#print axioms LeanSort.Direct.'+t+'\n' for t in THEOREMS)
    (directory/'Acceptance.lean').write_text(acceptance)
    phases['axiom_check']=command([lean,str(directory/'Acceptance.lean')],directory/'axioms.log',env)
    text=(directory/'axioms.log').read_text()
    groups=re.findall(r'depends on axioms:\s*\[([^]]*)\]',text)
    empty=re.findall('does not depend on any axioms',text)
    assert len(groups)+len(empty)==len(THEOREMS)
    found={x.strip() for g in groups for x in g.split(',') if x.strip()}
    assert found<={'propext','Classical.choice','Quot.sound'},found
    assert not re.search(r'\b(sorryAx|native_decide|Lean\.ofReduceBool)\b',text)
    save(directory/'axiom-audit.json',dict(theorems=THEOREMS,axioms=sorted(found),all_checked=True))
    phases['worker_check_codegen']=command([lean,'-c',str(directory/'Worker.audit.c'),str(HERE/'Worker.lean')],
        directory/'worker-check.log',env)
    save(directory/'compiler-audit.json',audit(*[(directory/(n+'.audit.c')).read_text()
        for n in ['Worker','Executor','Engine']]))
    sources='\n'.join((ROOT/Path('LeanSort',*m.split('.')).with_suffix('.lean')).read_text() for m in MODULES)
    assert not re.search(r'\b(sorry|admit|axiom)\b',sources)
    return lean,env
