import LeanSort.Algorithm.LearnedSelection.Model

namespace LeanSort.BudgetSelection
open Comparison Direct LearnedSelection

inductive FeatureSet where
  | length | eight | sixteen | legacy
  deriving Repr, BEq, DecidableEq

def FeatureSet.budget : FeatureSet → Nat
  | .length => 0 | .eight => 8 | .sixteen => 16 | .legacy => 80

def positions (budget n : Nat) : List Nat :=
  let k := min budget (n - 1)
  (List.range k).map fun i => i * (n - 2) / max 1 (k - 1)

namespace Engine
variable {m : Type → Type} [Monad m]

/-- One key comparison per probe. The two accumulators are metadata. -/
@[specialize] def fold (cmp : Compare m Nat) (seen desc : Nat) : List (Nat × Nat) → m (Nat × Nat)
  | [] => pure (seen, desc)
  | (x,y) :: ps => do
      let le ← cmp .check x y
      fold cmp (seen + 1) (desc + if le then 0 else 1) ps

/-- List.length plus a monotone walk to spread probes, not random-access O(1).
Zero slots mean unavailable features, never generator-derived information. -/
@[specialize] def extract (cmp : Compare m Nat) (budget : Nat) (xs : List Nat) : m (List Nat) := do
  let n := xs.length
  let ps := probePairs xs (positions budget n)
  let (seen,desc) ← fold cmp 0 0 ps
  pure [n, seen, 1000 * desc / max 1 seen, 0, 0, 0]

@[specialize] def feature (cmp : Compare m Nat) (kind : FeatureSet) (xs : List Nat) : m (List Nat) :=
  match kind with
  | .legacy => FeatureEngine.extract cmp xs
  | _ => extract cmp kind.budget xs

end Engine

@[noinline] def features (kind : FeatureSet) (xs : List Nat) : List Nat :=
  Engine.feature plainCompare kind xs
def counted (kind : FeatureSet) (xs : List Nat) : Result (List Nat) :=
  Engine.feature countedCompare kind xs
def symbolic (kind : FeatureSet) (xs : List Nat) : Program Nat (List Nat) :=
  Engine.feature symbolicCompare kind xs

inductive Choice where
  | fixed (id : Int)
  | rule (lengthCut descentCut : Nat)
  | learned (model : Model)
  deriving Repr, BEq

def choose (p : Choice) (fs : List Nat) : Option Int :=
  match p with
  | .fixed id => some id
  | .rule lengthCut descentCut =>
      if fs[0]?.getD 0 ≤ lengthCut then some 1
      else if fs[2]?.getD 1000 ≤ descentCut then some 5 else some 1
  | .learned m => m.predict fs

structure Policy where
  featureSet : FeatureSet
  choice : Choice
  deriving Repr, BEq

@[noinline] def select (p : Policy) (xs : List Nat) : Option Int :=
  match p.choice with
  | .fixed id => some id
  | _ => choose p.choice (features p.featureSet xs)

@[noinline] def run (p : Policy) (xs : List Nat) : List Nat :=
  dispatch (select p xs) xs

end LeanSort.BudgetSelection
