import LeanSort.Algorithm.Pancake

namespace LeanSort.Pancake

#guard flip 3 [3, 1, 2, 9] = [2, 1, 3, 9]
#guard replay [3, 2] [3, 1, 2] = [1, 2, 3]

#guard pancakeSort [3, 1, 2] = [1, 2, 3]
#guard pancakeSortTrace [3, 1, 2] = [3, 2]

#guard pancakeSort [5, 4, 3, 2, 1] = [1, 2, 3, 4, 5]
#guard pancakeSort [1, 2, 3, 4, 5] = [1, 2, 3, 4, 5]
#guard pancakeSortTrace [1, 2, 3, 4, 5] = []
#guard pancakeSort [2, 7, 1, 8, 2, 8] = [1, 2, 2, 7, 8, 8]
#guard pancakeSort ([-1, 3, 0] : List Int) = [-1, 0, 3]

#guard replay (pancakeSortTrace [3, 1, 2]) [3, 1, 2] = pancakeSort [3, 1, 2]
#guard replay (pancakeSortTrace [5, 4, 3, 2, 1]) [5, 4, 3, 2, 1] =
  pancakeSort [5, 4, 3, 2, 1]
#guard replay (pancakeSortTrace [2, 7, 1, 8, 2, 8]) [2, 7, 1, 8, 2, 8] =
  pancakeSort [2, 7, 1, 8, 2, 8]
#guard replay (pancakeSortTrace [4, 1, 5, 2, 3]) [4, 1, 5, 2, 3] = [1, 2, 3, 4, 5]

#guard (pancakeSortTrace [4, 1, 5, 2, 3]).all (2 ≤ ·)
#guard (pancakeSortTrace [4, 1, 5, 2, 3]).length ≤ 2 * 5 - 3

end LeanSort.Pancake
