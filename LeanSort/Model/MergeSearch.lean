import LeanSort.Model.MergeTree

namespace LeanSort.MergeSearch
open RunAdaptive

/-- The empty case plus full alphabetic binary trees. Leaf IDs are run indices. -/
inductive Shape where
  | empty
  | leaf (index : Nat)
  | node (left right : Shape)
  deriving Repr, DecidableEq, BEq

def Shape.indices : Shape → List Nat
  | .empty => []
  | .leaf i => [i]
  | .node l r => l.indices ++ r.indices

def Shape.size (s : Shape) : Nat := s.indices.length

def Shape.weight (w : Nat → Nat) : Shape → Nat
  | .empty => 0
  | .leaf i => w i
  | .node l r => l.weight w + r.weight w

def Shape.budget (w : Nat → Nat) : Shape → Nat
  | .empty | .leaf _ => 0
  | .node l r => l.budget w + r.budget w + l.weight w + r.weight w

/-- Exactly the half-open interval [i,j), with no empty child at a merge. -/
inductive Fits : Shape → Nat → Nat → Prop
  | empty (i) : Fits .empty i i
  | leaf (i) : Fits (.leaf i) i (i+1)
  | node {l r i k j} : i < k → k < j → Fits l i k → Fits r k j →
      Fits (.node l r) i j

def mass (w : Nat → Nat) (i j : Nat) : Nat :=
  ((List.range' i (j-i)).map w).sum

/-- Bellman SUBsolution. It proves a lower bound, not predicted cost. -/
def LowerValid (n : Nat) (w : Nat → Nat) (d : Nat → Nat → Nat) : Prop :=
  (∀ i : Fin (n+1), d i i = 0) ∧
  (∀ i : Fin n, d i (i+1) = 0) ∧
  (∀ i k j : Fin (n+1), i.val < k.val → k.val < j.val →
    d i j ≤ mass w i j + d i k + d k j)

def Optimal (w : Nat → Nat) (n : Nat) (s : Shape) : Prop :=
  Fits s 0 n ∧ ∀ t, Fits t 0 n → s.budget w ≤ t.budget w

end LeanSort.MergeSearch
