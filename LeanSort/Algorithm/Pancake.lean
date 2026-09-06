import LeanSort.Model.Rearrangement

/-!
# Pancake sort

The elementary moves are prefix reversals. Each round moves the largest entry of the
active prefix into its final position.
-/

namespace LeanSort.Pancake

abbrev Gen := Rearrangement.PrefixReversal.Gen

def flip {α : Type*} (k : ℕ) (l : List α) : List α :=
  Rearrangement.PrefixReversal.apply k l

def replay {α : Type*} (word : List Gen) (l : List α) : List α :=
  Rearrangement.replay flip word l

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

/-- Move the largest entry of the first `k` positions into position `k - 1`. -/
def round {α : Type*} [LinearOrder α] (k : ℕ) (l : List α) : List α × List Gen :=
  let m := maxIdx (l.take k)
  if m + 1 = k then (l, [])
  else if m = 0 then (flip k l, [k])
  else (flip k (flip (m + 1) l), [m + 1, k])

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
