# 动态 runs 实验结论

## 已形式化证明

- 不提供任何边界，扫描产生有序、非空的连续 runs，其拼接等于输入；空输入产生零个 runs。
- 实际 run 数等于严格下降的相邻对数加一（空输入单独处理）；扫描精确使用 max(0,n−1) 次键值比较。
- 两个建树器都保持全部 run 叶子的顺序；执行结果有序且保持排列。生成过程本身进入通用正确性定理。
- 按 run 数平衡时，总比较数 ≤ max(0,n−1)+n*Nat.clog(2,r)，包含识别开销；r 是实际发现值。
- 已证明 O(n(1+log(max(1,r))))、全输入 O(n log n)，以及全有序输入精确 max(0,n−1) 次比较。
- 长度策略有扫描＋实际合并树 budget 的证书；两种策略均有操作语义和比较计数的对应定理。
- 已证明一个区别策略的反例：run 长度 1/1/16 时，树 budget 为 35/20；输入 [50,30]++range(16) 的总比较数为 50/34。

## 仅实测观察

固定 Hybrid 阈值由独立校准集选为 8，在生成最终测试数据前冻结。测试 98 个输入、7 项策略；重复计时不是独立输入样本。
实际发现的 run 数范围为 0–257，不是预设 2/3/4 段。

| 策略 | 总比较数 | 识别/检查比较数 | 各输入中位数之和(ms) |
|---|---:|---:|---:|
| merge | 58166 | 0 | 377.387 |
| hybrid_8 | 58471 | 0 | 375.933 |
| fixed_two | 57030 | 3513 | 366.391 |
| fixed_three | 55483 | 4142 | 374.866 |
| fixed_four | 54730 | 4522 | 362.416 |
| runs_count | 49887 | 11566 | 604.529 |
| runs_length | 47797 | 11566 | 579.710 |

形态分组的相同输入比较（左为 runs_count，右为指定对照；时间为每输入中位数之和）：

| 形态 | 对照 | 总比较数（左/右） | 时间ms（左/右） |
|---|---|---:|---:|
| random | merge | 7756 / 7152 | 72.140 / 49.452 |
| random | runs_length | 7756 / 7702 | 72.140 / 73.848 |
| random | fixed_four | 7756 / 7215 | 72.140 / 49.658 |
| sorted | merge | 1152 / 4236 | 24.026 / 16.175 |
| sorted | runs_length | 1152 / 1152 | 24.026 / 23.933 |
| sorted | fixed_four | 1152 / 2277 | 24.026 / 9.982 |
| reverse | merge | 5535 / 4383 | 40.375 / 16.124 |
| reverse | runs_length | 5535 / 5388 | 40.375 / 42.181 |
| reverse | fixed_four | 5535 / 4419 | 40.375 / 16.317 |
| unequal_runs | merge | 3097 / 5350 | 56.026 / 37.243 |
| unequal_runs | runs_length | 3097 / 3004 | 56.026 / 55.211 |
| unequal_runs | fixed_four | 3097 / 4708 | 56.026 / 34.475 |
| random_boundaries | merge | 5555 / 6476 | 69.146 / 48.387 |
| random_boundaries | runs_length | 5555 / 5281 | 69.146 / 67.275 |
| random_boundaries | fixed_four | 5555 / 6649 | 69.146 / 48.035 |
| short_runs | merge | 7379 / 7122 | 72.451 / 50.187 |
| short_runs | runs_length | 7379 / 7284 | 72.451 / 73.183 |
| short_runs | fixed_four | 7379 / 7211 | 72.451 / 49.983 |
| long_runs | merge | 3051 / 5532 | 58.032 / 41.667 |
| long_runs | runs_length | 3051 / 3032 | 58.032 / 57.427 |
| long_runs | fixed_four | 3051 / 4886 | 58.032 / 39.117 |
| perturbed | merge | 4377 / 5721 | 60.913 / 40.868 |
| perturbed | runs_length | 4377 / 4381 | 60.913 / 60.437 |
| perturbed | fixed_four | 4377 / 5844 | 60.913 / 40.541 |
| skewed_runs | merge | 4709 / 5308 | 85.737 / 34.452 |
| skewed_runs | runs_length | 4709 / 3339 | 85.737 / 59.818 |
| skewed_runs | fixed_four | 4709 / 4550 | 85.737 / 31.432 |

## 验收问题与解释

1. **无需分段答案能否得到正确方案？** 能。调用者只给 List；检测、建树、合并均在执行链内，正确性对任意有限列表成立。
2. **哪些保证已证明？** 上述有限上界、结构敏感渐近界、全输入界和有序输入精确界。没有以测试、拟合或固定深度假设代替 r。
3. **哪里好或差？** 见逐形态表和 paired.csv；所有预设形态与失败/变慢样本都保留，不只展示获胜输入。
4. **少比较是否更快？** 不保证。paired.csv 单列 fewer_comparisons_but_slower，区分实际计数改善与当前解释器耗时。
5. **退化从何而来？** 逆序数据仅识别非递减 runs，因此 r=n，识别是额外 n−1 次比较；未实现下降 run 反转。极不均衡长度时，按 run 数平衡可能让大 run 过深，长度策略的树 budget 可揭示合并顺序差异。计数无法解释的耗时差异还可能来自比较程序/绑定表示、List 遍历和分配；分项诊断只作线索，没有作因果或机器复杂度证明。

## 对照与可信边界

runs_length 移植 Munro–Wild Peeksort Algorithm 1 的整数中点切分规则，使用提前发现的非递减 runs 和同一个 Lean merge。它不是原版懒扫描、下降 run 处理、minrun、galloping 或优化数组实现。独立的距离公式与原论文规则在正整数长度组合上核对；本仓库尚未证明其熵界或与原代码等价，不能声称超过原版 Peeksort/Powersort。
[原论文：§3.1、Algorithm 1](https://www.wild-inter.net/publications/munro-wild-2018.pdf)。
全部主要对照使用 List Nat、同一 ≤ 比较单位和 lean --run 比较程序后端。无跨语言库时间混入优势结论。
端到端计时包含输入读取、run 识别、建树、执行和完整输出消费。数据生成、JSON 通信、校准选择、证明生成/检查、结果核对及诊断重放在计时外。
扫描、建树和 merge-only 诊断各自重放；建树诊断还包含 budget/weight 的强制消费，不能视作精确可加拆分，也不再次加到 E2E。
List 遍历、长度/边界算术、树构造、分配、解释器及计数器成本未形式化；它们在实测时间内。无完整机器时间或空间复杂度证明。
这些是合成形态下的描述性配对测量，未声称样本独立、统计显著、真实生产分布代表性、全局最优或普遍速度优势。

## 尚未完成

Peeksort 风格策略的熵界、最优性/成本支配、下降 run 处理，以及从比较程序到高效直接执行器的精化。此前决策树负结果与固定切分实验原样保留。

## 复现与证据

从根目录执行 `python3 experiments/dynamic-runs/run.py`；先用 `--smoke --rounds 3` 检查流程。
`protocol.json`/`frozen.json` 保存预注册参数和校准选择；`dataset-*.jsonl` 与 `observations-*.jsonl` 保留输入、发现的 runs、实际树和每轮时间；`fresh-proof-*.log`/`Acceptance.lean`/`axioms.log` 保存本次源码的重新检查。
