import Mathlib.Data.List.Sort

/-! Shared definition of the inversion count. -/

namespace LeanSort

/-- Number of pairs of positions `i < j` with `l[i] > l[j]`. -/
def inversions {α : Type*} [LinearOrder α] : List α → ℕ
  | [] => 0
  | x :: l => l.countP (fun y => decide (y < x)) + inversions l

end LeanSort
