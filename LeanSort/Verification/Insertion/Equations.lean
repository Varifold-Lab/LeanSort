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

/-- Insertion crosses the initial block below `x`, emitting exactly that interval
of adjacent swaps. This equation also holds when the input block is not sorted. -/
theorem insertTr_split {α : Type*} [LinearOrder α] (off : ℕ) (x : α) (s : List α) :
    insertTr off x s =
      (s.takeWhile (fun y => decide (y < x)) ++ x :: s.dropWhile (fun y => decide (y < x)),
        List.range' off (s.takeWhile (fun y => decide (y < x))).length) := by
  induction s generalizing off with
  | nil => rfl
  | cons y ys ih =>
    by_cases h : x ≤ y
    · simp [insertTr_cons_of_le h, not_lt_of_ge h]
    · simp [insertTr_cons_of_gt h, lt_of_not_ge h, ih, List.range'_succ]

theorem insertTr_trace {α : Type*} [LinearOrder α] (off : ℕ) (x : α) (s : List α) :
    (insertTr off x s).2 = List.range' off (s.takeWhile (fun y => decide (y < x))).length :=
  congrArg Prod.snd (insertTr_split off x s)

end LeanSort.Insertion
