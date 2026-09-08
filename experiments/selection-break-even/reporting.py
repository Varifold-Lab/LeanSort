"""Paired descriptive summaries. Never feeds test evidence into fitting."""
from collections import Counter
import math
import statistics
from common import *
from plots import figures

def distribution(v):
    a=sorted(v)
    def q(p):
        x=(len(a)-1)*p;i=int(x);return a[i]+(a[min(i+1,len(a)-1)]-a[i])*(x-i)
    return dict(n=len(a),mean=statistics.mean(a),median=statistics.median(a),geometric_mean=math.exp(statistics.mean(map(math.log,a))),
        p10=q(.1),p90=q(.9),maximum=max(a),minimum=min(a),wins=sum(x<1 for x in a),over10=sum(x>1.1 for x in a))

def summarize(rows,names=None):
    ok=[r for r in rows if r['status']=='ok']
    if not ok:return dict(statuses=dict(Counter(r['status'] for r in rows)),complete=0,policies={})
    baseline=sum(r['policies']['fixed']['median_ns'] for r in ok);out={}
    for name in names or ok[0]['policies']:
        out[name]=dict(e2e_ms=sum(r['policies'][name]['median_ns'] for r in ok)/1e6,
            ratio=sum(r['policies'][name]['median_ns'] for r in ok)/baseline,
            selected_kernel_ms=sum(r['policies'][name]['selected_only_median_ns'] for r in ok)/1e6,
            paired=distribution([r['policies'][name]['median_ns']/r['policies']['fixed']['median_ns'] for r in ok]),
            inference_diag_ms=sum(statistics.median(r['policies'][name]['decision_samples_ns']) for r in ok)/1e6,
            kernel_comparisons=sum(r['policies'][name]['kernel_comparisons'] for r in ok),
            feature_comparisons=sum(r['policies'][name]['feature_comparisons'] for r in ok),
            choices=dict(Counter(str(r['policies'][name]['chosen_id']) for r in ok)))
    return dict(statuses=dict(Counter(r['status'] for r in rows)),complete=len(ok),base_groups=len({r['group_id'] for r in ok}),
        oracle_ms=sum(min(r['costs_ns']) for r in ok)/1e6,fixed_kernel_ms=sum(r['costs_ns'][5] for r in ok)/1e6,policies=out)

def report(p,a,validation,confirmation,proto,frozen):
    main=[r for r in a if r['family'] in FAMILIES]
    byn={str(n):summarize([r for r in main if r['n']==n]) for n in proto['lengths']}
    byfamily={f:summarize([r for r in main if f in r['family_aliases']]) for f in FAMILIES}
    overview=summarize(main);b=summarize(confirmation);v=summarize(validation);crossings={}
    for name in ['rule','classifier','cost_ranking']:
        pts=[(n,byn[str(n)]['policies'][name]['ratio']) for n in proto['lengths'] if byn[str(n)]['complete']]
        crossings[name]=next((n for i,(n,ratio) in enumerate(pts) if ratio<1 and all(r<1 for _,r in pts[i:])),None)
    pair_b={}
    for budget in BUDGETS:
        for kind in ['classifier','cost_ranking']:
            name=budget+'-'+kind;rule=budget+'-rule'
            pair_b[name]=dict(aggregate_ratio=b['policies'][name]['e2e_ms']/b['policies'][rule]['e2e_ms'],
                paired=distribution([r['policies'][name]['median_ns']/r['policies'][rule]['median_ns'] for r in confirmation]))
    save(p/'analysis.json',dict(A=overview,A_by_length=byn,A_by_family=byfamily,B=b,B_validation=v,
        observed_suffix_crossings=crossings,B_model_vs_matched_rule=pair_b))
    paired=[]
    for stage,rows in [('A',a),('B',confirmation)]:
        for r in rows:
            if r['status']!='ok':paired.append(dict(stage=stage,input_id=r['input_id'],status=r['status'],ratios=None));continue
            for name,policy in r['policies'].items():
                ref='rule' if stage=='A' else policy.get('feature_kind','length')+'-rule'
                paired.append(dict(stage=stage,input_id=r['input_id'],group_id=r['group_id'],n=r['n'],family=r['family'],name=name,status='ok',
                    ratio_fixed=policy['median_ns']/r['policies']['fixed']['median_ns'],ratio_rule=policy['median_ns']/r['policies'][ref]['median_ns'],
                    chosen_id=policy['chosen_id'],e2e_ns=policy['median_ns'],kernel_ns=policy['selected_only_median_ns']))
    save_rows(p/'paired.jsonl',paired);figures(p,a)
    lines=['# 在线选择：尺度诊断与低预算特征对照','',
        '两阶段均结束；最终人工判读见同目录 interpretation.zh.md。以下统计从全部保存记录产生，非最优性或普遍阈值证明。','',
        '## 范围与纪律','',
        f'正式长度 {proto["lengths"]}；请求上限 {proto["request_seconds"]} 秒，采样 RSS {proto["rss_limit_mib"]} MiB，栈 8 MiB。A/B 预算 {proto["a_total_seconds"]}/{proto["b_total_seconds"]} 秒。由独立 pilot 的请求耗时／RSS 决定，未按相对收益筛数据。',
        f'未执行扩展：{proto["excluded_lengths"]}；A 状态 {dict(Counter(r["status"] for r in a))}。未返回成本均为 null，原始局部事件保留，不填零。',
        '同源派生输入整组划分；完全相同输入合并并保留别名，计时重复不当独立输入。图示输入间波动并非独立同分布置信区间，同组形态相关。',
        '控制输入的固定 r=4/16、平均段长约 8/32 使用段间严格下降且值域分离的有序块；固定 n=512 改变 r 和均衡／偏斜程度。另有随机、逆序、重复、有序、局部扰动。真实 runs 在 Lean 和独立扫描中核对，不向选择器提供边界。控制设计不能代表所有具有相同 r 的自然输入。',
        'A 不训练、不改阈值，使用上一轮原 Worker、原最终模型和规则。B 与 A、历史输入隔离；所有策略使用相同直接 List 内核、Nat 比较器、Lean --run 编译方式和输出消费。','',
        '## A：冻结策略的净成本随长度变化','',
        '每输入三轮中位数之和 / 固定 runs_count；小于 1 为本次更快。',
        '| n | 完成输入 | Hybrid-8 | 旧规则 | 分类树 | 成本树 |','|---:|---:|---:|---:|---:|---:|']
    for n,s in byn.items():
        cells=' | '.join(f'{s["policies"][k]["ratio"]:.4f}' for k in ['hybrid','rule','classifier','cost_ranking']) if s['complete'] else '— | — | — | —'
        lines.append(f'| {n} | {s["complete"]} | {cells} |')
    lines+=['',f'观测网格后缀交叉点 {crossings}：此格及更大已完成格点汇总比值均 <1，末端孤立格点也可能入选。**这不是稳定临界点**；缺失格点、输入形态和逐输入退化仍需分别解释。',
        '', '| 策略 | E2E ms | /固定 | 所选内核 ms | 推理诊断 ms | 配对中位数 / P90 |','|---|---:|---:|---:|---:|---|']
    for k,x in overview['policies'].items():lines.append(f'| {k} | {x["e2e_ms"]:.3f} | {x["ratio"]:.4f} | {x["selected_kernel_ms"]:.3f} | {x["inference_diag_ms"]:.3f} | {x["paired"]["median"]:.3f} / {x["paired"]["p90"]:.3f} |')
    lines += ['',f'候选免费 Oracle 内核 {overview["oracle_ms"]:.3f} ms；固定内核 {overview["fixed_kernel_ms"]:.3f} ms。Oracle 只在已冻结七候选中按实测时间选择，不计在线成本，不是可部署／全局最优算法。',
        '图的横轴为 log2 长度，线是逐输入配对比值中位数，带为输入间 P10–P90，而不是重复轮的区间；图与总时间比的权重不同。曲线 CSV 和每输入 paired.jsonl 同时保存。',
        '', '![冻结策略的尺度曲线](figures/01-scale.png)','', '![各形态的净收益和波动](figures/02-shapes.png)',
        '', '![内核收益与在线收益的差距](figures/03-kernel-online.png)','', '![Oracle 与模型选中内核](figures/04-oracle.png)',
        '', '## B：有界特征预算、真实重训与独立确认','',
        'length 只用长度；8/16 每探针只做一次相邻键 ≤，提供长度、探针数和下降率，其他槽为不可用零；legacy 是旧六特征／最多 80 次键比较。每预算中规则和模型得到相同向量。',
        'List.length 与到达分散探针仍需遍历；指针单调推进，不为每个探针独立从表头索引。固定比较预算不是 O(1) 时间。提取、算术、分配、推理、分派、排序及完整输出消费都在 E2E 内；没有缓存／复用 runs。',
        '每预算训练分类树和相对成本回归树，深度 2/4、叶下限 8，共 16 个模型；规则从预先规定的长度阈值 32/128、下降率阈值 125/250 中选，共 16 个规则。只用独立验证 E2E 选配置。',
        f'冻结于 {frozen["frozen_at"]}，随后生成确认集。验证选出的整体预算 {frozen["best_budget"]}；所有预算结果也报告，不按确认结果重选赢家。',
        '', '| 配置 | 确认 E2E ms | /固定 | /同预算规则 | 特征比较 | 内核比较 |','|---|---:|---:|---:|---:|---:|']
    for k,x in b['policies'].items():
        ratio=f'{pair_b[k]["aggregate_ratio"]:.4f}' if k in pair_b else '—'
        lines.append(f'| {k} | {x["e2e_ms"]:.3f} | {x["ratio"]:.4f} | {ratio} | {x["feature_comparisons"]:,} | {x["kernel_comparisons"]:,} |')
    lines+=['','各预算是新特征＋相同新数据重训的整体对照，不把全部变化仅归因于比较次数。旧冻结树另外用原 legacy 特征运行；树参数不变，只适配特征版本标识。',
        '独立特征／推理／内核重放不能相加冒充 E2E；两次重放之差也不是单一组件的精确因果分解。','',
        '## 验证与可信边界','',
        '已形式化：任意候选选择与非法回退的有序性／排列保持；内核原比较成本界；新特征 Id/TimeM/Program 对应，低预算每探针恰一次键比较、总计 ≤0/8/16/80，特征＋所选内核的操作语义和组合界。',
        '仅检查／实测：Python/Lean 特征和导出预测、每次输出、独立比较计数及适用上界、数据分组／哈希、冻结文件、生成 C 的计时／消费位置、性能曲线。旧测试及新测试、模块重编译、公理日志保存。',
        '未知：普遍收益临界点、最快选择保证、机器时间／空间定理、编译器正确性。元数据、List 遍历和算术不是键比较成本，虽已实际计时。','',
        '## 复现','', '```sh\npython3 experiments/selection-break-even/run.py --smoke\npython3 experiments/selection-break-even/run.py\n```',
        '每次新建结果目录。原始输入／真实 runs／事件／请求／状态／模型／冻结配置／配对数据／图表／CSV／验证日志保留；阶段记录 decisions.zh.log，恢复检查点 checkpoint.json，失败 failure.json。',
        f'既有 {preserved()} 个文件哈希未变；分支 experiment/selection-break-even，未 commit、未 push。','']
    (p/'findings.zh.md').write_text('\n'.join(lines))
