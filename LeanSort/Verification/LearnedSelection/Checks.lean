import LeanSort.Verification.LearnedSelection.Features

namespace LeanSort.LearnedSelection

#guard resolve none == 1
#guard resolve (some (-1)) == 1
#guard resolve (some 7) == 1
#guard resolve (some 6) == 6
#guard Model.predict (.classifier (.leaf [99])) [1,2,3] == some 99
#guard resolve (Model.predict (.classifier (.leaf [99])) [1,2,3]) == 1
#guard Model.predict (.classifier (.branch 9 1 (.leaf [0]) (.leaf [5]))) [1,2,3] == none
#guard Model.predict (.costRanking (.leaf [4,3,2,1,2,3,4])) [] == some 3
#guard Model.predict (.costRanking (.leaf [4,3,-1,1,2,3,4])) [] == none
#guard Model.predict (.costRanking (.leaf [1,2])) [] == none
#guard features [] == [0,0,0,0,0,0]
#guard features [7] == [1,0,0,0,0,0]
#guard features [2,1] == [2,1,1000,0,0,0]
#guard (countedFeatures [1,1,3,0,2,2]).time == 25

#guard (List.range 6).all fun n => (List.replicate n [0,1,2]).sections.all fun xs =>
  features xs == (countedFeatures xs).ret &&
  (countedFeatures xs).time == 5 * (probePairs xs (probePositions xs.length)).length &&
  ([none, some (-5)] ++ (List.range 10).map (fun n => some (Int.ofNat n))).all fun id =>
    dispatch id xs == xs.mergeSort && kernelCost id xs ≤ kernelBound id xs

end LeanSort.LearnedSelection
