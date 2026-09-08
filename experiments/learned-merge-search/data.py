"""Grouped length-vector data. Scale/reversal canonical hashes cannot cross splits.
Perturbations are generated only inside the originating group. Equal vectors
are reserved structural diagnostics, not misleading 'unseen' scaled clones.
"""
import hashlib
import json
import math
import random
from functools import reduce
from reference import scan

FAMILIES=['random','giant','geometric','alternating','multipeak','real_runs']

def digest(x):return hashlib.sha256(json.dumps(x,separators=(',',':'),sort_keys=True).encode()).hexdigest()

def canonical(v):
    if not v:return ()
    g=reduce(math.gcd,v);a=tuple(x//g for x in v)
    return min(a,a[::-1])

def base_vector(r,f,rng):
    if f=='random':return [rng.randint(1,100) for _ in range(r)],None
    if f=='giant':
        v=[rng.randint(1,8) for _ in range(r)];v[rng.randrange(r)]=rng.randint(5,30)*r;return v,None
    if f=='geometric':
        ratio=rng.uniform(1.08,1.38);scale=rng.randint(10,30)
        v=[max(1,round(scale*ratio**i)) for i in range(r)]
        if rng.randrange(2):v.reverse()
        return v,None
    if f=='alternating':return [rng.randint(30,100) if i%2 else rng.randint(1,8) for i in range(r)],None
    if f=='multipeak':
        peaks=[rng.randrange(r),rng.randrange(r)];return [rng.randint(1,10)+sum(rng.randint(40,90)//(1+abs(i-p)) for p in peaks) for i in range(r)],None
    if f=='real_runs':
        # Scan a genuine random integer list, stop at a discovered r boundary.
        xs=[];nr=0;last=None
        while True:
            x=rng.randrange(1000)
            new=last is None or x<last
            if new and nr==r:break
            nr+=new;xs.append(x);last=x
        v=[len(run) for run in scan(xs)];assert len(v)==r
        return v,xs
    raise ValueError(f)

def generate(split,seeds,rs,used,perturb=True):
    cases=[]
    for seed in seeds:
        for r in rs:
            for fi,f in enumerate(FAMILIES):
                rng=random.Random(seed*100003+r*1009+fi)
                for attempt in range(1000):
                    v,raw=base_vector(r,f,rng);key=canonical(v)
                    if key not in used:break
                else:raise RuntimeError('unable to generate disjoint vector')
                group=f'{split}-{seed}-{r}-{f}';used[key]=group
                variants=[('base',v,raw)]
                if perturb and f!='real_runs':
                    q=[max(1,x+rng.choice([-1,0,1])*max(1,x//20)) for x in v]
                    if canonical(q) not in used:used[canonical(q)]=group;variants.append(('perturbed',q,None))
                for variant,ls,xs in variants:
                    cases.append(dict(input_id=group+'-'+variant,group=group,split=split,seed=seed,family=f,
                        variant=variant,lengths=ls,r=len(ls),n=sum(ls),input_sha256=digest(ls),
                        canonical_sha256=digest(canonical(ls)),source_input=xs,
                        aliases=['overall positive integer scaling','reversal retained in same group'],attempt=attempt))
    return cases

def diagnostics(rs):
    return [dict(input_id=f'equal-{r}',group=f'equal-{r}',split='structural_diagnostic',seed=None,
        family='equal',variant='reserved',lengths=[7]*r,r=r,n=7*r,input_sha256=digest([7]*r),
        canonical_sha256=digest(canonical([7]*r)),source_input=None,aliases=[],attempt=0) for r in [0,1]+rs]

def audit_splits(groups):
    byhash={};bycanonical={};bygroup={};n=0
    for split,rows in groups.items():
        for c in rows:
            assert c['split']==split
            assert c['input_sha256']==digest(c['lengths'])
            assert c['canonical_sha256']==digest(canonical(c['lengths']))
            assert all(type(x)is int and x>0 for x in c['lengths'])
            for key,registry in [(c['input_sha256'],byhash),(c['canonical_sha256'],bycanonical),(c['group'],bygroup)]:
                assert key not in registry or registry[key]==split,(key,split,registry.get(key));registry[key]=split
            if c['source_input'] is not None:assert [len(r) for r in scan(c['source_input'])]==c['lengths']
            n+=1
    return dict(passed=True,inputs=n,base_groups=len(bygroup),unique_hashes=len(byhash),canonical_groups=len(bycanonical),
        caveat='No guarantee against coincidental structural similarity across independently generated groups; scale/reversal identity and explicit perturbation lineage checked.')
