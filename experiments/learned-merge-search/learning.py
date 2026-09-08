"""CPU CART regressor for normalized optimal-continuation REGRET, not bounds."""
import json
import time
from core import FEATURE_NAMES,features,predict,flat_predict
from reference import dp


def labels(cases):
    rows=[];start=time.perf_counter_ns();dp_ns=0
    for c in cases:
        assert c['split']=='train'
        ls=c['lengths'];a=time.perf_counter_ns();d=dp(ls)['table'];dp_ns+=time.perf_counter_ns()-a
        for width in range(2,len(ls)+1):
            for i in range(len(ls)-width+1):
                j=i+width;w=sum(ls[i:j])
                for k in range(i+1,j):
                    rows.append(dict(input_id=c['input_id'],group=c['group'],split='train',i=i,k=k,j=j,
                        features=features(ls,i,k,j),target=1000000*(w+d[i][k]+d[k][j]-d[i][j])//w))
    return rows,dict(label_generation_ns=time.perf_counter_ns()-start,dp_ns=dp_ns,rows=len(rows))


def fit(rows,depth,min_leaf=16):
    start=time.perf_counter_ns();assert rows and all(r['split']=='train' for r in rows)
    def grow(ids,level):
        vals=[rows[i]['target'] for i in ids];n=len(ids);s=sum(vals);ss=sum(v*v for v in vals)
        leaf={'value':(s+n//2)//n};loss=ss-s*s/n
        if level>=depth or n<min_leaf*2 or loss<=0:return leaf
        best=None;bestloss=loss
        for f in range(len(FEATURE_NAMES)):
            ordered=sorted(ids,key=lambda i:rows[i]['features'][f]);cuts=[]
            for x in range(1,n):
                if rows[ordered[x-1]]['features'][f]!=rows[ordered[x]]['features'][f]:cuts.append(x)
            if len(cuts)>16:cuts=[cuts[q*(len(cuts)-1)//15] for q in range(16)]
            wanted=set(cuts);sl=ssl=0
            for x,idx in enumerate(ordered,1):
                y=rows[idx]['target'];sl+=y;ssl+=y*y
                if x not in wanted or x<min_leaf or n-x<min_leaf:continue
                v=ssl-sl*sl/x+(ss-ssl)-(s-sl)*(s-sl)/(n-x)
                if v<bestloss-1e-8:bestloss=v;best=(f,rows[idx]['features'][f],ordered[:x],ordered[x:])
        if best is None:return leaf
        f,t,l,r=best
        return dict(feature=f,threshold=t,left=grow(l,level+1),right=grow(r,level+1))
    m=dict(schema_version=1,feature_names=FEATURE_NAMES,target='optimal continuation regret / interval weight * 1000000',
        hyperparameters=dict(depth=depth,min_leaf=min_leaf),training_rows=len(rows),tree=grow(list(range(len(rows))),0))
    nodes=[]
    def export(t):
        at=len(nodes);nodes.append(None)
        if 'value' in t:nodes[at]=[-1,t['value'],0,0]
        else:
            l=export(t['left']);r=export(t['right']);nodes[at]=[t['feature'],t['threshold'],l,r]
        return at
    export(m['tree']);m['nodes']=nodes;m['fit_ns']=time.perf_counter_ns()-start
    assert all(predict(m,r['features'])==flat_predict(nodes,r['features']) for r in rows)
    m['model_bytes']=len(json.dumps(m).encode())
    return m
