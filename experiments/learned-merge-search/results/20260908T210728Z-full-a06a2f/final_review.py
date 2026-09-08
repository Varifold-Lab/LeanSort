"""Post-freeze independent numerical/serialization/trajectory audit. No fitting."""
import json
from pathlib import Path
from fractions import Fraction
from collections import Counter,defaultdict
import statistics
import sys
P=Path(__file__).resolve().parent
sys.path.insert(0,str(P.parents[1]))
from core import features,predict,flat_predict,search,stats
from data import digest
from reporting import dist

def rows(name):return [json.loads(x) for x in (P/name).read_text().splitlines()]
frozen=json.loads((P/'frozen.json').read_text());model=frozen['model']
def independent_features(ls,i,k,j):
    whole=ls[i:j];a=ls[i:k];b=ls[k:j];w=sum(whole);m=len(whole)
    floor=lambda x:int(1000*x)
    return [m,floor(Fraction(len(a),m)),floor(Fraction(sum(a),w)),
      floor(abs(2*Fraction(sum(a),w)-1)),floor(abs(2*Fraction(len(a),m)-1)),
      floor(Fraction(max(whole),w)),floor(sum(Fraction(x,w)**2 for x in whole)),
      floor(Fraction(max(a),w)),floor(Fraction(max(b),w)),floor(Fraction(ls[k-1]+ls[k],w))]

all_entries=sum([rows(f'evaluation-{phase}.jsonl') for phase in ['confirmation','extrapolation','structural_diagnostic']],[])
feature_checks=0;replays=0
for e in all_entries:
    ls=e['case']['lengths']
    for i in range(len(ls)):
        for j in range(i+2,len(ls)+1):
            for k in range(i+1,j):
                f=independent_features(ls,i,k,j)
                assert f==features(ls,i,k,j)
                assert predict(model,f)==flat_predict(model['nodes'],f)
                feature_checks+=1
    for method in ['fixed','heuristic','learned']:
        replay=search(ls,method,max(frozen['protocol']['node_budgets']),model=model)
        for saved in e['searches']:
            if saved['method']!=method or saved['mode']!='nodes' or saved['status']!='ok':continue
            assert digest(replay['tree'])==digest(saved['tree']) and replay['budget']==saved['budget']
            assert [(x['nodes'],x['budget'],digest(x['tree'])) for x in replay['events']]==[(x['nodes'],x['budget'],digest(x['tree'])) for x in saved['events']]
        replays+=1

def rowset(e,method,mode='nodes',wall=None):
    return [r for r in e['searches'] if r['method']==method and r['mode']==mode and r['wall_limit_ns']==wall and r['status']=='ok']
def med(xs):return statistics.median(xs)
details={}
for phase in ['confirmation','extrapolation','structural_diagnostic']:
    entries=[e for e in all_entries if e['case']['split']==phase];methods={}
    for method in ['fixed','heuristic','learned']:
        times=[];ratios=[];first=[];near=[];shares=[];fns=[];ins=[];initial_hits=0
        for e in entries:
            rs=rowset(e,method);t=med([r['elapsed_ns'] for r in rs]);times.append(t);ratios.append(t/e['reference']['median_ns'])
            fns.append(med([r['feature_ns'] for r in rs]));ins.append(med([r['inference_ns'] for r in rs]))
            shares.append(med([(r['feature_ns']+r['inference_ns'])/r['elapsed_ns'] for r in rs]))
            initial_hits+=rs[0]['initial_budget']==e['reference']['budget']
            for key,dest in [('first_optimal_ns',first),('first_target_ns',near)]:
                vs=[r['quality'][key] for r in rs if r['quality'][key] is not None]
                if len(vs)==len(rs):dest.append(med(vs))
        methods[method]=dict(total_search_ns=dist(times),search_to_dp_time=dist(ratios),initial_optimal_inputs=initial_hits,
           first_optimal_ns=dist(first),unreached_optimal=len(entries)-len(first),first_101pct_ns=dist(near),
           unreached_101pct=len(entries)-len(near),feature_ns=dist(fns),inference_ns=dist(ins),
           feature_plus_inference_fraction=dist(shares))
    pairing={}
    for n in frozen['protocol']['node_budgets']:
        signs=Counter();ratios=[];timing=[];byseed=defaultdict(list)
        for e in entries:
            l=rowset(e,'learned');h=rowset(e,'heuristic')
            a=med([x['quality']['at_nodes'][str(n)]['budget'] for x in l]);b=med([x['quality']['at_nodes'][str(n)]['budget'] for x in h])
            signs['better' if a<b else 'worse' if a>b else 'equal']+=1
            ratios.append(a/b if b else 1)
            timing.append(med([x['quality']['at_nodes'][str(n)]['elapsed_ns'] for x in l])/med([x['quality']['at_nodes'][str(n)]['elapsed_ns'] for x in h]))
            byseed[str(e['case']['seed'])].append(a/b if b else 1)
        pairing[str(n)]=dict(counts=dict(signs),budget_ratio=dist(ratios),time_ratio=dist(timing),seed_ratios={k:dist(v) for k,v in byseed.items()})
    details[phase]=dict(methods=methods,paired_learned_vs_heuristic=pairing)

requests=rows('checker-requests.jsonl');responses=rows('checker-responses.jsonl');certified_costs=0;ex=0;dp_length=Counter()
def weighted_depth(t,ls,depth=0):
    if t is None:return 0
    if isinstance(t,int):return depth*ls[t]
    return weighted_depth(t[0],ls,depth+1)+weighted_depth(t[1],ls,depth+1)
for q,reply in zip(requests,responses):
    if q['input_id']=='invalid-fallback':continue
    req=q['request'];res=reply['response'];ls=req['lengths']
    for t,b in zip(req['trees'],res['budgets']):assert weighted_depth(t,ls)==b;certified_costs+=1
    if req['execute']:
        ex+=len(res['executions'])
        e=next(e for e in all_entries if e['case']['input_id']==q['input_id'])
        hashes=[digest(t) for t in req['trees']]
        d=res['executions'][hashes.index(digest(e['reference']['tree']))]
        l=res['executions'][hashes.index(digest(e['baselines']['length']['tree']))]
        if d['budget']<l['budget']:dp_length['strict_budget_improvement']+=1
        dp_length['fewer_comparisons' if d['comparisons']<l['comparisons'] else 'more_comparisons' if d['comparisons']>l['comparisons'] else 'same_comparisons']+=1

result=dict(passed=True,independent_feature_and_export_checks=feature_checks,node_search_replays=replays,
    weighted_leaf_depth_cost_checks=certified_costs,executed_distinct_trees=ex,dp_vs_length_execution_samples=dict(dp_length),
    details=details,model_features_used=dict(Counter(n[0] for n in model['nodes'] if n[0]>=0)),
    model_nodes=len(model['nodes']),model_bytes=model['model_bytes'],
    note='Post-test analysis/audit only. Node replay compares structure/budget, never new timing. Goal times mean first attainment, not certified recognition; unreachable instances kept separately.')
(P/'final-review.json').write_text(json.dumps(result,indent=2,sort_keys=True)+'\n')
print(json.dumps({k:v for k,v in result.items() if k!='details'},indent=2))
