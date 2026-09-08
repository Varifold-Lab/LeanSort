"""Build, fresh theorem replay and code-generation audit; preserves old sources."""
import os
from pathlib import Path
import re
import sys
from common import *
import build_checks as old_build
import compiler_audit as old_audit

MODULES=['Algorithm.BudgetSelection.Features','Verification.BudgetSelection.Features','Verification.BudgetSelection.Checks']
THEOREMS=['counted_refines','plain_refines','features_agree','fold_cost','extract_cost','extract_bound','feature_bound','length_cost','legacy_eq','selection_eval','selection_execution','selection_bound','run_correct']

def audit_b(source):
    output={}
    for name,ops in [('timedKernel',['lean_st_ref_get(','LearnedSelection_dispatch','BudgetWorker_checksum(','lean_st_ref_set(']),
        ('timedPolicy',['lean_st_ref_get(','BudgetSelection_select','LearnedSelection_dispatch','BudgetWorker_checksum(','lean_st_ref_set(']),
        ('timedFeatures',['lean_st_ref_get(','BudgetSelection_features','BudgetWorker_checksum(','lean_st_ref_set(']),
        ('timedDecision',['lean_st_ref_get(','BudgetWorker_featureSelect','lean_st_ref_set('])]:
        b=old_audit.body(source,'BudgetWorker_'+name)
        clocks=[m.start() for m in re.finditer(r'lean_io_mono_nanos_now\(',b)]
        positions=[b.index(x) for x in ops]
        assert len(clocks)==2 and positions==sorted(positions)
        sinks=[m.start() for m in re.finditer(r'lean_st_ref_set\(',b)]
        assert clocks[0]<min(positions) and max(positions+sinks)<clocks[1]
        assert not any(x in b for x in ['countedFeatures','runCounted','Program_eval'])
        output[name]=b
    return dict(passed=True,bodies=output,scope='syntactic generated-C timing/consumption audit, not compiler correctness')

def prepare(directory,phases):
    phases['new_build']=old_build.command(['lake','build','LeanSort.Verification.BudgetSelection.Checks'],directory/'new-build.log')
    lean,env=old_build.prepare(directory,phases)
    for module in MODULES:
        rel=Path('LeanSort',*module.split('.')).with_suffix('.lean')
        dest=(directory/'Replay'/rel).with_suffix('.olean');dest.parent.mkdir(parents=True,exist_ok=True)
        phases['fresh_'+module]=old_build.command([lean,'-R',str(ROOT),'-o',str(dest),str(ROOT/rel)],directory/f'fresh-{module}.log',env)
    text='import LeanSort.Verification.BudgetSelection.Checks\n'+''.join('#print axioms LeanSort.BudgetSelection.'+t+'\n' for t in THEOREMS)
    (directory/'BudgetAcceptance.lean').write_text(text)
    old_build.command([lean,str(directory/'BudgetAcceptance.lean')],directory/'budget-axioms.log',env)
    log=(directory/'budget-axioms.log').read_text();groups=re.findall(r'depends on axioms:\s*\[([^]]*)\]',log)
    assert len(groups)+log.count('does not depend on any axioms')==len(THEOREMS)
    found={x.strip() for g in groups for x in g.split(',') if x.strip()}
    assert found<={'propext','Classical.choice','Quot.sound'}
    assert not re.search(r'\b(sorryAx|native_decide|Lean\.ofReduceBool)\b',log)
    save(directory/'budget-axiom-audit.json',dict(passed=True,theorems=THEOREMS,axioms=sorted(found)))
    old_build.command([lean,'-c',str(directory/'BudgetWorker.audit.c'),str(HERE/'Worker.lean')],directory/'budget-worker-check.log',env)
    save(directory/'budget-compiler-audit.json',audit_b((directory/'BudgetWorker.audit.c').read_text()))
    new='\n'.join((ROOT/Path('LeanSort',*m.split('.')).with_suffix('.lean')).read_text() for m in MODULES)
    assert not re.search(r'\b(sorry|admit|axiom)\b',new)
    phases['new_python_tests']=old_build.command([sys.executable,'-m','unittest','discover','-s',str(HERE),'-p','test_*.py'],directory/'new-tests.log')
    return lean,env
