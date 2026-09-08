# 学习引导的合并树搜索与成本认证

一个有终点的本机研究实验：给定正 run 长度，构造保持叶序、只合并相邻段的满二叉树，优化所有内部节点重量之和 B(T)。复用并证明等于 `MergeTree.budget`；不是精确键比较、机器耗时或所有排序算法的最优性。

## 复现

仓库现有 Lean/Lake 与 Python 标准库即可，不安装依赖、不联网：

```sh
python3 experiments/learned-merge-search/run.py --smoke
python3 experiments/learned-merge-search/run.py
python3 experiments/learned-merge-search/audit_saved.py experiments/learned-merge-search/results/<run>
```

每次生成新目录，不覆盖旧结果。最后一条仅核对保存数据，不重新训练或选择模型。`acceptance.json` 与 `saved-data-audit.json` 都通过才视为完成验收；失败保留 `failure.json`、阶段日志和可恢复 `checkpoint.json`。人工中文判读见正式结果目录的 `interpretation.zh.md`。

## 实验结构

- `reference.py`：经典区间 DP、重建及独立 postfix 全树枚举。枚举不用 DP 递推核对自己。
- `core.py`：统一有限 DFS。相同状态、初始可行解、切点集合、左侧优先待展开区间、去重与补全规则；三种方式只改变切点顺序。没有 beam、预测剪枝或借助测试 DP 的特征。运行中的可靠全局下界为 0，队列耗尽不作为 Lean 最优性证书。
- `learning.py`：训练轻量 CART，预测切点最优续接相对 regret，仅使用训练 DP 标签。验证集在预定深度 2/4 中选一个，冻结后才产生最终确认及段数外推数据。
- `data.py`：同源扰动整组划分，以除 gcd 后正反向最小向量检测缩放／反转泄漏。等长向量留作独立结构诊断，不把其缩放克隆称为未见数据。生成家族、真实列表扫描来源和完整向量保留，不作为模型输入。
- `certificates.py` 与 `Worker.lean`：对所有最终及中间改善树进行 Lean 可执行证书检查，核对旧 count/length 规划规则，抽取有序 runs 直接执行并独立核对比较数。每个实测 r 另有具体 kernel-normalized 最优性证书。
- `run.py`、`reporting.py`、`audit_saved.py`：pilot、冻结、训练、统一计时、原始记录、配对统计与事后独立复核。

没有修改原排序内核、规划器、七候选、历史模型或旧结果；本轮模型不做在线七选一，也不生成任意新排序算法。

## 数学证书

新增 `LeanSort/Model/MergeSearch.lean`、`Algorithm/MergeSearch/Certificate.lean`、`Verification/MergeSearch/`。

`Fits` 表示树恰覆盖半开区间 [i,j)，每个叶子是原 run 索引，合并子树非空且相邻。`realize_leaves` 证明不丢段、不重复、不改内容或顺序；`realize_budget_lengths` 证明预算与旧 MergeTree 完全一致。

Bellman 下界证书检查每个区间的所有合法切点：

```text
d(i,i) = d(i,i+1) = 0
d(i,j) ≤ sum(lengths[i:j]) + d(i,k) + d(k,j)
```

`lower_sound` 证明任意合法树预算 ≥d(i,j)。若另一个合法树预算等于根值，`checkOptimal_sound` 给出该限定空间内的最优性。预测值从不充当该下界；最终完整 DP 表在搜索之外产生并检查。

`safe_correct`、`safe_cost`、`discovered_correct`、`discovered_cost` 复用原直接执行精化，提供有序性、排列保持、比较数 ≤B，以及包含扫描时的 `(n−1)+B`。非法树安全回退 countPlan；损坏的模型优先级有界回退，不改变合法切点集合。

通用证明是 Lean kernel 检查的命题。全部具体数据经过定理支持的编译执行检查器；仅明确列出的代表实例另有 kernel-normalized 证明项，二者不混称。数值计算、JSON、编译器及实际机器仍是实验可信边界。

## 公平性、预算和解释

参数预先写在 `config.json`，pilot 仅依时间／内存选择 r 范围，然后冻结正式协议。对照包括旧 count/length 规则的长度向量移植、精确 DP 和三个共同搜索器，均在相同本机 Python 后端规划。长度规则逐实例和原 Lean 实现核对，但未另外证明该 Python 移植的通用精化。

比较固定展开数下的预算，以及严格截止时刻前已获得的预算。墙钟搜索可超出一个展开步骤；实际超出值保留，不能把截止后的改善当作按时结果。达到 OPT 或 1.01 OPT 的时间仅从保存轨迹事后计算，不让 OPT 影响搜索。超时、未完成、未执行分别记录，缺失成本不填零。

模型特征／推理、初始方案、去重、补全、排序优先级和轨迹记录均计入搜索时间。训练、标签 DP、最终参照、Lean 证书和排序执行单列；搜索不是在线排序速度。DP 无跟踪时间与单独 tracemalloc 峰值分配都直接测量，跟踪重放时间不混入主要计时。搜索预算中的内存限制针对 Python 进程；Lean 构建及证书进程另设超时，不把它们的内存当作 DP 算法空间。

重复轮先在各输入内汇总；同源扰动仍相关。报告均值、中位数、P90、逐实例退化、失败和目标未达到数，不做普遍最优、算法新颖性或统计显著性声明。

完整交付保留原始输入、搜索轨迹、中间树、DP 表、内存重放、标签、两个训练模型、冻结记录、所有 Lean 请求/响应、实际执行输出、比较数、时间、公理与重新编译日志。没有 commit 或 push。
