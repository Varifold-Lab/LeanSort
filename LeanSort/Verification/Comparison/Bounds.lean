import LeanSort.Verification.Comparison.Components
import Mathlib.Tactic.Linarith

namespace LeanSort.ComparisonBounds

theorem insertion_le_square (n : Nat) : insertion n ≤ n ^ 2 := by
  rw [insertion, Nat.choose_two_right, pow_two]
  exact (Nat.div_le_self _ _).trans (Nat.mul_le_mul_left n (Nat.sub_le n 1))

theorem clog_two_le_self (n : Nat) : Nat.clog 2 n ≤ n :=
  Nat.clog_le_of_le_pow (Nat.le_of_lt Nat.lt_two_pow_self)

theorem mergeSort_le_square (n : Nat) : mergeSort n ≤ n ^ 2 := by
  simpa only [mergeSort, pow_two] using Nat.mul_le_mul_left n (clog_two_le_self n)

/-- Uniform in length and threshold. A fixed threshold gives a log-linear bound;
allowing the threshold to grow with n does not justify O(n log n). -/
theorem hybrid_le_log_add (threshold n : Nat) :
    hybrid threshold n ≤ n * Nat.clog 2 n + n * max 1 threshold := by
  rw [hybrid]
  split_ifs with h
  · have hi := insertion_le_square n
    have hm := Nat.mul_le_mul_left n h
    nlinarith
  · have hl := hybrid_le_log_add threshold (n / 2)
    have hr := hybrid_le_log_add threshold (n - n / 2)
    have hleft := Cslib.Algorithms.Lean.TimeM.clog2_floor_half_le n (by omega)
    have hright := Cslib.Algorithms.Lean.TimeM.clog2_half_le n (by omega)
    have hhalf : (n + 1) / 2 = n - n / 2 := by omega
    rw [hhalf] at hright
    have hlog : 1 ≤ Nat.clog 2 n := Nat.clog_pos (by omega) (by omega)
    have ha := Nat.mul_le_mul_left (n / 2) hleft
    have hb := Nat.mul_le_mul_left (n - n / 2) hright
    have hsplit : n / 2 + (n - n / 2) = n := by omega
    have heq := Nat.sub_add_cancel hlog
    nlinarith
termination_by n
decreasing_by all_goals omega

theorem hybrid_le_square (threshold n : Nat) :
    hybrid threshold n ≤ (max 1 threshold + 1) * n ^ 2 := by
  have h := hybrid_le_log_add threshold n
  have hlog := Nat.mul_le_mul_left n (clog_two_le_self n)
  have hn : n ≤ n ^ 2 := by nlinarith
  have ht := Nat.mul_le_mul_right (max 1 threshold) hn
  nlinarith

theorem insertion_add (a b : Nat) :
    insertion (a + b) = insertion a + insertion b + a * b := by
  induction a with
  | zero => simp [insertion]
  | succ a ih =>
    change (a + 1 + b).choose 2 = (a + 1).choose 2 + b.choose 2 + (a + 1) * b
    have hleft : a + 1 + b = (a + b) + 1 := by omega
    rw [hleft, Nat.choose_succ_succ (a + b) 1, Nat.choose_succ_succ a 1]
    simp only [Nat.choose_one_right] at *
    change (a + b) + insertion (a + b) = a + insertion a + insertion b + (a + 1) * b
    rw [ih, Nat.add_mul, one_mul]
    omega

end LeanSort.ComparisonBounds

namespace LeanSort.ComparisonSort
open Comparison

/-- A fair sorted-input baseline: insertion itself already needs only n-1
comparisons, so a successful sorted guard is not claimed to improve on it. -/
theorem insertion_cost_of_sorted {α : Type} [LinearOrder α] (xs : List α)
    (sorted : xs.Pairwise (· ≤ ·)) : (insertion xs).eval.time = xs.length - 1 := by
  induction xs with
  | nil => rfl
  | cons x xs ih =>
    have hs := sorted.of_cons
    have he : (insertion xs).eval.ret = xs := by
      rw [insertion_ret, Insertion.insertionSortResult_eq]
      exact hs.insertionSort_eq
    rw [insertion, Program.eval_bind, he, ih hs]
    cases xs with
    | nil => simp [insert, Program.eval]
    | cons y ys =>
      have hxy : x ≤ y := (List.pairwise_cons.mp sorted).1 y (by simp)
      simp [insert, Program.eval, hxy]

end LeanSort.ComparisonSort
