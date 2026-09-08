import LeanSort.Algorithm.LearnedSelection.Candidates
import LeanSort.Algorithm.LearnedSelection.Features

namespace LeanSort.LearnedSelection

inductive Tree where
  | leaf (values : List Int)
  | branch (feature threshold : Nat) (left right : Tree)
  deriving Repr, BEq

def Tree.eval (t : Tree) (fs : List Nat) : Option (List Int) :=
  match t with
  | .leaf values => some values
  | .branch feature threshold left right => do
      let value ← fs[feature]?
      if value ≤ threshold then left.eval fs else right.eval fs

def argminAux : List Int → Nat → Nat → Int → Nat
  | [], _, best, _ => best
  | v :: vs, index, best, cost =>
      if v < cost then argminAux vs (index + 1) index v
      else argminAux vs (index + 1) best cost

def argmin (values : List Int) : Option Int :=
  match values with
  | [] => none
  | x :: xs =>
    if values.length = 7 && values.all (fun v => decide (0 ≤ v)) then
      some (Int.ofNat (argminAux xs 1 0 x))
    else none

inductive Model where
  | invalid
  | classifier (tree : Tree)
  | costRanking (tree : Tree)
  deriving Repr, BEq

def Model.predict (model : Model) (fs : List Nat) : Option Int :=
  match model with
  | .invalid => none
  | .classifier tree => do
      let values ← tree.eval fs
      match values with | [id] => some id | _ => none
  | .costRanking tree => do argmin (← tree.eval fs)

/-- Human rules are frozen before training. The length-only rule avoids
sampling; the sample rule deliberately uses the same feature API as models. -/
def sampleRule (fs : List Nat) : Option Int :=
  if fs[0]?.getD 0 ≤ 32 then some 1
  else if fs[2]?.getD 1000 ≤ 125 then some 5 else some 1

inductive Policy where
  | fixed (id : Int)
  | sampledRule
  | lengthRule
  | learned (model : Model)
  deriving Repr, BEq

@[noinline] def select (p : Policy) (xs : List Nat) : Option Int :=
  match p with
  | .fixed id => some id
  | .sampledRule => sampleRule (features xs)
  | .lengthRule => if xs.length ≤ 32 then some 1 else some 5
  | .learned model => model.predict (features xs)

@[noinline] def run (p : Policy) (xs : List Nat) : List Nat := dispatch (select p xs) xs

end LeanSort.LearnedSelection
