import LeanSort.Algorithm.Direct.Executor

namespace LeanSort.Direct
open Comparison RunAdaptive

/-- Operational cost semantics of the uncounted executor: instantiate its SAME
Engine body with a symbolic primitive that records each key comparison, including
its operands, phase and both continuations. Not inferred from output equality.
The symbolic computation is a specification, never evaluated by `Direct.run`.
-/
def Execution {α : Type} [LinearOrder α] (s : Strategy) (xs out : List α) (cost : Nat) : Prop :=
  Executes (Engine.strategy symbolicCompare s xs) out cost

end LeanSort.Direct
