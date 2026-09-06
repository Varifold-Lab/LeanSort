import LeanSort.Verification.Merge.Equations
import LeanSort.Verification.Merge.Cost

/-!
The optional trace agrees with CSlib in both result and comparison count.
Replay checks a single merge given its two input runs. The flat whole-sort trace
does not encode recursive boundaries and is not a rearrangement trace.
-/

namespace LeanSort.Merge

open Cslib.Algorithms.Lean

private theorem mergeTr_agrees {α : Type} [LinearOrder α] (left right : List α) :
    (mergeTr left right).1 = (TimeM.merge left right).ret ∧
      (mergeTr left right).2.length = (TimeM.merge left right).time := by
  fun_induction mergeTr <;>
    simp_all [TimeM.merge, TimeM.tick, Nat.add_comm, not_le_of_gt]

@[simp] theorem mergeTr_result {α : Type} [LinearOrder α] (left right : List α) :
    (mergeTr left right).1 = (TimeM.merge left right).ret :=
  (mergeTr_agrees left right).1

@[simp] theorem mergeTr_comparisons {α : Type} [LinearOrder α] (left right : List α) :
    (mergeTr left right).2.length = (TimeM.merge left right).time :=
  (mergeTr_agrees left right).2

private theorem sortTrace_agrees {α : Type} [LinearOrder α] (xs : List α) :
    (sortTrace xs).1 = (TimeM.mergeSort xs).ret ∧
      (sortTrace xs).2.length = (TimeM.mergeSort xs).time := by
  fun_induction sortTrace with
  | case1 => rw [TimeM.mergeSort]; simp_all
  | case2 xs h middle lr lt hl rr rt hr result trace hm ihl ihr =>
      have im := mergeTr_agrees lr rr
      rw [hm] at im
      rw [TimeM.mergeSort]
      simp_all [not_lt_of_ge, List.length_append, middle]

theorem sortTrace_result {α : Type} [LinearOrder α] (xs : List α) :
    (sortTrace xs).1 = mergeSortResult xs :=
  (sortTrace_agrees xs).1

theorem mergeSortTrace_length {α : Type} [LinearOrder α] (xs : List α) :
    (mergeSortTrace xs).length = mergeComparisonCost xs :=
  (sortTrace_agrees xs).2

/-- Check a complete merge trace; reject missing, extra, or incorrect choices. -/
def replayMerge? {α : Type} [LinearOrder α] :
    List Choice → List α → List α → Option (List α)
  | [], [], ys => some ys
  | [], xs, [] => some xs
  | [], _ :: _, _ :: _ => none
  | _ :: _, [], _ => none
  | _ :: _, _ :: _, [] => none
  | Choice.takeLeft :: trace, x :: xs, y :: ys =>
      if x ≤ y then (replayMerge? trace xs (y :: ys)).map (x :: ·) else none
  | Choice.takeRight :: trace, x :: xs, y :: ys =>
      if x ≤ y then none else (replayMerge? trace (x :: xs) ys).map (y :: ·)

theorem replayMerge?_mergeTr {α : Type} [LinearOrder α] (left right : List α) :
    replayMerge? (mergeTr left right).2 left right = some (mergeTr left right).1 := by
  fun_induction mergeTr <;> simp_all [replayMerge?]

end LeanSort.Merge
