import LeanSort.Algorithm.Direct.Executor

namespace LeanSort.Direct
open Comparison RunAdaptive

/-- Diagnostic replay only, never called by uncounted deployment. -/
def phaseCompare {α : Type} [LinearOrder α] (selected : Phase) : Compare Result α :=
  fun phase x y => ⟨decide (x ≤ y), if phase = selected then 1 else 0⟩

def runPhase {α : Type} [LinearOrder α] (phase : Phase) (s : Strategy) (xs : List α) : Result (List α) :=
  Engine.strategy (phaseCompare phase) s xs

end LeanSort.Direct
