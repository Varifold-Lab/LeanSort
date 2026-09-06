import LeanSort.Algorithm.Counting

/-! Regression checks, including all lists of length at most five over {0, 1, 2}. -/

namespace LeanSort.Counting

#guard countingSortResult ([] : List Nat) = []
#guard countingSortResult [7] = [7]
#guard countingSortResult [0, 0, 0] = [0, 0, 0]
#guard countingSortResult [1, 2, 3, 4] = [1, 2, 3, 4]
#guard countingSortResult [4, 3, 2, 1] = [1, 2, 3, 4]
#guard countingSortResult [2, 1, 2, 1] = [1, 1, 2, 2]

#guard histogram [2, 1, 2, 0] = #[1, 1, 2]
#guard countingSortResult [1000, 0, 1000, 1] = [0, 1, 1000, 1000]

#guard (List.range 6).all fun len =>
  (List.range (3 ^ len)).all fun code =>
    let xs := (List.range len).map (fun i => code / 3 ^ i % 3)
    countingSortResult xs == xs.mergeSort

end LeanSort.Counting
