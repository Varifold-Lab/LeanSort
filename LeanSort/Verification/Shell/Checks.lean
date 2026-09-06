import LeanSort.Algorithm.Shell

/-! Regression checks, including all lists of length at most five over {0, 1, 2}. -/

namespace LeanSort.Shell

#guard shellSortResult ([] : List Nat) = []
#guard shellSortResult [7] = [7]
#guard shellSortResult [0, 0, 0] = [0, 0, 0]
#guard shellSortResult [1, 2, 3, 4] = [1, 2, 3, 4]
#guard shellSortResult [4, 3, 2, 1] = [1, 2, 3, 4]
#guard shellSortResult [2, 1, 2, 1] = [1, 1, 2, 2]

#guard gaps 8 = [8, 4, 2, 1]
#guard gaps 0 = []
#guard gapPass 2 #[4, 3, 2, 1] = #[2, 1, 4, 3]
#guard gapPass 0 #[4, 3, 2, 1] = #[4, 3, 2, 1]
#guard gapPass 8 #[4, 3, 2, 1] = #[4, 3, 2, 1]
#guard shellSortResult ([-2, 3, 0, -2] : List Int) = [-2, -2, 0, 3]

#guard (List.range 6).all fun len =>
  (List.range (3 ^ len)).all fun code =>
    let xs := (List.range len).map (fun i => code / 3 ^ i % 3)
    shellSortResult xs == xs.mergeSort

end LeanSort.Shell
