import LeanSort.Algorithm.Direct.Phases
import LeanSort.Algorithm.Direct.Ablation
import LeanSort.Algorithm.PlanChecks

namespace LeanSort.Direct
open Comparison RunAdaptive

def checkedMerge : CostedPlan.Schema := .guardSorted (.leaf .merge)
def fixedTwo : CostedPlan.Schema := .split (.fraction 1 2) checkedMerge checkedMerge
def fixedFour : CostedPlan.Schema := .split (.fraction 1 2) fixedTwo fixedTwo
def strategies : List Strategy := [.fixed (.leaf .merge), .fixed (.leaf (.hybrid 8)),
  .fixed fixedFour, .countBalanced, .lengthBalanced]

/-- Offline diagnostic only. Kept apart from the proof imports so deployment
does not need to load the real-asymptotics library into its Lean process. -/
def diagnosticBound {α : Type} [LinearOrder α] : Strategy → List α → Nat
  | .fixed p, xs => p.upper xs.length
  | .countBalanced, xs => xs.length - 1 + xs.length * Nat.clog 2 (scan xs).length
  | .lengthBalanced, xs => xs.length - 1 + (lengthPlan (scan xs)).budget

end LeanSort.Direct
