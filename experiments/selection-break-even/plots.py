"""Static quantitative charts using existing Pillow; no new plotting dependency.
Log2 length axes, paired input-median ratios, input P10-P90 bands, not CIs.
"""
import csv
import math
from pathlib import Path
import statistics
from PIL import Image,ImageDraw,ImageFont
from common import FAMILIES

COLORS={'rule':'#228833','classifier':'#4477AA','cost_ranking':'#EE7733','hybrid':'#777777','oracle':'#AA3377','kernel':'#4477AA','online':'#EE7733'}
FONT='/System/Library/Fonts/Supplemental/Arial.ttf'
def font(size):return ImageFont.truetype(FONT,size)
def quant(v,p):
    a=sorted(v);x=(len(a)-1)*p;i=int(x);return a[i]+(a[min(i+1,len(a)-1)]-a[i])*(x-i)
def curve(rows,value):
    return [(n,statistics.median(v),quant(v,.1),quant(v,.9)) for n in sorted({r['n'] for r in rows}) if (v:=[value(r) for r in rows if r['n']==n])]
def rgb(c):return tuple(int(c[i:i+2],16) for i in [1,3,5])

def panel(draw,box,curves,title,yrange=None,xlabel='List length n (log2)',ylabel='Paired E2E / fixed'):
    left,top,right,bottom=box;l=left+72;t=top+65;r=right-22;b=bottom-72
    pts=[pt for values in curves.values() for pt in values]
    if not pts:return
    lo,hi=min(p[0] for p in pts),max(p[0] for p in pts)
    ymin,ymax=yrange or (min(.5,min(p[2] for p in pts)*.95),max(1.1,max(p[3] for p in pts)*1.05))
    X=lambda n:l+(math.log2(n)-math.log2(lo))/max(1,math.log2(hi)-math.log2(lo))*(r-l)
    Y=lambda y:b-(y-ymin)/(ymax-ymin)*(b-t)
    draw.text((left+12,top+10),title,fill='#222222',font=font(20))
    for i in range(6):
        y=ymin+(ymax-ymin)*i/5;at=Y(y)
        draw.line((l,at,r,at),fill='#e0e0e0',width=1)
        draw.text((left+5,at-8),f'{y:.2f}',fill='#444444',font=font(15))
    for e in range(math.ceil(math.log2(lo)),math.floor(math.log2(hi))+1):
        n=2**e
        if (hi/lo>16 and e%2) or (right-left<700 and e%2):continue
        x=X(n);draw.line((x,b,x,b+5),fill='#555555');draw.text((x-17,b+8),str(n),fill='#444444',font=font(14))
    draw.line((l,t,l,b,r,b),fill='#555555',width=2)
    if ymin<=1<=ymax:draw.line((l,Y(1),r,Y(1)),fill='#222222',width=2)
    for index,(name,values) in enumerate(curves.items()):
        color=COLORS.get(name,['#4477AA','#EE7733','#228833','#AA3377'][index%4]);base=rgb(color)
        pale=tuple(int(.83*255+.17*x) for x in base)
        if len(values)>1:
            polygon=[(X(n),Y(low)) for n,mid,low,high in values]+[(X(n),Y(high)) for n,mid,low,high in reversed(values)]
            draw.polygon(polygon,fill=pale)
        line=[(X(n),Y(mid)) for n,mid,low,high in values]
        draw.line(line,fill=color,width=3)
        for j,(x,y) in enumerate(line):
            if index%2:draw.rectangle((x-3,y-3,x+3,y+3),fill=color)
            else:draw.ellipse((x-3,y-3,x+3,y+3),fill=color)
        draw.text((l+index*(r-l)/max(1,len(curves)),bottom-27),name,fill=color,font=font(15))
    if ymin<=1<=ymax:draw.line((l,Y(1),r,Y(1)),fill='#222222',width=1)
    draw.text(((l+r)/2-85,b+30),xlabel,fill='#333333',font=font(15))
    draw.text((l,top+36),ylabel+'; band = input P10-P90',fill='#555555',font=font(14))

def draw_chart(path,curves,title,ylabel='Paired E2E / fixed'):
    im=Image.new('RGB',(1300,760),'white');draw=ImageDraw.Draw(im)
    panel(draw,(20,15,1275,735),curves,title,ylabel=ylabel);im.save(path)

def figures(p,rows):
    out=p/'figures';out.mkdir(exist_ok=True)
    good=[r for r in rows if r['status']=='ok' and r['family'] in FAMILIES]
    if not good:return
    value=lambda name:(lambda r:r['policies'][name]['median_ns']/r['policies']['fixed']['median_ns'])
    names=['hybrid','rule','classifier','cost_ranking']
    curves={k:curve(good,value(k)) for k in names}
    draw_chart(out/'01-scale.png',curves,'Frozen selectors: net cost changes with n, not one universal threshold')
    im=Image.new('RGB',(1680,1800),'white');draw=ImageDraw.Draw(im)
    all_ratios=[value(k)(r) for k in names for r in good]
    limits=(min(.5,min(all_ratios)*.95),max(1.1,max(all_ratios)*1.05))
    for idx,family in enumerate(FAMILIES):
        subset=[r for r in good if family in r['family_aliases']]
        panel(draw,(idx%3*560,idx//3*600,(idx%3+1)*560,(idx//3+1)*600),
            {k:curve(subset,value(k)) for k in ['rule','classifier','cost_ranking']},family,yrange=limits)
    im.save(out/'02-shapes.png')
    im=Image.new('RGB',(1500,700),'white');draw=ImageDraw.Draw(im)
    comparisons={k:{'kernel':curve(good,lambda r,k=k:r['policies'][k]['selected_only_median_ns']/r['costs_ns'][5]),'online':curve(good,value(k))} for k in ['classifier','cost_ranking']}
    bounds=(min(.5,min(v[2] for cs in comparisons.values() for vs in cs.values() for v in vs)),max(1.1,max(v[3] for cs in comparisons.values() for vs in cs.values() for v in vs)*1.05))
    for i,(k,cs) in enumerate(comparisons.items()):
        panel(draw,(750*i,0,750*(i+1),680),cs,k+': chosen kernel vs net deployment',yrange=bounds,ylabel='Cost / matching fixed baseline')
    im.save(out/'03-kernel-online.png')
    oracle={'oracle':curve(good,lambda r:min(r['costs_ns'])/r['costs_ns'][5])}
    oracle.update({k:curve(good,lambda r,k=k:r['policies'][k]['selected_only_median_ns']/r['costs_ns'][5]) for k in ['rule','classifier','cost_ranking']})
    draw_chart(out/'04-oracle.png',oracle,'Free candidate Oracle versus selected kernels (selection overhead excluded)',ylabel='Kernel / fixed kernel')
    structural=[dict(r,n=r['observed_runs']) for r in rows if r['status']=='ok' and any(a.startswith('structure_') for a in r['family_aliases'])]
    if structural:
        im=Image.new('RGB',(1300,760),'white');draw=ImageDraw.Draw(im)
        panel(draw,(20,15,1275,735),{k:curve(structural,value(k)) for k in ['rule','classifier','cost_ranking']},
            'Fixed n=512: run count and imbalance',xlabel='Observed runs r (log2)')
        im.save(out/'05-structure.png')
    with (out/'curves.csv').open('w') as f:
        writer=csv.writer(f);writer.writerow(['figure','strategy','length','input_median_ratio','input_p10','input_p90'])
        for fig,cs in [('01-scale',curves),('04-oracle',oracle)]:
            for k,pts in cs.items():
                for point in pts:writer.writerow([fig,k,*point])
