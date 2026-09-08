"""Cross-run smoke/pilot novelty and frozen selected-model file identity."""
import json,sys
from pathlib import Path
P=Path(__file__).resolve().parent;sys.path.insert(0,str(P.parents[1]))
from data import canonical,digest
seen=set();prior_rows=0
for d in P.parent.glob('*-smoke-*'):
    for f in d.glob('dataset-*.jsonl'):
        for line in f.read_text().splitlines():
            seen.add(canonical(json.loads(line)['lengths']));prior_rows+=1
for line in (P/'pilot.jsonl').read_text().splitlines():seen.add(canonical(json.loads(line)['case']['lengths']))
matches=[];new=0
for phase in ['confirmation','extrapolation']:
    for line in (P/f'dataset-{phase}.jsonl').read_text().splitlines():
        c=json.loads(line);new+=1
        if canonical(c['lengths']) in seen:matches.append(c['input_id'])
assert not matches
frozen=json.loads((P/'frozen.json').read_text())
saved=json.loads((P/'models'/f'depth-{frozen["selected_depth"]}.json').read_text())
assert saved==frozen['model'] and digest(saved)==frozen['model_sha256']
result=dict(passed=True,prior_smoke_rows=prior_rows,checked_final_inputs=new,canonical_matches=matches,
    selected_model_file_equals_frozen=True,scope='Scale/reversal exact equivalence, not arbitrary near-similarity; reserved equal diagnostics excluded intentionally.')
(P/'novelty-audit.json').write_text(json.dumps(result,indent=2)+'\n')
print(result)
