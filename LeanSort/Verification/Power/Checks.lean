import LeanSort.Verification.Power.Cost
import LeanSort.Verification.Power.Stability
import LeanSort.Verification.Power.Complexity

namespace LeanSort.Power

example {α : Type*} [LinearOrder α] (xs : List α) :
    IsSortingResult (· ≤ ·) xs (powerSortResult xs) := powerSortResult_spec xs

example {α β : Type*} [LinearOrder β] (key : α → β) (xs : List α) (k : β) :
    (powerSortBy (fun a b => decide (key a ≤ key b)) xs).filter (fun x => decide (key x = k)) =
      xs.filter (fun x => decide (key x = k)) := powerSortBy_stable key xs k

private def natLe (a b : Nat) : Bool := decide (a ≤ b)

#guard powerSortResult ([] : List Nat) = []
#guard powerSortResult [7] = [7]
#guard powerSortResult ([3, -2, 0, -2, 10] : List Int) = [-2, -2, 0, 3, 10]
#guard powerSortResult [10 ^ 30, 0, 1, 10 ^ 30] = [0, 1, 10 ^ 30, 10 ^ 30]
#guard naturalRuns natLe [4, 3, 2, 2, 1] = [[2, 3, 4], [1, 2]]
#guard powerSortTrace natLe [] = ⟨[], []⟩
#guard powerSortTrace natLe [4, 3, 2, 1] = ⟨[4], []⟩
#guard powerSortTrace natLe [3, 1, 2, 0] =
  ⟨[2, 2], [.boundary 0 2 2 1, .merge 2 2]⟩
-- Collapse the first two runs before the third boundary is computed. The next
-- boundary must still use start = 4 and the original third run's length = 2.
#guard powerSortTrace natLe [1, 5, 0, 4, 2, 6, 1, 3] =
  ⟨[2, 2, 2, 2], [.boundary 0 2 2 2, .boundary 2 2 2 1, .merge 2 2,
    .boundary 4 2 2 2, .merge 2 2, .merge 4 4]⟩

#guard replayChecked? natLe [3, 1, 2, 0] ⟨[2, 2], [.boundary 0 2 2 1, .merge 2 2]⟩ =
  some [0, 1, 2, 3]
-- Altered power/start/run sizes, missing/extra/reordered events, bad merge sizes.
#guard replayChecked? natLe [3, 1, 2, 0] ⟨[2, 2], [.boundary 0 2 2 2, .merge 2 2]⟩ = none
#guard replayChecked? natLe [3, 1, 2, 0] ⟨[2, 2], [.boundary 1 2 2 1, .merge 2 2]⟩ = none
#guard replayChecked? natLe [3, 1, 2, 0] ⟨[1, 3], [.boundary 0 2 2 1, .merge 2 2]⟩ = none
#guard replayChecked? natLe [3, 1, 2, 0] ⟨[2, 2], [.boundary 0 2 2 1]⟩ = none
#guard replayChecked? natLe [3, 1, 2, 0]
  ⟨[2, 2], [.boundary 0 2 2 1, .merge 2 2, .merge 0 4]⟩ = none
#guard replayChecked? natLe [3, 1, 2, 0] ⟨[2, 2], [.merge 2 2, .boundary 0 2 2 1]⟩ = none
#guard replayChecked? natLe [3, 1, 2, 0] ⟨[2, 2], [.boundary 0 2 2 1, .merge 1 3]⟩ = none

#guard powerComparisonCost natLe [] = 0
#guard powerComparisonCost natLe [7] = 0
#guard powerComparisonCost natLe [1, 2, 3, 4] = 3
#guard powerComparisonCost natLe [4, 3, 2, 1] = 3
#guard powerComparisonCost natLe [3, 1, 2, 0] = 6
#guard powerComparisonCost natLe [1, 5, 0, 4, 2, 6, 1, 3] = 20

-- Every valid adjacent-run geometry up to length 16, including dyadic endpoints.
#guard (List.range 17).all fun n => (List.range n).all fun start =>
  (List.range (n - start)).all fun l =>
    let left := l + 1
    (List.range (n - start - left)).all fun r =>
      let right := r + 1
      let p := nodePower n start left right
      let a := 2 * start + left
      let b := 2 * start + 2 * left + right
      1 ≤ p && p ≤ maxPower n && bucket (2*n) a p != bucket (2*n) b p &&
        (List.range p).all (fun k => bucket (2*n) a k == bucket (2*n) b k)

private def smallInputs : Nat → List (List Nat)
  | 0 => [[]]
  | n + 1 => (smallInputs n).flatMap fun xs => [0, 1, 2].map (fun x => x :: xs)

-- All 3,280 lists of lengths 0 through 7, including tagged equal-key records.
#guard ((List.range 8).flatMap smallInputs).all fun xs =>
  let execution := powerSortTr natLe xs
  let runs := naturalRuns natLe xs
  let tagged := xs.zipIdx
  let keyLe := fun a b : Nat × Nat => decide (a.1 ≤ b.1)
  let stable := powerSortBy keyLe tagged
  let counted := powerComparisonRun natLe xs
  execution.1 == xs.mergeSort &&
    counted.1 == execution.1 && counted.2 ≤ xs.length * (xs.length.log2 + 2) &&
    (scanComparisonRun natLe xs [] none []).2 == xs.length - 1 &&
    execution.1 == powerSortResult xs &&
    replayChecked? natLe xs execution.2 == some execution.1 &&
    mergeCount execution.2.events == runs.length - 1 &&
    execution.2.events.length == 2 * (runs.length - 1) &&
    stable == tagged.mergeSort keyLe &&
    [0, 1, 2].all (fun k => stable.filter (fun x => x.1 == k) == tagged.filter (fun x => x.1 == k))

#guard [15, 16, 17, 31, 32, 33, 64, 127, 256].all fun n =>
  [List.range n, (List.range n).reverse, List.replicate n 4,
    (List.range n).map (fun i => (i * 7) % 11)].all fun xs =>
      powerSortResult xs == xs.mergeSort &&
      mergeCount (powerSortTrace natLe xs).events ≤ n - 1 &&
      (powerComparisonRun natLe xs).1 == xs.mergeSort &&
      powerComparisonCost natLe xs ≤ n * (n.log2 + 2)

-- The total-preorder API does not require ordering the payload.
#guard powerSortBy (fun a b : Nat × String => decide (a.1 ≤ b.1))
    [(2, "a"), (1, "b"), (2, "c"), (1, "d")] =
      [(1, "b"), (1, "d"), (2, "a"), (2, "c")]

end LeanSort.Power
