import LeanSort.Algorithm.Insertion
import LeanSort.Algorithm.Merge

/-! A parameterized merge/insertion combination on arbitrary finite lists.

Subproblems of length at most `max 1 threshold` use insertion sort. Larger
subproblems are split in half, recursively sorted, and merged using CSlib.
The lower bound of one makes threshold zero safe as well.
-/

namespace LeanSort.HybridMerge

def sort {α : Type} [LinearOrder α] (threshold : Nat) (xs : List α) : List α :=
  if xs.length ≤ max 1 threshold then
    Insertion.insertionSortResult xs
  else
    let middle := xs.length / 2
    (Cslib.Algorithms.Lean.TimeM.merge
      (sort threshold (xs.take middle))
      (sort threshold (xs.drop middle))).ret
termination_by xs.length
decreasing_by all_goals simp_wf; omega

end LeanSort.HybridMerge
