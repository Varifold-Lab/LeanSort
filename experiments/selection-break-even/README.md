# 在线选择的收益临界点与特征预算

有终点的本机实验，不修改历史排序内核、规划器、候选或模型，不做空间／云资源／神经网络实验。

```sh
python3 experiments/selection-break-even/run.py --smoke
python3 experiments/selection-break-even/run.py
```

使用已有 Lean 工具链、Python 标准库和已安装 Pillow。无需 matplotlib 或新增依赖。脚本需要读取本机 sysctl、子进程 RSS；没有网络调用。

先运行旧／新测试、lake build、旧 17 模块及新 3 模块 fresh replay、公理审计和生成 C 计时检查。随后用独立 pilot 确定正式资源、长度范围。A 原样使用上轮最终模型、规则和 Worker 做长度／结构配对诊断；B 只比较 length / 8 / 16 / legacy 四种预算，在独立数据上拟合轻量树和校准有限规则网格，再冻结、生成确认集、评测一次。

配置见 config.json。所有正式测量使用同一请求超时和采样 RSS 界；pilot 资源预测不能完成的扩展格点留 not-executed，超时原始部分事件保留，缺失成本 null，不能填零。A 支持有界未完成扩展；B 训练／确认不完整则明确验收失败，不静默删除样本。

数据同时保存 input/base hash、完整输入、种子、分组、生成设计与实际发现 runs。生成边界不进入选择器；同源形态整组划分。旧实验与 A 的输入都不用于 B 确认。完全相同派生输入合并并记录别名；不同序列不等于独立同分布统计样本。

低预算提取需要 List.length 和单调前进的探针遍历，键比较少不等于 O(1) 时间。不缓存 runs，不独立从头查每个探针。所有在线特征、推理、分派、内核和完整输出消费计时；证明、加载模型、JSON、数据生成、精确核对和独立诊断重放在核心时间之外。诊断分项不相加冒充 E2E。

新 Lean 模块在 Algorithm/BudgetSelection 与 Verification/BudgetSelection。证明覆盖不计数／计数／符号特征对应，0/8/16/80 键比较预算和选择组合；复用旧正确性、回退和内核成本定理，不把有限测试冒充通用证明。特征选择器仅实验 Nat；候选分派的正确性仍由旧库在任意 LinearOrder 上保证。元数据、分配、遍历、模型计算和机器时间不属于键比较单位。

每次输出新 results 目录，包括阶段日志、checkpoint、完整请求／逐轮事件／记录、全部 16 模型、所有规则、冻结选择、paired.jsonl、analysis.json、图表及 CSV、findings.zh.md、验收日志。负结果也是完成，不循环直到跑赢。最终人工判读保存在正式运行的 interpretation.zh.md。
