import LeanSort.Model.Rearrangement

/-!
# Selection sort, instrumented

At each position, selection sort finds the leftmost smallest entry in the remaining suffix
and exchanges it with the entry currently at that position. Its elementary moves are
arbitrary swaps of two positions, rather than the adjacent swaps used by insertion and
bubble sort.

This module contains only executable definitions. Their verification lives in
`LeanSort.Verification.Selection`.
-/

namespace LeanSort.Selection

/-- A generator `(i, j)` exchanges the entries at positions `i` and `j`. -/
abbrev Gen := Rearrangement.Transposition.Gen

/-- Apply one arbitrary-position swap. An out-of-range generator acts as the identity. -/
def apply {α : Type*} (move : Gen) (xs : List α) : List α :=
  Rearrangement.Transposition.apply move xs

/-- Apply a word of arbitrary-position swaps from left to right. -/
def replay {α : Type*} (trace : List Gen) (xs : List α) : List α :=
  Rearrangement.replay apply trace xs

/-- `(index, value)` of the leftmost smallest entry, if one exists. -/
def argmin? {α : Type*} [LinearOrder α] : List α → Option (ℕ × α)
  | [] => none
  | x :: xs =>
      match argmin? xs with
      | none => some (0, x)
      | some (i, value) =>
          if x ≤ value then some (0, x) else some (i + 1, value)

/-- Index of the leftmost smallest entry; returns `0` on the empty list. -/
def minIdx {α : Type*} [LinearOrder α] (xs : List α) : ℕ :=
  ((argmin? xs).map Prod.fst).getD 0

/-- Exchange the head `x` with position `i` in `x :: xs`, returning the new head and tail.
An out-of-range index leaves the pair unchanged. -/
def swapHeadAt {α : Type*} (i : ℕ) (x : α) (xs : List α) : α × List α :=
  match i with
  | 0 => (x, xs)
  | j + 1 =>
      match xs[j]? with
      | none => (x, xs)
      | some y => (y, xs.set j x)

/-- Sort a suffix, using `fuel` remaining selection rounds.

The suffix begins at the absolute position `off`, so emitted swap indices refer to the
original whole list. -/
def sortAuxTr {α : Type*} [LinearOrder α] : ℕ → ℕ → List α → List α × List Gen
  | 0, _, xs => (xs, [])
  | _ + 1, _, [] => ([], [])
  | fuel + 1, off, x :: xs =>
      let i := minIdx (x :: xs)
      let (newHead, newTail) := swapHeadAt i x xs
      let (result, trace) := sortAuxTr fuel (off + 1) newTail
      if i = 0 then (newHead :: result, trace)
      else (newHead :: result, (off, off + i) :: trace)

/-- Selection-sort result paired with the arbitrary-swap word produced by the algorithm. -/
def sortTrace {α : Type*} [LinearOrder α] (xs : List α) : List α × List Gen :=
  sortAuxTr xs.length 0 xs

/-- The sorted list produced by traced selection sort. -/
def selectionSortResult {α : Type*} [LinearOrder α] (xs : List α) : List α :=
  (sortTrace xs).1

/-- The word of arbitrary-position swaps emitted by selection sort. -/
def selectionSortTrace {α : Type*} [LinearOrder α] (xs : List α) : List Gen :=
  (sortTrace xs).2

end LeanSort.Selection
