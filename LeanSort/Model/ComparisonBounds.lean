import Mathlib.Data.Nat.Choose.Basic
import Mathlib.Data.Nat.Log

namespace LeanSort.ComparisonBounds

def insertion (n : Nat) : Nat := n.choose 2
def mergeSort (n : Nat) : Nat := n * Nat.clog 2 n

/-- A length-only envelope: all leaves use insertion comparisons, all internal
merges cost at most the sum of their input lengths. Threshold zero means one. -/
def hybrid (threshold n : Nat) : Nat :=
  if n ≤ max 1 threshold then insertion n
  else hybrid threshold (n / 2) + hybrid threshold (n - n / 2) + n
termination_by n
decreasing_by all_goals omega

end LeanSort.ComparisonBounds
