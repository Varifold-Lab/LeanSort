import LeanSort.Algorithm.LearnedSelection.Model
import LeanSort.Verification.Direct.Refinement

namespace LeanSort.LearnedSelection

/-- Any model output, including unsupported IDs or failure, has a proved
dispatch. No assertion about choosing the fastest candidate is made. -/
theorem dispatch_correct {α : Type} [LinearOrder α] (id : Option Int) (xs : List α) :
    IsSortingResult (· ≤ ·) xs (dispatch id xs) :=
  Direct.correct (candidate (resolve id)) xs

theorem arbitrary_selector_correct {α : Type} [LinearOrder α]
    (choose : List α → Option Int) (xs : List α) :
    IsSortingResult (· ≤ ·) xs (dispatch (choose xs) xs) := dispatch_correct _ _

theorem run_correct (p : Policy) (xs : List Nat) :
    IsSortingResult (· ≤ ·) xs (run p xs) := dispatch_correct _ _

theorem fallback_correct {α : Type} [LinearOrder α] (xs : List α) :
    IsSortingResult (· ≤ ·) xs (dispatch none xs) := dispatch_correct _ _

theorem invalid_fallback {α : Type} [LinearOrder α] (id : Int) (xs : List α)
    (h : validId id = false) :
    dispatch (some id) xs = Direct.run (.fixed (.leaf (.hybrid 8))) xs := by
  simp [dispatch, resolve, h, candidate]

theorem kernel_bound {α : Type} [LinearOrder α] (id : Option Int) (xs : List α) :
    kernelCost id xs ≤ kernelBound id xs := by
  simpa only [kernelCost, kernelBound, Direct.diagnostic_bound_eq] using
    Direct.cost_bound (candidate (resolve id)) xs

theorem kernel_execution {α : Type} [LinearOrder α] (id : Option Int) (xs : List α) :
    Direct.Execution (candidate (resolve id)) xs (dispatch id xs) (kernelCost id xs) :=
  Direct.uncounted_execution _ _

structure Certificate where
  algorithm : RunAdaptive.Strategy
  correct : ∀ {α : Type} [LinearOrder α] (xs : List α),
    IsSortingResult (· ≤ ·) xs (Direct.run algorithm xs)
  cost : ∀ {α : Type} [LinearOrder α] (xs : List α),
    (Direct.runCounted algorithm xs).time ≤ Direct.diagnosticBound algorithm xs

def certificate (id : Nat) : Certificate where
  algorithm := candidate id
  correct := Direct.correct _
  cost xs := by simpa only [Direct.diagnostic_bound_eq] using Direct.cost_bound (candidate id) xs

/-- Seven theorem-backed entries, not automatically discovered properties. -/
def catalogue : List Certificate := (List.range 7).map certificate

end LeanSort.LearnedSelection
