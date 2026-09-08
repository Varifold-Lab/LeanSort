import LeanSort.Verification.RunAdaptive.Cost

namespace LeanSort.RunAdaptive
open Comparison

/-- Mathematical diagnostic only; deployment does not perform this second scan. -/
def descents {α : Type} [LinearOrder α] : List α → Nat
  | [] | [_] => 0
  | x :: y :: ys => (if x ≤ y then 0 else 1) + descents (y :: ys)

theorem scanTail_run_count {α : Type} [LinearOrder α] (x : α) (xs : List α) :
    (scanTail x xs).eval.ret.2.length = descents (x :: xs) := by
  induction xs generalizing x with
  | nil => rfl
  | cons y ys ih =>
    by_cases h : x ≤ y <;>
      simp [scanTail, Program.eval, Program.eval_bind, descents, h, ih, Nat.add_comm]

/-- Exactly one new run per strict descent: not merely some sorted partition. -/
theorem runCount_eq_descents {α : Type} [LinearOrder α] (xs : List α) :
    runCount xs = if xs = [] then 0 else descents xs + 1 := by
  cases xs with
  | nil => rfl
  | cons x xs => simp [runCount, discover, Program.eval_bind, Program.eval, scanTail_run_count]

theorem runCount_zero_iff {α : Type} [LinearOrder α] (xs : List α) :
    runCount xs = 0 ↔ xs = [] := by
  rw [runCount_eq_descents]
  split_ifs with h <;> simp [h]

theorem length_cost_of_sorted {α : Type} [LinearOrder α] (xs : List α)
    (sorted : xs.Pairwise (· ≤ ·)) :
    (sortProgram lengthPlan xs).eval.time = xs.length - 1 := by
  rw [cost_decomposition, discover_of_sorted xs sorted]
  split_ifs <;> simp [lengthPlan, MergeTree.program, Program.eval]

end LeanSort.RunAdaptive
