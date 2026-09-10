import LeanSort.Model.Rearrangement

/-!
# Pancake sort

The elementary moves are prefix reversals. Each round moves the largest entry of the
active prefix into its final position.
`replayChecked?` validates nontrivial prefix lengths before executing a trace.
The verification layer connects those moves to the shrinking active prefix.
-/

namespace LeanSort.Pancake

abbrev Gen := Rearrangement.PrefixReversal.Gen

def flip {α : Type*} (k : ℕ) (l : List α) : List α :=
  Rearrangement.PrefixReversal.apply k l

def replay {α : Type*} (word : List Gen) (l : List α) : List α :=
  Rearrangement.replay flip word l

/-- Replay only nontrivial, in-bounds flips. Acceptance validates the moves;
it does not assert that an arbitrary trace sorts the input. -/
def replayChecked? {α : Type*} : List Gen → List α → Option (List α)
  | [], xs => some xs
  | k :: rest, xs =>
      if 2 ≤ k ∧ k ≤ xs.length then replayChecked? rest (flip k xs) else none

/-- `(index, value)` of the leftmost largest entry, if one exists. -/
def argmax? {α : Type*} [LinearOrder α] : List α → Option (ℕ × α)
  | [] => none
  | x :: l =>
      match argmax? l with
      | none => some (0, x)
      | some (i, v) => if v ≤ x then some (0, x) else some (i + 1, v)

def argmax (l : List ℕ) : ℕ × ℕ := (argmax? l).getD (0, 0)

def maxIdx {α : Type*} [LinearOrder α] (l : List α) : ℕ :=
  ((argmax? l).map Prod.fst).getD 0

/-- A maximum at the end is already fixed; one at the head needs one flip;
otherwise first bring it to the head, then to the end of the active prefix. -/
def roundPlan (k maximumIndex : ℕ) : List Gen :=
  if maximumIndex + 1 = k then []
  else if maximumIndex = 0 then [k]
  else [maximumIndex + 1, k]

/-- Select a maximum, plan its relocation, and execute exactly that plan. -/
def round {α : Type*} [LinearOrder α] (k : ℕ) (l : List α) : List α × List Gen :=
  let word := roundPlan k (maxIdx (l.take k))
  (replay word l, word)

def sortAux {α : Type*} [LinearOrder α] : ℕ → List α → List α × List Gen
  | 0, l => (l, [])
  | k + 1, l =>
      let (l', word) := round (k + 1) l
      let (l'', rest) := sortAux k l'
      (l'', word ++ rest)

def sortTrace {α : Type*} [LinearOrder α] (l : List α) : List α × List Gen :=
  sortAux l.length l

def pancakeSort {α : Type*} [LinearOrder α] (l : List α) : List α :=
  (sortTrace l).1

def pancakeSortTrace {α : Type*} [LinearOrder α] (l : List α) : List Gen :=
  (sortTrace l).2

end LeanSort.Pancake
