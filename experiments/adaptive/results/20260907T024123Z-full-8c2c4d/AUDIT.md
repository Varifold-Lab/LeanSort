# Measurement audit — preserve this run, do not reuse its feature-only metric

The original raw data, frozen model and report are retained unchanged.

The **feature-only diagnostic** is invalid: Lean common-subexpression sharing
computed `features xs` before the diagnostic loop, so its reported 0.016 ms mostly
measured folding a previously computed feature vector. It cannot be used to
estimate extraction cost. This also affects the two earlier smoke runs, which
were not performance evidence.

The **main end-to-end timings remain informative**. Inspection of generated C
confirmed `checkedRun` calls the clock, `Strategy.run`, output checksum, then the
clock again. The approximately 9% slowdown versus the training-selected fixed
strategy is not removed or replaced with a favorable outcome.

The correction only isolates the feature diagnostic with a fresh IO read inside
its timer and adds a generated-code regression audit. Candidate algorithms,
feature definitions, manual rule, tree parameters, and primary endpoint are not
changed. A subsequent full run uses seed 20260908 for new training and test inputs;
this run's held-out observations do not enter its training. Historical compatibility
checks prevent mixing the two instrumentation versions.
