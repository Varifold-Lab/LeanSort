# Direct-executor cost learning

Local, CPU-only experiment: measured data → three growing training snapshots → validation → frozen model → unseen evaluation. This selects existing certified plans; it does not synthesize algorithms or prove performance optimality.

## Reproduce

From the repository root with its existing Lean toolchain and Python 3 (standard library only):

```sh
python3 experiments/direct-cost-learning/run.py --smoke
python3 experiments/direct-cost-learning/run.py
```

Each invocation creates a new timestamped directory under `results/`. It runs existing and new tests, `lake build`, fresh direct-executor/selection proof recompilation, axiom and generated-C timer audits, then measurements, actual model fitting, freezing and final tests. The local runner needs permission to read its child process RSS (`ps`) and machine memory (`sysctl`). No network, GPU or new dependency is used. Failure and partial timing streams are retained; a failure blocks acceptance, never supplies a zero label.

## Frozen design

`config.json` fixes seven candidates, feature schema, training prefixes, validation/test seeds, human rules, hyperparameter grid, repetitions and budgets before measurement. Candidate IDs 0–6 are Merge, Hybrid-8, fixed two/three/four segments, count-balanced runs, length-policy runs. `catalogue.json` records executable entry, theorem-backed certificate, preconditions and cost formula. Existing direct executors, comparison semantics and planners are unchanged. All candidates use the same direct List backend, comparator and output consumption in one persistent `lean --run` process.

Six features contain length and at most 16 spread adjacent-pair probes: sample count, adjacent descent/equality rates, descent rate between sampled left keys, and sampled range. List length and reaching sample positions still take traversal time; fixed comparison budget does **not** mean constant-time extraction. No generator family, seed, boundaries, sorted reference, absolute key offset or measured costs enter inference. There is no run reuse, so repeated traversal is paid online. Full feature extraction is inside each sampled selector's end-to-end timer.

The classifier is a small CART tree with 2% near-tie winner labels. A multi-output regression tree predicts seven relative time ratios (candidate median / per-input candidate Oracle median), then selects their minimum. These are relative wall-time predictions, not formal bounds or absolute nanoseconds. Both use only newly measured direct, uncounted execution labels. Depth/leaf-size options are evaluated on one fixed validation set; three nested training sizes and all models are saved. Final models come from the largest prefix; validation selects hyperparameters, not final test results.

The best fixed candidate is chosen using all training measurements. A sampled rule and a cheaper length-only rule are frozen in advance. Learned trees are loaded as simple data once, and inference/dispatch execute in Lean for every timed input. Invalid or unsupported models/IDs safely fall back to Hybrid-8. Model load, data generation, reference evaluation, proof work and diagnostic replays are outside core timing. Output consumption is inside; exact output checking is outside every timed repetition.

## Data and statistics

Shapes derived from one base sequence stay in one split. Exact within-group duplicate sequences are collapsed before measurement, with aliases recorded. Input/base hashes are checked for cross-split leakage. Independent final seeds are used only after writing `final-frozen.json`; additional lengths are reported separately as generalization. Previous public results are preserved and never reused as new unseen tests or mixed timing labels.

`dataset-*.jsonl` saves full inputs, reproducible identity and grouping. `events-*.jsonl` saves each warmup/repetition immediately. `records-*.jsonl` saves features, their diagnostic timing, each candidate's comparison phases, certified bound, applicability, raw direct times, online policy times, selected-only diagnostics and version hashes. Status distinguishes completed, failed and not executed; missing cost is null. Repeated measurements are not independent inputs.

End-to-end intervals include the strategy's actual features, inference, valid dispatch, sorting and complete output checksum. Standalone feature/decision/kernel diagnostics are **not summed** into E2E. Reports include input-wise paired distributions, regressions, shape groups and aggregate sums of input medians. The free hindsight Oracle is restricted to seven candidates, excludes selection overhead and is neither deployable nor globally optimal. No test-driven tuning or outlier deletion is performed.

## Proof boundary

`LeanSort/Verification/LearnedSelection/Correctness.lean` proves arbitrary selection and fallback correctness for finite lists over any `LinearOrder`, plus inherited kernel bounds. Learned numeric features/models specialize the experiment to Nat. Certificates manually register existing theorems; they are not automatic property discovery.

`Verification/LearnedSelection/Features.lean` proves plain/counted/symbolic feature correspondence, exactly five key comparisons per successful probe, at most 80 overall, and a symbolic composition with the selected kernel. Thus sampled selection has a proved key-comparison bound `80 + kernelBound` (also a tighter actual-probe bound). Fixed/length-only selectors have no additional key comparisons. Metadata comparisons, arithmetic, traversal, allocation and model inference are not key-comparison units, but their actual execution is timed. Output equality alone is not used to infer operation-count equivalence.

New core theorems are freshly compiled and their axioms audited along with existing direct refinement theorems. Independent Python feature/count implementations, exact sorted outputs, bound applicability, exported predictions (including full regression leaf vectors), fallback cases and generated C timer boundaries are checked. Lean semantics → compiler → runtime → machine remains a trusted boundary; no theorem proves machine time, compiler correctness, model accuracy or optimal choice.

Read each completed run's `validation.json`, `summary.zh.md`, `analysis.json`, `learning-curve.json`, `source-hashes.json`, build/audit logs and raw records. A manually reviewed Chinese `findings.zh.md` may accompany the accepted full run.
