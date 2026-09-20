import LeanSort.Algorithm.Bitonic
import Mathlib.Data.List.Perm.Basic

namespace LeanSort.Bitonic

variable {α : Type*} [LinearOrder α]

/-- A comparator preserves every occurrence, including padding sentinels. -/
theorem compareExchange_perm (ascending : Bool) (i j : Nat) (xs : Array (Option α)) :
    (compareExchange ascending i j xs).toList.Perm xs.toList := by
  unfold compareExchange
  split
  · split <;> dsimp only <;> split
    all_goals first | exact .refl _ | exact (Array.swap_perm _ _).toList
  · exact .refl _

theorem compareFold_perm (ascending : Bool) (start half : Nat)
    (indices : List Nat) (xs : Array (Option α)) :
    (indices.foldl (fun a i => compareExchange ascending
      (start + i) (start + half + i) a) xs).toList.Perm xs.toList := by
  induction indices generalizing xs with
  | nil => exact .refl _
  | cons i indices ih =>
    exact (ih _).trans (compareExchange_perm _ _ _ _)

theorem mergeNetwork_perm (depth start : Nat) (ascending : Bool)
    (xs : Array (Option α)) :
    (mergeNetwork depth start ascending xs).toList.Perm xs.toList := by
  induction depth generalizing start xs with
  | zero => exact .refl _
  | succ depth ih =>
    exact (ih _ _).trans ((ih _ _).trans (compareFold_perm _ _ _ _ _))

theorem sortNetwork_perm (depth start : Nat) (ascending : Bool)
    (xs : Array (Option α)) :
    (sortNetwork depth start ascending xs).toList.Perm xs.toList := by
  induction depth generalizing start ascending xs with
  | zero => exact .refl _
  | succ depth ih =>
    exact (mergeNetwork_perm _ _ _ _).trans ((ih _ _ _).trans (ih _ _ _))

@[simp] theorem compareExchange_size (ascending : Bool) (i j : Nat)
    (xs : Array (Option α)) : (compareExchange ascending i j xs).size = xs.size :=
  (compareExchange_perm ascending i j xs).length_eq

@[simp] theorem mergeNetwork_size (depth start : Nat) (ascending : Bool)
    (xs : Array (Option α)) : (mergeNetwork depth start ascending xs).size = xs.size :=
  (mergeNetwork_perm depth start ascending xs).length_eq

@[simp] theorem sortNetwork_size (depth start : Nat) (ascending : Bool)
    (xs : Array (Option α)) : (sortNetwork depth start ascending xs).size = xs.size :=
  (sortNetwork_perm depth start ascending xs).length_eq

/-- Removing padding preserves the input multiset without any distinctness assumption. -/
theorem bitonicSortResult_perm (xs : List α) : (bitonicSortResult xs).Perm xs := by
  have h := (sortNetwork_perm (networkDepth xs.length) 0 true (paddedInput xs)).filterMap
    (f := id)
  simpa [bitonicSortResult, paddedInput, List.filterMap_append,
    List.filterMap_replicate] using h

@[simp] theorem bitonicSortResult_length (xs : List α) :
    (bitonicSortResult xs).length = xs.length := (bitonicSortResult_perm xs).length_eq

theorem length_le_paddedLength (n : Nat) : n ≤ 2 ^ networkDepth n := by
  unfold networkDepth
  split
  · simpa using ‹n ≤ 1›
  · have := Nat.lt_log2_self (n := n - 1)
    omega

omit [LinearOrder α] in
@[simp] theorem paddedInput_size (xs : List α) :
    (paddedInput xs).size = 2 ^ networkDepth xs.length := by
  have := length_le_paddedLength xs.length
  simp [paddedInput]
  omega

end LeanSort.Bitonic
