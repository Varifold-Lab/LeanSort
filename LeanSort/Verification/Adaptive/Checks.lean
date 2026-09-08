import LeanSort.Verification.Adaptive.Correctness

namespace LeanSort.Adaptive

#guard execute none [3, 1, 2, 1] = [1, 1, 2, 3]
#guard (Plan.split 0 .insertion (.hybrid 0)).run [2, 1] = [1, 2]
#guard (Plan.split 100 .merge .insertion).run [3, 2, 1] = [1, 2, 3]
#guard (Plan.split 2 (.hybrid 8) (.split 1 .insertion .merge)).run
  ([4, -1, 3, -1, 2] : List Int) = [-1, -1, 2, 3, 4]
#guard (Plan.split 0 .merge .insertion).run ([] : List Nat) = []

example {α : Type} [LinearOrder α] (xs : List α) :
    IsSortingResult (· ≤ ·) xs
      (selectAndRun (fun ys => some (.split (ys.length / 3) (.hybrid 8) .merge)) xs) :=
  selectAndRun_spec _ xs

end LeanSort.Adaptive
