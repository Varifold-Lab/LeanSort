import LeanSort.Algorithm.Merge

/-! Equations for the optional comparison trace. -/

namespace LeanSort.Merge

@[simp] theorem mergeTr_nil_left {α : Type} [LinearOrder α] (ys : List α) :
    mergeTr [] ys = (ys, []) := by rw [mergeTr]

@[simp] theorem mergeTr_nil_right {α : Type} [LinearOrder α] (xs : List α) :
    mergeTr xs [] = (xs, []) := by cases xs <;> simp [mergeTr]

@[simp] theorem sortTrace_of_length_lt_two {α : Type} [LinearOrder α]
    (xs : List α) (h : xs.length < 2) : sortTrace xs = (xs, []) := by
  rw [sortTrace, ite_eq_left h]

end LeanSort.Merge
