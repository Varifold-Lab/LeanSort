import Mathlib.Data.List.Sort

/-! First-pivot quicksort, using a single partition pass per recursive call. -/

namespace LeanSort.Quick

/-- Partition the tail around its head, recursively sort both parts, then concatenate.
Equal keys go into the left part. This is the deterministic first-pivot variant. -/
def quickSortResult {α : Type*} [LinearOrder α] : List α → List α
  | [] => []
  | pivot :: xs =>
      let parts := xs.partition (fun x => decide (x ≤ pivot))
      quickSortResult parts.1 ++ pivot :: quickSortResult parts.2
termination_by xs => xs.length
decreasing_by
  all_goals
    simp only [List.partition_eq_filter_filter, List.length_cons]
    exact Nat.lt_succ_of_le (List.length_filter_le ..)

end LeanSort.Quick
