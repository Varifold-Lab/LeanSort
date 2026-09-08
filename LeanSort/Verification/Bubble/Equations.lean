import LeanSort.Algorithm.Bubble

namespace LeanSort.Bubble

/-! Computation rules for instrumented bubble sort. -/

/-- One comparison computes the minimum, maximum, and strict inversion decision. -/
theorem compareExchange_spec {α : Type*} [LinearOrder α] (x y : α) :
    (compareExchange x y).lower = min x y ∧
      (compareExchange x y).upper = max x y ∧
      ((compareExchange x y).swapped = true ↔ y < x) := by
  by_cases h : x ≤ y
  · simp [compareExchange, h]
  · simp [compareExchange, h, le_of_not_ge h, lt_of_not_ge h]

@[simp] theorem passAuxTr_nil {α : Type*} [LinearOrder α] (off : ℕ) (x : α) :
    passAuxTr off x [] = ([x], []) := rfl

theorem passAuxTr_cons_of_le {α : Type*} [LinearOrder α] {off : ℕ} {x y : α}
    {ys : List α} (h : x ≤ y) :
    passAuxTr off x (y :: ys) =
      (x :: (passAuxTr (off + 1) y ys).1, (passAuxTr (off + 1) y ys).2) := by
  simp [passAuxTr, compareExchange, h]

theorem passAuxTr_cons_of_gt {α : Type*} [LinearOrder α] {off : ℕ} {x y : α}
    {ys : List α} (h : ¬ x ≤ y) :
    passAuxTr off x (y :: ys) =
      (y :: (passAuxTr (off + 1) x ys).1, off :: (passAuxTr (off + 1) x ys).2) := by
  simp [passAuxTr, compareExchange, h]

@[simp] theorem passTr_nil {α : Type*} [LinearOrder α] (off : ℕ) :
    passTr off ([] : List α) = ([], []) := rfl

@[simp] theorem passTr_cons {α : Type*} [LinearOrder α] (off : ℕ) (x : α)
    (xs : List α) :
    passTr off (x :: xs) = passAuxTr off x xs := rfl

@[simp] theorem sortAuxTr_zero {α : Type*} [LinearOrder α] (xs : List α) :
    sortAuxTr 0 xs = (xs, []) := rfl

theorem sortAuxTr_succ {α : Type*} [LinearOrder α] (passes : ℕ) (xs : List α) :
    sortAuxTr (passes + 1) xs =
      ((sortAuxTr passes (passTr 0 xs).1).1,
        (passTr 0 xs).2 ++ (sortAuxTr passes (passTr 0 xs).1).2) := by
  unfold sortAuxTr
  dsimp only
  rw [Function.iterate_succ_apply']
  rfl

end LeanSort.Bubble
