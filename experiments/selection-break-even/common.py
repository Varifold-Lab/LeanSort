"""Shared protocol and independent data/features. Existing modules are read-only."""
import hashlib
import json
from pathlib import Path
import random
import sys

HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[1]
OLD=HERE.parent/'direct-cost-learning'
sys.path.insert(0,str(OLD))
import data_protocol as prior_data
import learning as prior_learning
import measurement as prior_measurement
from dyn_reference import discover,evaluate

BUDGETS=['length','eight','sixteen','legacy']
LIMITS=dict(length=0,eight=8,sixteen=16,legacy=80)
FAMILIES=['random','sorted','reverse','duplicates','perturbed','fixed_r4','fixed_r16','avg_run8','avg_run32']

def config():return json.loads((HERE/'config.json').read_text())
def save(path,x):path.write_text(json.dumps(x,indent=2,sort_keys=True)+'\n')
def digest(x):return hashlib.sha256(repr(x).encode()).hexdigest()
def filehash(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def jsonhash(x):return hashlib.sha256(json.dumps(x,sort_keys=True).encode()).hexdigest()
def load_rows(p):return [json.loads(x) for x in p.read_text().splitlines()]
def save_rows(p,rows):
    with p.open('w') as f:
        for row in rows:f.write(json.dumps(row)+'\n')

def feature(kind,xs):
    if kind=='legacy':return prior_data.features(xs)
    n=len(xs);k=min(LIMITS[kind],max(0,n-1));desc=0
    for i in range(k):
        pos=i*max(0,n-2)//max(1,k-1)
        desc+=not xs[pos]<=xs[pos+1]
    return [n,k,1000*desc//max(1,k),0,0,0],k

def controlled(base,r,unequal=False):
    n=len(base);r=min(max(1,r),n)
    if unequal:sizes=[1]*(r-1)+[n-r+1]
    else:sizes=[n//r+(i<n%r) for i in range(r)]
    # Assign successive ascending key ranges to runs, then reverse run order.
    # Strict inter-run descents guarantee r; no boundary is passed to a selector.
    ordered=sorted(base);groups=[];at=0
    for size in sizes:groups.append(ordered[at:at+size]);at+=size
    return [x for run in reversed(groups) for x in run]

def generate(split,lengths,seeds,structure=False,families=None):
    out=[]
    for seed in seeds:
        for n in lengths:
            rng=random.Random(seed*1000033+n*101)
            base=[seed*100000+x for x in rng.sample(range(16*n),n)]
            variations=[]
            for family in families or FAMILIES:
                if family=='random':xs=base[:]
                elif family=='sorted':xs=sorted(base)
                elif family=='reverse':xs=sorted(base,reverse=True)
                elif family=='duplicates':xs=[seed*100000+x%5 for x in base]
                elif family=='perturbed':
                    xs=sorted(base)
                    for _ in range(max(1,n//25)):
                        a,b=rng.sample(range(n),2);xs[a],xs[b]=xs[b],xs[a]
                elif family.startswith('fixed_r'):xs=controlled(base,int(family[7:]))
                else:xs=controlled(base,max(1,n//int(family[7:])))
                variations.append((family,xs,{}))
            if structure and n==config()['structure_n']:
                for r in config()['structure_run_counts']:
                    for uneven in [False,True]:
                        variations.append((f'structure_r{r}_'+('skewed' if uneven else 'equal'),controlled(base,r,uneven),dict(requested_runs=r,skewed=uneven)))
            seen={}
            for family,xs,design in variations:
                h=digest(xs)
                if h in seen:
                    seen[h]['family_aliases'].append(family)
                    seen[h]['designs'].append(dict(family=family,**design));continue
                rs,_=discover(xs)
                row=dict(input_id=f'{split}-{seed}-{n}-{family}',input=xs,expected=sorted(xs),input_sha256=h,
                    base_input=base,base_sha256=digest(base),group_id=f'base-{seed}-{n}',split=split,seed=seed,n=n,
                    family=family,family_aliases=[family],designs=[dict(family=family,**design)],
                    observed_run_lengths=list(map(len,rs)),observed_runs=len(rs))
                seen[h]=row;out.append(row)
    return out

def old_policies():
    p=ROOT/config()['previous_result']
    return dict(fixed=dict(kind='fixed',id=5),hybrid=dict(kind='fixed',id=1),
        rule=dict(kind='sample_rule'),classifier=dict(kind='learned',model=json.loads((p/'final-classifier.json').read_text())),
        cost_ranking=dict(kind='learned',model=json.loads((p/'final-cost_ranking.json').read_text())))

def predict(policy,fs):
    if policy['kind']=='fixed':return policy['id']
    if policy['kind']=='rule':return 1 if fs[0]<=policy['length_cut'] else 5 if fs[2]<=policy['descent_cut'] else 1
    model=policy['model'];values=prior_learning.predict_values(model['tree'],fs)
    if values is None:return None
    if model['kind']=='classifier':return values[0] if len(values)==1 else None
    if len(values)==7 and all(v>=0 for v in values):return min(range(7),key=values.__getitem__)
    return None

def source_hashes():
    files=list((ROOT/'LeanSort').rglob('*.lean'))
    for exp in ['selection-break-even','direct-cost-learning','direct-executor','dynamic-runs','cost-plans','adaptive','hybrid-threshold']:
        files += [p for p in (HERE.parent/exp).iterdir() if p.is_file() and p.suffix in ['.lean','.py','.json','.md'] and p.name!='LOG.zh.md']
    files += [ROOT/p for p in ['LeanSort.lean','lean-toolchain','lakefile.toml','lake-manifest.json']]
    return {str(p.relative_to(ROOT)):filehash(p) for p in sorted(set(files))}

def preserved():
    lines=(HERE/'original-files.sha256').read_text().splitlines()
    for line in lines:
        h,name=line.split('  ',1)
        assert filehash(ROOT/name)==h,'original file changed: '+name
    return len(lines)
