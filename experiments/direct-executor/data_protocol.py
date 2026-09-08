"""Prior fixed diagnostic inputs; separately seeded confirmation after freeze."""
import hashlib
import json
from pathlib import Path
import random
import sys

ROOT=Path(__file__).resolve().parents[2]
sys.path.append(str(ROOT/'experiments/dynamic-runs'))
from datasets import SHAPES, make
from dyn_reference import discover, evaluate, plan, signature, tree_stats


def config():
    return json.loads((Path(__file__).parent/'config.json').read_text())


def paired():
    cases=[json.loads(s) for s in (ROOT/config()['paired_data']).read_text().splitlines()]
    assert len(cases)==98
    return [dict(c,stage='paired',source_id=c['id']) for c in cases]


def generated(stage, sizes, seeds, shapes=SHAPES):
    cases=[]
    for seed in seeds:
        for n in sizes:
            for index,shape in enumerate(shapes):
                rng=random.Random(seed*1000033+n*101+SHAPES.index(shape)*17011)
                xs=make(shape,n,rng)
                cases.append(dict(id=f'{stage}-{seed}-{n}-{shape}',stage=stage,shape=shape,
                    seed=seed,input=xs,expected=sorted(xs),
                    input_sha256=hashlib.sha256(repr(xs).encode()).hexdigest()))
    return cases


def confirmation():
    c=config()
    cases=generated('confirmation',c['confirmation_sizes'],c['confirmation_seeds'])
    random.Random(3909).shuffle(cases)
    assert not {c['input_sha256'] for c in cases}&{c['input_sha256'] for c in paired()}
    return cases


def smoke():
    c=config()
    cases=generated('smoke',c['smoke_sizes'],c['smoke_seeds'])
    return cases+[dict(x,stage='smoke') for x in paired() if x['shape'].startswith('edge_')]


def extension():
    c=config()
    return generated('extension',c['extension_sizes'],[c['extension_seed']],c['extension_shapes'])


def variants(ablations=True):
    c=config()
    return [(s,m) for s in c['strategies'] for m in
        (c['primary_modes']+(c['adaptive_ablation_modes'] if ablations and s.startswith('runs_') else []))]
