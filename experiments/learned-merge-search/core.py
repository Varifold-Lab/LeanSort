"""One finite DFS constructor; learned scores ONLY reorder identical actions.
No dynamic programming, reference optimum, prediction-based pruning or beam.
The certified global lower bound during search is zero. Queue exhaustion is
reported as operational status, never as a Lean optimality certificate.
"""
from dataclasses import dataclass
import time


def leaves(t):
    if t is None:return []
    if isinstance(t,int):return [t]
    return leaves(t[0])+leaves(t[1])


def stats(t,ls):
    if t is None:return 0,0
    if isinstance(t,int):return ls[t],0
    a,x=stats(t[0],ls);b,y=stats(t[1],ls)
    return a+b,x+y+a+b


def valid(t,ls):
    return leaves(t)==list(range(len(ls))) and (t is None)==(not ls)


def plan(ls,kind='count',i=0,j=None):
    j=len(ls) if j is None else j
    if j==i:return None
    if j==i+1:return i
    if kind=='count':k=(i+j)//2
    else:
        # Existing integer-midpoint length policy, including odd/even ties.
        total=sum(ls[i:j]);at=0;scores=[]
        for k in range(i+1,j):
            at+=ls[k-1];scores.append((abs(2*at-total),k if total%2==0 else -k,k))
        k=min(scores)[2]
    return (plan(ls,kind,i,k),plan(ls,kind,k,j))


FEATURE_NAMES=['runs','left_count_per_mille','left_weight_per_mille',
 'weight_imbalance','count_imbalance','max_share','concentration',
 'left_max_share','right_max_share','boundary_share']


def features(ls,i,k,j):
    v=ls[i:j];left=ls[i:k];right=ls[k:j];total=sum(v);lw=sum(left)
    # Length metadata only; all slices, scans and arithmetic timed in search.
    return [len(v),1000*len(left)//len(v),1000*lw//total,
        1000*abs(2*lw-total)//total,1000*abs(2*len(left)-len(v))//len(v),
        1000*max(v)//total,1000*sum(x*x for x in v)//(total*total),
        1000*max(left)//total,1000*max(right)//total,
        1000*(ls[k-1]+ls[k])//total]


def predict(model,fs):
    t=model['tree']
    while 'feature' in t:t=t['left'] if fs[t['feature']]<=t['threshold'] else t['right']
    return t['value']


def flat_predict(nodes,fs):
    at=0
    for _ in range(len(nodes)+1):
        if not 0<=at<len(nodes):raise ValueError('invalid node index')
        if nodes[at][0]<0:return nodes[at][1]
        f,cut,a,b=nodes[at]
        if not 0<=f<len(fs):raise ValueError('invalid feature index')
        at=a if fs[f]<=cut else b
    raise ValueError('cyclic model')


@dataclass(frozen=True)
class Hole:
    i:int
    j:int


def hole(i,j):return i if j==i+1 else Hole(i,j)


def first_hole(t,path=()):
    if isinstance(t,Hole):return path,t
    if t is None or isinstance(t,int):return None
    return first_hole(t[0],path+(0,)) or first_hole(t[1],path+(1,))


def replace(t,path,value):
    if not path:return value
    a,b=t
    return (replace(a,path[1:],value),b) if path[0]==0 else (a,replace(b,path[1:],value))


def complete(t,ls):
    if isinstance(t,Hole):return plan(ls,'count',t.i,t.j)
    if t is None or isinstance(t,int):return t
    return (complete(t[0],ls),complete(t[1],ls))


def search(ls,order,node_limit=256,wall_ns=None,model=None):
    start=time.perf_counter_ns()
    if any(type(x) is not int or x<=0 for x in ls):raise ValueError('positive lengths required')
    initial=[plan(ls,'count'),plan(ls,'length')]
    incumbent=min(initial,key=lambda t:stats(t,ls)[1]);upper=stats(incumbent,ls)[1]
    events=[dict(nodes=0,elapsed_ns=time.perf_counter_ns()-start,budget=upper,tree=incumbent)]
    stack=[hole(0,len(ls))] if ls else []
    seen=set();nodes=0;duplicates=0;features_ns=0;inference_ns=0;model_calls=0;fallbacks=0
    timeline=[];termination='exhausted'
    while stack:
        if nodes>=node_limit:termination='node_budget';break
        if wall_ns is not None and time.perf_counter_ns()-start>=wall_ns:termination='wall_budget';break
        partial=stack.pop()
        if partial in seen:duplicates+=1;continue
        seen.add(partial);nodes+=1
        t=complete(partial,ls);b=stats(t,ls)[1]
        if b<upper:
            upper=b;incumbent=t
            events.append(dict(nodes=nodes,elapsed_ns=time.perf_counter_ns()-start,budget=upper,tree=t))
        pending=first_hole(partial)
        if pending:
            path,h=pending;cuts=list(range(h.i+1,h.j))
            if order=='heuristic':
                total=sum(ls[h.i:h.j]);at=0;rank={}
                for k in cuts:
                    at+=ls[k-1];rank[k]=(abs(2*at-total),abs(2*k-h.i-h.j),k)
                cuts.sort(key=rank.__getitem__)
            elif order=='learned':
                rank={}
                for k in cuts:
                    a=time.perf_counter_ns();fs=features(ls,h.i,k,h.j);features_ns+=time.perf_counter_ns()-a
                    a=time.perf_counter_ns()
                    try:
                        score=flat_predict(model['nodes'],fs)
                        if type(score) is not int:raise ValueError('bad score')
                    except (KeyError,IndexError,TypeError,ValueError):score=0;fallbacks+=1
                    inference_ns+=time.perf_counter_ns()-a;model_calls+=1;rank[k]=(score,k)
                cuts.sort(key=rank.__getitem__)
            elif order!='fixed':raise ValueError(order)
            # An invalid priority value can never create a cut or remove one.
            assert sorted(cuts)==list(range(h.i+1,h.j))
            for k in reversed(cuts):stack.append(replace(partial,path,(hole(h.i,k),hole(k,h.j))))
        timeline.append(dict(nodes=nodes,elapsed_ns=time.perf_counter_ns()-start,budget=upper))
    assert valid(incumbent,ls)
    elapsed=time.perf_counter_ns()-start
    return dict(tree=incumbent,budget=upper,initial_budget=events[0]['budget'],lower_bound=0,
        nodes=nodes,elapsed_ns=elapsed,feature_ns=features_ns,inference_ns=inference_ns,
        model_calls=model_calls,model_fallbacks=fallbacks,duplicates=duplicates,frontier=len(stack),
        termination=termination,events=events,timeline=timeline,
        status='ok',optimality='not_claimed_by_search')
