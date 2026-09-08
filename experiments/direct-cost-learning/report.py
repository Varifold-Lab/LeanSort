"""Paired distributions and learning curves. No test-driven fitting."""
from collections import Counter
import json
import math
import statistics


def quantile(values,p):
    a=sorted(values);at=(len(a)-1)*p;i=int(at);j=min(i+1,len(a)-1)
    return a[i]+(a[j]-a[i])*(at-i)


def distribution(values):
    return dict(n=len(values),mean=statistics.mean(values),geometric_mean=math.exp(statistics.mean(map(math.log,values))),
        minimum=min(values),p10=quantile(values,.1),p25=quantile(values,.25),median=statistics.median(values),
        p75=quantile(values,.75),p90=quantile(values,.9),p95=quantile(values,.95),maximum=max(values),
        wins=sum(x<1 for x in values),ties=sum(x==1 for x in values),losses=sum(x>1 for x in values),
        regressions_over_10_percent=sum(x>1.1 for x in values),regressions_over_50_percent=sum(x>1.5 for x in values))


def opportunity(rows,fixed):
    totals=[sum(r['costs_ns'][i] for r in rows) for i in range(7)]
    oracle=sum(min(r['costs_ns']) for r in rows)
    return dict(inputs=len(rows),fixed_id=fixed,fixed_kernel_sum_ns=totals[fixed],oracle_kernel_sum_ns=oracle,
        oracle_over_fixed=oracle/totals[fixed],candidate_totals_ns=totals,
        winner_counts=dict(Counter(str(min(range(7),key=r['costs_ns'].__getitem__)) for r in rows)),
        by_family={f:dict(fixed_ns=sum(r['costs_ns'][fixed] for r in rows if r['family']==f),
            oracle_ns=sum(min(r['costs_ns']) for r in rows if r['family']==f),n=sum(r['family']==f for r in rows))
            for f in sorted({r['family'] for r in rows})},
        note='free hindsight oracle restricted to frozen candidates; excludes feature/inference and is not a deployable or globally optimal algorithm')


def summarize(rows,baseline='best_fixed'):
    assert rows and all(r['status']=='ok' for r in rows)
    names=list(rows[0]['policies'])
    fixed_sum=sum(r['policies'][baseline]['median_ns'] for r in rows)
    out={}
    for name in names:
        policies=[r['policies'][name] for r in rows]
        total=sum(p['median_ns'] for p in policies)
        ratios=[r['policies'][name]['median_ns']/r['policies'][baseline]['median_ns'] for r in rows]
        regret=[r['policies'][name]['selected_only_median_ns']/min(r['costs_ns']) for r in rows]
        selected=sum(p['selected_only_median_ns'] for p in policies)
        out[name]=dict(e2e_sum_ms=total/1e6,aggregate_ratio=total/fixed_sum,paired_ratios=distribution(ratios),
            selected_only_sum_ms=selected/1e6,selection_regret=distribution(regret),
            online_gap_vs_selected_ms=(total-selected)/1e6,
            decision_diagnostic_sum_ms=sum(statistics.median(p['decision_samples_ns']) for p in policies)/1e6,
            key_comparisons=sum(p['total_key_comparisons'] for p in policies),
            kernel_comparisons=sum(p['kernel_comparisons'] for p in policies),
            feature_comparisons=sum(p['feature_comparisons'] for p in policies),
            chosen_counts=dict(Counter(str(p['chosen_id']) for p in policies)),
            by_family={f:dict(n=sum(r['family']==f for r in rows),
                e2e_ms=sum(r['policies'][name]['median_ns'] for r in rows if r['family']==f)/1e6,
                ratio=sum(r['policies'][name]['median_ns'] for r in rows if r['family']==f)/
                    sum(r['policies'][baseline]['median_ns'] for r in rows if r['family']==f)) for f in sorted({r['family'] for r in rows})})
    oracle=sum(min(r['costs_ns']) for r in rows)
    return dict(inputs=len(rows),policies=out,oracle_sum_ms=oracle/1e6,oracle_over_fixed=oracle/fixed_sum,
        feature_diagnostic_sum_ms=sum(statistics.median(r['feature_samples_ns']) for r in rows)/1e6,
        decomposition_note='selected-only, feature and decision are separate diagnostic replays; never summed into E2E; online gap is a paired aggregate difference, not an isolated component timer')


def write_report(directory,learning_curve,final,model_sizes):
    analyses={stage:summarize(rows) for stage,rows in final.items()}
    (directory/'analysis.json').write_text(json.dumps(analyses,indent=2,sort_keys=True)+'\n')
    lines=['# 学习选择：自动生成的完整统计','',
        '时间单位 ms，为各独立输入五轮计时中位数之和（smoke 为三轮）。逐输入比值分布另列，重复不当独立输入。',
        '所有可部署策略都计入各自实际使用的特征、推理、合法分派、同一直接排序内核和完整输出消费。','',
        '## 固定验证集学习曲线','',
        '| 训练输入数 | 模型 | 验证 E2E / 最佳固定 | 选中内核 / Oracle（均值） | 深度/叶下限 |',
        '|---:|---|---:|---:|---|']
    for row in learning_curve:
        lines.append(f'| {row["training_inputs"]} | {row["kind"]} | {row["validation_ratio"]:.4f} | {row["quality"]["mean_oracle_ratio"]:.4f} | {row["depth"]}/{row["min_leaf"]} |')
    for stage,a in analyses.items():
        lines+=['','## '+stage,'',
            f'输入数：{a["inputs"]}。事后免费候选 Oracle：{a["oracle_sum_ms"]:.3f} ms；不是可部署方法。',
            '', '| 策略 | E2E ms | /固定 | 选中内核 ms | 键比较（特征＋内核） |',
            '|---|---:|---:|---:|---:|']
        for name,p in a['policies'].items():
            lines.append(f'| {name} | {p["e2e_sum_ms"]:.3f} | {p["aggregate_ratio"]:.4f} | {p["selected_only_sum_ms"]:.3f} | {p["key_comparisons"]} |')
        lines+=['','### 逐输入 E2E / 同输入固定基线','',
            '| 策略 | 均值 | 几何均值 | P10 | 中位数 | P90 | P95 | 最大 | 胜/负 | >10%退化 |',
            '|---|---:|---:|---:|---:|---:|---:|---:|---|---:|']
        for name,p in a['policies'].items():
            q=p['paired_ratios']
            lines.append('| '+name+' | '+' | '.join(f'{q[k]:.3f}' for k in ['mean','geometric_mean','p10','median','p90','p95','maximum'])+
                f' | {q["wins"]}/{q["losses"]} | {q["regressions_over_10_percent"]} |')
        names=list(a['policies'])
        lines+=['','### 形态分组的 E2E / 固定基线','',
            '| 形态 | '+' | '.join(names)+' |','|---|'+'---:|'*len(names)]
        for family in sorted(next(iter(a['policies'].values()))['by_family']):
            lines.append('| '+family+' | '+' | '.join(f'{a["policies"][name]["by_family"][family]["ratio"]:.3f}' for name in names)+' |')
    lines+=['','## 模型开销与边界','',
        '最终模型大小、深度与训练时间：`'+json.dumps(model_sizes,ensure_ascii=False)+'`。',
        '完整推理分项、每输入退化、全部候选、状态与原始重复均保留于 JSON/JSONL。',
        '诊断重放不相加冒充 E2E；实际键比较、已证明上界、墙钟标签相互分离。',
        '本实验是已有候选的性能学习与选择，不是新排序算法综合；正确性不蕴含选择最优。',
        '所有统计是本机有限输入实测，不宣称统计显著性、机器时间证明或跨硬件结论。','']
    (directory/'summary.zh.md').write_text('\n'.join(lines))
    return analyses
