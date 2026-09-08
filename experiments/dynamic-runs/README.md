# 动态发现 runs：正确性、结构成本与实测

这是独立研究实验，不修改主入口、此前实验或算法目录。目标是从任意有限 `List α` 自动发现结构并产生可执行合并方案，不接受生成器边界，不预设 run 数，也不使用学习模型。

## 一键验收

在仓库根目录、已配置的 Lean/mathlib 环境中：

```sh
python3 experiments/dynamic-runs/run.py --smoke --rounds 3
python3 experiments/dynamic-runs/run.py
```

仅本机 CPU、Python 标准库和仓库锁定的 Lean 依赖。每次产生独立 `results/<timestamp>-<mode>-<id>/`，不覆盖旧数据。失败会保留原始响应和 `failure.json`；只有全部验收通过才生成 `acceptance.json`。完整实验不是大规模性能竞赛：60 个校准输入、98 个最终输入，每个策略每输入默认重复 5 次。

## 数学与执行语义

`RunDiscovery` 从左至右比较每对相邻键，得到连续的非递减 runs。`RunMerge.countPlan` 按实际 run 数对半递归；`RunLengthPlan.lengthPlan` 按元素位置中点选择邻近 run 边界。输入为空时树为空；单个 run 不再比较。两者都终止并保留 run 的顺序和内容。

| 文件 | 内容 |
|---|---|
| `LeanSort/Algorithm/RunDiscovery.lean` | 扫描的比较程序 |
| `LeanSort/Model/MergeTree.lean` | 动态树、叶子、重量、深度、合并预算与有效 runs 命题 |
| `LeanSort/Algorithm/RunMerge.lean` | 树执行、按 run 数建树、扫描后构造并执行 |
| `LeanSort/Algorithm/RunLengthPlan.lean` | Peeksort 风格长度策略 |
| `LeanSort/Algorithm/RunStrategy.lean` | 与已有 CostedPlan 共用的部署接口 |
| `LeanSort/Verification/RunAdaptive/` | 分段、正确性、成本、渐近界、结构性质、策略证书、核内小例子 |

统一单位是一次键值 `≤` 比较，沿用 `Comparison.Program`、`Program.eval` 和 `Executes`，不混合交换数或其他算法的成本模型。每个 `compare` 执行一次并计数一次；扫描记为 `.check`，合并记为 `.sort`。比较计数解释器本身也有运行开销。此处不声称存在零开销插桩或已验证的原生编译器。

主要定理（前缀 `LeanSort.RunAdaptive`）：

- `discover_spec`：拼接等于输入、每段有序且非空；空输入无段。
- `discover_cost`：扫描精确 `n-1` 次（自然数截断减法）；`runCount_eq_descents`：非空时实际 run 数为下降边界数加一；`runCount_zero_iff` 处理零。
- `countPlan_leaves` / `lengthPlan_leaves`：数据驱动建树保持叶子顺序。`count_sort_spec` / `length_sort_spec`：最终有序并保持排列。
- `operational_certificate` / `Strategy.execution`：实际程序的输出和计数满足操作语义；`check_cost`、`sorting_cost`、`cost_decomposition`：阶段成本精确对应。
- `cost_le_tree_budget`：任意建树器的总成本不超过扫描加树中所有内部节点重量之和。预算是上界，不是实际比较数。
- `countPlan_depth`：深度不超过 `Nat.clog 2 r`；`count_cost_le_upper`：

  `C(xs) ≤ max(0,n−1) + n * Nat.clog 2 r`。

- `count_cost_isBigO_structural`：`O(n*(1+log(max(1,r))))`，其中 `r` 随输入变化，不藏进常数。先证明适用于所有 `n,r` 的显式实数不等式，再用 mathlib 的 `Asymptotics.IsBigO`。
- `count_cost_isBigO_nlog`：全输入 `O(n log n)`；`count_cost_of_sorted` / `length_cost_of_sorted`：已排序输入精确 `max(0,n−1)` 次比较；另有有序输入线性渐近定理。

所有定理对任意有限长度及合法 `LinearOrder α` 成立。扫描和建树由 Lean 的结构/良基递归检查终止，程序解释器也为总函数；这不等于证明真实机器不会耗尽栈或内存。没有重复检查已认证 runs 的键值；建树会访问长度等元数据，其成本不属于键值比较数。

## 公平对照与预注册

主要策略全部使用同一 Lean `List Nat`、`≤` 和比较程序解释器：

1. 单一 Merge。
2. 固定 Hybrid：仅在独立校准集上从 `1,4,8,16,24,64` 选择阈值，以每输入 E2E 中位数之和最小为准；平局取小阈值。
3. 上阶段的 2/3/4 固定比例切分，各叶使用有序检查＋Merge 回退；检查比较计入成本。仅 `Ready` 真时使用条件成本定理，无条件上界对所有输入有效。
4. 自动扫描＋按 run 数平衡。
5. 自动扫描＋Peeksort 风格长度中点策略。

长度策略参考 [Munro–Wild 原论文 §3.1、Algorithm 1](https://www.wild-inter.net/publications/munro-wild-2018.pdf)，包括整数中点的奇偶/平局行为。独立 Python oracle 用边界到半长的距离实现，并与论文分支规则枚举核对。它是**提前检测非递减 runs 后的切分策略移植**，不含原版惰性扫描、下降 run 反转、数组优化等；尚未证明论文熵界或与原实现等价。不能据此声称超过原版 Peeksort/Powersort。

完整校准：长度 `24,80,192`，种子 `9011,9029`。最终测试：长度 `33,97,257`，种子 `100003,200003,300007`，另加 8 个边界例子。10 种形态为随机、有序、严格逆序、重复值、不等长 runs、随机边界、大量短 runs、少量长 runs、局部扰动、极不均衡 runs。生成的相邻块可能自然连接，始终保存扫描实际得到的 run 数和长度，不使用生成器的预设段数。

`protocol.json` 在校准前保存候选和指标，`frozen.json` 在最终测试生成前保存阈值、校准得分和源码摘要。数据集的 ID、种子、长度与输入哈希隔离；测试集不得用于调参。单元测试可验证生成器的分离和覆盖性，但不根据最终测试性能调参。

## 计时边界与验收

部署计时从内存输入开始：时钟 → IO 读取输入 → 扫描/建树/执行（或固定方案）→ 全输出 checksum 写入 sink → 时钟。结果等于参考排序的检查在时钟外，并对每次执行进行。所有方案轮换/反转执行次序且先预热一次。

计时外：数据生成、JSON 通信、离线证明生成与检查、校准选择、独立成本核对、诊断重放。源码 C 输出的计时位置检查只防范常见的复用/移动计算回归，不是编译器或时钟语义的形式化证明。

`scan_ns`、`plan_with_consumption_ns`、`merge_only_ns` 是分别重放的诊断。建树诊断还消费树的 budget/weight；这些数不能相加当成 E2E，也不重复加到 E2E。算法内的 List 遍历、长度运算、分配、树/比较程序构造、解释器及计数器开销都在 E2E 内，却不在已证明的比较成本模型里。不能称作完整机器时间或空间成本证明。

每次运行执行：

- 当前项目与相关旧/新模块的 `lake build`，新旧 Python 回归测试。
- 将全部 13 个新 Lean 模块重新编译到本次结果目录，导入路径优先使用新产物，不只读取旧缓存；重新检查部署 Worker 和冻结阈值证书。
- `#print axioms` 核心定理审计，仅允许 Lean/mathlib 标准 `propext`、`Classical.choice`、`Quot.sound`；不允许 `sorry`、自定义公理或 `native_decide` 证明捷径。
- 每个输入/策略的输出、实际 run 边界、各项比较数、树形及适用成本不等式，与独立流式 Python 实现逐项核对；包含手算小例子。
- 源码哈希在运行前后相同，保存完整输入、实际计划、每轮时间与环境信息。

`evaluation.csv` 是每个真实输入/策略一行；`by-shape.csv` 和 `paired.csv` 分别汇总形态与配对胜负，不把重复计时当成新增独立样本。上界更小、实际比较更少、时间更短是不同结论；不据上界或实测声称成本支配/全局最优。

完整原始数据在 `dataset-*.jsonl`、`observations-*.jsonl`，证明记录在 `fresh-proof-*.log`、`Acceptance.lean`、`axioms.log`、`Frozen.lean`，实测中文结论在 `conclusion.zh.md`。此前 `experiments/adaptive` 的决策树负结果和 `experiments/cost-plans` 的固定方案实验原样保留。
