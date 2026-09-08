import LeanSort.Algorithm.HybridMerge
import LeanSort.Verification.Insertion.Correctness

/-! Universal correctness of the hybrid family, independent of threshold choice.
This proves sortedness and permutation, not stability or a runtime bound.
-/

namespace LeanSort.HybridMerge

theorem sort_spec {α : Type} [LinearOrder α] (threshold : Nat) (xs : List α) :
    IsSortingResult (· ≤ ·) xs (sort threshold xs) := by
  rw [sort]
  split
  · exact Insertion.insertionSortResult_spec xs
  · dsimp only
    have left := sort_spec threshold (xs.take (xs.length / 2))
    have right := sort_spec threshold (xs.drop (xs.length / 2))
    refine ⟨Cslib.Algorithms.Lean.TimeM.sorted_merge left.1 right.1, ?_⟩
    exact (Cslib.Algorithms.Lean.TimeM.merge_perm _ _).trans
      (by simpa only [List.take_append_drop] using left.2.append right.2)
termination_by xs.length
decreasing_by all_goals simp_wf; omega

/-- Any total selector is safe for correctness, even if it predicts poorly.
Its own cost and the resulting sorting cost are not bounded by this theorem. -/
theorem selected_sort_spec {α : Type} [LinearOrder α]
    (choose : List α → Nat) (xs : List α) :
    IsSortingResult (· ≤ ·) xs (sort (choose xs) xs) :=
  sort_spec (choose xs) xs

end LeanSort.HybridMerge
