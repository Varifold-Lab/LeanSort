import LeanSort.Algorithm.Insertion

/-! Computation rules for the instrumented insertion-sort definitions. -/

namespace LeanSort.Insertion

@[simp] theorem insertTr_nil {α : Type*} [LinearOrder α] (off : ℕ) (x : α) :
    insertTr off x [] = ([x], []) := rfl

theorem insertTr_cons_of_le {α : Type*} [LinearOrder α] {off : ℕ} {x y : α}
    {ys : List α} (h : x ≤ y) :
    insertTr off x (y :: ys) = (x :: y :: ys, []) := ite_eq_left h

theorem insertTr_cons_of_gt {α : Type*} [LinearOrder α] {off : ℕ} {x y : α}
    {ys : List α} (h : ¬ x ≤ y) :
    insertTr off x (y :: ys) =
      (y :: (insertTr (off + 1) x ys).1, off :: (insertTr (off + 1) x ys).2) :=
  ite_eq_right h

@[simp] theorem sortTr_nil {α : Type*} [LinearOrder α] (off : ℕ) :
    sortTr off ([] : List α) = ([], []) := rfl

theorem sortTr_cons {α : Type*} [LinearOrder α] (off : ℕ) (x : α) (l : List α) :
    sortTr off (x :: l) =
      ((insertTr off x (sortTr (off + 1) l).1).1,
        (sortTr (off + 1) l).2 ++ (insertTr off x (sortTr (off + 1) l).1).2) := rfl

end LeanSort.Insertion
