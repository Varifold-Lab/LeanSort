import LeanSort.Model.Rearrangement
import Mathlib.Control.Monad.Writer
import Mathlib.Logic.Function.Iterate

/-!
# Bubble sort, instrumented

Each pass scans the list from left to right. Whenever two neighboring entries are out of
order, it swaps them and records the corresponding adjacent transposition. Repeating a
pass once per input entry yields bubble sort together with the word of moves it performs.
-/

namespace LeanSort.Bubble

universe u

variable {α : Type u} [LinearOrder α]

/-- A generator `i` exchanges the entries at positions `i` and `i + 1`. -/
abbrev Gen := Rearrangement.AdjacentTransposition.Gen

/-- The left position of an adjacent swap in a list of length `n`. -/
abbrev SwapIndex (n : ℕ) := Fin (n - 1)

/-- Writer logs are lifted so sorting remains polymorphic in the element universe. -/
private abbrev TraceM (β : Type u) := Writer (ULift.{u} (List Gen)) β

private instance : Monad TraceM.{u} :=
  WriterT.monad ⟨[]⟩ fun a b => ⟨a.down ++ b.down⟩

/-- The ordered pair and the decision produced by one comparison. -/
structure CompareExchangeResult (α : Type u) where
  lower : α
  upper : α
  swapped : Bool
  deriving Repr, DecidableEq

/-- Compare once, choosing both output entries and whether to record a swap. -/
def compareExchange (x y : α) : CompareExchangeResult α :=
  if x ≤ y then ⟨x, y, false⟩ else ⟨y, x, true⟩

/-- Continue one left-to-right pass with `x` as the entry currently being carried.

Each step emits the smaller entry and carries the larger one. Trace indices are absolute:
`off` is the position occupied by `x` before the next comparison. -/
def passAuxTr (off : ℕ) (x : α) : List α → List α × List Gen
  | [] => ([x], [])
  | y :: ys =>
      let step := compareExchange x y
      let (result, trace) := passAuxTr (off + 1) step.upper ys
      (step.lower :: result, if step.swapped then off :: trace else trace)

/-- Perform one left-to-right bubble pass on a block beginning at position `off`. -/
def passTr (off : ℕ) : List α → List α × List Gen
  | [] => ([], [])
  | x :: xs => passAuxTr off x xs

/-- Iterate a Writer computation that prepends one full pass to the remaining passes. -/
def sortAuxTr (passes : ℕ) (xs : List α) : List α × List Gen :=
  let prependPass (next : List α → TraceM (List α)) (ys : List α) := do
    let afterPass ← WriterT.mk ((passTr 0 ys).map id ULift.up)
    next afterPass
  ((prependPass^[passes] pure) xs).run.map id ULift.down

/-- Bubble-sort result paired with the adjacent-swap word produced by the algorithm. -/
def sortTrace (xs : List α) : List α × List Gen :=
  sortAuxTr xs.length xs

/-- The sorted list produced by traced bubble sort. -/
def bubbleSortResult (xs : List α) : List α :=
  (sortTrace xs).1

/-- The word of adjacent transpositions emitted by bubble sort. -/
def bubbleSortTrace (xs : List α) : List Gen :=
  (sortTrace xs).2

/-- Apply a word of adjacent transpositions from left to right. -/
def replay (trace : List Gen) (xs : List α) : List α :=
  Rearrangement.replay Rearrangement.AdjacentTransposition.apply trace xs

/-- Replay only indices whose two adjacent positions are within the input. -/
def replayBounded (xs : List α) (trace : List (SwapIndex xs.length)) : List α :=
  replay (trace.map Fin.val) xs

end LeanSort.Bubble
