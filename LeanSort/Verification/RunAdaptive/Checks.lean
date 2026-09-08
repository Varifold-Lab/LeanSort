import LeanSort.Verification.RunAdaptive.Complexity
import LeanSort.Verification.RunAdaptive.Structure

namespace LeanSort.RunAdaptive

set_option maxRecDepth 10000
set_option maxHeartbeats 2000000

example : (discover ([] : List Nat)).eval.ret = [] := by rfl
example : (discover [7]).eval.ret = [[7]] := by decide +kernel
example : (discover [1, 1, 2, 0, 0, 3, 2]).eval.ret = [[1, 1, 2], [0, 0, 3], [2]] := by decide +kernel
example : runCount [4, 3, 2, 1] = 4 := by decide +kernel
example : (sortProgram countPlan [4, 3, 2, 1]).eval.ret = [1, 2, 3, 4] := by decide +kernel
example : (sortProgram lengthPlan [4, 3, 2, 1]).eval.ret = [1, 2, 3, 4] := by decide +kernel

/-- A verified witness that count balancing and the length-aware control are
different strategies. Neither tree budget nor this input proves global dominance. -/
theorem unequal_length_witness :
    (countPlan [[50], [30], List.range 16]).budget = 35 ∧
    (lengthPlan [[50], [30], List.range 16]).budget = 20 ∧
    (sortProgram countPlan ([50, 30] ++ List.range 16)).eval.time = 50 ∧
    (sortProgram lengthPlan ([50, 30] ++ List.range 16)).eval.time = 34 := by decide +kernel

end LeanSort.RunAdaptive
