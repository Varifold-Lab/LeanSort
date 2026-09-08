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

固定 Hybrid 阈值由独立校准集选为 4，在生成最终测试数据前冻结。测试 28 个输入、7 项策略；重复计时不是独立输入样本。
实际发现的 run 数范围为 0–47，不是预设 2/3/4 段。

| 策略 | 总比较数 | 识别/检查比较数 | 各输入中位数之和(ms) |
|---|---:|---:|---:|
| merge | 2437 | 0 | 5.023 |
| hybrid_4 | 2436 | 0 | 4.846 |
| fixed_two | 2535 | 293 | 4.940 |
| fixed_three | 2484 | 342 | 4.957 |
| fixed_four | 2484 | 365 | 4.924 |
| runs_count | 2290 | 726 | 6.898 |
| runs_length | 2192 | 726 | 7.092 |

形态分组的相同输入比较（左为 runs_count，右为指定对照；时间为每输入中位数之和）：

| 形态 | 对照 | 总比较数（左/右） | 时间ms（左/右） |
|---|---|---:|---:|
| random | merge | 320 / 288 | 0.864 / 0.679 |
| random | runs_length | 320 / 315 | 0.864 / 0.933 |
| random | fixed_four | 320 / 300 | 0.864 / 0.707 |
| sorted | merge | 68 / 171 | 0.289 / 0.288 |
| sorted | runs_length | 68 / 68 | 0.289 / 0.292 |
| sorted | fixed_four | 68 / 130 | 0.289 / 0.178 |
| reverse | merge | 268 / 200 | 0.651 / 0.341 |
| reverse | runs_length | 268 / 239 | 0.651 / 0.733 |
| reverse | fixed_four | 268 / 208 | 0.651 / 0.360 |
| unequal_runs | merge | 194 / 242 | 0.652 / 0.501 |
| unequal_runs | runs_length | 194 / 193 | 0.652 / 0.701 |
| unequal_runs | fixed_four | 194 / 256 | 0.652 / 0.519 |
| random_boundaries | merge | 243 / 265 | 0.776 / 0.629 |
| random_boundaries | runs_length | 243 / 235 | 0.776 / 0.774 |
| random_boundaries | fixed_four | 243 / 284 | 0.776 / 0.623 |
| short_runs | merge | 279 / 274 | 0.797 / 0.627 |
| short_runs | runs_length | 279 / 283 | 0.797 / 0.854 |
| short_runs | fixed_four | 279 / 292 | 0.797 / 0.635 |
| long_runs | merge | 174 / 234 | 0.672 / 0.535 |
| long_runs | runs_length | 174 / 174 | 0.672 / 0.690 |
| long_runs | fixed_four | 174 / 233 | 0.672 / 0.512 |
| perturbed | merge | 140 / 189 | 0.479 / 0.360 |
| perturbed | runs_length | 140 / 140 | 0.479 / 0.507 |
| perturbed | fixed_four | 140 / 192 | 0.479 / 0.325 |
| skewed_runs | merge | 192 / 202 | 0.703 / 0.355 |
| skewed_runs | runs_length | 192 / 155 | 0.703 / 0.586 |
| skewed_runs | fixed_four | 192 / 194 | 0.703 / 0.305 |

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
