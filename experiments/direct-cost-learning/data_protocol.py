"""Versioned grouped data; all shapes from one base sequence share a split.
No previous interpreter or direct timing is used as a training label.
"""
import hashlib
import json
from pathlib import Path
import random
import sys

HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[1]
sys.path.append(str(ROOT/'experiments/dynamic-runs'))
from dyn_reference import evaluate,discover,plan,signature
from datasets import random_sizes,sorted_chunks,SHAPES


def config(): return json.loads((HERE/'config.json').read_text())
def digest(xs): return hashlib.sha256(repr(xs).encode()).hexdigest()


def features(xs):
    n=len(xs);k=min(16,max(0,n-1))
    positions=[i*max(0,n-2)//max(1,k-1) for i in range(k)]
    if not positions: return [n,0,0,0,0,0],0
    low=high=previous=xs[positions[0]]
    desc=equal=cross=0
    comparisons=0
    for i,p in enumerate(positions):
        x,y=xs[p],xs[p+1]
        le=x<=y; ge=y<=x; lower=x<=low; higher=high<=x; rising=previous<=x
        comparisons+=5
        desc+=not le;equal+=le and ge;cross+=i>0 and not rising
        low=x if lower else low;high=x if higher else high;previous=x
    return [n,k,1000*desc//k,1000*equal//k,1000*cross//max(1,k-1),high-low],comparisons


def derive(base,family,rng):
    n=len(base)
    if family=='random': return base[:]
    if family=='sorted': return sorted(base)
    if family=='reverse': return sorted(base,reverse=True)
    if family=='duplicates':
        offset=min(base)//100000*100000
        return [offset+x%5 for x in base]
    if family=='perturbed':
        out=sorted(base)
        for _ in range(max(1,n//25)):
            a,b=rng.sample(range(n),2);out[a],out[b]=out[b],out[a]
        return out
    if family=='short_runs': sizes=random_sizes(n,rng,1,4)
    elif family=='long_runs': sizes=random_sizes(n,rng,max(2,n//4),max(3,n//2))
    elif family=='unequal_runs': sizes=random_sizes(n,rng,1,max(2,2*n//3))
    elif family=='random_boundaries':
        interior=[i for i in range(1,n) if rng.random()<0.11]
        if not interior: interior=[rng.randrange(1,n)]
        bounds=[0]+interior+[n];sizes=[b-a for a,b in zip(bounds,bounds[1:])]
    elif family=='skewed_runs':
        small=max(3,n//8);sizes=[1]*small
        sizes.insert(rng.randrange(len(sizes)+1),n-small)
    else: raise ValueError(family)
    return sorted_chunks(base,sizes)


def generate(split,lengths,seeds):
    cases=[]
    for seed in seeds:
        for n in lengths:
            rng=random.Random(seed*1000033+n*101)
            # Offset separates physical sequences across base groups but is NOT
            # a feature: range and order are invariant under this translation.
            base=[seed*100000+x for x in rng.sample(range(16*n),n)]
            base_hash=digest(base)
            group=f'base-{seed}-{n}'
            by_hash={}
            for index,family in enumerate(SHAPES):
                xs=derive(base,family,random.Random(seed*1000033+n*101+index*17011))
                h=digest(xs)
                if h in by_hash:
                    by_hash[h]['family_aliases'].append(family)
                    continue
                row=dict(input_id=f'{split}-{seed}-{n}-{family}',group_id=group,
                    base_sha256=base_hash,base_input=base,split=split,seed=seed,family=family,
                    family_aliases=[family],input=xs,input_sha256=h,n=n,expected=sorted(xs))
                by_hash[h]=row;cases.append(row)
    return cases


def protocol(smoke=False):
    c=config()
    return dict(lengths=c['smoke_lengths'] if smoke else c['train_lengths'],
        train_seeds=c['smoke_train_seeds'] if smoke else c['train_seeds'],
        prefixes=c['smoke_training_seed_prefixes'] if smoke else c['training_seed_prefixes'],
        validation_seeds=c['smoke_validation_seeds'] if smoke else c['validation_seeds'],
        test_seeds=c['smoke_test_seeds'] if smoke else c['test_seeds'],rounds=3 if smoke else c['rounds'])


def old_hashes():
    hashes=set()
    for dirname in ['direct-executor','dynamic-runs','cost-plans','adaptive','hybrid-threshold']:
        for path in (ROOT/'experiments'/dirname).rglob('*.jsonl'):
            if not any(x in path.name for x in ['dataset','train','heldout','test']): continue
            for line in path.read_text().splitlines():
                row=json.loads(line)
                if isinstance(row.get('input'),list): hashes.add(digest(row['input']))
    return hashes


def assert_split_integrity(collections,prior=None):
    owners={};groups={};bases={};ids=set()
    for split,cases in collections.items():
        for c in cases:
            assert c['split']==split and c['input_id'] not in ids
            ids.add(c['input_id'])
            assert c['input_sha256']==digest(c['input']) and c['expected']==sorted(c['input'])
            assert c['base_sha256']==digest(c['base_input'])
            for owner,key in [(owners,c['input_sha256']),(groups,c['group_id']),(bases,c['base_sha256'])]:
                assert key not in owner or owner[key]==split,'cross-split leakage'
                owner[key]=split
            if split in ['test','generalization'] and prior is not None:
                assert c['input_sha256'] not in prior,'previously seen final input'
        assert len({c['input_sha256'] for c in cases})==len(cases),'duplicate observations'
    return dict(inputs=len(ids),unique_hashes=len(owners),base_groups=len(groups),passed=True)
