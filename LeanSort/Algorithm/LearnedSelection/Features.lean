import LeanSort.Algorithm.Direct.Engine

namespace LeanSort.LearnedSelection
open Comparison Direct

/-- Six integer features: length, probe count, local descents/equalities per
mille, cross-probe descents per mille, sampled left-key range. Sampling uses at
most 16 adjacent pairs spread over the list. List length and walking are O(n),
NOT O(1); all of this happens inside deployment timing. No run reuse. -/
def probePositions (n : Nat) : List Nat :=
  let k := min 16 (n - 1)
  (List.range k).map fun i => i * (n - 2) / max 1 (k - 1)

def probePairs (xs : List Nat) (positions : List Nat) (start : Nat := 0) : List (Nat × Nat) :=
  match positions with
  | [] => []
  | p :: rest => match xs.drop (p - start) with
    | x :: y :: tail => (x, y) :: probePairs (y :: tail) rest (p + 1)
    | _ => []

structure SampleState where
  low : Nat
  high : Nat
  previous : Nat
  seen : Nat := 0
  descents : Nat := 0
  equalities : Nat := 0
  crossDescents : Nat := 0
  deriving Repr, BEq

def initialState (pairs : List (Nat × Nat)) : SampleState :=
  let x := match pairs with | [] => 0 | (x, _) :: _ => x
  ⟨x, x, x, 0, 0, 0, 0⟩

namespace FeatureEngine
variable {m : Type → Type} [Monad m]

@[specialize] def step (cmp : Compare m Nat) (s : SampleState) (pair : Nat × Nat) : m SampleState := do
  let le ← cmp .check pair.1 pair.2
  let ge ← cmp .check pair.2 pair.1
  let lower ← cmp .check pair.1 s.low
  let higher ← cmp .check s.high pair.1
  let cross ← cmp .check s.previous pair.1
  pure ⟨(if lower then pair.1 else s.low),
    (if higher then pair.1 else s.high), pair.1,
    s.seen + 1, s.descents + (if le then 0 else 1),
    s.equalities + (if le && ge then 1 else 0),
    s.crossDescents + (if s.seen = 0 || cross then 0 else 1)⟩

@[specialize] def fold (cmp : Compare m Nat) (s : SampleState) : List (Nat × Nat) → m SampleState
  | [] => pure s
  | p :: rest => do
      let next ← step cmp s p
      fold cmp next rest

def vector (n : Nat) (s : SampleState) : List Nat :=
  [n, s.seen, 1000 * s.descents / max 1 s.seen,
    1000 * s.equalities / max 1 s.seen,
    1000 * s.crossDescents / max 1 (s.seen - 1), s.high - s.low]

@[specialize] def extract (cmp : Compare m Nat) (xs : List Nat) : m (List Nat) := do
  let n := xs.length
  let pairs := probePairs xs (probePositions n)
  let s ← fold cmp (initialState pairs) pairs
  pure (vector n s)

end FeatureEngine

@[noinline] def features (xs : List Nat) : List Nat := FeatureEngine.extract plainCompare xs

/-- Offline instrumentation only. Deployment never calls this projection. -/
def countedFeatures (xs : List Nat) : Result (List Nat) := FeatureEngine.extract countedCompare xs

def featureProgram (xs : List Nat) : Program Nat (List Nat) := FeatureEngine.extract symbolicCompare xs

end LeanSort.LearnedSelection
