import LeanSort.Algorithm.Counting

/-! Histogram expansion always emits nondecreasing keys.
This does not yet establish that the histogram preserves input multiplicities. -/

namespace LeanSort.Counting

theorem sorted_countingSortResult (xs : List ℕ) :
    (countingSortResult xs).Pairwise (· ≤ ·) := by
  unfold countingSortResult
  apply List.pairwise_flatMap.mpr
  constructor
  · intro key _
    simp
  · apply List.pairwise_le_range.imp
    intro a b hab x hx y hy
    have hx' := (List.mem_replicate.mp hx).2
    have hy' := (List.mem_replicate.mp hy).2
    simpa [hx', hy'] using hab

end LeanSort.Counting
