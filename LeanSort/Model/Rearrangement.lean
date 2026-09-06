import Mathlib.Data.List.Sort

/-! Position rearrangements used as elementary moves by sorting algorithms. -/

namespace LeanSort.Rearrangement

/-- Apply a word of elementary moves from left to right. -/
def replay {State Move : Type*} (apply : Move → State → State)
    (word : List Move) (start : State) : State :=
  word.foldl (fun state move => apply move state) start

namespace Transposition

/-- A transposition is represented by the pair of positions it exchanges. -/
abbrev Gen := ℕ × ℕ

/-- Apply one transposition. Out-of-range positions leave the list unchanged. -/
def apply {α : Type*} (move : Gen) (xs : List α) : List α :=
  xs.swap move.1 move.2

end Transposition

namespace AdjacentTransposition

/-- `i` represents the simple transposition exchanging positions `i` and `i + 1`. -/
abbrev Gen := ℕ

/-- Apply one adjacent transposition. -/
def apply {α : Type*} (i : Gen) (xs : List α) : List α :=
  Transposition.apply (i, i + 1) xs

end AdjacentTransposition

namespace PrefixReversal

/-- `k` represents reversal of the first `k` positions. -/
abbrev Gen := ℕ

/-- Reverse the first `k` entries, or do nothing when `k` exceeds the list length. -/
def apply {α : Type*} (k : Gen) (xs : List α) : List α :=
  if k ≤ xs.length then (xs.take k).reverse ++ xs.drop k else xs

end PrefixReversal

end LeanSort.Rearrangement
