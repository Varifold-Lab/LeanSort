import LeanSort.Algorithm.Heap
import Mathlib.Data.List.Sort
import Mathlib.Data.Nat.Log

/-!
Introsort combines first-pivot quicksort, insertion sort for small partitions,
and heap sort when the partition-depth budget is exhausted. Both recursive
branches receive the decremented budget; it is never reset for a subproblem.

This is a list-based implementation, using the existing array-backed heap sort
as its fallback. It does not claim in-place execution or constant extra space.
Correctness and complexity proofs belong in the verification layer.
-/

namespace LeanSort.Intro

/-- Small partitions use insertion sort while the depth budget is positive. -/
def insertionCutoff : Nat := 16

/-- Twice the integer base-two logarithm of the original input length.
Lean's `Nat.log2` is zero at zero, so empty input also has budget zero. -/
def depthLimit (n : Nat) : Nat := 2 * n.log2

/-- Introsort with an explicit insertion cutoff and partition-depth budget.
Zero budget always delegates to heap sort. With positive budget, small lists
use insertion sort; otherwise the first element is the pivot and ties go left.
The explicit parameters also allow the fallback paths to be exercised directly. -/
def introSortAux {α : Type} [LinearOrder α] (cutoff : Nat) : Nat → List α → List α
  | 0, xs => LeanSort.Heap.heapSortResult xs
  | depth + 1, xs =>
      if xs.length ≤ cutoff then xs.insertionSort (· ≤ ·)
      else
        match xs with
        | [] => []
        | pivot :: rest =>
            let (left, right) := rest.partition (fun x => decide (x ≤ pivot))
            introSortAux cutoff depth left ++ pivot :: introSortAux cutoff depth right

/-- Ascending introsort with a fixed small-partition cutoff and a depth budget
computed once from the original input. Duplicate occurrences are retained. -/
def introSortResult {α : Type} [LinearOrder α] (xs : List α) : List α :=
  introSortAux insertionCutoff (depthLimit xs.length) xs

end LeanSort.Intro
