"""Descriptive paired analysis. No independence or significance claims."""
import csv
import json
import statistics


def write_csv(path,rows):
    with path.open('w',newline='') as f:
        w=csv.DictWriter(f,fieldnames=list(rows[0])); w.writeheader(); w.writerows(rows)


def report(directory,rows,selected,threshold,phases):
    test=[r for r in rows if r['stage']=='test']
    write_csv(directory/'evaluation.csv',rows)
    grouped=[]
    for shape in ['ALL']+sorted({r['shape'] for r in test}):
        for name in selected:
            rs=[r for r in test if r['strategy']==name and (shape=='ALL' or r['shape']==shape)]
            grouped.append(dict(shape=shape,strategy=name,inputs=len(rs),
                comparisons=sum(r['comparisons'] for r in rs),checks=sum(r['check_comparisons'] for r in rs),
                sum_input_median_ns=sum(r['median_ns'] for r in rs)))
    write_csv(directory/'by-shape.csv',grouped)
    paired=[]
    keys={(r['case_id'],r['strategy']):r for r in test}
    for adaptive in ('runs_count','runs_length'):
        for baseline in selected:
            if baseline==adaptive: continue
            rs=[r for r in test if r['strategy']==adaptive]
            bs=[keys[r['case_id'],baseline] for r in rs]
            paired.append(dict(adaptive=adaptive,baseline=baseline,inputs=len(rs),
                fewer_comparisons=sum(a['comparisons']<b['comparisons'] for a,b in zip(rs,bs)),
                more_comparisons=sum(a['comparisons']>b['comparisons'] for a,b in zip(rs,bs)),
                lower_median_ns=sum(a['median_ns']<b['median_ns'] for a,b in zip(rs,bs)),
                fewer_comparisons_but_slower=sum(a['comparisons']<b['comparisons'] and a['median_ns']>b['median_ns'] for a,b in zip(rs,bs))))
    write_csv(directory/'paired.csv',paired)
    counts=[r['run_count'] for r in test if r['strategy']=='runs_count']
    summary=dict(calibrated_threshold=threshold,test_inputs=len(counts),test_strategies=len(selected),
                 run_count_min=min(counts),run_count_max=max(counts),aggregates=[r for r in grouped if r['shape']=='ALL'],
                 phases_ns=phases,paired=paired)
    (directory/'summary.json').write_text(json.dumps(summary,indent=2)+'\n')
    lines=['# 动态 runs 实验结论','',
        '## 已形式化证明','',
        '- 不提供任何边界，扫描产生有序、非空的连续 runs，其拼接等于输入；空输入产生零个 runs。',
        '- 实际 run 数等于严格下降的相邻对数加一（空输入单独处理）；扫描精确使用 max(0,n−1) 次键值比较。',
        '- 两个建树器都保持全部 run 叶子的顺序；执行结果有序且保持排列。生成过程本身进入通用正确性定理。',
        '- 按 run 数平衡时，总比较数 ≤ max(0,n−1)+n*Nat.clog(2,r)，包含识别开销；r 是实际发现值。',
        '- 已证明 O(n(1+log(max(1,r))))、全输入 O(n log n)，以及全有序输入精确 max(0,n−1) 次比较。',
        '- 长度策略有扫描＋实际合并树 budget 的证书；两种策略均有操作语义和比较计数的对应定理。',
        '- 已证明一个区别策略的反例：run 长度 1/1/16 时，树 budget 为 35/20；输入 [50,30]++range(16) 的总比较数为 50/34。','',
        '## 仅实测观察','',
        f'固定 Hybrid 阈值由独立校准集选为 {threshold}，在生成最终测试数据前冻结。测试 {len(counts)} 个输入、{len(selected)} 项策略；重复计时不是独立输入样本。',
        f'实际发现的 run 数范围为 {min(counts)}–{max(counts)}，不是预设 2/3/4 段。', '',
        '| 策略 | 总比较数 | 识别/检查比较数 | 各输入中位数之和(ms) |','|---|---:|---:|---:|']
    for r in summary['aggregates']:
        lines.append(f"| {r['strategy']} | {r['comparisons']} | {r['checks']} | {r['sum_input_median_ns']/1e6:.3f} |")
    lines += ['', '形态分组的相同输入比较（左为 runs_count，右为指定对照；时间为每输入中位数之和）：','',
              '| 形态 | 对照 | 总比较数（左/右） | 时间ms（左/右） |','|---|---|---:|---:|']
    for shape in ['random','sorted','reverse','unequal_runs','random_boundaries','short_runs','long_runs','perturbed','skewed_runs']:
        a=next(r for r in grouped if r['shape']==shape and r['strategy']=='runs_count')
        for baseline in ['merge','runs_length','fixed_four']:
            b=next(r for r in grouped if r['shape']==shape and r['strategy']==baseline)
            lines.append(f"| {shape} | {baseline} | {a['comparisons']} / {b['comparisons']} | {a['sum_input_median_ns']/1e6:.3f} / {b['sum_input_median_ns']/1e6:.3f} |")
    lines += ['', '## 验收问题与解释','',
        '1. **无需分段答案能否得到正确方案？** 能。调用者只给 List；检测、建树、合并均在执行链内，正确性对任意有限列表成立。',
        '2. **哪些保证已证明？** 上述有限上界、结构敏感渐近界、全输入界和有序输入精确界。没有以测试、拟合或固定深度假设代替 r。',
        '3. **哪里好或差？** 见逐形态表和 paired.csv；所有预设形态与失败/变慢样本都保留，不只展示获胜输入。',
        '4. **少比较是否更快？** 不保证。paired.csv 单列 fewer_comparisons_but_slower，区分实际计数改善与当前解释器耗时。',
        '5. **退化从何而来？** 逆序数据仅识别非递减 runs，因此 r=n，识别是额外 n−1 次比较；未实现下降 run 反转。极不均衡长度时，按 run 数平衡可能让大 run 过深，长度策略的树 budget 可揭示合并顺序差异。计数无法解释的耗时差异还可能来自比较程序/绑定表示、List 遍历和分配；分项诊断只作线索，没有作因果或机器复杂度证明。','',
        '## 对照与可信边界','',
        'runs_length 移植 Munro–Wild Peeksort Algorithm 1 的整数中点切分规则，使用提前发现的非递减 runs 和同一个 Lean merge。它不是原版懒扫描、下降 run 处理、minrun、galloping 或优化数组实现。独立的距离公式与原论文规则在正整数长度组合上核对；本仓库尚未证明其熵界或与原代码等价，不能声称超过原版 Peeksort/Powersort。',
        '[原论文：§3.1、Algorithm 1](https://www.wild-inter.net/publications/munro-wild-2018.pdf)。',
        '全部主要对照使用 List Nat、同一 ≤ 比较单位和 lean --run 比较程序后端。无跨语言库时间混入优势结论。',
        '端到端计时包含输入读取、run 识别、建树、执行和完整输出消费。数据生成、JSON 通信、校准选择、证明生成/检查、结果核对及诊断重放在计时外。',
        '扫描、建树和 merge-only 诊断各自重放；建树诊断还包含 budget/weight 的强制消费，不能视作精确可加拆分，也不再次加到 E2E。',
        'List 遍历、长度/边界算术、树构造、分配、解释器及计数器成本未形式化；它们在实测时间内。无完整机器时间或空间复杂度证明。',
        '这些是合成形态下的描述性配对测量，未声称样本独立、统计显著、真实生产分布代表性、全局最优或普遍速度优势。','',
        '## 尚未完成','',
        'Peeksort 风格策略的熵界、最优性/成本支配、下降 run 处理，以及从比较程序到高效直接执行器的精化。此前决策树负结果与固定切分实验原样保留。','',
        '## 复现与证据','',
        '从根目录执行 `python3 experiments/dynamic-runs/run.py`；先用 `--smoke --rounds 3` 检查流程。',
        '`protocol.json`/`frozen.json` 保存预注册参数和校准选择；`dataset-*.jsonl` 与 `observations-*.jsonl` 保留输入、发现的 runs、实际树和每轮时间；`fresh-proof-*.log`/`Acceptance.lean`/`axioms.log` 保存本次源码的重新检查。']
    (directory/'conclusion.zh.md').write_text('\n'.join(lines)+'\n')
    return summary
