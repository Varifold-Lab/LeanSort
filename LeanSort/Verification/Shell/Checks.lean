import LeanSort.Verification.Shell.Complexity

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

-- Odd sizes and gaps exercise rounding in the halving sequence.
#guard gaps 7 = [7, 3, 1]
#guard shellSortResult [9, 8, 7, 6, 5, 4, 3, 2, 1] = [1, 2, 3, 4, 5, 6, 7, 8, 9]
#guard gapPass 3 #[9, 8, 7, 6, 5, 4, 3, 2, 1] = #[3, 2, 1, 6, 5, 4, 9, 8, 7]
#guard (gapInsertTrace 0 #[3, 2, 1] 2).2 = []
#guard (gapInsertTrace 1 #[3, 2, 1] 3).2 = []
#guard shellSortTrace ([] : List Nat) = []
#guard shellSortTrace [7] = []
#guard shellSortTrace [1, 2, 3, 4] = []
#guard shellSortTrace [0, 0, 0] = []
#guard shellSortTrace [4, 3, 2, 1] = [(2, 0), (3, 1), (1, 0), (3, 2)]
#guard shellSwapCost [4, 3, 2, 1] = 4
#guard replay (shellSortTrace [4, 3, 2, 1]) [4, 3, 2, 1] = [1, 2, 3, 4]
#guard replay [(10, 0)] [3, 2, 1] = [3, 2, 1]
#guard replay [(0, 0)] [3, 2, 1] = [3, 2, 1]
#guard (sortTrace ([-2, 3, 0, -2] : List Int)).1 = [-2, -2, 0, 3]

example {α : Type*} [LinearOrder α] (xs : List α) :
    LeanSort.IsSortingResult (· ≤ ·) xs (shellSortResult xs) := shellSortResult_spec xs

#guard (List.range 6).all fun len =>
  (List.range (3 ^ len)).all fun code =>
    let xs := (List.range len).map (fun i => code / 3 ^ i % 3)
    shellSortResult xs == xs.mergeSort &&
      (sortTrace xs).1 == shellSortResult xs &&
      replay (shellSortTrace xs) xs == shellSortResult xs &&
      decide (shellSwapCost xs ≤ 2 * xs.length ^ 2)

end LeanSort.Shell
