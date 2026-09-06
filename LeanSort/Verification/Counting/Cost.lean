import LeanSort.Verification.Counting.Trace

/-!
Logical work in the histogram implementation: one unit per maximum-scan entry,
initialized bucket, recorded increment, enumerated bucket, and emitted entry.
Runtime allocation/copying, trace storage, and the bit cost of natural-number
arithmetic are excluded. This is an explicit operation model, not elapsed time.
-/

namespace LeanSort.Counting

/-- Work of the five loops/phases of counting sort. -/
def countingWorkCost (xs : List ℕ) : ℕ :=
  xs.length + (histogram xs).size + (countingSortTrace xs).length +
    (List.range (histogram xs).size).length + (countingSortResult xs).length

/-- Three input/output passes and two passes over the key range. -/
theorem countingWorkCost_eq (xs : List ℕ) :
    countingWorkCost xs = 3 * xs.length + 2 * keyRange xs := by
  simp only [countingWorkCost, histogram_size, countingSortTrace_length,
    List.length_range, countingSortResult_length]
  omega

theorem countingWorkCost_le (xs : List ℕ) :
    countingWorkCost xs ≤ 3 * (xs.length + keyRange xs) := by
  rw [countingWorkCost_eq]
  omega

theorem length_add_keyRange_le_countingWorkCost (xs : List ℕ) :
    xs.length + keyRange xs ≤ countingWorkCost xs := by
  rw [countingWorkCost_eq]
  omega

end LeanSort.Counting
