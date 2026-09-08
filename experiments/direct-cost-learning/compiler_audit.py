"""Compiler-output regression, not a compiler-correctness proof."""
import importlib.util
from pathlib import Path
import re

spec=importlib.util.spec_from_file_location('frozen_direct_audit',Path(__file__).resolve().parent.parent/'direct-executor/audit.py')
old=importlib.util.module_from_spec(spec);spec.loader.exec_module(old)
body=old.body
functions=old.functions


def audit(source):
    bodies={}
    for name,ops in [
        ('timedKernel',['lean_st_ref_get(','LearnedSelection_dispatch','LearningWorker_checksum(','lean_st_ref_set(']),
        ('timedPolicy',['lean_st_ref_get(','LearnedSelection_select','LearnedSelection_dispatch','LearningWorker_checksum(','lean_st_ref_set(']),
        ('timedFeatures',['lean_st_ref_get(','LearnedSelection_features','LearningWorker_checksum(','lean_st_ref_set(']),
        ('timedDecision',['lean_st_ref_get(','LearningWorker_featureSelect','lean_st_ref_set('])]:
        b=body(source,'LearningWorker_'+name)
        clocks=[m.start() for m in re.finditer(r'lean_io_mono_nanos_now\(',b)]
        positions=[b.index(op) for op in ops]
        sinks=[m.start() for m in re.finditer(r'lean_st_ref_set\(',b)]
        assert len(clocks)==2 and positions==sorted(positions)
        assert clocks[0]<min(positions) and max(positions+sinks)<clocks[1]
        assert not any(x in b for x in ['runCounted','countedFeatures','Program_eval'])
        if name in ['timedKernel','timedPolicy']: assert len(sinks)==2
        bodies[name]=b
    return dict(passed=True,bodies=bodies,scope='syntactic timing/consumption check; same lean --run backend, not native C benchmark')
