"""Untimed-by-search exact interval DP and a DISTINCT postfix enumeration.
The evaluator imports this module; core.py never does. DP costs are label data
on TRAIN only, and post-search evaluation/certificate data on confirmation.
"""
import itertools


def dp(ls):
    n=len(ls);p=[0]
    for x in ls:p.append(p[-1]+x)
    d=[[0]*(n+1) for _ in range(n+1)];cuts={}
    for width in range(2,n+1):
        for i in range(n-width+1):
            j=i+width;k=min(range(i+1,j),key=lambda k:(d[i][k]+d[k][j],k))
            d[i][j]=p[j]-p[i]+d[i][k]+d[k][j];cuts[i,j]=k
    def tree(i,j):
        if i==j:return None
        if j==i+1:return i
        k=cuts[i,j];return (tree(i,k),tree(k,j))
    return dict(table=d,tree=tree(0,n),budget=d[0][n])


def postfix_trees(ls):
    """Choose leaf-token positions, simulate stack; NO interval DP recurrence."""
    n=len(ls)
    if not n:yield None,0;return
    for pos in itertools.combinations(range(2*n-1),n):
        pos=set(pos);stack=[];next_leaf=0;ok=True
        for step in range(2*n-1):
            if step in pos:
                stack.append((next_leaf,ls[next_leaf],0));next_leaf+=1
            elif len(stack)<2:ok=False;break
            else:
                b,wb,cb=stack.pop();a,wa,ca=stack.pop()
                stack.append(((a,b),wa+wb,ca+cb+wa+wb))
        if ok and len(stack)==1:yield stack[0][0],stack[0][2]


def lower_check(ls,d):
    n=len(ls)
    if len(d)!=n+1 or any(len(row)!=n+1 for row in d):return False
    if any(type(x) is not int or x<0 for row in d for x in row):return False
    if any(d[i][i]!=0 for i in range(n+1)):return False
    if any(d[i][i+1]!=0 for i in range(n)):return False
    for i in range(n):
        for j in range(i+2,n+1):
            for k in range(i+1,j):
                if d[i][j]>sum(ls[i:j])+d[i][k]+d[k][j]:return False
    return True


def execute(t,runs):
    if t is None:return [],0
    if isinstance(t,int):return list(runs[t]),0
    a,ca=execute(t[0],runs);b,cb=execute(t[1],runs);i=j=0;out=[];c=ca+cb
    while i<len(a) and j<len(b):
        c+=1
        if a[i]<=b[j]:out.append(a[i]);i+=1
        else:out.append(b[j]);j+=1
    return out+a[i:]+b[j:],c


def scan(xs):
    runs=[]
    for x in xs:
        if not runs or x<runs[-1][-1]:runs.append([x])
        else:runs[-1].append(x)
    return runs
