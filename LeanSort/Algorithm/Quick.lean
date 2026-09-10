import Mathlib.Data.List.Sort

/-! First-pivot quicksort, using a single partition pass per recursive call. -/

namespace LeanSort.Quick

/-- One scan produces both stable partitions and their comparison decisions.
Each input occurrence is compared exactly once; ties go left. -/
def partitionTr {α : Type*} [LinearOrder α] (pivot : α) :
    List α → (List α × List α) × List Bool
  | [] => (([], []), [])
  | x :: xs =>
      let rest := partitionTr pivot xs
      if x ≤ pivot then ((x :: rest.1.1, rest.1.2), true :: rest.2)
      else ((rest.1.1, x :: rest.1.2), false :: rest.2)

/-- A recursion tree records each comparison decision in input order.
`true` sends a key to the left (including ties); `false` sends it right.
Empty leaves distinguish empty calls from singleton pivot calls. -/
inductive Trace where
  | empty
  | node (decisions : List Bool) (left right : Trace)
  deriving DecidableEq, Repr

/-- Instrumented first-pivot execution; recursive boundaries remain explicit. -/
def quickSortTr {α : Type*} [LinearOrder α] : List α → List α × Trace
  | [] => ([], .empty)
  | pivot :: xs =>
      let parts := partitionTr pivot xs
      let left := quickSortTr parts.1.1
      let right := quickSortTr parts.1.2
      (left.1 ++ pivot :: right.1,
        .node parts.2 left.2 right.2)
termination_by xs => xs.length
decreasing_by
  all_goals
    have bounds : ∀ ys : List α, (partitionTr pivot ys).1.1.length ≤ ys.length ∧
        (partitionTr pivot ys).1.2.length ≤ ys.length := by
      intro ys
      induction ys with
      | nil => simp [partitionTr]
      | cons x xs ih =>
          obtain ⟨hl, hr⟩ := ih
          simp only [partitionTr]
          split <;> simp only [List.length_cons] <;> omega
    simp only [List.length_cons]
    have := bounds xs
    omega

/-- The public result is a projection of the same execution that emits the trace. -/
def quickSortResult {α : Type*} [LinearOrder α] (xs : List α) : List α :=
  (quickSortTr xs).1

/-- Checked replay validates every comparison and recursive boundary.
It re-executes partitioning; it does not trust supplied decisions. -/
def replayChecked? {α : Type*} [LinearOrder α] : Trace → List α → Option (List α)
  | .empty, [] => some []
  | .node decisions left right, pivot :: xs =>
      let parts := partitionTr pivot xs
      if decisions = parts.2 then
        match replayChecked? left parts.1.1, replayChecked? right parts.1.2 with
        | some l, some r => some (l ++ pivot :: r)
        | _, _ => none
      else none
  | _, _ => none

/-- Key comparisons only: one per non-pivot key in each partition. -/
def Trace.comparisons : Trace → Nat
  | .empty => 0
  | .node decisions left right => decisions.length + left.comparisons + right.comparisons

/-- Number of nonempty recursive calls, equivalently pivot occurrences. -/
def Trace.pivots : Trace → Nat
  | .empty => 0
  | .node _ left right => left.pivots + 1 + right.pivots

end LeanSort.Quick
