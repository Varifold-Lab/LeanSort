import LeanSort.Verification.RunAdaptive.Strategy
open LeanSort LeanSort.RunAdaptive
def frozenHybrid : Strategy := .fixed (.leaf (.hybrid 8))
theorem frozen_correct (xs : List Nat) : IsSortingResult (· ≤ ·) xs (frozenHybrid.run xs) :=
  frozenHybrid.correct xs
theorem frozen_cost (xs : List Nat) : (frozenHybrid.program xs).eval.time ≤ frozenHybrid.bound xs :=
  frozenHybrid.cost_bound xs
#print axioms frozen_correct
#print axioms frozen_cost
