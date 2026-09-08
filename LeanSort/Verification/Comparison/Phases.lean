import LeanSort.Verification.Comparison.Components

namespace LeanSort.Comparison

theorem Program.count_bind {α β γ : Type} [LinearOrder α] (phase : Phase)
    (p : Program α β) (f : β → Program α γ) :
    (p.bind f).count phase = p.count phase + (f p.eval.ret).count phase := by
  induction p with
  | pure x => simp [Program.bind, Program.count, Program.eval]
  | compare tag x y next ih =>
    simp [Program.bind, Program.count, Program.eval, ih, Nat.add_assoc, Nat.add_comm]

end LeanSort.Comparison

namespace LeanSort.ComparisonSort
open Comparison

theorem insert_no_checks {α : Type} [LinearOrder α] (x : α) (xs : List α) :
    (insert x xs).count .check = 0 := by
  induction xs with
  | nil => rfl
  | cons y ys ih =>
    by_cases h : x ≤ y <;> simp [insert, Program.count, Program.count_bind, h, ih]

theorem insertion_no_checks {α : Type} [LinearOrder α] (xs : List α) :
    (insertion xs).count .check = 0 := by
  induction xs with
  | nil => rfl
  | cons x xs ih => simp [insertion, Program.count_bind, insert_no_checks, ih]

theorem merge_no_checks {α : Type} [LinearOrder α] (xs ys : List α) :
    (merge xs ys).count .check = 0 := by
  cases xs with
  | nil => simp [merge, Program.count]
  | cons x xs =>
    cases ys with
    | nil => simp [merge, Program.count]
    | cons y ys =>
      have hl := merge_no_checks xs (y :: ys)
      have hr := merge_no_checks (x :: xs) ys
      by_cases h : x ≤ y <;> simp [merge, Program.count, Program.count_bind, h, hl, hr]
termination_by xs.length + ys.length

theorem mergeSort_no_checks {α : Type} [LinearOrder α] (xs : List α) :
    (mergeSort xs).count .check = 0 := by
  rw [mergeSort]
  split_ifs with h
  · rfl
  · simp only [Program.count_bind, merge_no_checks, Nat.add_zero]
    rw [mergeSort_no_checks (xs.take (xs.length / 2)),
      mergeSort_no_checks (xs.drop (xs.length / 2))]
termination_by xs.length
decreasing_by all_goals simp_wf; omega

theorem hybrid_no_checks {α : Type} [LinearOrder α] (t : Nat) (xs : List α) :
    (hybrid t xs).count .check = 0 := by
  rw [hybrid]
  split_ifs with h
  · exact insertion_no_checks xs
  · simp only [Program.count_bind, merge_no_checks, Nat.add_zero]
    rw [hybrid_no_checks t (xs.take (xs.length / 2)),
      hybrid_no_checks t (xs.drop (xs.length / 2))]
termination_by xs.length
decreasing_by all_goals simp_wf; omega

theorem checkSorted_no_sorting {α : Type} [LinearOrder α] (xs : List α) :
    (checkSorted xs).count .sort = 0 := by
  induction xs with
  | nil => rfl
  | cons x xs ih =>
    cases xs with
    | nil => rfl
    | cons y ys =>
      by_cases h : x ≤ y <;> simp [checkSorted, Program.count, h, ih]

theorem checkSorted_check_count {α : Type} [LinearOrder α] (xs : List α) :
    (checkSorted xs).count .check = (checkSorted xs).eval.time := by
  simpa [checkSorted_no_sorting] using (checkSorted xs).count_partition

end LeanSort.ComparisonSort
