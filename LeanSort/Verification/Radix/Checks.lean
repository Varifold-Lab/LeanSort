import LeanSort.Algorithm.Radix

/-! Regression checks, including all lists of length at most five over {0, 1, 2}. -/

namespace LeanSort.Radix

#guard radixSortResult ([] : List Nat) = []
#guard radixSortResult [7] = [7]
#guard radixSortResult [0, 0, 0] = [0, 0, 0]
#guard radixSortResult [1, 2, 3, 4] = [1, 2, 3, 4]
#guard radixSortResult [4, 3, 2, 1] = [1, 2, 3, 4]
#guard radixSortResult [2, 1, 2, 1] = [1, 1, 2, 2]

#guard digitPass 0 [3, 2, 1, 0, 2, 3] = [2, 0, 2, 3, 1, 3]
#guard radixSortResult [170, 45, 75, 90, 802, 24, 2, 66] =
  [2, 24, 45, 66, 75, 90, 170, 802]
#guard radixSortResult [65536, 255, 0, 256, 65535] = [0, 255, 256, 65535, 65536]

#guard (List.range 6).all fun len =>
  (List.range (3 ^ len)).all fun code =>
    let xs := (List.range len).map (fun i => code / 3 ^ i % 3)
    radixSortResult xs == xs.mergeSort

end LeanSort.Radix
