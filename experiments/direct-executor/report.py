"""Fixed descriptive summaries: no post-test parameter selection or tuning."""
from collections import Counter,defaultdict
import json


def report(directory,rows,statuses):
    stages=sorted({r['stage'] for r in rows if r['stage']!='extension'})
    summary={}
    lines=['# 直接执行器：自动生成的描述统计','',
        '单位为每个独立输入的端到端时间中位数之和（ms）。重复计时不是独立样本；这不是显著性或全局最优证明。',
        '计时包含扫描、同一规划器、执行和完整输出 checksum；不含数据生成、证明、传输、核对和诊断重放。','']
    for stage in stages:
        group=[r for r in rows if r['stage']==stage]
        index={(r['case_id'],r['strategy'],r['mode']):r for r in group}
        algorithms=list(dict.fromkeys(r['strategy'] for r in group))
        total=defaultdict(float)
        for r in group: total[(r['strategy'],r['mode'])]+=r['median_ns']/1e6
        records={}
        for s in algorithms:
            modes={m:t for (a,m),t in total.items() if a==s}
            costs=sum(r['comparisons'] for r in group if r['strategy']==s and r['mode']=='counted')
            pairs=[r for r in group if r['strategy']==s and r['mode']=='plain']
            wins=sum(r['median_ns']<index[r['case_id'],s,'reference']['median_ns'] for r in pairs)
            records[s]=dict(times_ms=modes,comparisons=costs,plain_wins_vs_reference=wins,
                count=len(pairs),plain_over_reference=modes['plain']/modes['reference'],
                counted_over_reference=modes['counted']/modes['reference'],plain_over_counted=modes['plain']/modes['counted'])
        shapes={}
        for shape in sorted({r['shape'] for r in group}):
            selected=[r for r in group if r['shape']==shape]
            shapes[shape]={s:{m:sum(r['median_ns'] for r in selected if r['strategy']==s and r['mode']==m)/1e6
                for m in ['reference','counted','plain']} for s in algorithms}
        ablations={}
        for s in ['runs_count','runs_length']:
            m=records[s]['times_ms']
            ablations[s]=dict(staging_over_reference=m['staged_reference']/m['reference'],
                scan_only_over_staged_reference=m['scan_only']/m['staged_reference'],
                merge_only_over_staged_reference=m['merge_only']/m['staged_reference'],
                staged_direct_over_staged_reference=m['staged_direct']/m['staged_reference'],
                full_counted_over_staged_direct=m['counted']/m['staged_direct'])
        plain_pairs={}
        for a in ['runs_count','runs_length']:
            plain_pairs[a]={}
            for b in ['merge','hybrid_8','fixed_four']:
                pairs=[r for r in group if r['strategy']==a and r['mode']=='plain']
                plain_pairs[a][b]=dict(wins=sum(r['median_ns']<index[r['case_id'],b,'plain']['median_ns'] for r in pairs),
                    total=len(pairs),aggregate_ratio=records[a]['times_ms']['plain']/records[b]['times_ms']['plain'])
        summary[stage]=dict(algorithms=records,by_shape_ms=shapes,ablation_ratios=ablations,plain_algorithm_pairs=plain_pairs)
        lines += ['## '+stage,'','| 算法 | 键比较 | A 解释器 ms | B 直接计数 ms | C 直接无计数 ms | C/A |',
            '|---|---:|---:|---:|---:|---:|']
        for s,r in records.items():
            m=r['times_ms']
            lines.append(f'| {s} | {r["comparisons"]} | {m["reference"]:.3f} | {m["counted"]:.3f} | {m["plain"]:.3f} | {r["plain_over_reference"]:.3f} |')
        lines += ['','### 消融（仍是端到端时间，不把分项重放相加）','',
            '| 策略 | 双旧分阶段 | 只替换扫描 | 只替换合并 | 双直接分阶段 | 完整直接计数 |',
            '|---|---:|---:|---:|---:|---:|']
        for s in ['runs_count','runs_length']:
            m=records[s]['times_ms']
            lines.append('| '+s+' | '+' | '.join(f'{m[x]:.3f}' for x in
                ['staged_reference','scan_only','merge_only','staged_direct','counted'])+' |')
        lines+=['','### 形态：相同无计数后端 ms','',
            '| 形态 | Merge | Hybrid-8 | 固定四段 | run 数平衡 | 长度策略 |',
            '|---|---:|---:|---:|---:|---:|']
        for shape,ss in shapes.items():
            lines.append('| '+shape+' | '+' | '.join(f'{ss[s]["plain"]:.3f}' for s in algorithms)+' |')
        lines+=['']
    summary['extension_status_counts']=dict(Counter(s['status'] for s in statuses))
    summary['extension_matched']={}
    for n in sorted({s['n'] for s in statuses}):
        er=[r for r in rows if r['stage']=='extension' and r['n']==n]
        complete=[case for case in dict.fromkeys(r['case_id'] for r in er) if
                  sum(r['case_id']==case for r in er)==15]
        summary['extension_matched'][n]=dict(complete_input_ids=complete,
            times_ms={s:{m:sum(r['median_ns'] for r in er if r['case_id'] in complete and r['strategy']==s and r['mode']==m)/1e6
                for m in ['reference','counted','plain']} for s in ['merge','hybrid_8','fixed_four','runs_count','runs_length']})
    if statuses:
        lines+=['## 扩展实验','',
            '统一请求预算 5 秒、总预算 180 秒、worker 栈 8 MiB、采样 RSS 超过 3 GiB 时停止。',
            '请求预算含该请求的预热与多轮测量及传输/核对；不是单次排序的时间上界。',
            '失败记录不丢弃；仅在同一输入的 15 个主变体全部完成时作跨算法/模式汇总。','',
            '状态：`'+json.dumps(summary['extension_status_counts'],ensure_ascii=False)+'`','']
    lines+=['## 可信边界','',
        '- Lean 证明任意有限 List、合法 LinearOrder 下的符号比较程序精化、输出/计数相等和键比较成本界。',
        '- C 的输出在运行时不维护计数；其成本来自同一递归算法的符号插桩及已证明的解释对应，不是用输出相等猜测成本。',
        '- 比较单位仅为键上的 ≤；列表遍历、分配、算术、规划与一般 Monad 分派没有机器成本定理。',
        '- 直接版移除比较程序节点/解释遍历。泛型代码仍有 Monad 分派；Nat 的 plain C 特化核心未出现 TimeM、动态分派或闭包分配。C 是结构审计，不是本轮计时后端，仍不能据此单独识别各类机器开销。',
        '- 运行后端均为 lean --run。C 输出仅用于检查编译结构，没有验证 Lean 编译器，也没有混入原生后端成绩。',
        '- 旧 98 个输入只是已见配对诊断；独立确认集的种子、参数和源码先冻结，未依结果调参。','']
    (directory/'analysis.json').write_text(json.dumps(summary,indent=2,sort_keys=True)+'\n')
    (directory/'summary.zh.md').write_text('\n'.join(lines))
