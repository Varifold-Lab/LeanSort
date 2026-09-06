import Mathlib.Data.List.Sort

/-! The common input/output specification of sorting. -/

namespace LeanSort

/-- `output` is a sorted rearrangement of `input` with respect to `r`. -/
def IsSortingResult (r : α → α → Prop) (input output : List α) : Prop :=
  output.Pairwise r ∧ output.Perm input

end LeanSort
