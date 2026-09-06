import LeanSort.Model.Rearrangement

/-!
# Bubble sort, instrumented

Each pass scans the list from left to right. Whenever two neighboring entries are out of
order, it swaps them and records the corresponding adjacent transposition. Repeating a
pass once per input entry yields bubble sort together with the word of moves it performs.
-/

namespace LeanSort.Bubble

/-- A generator `i` exchanges the entries at positions `i` and `i + 1`. -/
abbrev Gen := Rearrangement.AdjacentTransposition.Gen

/-- Continue one left-to-right pass with `x` as the entry currently being carried.

The returned list contains `x` and all of `xs`. Trace indices are absolute: `off` is the
position occupied by `x` before the next comparison. -/
def passAuxTr {α : Type*} [LinearOrder α] (off : ℕ) (x : α) :
    List α → List α × List Gen
  | [] => ([x], [])
  | y :: ys =>
      if x ≤ y then
        let (result, trace) := passAuxTr (off + 1) y ys
        (x :: result, trace)
      else
        let (result, trace) := passAuxTr (off + 1) x ys
        (y :: result, off :: trace)

/-- Perform one left-to-right bubble pass on a block beginning at position `off`. -/
def passTr {α : Type*} [LinearOrder α] (off : ℕ) : List α → List α × List Gen
  | [] => ([], [])
  | x :: xs => passAuxTr off x xs

/-- Repeat full bubble passes. The natural-number argument is the number of passes left. -/
def sortAuxTr {α : Type*} [LinearOrder α] : ℕ → List α → List α × List Gen
  | 0, xs => (xs, [])
  | passes + 1, xs =>
      let (afterPass, passTrace) := passTr 0 xs
      let (result, restTrace) := sortAuxTr passes afterPass
      (result, passTrace ++ restTrace)

/-- Bubble-sort result paired with the adjacent-swap word produced by the algorithm. -/
def sortTrace {α : Type*} [LinearOrder α] (xs : List α) : List α × List Gen :=
  sortAuxTr xs.length xs

/-- The sorted list produced by traced bubble sort. -/
def bubbleSortResult {α : Type*} [LinearOrder α] (xs : List α) : List α :=
  (sortTrace xs).1

/-- The word of adjacent transpositions emitted by bubble sort. -/
def bubbleSortTrace {α : Type*} [LinearOrder α] (xs : List α) : List Gen :=
  (sortTrace xs).2

/-- Apply a word of adjacent transpositions from left to right. -/
def replay {α : Type*} (trace : List Gen) (xs : List α) : List α :=
  Rearrangement.replay Rearrangement.AdjacentTransposition.apply trace xs

end LeanSort.Bubble
