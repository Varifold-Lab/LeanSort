import LeanSort.Verification.Counting.Cost

/-! Regression checks, including all lists of length at most five over {0, 1, 2}. -/

namespace LeanSort.Counting

#guard [([], []), ([7], [7]), ([0, 0, 0], [0, 0, 0]),
    ([1, 2, 3, 4], [1, 2, 3, 4]), ([4, 3, 2, 1], [1, 2, 3, 4]),
    ([2, 1, 2, 1], [1, 1, 2, 2]), ([1000, 0, 1000, 1], [0, 1, 1000, 1000])].all
  fun (xs, expected) => countingSortResult xs == expected

#guard histogram [2, 1, 2, 0] = #[1, 1, 2]

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

-- Stateful traversal preserves seeded counts and the legacy out-of-range helper behavior.
#guard histogramTraceAux [1, 1] #[0, 2] = (#[0, 4], [⟨1, 3⟩, ⟨1, 4⟩])
#guard histogramTraceAux [2] #[0, 0] = (#[0, 0], [⟨2, 0⟩])
-- A certified key does not make an incorrect counter value acceptable.
#guard replayBounded? [1] [⟨⟨1, by decide⟩, 0⟩] = none

-- Cost cases distinguish list length from the allocated key range.
#guard [([], 2), ([7], 19), ([0, 0, 0], 11),
    ([2, 1, 2, 0], 18), ([1000, 0, 1000, 1], 2014)].all
  fun (xs, expected) => countingWorkCost xs == expected

#guard (List.range 6).all fun len =>
  (List.replicate len [0, 1, 2]).sections.all fun xs =>
    countingSortResult xs == xs.mergeSort &&
      (sortTrace xs).1 == countingSortResult xs &&
      replay? xs (countingSortTrace xs) == some (countingSortResult xs) &&
      replayBounded? xs (countingSortTraceBounded xs) == some (countingSortResult xs)

end LeanSort.Counting
