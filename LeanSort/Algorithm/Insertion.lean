import LeanSort.Model.Rearrangement
import Mathlib.Control.Monad.Writer

/-!
# Insertion sort, instrumented

Generators here are the adjacent transpositions `sᵢ = (i, i+1)`, the Coxeter generators
of `Sₙ`. The executable algorithm returns both its output and the word of rearrangements
it performs; computation rules and proofs live in `LeanSort.Verification.Insertion`.
-/

namespace LeanSort.Insertion

/-- A generator: `i` denotes the adjacent transposition of positions `i` and `i + 1`. -/
abbrev Gen := Rearrangement.AdjacentTransposition.Gen

universe u

-- ULift lets a natural-number log accompany elements in any universe.
private abbrev TraceM (α : Type u) := Writer (ULift.{u} (List Gen)) α

private instance : Monad TraceM.{u} :=
  WriterT.monad ⟨[]⟩ fun a b => ⟨a.down ++ b.down⟩

private def recorded {α : Type u} (result : α × List Gen) : TraceM α :=
  WriterT.mk (result.map id ULift.up)

private def runTrace {α : Type u} (action : TraceM α) : α × List Gen :=
  action.run.map id ULift.down

/-- Insert `x`, sitting at position `off`, rightwards into the sorted block occupying
positions `off + 1, off + 2, …`. Returns the new block and the generators applied. -/
def insertTr {α : Type*} [LinearOrder α] (off : ℕ) (x : α) : List α → List α × List Gen
  | [] => ([x], [])
  | y :: ys =>
      if x ≤ y then (x :: y :: ys, [])
      else
        let (r, t) := insertTr (off + 1) x ys
        (y :: r, off :: t)

/-- Sort the block occupying positions `off, off + 1, …`: tail first, then insert the head
from position `off`, so the tail's trace comes first. -/
def sortTr {α : Type*} [LinearOrder α] (off : ℕ) : List α → List α × List Gen
  | [] => ([], [])
  | x :: l =>
      runTrace do
        let sortedTail ← recorded (sortTr (off + 1) l)
        recorded (insertTr off x sortedTail)

/-- The word in the Coxeter generators emitted by insertion sort on `l`. -/
def insertionSortTrace {α : Type*} [LinearOrder α] (l : List α) : List Gen :=
  (sortTr 0 l).2

/-- The sorted list produced by the instrumented algorithm. -/
def insertionSortResult {α : Type*} [LinearOrder α] (l : List α) : List α :=
  (sortTr 0 l).1

/-- Apply a word of adjacent transpositions from left to right. -/
def replay {α : Type*} (t : List Gen) (l : List α) : List α :=
  Rearrangement.replay Rearrangement.AdjacentTransposition.apply t l

/-- A valid adjacent swap in a list of length `n`. -/
abbrev SwapIndex (n : ℕ) := Fin (n - 1)

/-- Replay a trace whose indices are certified for this input length. -/
def replayBounded {α : Type*} (xs : List α) (trace : List (SwapIndex xs.length)) : List α :=
  replay (trace.map Fin.val) xs

end LeanSort.Insertion
