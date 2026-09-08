import LeanSort.Algorithm.Direct.Profile

/-! A closed, versioned catalogue over the FROZEN direct executor.
No new sorting kernel: the extra fixed schemas use the already verified schema
interpreter. Unsupported IDs select Hybrid-8, never arbitrary executable code. -/
namespace LeanSort.LearnedSelection
open RunAdaptive

def fixedThree : CostedPlan.Schema :=
  .split (.fraction 1 3) Direct.checkedMerge Direct.fixedTwo

def candidate : Nat → Strategy
  | 0 => .fixed (.leaf .merge)
  | 1 => .fixed (.leaf (.hybrid 8))
  | 2 => .fixed Direct.fixedTwo
  | 3 => .fixed fixedThree
  | 4 => .fixed Direct.fixedFour
  | 5 => .countBalanced
  | 6 => .lengthBalanced
  | _ => .fixed (.leaf (.hybrid 8))

def validId (id : Int) : Bool := decide (0 ≤ id ∧ id < 7)

def resolve : Option Int → Nat
  | some id => if validId id then id.toNat else 1
  | none => 1

@[noinline] def dispatch {α : Type} [LinearOrder α] (id : Option Int) (xs : List α) : List α :=
  Direct.run (candidate (resolve id)) xs

def kernelCost {α : Type} [LinearOrder α] (id : Option Int) (xs : List α) : Nat :=
  (Direct.runCounted (candidate (resolve id)) xs).time

def kernelBound {α : Type} [LinearOrder α] (id : Option Int) (xs : List α) : Nat :=
  Direct.diagnosticBound (candidate (resolve id)) xs

end LeanSort.LearnedSelection
