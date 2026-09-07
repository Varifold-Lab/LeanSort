import LeanSort.Verification.Counting.Cost

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

-- The trace records each input key's new bucket value in input order.
#guard countingSortTrace [2, 1, 2, 0] = [⟨2, 1⟩, ⟨1, 1⟩, ⟨2, 2⟩, ⟨0, 1⟩]
#guard (sortTrace [2, 1, 2, 0]).1 = [0, 1, 2, 2]
#guard replay? [] [] = some []
#guard replay? [2, 1, 2, 0] (countingSortTrace [2, 1, 2, 0]) = some [0, 1, 2, 2]

-- Reject missing/extra updates, the wrong input key, and incorrect counter values.
#guard replay? [1] [] = none
#guard replay? [] [⟨0, 1⟩] = none
#guard replay? [1] [⟨1, 1⟩, ⟨1, 2⟩] = none
#guard replay? [1] [⟨0, 1⟩] = none
#guard replay? [1] [⟨1, 0⟩] = none
#guard replay? [1, 1] [⟨1, 1⟩, ⟨1, 1⟩] = none
#guard replayHistogram? [2] [⟨2, 1⟩] #[0, 0] = none
#guard replayHistogram? [1, 1] [⟨1, 3⟩, ⟨1, 4⟩] #[0, 2] = some #[0, 4]

-- Cost cases distinguish list length from the allocated key range.
#guard countingWorkCost [] = 2
#guard countingWorkCost [7] = 19
#guard countingWorkCost [0, 0, 0] = 11
#guard countingWorkCost [2, 1, 2, 0] = 18
#guard countingWorkCost [1000, 0, 1000, 1] = 2014

#guard (List.range 6).all fun len =>
  (List.range (3 ^ len)).all fun code =>
    let xs := (List.range len).map (fun i => code / 3 ^ i % 3)
    countingSortResult xs == xs.mergeSort &&
      (sortTrace xs).1 == countingSortResult xs &&
      replay? xs (countingSortTrace xs) == some (countingSortResult xs)

end LeanSort.Counting
