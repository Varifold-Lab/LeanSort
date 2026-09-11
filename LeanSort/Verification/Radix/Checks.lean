import LeanSort.Verification.Radix.Complexity
import LeanSort.Verification.Radix.Semantics

/-! Regression checks, including all lists of length at most five over {0, 1, 2}. -/

namespace LeanSort.Radix

-- Rules can derive a pass directly, including stable order inside each bucket.
example : PartitionDerivation 0 [3, 2, 1, 0] [2, 0] [3, 1]
    [false, true, false, true] :=
  .one (by decide) (.zero (by decide) (.one (by decide) (.zero (by decide) .nil)))

example : DigitDerivation 0 [2, 1] ⟨0, [true, false]⟩ [2, 1] :=
  .join (.zero (by decide) (.one (by decide) .nil))

-- A legal pass need not fully sort: the invariant refers to processed low bits.
#guard replayDigit 0 [2, 1] ⟨0, [true, false]⟩ = some [2, 1]
#guard passesTrace [1, 0] [3, 2, 1, 0] =
  ([0, 2, 1, 3], [⟨1, [false, false, true, true]⟩, ⟨0, [false, true, false, true]⟩])
#guard replayPasses [1, 0] [3, 2, 1, 0] (passesTrace [1, 0] [3, 2, 1, 0]).2 =
  some [0, 2, 1, 3]
#guard replay [3, 2, 1, 0] (passesTrace [1, 0] [3, 2, 1, 0]).2 = none
#guard (radixSortCertificate []).trace = [⟨0, []⟩]
#guard (radixSortCertificate [0, 0]).trace = [⟨0, [true, true]⟩]

example (xs : List ℕ) :
    LeanSort.IsSortingResult (· ≤ ·) xs (radixSortCertificate xs).output :=
  (radixSortCertificate xs).spec

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

-- Crossing a power of two adds a pass; zero and empty inputs still use one.
#guard radixBits [] = 1
#guard radixBits [0, 0] = 1
#guard radixBits [7] = 3
#guard radixBits [8] = 4
#guard radixSortResult [16, 15, 8, 7, 4, 3, 2, 1, 0, 16] =
  [0, 1, 2, 3, 4, 7, 8, 15, 16, 16]
#guard (sortTrace [3, 2, 1, 0]).1 = [0, 1, 2, 3]
#guard radixSortTrace [3, 2, 1, 0] =
  [⟨0, [false, true, false, true]⟩, ⟨1, [false, true, false, true]⟩]
#guard digitTests [3, 2, 1, 0] = 8
#guard digitTests [] = 0
#guard replay [] (radixSortTrace []) = some []
#guard replay [0, 0] (radixSortTrace [0, 0]) = some [0, 0]
#guard replay [3, 2, 1, 0] (radixSortTrace [3, 2, 1, 0]) = some [0, 1, 2, 3]

-- Distinguish digit tests from scan/partition/append work.
#guard passesWithWork [0, 1] [3, 2, 1, 0] = ([0, 1, 2, 3], 12)
#guard sortWithWork [3, 2, 1, 0] = ([0, 1, 2, 3], 16)
#guard radixWorkCost [] = 0 -- no charged element visits, not zero elapsed time
#guard radixWorkCost [0, 0] = 6
#guard radixWorkCost [7] = 4
#guard radixWorkCost [8] = 8

-- Reject a wrong bit, wrong bucket, truncated choices, and surplus choices.
#guard replayDigit 0 [2, 1] ⟨1, [true, false]⟩ = none
#guard replayDigit 0 [2, 1] ⟨0, [false, false]⟩ = none
#guard replayDigit 0 [2, 1] ⟨0, [true]⟩ = none
#guard replayDigit 0 [2, 1] ⟨0, [true, false, true]⟩ = none
-- Reject missing, extra, and reordered rounds.
#guard replay [3, 2, 1, 0] ((radixSortTrace [3, 2, 1, 0]).take 1) = none
#guard replay [3, 2, 1, 0] (radixSortTrace [3, 2, 1, 0] ++ [⟨2, []⟩]) = none
#guard replay [3, 2, 1, 0] (radixSortTrace [3, 2, 1, 0]).reverse = none
#guard replay [] [] = none

example (xs : List ℕ) : LeanSort.IsSortingResult (· ≤ ·) xs (radixSortResult xs) :=
  radixSortResult_spec xs

-- Output correctness and work bounds refer to the same costed execution.
example (xs : List ℕ) :
    LeanSort.IsSortingResult (· ≤ ·) xs (sortWithWork xs).1 ∧
      xs.length * radixBits xs ≤ radixWorkCost xs ∧
      radixWorkCost xs ≤ 3 * (xs.length * radixBits xs) := by
  constructor
  · rw [sortWithWork_result]
    exact radixSortResult_spec xs
  · exact radixWorkCost_bounds xs

#guard (List.range 6).all fun len =>
  (List.range (3 ^ len)).all fun code =>
    let xs := (List.range len).map (fun i => code / 3 ^ i % 3)
    radixSortResult xs == xs.mergeSort &&
      (sortTrace xs).1 == radixSortResult xs &&
      replay xs (radixSortTrace xs) == some (radixSortResult xs) &&
      digitTests xs == xs.length * radixBits xs &&
      (radixSortCertificate xs).trace.map DigitStep.bit == List.range (radixBits xs) &&
      (sortWithWork xs).1 == radixSortResult xs &&
      decide (xs.length * radixBits xs ≤ radixWorkCost xs ∧
        radixWorkCost xs ≤ 3 * (xs.length * radixBits xs))

end LeanSort.Radix
