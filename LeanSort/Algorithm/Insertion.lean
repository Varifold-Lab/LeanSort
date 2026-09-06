import LeanSort.Model.Rearrangement

/-!
# Insertion sort, instrumented

Generators here are the adjacent transpositions `sᵢ = (i, i+1)`, the Coxeter generators
of `Sₙ`. The executable algorithm returns both its output and the word of rearrangements
it performs; computation rules and proofs live in `LeanSort.Verification.Insertion`.
-/

namespace LeanSort.Insertion

/-- A generator: `i` denotes the adjacent transposition of positions `i` and `i + 1`. -/
abbrev Gen := Rearrangement.AdjacentTransposition.Gen

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
      let (s, t₁) := sortTr (off + 1) l
      let (r, t₂) := insertTr off x s
      (r, t₁ ++ t₂)

/-- The word in the Coxeter generators emitted by insertion sort on `l`. -/
def insertionSortTrace {α : Type*} [LinearOrder α] (l : List α) : List Gen :=
  (sortTr 0 l).2

/-- The sorted list produced by the instrumented algorithm. -/
def insertionSortResult {α : Type*} [LinearOrder α] (l : List α) : List α :=
  (sortTr 0 l).1

/-- Apply a word of adjacent transpositions from left to right. -/
def replay {α : Type*} (t : List Gen) (l : List α) : List α :=
  Rearrangement.replay Rearrangement.AdjacentTransposition.apply t l

end LeanSort.Insertion
