# 排序方案 → 算法 → 成本证书

这是独立的、离线的组合实验。保留原来的 Adaptive/HybridMerge、threshold 和决策树实验；
不改变默认库入口，不开发 UI，也不把固定长度网络作为算法表示。

## 本机复现

从仓库根目录执行，仅需现有 Lean 依赖和 Python 3.9+ 标准库：

```sh
python3 experiments/cost-plans/run.py --smoke --rounds 3
python3 experiments/cost-plans/run.py
```

每次创建新的 `results/时间戳/`，不覆盖旧结果。默认流程：运行单元测试和 `lake build`，
检查通用证明，离线枚举 100 个结构去重的组合，冻结短名单，生成并检查 105 份证书
（另含 5 个单算法基线），最后执行短名单、保存原始样本和报告。Smoke 只用于验证流程。
默认完整实验使用 62 个输入、每项 5 次计时；这是描述性实验，不做显著性或全局最优声明。

主要交付文件：

| 文件 | 内容 |
|---|---|
| `Generated/Algorithms.lean` | 每个方案及 `List α → List α` 可执行实现、成本公式 |
| `Generated/Certificates.lean` | 逐项正确性、操作语义、无条件/条件成本和适用的渐近证明 |
| `catalogue.json` | 方案、输入前提、公式、定理名；只在 Lean 检查成功后标记 proved |
| `shortlist-frozen.json` | 执行前冻结的筛选依据与算法 ID |
| `dataset.jsonl` / `observations.jsonl` | 完整输入、各轮原始时间、比较次数和检查结果 |
| `evaluation.csv` / `contrasts.csv` | 同一输入下分别比较上界、操作数和时间 |
| `conclusion.md` / `summary.json` | 结论、覆盖范围、分阶段开销 |
| `certificates.log` / `codegen-audit.json` | 公理审计和编译输出的计时位置检查 |

只有存在 `completed.json` 且 `success=true` 的目录才是完整实验结果。

## 先说清楚数的是什么

统一单位是**一次键值 `≤` 比较**。排序比较和运行时形态检查比较使用同一个单位，只带不同标签。
Insertion 的比较次数重新从其比较程序证明，**没有使用它原来的交换次数代替比较次数**。
Merge/MergeSort 的返回值和计数均证明等于 CSlib 对应实现。

`Comparison.Program` 把比较显式表示为动作；`Executes` 给出逐步累计比较的操作语义。
`eval_executes` 和 `Executes.eval_eq` 证明执行结果与成本一致。
这证明的是指定比较语义中的实际操作数，不是 CPU 指令数或硬件耗时。
通用证书只覆盖下面的封闭方案语言；不能把任意 Lean 函数藏在 `pure` 里便声称其计算免费。

不在比较计数内：List 遍历/切分/分配、长度和索引运算、计数器维护、解释器和输出消费。
这些开销都在部署计时内。因此比较数少不保证运行时间短；昂贵比较器也不具有相同的墙钟单价。

## 参数化方案和组合规则

```text
leaf: Merge | Insertion | Hybrid threshold
split: cut × left schema × right schema → sort blocks and merge
guardSorted: check adjacent order → unchanged if sorted, certified fallback otherwise
cut: clipped prefix k | clipped fraction a/b of the current subproblem length
```

每个方案适用于任意有限长度的 `List α`，要求 `[LinearOrder α]`。切点随当前子问题长度计算；
切点越界会截断，分母 0 按 1 处理，阈值 0 按 1 处理。方案可以嵌套；Hybrid 本身是递归排序。
当前不搜索依赖自然 runs 动态增减分段数的递归规划器。已有 Adaptive Plan 能嵌入新语义，输出相等已证明。

记 `I(n)=n.choose 2`，`M(n)=n*Nat.clog 2 n`，`T=max(1,threshold)`：

| 构件 | 已证明的比较上界 |
|---|---|
| Insertion | `I(n)`；已有序时精确为 `n-1`（自然数截断减法） |
| Merge 两个列表 | `left.length + right.length`，这是保守上界 |
| MergeSort | `M(n)` |
| Hybrid | `H(t,n)=I(n)` 若 `n≤T`，否则 `H(t,⌊n/2⌋)+H(t,n-⌊n/2⌋)+n` |
| Split | `Uleft(cut(n)) + Uright(n-cut(n)) + n` |
| Guard | `max(0,n-1)+Ufallback(n)`；检查成功时只有 `max(0,n-1)` |

这些不是 Python 标签：Lean 中的 `Schema.upper`、`Schema.readyUpper` 是正式公式，
`Schema.certify` 通过结构归纳组合已有定理，得到任何有限方案的证书。
目录中的可读公式是辅助显示；权威版本是条目指向的 Lean 定义。
Python 输出的 0/1/8/16/32/64/128 长度公式值也逐项经 Lean kernel 计算检查。

渐近界：

- 所有有限方案都有保守的固定系数 `O(n²)`。
- `logWeight = some k` 是一个充分结构规则，给出固定阈值/固定方案下的 `O(n log n)`；
  `none` 表示此规则不能证明，**不是性质为 false**。
- `Ready` 要求方案中实际受检的各块已有序；检查仍在部署时执行并计费。
  若 `readyDepth = some d`，总比较数至多 `n*(d+1)`，固定深度给出条件 `O(n)`。
- `H(t,n) ≤ n*clog₂(n)+n*max(1,t)` 对所有阈值和长度成立。
  阈值或方案深度若随 `n` 增长，必须使用带参数的界，不能直接套固定参数的渐近结论。

## 比较必须诚实

短名单固定为 8 个数学示例加上在 `n=64` 无条件上界最小的 5 项（再去重），然后加入单算法基线。
不根据测量结果调整这个规则，也不把条件不同的上界混在一起排名。
数据包括随机、已有序、逆序、重复值、2/3/4 个已有序块和边界情形；不是新一轮训练集调参。

计时从内存中的 List 开始，包括方案解释、切分、条件检查、排序和完整输出消费。
不包括离线搜索/证明、数据生成、JSON 通信及计时后的正确性核对。
同一 Lean 比较程序解释器用于组合和单算法；**不是优化后的 native 排序性能比较**。
每个结果与 Python `sorted` 核对，并与独立 Python 比较计数解释器交叉检查。
轮次交替旋转算法顺序；保留每轮数据，不只保留最快一轮。

`check_comparisons + sorting_comparisons = total` 有 Lean 证明。
`check_replay_samples_ns` 单独重放相同的检查动作，仅作诊断；它不是墙钟时间的可加拆分，
也不会再次加到部署时间。离线搜索、源代码生成、Lean 检查、解释器启动和 profile 另行记录。
编译输出审计确认排序/检查/输出消费在计时区间内；该审计是回归检查，不是形式化的时间证明。

已有数学示例还证明：两段 Insertion 虽有更小的上界，却**不逐点支配**整段 Insertion；
仅把 MergeSort 第一层展开的方案与原比较程序相同。因此“100 个结构不同的方案”不等于
“100 个语义不同或新发现的算法”。当前能力是**有限语法内的离线枚举、已证明构件组合和证书实例化**。

## 从哪里读证明

定义与算法在 `LeanSort/Semantics/Comparison.lean`、`Model/ComparisonBounds.lean`、
`Model/SortingPlan.lean`、`Algorithm/ComparisonSort.lean`、`Algorithm/CostedPlan.lean`。
证明分别在 `Verification/Comparison/` 和 `Verification/CostedPlan/`，按证明目标分文件。
先读后者的 `Examples.lean`，再看 `Cost.lean`、`Complexity.lean`、`Conditions.lean`。
单独检查：

```sh
lake build LeanSort.Verification.CostedPlan.Examples LeanSort.Verification.Adaptive.Correctness
python3 -m unittest discover -s experiments/cost-plans -p 'test_*.py' -v
```

下一步的数学缺口：更紧的受限输入上界和下界、非平凡的成本支配关系、可变分段递归模式的终止与成本定理，
以及高效直接执行器相对于比较程序语义的精化证明。空间/写入成本、真实硬件常数、全局最优性尚未证明。
第一阶段决策树慢于固定策略的原始结果保留在 `experiments/adaptive/`，不因本阶段结果而改写。
