"""First-attainment on hard inputs, with censoring; only saved event times."""
import json,statistics
from pathlib import Path
import sys
P=Path(__file__).resolve().parent;sys.path.insert(0,str(P.parents[1]))
from reporting import dist
out={}
for phase in ['confirmation','extrapolation']:
    entries=[json.loads(x) for x in (P/f'evaluation-{phase}.jsonl').read_text().splitlines()]
    d={}
    for label,num in [('optimal',100),('within_one_percent',101)]:
        hard=[e for e in entries if 100*e['searches'][0]['initial_budget']>num*e['reference']['budget']]
        hits={};times={}
        for method in ['fixed','heuristic','learned']:
            t={}
            for e in hard:
                rs=[r for r in e['searches'] if r['method']==method and r['mode']=='nodes']
                elapsed=[]
                for r in rs:
                    es=[x for x in r['events'] if 100*x['budget']<=num*e['reference']['budget']]
                    if es:elapsed.append(es[0]['elapsed_ns'])
                if len(elapsed)==len(rs):t[e['case']['input_id']]=statistics.median(elapsed)
            hits[method]=dict(reached=len(t),not_reached=len(hard)-len(t),first_time_ns=dist(list(t.values())))
            times[method]=t
        common=times['learned'].keys()&times['heuristic'].keys()
        paired=[times['learned'][i]/times['heuristic'][i] for i in common]
        d[label]=dict(hard_inputs=len(hard),methods=hits,common_reached=len(common),learned_over_heuristic_time=dist(paired),
            note='Conditional paired first attainment, not recognition/certification time or an uncensored average.')
    out[phase]=d
(P/'goal-analysis.json').write_text(json.dumps(out,indent=2,sort_keys=True)+'\n')
print(json.dumps(out,indent=2))
