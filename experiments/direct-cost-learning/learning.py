"""Two real CPU-trained trees, standard library only.
Classifier: Gini CART on epsilon-tied fastest-candidate labels.
Regressor: multi-output squared-error CART predicting relative latency of ALL
candidates (time / that training input's candidate oracle). Integer leaf export
is also the training-side predictor; no Float drift in Lean deployment.
"""
import hashlib
import json
import math
import time

from data_protocol import config


def best_fixed(rows):
    assert rows and all(r['split']=='train' for r in rows)
    return min(range(7),key=lambda k:sum(r['costs_ns'][k] for r in rows))


def near_label(costs,preferred,tolerance):
    best=min(costs)
    eligible=[i for i,x in enumerate(costs) if x<=best*(1+tolerance)]
    return preferred if preferred in eligible else min(eligible)


def predict_values(tree,features):
    while tree['kind']=='branch':
        index=tree['feature']
        if not 0<=index<len(features): return None
        tree=tree['left'] if features[index]<=tree['threshold'] else tree['right']
    return tree['values']


def predict_raw(model,features):
    if not isinstance(model,dict): return None
    c=config()
    if model.get('schema_version')!=1 or model.get('feature_version')!=c['feature_version'] or model.get('candidate_version')!=c['candidate_version']:
        return None
    values=predict_values(model['tree'],features)
    if values is None: return None
    if model['kind']=='classifier': return values[0] if len(values)==1 else None
    if model['kind']=='cost_ranking' and len(values)==7 and all(v>=0 for v in values):
        return min(range(7),key=values.__getitem__)
    return None


def resolve(value): return value if type(value) is int and 0<=value<7 else 1
def predict(model,features): return resolve(predict_raw(model,features))


def fit(rows,kind,depth,min_leaf):
    c=config();start=time.perf_counter_ns()
    if not rows or any(r['split']!='train' for r in rows): raise ValueError('training rows only')
    if len({r['input_sha256'] for r in rows})!=len(rows): raise ValueError('duplicate training input')
    if any(len(r['features'])!=6 or len(r['costs_ns'])!=7 or any(t<=0 for t in r['costs_ns']) for r in rows):
        raise ValueError('incomplete/nonpositive direct timing labels')
    preferred=best_fixed(rows)
    labels=[near_label(r['costs_ns'],preferred,c['near_tie_fraction']) for r in rows]
    targets=[[t/min(r['costs_ns']) for t in r['costs_ns']] for r in rows]

    def stats(indices):
        n=len(indices)
        if kind=='classifier':
            counts=[sum(labels[i]==k for i in indices) for k in range(7)]
            selected=min(range(7),key=lambda k:(-counts[k],k!=preferred,k))
            return [selected],n-sum(v*v for v in counts)/n
        means=[sum(targets[i][k] for i in indices)/n for k in range(7)]
        loss=sum(sum((targets[i][k]-means[k])**2 for k in range(7)) for i in indices)
        return [max(0,int(v*c['relative_cost_scale']+0.5)) for v in means],loss

    def grow(indices,level):
        values,loss=stats(indices)
        leaf={'kind':'leaf','values':values}
        if level>=depth or len(indices)<2*min_leaf or loss<=1e-12: return leaf
        best=None;best_loss=loss
        for feature in range(6):
            cuts=sorted({rows[i]['features'][feature] for i in indices})[:-1]
            cap=c['tree_max_split_candidates']
            if len(cuts)>cap: cuts=[cuts[j*(len(cuts)-1)//(cap-1)] for j in range(cap)]
            for threshold in cuts:
                left=[i for i in indices if rows[i]['features'][feature]<=threshold]
                right=[i for i in indices if rows[i]['features'][feature]>threshold]
                if min(len(left),len(right))<min_leaf: continue
                child_loss=stats(left)[1]+stats(right)[1]
                if child_loss<best_loss-1e-10:
                    best_loss=child_loss;best=(feature,threshold,left,right)
        if best is None: return leaf
        f,t,left,right=best
        return dict(kind='branch',feature=f,threshold=t,left=grow(left,level+1),right=grow(right,level+1))

    model=dict(schema_version=1,kind=kind,candidate_version=c['candidate_version'],
        feature_version=c['feature_version'],feature_names=c['feature_names'],
        tree=grow(list(range(len(rows))),0),hyperparameters=dict(depth=depth,min_leaf=min_leaf),
        training_inputs=len(rows),training_hash=hashlib.sha256(json.dumps(sorted(r['input_sha256'] for r in rows)).encode()).hexdigest(),
        target='epsilon-tied fastest candidate ID' if kind=='classifier' else 'relative latency time/input-oracle; integer scale 1000000',
        training_preferred_id=preferred)
    model['training_ns']=time.perf_counter_ns()-start
    return model


def size(model):
    def walk(t):
        if t['kind']=='leaf': return 1,0
        a,b=walk(t['left']);c,d=walk(t['right']);return 1+a+c,1+max(b,d)
    nodes,depth=walk(model['tree'])
    return dict(nodes=nodes,depth=depth,json_bytes=len(json.dumps(model,separators=(',',':')).encode()),training_ns=model['training_ns'])


def quality(model,rows):
    ratios=[];accuracy=0;near=0;selected=[]
    for row in rows:
        i=predict(model,row['features']);cost=row['costs_ns'][i];best=min(row['costs_ns'])
        selected.append(cost);ratios.append(cost/best)
        accuracy+=cost==best;near+=cost<=best*1.02
    return dict(plan_only_sum_ns=sum(selected),mean_oracle_ratio=sum(ratios)/len(ratios),
        winner_accuracy=accuracy/len(rows),within_two_percent=near/len(rows),
        note='selection-quality diagnostic; excludes feature and inference overhead')


def describe(model):
    names=config()['feature_names'];candidates=config()['candidate_ids']
    def walk(t,indent):
        if t['kind']=='leaf':
            value=t['values']
            return [indent+('return '+candidates[resolve(value[0])] if model['kind']=='classifier'
                else 'relative_costs='+str(value)+' -> '+candidates[min(range(7),key=value.__getitem__)])]
        return [indent+f'if {names[t["feature"]]} <= {t["threshold"]}:']+walk(t['left'],indent+'  ')+[indent+'else:']+walk(t['right'],indent+'  ')
    return '\n'.join(walk(model['tree'],''))
