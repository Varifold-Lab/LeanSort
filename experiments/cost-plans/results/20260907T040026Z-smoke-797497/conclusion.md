# Certified cost-plan experiment

Lean checked 100 structurally distinct composites and 5 single-algorithm baselines, each for arbitrary finite lists over a linear order.
The structural n-log-n rule covers 66 composites; the conditional linear rule covers 50.
Only the offline-frozen shortlist (18 algorithms) was measured on 20 inputs. All outputs and cost inequalities passed finite regression checks.

## Three different claims

- Proved: for n >= 8, two insertion-sorted halves have a smaller sufficient comparison envelope than insertion on the whole list.
- Proved: if both halves are sorted, two guarded halves have a smaller envelope than the general merge-sort envelope for n >= 8. Guards are charged; fixed block depth gives O(n). This compares available envelopes, not tight worst-case costs under the same restricted domain.
- Proved counterexample: on range(8), the envelopes are 20 < 28 but actual comparisons are 10 > 7. Hence envelope ordering alone does not imply pointwise dominance.
- Proved no novelty: merge-halves executes the same comparison program as merge-sort for lengths >= 2. Structural deduplication does not remove all semantic duplicates.

## Descriptive measurements (same inputs, same interpreter)

| Algorithm | Total comparisons | Guard comparisons | Sum of per-input median time (ms) |
|---|---:|---:|---:|
| single_merge | 875 | 0 | 1.625 |
| single_insertion | 1649 | 0 | 5.917 |
| single_hybrid_4 | 857 | 0 | 1.526 |
| single_hybrid_8 | 905 | 0 | 1.667 |
| single_hybrid_16 | 1094 | 0 | 2.353 |
| p000_two_insertion | 1061 | 0 | 2.389 |
| p001_two_guarded | 851 | 153 | 1.577 |
| p002_merge_halves | 875 | 0 | 1.672 |
| p003_guarded_merge | 851 | 113 | 1.509 |
| p004_prefix_insertion_merge | 909 | 0 | 1.766 |
| p005_three_guarded | 870 | 167 | 1.510 |
| p006_four_guarded | 846 | 181 | 1.484 |
| p007_mixed_hybrid | 958 | 0 | 1.807 |
| p028_split | 870 | 0 | 1.582 |
| p031_nested | 870 | 0 | 1.585 |
| p098_split | 903 | 0 | 1.660 |
| p024_split | 898 | 0 | 1.670 |
| p027_nested | 898 | 0 | 1.685 |

Raw repetitions are in observations.jsonl; per-case comparisons and guard applicability are in evaluation.csv. contrasts.csv separates envelope, operation-count and time comparisons, on identical inputs for each pair.

The conditional column is applicable only where ready=true. The baseline is evaluated on those same inputs, but its displayed envelope remains a general-input bound; no tight lower bound for that restricted domain was proved.

## Accounting and limitations

The uniform unit is one key <= comparison, tagged as sorting or runtime checking. Split traversal, allocation, length arithmetic, interpreter overhead and output consumption are outside that operation count but inside measured deployment time.
End-to-end timing starts from an in-memory input list, includes schema interpretation/splitting/guards/sorting and forced output consumption. Dataset generation, JSON transport, offline proof work and post-timing output equality checks are excluded. No model inference is deployed in this phase.
check_replay timing is an isolated replay of the same guard comparisons, proved to have the same check count. It is NOT an additive wall-time decomposition and is not added again to end-to-end time. Offline profiling executes extra diagnostics and is logged separately.
Backend: lean --run, with the same comparison-program interpreter for singles and composites. These timings describe this research representation, not an optimized/native sorting implementation. Repetition medians are descriptive; there is no significance, universal speedup or hardware-independent performance claim.
The generator enumerates a finite schema grammar and instantiates previously proved structural rules; it neither discovers new theorems nor claims globally optimal synthesis. The general certificate covers every finite schema in the grammar, beyond these 100 examples; it does not cover arbitrary Lean programs.
Thresholds and schema depth are fixed in the n-log-n/linear theorems. Concrete formulas expose their parameters. Allowing those parameters to grow with n requires using the parameter-dependent bound, not silently reusing the fixed-parameter asymptotic theorem.
Previous adaptive decision-tree data and its negative result are preserved unchanged. This experiment does not retrain or tune on those data.

## Separately recorded offline costs

- existing_lake_build: 2.077555 s
- general_proof_build: 1.820402 s
- offline_search_and_selection: 0.001210 s
- algorithm_and_proof_source_generation: 0.002210 s
- lean_check_algorithms: 2.671920 s
- lean_check_certificates: 6.478485 s
- worker_typecheck: 3.688929 s
- worker_startup: 1.833858 s
- evaluation_wall_including_transport_and_diagnostics: 2.128289 s
- offline_profile_diagnostics: 0.037373 s
