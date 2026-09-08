import LeanSort.Model.ComparisonBounds
import LeanSort.Model.SortingResult

namespace LeanSort.CostedPlan

inductive Cut where
  | prefix (size : Nat)
  | fraction (numerator denominator : Nat)
  deriving BEq, Repr, DecidableEq

/-- Evaluated on each current subproblem's length, not on a fixed training list.
Cuts are clipped; denominator zero is interpreted as one. -/
def Cut.position : Cut → Nat → Nat
  | .prefix k, n => min n k
  | .fraction a b, n => min n (n * a / max 1 b)

inductive Component where
  | merge
  | insertion
  | hybrid (threshold : Nat)
  deriving BEq, Repr, DecidableEq

inductive Schema where
  | leaf (component : Component)
  | split (cut : Cut) (left right : Schema)
  | guardSorted (fallback : Schema)
  deriving BEq, Repr, DecidableEq

def Component.upper : Component → Nat → Nat
  | .merge, n => ComparisonBounds.mergeSort n
  | .insertion, n => ComparisonBounds.insertion n
  | .hybrid t, n => ComparisonBounds.hybrid t n

def Schema.upper : Schema → Nat → Nat
  | .leaf c, n => c.upper n
  | .split cut left right, n =>
    left.upper (cut.position n) + right.upper (n - cut.position n) + n
  | .guardSorted fallback, n => (n - 1) + fallback.upper n

/-- All guarded blocks are already nondecreasing. This is a conditional theorem
domain, not an unchecked deployment assumption: guards still execute and are charged. -/
def Schema.Ready {α : Type} [LinearOrder α] : Schema → List α → Prop
  | .leaf _, _ => True
  | .split cut left right, xs =>
    left.Ready (xs.take (cut.position xs.length)) ∧
      right.Ready (xs.drop (cut.position xs.length))
  | .guardSorted _, xs => xs.Pairwise (· ≤ ·)

def Schema.readyUpper : Schema → Nat → Nat
  | .leaf c, n => c.upper n
  | .split cut left right, n =>
    left.readyUpper (cut.position n) + right.readyUpper (n - cut.position n) + n
  | .guardSorted _, n => n - 1

/-- A conservative quadratic coefficient, valid for every finite schema. -/
def Schema.quadraticWeight : Schema → Nat
  | .leaf .merge => 1
  | .leaf .insertion => 1
  | .leaf (.hybrid t) => max 1 t + 1
  | .split _ l r => l.quadraticWeight + r.quadraticWeight + 1
  | .guardSorted p => p.quadraticWeight + 1

/-- Sufficient, not necessary, structural evidence for an O(n log n) envelope.
`none` means this rule is inconclusive, NOT that the algorithm is not O(n log n). -/
def Schema.logWeight : Schema → Option Nat
  | .leaf .merge => some 1
  | .leaf .insertion => none
  | .leaf (.hybrid t) => some (max 1 t + 1)
  | .split _ l r => do return (← l.logWeight) + (← r.logWeight) + 1
  | .guardSorted p => do return (← p.logWeight) + 1

end LeanSort.CostedPlan
