"""Compiler-output regression only, not a formal machine-time theorem."""
import re
import sys
from pathlib import Path
sys.path.append(str(Path(__file__).resolve().parent.parent / 'cost-plans'))
from audit_codegen import function_body


def audit(source):
    checks,bodies={},{}
    for name,ops in [
        ('timedRun',['lean_st_ref_get(', 'RunAdaptive_Strategy_run', 'RunExperiment_checksum(', 'lean_st_ref_set(']),
        ('timedScan',['lean_st_ref_get(', 'RunAdaptive_discover', 'lean_st_ref_set(']),
        ('timedPlan',['lean_st_ref_get(', 'lean_apply_1(', 'MergeTree_budget', 'lean_st_ref_set(']),
        ('timedMerge',['lean_st_ref_get(', 'MergeTree_program', 'Program_eval', 'RunExperiment_checksum(', 'lean_st_ref_set('])]:
        body=function_body(source,'l_RunExperiment_'+name)
        clocks=[m.start() for m in re.finditer(r'lean_io_mono_nanos_now\(',body)]
        positions=[body.index(op) for op in ops]
        if len(clocks)!=2 or not clocks[0]<min(positions)<=max(positions)<clocks[1] or positions!=sorted(positions):
            raise ValueError('timer placement failed: '+name)
        checks[name]=True
        bodies[name]=body
    return dict(checks=checks,bodies=bodies,scope='syntactic optimizer regression, not verified native execution')
