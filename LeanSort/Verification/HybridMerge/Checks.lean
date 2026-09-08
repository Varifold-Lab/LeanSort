import LeanSort.Verification.HybridMerge.Correctness

/-! Finite executable regressions; the universal guarantee is `sort_spec`. -/

namespace LeanSort.HybridMerge

#guard sort 0 ([] : List Nat) = []
#guard sort 0 [7] = [7]
#guard sort 1 [5, 4, 3, 2, 1] = [1, 2, 3, 4, 5]
#guard sort 2 [2, 1, 2, 1] = [1, 1, 2, 2]
#guard sort 100 ([-2, 3, 0, -2] : List Int) = [-2, -2, 0, 3]
#guard sort 8 (List.range 17).reverse = List.range 17

private def words : Nat → List (List Nat)
  | 0 => [[]]
  | n + 1 => (words n).flatMap fun xs => [0, 1, 2].map (· :: xs)

-- Every word of length 0–5 over {0,1,2}, at five thresholds.
#guard ((List.range 6).flatMap words).all fun xs =>
  [0, 1, 2, 4, 100].all fun threshold =>
    sort threshold xs == Merge.mergeSortResult xs

example {α : Type} [LinearOrder α] (xs : List α) :
    IsSortingResult (· ≤ ·) xs (sort (if xs.length < 20 then 8 else 2) xs) :=
  selected_sort_spec (fun ys => if ys.length < 20 then 8 else 2) xs

end LeanSort.HybridMerge
