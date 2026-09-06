import Mathlib.Data.List.Sort

/-! Bounds for the maximum-key scan used by counting and radix sort. -/

namespace LeanSort

theorem le_foldl_max (xs : List ℕ) (initial : ℕ) : initial ≤ xs.foldl max initial := by
  induction xs generalizing initial with
  | nil => rfl
  | cons x xs ih => exact (Nat.le_max_left initial x).trans (ih (max initial x))

theorem mem_le_foldl_max (xs : List ℕ) (initial x : ℕ) (hx : x ∈ xs) :
    x ≤ xs.foldl max initial := by
  induction xs generalizing initial with
  | nil => simp at hx
  | cons y xs ih =>
      rcases List.mem_cons.mp hx with rfl | hx
      · exact (Nat.le_max_right initial x).trans (le_foldl_max xs (max initial x))
      · exact ih (max initial y) hx

theorem foldl_max_le (xs : List ℕ) (initial bound : ℕ)
    (hi : initial ≤ bound) (hx : ∀ x ∈ xs, x ≤ bound) : xs.foldl max initial ≤ bound := by
  induction xs generalizing initial with
  | nil => exact hi
  | cons x xs ih =>
      exact ih (max initial x) (max_le hi (hx x (by simp)))
        (fun y hy => hx y (by simp [hy]))

end LeanSort
