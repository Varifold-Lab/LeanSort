import LeanSort.Algorithm.Pancake

/-! # Pancake-sort computation rules -/

namespace LeanSort.Pancake

@[simp] theorem argmax?_nil {α : Type*} [LinearOrder α] :
    argmax? ([] : List α) = none := rfl

theorem argmax?_cons {α : Type*} [LinearOrder α] (x : α) (xs : List α) :
    argmax? (x :: xs) =
      match argmax? xs with
      | none => some (0, x)
      | some (i, value) =>
          if value ≤ x then some (0, x) else some (i + 1, value) := rfl

@[simp] theorem maxIdx_nil {α : Type*} [LinearOrder α] :
    maxIdx ([] : List α) = 0 := rfl

theorem maxIdx_eq_of_argmax?_eq_some {α : Type*} [LinearOrder α]
    {xs : List α} {i : ℕ} {value : α} (h : argmax? xs = some (i, value)) :
    maxIdx xs = i := by
  simp [maxIdx, h]

theorem flip_of_le_length {α : Type*} (k : ℕ) (xs : List α)
    (h : k ≤ xs.length) :
    flip k xs = (xs.take k).reverse ++ xs.drop k := by
  simp [flip, Rearrangement.PrefixReversal.apply, h]

theorem flip_of_length_lt {α : Type*} (k : ℕ) (xs : List α)
    (h : xs.length < k) :
    flip k xs = xs := by
  simp [flip, Rearrangement.PrefixReversal.apply, Nat.not_le.mpr h]

theorem round_eq {α : Type*} [LinearOrder α] (k : ℕ) (xs : List α) :
    round k xs =
      let m := maxIdx (xs.take k)
      if m + 1 = k then (xs, [])
      else if m = 0 then (flip k xs, [k])
      else (flip k (flip (m + 1) xs), [m + 1, k]) := by
  unfold round roundPlan
  dsimp only
  split_ifs <;> rfl

theorem round_of_max_at_end {α : Type*} [LinearOrder α] (k : ℕ) (xs : List α)
    (h : maxIdx (xs.take k) + 1 = k) :
    round k xs = (xs, []) := by
  simp [round_eq, h]

theorem round_of_max_at_head {α : Type*} [LinearOrder α] (k : ℕ) (xs : List α)
    (hend : maxIdx (xs.take k) + 1 ≠ k)
    (hhead : maxIdx (xs.take k) = 0) :
    round k xs = (flip k xs, [k]) := by
  rw [round_eq]
  dsimp only
  rw [ite_eq_right hend, ite_eq_left hhead]

theorem round_of_max_interior {α : Type*} [LinearOrder α] (k : ℕ) (xs : List α)
    (hend : maxIdx (xs.take k) + 1 ≠ k)
    (hhead : maxIdx (xs.take k) ≠ 0) :
    round k xs =
      (flip k (flip (maxIdx (xs.take k) + 1) xs),
        [maxIdx (xs.take k) + 1, k]) := by
  rw [round_eq]
  dsimp only
  rw [ite_eq_right hend, ite_eq_right hhead]

@[simp] theorem sortAux_zero {α : Type*} [LinearOrder α] (xs : List α) :
    sortAux 0 xs = (xs, []) := rfl

theorem sortAux_succ {α : Type*} [LinearOrder α] (k : ℕ) (xs : List α) :
    sortAux (k + 1) xs =
      let (afterRound, word) := round (k + 1) xs
      let (result, rest) := sortAux k afterRound
      (result, word ++ rest) := rfl

theorem sortTrace_eq {α : Type*} [LinearOrder α] (xs : List α) :
    sortTrace xs = sortAux xs.length xs := rfl

@[simp] theorem pancakeSort_eq_sortAux_fst {α : Type*} [LinearOrder α]
    (xs : List α) :
    pancakeSort xs = (sortAux xs.length xs).1 := rfl

@[simp] theorem pancakeSortTrace_eq_sortAux_snd {α : Type*} [LinearOrder α]
    (xs : List α) :
    pancakeSortTrace xs = (sortAux xs.length xs).2 := rfl

end LeanSort.Pancake
