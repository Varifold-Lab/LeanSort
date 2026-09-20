import LeanSort.Verification.Bitonic.Network
import LeanSort.Verification.Bitonic.Refinement
import LeanSort.Model.SortingResult

namespace LeanSort.Bitonic

variable {α : Type*} [LinearOrder α]

/-- The actual array network orders every valid block, in either direction. -/
theorem sortNetwork_ordered (d s : Nat) (a : Bool) (xs : Array (Option α))
    (hsize : s + 2 ^ d ≤ xs.size) :
    Functional.Ordered a (wires (sortNetwork d s a xs)) s (2 ^ d) := by
  rw [wires_sortNetwork d s a xs hsize]
  exact Functional.sort_ordered d s a (wires xs)

/-- Sortedness for arbitrary input lengths; sentinels are removed only after sorting. -/
theorem sorted_bitonicSortResult (xs : List α) :
    (bitonicSortResult xs).Pairwise (· ≤ ·) := by
  let ys := sortNetwork (networkDepth xs.length) 0 true (paddedInput xs)
  have hsize : ys.size = 2 ^ networkDepth xs.length := by simp [ys]
  have hs := sortNetwork_ordered (networkDepth xs.length) 0 true (paddedInput xs) (by simp)
  have hp : ys.toList.Pairwise (fun x y => liftPad x ≤ liftPad y) := by
    apply List.pairwise_iff_getElem.mpr
    intro i j hi hj hij
    have hi' : i < ys.size := by simpa using hi
    have hj' : j < ys.size := by simpa using hj
    have h := hs i j (Nat.zero_le _) (Nat.le_of_lt hij) (by simpa [hsize] using hj')
    change wires ys i ≤ wires ys j at h
    rw [wires_get ys i hi', wires_get ys j hj'] at h
    simpa using h
  apply hp.filterMap id
  intro a b hab x hx y hy
  change a = some x at hx
  change b = some y at hy
  subst a
  subst b
  simpa [liftPad] using hab

/-- Full sorting specification for every linearly ordered key type. -/
theorem bitonicSortResult_spec (xs : List α) :
    IsSortingResult (· ≤ ·) xs (bitonicSortResult xs) :=
  ⟨sorted_bitonicSortResult xs, bitonicSortResult_perm xs⟩

theorem replayChecked?_spec (xs output : List α) (steps : List Comparator)
    (h : replayChecked? xs steps = some output) : IsSortingResult (· ≤ ·) xs output := by
  obtain ⟨_, rfl⟩ := (replayChecked?_iff xs output steps).mp h
  exact bitonicSortResult_spec xs

end LeanSort.Bitonic
