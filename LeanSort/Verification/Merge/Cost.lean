import LeanSort.Algorithm.Merge

/-! Comparison cost supplied by CSlib's TimeM; excludes splitting and allocation. -/

namespace LeanSort.Merge

/-- Number of comparisons, not total execution time or memory usage. -/
def mergeComparisonCost {α : Type} [LinearOrder α] (xs : List α) : ℕ :=
  (Cslib.Algorithms.Lean.TimeM.mergeSort xs).time

theorem mergeComparisonCost_le_length_mul_clog_two
    {α : Type} [LinearOrder α] (xs : List α) :
    mergeComparisonCost xs ≤ xs.length * Nat.clog 2 xs.length :=
  Cslib.Algorithms.Lean.TimeM.mergeSort_time xs

end LeanSort.Merge
