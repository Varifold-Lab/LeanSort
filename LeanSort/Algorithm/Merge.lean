import Cslib.Algorithms.Lean.MergeSort.MergeSort

/-! Merge sort uses CSlib directly. The optional instrumentation records comparison choices. -/

namespace LeanSort.Merge

/-- The sorted result of CSlib's comparison-counting merge sort. -/
def mergeSortResult {α : Type} [LinearOrder α] (xs : List α) : List α :=
  (Cslib.Algorithms.Lean.TimeM.mergeSort xs).ret

/-- One head-to-head comparison during merging. -/
inductive Choice where
  | takeLeft
  | takeRight
  deriving DecidableEq, Repr

/-- Optional instrumentation of a merge, recording each comparison choice. -/
def mergeTr {α : Type} [LinearOrder α] : List α → List α → List α × List Choice
  | [], ys => (ys, [])
  | xs, [] => (xs, [])
  | x :: xs, y :: ys =>
      if x ≤ y then
        let (result, trace) := mergeTr xs (y :: ys)
        (x :: result, Choice.takeLeft :: trace)
      else
        let (result, trace) := mergeTr (x :: xs) ys
        (y :: result, Choice.takeRight :: trace)

/-- Optional instrumentation of merge sort; not used to compute `mergeSortResult`. -/
def sortTrace {α : Type} [LinearOrder α] (xs : List α) : List α × List Choice :=
  if xs.length < 2 then (xs, [])
  else
    let middle := xs.length / 2
    let (leftResult, leftTrace) := sortTrace (xs.take middle)
    let (rightResult, rightTrace) := sortTrace (xs.drop middle)
    let (result, trace) := mergeTr leftResult rightResult
    (result, leftTrace ++ rightTrace ++ trace)

def mergeSortTrace {α : Type} [LinearOrder α] (xs : List α) : List Choice :=
  (sortTrace xs).2

end LeanSort.Merge
