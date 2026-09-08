import LeanSort.Verification.BudgetSelection.Features

namespace LeanSort.BudgetSelection
open LearnedSelection

#guard features .eight [] == [0,0,0,0,0,0]
#guard features .sixteen [3,2,1] == [3,2,1000,0,0,0]
#guard features .length [3,2,1] == [3,0,0,0,0,0]
#guard (counted .eight (List.range 40)).time == 8
#guard (counted .sixteen (List.range 40)).time == 16
#guard (counted .legacy (List.range 40)).time == 80

private def inputs : Nat → List (List Nat)
  | 0 => [[]]
  | n+1 => (inputs n).flatMap fun xs => [0::xs,1::xs,2::xs]

#guard (List.range 6).all fun n => (inputs n).all fun xs =>
  [FeatureSet.length,.eight,.sixteen,.legacy].all fun f =>
    features f xs == (counted f xs).ret && (counted f xs).time ≤ f.budget &&
      run ⟨f,.learned .invalid⟩ xs == xs.mergeSort

end LeanSort.BudgetSelection
