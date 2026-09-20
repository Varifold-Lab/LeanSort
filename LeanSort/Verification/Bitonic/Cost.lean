import LeanSort.Verification.Bitonic.Trace
import Mathlib.Tactic.Ring

/-! Exact counts of comparator calls, including comparisons with padding.
These are sequential work counts, not measured running times or swap counts. -/

namespace LeanSort.Bitonic

def mergeComparisons : Nat → Nat
  | 0 => 0
  | depth + 1 => 2 ^ depth + 2 * mergeComparisons depth

def sortComparisons : Nat → Nat
  | 0 => 0
  | depth + 1 => 2 * sortComparisons depth + mergeComparisons (depth + 1)

@[simp] theorem mergeSchedule_length (depth start : Nat) (ascending : Bool) :
    (mergeSchedule depth start ascending).length = mergeComparisons depth := by
  induction depth generalizing start with
  | zero => rfl
  | succ depth ih => simp [mergeSchedule, mergeComparisons, ih]; omega

@[simp] theorem sortSchedule_length (depth start : Nat) (ascending : Bool) :
    (sortSchedule depth start ascending).length = sortComparisons depth := by
  induction depth generalizing start ascending with
  | zero => rfl
  | succ depth ih => simp [sortSchedule, sortComparisons, ih]; omega

/-- Division-free closed form, valid even at depth zero. -/
theorem mergeComparisons_exact (depth : Nat) :
    2 * mergeComparisons depth = 2 ^ depth * depth := by
  induction depth with
  | zero => simp [mergeComparisons]
  | succ depth ih =>
    simp only [mergeComparisons, Nat.pow_succ]
    calc
      2 * (2 ^ depth + 2 * mergeComparisons depth) =
          2 * 2 ^ depth + 2 * (2 * mergeComparisons depth) := by ring
      _ = (2 ^ depth * 2) * (depth + 1) := by rw [ih]; ring

/-- For `p = 2^depth` wires the network uses `p * depth * (depth+1) / 4` comparators. -/
theorem sortComparisons_exact (depth : Nat) :
    4 * sortComparisons depth = 2 ^ depth * depth * (depth + 1) := by
  induction depth with
  | zero => simp [sortComparisons]
  | succ depth ih =>
    calc
      4 * sortComparisons (depth + 1) =
          2 * (4 * sortComparisons depth) + 2 * (2 * mergeComparisons (depth + 1)) := by
        rw [sortComparisons]; ring
      _ = 2 ^ (depth + 1) * (depth + 1) * (depth + 1 + 1) := by
        rw [ih, mergeComparisons_exact, Nat.pow_succ]; ring

theorem sortComparisons_eq (depth : Nat) :
    sortComparisons depth = 2 ^ depth * depth * (depth + 1) / 4 := by
  rw [← sortComparisons_exact]; omega

end LeanSort.Bitonic
