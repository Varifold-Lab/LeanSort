# Learnable, verified adaptive sorting — local experiment

This experiment learns a small decision tree from measured costs, freezes it,
and evaluates it on unseen inputs. It can fail to beat a fixed strategy. It is a
research baseline, not a UI, production service, or general algorithm synthesizer.
CPU only; Python 3.9+ standard library and the existing Lean dependencies suffice.
The original threshold experiment and default library imports are unchanged.

## Run the complete loop

From the repository root:

```sh
python3 experiments/adaptive/run.py --smoke
python3 experiments/adaptive/run.py
```

The recorded audited full run is
[`20260907T024833Z-full-b5f2e8`](results/20260907T024833Z-full-b5f2e8/conclusion.md).
Reproduce its input dataset with `python3 experiments/adaptive/run.py --seed 20260908`.
Timings, and therefore fitted trees, may vary between runs; the saved model can be
loaded directly to reproduce its decisions. In this run the tree was about 8% slower
than the training-selected fixed Hybrid-24 after counting feature/decision overhead.
The earlier negative result and its measurement audit are also retained.

Each command creates a **new** timestamped directory in `experiments/adaptive/results/`.
An existing `--output DIRECTORY` is rejected, never overwritten. Default execution
builds the library, checks the new proofs, runs Python tests, then collects and
evaluates. Smoke mode only checks the harness; it is not a performance experiment.

Continue accumulating compatible training observations using a different seed:

```sh
python3 experiments/adaptive/run.py --seed 20260907 --training-from PATH_TO_PREVIOUS_FULL_RUN
```

`--training-from` can be repeated. Only `observations-train.jsonl` is accepted,
validated against its training dataset and split. Repeated observations of the
same input are pooled before fitting so they do not multiply that input's weight.
Configuration, code, backend and machine fingerprints must match. Smoke and full
results cannot be mixed. The current run's new observations remain separate from
historical logs; list every history directory you wish to reuse, not just the last.
Never promote test observations to training or change settings to chase this test
set. After research decisions based on a report, use a newly reserved evaluation
set for a new confirmatory experiment.

Try a trained policy on your own sequence:

```sh
python3 experiments/adaptive/infer.py --model PATH_TO_RUN/model.json --input '[9, 1, 4, 4, 2]'
```

It prints input features, the selected plan, fallback status, and sorted output.
A missing, malformed or unsupported model falls back to merge sort. Input must
be a JSON list of natural numbers; malformed inputs are rejected, not reinterpreted.

## Frozen experimental protocol

[`config.json`](config.json) is fixed before data collection and copied into each
run's metadata. No hyperparameter search uses test results.

- **Candidates:** Merge, Insertion, Hybrid thresholds 1, 8, 24, 64.
- **Training:** 160 inputs, lengths 16/32/64/128/256, four seeds per shape/length.
- **Test:** 80 inputs, lengths 23/39/71/135/263, two separate seeds per shape/length.
- **Shapes:** sorted, reverse, nearly sorted, random, duplicate-heavy, variable
  ascending runs, organ-pipe, and skewed values.
- **Features:** length, adjacent descent fraction, count of maximal nondecreasing
  runs, adjacent equality fraction, max-minus-min, and duplicate fraction in the
  first 32 elements. Fractions are integer parts-per-thousand. The last feature is
  a biased prefix proxy, not global distinct cardinality; descents are not inversion
  count. Family names, seeds and case IDs are never model inputs.
- **Learner:** cost-sensitive CART, depth at most 3, minimum 8 inputs per leaf,
  at most 16 candidate cut values per feature, minimum 1% empirical cost reduction.
  Leaves minimize summed training median latency, not classification error.
- **Accumulation:** fit on the first half of new training observations plus history,
  then refit on all training observations plus history. Save both model snapshots.
  Only the final frozen snapshot sees held-out evaluation.
- **Best fixed:** selected using aggregate training costs, never test costs.
- **Manual rule:** Insertion for length ≤ 32 or no descents; Hybrid-64 for descent
  fraction ≤ 50/1000; Hybrid-24 otherwise. It computes the same features as the tree.
- **Oracle:** post-hoc minimum of six measured fixed-candidate medians per test
  input. It assumes free perfect choice and is selection-biased, not executable.

Train/test seed domains and lengths are disjoint. Test generation happens only
after `model-frozen.json` records the final model hash and chosen fixed baseline.
Every test observation carries that hash; it is checked again after evaluation.

## What the timer includes

The persistent Lean worker sorts actual `List Nat` values using the repository's
implementations. For each adaptive call the timer covers:

```text
input List already available
  → extract features → traverse tree / apply manual rule
  → validate-by-construction plan dispatch → sort → consume output → stop timer
```

Input features are recomputed **inside** every adaptive timed call. Fixed policies
pay no feature-extraction cost. Every resulting list is checked against Python's
`sorted` reference **after** the timer stops, including warm-up calls. Feature
values and exported tree predictions are also cross-checked between Python and Lean.

Each candidate is warmed up. Five rounds × three calls per strategy/input are
recorded, with rotated/reversed strategy order. Raw samples are retained without
outlier removal. A generated-code audit checks that sorting and feature extraction remain between
the clock reads. The feature diagnostic reads its input through IO inside its timer
to prevent sharing a previously computed vector. The output checksum/traversal and timing/IO-reference overhead
are included equally; dataset generation, reference sorting, correctness checking,
model loading, JSON transport and process startup are outside each in-process sort
timer. Startup, model-load roundtrip, request wall time and training time are saved
separately. Thus these are **steady-state sorting API** measurements, not cold CLI
latency or amortized training cost. Warm repeated inputs can favor cache locality.

The backend is `lake env lean --run`, not a native C/LLVM benchmark. Component
instrumentation and Lean runtime behavior influence costs. No inference about
hardware-independent algorithm speed, native deployment, or asymptotic complexity
is warranted from these measurements.

Primary endpoint: tree / training-selected best fixed, using the sum of per-input
median end-to-end latencies. A family-stratified paired bootstrap over input cases
reports a descriptive 95% interval; repeats are not treated as independent inputs.
This is not a multi-session hardware study. Other comparisons and family breakdowns
are descriptive. The report also includes mean, median and P90 per-input latency.
`tree_plan_only` and separately measured feature extraction help diagnose overhead;
their timing differences remain noisy, not an exact causal decomposition.

## Proof boundary and extension point

[`Adaptive.Plan`](../../LeanSort/Algorithm/Adaptive.lean) supports verified leaves
and arbitrary nested `split cut left right` plans. Split means take/drop at the cut,
recursively execute the two plans, then merge. The number and position of cuts are
not fixed by this representation. This learner emits **leaf plans only**; no dynamic
segmentation planner or novel algorithm synthesis is implemented.

[`Plan.run_spec`](../../LeanSort/Verification/Adaptive/Correctness.lean) proves
sortedness and permutation for **every finite plan, every finite `List α`, and
every linear order**. The split case composes existing insertion/hybrid correctness
and CSlib merge theorems. `selectAndRun_spec` covers any total plan selector;
`rejected_eq_merge` describes the fallback. The actual worker's `strategy_spec`
instantiates that theorem for its fixed/manual/learned strategies.

JSON only decodes to this typed language. Unknown algorithms, unsupported thresholds,
invalid feature indices, schema mismatch and excessive nesting reject the model or
plan, yielding `none`; execution then uses proved Merge. Bad predictions may be
slow but cannot invalidate the mathematical sorting guarantee. This does not prove
the parser, OS, compiler, hardware, benchmark clock, Python trainer, or absence of
resource exhaustion. Termination concerns the mathematical finite plan execution,
not unbounded IO requests. Stability and hybrid/plan cost bounds remain unproved.

The earlier run `20260907T024123Z-full-8c2c4d` is preserved with an
[`AUDIT.md`](results/20260907T024123Z-full-8c2c4d/AUDIT.md): its feature-only diagnostic
was optimized outside the timer. Its main end-to-end timings were confirmed inside
the timer. Instrumentation version 2 fixes only that diagnostic and adds the compiler
audit; no candidate or learning parameter was tuned using test results.

## Files and checks

`data.py` generates inputs; `learning.py` fits/prints the tree; `Worker.lean` executes
and times; `run.py` orchestrates/persists; `report.py` evaluates; `infer.py` runs one
inference. No external model framework or network service is involved.

Each completed run contains datasets, incrementally flushed observation JSONL files,
two model snapshots, model-freeze evidence, a training learning curve, test CSV,
`summary.json`, `conclusion.md`, metadata/code hashes, build/axiom logs, generated-C
timer-placement audit, and counts
of checked outputs. Interrupted runs retain their partial observations; only a
completed consolidated training log is currently reusable by `--training-from`.

```sh
lake build
lake build LeanSort.Verification.HybridMerge.Checks LeanSort.Verification.Adaptive.Checks
python3 -m unittest discover -s experiments/adaptive -p 'test_*.py'
```

Lean regressions cover empty lists, zero/oversized cuts and nested heterogeneous
plans. Python unit tests cover data isolation, tree fitting, training-only access,
deduplication, provenance, compatibility rejection and honest reporting of losses.
The live protocol checks feature values, malformed models, valid/invalid plans,
fallback and output equality. These are finite checks, distinct from Lean's universal
theorems. Next mathematical work: a compositional operational-cost semantics and
resource bounds for plans, then certified propagation rules to guide dynamic cuts.
