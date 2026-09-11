import LeanSort.Algorithm.Selection

/-! # Selection sort computation rules -/

namespace LeanSort.Selection

@[simp] theorem argmin?_nil {α : Type*} [LinearOrder α] :
    argmin? ([] : List α) = none := rfl

theorem argmin?_cons {α : Type*} [LinearOrder α] (x : α) (xs : List α) :
    argmin? (x :: xs) =
      match argmin? xs with
      | none => some (0, x)
      | some (i, value) =>
          if x ≤ value then some (0, x) else some (i + 1, value) := rfl

@[simp] theorem swapHeadAt_zero {α : Type*} (x : α) (xs : List α) :
    swapHeadAt 0 x xs = (x, xs) := rfl

theorem swapHeadAt_succ {α : Type*} (i : ℕ) (x : α) (xs : List α) :
    swapHeadAt (i + 1) x xs =
      match xs[i]? with
      | none => (x, xs)
      | some y => (y, xs.set i x) := rfl

@[simp] theorem sortAuxTr_zero {α : Type*} [LinearOrder α] (off : ℕ) (xs : List α) :
    sortAuxTr 0 off xs = (xs, []) := rfl

@[simp] theorem sortAuxTr_succ_nil {α : Type*} [LinearOrder α] (fuel off : ℕ) :
    sortAuxTr (fuel + 1) off ([] : List α) = ([], []) := rfl

theorem sortAuxTr_succ_cons {α : Type*} [LinearOrder α] (fuel off : ℕ)
    (x : α) (xs : List α) :
    sortAuxTr (fuel + 1) off (x :: xs) =
      let i := minIdx (x :: xs)
      let (newHead, newTail) := swapHeadAt i x xs
      let (result, trace) := sortAuxTr fuel (off + 1) newTail
      if i = 0 then (newHead :: result, trace)
      else (newHead :: result, (off, off + i) :: trace) := by
  simp only [sortAuxTr, round]
  split <;> simp

end LeanSort.Selection
