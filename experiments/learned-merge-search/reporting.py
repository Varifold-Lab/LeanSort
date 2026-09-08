"""Descriptive paired summaries; never turn node repeats into new inputs."""
from collections import defaultdict
import json
import statistics
from pathlib import Path

def quantile(xs,p):
    s=sorted(xs)
    if not s:return None
    z=p*(len(s)-1);i=int(z);return s[i]+(s[min(i+1,len(s)-1)]-s[i])*(z-i)

def dist(xs):
    return dict(n=len(xs),mean=statistics.mean(xs) if xs else None,median=statistics.median(xs) if xs else None,
        p10=quantile(xs,.1),p90=quantile(xs,.9),maximum=max(xs) if xs else None)

def summarize(entries,protocol):
    out=dict(instances=len(entries),methods={},nodes={},wall={},families={},dp_memory=dist([e['reference']['peak_python_bytes'] for e in entries]))
    for method in ['count','length','dp']:
        vals=[e['reference'] if method=='dp' else e['baselines'][method] for e in entries]
        ratios=[v['budget']/e['reference']['budget'] if e['reference']['budget'] else 1 for e,v in zip(entries,vals)]
        out['methods'][method]=dict(ratios=dist(ratios),time_ns=dist([v['median_ns'] for v in vals]),
            exact=sum(v['budget']==e['reference']['budget'] for e,v in zip(entries,vals)),budget_sum=sum(v['budget'] for v in vals))
    for method in ['fixed','heuristic','learned']:
        for n in protocol['node_budgets']:
            ratios=[];times=[];exact=0;features=[];infer=[];nodes=[];firstopt=[];target=[];matched=[]
            for e in entries:
                rows=[r for r in e['searches'] if r['status']=='ok' and r['method']==method and r['mode']=='nodes']
                if not rows:continue
                q=[r['quality']['at_nodes'][str(n)] for r in rows]
                ratios.append(statistics.median(x['ratio'] for x in q));times.append(statistics.median(x['elapsed_ns'] for x in q))
                exact+=all(x['budget']==e['reference']['budget'] for x in q)
                features.append(statistics.median(r['feature_ns'] for r in rows));infer.append(statistics.median(r['inference_ns'] for r in rows))
                nodes.append(statistics.median(r['nodes'] for r in rows))
                # Goal reach time refers to the full node-budget request, not the smaller checkpoint.
                fo=[r['quality']['first_optimal_ns'] for r in rows if r['quality']['first_optimal_ns'] is not None]
                ft=[r['quality']['first_target_ns'] for r in rows if r['quality']['first_target_ns'] is not None]
                if len(fo)==len(rows):firstopt.append(statistics.median(fo))
                if len(ft)==len(rows):target.append(statistics.median(ft))
                other=[r for r in e['searches'] if r['status']=='ok' and r['method']=='heuristic' and r['mode']=='nodes']
                if other:
                    b=statistics.median(r['quality']['at_nodes'][str(n)]['budget'] for r in rows)
                    h=statistics.median(r['quality']['at_nodes'][str(n)]['budget'] for r in other)
                    matched.append(b/h if h else 1)
            out['nodes'][f'{method}-{n}']=dict(ratios=dist(ratios),time_ns=dist(times),exact_inputs=exact,
                versus_heuristic=dist(matched),feature_ns_full_request=dist(features),inference_ns_full_request=dist(infer),
                first_optimal_ns_full_request=dist(firstopt),first_target_ns_full_request=dist(target),
                unreached_optimal_inputs=len(ratios)-len(firstopt),unreached_target_inputs=len(ratios)-len(target))
        for wall in protocol['wall_budgets_ns']:
            ratios=[];times=[];over=[];missing=0
            for e in entries:
                rows=[r for r in e['searches'] if r['status']=='ok' and r['method']==method and r['mode']=='wall' and r['wall_limit_ns']==wall]
                vals=[r['quality']['timely_ratio'] for r in rows if r['quality']['timely_ratio'] is not None]
                if not vals:missing+=1;continue
                ratios.append(statistics.median(vals));times.append(statistics.median(r['elapsed_ns'] for r in rows));over.extend(r['quality']['overrun_ns'] for r in rows)
            out['wall'][f'{method}-{wall}']=dict(ratios=dist(ratios),request_time_ns=dist(times),no_timely_result_inputs=missing,step_overrun_ns=dist(over))
    for fam in sorted({e['case']['family'] for e in entries}):
        group=[e for e in entries if e['case']['family']==fam];d={}
        for method in ['fixed','heuristic','learned']:
            rr=[]
            for e in group:
                q=[r['budget']/e['reference']['budget'] if e['reference']['budget'] else 1 for r in e['searches'] if r['status']=='ok' and r['mode']=='nodes' and r['method']==method]
                if q:rr.append(statistics.median(q))
            d[method]=dist(rr)
        out['families'][fam]=d
    return out

def fmt(x,scale=1):return '—' if x is None else f'{x/scale:.4f}'

def report(out,entries,certs,frozen,labels):
    protocol=frozen['protocol'];groups={}
    for split in ['confirmation','extrapolation','structural_diagnostic']:
        es=[e for e in entries if e['case']['split']==split]
        groups[split]=summarize(es,protocol)
    (out/'analysis.json').write_text(json.dumps(groups,indent=2,sort_keys=True)+'\n')
    pairs=[]
    for e in entries:
        for r in e['searches']:
            if r['status']=='ok':
                pairs.append(dict(input_id=e['case']['input_id'],split=e['case']['split'],family=e['case']['family'],
                    r=e['case']['r'],n=e['case']['n'],method=r['method'],mode=r['mode'],repeat=r['repeat'],
                    wall_limit_ns=r['wall_limit_ns'],U=r['budget'],L=0,reference=e['reference']['budget'],
                    quality=r['quality'],elapsed_ns=r['elapsed_ns'],feature_ns=r['feature_ns'],inference_ns=r['inference_ns']))
    with (out/'paired.jsonl').open('w') as f:
        for p in pairs:f.write(json.dumps(p,separators=(',',':'))+'\n')
    text=['# 学习引导的合并树搜索与成本认证','',
      '冻结实验结束。本文件由全部保存记录生成；人工判读另见 interpretation.zh.md。负结果不触发继续调参。','',
      '## 对象和可信边界','',
      '`B(T)` 与现有 `MergeTree.budget` 一致，且 `realize_budget_lengths` 已证明两种表示预算相等。目标只限保持叶序、相邻归并的满二叉树；不是所有排序算法的最优解，也不是精确键比较或机器时间。','',
      '三种搜索共用初始解（count 与旧 length 策略的较小预算）、状态、全部切点、左侧优先待展开区间、去重、补全、节点预算和停止规则。模型只改变切点优先级；没有剪枝或 beam。搜索内只给出已证明的全局下界 0。队列耗尽不被当作 Lean 最优性证书。','',
      '精确 DP 独立测量（含重建）；确认搜索先运行，再计算 DP，DP 不进入搜索特征或优先级。完整 Bellman 表是事后独立下界证书，结合可行树预算相等时由通用 Lean 定理推出该空间内最优。所有输出及中间改善树经过定理支持的 Lean 可执行检查器；每个 r 另有具体 kernel-normalized 证书，完整清单在 certificates.jsonl。其余实例不冒称逐个已有 kernel-normalized 证明项。','',
      f'模型是深度 {frozen["selected_depth"]} 的 CART 续接 regret 回归树；标签 {labels["rows"]} 条，标签构造 {labels["label_generation_ns"]/1e6:.3f} ms。冻结时间 {frozen["frozen_at"]}，随后才生成确认／外推集。','',
      '## 预算与计时','',
      '搜索计时含初始解、补全、去重、全部特征／推理、排序候选优先级、记录和结果合法性检查；不含训练、DP 参照、Lean 证书、数据生成或排序执行。特征／推理诊断在实际搜索内累计，计时器本身有开销。排序样本使用原 Lean 直接执行器；只有内核时间，不作在线加速结论。','',
      '墙钟预算在展开边界停止，可能超出一个展开步骤；同墙钟质量严格只取截止时间前可用的改善事件。实际超出时长、未及时返回和未执行均保留。事后达到目标的时间从轨迹读取；OPT／1.01 OPT 仅在评价阶段使用，不影响搜索停止。','',
      'DP 内存为独立 tracemalloc 重放的峰值 Python 分配，跟踪重放时间不混入无跟踪 DP 时间；不是形式化空间成本，也不等于整个进程 RSS。','',
      '## 汇总','',
      '每个输入先汇总重复轮，再给跨输入均值／中位数／P90。重复轮不是独立样本；同源扰动也相关，不作显著性声明。']
    for split,a in groups.items():
        text+=['',f'### {split}：{a["instances"]} 个输入','',
          '| 基线 | 平均预算/OPT | 中位预算/OPT | 精确最优输入 | 规划中位 ms |',
          '|---|---:|---:|---:|---:|']
        for m,v in a['methods'].items():text.append(f'| {m} | {fmt(v["ratios"]["mean"])} | {fmt(v["ratios"]["median"])} | {v["exact"]} | {fmt(v["time_ns"]["median"],1e6)} |')
        text+=['','| 搜索／展开预算 | 平均预算/OPT | 中位预算/OPT | P90 | 最优输入 | 搜索中位 ms |','|---|---:|---:|---:|---:|---:|']
        for m,v in a['nodes'].items():text.append(f'| {m} | {fmt(v["ratios"]["mean"])} | {fmt(v["ratios"]["median"])} | {fmt(v["ratios"]["p90"])} | {v["exact_inputs"]} | {fmt(v["time_ns"]["median"],1e6)} |')
        text+=['','| 搜索／墙钟 ns | 平均及时预算/OPT | P90 | 无及时结果输入 | 实际请求中位 ms |','|---|---:|---:|---:|---:|']
        for m,v in a['wall'].items():text.append(f'| {m} | {fmt(v["ratios"]["mean"])} | {fmt(v["ratios"]["p90"])} | {v["no_timely_result_inputs"]} | {fmt(v["request_time_ns"]["median"],1e6)} |')
        text+=['',f'DP 峰值 Python 分配（字节）：{a["dp_memory"]}。']
    text+=['','## 验收与复现','',
      '新旧测试、lake build、直接执行精化链及新模块重新编译、公理审计、训练/导出预测、哈希/缩放/反转分组隔离、独立 postfix 穷举、坏证书/坏树回退与执行输出核对均须通过 acceptance.json 才算验收。','',
      '等长向量只放在保留的结构诊断，不把缩放克隆叫作未见数据。独立生成的偶然近似结构仍可能存在；所有显式扰动留在原组。真实列表扫描得到的长度与原列表一起保存，生成器标签不进入特征。','',
      '```sh','python3 experiments/learned-merge-search/run.py --smoke','python3 experiments/learned-merge-search/run.py','```','',
      '每次新建结果目录；不提交或推送，不修改历史源码、模型或结果。源码/模型哈希、每个输入与每轮搜索轨迹、完整 DP 表、Python 内存重放、Lean 请求响应和具体证明均保留。']
    (out/'findings.zh.md').write_text('\n'.join(text)+'\n')
