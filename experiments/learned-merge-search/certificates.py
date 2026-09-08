"""External data is accepted only by Lean's checked structure/Bellman interface.
Concrete kernel-normalized proofs accompany representative vectors; the full
saved batch is also run through the theorem-backed executable checker.
"""
import json
from pathlib import Path
import select
import subprocess
import time
from core import stats,plan
from reference import execute,scan
from build_checks import ROOT,HERE,command


def shape(t):
    if t is None:return 'Shape.empty'
    if isinstance(t,int):return f'(Shape.leaf {t})'
    return '(Shape.node '+shape(t[0])+' '+shape(t[1])+')'


def array(d):return '#['+','.join('#['+','.join(map(str,row))+']' for row in d)+']'


def kernel_proof(case,ref,trees,path,lean,env,timeout=90):
    ls=case['lengths'];parts=['import LeanSort.Verification.MergeSearch.Checks',
      'open LeanSort.MergeSearch','set_option maxRecDepth 100000','set_option maxHeartbeats 0',
      f'def ls : List Nat := {ls}',f'def tab : Table := {array(ref["table"])}',
      f'def winner : Shape := {shape(ref["tree"])}',
      'theorem optimal : Optimal (weights ls) ls.length winner := checkOptimal_sound (d := tab) (by decide)',
      f'def candidates : List Shape := [{",".join(shape(t) for t in trees)}]',
      'theorem feasible : candidates.all (fun t => checkFits t 0 ls.length) = true := by decide',
      '#print axioms optimal','#print axioms feasible']
    path.write_text('\n'.join(parts)+'\n')
    elapsed=command([lean,str(path)],path.with_suffix('.log'),env,timeout)
    log=path.with_suffix('.log').read_text()
    assert 'sorryAx' not in log and 'Lean.ofReduceBool' not in log
    return dict(path=str(path.relative_to(ROOT)),elapsed_ns=elapsed,status='kernel_checked')


def signature(t,ls):
    if t is None:return None
    if isinstance(t,int):return ls[t]
    return [signature(t[0],ls),signature(t[1],ls)]


class Checker:
    def __init__(self,out,lean,env,timeout):
        self.timeout=timeout;self.out=out
        self.err=(out/'checker.stderr.log').open('w')
        self.proc=subprocess.Popen([lean,'--run',str(HERE/'Worker.lean')],cwd=ROOT,env=env,
            stdin=subprocess.PIPE,stdout=subprocess.PIPE,stderr=self.err,text=True,bufsize=1)
    def request(self,case,ref,trees,do_execute=False,malformed=False):
        ls=case['lengths'];rs=[]
        if do_execute:
            if case.get('source_input') is not None:rs=scan(case['source_input'])
            else:
                # Disjoint descending block ranges: every supplied run is sorted.
                at=sum(ls)
                for n in ls:rs.append(list(range(at-n,at)));at-=n
        req=dict(lengths=ls,table=ref['table'],trees=trees,runs=rs,execute=do_execute)
        with (self.out/'checker-requests.jsonl').open('a') as f:f.write(json.dumps(dict(input_id=case['input_id'],request=req))+'\n')
        start=time.perf_counter_ns();self.proc.stdin.write(json.dumps(req)+'\n');self.proc.stdin.flush()
        if not select.select([self.proc.stdout],[],[],self.timeout)[0]:raise TimeoutError('Lean checker timeout')
        line=self.proc.stdout.readline()
        if not line:raise RuntimeError('Lean checker exited')
        res=json.loads(line);res['request_wall_ns']=time.perf_counter_ns()-start
        with (self.out/'checker-responses.jsonl').open('a') as f:f.write(json.dumps(dict(input_id=case['input_id'],response=res))+'\n')
        if 'error' in res:raise RuntimeError(res['error'])
        assert res['lower_checked'] and res['lower']==ref['budget']
        if not malformed:
            assert all(res['fits'])
            assert res['budgets']==[stats(t,ls)[1] for t in trees]
            assert res['optimal']==[stats(t,ls)[1]==ref['budget'] for t in trees]
        assert res['count_signature']==signature(plan(ls,'count'),ls)
        assert res['length_signature']==signature(plan(ls,'length'),ls)
        if do_execute:
            for t,e in zip(trees,res['executions']):
                out,c=execute(t if not malformed else plan(ls,'count'),rs)
                assert e['output']==sorted(sum(rs,[]))==out
                assert c==e['comparisons']<=e['budget']
                assert e['leaves']==rs
        return res
    def close(self):
        self.proc.stdin.close()
        try:self.proc.wait(timeout=5)
        except subprocess.TimeoutExpired:self.proc.terminate();self.proc.wait()
        self.err.close()
