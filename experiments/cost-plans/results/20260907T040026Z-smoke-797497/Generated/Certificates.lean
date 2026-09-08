import Generated.Algorithms
import LeanSort.Verification.CostedPlan.Examples
namespace CostPlanGenerated
open LeanSort LeanSort.CostedPlan Filter Asymptotics
theorem p000_two_insertion_certificate : Certificate p000_two_insertion := p000_two_insertion.certify
theorem p000_two_insertion_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p000_two_insertion_algorithm xs) := p000_two_insertion.run_spec xs
theorem p000_two_insertion_cost {α : Type} [LinearOrder α] (xs : List α) : (p000_two_insertion.eval xs).time ≤ p000_two_insertion_costFormula xs.length := p000_two_insertion.cost_le_upper xs
theorem p000_two_insertion_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p000_two_insertion.Ready xs) : (p000_two_insertion.eval xs).time ≤ p000_two_insertion_conditionalFormula xs.length := p000_two_insertion.cost_le_readyUpper xs h
theorem p000_two_insertion_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p000_two_insertion.program xs) (p000_two_insertion_algorithm xs) (p000_two_insertion.eval xs).time := p000_two_insertion.operational_certificate xs
theorem p000_two_insertion_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p000_two_insertion.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p000_two_insertion.cost_isBigO_of_upper _ p000_two_insertion.upper_isBigO_quadratic
theorem p000_two_insertion_formula_0 : p000_two_insertion_costFormula 0 = 0 ∧ p000_two_insertion_conditionalFormula 0 = 0 := by decide +kernel
theorem p000_two_insertion_formula_1 : p000_two_insertion_costFormula 1 = 1 ∧ p000_two_insertion_conditionalFormula 1 = 1 := by decide +kernel
theorem p000_two_insertion_formula_8 : p000_two_insertion_costFormula 8 = 20 ∧ p000_two_insertion_conditionalFormula 8 = 20 := by decide +kernel
theorem p000_two_insertion_formula_16 : p000_two_insertion_costFormula 16 = 72 ∧ p000_two_insertion_conditionalFormula 16 = 72 := by decide +kernel
theorem p000_two_insertion_formula_32 : p000_two_insertion_costFormula 32 = 272 ∧ p000_two_insertion_conditionalFormula 32 = 272 := by decide +kernel
theorem p000_two_insertion_formula_64 : p000_two_insertion_costFormula 64 = 1056 ∧ p000_two_insertion_conditionalFormula 64 = 1056 := by decide +kernel
theorem p000_two_insertion_formula_128 : p000_two_insertion_costFormula 128 = 4160 ∧ p000_two_insertion_conditionalFormula 128 = 4160 := by decide +kernel
#print axioms p000_two_insertion_certificate
#print axioms p000_two_insertion_correct
#print axioms p000_two_insertion_cost
#print axioms p000_two_insertion_conditional
#print axioms p000_two_insertion_operational
#print axioms p000_two_insertion_quadratic
theorem p001_two_guarded_certificate : Certificate p001_two_guarded := p001_two_guarded.certify
theorem p001_two_guarded_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p001_two_guarded_algorithm xs) := p001_two_guarded.run_spec xs
theorem p001_two_guarded_cost {α : Type} [LinearOrder α] (xs : List α) : (p001_two_guarded.eval xs).time ≤ p001_two_guarded_costFormula xs.length := p001_two_guarded.cost_le_upper xs
theorem p001_two_guarded_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p001_two_guarded.Ready xs) : (p001_two_guarded.eval xs).time ≤ p001_two_guarded_conditionalFormula xs.length := p001_two_guarded.cost_le_readyUpper xs h
theorem p001_two_guarded_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p001_two_guarded.program xs) (p001_two_guarded_algorithm xs) (p001_two_guarded.eval xs).time := p001_two_guarded.operational_certificate xs
theorem p001_two_guarded_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p001_two_guarded.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p001_two_guarded.cost_isBigO_of_upper _ p001_two_guarded.upper_isBigO_quadratic
theorem p001_two_guarded_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p001_two_guarded.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p001_two_guarded.cost_isBigO_of_upper _ (p001_two_guarded.upper_isBigO_nlog 5 rfl)
theorem p001_two_guarded_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p001_two_guarded.Ready xs} => ((p001_two_guarded.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p001_two_guarded.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p001_two_guarded.Ready xs} => (xs.val.length : ℝ)) := p001_two_guarded.ready_cost_isBigO_linear 1 rfl
theorem p001_two_guarded_formula_0 : p001_two_guarded_costFormula 0 = 0 ∧ p001_two_guarded_conditionalFormula 0 = 0 := by decide +kernel
theorem p001_two_guarded_formula_1 : p001_two_guarded_costFormula 1 = 1 ∧ p001_two_guarded_conditionalFormula 1 = 1 := by decide +kernel
theorem p001_two_guarded_formula_8 : p001_two_guarded_costFormula 8 = 30 ∧ p001_two_guarded_conditionalFormula 8 = 14 := by decide +kernel
theorem p001_two_guarded_formula_16 : p001_two_guarded_costFormula 16 = 78 ∧ p001_two_guarded_conditionalFormula 16 = 30 := by decide +kernel
theorem p001_two_guarded_formula_32 : p001_two_guarded_costFormula 32 = 190 ∧ p001_two_guarded_conditionalFormula 32 = 62 := by decide +kernel
theorem p001_two_guarded_formula_64 : p001_two_guarded_costFormula 64 = 446 ∧ p001_two_guarded_conditionalFormula 64 = 126 := by decide +kernel
theorem p001_two_guarded_formula_128 : p001_two_guarded_costFormula 128 = 1022 ∧ p001_two_guarded_conditionalFormula 128 = 254 := by decide +kernel
#print axioms p001_two_guarded_certificate
#print axioms p001_two_guarded_correct
#print axioms p001_two_guarded_cost
#print axioms p001_two_guarded_conditional
#print axioms p001_two_guarded_operational
#print axioms p001_two_guarded_quadratic
#print axioms p001_two_guarded_nlog
#print axioms p001_two_guarded_conditional_linear
theorem p002_merge_halves_certificate : Certificate p002_merge_halves := p002_merge_halves.certify
theorem p002_merge_halves_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p002_merge_halves_algorithm xs) := p002_merge_halves.run_spec xs
theorem p002_merge_halves_cost {α : Type} [LinearOrder α] (xs : List α) : (p002_merge_halves.eval xs).time ≤ p002_merge_halves_costFormula xs.length := p002_merge_halves.cost_le_upper xs
theorem p002_merge_halves_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p002_merge_halves.Ready xs) : (p002_merge_halves.eval xs).time ≤ p002_merge_halves_conditionalFormula xs.length := p002_merge_halves.cost_le_readyUpper xs h
theorem p002_merge_halves_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p002_merge_halves.program xs) (p002_merge_halves_algorithm xs) (p002_merge_halves.eval xs).time := p002_merge_halves.operational_certificate xs
theorem p002_merge_halves_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p002_merge_halves.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p002_merge_halves.cost_isBigO_of_upper _ p002_merge_halves.upper_isBigO_quadratic
theorem p002_merge_halves_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p002_merge_halves.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p002_merge_halves.cost_isBigO_of_upper _ (p002_merge_halves.upper_isBigO_nlog 3 rfl)
theorem p002_merge_halves_formula_0 : p002_merge_halves_costFormula 0 = 0 ∧ p002_merge_halves_conditionalFormula 0 = 0 := by decide +kernel
theorem p002_merge_halves_formula_1 : p002_merge_halves_costFormula 1 = 1 ∧ p002_merge_halves_conditionalFormula 1 = 1 := by decide +kernel
theorem p002_merge_halves_formula_8 : p002_merge_halves_costFormula 8 = 24 ∧ p002_merge_halves_conditionalFormula 8 = 24 := by decide +kernel
theorem p002_merge_halves_formula_16 : p002_merge_halves_costFormula 16 = 64 ∧ p002_merge_halves_conditionalFormula 16 = 64 := by decide +kernel
theorem p002_merge_halves_formula_32 : p002_merge_halves_costFormula 32 = 160 ∧ p002_merge_halves_conditionalFormula 32 = 160 := by decide +kernel
theorem p002_merge_halves_formula_64 : p002_merge_halves_costFormula 64 = 384 ∧ p002_merge_halves_conditionalFormula 64 = 384 := by decide +kernel
theorem p002_merge_halves_formula_128 : p002_merge_halves_costFormula 128 = 896 ∧ p002_merge_halves_conditionalFormula 128 = 896 := by decide +kernel
#print axioms p002_merge_halves_certificate
#print axioms p002_merge_halves_correct
#print axioms p002_merge_halves_cost
#print axioms p002_merge_halves_conditional
#print axioms p002_merge_halves_operational
#print axioms p002_merge_halves_quadratic
#print axioms p002_merge_halves_nlog
theorem p003_guarded_merge_certificate : Certificate p003_guarded_merge := p003_guarded_merge.certify
theorem p003_guarded_merge_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p003_guarded_merge_algorithm xs) := p003_guarded_merge.run_spec xs
theorem p003_guarded_merge_cost {α : Type} [LinearOrder α] (xs : List α) : (p003_guarded_merge.eval xs).time ≤ p003_guarded_merge_costFormula xs.length := p003_guarded_merge.cost_le_upper xs
theorem p003_guarded_merge_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p003_guarded_merge.Ready xs) : (p003_guarded_merge.eval xs).time ≤ p003_guarded_merge_conditionalFormula xs.length := p003_guarded_merge.cost_le_readyUpper xs h
theorem p003_guarded_merge_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p003_guarded_merge.program xs) (p003_guarded_merge_algorithm xs) (p003_guarded_merge.eval xs).time := p003_guarded_merge.operational_certificate xs
theorem p003_guarded_merge_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p003_guarded_merge.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p003_guarded_merge.cost_isBigO_of_upper _ p003_guarded_merge.upper_isBigO_quadratic
theorem p003_guarded_merge_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p003_guarded_merge.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p003_guarded_merge.cost_isBigO_of_upper _ (p003_guarded_merge.upper_isBigO_nlog 2 rfl)
theorem p003_guarded_merge_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p003_guarded_merge.Ready xs} => ((p003_guarded_merge.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p003_guarded_merge.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p003_guarded_merge.Ready xs} => (xs.val.length : ℝ)) := p003_guarded_merge.ready_cost_isBigO_linear 0 rfl
theorem p003_guarded_merge_formula_0 : p003_guarded_merge_costFormula 0 = 0 ∧ p003_guarded_merge_conditionalFormula 0 = 0 := by decide +kernel
theorem p003_guarded_merge_formula_1 : p003_guarded_merge_costFormula 1 = 0 ∧ p003_guarded_merge_conditionalFormula 1 = 0 := by decide +kernel
theorem p003_guarded_merge_formula_8 : p003_guarded_merge_costFormula 8 = 31 ∧ p003_guarded_merge_conditionalFormula 8 = 7 := by decide +kernel
theorem p003_guarded_merge_formula_16 : p003_guarded_merge_costFormula 16 = 79 ∧ p003_guarded_merge_conditionalFormula 16 = 15 := by decide +kernel
theorem p003_guarded_merge_formula_32 : p003_guarded_merge_costFormula 32 = 191 ∧ p003_guarded_merge_conditionalFormula 32 = 31 := by decide +kernel
theorem p003_guarded_merge_formula_64 : p003_guarded_merge_costFormula 64 = 447 ∧ p003_guarded_merge_conditionalFormula 64 = 63 := by decide +kernel
theorem p003_guarded_merge_formula_128 : p003_guarded_merge_costFormula 128 = 1023 ∧ p003_guarded_merge_conditionalFormula 128 = 127 := by decide +kernel
#print axioms p003_guarded_merge_certificate
#print axioms p003_guarded_merge_correct
#print axioms p003_guarded_merge_cost
#print axioms p003_guarded_merge_conditional
#print axioms p003_guarded_merge_operational
#print axioms p003_guarded_merge_quadratic
#print axioms p003_guarded_merge_nlog
#print axioms p003_guarded_merge_conditional_linear
theorem p004_prefix_insertion_merge_certificate : Certificate p004_prefix_insertion_merge := p004_prefix_insertion_merge.certify
theorem p004_prefix_insertion_merge_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p004_prefix_insertion_merge_algorithm xs) := p004_prefix_insertion_merge.run_spec xs
theorem p004_prefix_insertion_merge_cost {α : Type} [LinearOrder α] (xs : List α) : (p004_prefix_insertion_merge.eval xs).time ≤ p004_prefix_insertion_merge_costFormula xs.length := p004_prefix_insertion_merge.cost_le_upper xs
theorem p004_prefix_insertion_merge_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p004_prefix_insertion_merge.Ready xs) : (p004_prefix_insertion_merge.eval xs).time ≤ p004_prefix_insertion_merge_conditionalFormula xs.length := p004_prefix_insertion_merge.cost_le_readyUpper xs h
theorem p004_prefix_insertion_merge_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p004_prefix_insertion_merge.program xs) (p004_prefix_insertion_merge_algorithm xs) (p004_prefix_insertion_merge.eval xs).time := p004_prefix_insertion_merge.operational_certificate xs
theorem p004_prefix_insertion_merge_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p004_prefix_insertion_merge.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p004_prefix_insertion_merge.cost_isBigO_of_upper _ p004_prefix_insertion_merge.upper_isBigO_quadratic
theorem p004_prefix_insertion_merge_formula_0 : p004_prefix_insertion_merge_costFormula 0 = 0 ∧ p004_prefix_insertion_merge_conditionalFormula 0 = 0 := by decide +kernel
theorem p004_prefix_insertion_merge_formula_1 : p004_prefix_insertion_merge_costFormula 1 = 1 ∧ p004_prefix_insertion_merge_conditionalFormula 1 = 1 := by decide +kernel
theorem p004_prefix_insertion_merge_formula_8 : p004_prefix_insertion_merge_costFormula 8 = 36 ∧ p004_prefix_insertion_merge_conditionalFormula 8 = 36 := by decide +kernel
theorem p004_prefix_insertion_merge_formula_16 : p004_prefix_insertion_merge_costFormula 16 = 68 ∧ p004_prefix_insertion_merge_conditionalFormula 16 = 68 := by decide +kernel
theorem p004_prefix_insertion_merge_formula_32 : p004_prefix_insertion_merge_costFormula 32 = 180 ∧ p004_prefix_insertion_merge_conditionalFormula 32 = 180 := by decide +kernel
theorem p004_prefix_insertion_merge_formula_64 : p004_prefix_insertion_merge_costFormula 64 = 428 ∧ p004_prefix_insertion_merge_conditionalFormula 64 = 428 := by decide +kernel
theorem p004_prefix_insertion_merge_formula_128 : p004_prefix_insertion_merge_costFormula 128 = 996 ∧ p004_prefix_insertion_merge_conditionalFormula 128 = 996 := by decide +kernel
#print axioms p004_prefix_insertion_merge_certificate
#print axioms p004_prefix_insertion_merge_correct
#print axioms p004_prefix_insertion_merge_cost
#print axioms p004_prefix_insertion_merge_conditional
#print axioms p004_prefix_insertion_merge_operational
#print axioms p004_prefix_insertion_merge_quadratic
theorem p005_three_guarded_certificate : Certificate p005_three_guarded := p005_three_guarded.certify
theorem p005_three_guarded_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p005_three_guarded_algorithm xs) := p005_three_guarded.run_spec xs
theorem p005_three_guarded_cost {α : Type} [LinearOrder α] (xs : List α) : (p005_three_guarded.eval xs).time ≤ p005_three_guarded_costFormula xs.length := p005_three_guarded.cost_le_upper xs
theorem p005_three_guarded_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p005_three_guarded.Ready xs) : (p005_three_guarded.eval xs).time ≤ p005_three_guarded_conditionalFormula xs.length := p005_three_guarded.cost_le_readyUpper xs h
theorem p005_three_guarded_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p005_three_guarded.program xs) (p005_three_guarded_algorithm xs) (p005_three_guarded.eval xs).time := p005_three_guarded.operational_certificate xs
theorem p005_three_guarded_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p005_three_guarded.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p005_three_guarded.cost_isBigO_of_upper _ p005_three_guarded.upper_isBigO_quadratic
theorem p005_three_guarded_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p005_three_guarded.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p005_three_guarded.cost_isBigO_of_upper _ (p005_three_guarded.upper_isBigO_nlog 8 rfl)
theorem p005_three_guarded_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p005_three_guarded.Ready xs} => ((p005_three_guarded.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p005_three_guarded.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p005_three_guarded.Ready xs} => (xs.val.length : ℝ)) := p005_three_guarded.ready_cost_isBigO_linear 2 rfl
theorem p005_three_guarded_formula_0 : p005_three_guarded_costFormula 0 = 0 ∧ p005_three_guarded_conditionalFormula 0 = 0 := by decide +kernel
theorem p005_three_guarded_formula_1 : p005_three_guarded_costFormula 1 = 2 ∧ p005_three_guarded_conditionalFormula 1 = 2 := by decide +kernel
theorem p005_three_guarded_formula_8 : p005_three_guarded_costFormula 8 = 33 ∧ p005_three_guarded_conditionalFormula 8 = 19 := by decide +kernel
theorem p005_three_guarded_formula_16 : p005_three_guarded_costFormula 16 = 88 ∧ p005_three_guarded_conditionalFormula 16 = 40 := by decide +kernel
theorem p005_three_guarded_formula_32 : p005_three_guarded_costFormula 32 = 211 ∧ p005_three_guarded_conditionalFormula 32 = 83 := by decide +kernel
theorem p005_three_guarded_formula_64 : p005_three_guarded_costFormula 64 = 488 ∧ p005_three_guarded_conditionalFormula 64 = 168 := by decide +kernel
theorem p005_three_guarded_formula_128 : p005_three_guarded_costFormula 128 = 1107 ∧ p005_three_guarded_conditionalFormula 128 = 339 := by decide +kernel
#print axioms p005_three_guarded_certificate
#print axioms p005_three_guarded_correct
#print axioms p005_three_guarded_cost
#print axioms p005_three_guarded_conditional
#print axioms p005_three_guarded_operational
#print axioms p005_three_guarded_quadratic
#print axioms p005_three_guarded_nlog
#print axioms p005_three_guarded_conditional_linear
theorem p006_four_guarded_certificate : Certificate p006_four_guarded := p006_four_guarded.certify
theorem p006_four_guarded_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p006_four_guarded_algorithm xs) := p006_four_guarded.run_spec xs
theorem p006_four_guarded_cost {α : Type} [LinearOrder α] (xs : List α) : (p006_four_guarded.eval xs).time ≤ p006_four_guarded_costFormula xs.length := p006_four_guarded.cost_le_upper xs
theorem p006_four_guarded_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p006_four_guarded.Ready xs) : (p006_four_guarded.eval xs).time ≤ p006_four_guarded_conditionalFormula xs.length := p006_four_guarded.cost_le_readyUpper xs h
theorem p006_four_guarded_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p006_four_guarded.program xs) (p006_four_guarded_algorithm xs) (p006_four_guarded.eval xs).time := p006_four_guarded.operational_certificate xs
theorem p006_four_guarded_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p006_four_guarded.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p006_four_guarded.cost_isBigO_of_upper _ p006_four_guarded.upper_isBigO_quadratic
theorem p006_four_guarded_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p006_four_guarded.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p006_four_guarded.cost_isBigO_of_upper _ (p006_four_guarded.upper_isBigO_nlog 11 rfl)
theorem p006_four_guarded_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p006_four_guarded.Ready xs} => ((p006_four_guarded.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p006_four_guarded.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p006_four_guarded.Ready xs} => (xs.val.length : ℝ)) := p006_four_guarded.ready_cost_isBigO_linear 2 rfl
theorem p006_four_guarded_formula_0 : p006_four_guarded_costFormula 0 = 0 ∧ p006_four_guarded_conditionalFormula 0 = 0 := by decide +kernel
theorem p006_four_guarded_formula_1 : p006_four_guarded_costFormula 1 = 2 ∧ p006_four_guarded_conditionalFormula 1 = 2 := by decide +kernel
theorem p006_four_guarded_formula_8 : p006_four_guarded_costFormula 8 = 28 ∧ p006_four_guarded_conditionalFormula 8 = 20 := by decide +kernel
theorem p006_four_guarded_formula_16 : p006_four_guarded_costFormula 16 = 76 ∧ p006_four_guarded_conditionalFormula 16 = 44 := by decide +kernel
theorem p006_four_guarded_formula_32 : p006_four_guarded_costFormula 32 = 188 ∧ p006_four_guarded_conditionalFormula 32 = 92 := by decide +kernel
theorem p006_four_guarded_formula_64 : p006_four_guarded_costFormula 64 = 444 ∧ p006_four_guarded_conditionalFormula 64 = 188 := by decide +kernel
theorem p006_four_guarded_formula_128 : p006_four_guarded_costFormula 128 = 1020 ∧ p006_four_guarded_conditionalFormula 128 = 380 := by decide +kernel
#print axioms p006_four_guarded_certificate
#print axioms p006_four_guarded_correct
#print axioms p006_four_guarded_cost
#print axioms p006_four_guarded_conditional
#print axioms p006_four_guarded_operational
#print axioms p006_four_guarded_quadratic
#print axioms p006_four_guarded_nlog
#print axioms p006_four_guarded_conditional_linear
theorem p007_mixed_hybrid_certificate : Certificate p007_mixed_hybrid := p007_mixed_hybrid.certify
theorem p007_mixed_hybrid_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p007_mixed_hybrid_algorithm xs) := p007_mixed_hybrid.run_spec xs
theorem p007_mixed_hybrid_cost {α : Type} [LinearOrder α] (xs : List α) : (p007_mixed_hybrid.eval xs).time ≤ p007_mixed_hybrid_costFormula xs.length := p007_mixed_hybrid.cost_le_upper xs
theorem p007_mixed_hybrid_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p007_mixed_hybrid.Ready xs) : (p007_mixed_hybrid.eval xs).time ≤ p007_mixed_hybrid_conditionalFormula xs.length := p007_mixed_hybrid.cost_le_readyUpper xs h
theorem p007_mixed_hybrid_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p007_mixed_hybrid.program xs) (p007_mixed_hybrid_algorithm xs) (p007_mixed_hybrid.eval xs).time := p007_mixed_hybrid.operational_certificate xs
theorem p007_mixed_hybrid_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p007_mixed_hybrid.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p007_mixed_hybrid.cost_isBigO_of_upper _ p007_mixed_hybrid.upper_isBigO_quadratic
theorem p007_mixed_hybrid_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p007_mixed_hybrid.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p007_mixed_hybrid.cost_isBigO_of_upper _ (p007_mixed_hybrid.upper_isBigO_nlog 23 rfl)
theorem p007_mixed_hybrid_formula_0 : p007_mixed_hybrid_costFormula 0 = 0 ∧ p007_mixed_hybrid_conditionalFormula 0 = 0 := by decide +kernel
theorem p007_mixed_hybrid_formula_1 : p007_mixed_hybrid_costFormula 1 = 1 ∧ p007_mixed_hybrid_conditionalFormula 1 = 1 := by decide +kernel
theorem p007_mixed_hybrid_formula_8 : p007_mixed_hybrid_costFormula 8 = 24 ∧ p007_mixed_hybrid_conditionalFormula 8 = 24 := by decide +kernel
theorem p007_mixed_hybrid_formula_16 : p007_mixed_hybrid_costFormula 16 = 80 ∧ p007_mixed_hybrid_conditionalFormula 16 = 80 := by decide +kernel
theorem p007_mixed_hybrid_formula_32 : p007_mixed_hybrid_costFormula 32 = 192 ∧ p007_mixed_hybrid_conditionalFormula 32 = 192 := by decide +kernel
theorem p007_mixed_hybrid_formula_64 : p007_mixed_hybrid_costFormula 64 = 441 ∧ p007_mixed_hybrid_conditionalFormula 64 = 441 := by decide +kernel
theorem p007_mixed_hybrid_formula_128 : p007_mixed_hybrid_costFormula 128 = 1010 ∧ p007_mixed_hybrid_conditionalFormula 128 = 1010 := by decide +kernel
#print axioms p007_mixed_hybrid_certificate
#print axioms p007_mixed_hybrid_correct
#print axioms p007_mixed_hybrid_cost
#print axioms p007_mixed_hybrid_conditional
#print axioms p007_mixed_hybrid_operational
#print axioms p007_mixed_hybrid_quadratic
#print axioms p007_mixed_hybrid_nlog
theorem p008_split_certificate : Certificate p008_split := p008_split.certify
theorem p008_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p008_split_algorithm xs) := p008_split.run_spec xs
theorem p008_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p008_split.eval xs).time ≤ p008_split_costFormula xs.length := p008_split.cost_le_upper xs
theorem p008_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p008_split.Ready xs) : (p008_split.eval xs).time ≤ p008_split_conditionalFormula xs.length := p008_split.cost_le_readyUpper xs h
theorem p008_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p008_split.program xs) (p008_split_algorithm xs) (p008_split.eval xs).time := p008_split.operational_certificate xs
theorem p008_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p008_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p008_split.cost_isBigO_of_upper _ p008_split.upper_isBigO_quadratic
theorem p008_split_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p008_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p008_split.cost_isBigO_of_upper _ (p008_split.upper_isBigO_nlog 35 rfl)
theorem p008_split_formula_0 : p008_split_costFormula 0 = 0 ∧ p008_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p008_split_formula_1 : p008_split_costFormula 1 = 1 ∧ p008_split_conditionalFormula 1 = 1 := by decide +kernel
theorem p008_split_formula_8 : p008_split_costFormula 8 = 36 ∧ p008_split_conditionalFormula 8 = 36 := by decide +kernel
theorem p008_split_formula_16 : p008_split_costFormula 16 = 136 ∧ p008_split_conditionalFormula 16 = 136 := by decide +kernel
theorem p008_split_formula_32 : p008_split_costFormula 32 = 272 ∧ p008_split_conditionalFormula 32 = 272 := by decide +kernel
theorem p008_split_formula_64 : p008_split_costFormula 64 = 544 ∧ p008_split_conditionalFormula 64 = 544 := by decide +kernel
theorem p008_split_formula_128 : p008_split_costFormula 128 = 1312 ∧ p008_split_conditionalFormula 128 = 1312 := by decide +kernel
#print axioms p008_split_certificate
#print axioms p008_split_correct
#print axioms p008_split_cost
#print axioms p008_split_conditional
#print axioms p008_split_operational
#print axioms p008_split_quadratic
#print axioms p008_split_nlog
theorem p009_guarded_split_certificate : Certificate p009_guarded_split := p009_guarded_split.certify
theorem p009_guarded_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p009_guarded_split_algorithm xs) := p009_guarded_split.run_spec xs
theorem p009_guarded_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p009_guarded_split.eval xs).time ≤ p009_guarded_split_costFormula xs.length := p009_guarded_split.cost_le_upper xs
theorem p009_guarded_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p009_guarded_split.Ready xs) : (p009_guarded_split.eval xs).time ≤ p009_guarded_split_conditionalFormula xs.length := p009_guarded_split.cost_le_readyUpper xs h
theorem p009_guarded_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p009_guarded_split.program xs) (p009_guarded_split_algorithm xs) (p009_guarded_split.eval xs).time := p009_guarded_split.operational_certificate xs
theorem p009_guarded_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p009_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p009_guarded_split.cost_isBigO_of_upper _ p009_guarded_split.upper_isBigO_quadratic
theorem p009_guarded_split_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p009_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p009_guarded_split.cost_isBigO_of_upper _ (p009_guarded_split.upper_isBigO_nlog 36 rfl)
theorem p009_guarded_split_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p009_guarded_split.Ready xs} => ((p009_guarded_split.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p009_guarded_split.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p009_guarded_split.Ready xs} => (xs.val.length : ℝ)) := p009_guarded_split.ready_cost_isBigO_linear 0 rfl
theorem p009_guarded_split_formula_0 : p009_guarded_split_costFormula 0 = 0 ∧ p009_guarded_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p009_guarded_split_formula_1 : p009_guarded_split_costFormula 1 = 1 ∧ p009_guarded_split_conditionalFormula 1 = 0 := by decide +kernel
theorem p009_guarded_split_formula_8 : p009_guarded_split_costFormula 8 = 43 ∧ p009_guarded_split_conditionalFormula 8 = 7 := by decide +kernel
theorem p009_guarded_split_formula_16 : p009_guarded_split_costFormula 16 = 151 ∧ p009_guarded_split_conditionalFormula 16 = 15 := by decide +kernel
theorem p009_guarded_split_formula_32 : p009_guarded_split_costFormula 32 = 303 ∧ p009_guarded_split_conditionalFormula 32 = 31 := by decide +kernel
theorem p009_guarded_split_formula_64 : p009_guarded_split_costFormula 64 = 607 ∧ p009_guarded_split_conditionalFormula 64 = 63 := by decide +kernel
theorem p009_guarded_split_formula_128 : p009_guarded_split_costFormula 128 = 1439 ∧ p009_guarded_split_conditionalFormula 128 = 127 := by decide +kernel
#print axioms p009_guarded_split_certificate
#print axioms p009_guarded_split_correct
#print axioms p009_guarded_split_cost
#print axioms p009_guarded_split_conditional
#print axioms p009_guarded_split_operational
#print axioms p009_guarded_split_quadratic
#print axioms p009_guarded_split_nlog
#print axioms p009_guarded_split_conditional_linear
theorem p010_checked_blocks_certificate : Certificate p010_checked_blocks := p010_checked_blocks.certify
theorem p010_checked_blocks_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p010_checked_blocks_algorithm xs) := p010_checked_blocks.run_spec xs
theorem p010_checked_blocks_cost {α : Type} [LinearOrder α] (xs : List α) : (p010_checked_blocks.eval xs).time ≤ p010_checked_blocks_costFormula xs.length := p010_checked_blocks.cost_le_upper xs
theorem p010_checked_blocks_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p010_checked_blocks.Ready xs) : (p010_checked_blocks.eval xs).time ≤ p010_checked_blocks_conditionalFormula xs.length := p010_checked_blocks.cost_le_readyUpper xs h
theorem p010_checked_blocks_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p010_checked_blocks.program xs) (p010_checked_blocks_algorithm xs) (p010_checked_blocks.eval xs).time := p010_checked_blocks.operational_certificate xs
theorem p010_checked_blocks_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p010_checked_blocks.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p010_checked_blocks.cost_isBigO_of_upper _ p010_checked_blocks.upper_isBigO_quadratic
theorem p010_checked_blocks_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p010_checked_blocks.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p010_checked_blocks.cost_isBigO_of_upper _ (p010_checked_blocks.upper_isBigO_nlog 37 rfl)
theorem p010_checked_blocks_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p010_checked_blocks.Ready xs} => ((p010_checked_blocks.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p010_checked_blocks.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p010_checked_blocks.Ready xs} => (xs.val.length : ℝ)) := p010_checked_blocks.ready_cost_isBigO_linear 1 rfl
theorem p010_checked_blocks_formula_0 : p010_checked_blocks_costFormula 0 = 0 ∧ p010_checked_blocks_conditionalFormula 0 = 0 := by decide +kernel
theorem p010_checked_blocks_formula_1 : p010_checked_blocks_costFormula 1 = 1 ∧ p010_checked_blocks_conditionalFormula 1 = 1 := by decide +kernel
theorem p010_checked_blocks_formula_8 : p010_checked_blocks_costFormula 8 = 43 ∧ p010_checked_blocks_conditionalFormula 8 = 15 := by decide +kernel
theorem p010_checked_blocks_formula_16 : p010_checked_blocks_costFormula 16 = 151 ∧ p010_checked_blocks_conditionalFormula 16 = 31 := by decide +kernel
theorem p010_checked_blocks_formula_32 : p010_checked_blocks_costFormula 32 = 302 ∧ p010_checked_blocks_conditionalFormula 32 = 62 := by decide +kernel
theorem p010_checked_blocks_formula_64 : p010_checked_blocks_costFormula 64 = 606 ∧ p010_checked_blocks_conditionalFormula 64 = 126 := by decide +kernel
theorem p010_checked_blocks_formula_128 : p010_checked_blocks_costFormula 128 = 1438 ∧ p010_checked_blocks_conditionalFormula 128 = 254 := by decide +kernel
#print axioms p010_checked_blocks_certificate
#print axioms p010_checked_blocks_correct
#print axioms p010_checked_blocks_cost
#print axioms p010_checked_blocks_conditional
#print axioms p010_checked_blocks_operational
#print axioms p010_checked_blocks_quadratic
#print axioms p010_checked_blocks_nlog
#print axioms p010_checked_blocks_conditional_linear
theorem p011_nested_certificate : Certificate p011_nested := p011_nested.certify
theorem p011_nested_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p011_nested_algorithm xs) := p011_nested.run_spec xs
theorem p011_nested_cost {α : Type} [LinearOrder α] (xs : List α) : (p011_nested.eval xs).time ≤ p011_nested_costFormula xs.length := p011_nested.cost_le_upper xs
theorem p011_nested_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p011_nested.Ready xs) : (p011_nested.eval xs).time ≤ p011_nested_conditionalFormula xs.length := p011_nested.cost_le_readyUpper xs h
theorem p011_nested_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p011_nested.program xs) (p011_nested_algorithm xs) (p011_nested.eval xs).time := p011_nested.operational_certificate xs
theorem p011_nested_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p011_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p011_nested.cost_isBigO_of_upper _ p011_nested.upper_isBigO_quadratic
theorem p011_nested_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p011_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p011_nested.cost_isBigO_of_upper _ (p011_nested.upper_isBigO_nlog 37 rfl)
theorem p011_nested_formula_0 : p011_nested_costFormula 0 = 0 ∧ p011_nested_conditionalFormula 0 = 0 := by decide +kernel
theorem p011_nested_formula_1 : p011_nested_costFormula 1 = 1 ∧ p011_nested_conditionalFormula 1 = 1 := by decide +kernel
theorem p011_nested_formula_8 : p011_nested_costFormula 8 = 36 ∧ p011_nested_conditionalFormula 8 = 36 := by decide +kernel
theorem p011_nested_formula_16 : p011_nested_costFormula 16 = 136 ∧ p011_nested_conditionalFormula 16 = 136 := by decide +kernel
theorem p011_nested_formula_32 : p011_nested_costFormula 32 = 220 ∧ p011_nested_conditionalFormula 32 = 220 := by decide +kernel
theorem p011_nested_formula_64 : p011_nested_costFormula 64 = 508 ∧ p011_nested_conditionalFormula 64 = 508 := by decide +kernel
theorem p011_nested_formula_128 : p011_nested_costFormula 128 = 1172 ∧ p011_nested_conditionalFormula 128 = 1172 := by decide +kernel
#print axioms p011_nested_certificate
#print axioms p011_nested_correct
#print axioms p011_nested_cost
#print axioms p011_nested_conditional
#print axioms p011_nested_operational
#print axioms p011_nested_quadratic
#print axioms p011_nested_nlog
theorem p012_split_certificate : Certificate p012_split := p012_split.certify
theorem p012_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p012_split_algorithm xs) := p012_split.run_spec xs
theorem p012_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p012_split.eval xs).time ≤ p012_split_costFormula xs.length := p012_split.cost_le_upper xs
theorem p012_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p012_split.Ready xs) : (p012_split.eval xs).time ≤ p012_split_conditionalFormula xs.length := p012_split.cost_le_readyUpper xs h
theorem p012_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p012_split.program xs) (p012_split_algorithm xs) (p012_split.eval xs).time := p012_split.operational_certificate xs
theorem p012_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p012_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p012_split.cost_isBigO_of_upper _ p012_split.upper_isBigO_quadratic
theorem p012_split_formula_0 : p012_split_costFormula 0 = 0 ∧ p012_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p012_split_formula_1 : p012_split_costFormula 1 = 1 ∧ p012_split_conditionalFormula 1 = 1 := by decide +kernel
theorem p012_split_formula_8 : p012_split_costFormula 8 = 22 ∧ p012_split_conditionalFormula 8 = 22 := by decide +kernel
theorem p012_split_formula_16 : p012_split_costFormula 16 = 68 ∧ p012_split_conditionalFormula 16 = 68 := by decide +kernel
theorem p012_split_formula_32 : p012_split_costFormula 32 = 216 ∧ p012_split_conditionalFormula 32 = 216 := by decide +kernel
theorem p012_split_formula_64 : p012_split_costFormula 64 = 720 ∧ p012_split_conditionalFormula 64 = 720 := by decide +kernel
theorem p012_split_formula_128 : p012_split_costFormula 128 = 2528 ∧ p012_split_conditionalFormula 128 = 2528 := by decide +kernel
#print axioms p012_split_certificate
#print axioms p012_split_correct
#print axioms p012_split_cost
#print axioms p012_split_conditional
#print axioms p012_split_operational
#print axioms p012_split_quadratic
theorem p013_guarded_split_certificate : Certificate p013_guarded_split := p013_guarded_split.certify
theorem p013_guarded_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p013_guarded_split_algorithm xs) := p013_guarded_split.run_spec xs
theorem p013_guarded_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p013_guarded_split.eval xs).time ≤ p013_guarded_split_costFormula xs.length := p013_guarded_split.cost_le_upper xs
theorem p013_guarded_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p013_guarded_split.Ready xs) : (p013_guarded_split.eval xs).time ≤ p013_guarded_split_conditionalFormula xs.length := p013_guarded_split.cost_le_readyUpper xs h
theorem p013_guarded_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p013_guarded_split.program xs) (p013_guarded_split_algorithm xs) (p013_guarded_split.eval xs).time := p013_guarded_split.operational_certificate xs
theorem p013_guarded_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p013_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p013_guarded_split.cost_isBigO_of_upper _ p013_guarded_split.upper_isBigO_quadratic
theorem p013_guarded_split_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p013_guarded_split.Ready xs} => ((p013_guarded_split.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p013_guarded_split.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p013_guarded_split.Ready xs} => (xs.val.length : ℝ)) := p013_guarded_split.ready_cost_isBigO_linear 0 rfl
theorem p013_guarded_split_formula_0 : p013_guarded_split_costFormula 0 = 0 ∧ p013_guarded_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p013_guarded_split_formula_1 : p013_guarded_split_costFormula 1 = 1 ∧ p013_guarded_split_conditionalFormula 1 = 0 := by decide +kernel
theorem p013_guarded_split_formula_8 : p013_guarded_split_costFormula 8 = 29 ∧ p013_guarded_split_conditionalFormula 8 = 7 := by decide +kernel
theorem p013_guarded_split_formula_16 : p013_guarded_split_costFormula 16 = 83 ∧ p013_guarded_split_conditionalFormula 16 = 15 := by decide +kernel
theorem p013_guarded_split_formula_32 : p013_guarded_split_costFormula 32 = 247 ∧ p013_guarded_split_conditionalFormula 32 = 31 := by decide +kernel
theorem p013_guarded_split_formula_64 : p013_guarded_split_costFormula 64 = 783 ∧ p013_guarded_split_conditionalFormula 64 = 63 := by decide +kernel
theorem p013_guarded_split_formula_128 : p013_guarded_split_costFormula 128 = 2655 ∧ p013_guarded_split_conditionalFormula 128 = 127 := by decide +kernel
#print axioms p013_guarded_split_certificate
#print axioms p013_guarded_split_correct
#print axioms p013_guarded_split_cost
#print axioms p013_guarded_split_conditional
#print axioms p013_guarded_split_operational
#print axioms p013_guarded_split_quadratic
#print axioms p013_guarded_split_conditional_linear
theorem p014_checked_blocks_certificate : Certificate p014_checked_blocks := p014_checked_blocks.certify
theorem p014_checked_blocks_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p014_checked_blocks_algorithm xs) := p014_checked_blocks.run_spec xs
theorem p014_checked_blocks_cost {α : Type} [LinearOrder α] (xs : List α) : (p014_checked_blocks.eval xs).time ≤ p014_checked_blocks_costFormula xs.length := p014_checked_blocks.cost_le_upper xs
theorem p014_checked_blocks_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p014_checked_blocks.Ready xs) : (p014_checked_blocks.eval xs).time ≤ p014_checked_blocks_conditionalFormula xs.length := p014_checked_blocks.cost_le_readyUpper xs h
theorem p014_checked_blocks_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p014_checked_blocks.program xs) (p014_checked_blocks_algorithm xs) (p014_checked_blocks.eval xs).time := p014_checked_blocks.operational_certificate xs
theorem p014_checked_blocks_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p014_checked_blocks.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p014_checked_blocks.cost_isBigO_of_upper _ p014_checked_blocks.upper_isBigO_quadratic
theorem p014_checked_blocks_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p014_checked_blocks.Ready xs} => ((p014_checked_blocks.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p014_checked_blocks.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p014_checked_blocks.Ready xs} => (xs.val.length : ℝ)) := p014_checked_blocks.ready_cost_isBigO_linear 1 rfl
theorem p014_checked_blocks_formula_0 : p014_checked_blocks_costFormula 0 = 0 ∧ p014_checked_blocks_conditionalFormula 0 = 0 := by decide +kernel
theorem p014_checked_blocks_formula_1 : p014_checked_blocks_costFormula 1 = 1 ∧ p014_checked_blocks_conditionalFormula 1 = 1 := by decide +kernel
theorem p014_checked_blocks_formula_8 : p014_checked_blocks_costFormula 8 = 28 ∧ p014_checked_blocks_conditionalFormula 8 = 14 := by decide +kernel
theorem p014_checked_blocks_formula_16 : p014_checked_blocks_costFormula 16 = 82 ∧ p014_checked_blocks_conditionalFormula 16 = 30 := by decide +kernel
theorem p014_checked_blocks_formula_32 : p014_checked_blocks_costFormula 32 = 246 ∧ p014_checked_blocks_conditionalFormula 32 = 62 := by decide +kernel
theorem p014_checked_blocks_formula_64 : p014_checked_blocks_costFormula 64 = 782 ∧ p014_checked_blocks_conditionalFormula 64 = 126 := by decide +kernel
theorem p014_checked_blocks_formula_128 : p014_checked_blocks_costFormula 128 = 2654 ∧ p014_checked_blocks_conditionalFormula 128 = 254 := by decide +kernel
#print axioms p014_checked_blocks_certificate
#print axioms p014_checked_blocks_correct
#print axioms p014_checked_blocks_cost
#print axioms p014_checked_blocks_conditional
#print axioms p014_checked_blocks_operational
#print axioms p014_checked_blocks_quadratic
#print axioms p014_checked_blocks_conditional_linear
theorem p015_nested_certificate : Certificate p015_nested := p015_nested.certify
theorem p015_nested_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p015_nested_algorithm xs) := p015_nested.run_spec xs
theorem p015_nested_cost {α : Type} [LinearOrder α] (xs : List α) : (p015_nested.eval xs).time ≤ p015_nested_costFormula xs.length := p015_nested.cost_le_upper xs
theorem p015_nested_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p015_nested.Ready xs) : (p015_nested.eval xs).time ≤ p015_nested_conditionalFormula xs.length := p015_nested.cost_le_readyUpper xs h
theorem p015_nested_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p015_nested.program xs) (p015_nested_algorithm xs) (p015_nested.eval xs).time := p015_nested.operational_certificate xs
theorem p015_nested_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p015_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p015_nested.cost_isBigO_of_upper _ p015_nested.upper_isBigO_quadratic
theorem p015_nested_formula_0 : p015_nested_costFormula 0 = 0 ∧ p015_nested_conditionalFormula 0 = 0 := by decide +kernel
theorem p015_nested_formula_1 : p015_nested_costFormula 1 = 2 ∧ p015_nested_conditionalFormula 1 = 2 := by decide +kernel
theorem p015_nested_formula_8 : p015_nested_costFormula 8 = 22 ∧ p015_nested_conditionalFormula 8 = 22 := by decide +kernel
theorem p015_nested_formula_16 : p015_nested_costFormula 16 = 68 ∧ p015_nested_conditionalFormula 16 = 68 := by decide +kernel
theorem p015_nested_formula_32 : p015_nested_costFormula 32 = 216 ∧ p015_nested_conditionalFormula 32 = 216 := by decide +kernel
theorem p015_nested_formula_64 : p015_nested_costFormula 64 = 720 ∧ p015_nested_conditionalFormula 64 = 720 := by decide +kernel
theorem p015_nested_formula_128 : p015_nested_costFormula 128 = 2528 ∧ p015_nested_conditionalFormula 128 = 2528 := by decide +kernel
#print axioms p015_nested_certificate
#print axioms p015_nested_correct
#print axioms p015_nested_cost
#print axioms p015_nested_conditional
#print axioms p015_nested_operational
#print axioms p015_nested_quadratic
theorem p016_split_certificate : Certificate p016_split := p016_split.certify
theorem p016_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p016_split_algorithm xs) := p016_split.run_spec xs
theorem p016_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p016_split.eval xs).time ≤ p016_split_costFormula xs.length := p016_split.cost_le_upper xs
theorem p016_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p016_split.Ready xs) : (p016_split.eval xs).time ≤ p016_split_conditionalFormula xs.length := p016_split.cost_le_readyUpper xs h
theorem p016_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p016_split.program xs) (p016_split_algorithm xs) (p016_split.eval xs).time := p016_split.operational_certificate xs
theorem p016_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p016_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p016_split.cost_isBigO_of_upper _ p016_split.upper_isBigO_quadratic
theorem p016_split_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p016_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p016_split.cost_isBigO_of_upper _ (p016_split.upper_isBigO_nlog 11 rfl)
theorem p016_split_formula_0 : p016_split_costFormula 0 = 0 ∧ p016_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p016_split_formula_1 : p016_split_costFormula 1 = 1 ∧ p016_split_conditionalFormula 1 = 1 := by decide +kernel
theorem p016_split_formula_8 : p016_split_costFormula 8 = 36 ∧ p016_split_conditionalFormula 8 = 36 := by decide +kernel
theorem p016_split_formula_16 : p016_split_costFormula 16 = 68 ∧ p016_split_conditionalFormula 16 = 68 := by decide +kernel
theorem p016_split_formula_32 : p016_split_costFormula 32 = 180 ∧ p016_split_conditionalFormula 32 = 180 := by decide +kernel
theorem p016_split_formula_64 : p016_split_costFormula 64 = 428 ∧ p016_split_conditionalFormula 64 = 428 := by decide +kernel
theorem p016_split_formula_128 : p016_split_costFormula 128 = 996 ∧ p016_split_conditionalFormula 128 = 996 := by decide +kernel
#print axioms p016_split_certificate
#print axioms p016_split_correct
#print axioms p016_split_cost
#print axioms p016_split_conditional
#print axioms p016_split_operational
#print axioms p016_split_quadratic
#print axioms p016_split_nlog
theorem p017_guarded_split_certificate : Certificate p017_guarded_split := p017_guarded_split.certify
theorem p017_guarded_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p017_guarded_split_algorithm xs) := p017_guarded_split.run_spec xs
theorem p017_guarded_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p017_guarded_split.eval xs).time ≤ p017_guarded_split_costFormula xs.length := p017_guarded_split.cost_le_upper xs
theorem p017_guarded_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p017_guarded_split.Ready xs) : (p017_guarded_split.eval xs).time ≤ p017_guarded_split_conditionalFormula xs.length := p017_guarded_split.cost_le_readyUpper xs h
theorem p017_guarded_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p017_guarded_split.program xs) (p017_guarded_split_algorithm xs) (p017_guarded_split.eval xs).time := p017_guarded_split.operational_certificate xs
theorem p017_guarded_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p017_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p017_guarded_split.cost_isBigO_of_upper _ p017_guarded_split.upper_isBigO_quadratic
theorem p017_guarded_split_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p017_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p017_guarded_split.cost_isBigO_of_upper _ (p017_guarded_split.upper_isBigO_nlog 12 rfl)
theorem p017_guarded_split_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p017_guarded_split.Ready xs} => ((p017_guarded_split.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p017_guarded_split.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p017_guarded_split.Ready xs} => (xs.val.length : ℝ)) := p017_guarded_split.ready_cost_isBigO_linear 0 rfl
theorem p017_guarded_split_formula_0 : p017_guarded_split_costFormula 0 = 0 ∧ p017_guarded_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p017_guarded_split_formula_1 : p017_guarded_split_costFormula 1 = 1 ∧ p017_guarded_split_conditionalFormula 1 = 0 := by decide +kernel
theorem p017_guarded_split_formula_8 : p017_guarded_split_costFormula 8 = 43 ∧ p017_guarded_split_conditionalFormula 8 = 7 := by decide +kernel
theorem p017_guarded_split_formula_16 : p017_guarded_split_costFormula 16 = 83 ∧ p017_guarded_split_conditionalFormula 16 = 15 := by decide +kernel
theorem p017_guarded_split_formula_32 : p017_guarded_split_costFormula 32 = 211 ∧ p017_guarded_split_conditionalFormula 32 = 31 := by decide +kernel
theorem p017_guarded_split_formula_64 : p017_guarded_split_costFormula 64 = 491 ∧ p017_guarded_split_conditionalFormula 64 = 63 := by decide +kernel
theorem p017_guarded_split_formula_128 : p017_guarded_split_costFormula 128 = 1123 ∧ p017_guarded_split_conditionalFormula 128 = 127 := by decide +kernel
#print axioms p017_guarded_split_certificate
#print axioms p017_guarded_split_correct
#print axioms p017_guarded_split_cost
#print axioms p017_guarded_split_conditional
#print axioms p017_guarded_split_operational
#print axioms p017_guarded_split_quadratic
#print axioms p017_guarded_split_nlog
#print axioms p017_guarded_split_conditional_linear
theorem p018_checked_blocks_certificate : Certificate p018_checked_blocks := p018_checked_blocks.certify
theorem p018_checked_blocks_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p018_checked_blocks_algorithm xs) := p018_checked_blocks.run_spec xs
theorem p018_checked_blocks_cost {α : Type} [LinearOrder α] (xs : List α) : (p018_checked_blocks.eval xs).time ≤ p018_checked_blocks_costFormula xs.length := p018_checked_blocks.cost_le_upper xs
theorem p018_checked_blocks_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p018_checked_blocks.Ready xs) : (p018_checked_blocks.eval xs).time ≤ p018_checked_blocks_conditionalFormula xs.length := p018_checked_blocks.cost_le_readyUpper xs h
theorem p018_checked_blocks_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p018_checked_blocks.program xs) (p018_checked_blocks_algorithm xs) (p018_checked_blocks.eval xs).time := p018_checked_blocks.operational_certificate xs
theorem p018_checked_blocks_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p018_checked_blocks.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p018_checked_blocks.cost_isBigO_of_upper _ p018_checked_blocks.upper_isBigO_quadratic
theorem p018_checked_blocks_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p018_checked_blocks.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p018_checked_blocks.cost_isBigO_of_upper _ (p018_checked_blocks.upper_isBigO_nlog 13 rfl)
theorem p018_checked_blocks_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p018_checked_blocks.Ready xs} => ((p018_checked_blocks.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p018_checked_blocks.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p018_checked_blocks.Ready xs} => (xs.val.length : ℝ)) := p018_checked_blocks.ready_cost_isBigO_linear 1 rfl
theorem p018_checked_blocks_formula_0 : p018_checked_blocks_costFormula 0 = 0 ∧ p018_checked_blocks_conditionalFormula 0 = 0 := by decide +kernel
theorem p018_checked_blocks_formula_1 : p018_checked_blocks_costFormula 1 = 1 ∧ p018_checked_blocks_conditionalFormula 1 = 1 := by decide +kernel
theorem p018_checked_blocks_formula_8 : p018_checked_blocks_costFormula 8 = 43 ∧ p018_checked_blocks_conditionalFormula 8 = 15 := by decide +kernel
theorem p018_checked_blocks_formula_16 : p018_checked_blocks_costFormula 16 = 82 ∧ p018_checked_blocks_conditionalFormula 16 = 30 := by decide +kernel
theorem p018_checked_blocks_formula_32 : p018_checked_blocks_costFormula 32 = 210 ∧ p018_checked_blocks_conditionalFormula 32 = 62 := by decide +kernel
theorem p018_checked_blocks_formula_64 : p018_checked_blocks_costFormula 64 = 490 ∧ p018_checked_blocks_conditionalFormula 64 = 126 := by decide +kernel
theorem p018_checked_blocks_formula_128 : p018_checked_blocks_costFormula 128 = 1122 ∧ p018_checked_blocks_conditionalFormula 128 = 254 := by decide +kernel
#print axioms p018_checked_blocks_certificate
#print axioms p018_checked_blocks_correct
#print axioms p018_checked_blocks_cost
#print axioms p018_checked_blocks_conditional
#print axioms p018_checked_blocks_operational
#print axioms p018_checked_blocks_quadratic
#print axioms p018_checked_blocks_nlog
#print axioms p018_checked_blocks_conditional_linear
theorem p019_nested_certificate : Certificate p019_nested := p019_nested.certify
theorem p019_nested_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p019_nested_algorithm xs) := p019_nested.run_spec xs
theorem p019_nested_cost {α : Type} [LinearOrder α] (xs : List α) : (p019_nested.eval xs).time ≤ p019_nested_costFormula xs.length := p019_nested.cost_le_upper xs
theorem p019_nested_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p019_nested.Ready xs) : (p019_nested.eval xs).time ≤ p019_nested_conditionalFormula xs.length := p019_nested.cost_le_readyUpper xs h
theorem p019_nested_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p019_nested.program xs) (p019_nested_algorithm xs) (p019_nested.eval xs).time := p019_nested.operational_certificate xs
theorem p019_nested_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p019_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p019_nested.cost_isBigO_of_upper _ p019_nested.upper_isBigO_quadratic
theorem p019_nested_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p019_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p019_nested.cost_isBigO_of_upper _ (p019_nested.upper_isBigO_nlog 13 rfl)
theorem p019_nested_formula_0 : p019_nested_costFormula 0 = 0 ∧ p019_nested_conditionalFormula 0 = 0 := by decide +kernel
theorem p019_nested_formula_1 : p019_nested_costFormula 1 = 1 ∧ p019_nested_conditionalFormula 1 = 1 := by decide +kernel
theorem p019_nested_formula_8 : p019_nested_costFormula 8 = 36 ∧ p019_nested_conditionalFormula 8 = 36 := by decide +kernel
theorem p019_nested_formula_16 : p019_nested_costFormula 16 = 68 ∧ p019_nested_conditionalFormula 16 = 68 := by decide +kernel
theorem p019_nested_formula_32 : p019_nested_costFormula 32 = 180 ∧ p019_nested_conditionalFormula 32 = 180 := by decide +kernel
theorem p019_nested_formula_64 : p019_nested_costFormula 64 = 428 ∧ p019_nested_conditionalFormula 64 = 428 := by decide +kernel
theorem p019_nested_formula_128 : p019_nested_costFormula 128 = 996 ∧ p019_nested_conditionalFormula 128 = 996 := by decide +kernel
#print axioms p019_nested_certificate
#print axioms p019_nested_correct
#print axioms p019_nested_cost
#print axioms p019_nested_conditional
#print axioms p019_nested_operational
#print axioms p019_nested_quadratic
#print axioms p019_nested_nlog
theorem p020_split_certificate : Certificate p020_split := p020_split.certify
theorem p020_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p020_split_algorithm xs) := p020_split.run_spec xs
theorem p020_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p020_split.eval xs).time ≤ p020_split_costFormula xs.length := p020_split.cost_le_upper xs
theorem p020_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p020_split.Ready xs) : (p020_split.eval xs).time ≤ p020_split_conditionalFormula xs.length := p020_split.cost_le_readyUpper xs h
theorem p020_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p020_split.program xs) (p020_split_algorithm xs) (p020_split.eval xs).time := p020_split.operational_certificate xs
theorem p020_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p020_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p020_split.cost_isBigO_of_upper _ p020_split.upper_isBigO_quadratic
theorem p020_split_formula_0 : p020_split_costFormula 0 = 0 ∧ p020_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p020_split_formula_1 : p020_split_costFormula 1 = 1 ∧ p020_split_conditionalFormula 1 = 1 := by decide +kernel
theorem p020_split_formula_8 : p020_split_costFormula 8 = 24 ∧ p020_split_conditionalFormula 8 = 24 := by decide +kernel
theorem p020_split_formula_16 : p020_split_costFormula 16 = 80 ∧ p020_split_conditionalFormula 16 = 80 := by decide +kernel
theorem p020_split_formula_32 : p020_split_costFormula 32 = 291 ∧ p020_split_conditionalFormula 32 = 291 := by decide +kernel
theorem p020_split_formula_64 : p020_split_costFormula 64 = 1048 ∧ p020_split_conditionalFormula 64 = 1048 := by decide +kernel
theorem p020_split_formula_128 : p020_split_costFormula 128 = 3987 ∧ p020_split_conditionalFormula 128 = 3987 := by decide +kernel
#print axioms p020_split_certificate
#print axioms p020_split_correct
#print axioms p020_split_cost
#print axioms p020_split_conditional
#print axioms p020_split_operational
#print axioms p020_split_quadratic
theorem p021_guarded_split_certificate : Certificate p021_guarded_split := p021_guarded_split.certify
theorem p021_guarded_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p021_guarded_split_algorithm xs) := p021_guarded_split.run_spec xs
theorem p021_guarded_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p021_guarded_split.eval xs).time ≤ p021_guarded_split_costFormula xs.length := p021_guarded_split.cost_le_upper xs
theorem p021_guarded_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p021_guarded_split.Ready xs) : (p021_guarded_split.eval xs).time ≤ p021_guarded_split_conditionalFormula xs.length := p021_guarded_split.cost_le_readyUpper xs h
theorem p021_guarded_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p021_guarded_split.program xs) (p021_guarded_split_algorithm xs) (p021_guarded_split.eval xs).time := p021_guarded_split.operational_certificate xs
theorem p021_guarded_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p021_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p021_guarded_split.cost_isBigO_of_upper _ p021_guarded_split.upper_isBigO_quadratic
theorem p021_guarded_split_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p021_guarded_split.Ready xs} => ((p021_guarded_split.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p021_guarded_split.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p021_guarded_split.Ready xs} => (xs.val.length : ℝ)) := p021_guarded_split.ready_cost_isBigO_linear 0 rfl
theorem p021_guarded_split_formula_0 : p021_guarded_split_costFormula 0 = 0 ∧ p021_guarded_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p021_guarded_split_formula_1 : p021_guarded_split_costFormula 1 = 1 ∧ p021_guarded_split_conditionalFormula 1 = 0 := by decide +kernel
theorem p021_guarded_split_formula_8 : p021_guarded_split_costFormula 8 = 31 ∧ p021_guarded_split_conditionalFormula 8 = 7 := by decide +kernel
theorem p021_guarded_split_formula_16 : p021_guarded_split_costFormula 16 = 95 ∧ p021_guarded_split_conditionalFormula 16 = 15 := by decide +kernel
theorem p021_guarded_split_formula_32 : p021_guarded_split_costFormula 32 = 322 ∧ p021_guarded_split_conditionalFormula 32 = 31 := by decide +kernel
theorem p021_guarded_split_formula_64 : p021_guarded_split_costFormula 64 = 1111 ∧ p021_guarded_split_conditionalFormula 64 = 63 := by decide +kernel
theorem p021_guarded_split_formula_128 : p021_guarded_split_costFormula 128 = 4114 ∧ p021_guarded_split_conditionalFormula 128 = 127 := by decide +kernel
#print axioms p021_guarded_split_certificate
#print axioms p021_guarded_split_correct
#print axioms p021_guarded_split_cost
#print axioms p021_guarded_split_conditional
#print axioms p021_guarded_split_operational
#print axioms p021_guarded_split_quadratic
#print axioms p021_guarded_split_conditional_linear
theorem p022_checked_blocks_certificate : Certificate p022_checked_blocks := p022_checked_blocks.certify
theorem p022_checked_blocks_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p022_checked_blocks_algorithm xs) := p022_checked_blocks.run_spec xs
theorem p022_checked_blocks_cost {α : Type} [LinearOrder α] (xs : List α) : (p022_checked_blocks.eval xs).time ≤ p022_checked_blocks_costFormula xs.length := p022_checked_blocks.cost_le_upper xs
theorem p022_checked_blocks_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p022_checked_blocks.Ready xs) : (p022_checked_blocks.eval xs).time ≤ p022_checked_blocks_conditionalFormula xs.length := p022_checked_blocks.cost_le_readyUpper xs h
theorem p022_checked_blocks_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p022_checked_blocks.program xs) (p022_checked_blocks_algorithm xs) (p022_checked_blocks.eval xs).time := p022_checked_blocks.operational_certificate xs
theorem p022_checked_blocks_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p022_checked_blocks.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p022_checked_blocks.cost_isBigO_of_upper _ p022_checked_blocks.upper_isBigO_quadratic
theorem p022_checked_blocks_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p022_checked_blocks.Ready xs} => ((p022_checked_blocks.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p022_checked_blocks.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p022_checked_blocks.Ready xs} => (xs.val.length : ℝ)) := p022_checked_blocks.ready_cost_isBigO_linear 1 rfl
theorem p022_checked_blocks_formula_0 : p022_checked_blocks_costFormula 0 = 0 ∧ p022_checked_blocks_conditionalFormula 0 = 0 := by decide +kernel
theorem p022_checked_blocks_formula_1 : p022_checked_blocks_costFormula 1 = 1 ∧ p022_checked_blocks_conditionalFormula 1 = 1 := by decide +kernel
theorem p022_checked_blocks_formula_8 : p022_checked_blocks_costFormula 8 = 30 ∧ p022_checked_blocks_conditionalFormula 8 = 14 := by decide +kernel
theorem p022_checked_blocks_formula_16 : p022_checked_blocks_costFormula 16 = 94 ∧ p022_checked_blocks_conditionalFormula 16 = 30 := by decide +kernel
theorem p022_checked_blocks_formula_32 : p022_checked_blocks_costFormula 32 = 321 ∧ p022_checked_blocks_conditionalFormula 32 = 62 := by decide +kernel
theorem p022_checked_blocks_formula_64 : p022_checked_blocks_costFormula 64 = 1110 ∧ p022_checked_blocks_conditionalFormula 64 = 126 := by decide +kernel
theorem p022_checked_blocks_formula_128 : p022_checked_blocks_costFormula 128 = 4113 ∧ p022_checked_blocks_conditionalFormula 128 = 254 := by decide +kernel
#print axioms p022_checked_blocks_certificate
#print axioms p022_checked_blocks_correct
#print axioms p022_checked_blocks_cost
#print axioms p022_checked_blocks_conditional
#print axioms p022_checked_blocks_operational
#print axioms p022_checked_blocks_quadratic
#print axioms p022_checked_blocks_conditional_linear
theorem p023_nested_certificate : Certificate p023_nested := p023_nested.certify
theorem p023_nested_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p023_nested_algorithm xs) := p023_nested.run_spec xs
theorem p023_nested_cost {α : Type} [LinearOrder α] (xs : List α) : (p023_nested.eval xs).time ≤ p023_nested_costFormula xs.length := p023_nested.cost_le_upper xs
theorem p023_nested_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p023_nested.Ready xs) : (p023_nested.eval xs).time ≤ p023_nested_conditionalFormula xs.length := p023_nested.cost_le_readyUpper xs h
theorem p023_nested_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p023_nested.program xs) (p023_nested_algorithm xs) (p023_nested.eval xs).time := p023_nested.operational_certificate xs
theorem p023_nested_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p023_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p023_nested.cost_isBigO_of_upper _ p023_nested.upper_isBigO_quadratic
theorem p023_nested_formula_0 : p023_nested_costFormula 0 = 0 ∧ p023_nested_conditionalFormula 0 = 0 := by decide +kernel
theorem p023_nested_formula_1 : p023_nested_costFormula 1 = 2 ∧ p023_nested_conditionalFormula 1 = 2 := by decide +kernel
theorem p023_nested_formula_8 : p023_nested_costFormula 8 = 24 ∧ p023_nested_conditionalFormula 8 = 24 := by decide +kernel
theorem p023_nested_formula_16 : p023_nested_costFormula 16 = 64 ∧ p023_nested_conditionalFormula 16 = 64 := by decide +kernel
theorem p023_nested_formula_32 : p023_nested_costFormula 32 = 181 ∧ p023_nested_conditionalFormula 32 = 181 := by decide +kernel
theorem p023_nested_formula_64 : p023_nested_costFormula 64 = 508 ∧ p023_nested_conditionalFormula 64 = 508 := by decide +kernel
theorem p023_nested_formula_128 : p023_nested_costFormula 128 = 1579 ∧ p023_nested_conditionalFormula 128 = 1579 := by decide +kernel
#print axioms p023_nested_certificate
#print axioms p023_nested_correct
#print axioms p023_nested_cost
#print axioms p023_nested_conditional
#print axioms p023_nested_operational
#print axioms p023_nested_quadratic
theorem p024_split_certificate : Certificate p024_split := p024_split.certify
theorem p024_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p024_split_algorithm xs) := p024_split.run_spec xs
theorem p024_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p024_split.eval xs).time ≤ p024_split_costFormula xs.length := p024_split.cost_le_upper xs
theorem p024_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p024_split.Ready xs) : (p024_split.eval xs).time ≤ p024_split_conditionalFormula xs.length := p024_split.cost_le_readyUpper xs h
theorem p024_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p024_split.program xs) (p024_split_algorithm xs) (p024_split.eval xs).time := p024_split.operational_certificate xs
theorem p024_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p024_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p024_split.cost_isBigO_of_upper _ p024_split.upper_isBigO_quadratic
theorem p024_split_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p024_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p024_split.cost_isBigO_of_upper _ (p024_split.upper_isBigO_nlog 7 rfl)
theorem p024_split_formula_0 : p024_split_costFormula 0 = 0 ∧ p024_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p024_split_formula_1 : p024_split_costFormula 1 = 1 ∧ p024_split_conditionalFormula 1 = 1 := by decide +kernel
theorem p024_split_formula_8 : p024_split_costFormula 8 = 23 ∧ p024_split_conditionalFormula 8 = 23 := by decide +kernel
theorem p024_split_formula_16 : p024_split_costFormula 16 = 62 ∧ p024_split_conditionalFormula 16 = 62 := by decide +kernel
theorem p024_split_formula_32 : p024_split_costFormula 32 = 157 ∧ p024_split_conditionalFormula 32 = 157 := by decide +kernel
theorem p024_split_formula_64 : p024_split_costFormula 64 = 378 ∧ p024_split_conditionalFormula 64 = 378 := by decide +kernel
theorem p024_split_formula_128 : p024_split_costFormula 128 = 885 ∧ p024_split_conditionalFormula 128 = 885 := by decide +kernel
#print axioms p024_split_certificate
#print axioms p024_split_correct
#print axioms p024_split_cost
#print axioms p024_split_conditional
#print axioms p024_split_operational
#print axioms p024_split_quadratic
#print axioms p024_split_nlog
theorem p025_guarded_split_certificate : Certificate p025_guarded_split := p025_guarded_split.certify
theorem p025_guarded_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p025_guarded_split_algorithm xs) := p025_guarded_split.run_spec xs
theorem p025_guarded_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p025_guarded_split.eval xs).time ≤ p025_guarded_split_costFormula xs.length := p025_guarded_split.cost_le_upper xs
theorem p025_guarded_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p025_guarded_split.Ready xs) : (p025_guarded_split.eval xs).time ≤ p025_guarded_split_conditionalFormula xs.length := p025_guarded_split.cost_le_readyUpper xs h
theorem p025_guarded_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p025_guarded_split.program xs) (p025_guarded_split_algorithm xs) (p025_guarded_split.eval xs).time := p025_guarded_split.operational_certificate xs
theorem p025_guarded_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p025_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p025_guarded_split.cost_isBigO_of_upper _ p025_guarded_split.upper_isBigO_quadratic
theorem p025_guarded_split_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p025_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p025_guarded_split.cost_isBigO_of_upper _ (p025_guarded_split.upper_isBigO_nlog 8 rfl)
theorem p025_guarded_split_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p025_guarded_split.Ready xs} => ((p025_guarded_split.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p025_guarded_split.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p025_guarded_split.Ready xs} => (xs.val.length : ℝ)) := p025_guarded_split.ready_cost_isBigO_linear 0 rfl
theorem p025_guarded_split_formula_0 : p025_guarded_split_costFormula 0 = 0 ∧ p025_guarded_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p025_guarded_split_formula_1 : p025_guarded_split_costFormula 1 = 1 ∧ p025_guarded_split_conditionalFormula 1 = 0 := by decide +kernel
theorem p025_guarded_split_formula_8 : p025_guarded_split_costFormula 8 = 30 ∧ p025_guarded_split_conditionalFormula 8 = 7 := by decide +kernel
theorem p025_guarded_split_formula_16 : p025_guarded_split_costFormula 16 = 77 ∧ p025_guarded_split_conditionalFormula 16 = 15 := by decide +kernel
theorem p025_guarded_split_formula_32 : p025_guarded_split_costFormula 32 = 188 ∧ p025_guarded_split_conditionalFormula 32 = 31 := by decide +kernel
theorem p025_guarded_split_formula_64 : p025_guarded_split_costFormula 64 = 441 ∧ p025_guarded_split_conditionalFormula 64 = 63 := by decide +kernel
theorem p025_guarded_split_formula_128 : p025_guarded_split_costFormula 128 = 1012 ∧ p025_guarded_split_conditionalFormula 128 = 127 := by decide +kernel
#print axioms p025_guarded_split_certificate
#print axioms p025_guarded_split_correct
#print axioms p025_guarded_split_cost
#print axioms p025_guarded_split_conditional
#print axioms p025_guarded_split_operational
#print axioms p025_guarded_split_quadratic
#print axioms p025_guarded_split_nlog
#print axioms p025_guarded_split_conditional_linear
theorem p026_checked_blocks_certificate : Certificate p026_checked_blocks := p026_checked_blocks.certify
theorem p026_checked_blocks_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p026_checked_blocks_algorithm xs) := p026_checked_blocks.run_spec xs
theorem p026_checked_blocks_cost {α : Type} [LinearOrder α] (xs : List α) : (p026_checked_blocks.eval xs).time ≤ p026_checked_blocks_costFormula xs.length := p026_checked_blocks.cost_le_upper xs
theorem p026_checked_blocks_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p026_checked_blocks.Ready xs) : (p026_checked_blocks.eval xs).time ≤ p026_checked_blocks_conditionalFormula xs.length := p026_checked_blocks.cost_le_readyUpper xs h
theorem p026_checked_blocks_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p026_checked_blocks.program xs) (p026_checked_blocks_algorithm xs) (p026_checked_blocks.eval xs).time := p026_checked_blocks.operational_certificate xs
theorem p026_checked_blocks_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p026_checked_blocks.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p026_checked_blocks.cost_isBigO_of_upper _ p026_checked_blocks.upper_isBigO_quadratic
theorem p026_checked_blocks_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p026_checked_blocks.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p026_checked_blocks.cost_isBigO_of_upper _ (p026_checked_blocks.upper_isBigO_nlog 9 rfl)
theorem p026_checked_blocks_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p026_checked_blocks.Ready xs} => ((p026_checked_blocks.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p026_checked_blocks.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p026_checked_blocks.Ready xs} => (xs.val.length : ℝ)) := p026_checked_blocks.ready_cost_isBigO_linear 1 rfl
theorem p026_checked_blocks_formula_0 : p026_checked_blocks_costFormula 0 = 0 ∧ p026_checked_blocks_conditionalFormula 0 = 0 := by decide +kernel
theorem p026_checked_blocks_formula_1 : p026_checked_blocks_costFormula 1 = 1 ∧ p026_checked_blocks_conditionalFormula 1 = 1 := by decide +kernel
theorem p026_checked_blocks_formula_8 : p026_checked_blocks_costFormula 8 = 29 ∧ p026_checked_blocks_conditionalFormula 8 = 14 := by decide +kernel
theorem p026_checked_blocks_formula_16 : p026_checked_blocks_costFormula 16 = 76 ∧ p026_checked_blocks_conditionalFormula 16 = 30 := by decide +kernel
theorem p026_checked_blocks_formula_32 : p026_checked_blocks_costFormula 32 = 187 ∧ p026_checked_blocks_conditionalFormula 32 = 62 := by decide +kernel
theorem p026_checked_blocks_formula_64 : p026_checked_blocks_costFormula 64 = 440 ∧ p026_checked_blocks_conditionalFormula 64 = 126 := by decide +kernel
theorem p026_checked_blocks_formula_128 : p026_checked_blocks_costFormula 128 = 1011 ∧ p026_checked_blocks_conditionalFormula 128 = 254 := by decide +kernel
#print axioms p026_checked_blocks_certificate
#print axioms p026_checked_blocks_correct
#print axioms p026_checked_blocks_cost
#print axioms p026_checked_blocks_conditional
#print axioms p026_checked_blocks_operational
#print axioms p026_checked_blocks_quadratic
#print axioms p026_checked_blocks_nlog
#print axioms p026_checked_blocks_conditional_linear
theorem p027_nested_certificate : Certificate p027_nested := p027_nested.certify
theorem p027_nested_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p027_nested_algorithm xs) := p027_nested.run_spec xs
theorem p027_nested_cost {α : Type} [LinearOrder α] (xs : List α) : (p027_nested.eval xs).time ≤ p027_nested_costFormula xs.length := p027_nested.cost_le_upper xs
theorem p027_nested_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p027_nested.Ready xs) : (p027_nested.eval xs).time ≤ p027_nested_conditionalFormula xs.length := p027_nested.cost_le_readyUpper xs h
theorem p027_nested_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p027_nested.program xs) (p027_nested_algorithm xs) (p027_nested.eval xs).time := p027_nested.operational_certificate xs
theorem p027_nested_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p027_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p027_nested.cost_isBigO_of_upper _ p027_nested.upper_isBigO_quadratic
theorem p027_nested_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p027_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p027_nested.cost_isBigO_of_upper _ (p027_nested.upper_isBigO_nlog 9 rfl)
theorem p027_nested_formula_0 : p027_nested_costFormula 0 = 0 ∧ p027_nested_conditionalFormula 0 = 0 := by decide +kernel
theorem p027_nested_formula_1 : p027_nested_costFormula 1 = 2 ∧ p027_nested_conditionalFormula 1 = 2 := by decide +kernel
theorem p027_nested_formula_8 : p027_nested_costFormula 8 = 22 ∧ p027_nested_conditionalFormula 8 = 22 := by decide +kernel
theorem p027_nested_formula_16 : p027_nested_costFormula 16 = 62 ∧ p027_nested_conditionalFormula 16 = 62 := by decide +kernel
theorem p027_nested_formula_32 : p027_nested_costFormula 32 = 157 ∧ p027_nested_conditionalFormula 32 = 157 := by decide +kernel
theorem p027_nested_formula_64 : p027_nested_costFormula 64 = 378 ∧ p027_nested_conditionalFormula 64 = 378 := by decide +kernel
theorem p027_nested_formula_128 : p027_nested_costFormula 128 = 885 ∧ p027_nested_conditionalFormula 128 = 885 := by decide +kernel
#print axioms p027_nested_certificate
#print axioms p027_nested_correct
#print axioms p027_nested_cost
#print axioms p027_nested_conditional
#print axioms p027_nested_operational
#print axioms p027_nested_quadratic
#print axioms p027_nested_nlog
theorem p028_split_certificate : Certificate p028_split := p028_split.certify
theorem p028_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p028_split_algorithm xs) := p028_split.run_spec xs
theorem p028_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p028_split.eval xs).time ≤ p028_split_costFormula xs.length := p028_split.cost_le_upper xs
theorem p028_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p028_split.Ready xs) : (p028_split.eval xs).time ≤ p028_split_conditionalFormula xs.length := p028_split.cost_le_readyUpper xs h
theorem p028_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p028_split.program xs) (p028_split_algorithm xs) (p028_split.eval xs).time := p028_split.operational_certificate xs
theorem p028_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p028_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p028_split.cost_isBigO_of_upper _ p028_split.upper_isBigO_quadratic
theorem p028_split_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p028_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p028_split.cost_isBigO_of_upper _ (p028_split.upper_isBigO_nlog 7 rfl)
theorem p028_split_formula_0 : p028_split_costFormula 0 = 0 ∧ p028_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p028_split_formula_1 : p028_split_costFormula 1 = 1 ∧ p028_split_conditionalFormula 1 = 1 := by decide +kernel
theorem p028_split_formula_8 : p028_split_costFormula 8 = 22 ∧ p028_split_conditionalFormula 8 = 22 := by decide +kernel
theorem p028_split_formula_16 : p028_split_costFormula 16 = 60 ∧ p028_split_conditionalFormula 16 = 60 := by decide +kernel
theorem p028_split_formula_32 : p028_split_costFormula 32 = 152 ∧ p028_split_conditionalFormula 32 = 152 := by decide +kernel
theorem p028_split_formula_64 : p028_split_costFormula 64 = 368 ∧ p028_split_conditionalFormula 64 = 368 := by decide +kernel
theorem p028_split_formula_128 : p028_split_costFormula 128 = 864 ∧ p028_split_conditionalFormula 128 = 864 := by decide +kernel
#print axioms p028_split_certificate
#print axioms p028_split_correct
#print axioms p028_split_cost
#print axioms p028_split_conditional
#print axioms p028_split_operational
#print axioms p028_split_quadratic
#print axioms p028_split_nlog
theorem p029_guarded_split_certificate : Certificate p029_guarded_split := p029_guarded_split.certify
theorem p029_guarded_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p029_guarded_split_algorithm xs) := p029_guarded_split.run_spec xs
theorem p029_guarded_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p029_guarded_split.eval xs).time ≤ p029_guarded_split_costFormula xs.length := p029_guarded_split.cost_le_upper xs
theorem p029_guarded_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p029_guarded_split.Ready xs) : (p029_guarded_split.eval xs).time ≤ p029_guarded_split_conditionalFormula xs.length := p029_guarded_split.cost_le_readyUpper xs h
theorem p029_guarded_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p029_guarded_split.program xs) (p029_guarded_split_algorithm xs) (p029_guarded_split.eval xs).time := p029_guarded_split.operational_certificate xs
theorem p029_guarded_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p029_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p029_guarded_split.cost_isBigO_of_upper _ p029_guarded_split.upper_isBigO_quadratic
theorem p029_guarded_split_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p029_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p029_guarded_split.cost_isBigO_of_upper _ (p029_guarded_split.upper_isBigO_nlog 8 rfl)
theorem p029_guarded_split_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p029_guarded_split.Ready xs} => ((p029_guarded_split.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p029_guarded_split.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p029_guarded_split.Ready xs} => (xs.val.length : ℝ)) := p029_guarded_split.ready_cost_isBigO_linear 0 rfl
theorem p029_guarded_split_formula_0 : p029_guarded_split_costFormula 0 = 0 ∧ p029_guarded_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p029_guarded_split_formula_1 : p029_guarded_split_costFormula 1 = 1 ∧ p029_guarded_split_conditionalFormula 1 = 0 := by decide +kernel
theorem p029_guarded_split_formula_8 : p029_guarded_split_costFormula 8 = 29 ∧ p029_guarded_split_conditionalFormula 8 = 7 := by decide +kernel
theorem p029_guarded_split_formula_16 : p029_guarded_split_costFormula 16 = 75 ∧ p029_guarded_split_conditionalFormula 16 = 15 := by decide +kernel
theorem p029_guarded_split_formula_32 : p029_guarded_split_costFormula 32 = 183 ∧ p029_guarded_split_conditionalFormula 32 = 31 := by decide +kernel
theorem p029_guarded_split_formula_64 : p029_guarded_split_costFormula 64 = 431 ∧ p029_guarded_split_conditionalFormula 64 = 63 := by decide +kernel
theorem p029_guarded_split_formula_128 : p029_guarded_split_costFormula 128 = 991 ∧ p029_guarded_split_conditionalFormula 128 = 127 := by decide +kernel
#print axioms p029_guarded_split_certificate
#print axioms p029_guarded_split_correct
#print axioms p029_guarded_split_cost
#print axioms p029_guarded_split_conditional
#print axioms p029_guarded_split_operational
#print axioms p029_guarded_split_quadratic
#print axioms p029_guarded_split_nlog
#print axioms p029_guarded_split_conditional_linear
theorem p030_checked_blocks_certificate : Certificate p030_checked_blocks := p030_checked_blocks.certify
theorem p030_checked_blocks_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p030_checked_blocks_algorithm xs) := p030_checked_blocks.run_spec xs
theorem p030_checked_blocks_cost {α : Type} [LinearOrder α] (xs : List α) : (p030_checked_blocks.eval xs).time ≤ p030_checked_blocks_costFormula xs.length := p030_checked_blocks.cost_le_upper xs
theorem p030_checked_blocks_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p030_checked_blocks.Ready xs) : (p030_checked_blocks.eval xs).time ≤ p030_checked_blocks_conditionalFormula xs.length := p030_checked_blocks.cost_le_readyUpper xs h
theorem p030_checked_blocks_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p030_checked_blocks.program xs) (p030_checked_blocks_algorithm xs) (p030_checked_blocks.eval xs).time := p030_checked_blocks.operational_certificate xs
theorem p030_checked_blocks_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p030_checked_blocks.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p030_checked_blocks.cost_isBigO_of_upper _ p030_checked_blocks.upper_isBigO_quadratic
theorem p030_checked_blocks_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p030_checked_blocks.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p030_checked_blocks.cost_isBigO_of_upper _ (p030_checked_blocks.upper_isBigO_nlog 9 rfl)
theorem p030_checked_blocks_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p030_checked_blocks.Ready xs} => ((p030_checked_blocks.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p030_checked_blocks.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p030_checked_blocks.Ready xs} => (xs.val.length : ℝ)) := p030_checked_blocks.ready_cost_isBigO_linear 1 rfl
theorem p030_checked_blocks_formula_0 : p030_checked_blocks_costFormula 0 = 0 ∧ p030_checked_blocks_conditionalFormula 0 = 0 := by decide +kernel
theorem p030_checked_blocks_formula_1 : p030_checked_blocks_costFormula 1 = 1 ∧ p030_checked_blocks_conditionalFormula 1 = 1 := by decide +kernel
theorem p030_checked_blocks_formula_8 : p030_checked_blocks_costFormula 8 = 28 ∧ p030_checked_blocks_conditionalFormula 8 = 14 := by decide +kernel
theorem p030_checked_blocks_formula_16 : p030_checked_blocks_costFormula 16 = 74 ∧ p030_checked_blocks_conditionalFormula 16 = 30 := by decide +kernel
theorem p030_checked_blocks_formula_32 : p030_checked_blocks_costFormula 32 = 182 ∧ p030_checked_blocks_conditionalFormula 32 = 62 := by decide +kernel
theorem p030_checked_blocks_formula_64 : p030_checked_blocks_costFormula 64 = 430 ∧ p030_checked_blocks_conditionalFormula 64 = 126 := by decide +kernel
theorem p030_checked_blocks_formula_128 : p030_checked_blocks_costFormula 128 = 990 ∧ p030_checked_blocks_conditionalFormula 128 = 254 := by decide +kernel
#print axioms p030_checked_blocks_certificate
#print axioms p030_checked_blocks_correct
#print axioms p030_checked_blocks_cost
#print axioms p030_checked_blocks_conditional
#print axioms p030_checked_blocks_operational
#print axioms p030_checked_blocks_quadratic
#print axioms p030_checked_blocks_nlog
#print axioms p030_checked_blocks_conditional_linear
theorem p031_nested_certificate : Certificate p031_nested := p031_nested.certify
theorem p031_nested_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p031_nested_algorithm xs) := p031_nested.run_spec xs
theorem p031_nested_cost {α : Type} [LinearOrder α] (xs : List α) : (p031_nested.eval xs).time ≤ p031_nested_costFormula xs.length := p031_nested.cost_le_upper xs
theorem p031_nested_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p031_nested.Ready xs) : (p031_nested.eval xs).time ≤ p031_nested_conditionalFormula xs.length := p031_nested.cost_le_readyUpper xs h
theorem p031_nested_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p031_nested.program xs) (p031_nested_algorithm xs) (p031_nested.eval xs).time := p031_nested.operational_certificate xs
theorem p031_nested_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p031_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p031_nested.cost_isBigO_of_upper _ p031_nested.upper_isBigO_quadratic
theorem p031_nested_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p031_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p031_nested.cost_isBigO_of_upper _ (p031_nested.upper_isBigO_nlog 9 rfl)
theorem p031_nested_formula_0 : p031_nested_costFormula 0 = 0 ∧ p031_nested_conditionalFormula 0 = 0 := by decide +kernel
theorem p031_nested_formula_1 : p031_nested_costFormula 1 = 2 ∧ p031_nested_conditionalFormula 1 = 2 := by decide +kernel
theorem p031_nested_formula_8 : p031_nested_costFormula 8 = 22 ∧ p031_nested_conditionalFormula 8 = 22 := by decide +kernel
theorem p031_nested_formula_16 : p031_nested_costFormula 16 = 60 ∧ p031_nested_conditionalFormula 16 = 60 := by decide +kernel
theorem p031_nested_formula_32 : p031_nested_costFormula 32 = 152 ∧ p031_nested_conditionalFormula 32 = 152 := by decide +kernel
theorem p031_nested_formula_64 : p031_nested_costFormula 64 = 368 ∧ p031_nested_conditionalFormula 64 = 368 := by decide +kernel
theorem p031_nested_formula_128 : p031_nested_costFormula 128 = 864 ∧ p031_nested_conditionalFormula 128 = 864 := by decide +kernel
#print axioms p031_nested_certificate
#print axioms p031_nested_correct
#print axioms p031_nested_cost
#print axioms p031_nested_conditional
#print axioms p031_nested_operational
#print axioms p031_nested_quadratic
#print axioms p031_nested_nlog
theorem p032_split_certificate : Certificate p032_split := p032_split.certify
theorem p032_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p032_split_algorithm xs) := p032_split.run_spec xs
theorem p032_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p032_split.eval xs).time ≤ p032_split_costFormula xs.length := p032_split.cost_le_upper xs
theorem p032_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p032_split.Ready xs) : (p032_split.eval xs).time ≤ p032_split_conditionalFormula xs.length := p032_split.cost_le_readyUpper xs h
theorem p032_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p032_split.program xs) (p032_split_algorithm xs) (p032_split.eval xs).time := p032_split.operational_certificate xs
theorem p032_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p032_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p032_split.cost_isBigO_of_upper _ p032_split.upper_isBigO_quadratic
theorem p032_split_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p032_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p032_split.cost_isBigO_of_upper _ (p032_split.upper_isBigO_nlog 23 rfl)
theorem p032_split_formula_0 : p032_split_costFormula 0 = 0 ∧ p032_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p032_split_formula_1 : p032_split_costFormula 1 = 1 ∧ p032_split_conditionalFormula 1 = 1 := by decide +kernel
theorem p032_split_formula_8 : p032_split_costFormula 8 = 36 ∧ p032_split_conditionalFormula 8 = 36 := by decide +kernel
theorem p032_split_formula_16 : p032_split_costFormula 16 = 64 ∧ p032_split_conditionalFormula 16 = 64 := by decide +kernel
theorem p032_split_formula_32 : p032_split_costFormula 32 = 156 ∧ p032_split_conditionalFormula 32 = 156 := by decide +kernel
theorem p032_split_formula_64 : p032_split_costFormula 64 = 388 ∧ p032_split_conditionalFormula 64 = 388 := by decide +kernel
theorem p032_split_formula_128 : p032_split_costFormula 128 = 924 ∧ p032_split_conditionalFormula 128 = 924 := by decide +kernel
#print axioms p032_split_certificate
#print axioms p032_split_correct
#print axioms p032_split_cost
#print axioms p032_split_conditional
#print axioms p032_split_operational
#print axioms p032_split_quadratic
#print axioms p032_split_nlog
theorem p033_guarded_split_certificate : Certificate p033_guarded_split := p033_guarded_split.certify
theorem p033_guarded_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p033_guarded_split_algorithm xs) := p033_guarded_split.run_spec xs
theorem p033_guarded_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p033_guarded_split.eval xs).time ≤ p033_guarded_split_costFormula xs.length := p033_guarded_split.cost_le_upper xs
theorem p033_guarded_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p033_guarded_split.Ready xs) : (p033_guarded_split.eval xs).time ≤ p033_guarded_split_conditionalFormula xs.length := p033_guarded_split.cost_le_readyUpper xs h
theorem p033_guarded_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p033_guarded_split.program xs) (p033_guarded_split_algorithm xs) (p033_guarded_split.eval xs).time := p033_guarded_split.operational_certificate xs
theorem p033_guarded_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p033_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p033_guarded_split.cost_isBigO_of_upper _ p033_guarded_split.upper_isBigO_quadratic
theorem p033_guarded_split_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p033_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p033_guarded_split.cost_isBigO_of_upper _ (p033_guarded_split.upper_isBigO_nlog 24 rfl)
theorem p033_guarded_split_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p033_guarded_split.Ready xs} => ((p033_guarded_split.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p033_guarded_split.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p033_guarded_split.Ready xs} => (xs.val.length : ℝ)) := p033_guarded_split.ready_cost_isBigO_linear 0 rfl
theorem p033_guarded_split_formula_0 : p033_guarded_split_costFormula 0 = 0 ∧ p033_guarded_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p033_guarded_split_formula_1 : p033_guarded_split_costFormula 1 = 1 ∧ p033_guarded_split_conditionalFormula 1 = 0 := by decide +kernel
theorem p033_guarded_split_formula_8 : p033_guarded_split_costFormula 8 = 43 ∧ p033_guarded_split_conditionalFormula 8 = 7 := by decide +kernel
theorem p033_guarded_split_formula_16 : p033_guarded_split_costFormula 16 = 79 ∧ p033_guarded_split_conditionalFormula 16 = 15 := by decide +kernel
theorem p033_guarded_split_formula_32 : p033_guarded_split_costFormula 32 = 187 ∧ p033_guarded_split_conditionalFormula 32 = 31 := by decide +kernel
theorem p033_guarded_split_formula_64 : p033_guarded_split_costFormula 64 = 451 ∧ p033_guarded_split_conditionalFormula 64 = 63 := by decide +kernel
theorem p033_guarded_split_formula_128 : p033_guarded_split_costFormula 128 = 1051 ∧ p033_guarded_split_conditionalFormula 128 = 127 := by decide +kernel
#print axioms p033_guarded_split_certificate
#print axioms p033_guarded_split_correct
#print axioms p033_guarded_split_cost
#print axioms p033_guarded_split_conditional
#print axioms p033_guarded_split_operational
#print axioms p033_guarded_split_quadratic
#print axioms p033_guarded_split_nlog
#print axioms p033_guarded_split_conditional_linear
theorem p034_checked_blocks_certificate : Certificate p034_checked_blocks := p034_checked_blocks.certify
theorem p034_checked_blocks_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p034_checked_blocks_algorithm xs) := p034_checked_blocks.run_spec xs
theorem p034_checked_blocks_cost {α : Type} [LinearOrder α] (xs : List α) : (p034_checked_blocks.eval xs).time ≤ p034_checked_blocks_costFormula xs.length := p034_checked_blocks.cost_le_upper xs
theorem p034_checked_blocks_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p034_checked_blocks.Ready xs) : (p034_checked_blocks.eval xs).time ≤ p034_checked_blocks_conditionalFormula xs.length := p034_checked_blocks.cost_le_readyUpper xs h
theorem p034_checked_blocks_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p034_checked_blocks.program xs) (p034_checked_blocks_algorithm xs) (p034_checked_blocks.eval xs).time := p034_checked_blocks.operational_certificate xs
theorem p034_checked_blocks_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p034_checked_blocks.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p034_checked_blocks.cost_isBigO_of_upper _ p034_checked_blocks.upper_isBigO_quadratic
theorem p034_checked_blocks_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p034_checked_blocks.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p034_checked_blocks.cost_isBigO_of_upper _ (p034_checked_blocks.upper_isBigO_nlog 25 rfl)
theorem p034_checked_blocks_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p034_checked_blocks.Ready xs} => ((p034_checked_blocks.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p034_checked_blocks.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p034_checked_blocks.Ready xs} => (xs.val.length : ℝ)) := p034_checked_blocks.ready_cost_isBigO_linear 1 rfl
theorem p034_checked_blocks_formula_0 : p034_checked_blocks_costFormula 0 = 0 ∧ p034_checked_blocks_conditionalFormula 0 = 0 := by decide +kernel
theorem p034_checked_blocks_formula_1 : p034_checked_blocks_costFormula 1 = 1 ∧ p034_checked_blocks_conditionalFormula 1 = 1 := by decide +kernel
theorem p034_checked_blocks_formula_8 : p034_checked_blocks_costFormula 8 = 43 ∧ p034_checked_blocks_conditionalFormula 8 = 15 := by decide +kernel
theorem p034_checked_blocks_formula_16 : p034_checked_blocks_costFormula 16 = 78 ∧ p034_checked_blocks_conditionalFormula 16 = 30 := by decide +kernel
theorem p034_checked_blocks_formula_32 : p034_checked_blocks_costFormula 32 = 186 ∧ p034_checked_blocks_conditionalFormula 32 = 62 := by decide +kernel
theorem p034_checked_blocks_formula_64 : p034_checked_blocks_costFormula 64 = 450 ∧ p034_checked_blocks_conditionalFormula 64 = 126 := by decide +kernel
theorem p034_checked_blocks_formula_128 : p034_checked_blocks_costFormula 128 = 1050 ∧ p034_checked_blocks_conditionalFormula 128 = 254 := by decide +kernel
#print axioms p034_checked_blocks_certificate
#print axioms p034_checked_blocks_correct
#print axioms p034_checked_blocks_cost
#print axioms p034_checked_blocks_conditional
#print axioms p034_checked_blocks_operational
#print axioms p034_checked_blocks_quadratic
#print axioms p034_checked_blocks_nlog
#print axioms p034_checked_blocks_conditional_linear
theorem p035_nested_certificate : Certificate p035_nested := p035_nested.certify
theorem p035_nested_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p035_nested_algorithm xs) := p035_nested.run_spec xs
theorem p035_nested_cost {α : Type} [LinearOrder α] (xs : List α) : (p035_nested.eval xs).time ≤ p035_nested_costFormula xs.length := p035_nested.cost_le_upper xs
theorem p035_nested_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p035_nested.Ready xs) : (p035_nested.eval xs).time ≤ p035_nested_conditionalFormula xs.length := p035_nested.cost_le_readyUpper xs h
theorem p035_nested_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p035_nested.program xs) (p035_nested_algorithm xs) (p035_nested.eval xs).time := p035_nested.operational_certificate xs
theorem p035_nested_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p035_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p035_nested.cost_isBigO_of_upper _ p035_nested.upper_isBigO_quadratic
theorem p035_nested_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p035_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p035_nested.cost_isBigO_of_upper _ (p035_nested.upper_isBigO_nlog 25 rfl)
theorem p035_nested_formula_0 : p035_nested_costFormula 0 = 0 ∧ p035_nested_conditionalFormula 0 = 0 := by decide +kernel
theorem p035_nested_formula_1 : p035_nested_costFormula 1 = 1 ∧ p035_nested_conditionalFormula 1 = 1 := by decide +kernel
theorem p035_nested_formula_8 : p035_nested_costFormula 8 = 36 ∧ p035_nested_conditionalFormula 8 = 36 := by decide +kernel
theorem p035_nested_formula_16 : p035_nested_costFormula 16 = 66 ∧ p035_nested_conditionalFormula 16 = 66 := by decide +kernel
theorem p035_nested_formula_32 : p035_nested_costFormula 32 = 168 ∧ p035_nested_conditionalFormula 32 = 168 := by decide +kernel
theorem p035_nested_formula_64 : p035_nested_costFormula 64 = 408 ∧ p035_nested_conditionalFormula 64 = 408 := by decide +kernel
theorem p035_nested_formula_128 : p035_nested_costFormula 128 = 960 ∧ p035_nested_conditionalFormula 128 = 960 := by decide +kernel
#print axioms p035_nested_certificate
#print axioms p035_nested_correct
#print axioms p035_nested_cost
#print axioms p035_nested_conditional
#print axioms p035_nested_operational
#print axioms p035_nested_quadratic
#print axioms p035_nested_nlog
theorem p036_guarded_split_certificate : Certificate p036_guarded_split := p036_guarded_split.certify
theorem p036_guarded_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p036_guarded_split_algorithm xs) := p036_guarded_split.run_spec xs
theorem p036_guarded_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p036_guarded_split.eval xs).time ≤ p036_guarded_split_costFormula xs.length := p036_guarded_split.cost_le_upper xs
theorem p036_guarded_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p036_guarded_split.Ready xs) : (p036_guarded_split.eval xs).time ≤ p036_guarded_split_conditionalFormula xs.length := p036_guarded_split.cost_le_readyUpper xs h
theorem p036_guarded_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p036_guarded_split.program xs) (p036_guarded_split_algorithm xs) (p036_guarded_split.eval xs).time := p036_guarded_split.operational_certificate xs
theorem p036_guarded_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p036_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p036_guarded_split.cost_isBigO_of_upper _ p036_guarded_split.upper_isBigO_quadratic
theorem p036_guarded_split_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p036_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p036_guarded_split.cost_isBigO_of_upper _ (p036_guarded_split.upper_isBigO_nlog 4 rfl)
theorem p036_guarded_split_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p036_guarded_split.Ready xs} => ((p036_guarded_split.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p036_guarded_split.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p036_guarded_split.Ready xs} => (xs.val.length : ℝ)) := p036_guarded_split.ready_cost_isBigO_linear 0 rfl
theorem p036_guarded_split_formula_0 : p036_guarded_split_costFormula 0 = 0 ∧ p036_guarded_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p036_guarded_split_formula_1 : p036_guarded_split_costFormula 1 = 1 ∧ p036_guarded_split_conditionalFormula 1 = 0 := by decide +kernel
theorem p036_guarded_split_formula_8 : p036_guarded_split_costFormula 8 = 31 ∧ p036_guarded_split_conditionalFormula 8 = 7 := by decide +kernel
theorem p036_guarded_split_formula_16 : p036_guarded_split_costFormula 16 = 79 ∧ p036_guarded_split_conditionalFormula 16 = 15 := by decide +kernel
theorem p036_guarded_split_formula_32 : p036_guarded_split_costFormula 32 = 191 ∧ p036_guarded_split_conditionalFormula 32 = 31 := by decide +kernel
theorem p036_guarded_split_formula_64 : p036_guarded_split_costFormula 64 = 447 ∧ p036_guarded_split_conditionalFormula 64 = 63 := by decide +kernel
theorem p036_guarded_split_formula_128 : p036_guarded_split_costFormula 128 = 1023 ∧ p036_guarded_split_conditionalFormula 128 = 127 := by decide +kernel
#print axioms p036_guarded_split_certificate
#print axioms p036_guarded_split_correct
#print axioms p036_guarded_split_cost
#print axioms p036_guarded_split_conditional
#print axioms p036_guarded_split_operational
#print axioms p036_guarded_split_quadratic
#print axioms p036_guarded_split_nlog
#print axioms p036_guarded_split_conditional_linear
theorem p037_nested_certificate : Certificate p037_nested := p037_nested.certify
theorem p037_nested_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p037_nested_algorithm xs) := p037_nested.run_spec xs
theorem p037_nested_cost {α : Type} [LinearOrder α] (xs : List α) : (p037_nested.eval xs).time ≤ p037_nested_costFormula xs.length := p037_nested.cost_le_upper xs
theorem p037_nested_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p037_nested.Ready xs) : (p037_nested.eval xs).time ≤ p037_nested_conditionalFormula xs.length := p037_nested.cost_le_readyUpper xs h
theorem p037_nested_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p037_nested.program xs) (p037_nested_algorithm xs) (p037_nested.eval xs).time := p037_nested.operational_certificate xs
theorem p037_nested_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p037_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p037_nested.cost_isBigO_of_upper _ p037_nested.upper_isBigO_quadratic
theorem p037_nested_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p037_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p037_nested.cost_isBigO_of_upper _ (p037_nested.upper_isBigO_nlog 5 rfl)
theorem p037_nested_formula_0 : p037_nested_costFormula 0 = 0 ∧ p037_nested_conditionalFormula 0 = 0 := by decide +kernel
theorem p037_nested_formula_1 : p037_nested_costFormula 1 = 2 ∧ p037_nested_conditionalFormula 1 = 2 := by decide +kernel
theorem p037_nested_formula_8 : p037_nested_costFormula 8 = 24 ∧ p037_nested_conditionalFormula 8 = 24 := by decide +kernel
theorem p037_nested_formula_16 : p037_nested_costFormula 16 = 64 ∧ p037_nested_conditionalFormula 16 = 64 := by decide +kernel
theorem p037_nested_formula_32 : p037_nested_costFormula 32 = 160 ∧ p037_nested_conditionalFormula 32 = 160 := by decide +kernel
theorem p037_nested_formula_64 : p037_nested_costFormula 64 = 384 ∧ p037_nested_conditionalFormula 64 = 384 := by decide +kernel
theorem p037_nested_formula_128 : p037_nested_costFormula 128 = 896 ∧ p037_nested_conditionalFormula 128 = 896 := by decide +kernel
#print axioms p037_nested_certificate
#print axioms p037_nested_correct
#print axioms p037_nested_cost
#print axioms p037_nested_conditional
#print axioms p037_nested_operational
#print axioms p037_nested_quadratic
#print axioms p037_nested_nlog
theorem p038_split_certificate : Certificate p038_split := p038_split.certify
theorem p038_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p038_split_algorithm xs) := p038_split.run_spec xs
theorem p038_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p038_split.eval xs).time ≤ p038_split_costFormula xs.length := p038_split.cost_le_upper xs
theorem p038_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p038_split.Ready xs) : (p038_split.eval xs).time ≤ p038_split_conditionalFormula xs.length := p038_split.cost_le_readyUpper xs h
theorem p038_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p038_split.program xs) (p038_split_algorithm xs) (p038_split.eval xs).time := p038_split.operational_certificate xs
theorem p038_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p038_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p038_split.cost_isBigO_of_upper _ p038_split.upper_isBigO_quadratic
theorem p038_split_formula_0 : p038_split_costFormula 0 = 0 ∧ p038_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p038_split_formula_1 : p038_split_costFormula 1 = 1 ∧ p038_split_conditionalFormula 1 = 1 := by decide +kernel
theorem p038_split_formula_8 : p038_split_costFormula 8 = 24 ∧ p038_split_conditionalFormula 8 = 24 := by decide +kernel
theorem p038_split_formula_16 : p038_split_costFormula 16 = 81 ∧ p038_split_conditionalFormula 16 = 81 := by decide +kernel
theorem p038_split_formula_32 : p038_split_costFormula 32 = 308 ∧ p038_split_conditionalFormula 32 = 308 := by decide +kernel
theorem p038_split_formula_64 : p038_split_costFormula 64 = 1088 ∧ p038_split_conditionalFormula 64 = 1088 := by decide +kernel
theorem p038_split_formula_128 : p038_split_costFormula 128 = 4067 ∧ p038_split_conditionalFormula 128 = 4067 := by decide +kernel
#print axioms p038_split_certificate
#print axioms p038_split_correct
#print axioms p038_split_cost
#print axioms p038_split_conditional
#print axioms p038_split_operational
#print axioms p038_split_quadratic
theorem p039_guarded_split_certificate : Certificate p039_guarded_split := p039_guarded_split.certify
theorem p039_guarded_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p039_guarded_split_algorithm xs) := p039_guarded_split.run_spec xs
theorem p039_guarded_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p039_guarded_split.eval xs).time ≤ p039_guarded_split_costFormula xs.length := p039_guarded_split.cost_le_upper xs
theorem p039_guarded_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p039_guarded_split.Ready xs) : (p039_guarded_split.eval xs).time ≤ p039_guarded_split_conditionalFormula xs.length := p039_guarded_split.cost_le_readyUpper xs h
theorem p039_guarded_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p039_guarded_split.program xs) (p039_guarded_split_algorithm xs) (p039_guarded_split.eval xs).time := p039_guarded_split.operational_certificate xs
theorem p039_guarded_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p039_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p039_guarded_split.cost_isBigO_of_upper _ p039_guarded_split.upper_isBigO_quadratic
theorem p039_guarded_split_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p039_guarded_split.Ready xs} => ((p039_guarded_split.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p039_guarded_split.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p039_guarded_split.Ready xs} => (xs.val.length : ℝ)) := p039_guarded_split.ready_cost_isBigO_linear 0 rfl
theorem p039_guarded_split_formula_0 : p039_guarded_split_costFormula 0 = 0 ∧ p039_guarded_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p039_guarded_split_formula_1 : p039_guarded_split_costFormula 1 = 1 ∧ p039_guarded_split_conditionalFormula 1 = 0 := by decide +kernel
theorem p039_guarded_split_formula_8 : p039_guarded_split_costFormula 8 = 31 ∧ p039_guarded_split_conditionalFormula 8 = 7 := by decide +kernel
theorem p039_guarded_split_formula_16 : p039_guarded_split_costFormula 16 = 96 ∧ p039_guarded_split_conditionalFormula 16 = 15 := by decide +kernel
theorem p039_guarded_split_formula_32 : p039_guarded_split_costFormula 32 = 339 ∧ p039_guarded_split_conditionalFormula 32 = 31 := by decide +kernel
theorem p039_guarded_split_formula_64 : p039_guarded_split_costFormula 64 = 1151 ∧ p039_guarded_split_conditionalFormula 64 = 63 := by decide +kernel
theorem p039_guarded_split_formula_128 : p039_guarded_split_costFormula 128 = 4194 ∧ p039_guarded_split_conditionalFormula 128 = 127 := by decide +kernel
#print axioms p039_guarded_split_certificate
#print axioms p039_guarded_split_correct
#print axioms p039_guarded_split_cost
#print axioms p039_guarded_split_conditional
#print axioms p039_guarded_split_operational
#print axioms p039_guarded_split_quadratic
#print axioms p039_guarded_split_conditional_linear
theorem p040_checked_blocks_certificate : Certificate p040_checked_blocks := p040_checked_blocks.certify
theorem p040_checked_blocks_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p040_checked_blocks_algorithm xs) := p040_checked_blocks.run_spec xs
theorem p040_checked_blocks_cost {α : Type} [LinearOrder α] (xs : List α) : (p040_checked_blocks.eval xs).time ≤ p040_checked_blocks_costFormula xs.length := p040_checked_blocks.cost_le_upper xs
theorem p040_checked_blocks_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p040_checked_blocks.Ready xs) : (p040_checked_blocks.eval xs).time ≤ p040_checked_blocks_conditionalFormula xs.length := p040_checked_blocks.cost_le_readyUpper xs h
theorem p040_checked_blocks_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p040_checked_blocks.program xs) (p040_checked_blocks_algorithm xs) (p040_checked_blocks.eval xs).time := p040_checked_blocks.operational_certificate xs
theorem p040_checked_blocks_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p040_checked_blocks.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p040_checked_blocks.cost_isBigO_of_upper _ p040_checked_blocks.upper_isBigO_quadratic
theorem p040_checked_blocks_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p040_checked_blocks.Ready xs} => ((p040_checked_blocks.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p040_checked_blocks.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p040_checked_blocks.Ready xs} => (xs.val.length : ℝ)) := p040_checked_blocks.ready_cost_isBigO_linear 1 rfl
theorem p040_checked_blocks_formula_0 : p040_checked_blocks_costFormula 0 = 0 ∧ p040_checked_blocks_conditionalFormula 0 = 0 := by decide +kernel
theorem p040_checked_blocks_formula_1 : p040_checked_blocks_costFormula 1 = 1 ∧ p040_checked_blocks_conditionalFormula 1 = 1 := by decide +kernel
theorem p040_checked_blocks_formula_8 : p040_checked_blocks_costFormula 8 = 30 ∧ p040_checked_blocks_conditionalFormula 8 = 14 := by decide +kernel
theorem p040_checked_blocks_formula_16 : p040_checked_blocks_costFormula 16 = 95 ∧ p040_checked_blocks_conditionalFormula 16 = 30 := by decide +kernel
theorem p040_checked_blocks_formula_32 : p040_checked_blocks_costFormula 32 = 338 ∧ p040_checked_blocks_conditionalFormula 32 = 62 := by decide +kernel
theorem p040_checked_blocks_formula_64 : p040_checked_blocks_costFormula 64 = 1150 ∧ p040_checked_blocks_conditionalFormula 64 = 126 := by decide +kernel
theorem p040_checked_blocks_formula_128 : p040_checked_blocks_costFormula 128 = 4193 ∧ p040_checked_blocks_conditionalFormula 128 = 254 := by decide +kernel
#print axioms p040_checked_blocks_certificate
#print axioms p040_checked_blocks_correct
#print axioms p040_checked_blocks_cost
#print axioms p040_checked_blocks_conditional
#print axioms p040_checked_blocks_operational
#print axioms p040_checked_blocks_quadratic
#print axioms p040_checked_blocks_conditional_linear
theorem p041_nested_certificate : Certificate p041_nested := p041_nested.certify
theorem p041_nested_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p041_nested_algorithm xs) := p041_nested.run_spec xs
theorem p041_nested_cost {α : Type} [LinearOrder α] (xs : List α) : (p041_nested.eval xs).time ≤ p041_nested_costFormula xs.length := p041_nested.cost_le_upper xs
theorem p041_nested_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p041_nested.Ready xs) : (p041_nested.eval xs).time ≤ p041_nested_conditionalFormula xs.length := p041_nested.cost_le_readyUpper xs h
theorem p041_nested_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p041_nested.program xs) (p041_nested_algorithm xs) (p041_nested.eval xs).time := p041_nested.operational_certificate xs
theorem p041_nested_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p041_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p041_nested.cost_isBigO_of_upper _ p041_nested.upper_isBigO_quadratic
theorem p041_nested_formula_0 : p041_nested_costFormula 0 = 0 ∧ p041_nested_conditionalFormula 0 = 0 := by decide +kernel
theorem p041_nested_formula_1 : p041_nested_costFormula 1 = 2 ∧ p041_nested_conditionalFormula 1 = 2 := by decide +kernel
theorem p041_nested_formula_8 : p041_nested_costFormula 8 = 24 ∧ p041_nested_conditionalFormula 8 = 24 := by decide +kernel
theorem p041_nested_formula_16 : p041_nested_costFormula 16 = 65 ∧ p041_nested_conditionalFormula 16 = 65 := by decide +kernel
theorem p041_nested_formula_32 : p041_nested_costFormula 32 = 198 ∧ p041_nested_conditionalFormula 32 = 198 := by decide +kernel
theorem p041_nested_formula_64 : p041_nested_costFormula 64 = 548 ∧ p041_nested_conditionalFormula 64 = 548 := by decide +kernel
theorem p041_nested_formula_128 : p041_nested_costFormula 128 = 1659 ∧ p041_nested_conditionalFormula 128 = 1659 := by decide +kernel
#print axioms p041_nested_certificate
#print axioms p041_nested_correct
#print axioms p041_nested_cost
#print axioms p041_nested_conditional
#print axioms p041_nested_operational
#print axioms p041_nested_quadratic
theorem p042_split_certificate : Certificate p042_split := p042_split.certify
theorem p042_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p042_split_algorithm xs) := p042_split.run_spec xs
theorem p042_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p042_split.eval xs).time ≤ p042_split_costFormula xs.length := p042_split.cost_le_upper xs
theorem p042_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p042_split.Ready xs) : (p042_split.eval xs).time ≤ p042_split_conditionalFormula xs.length := p042_split.cost_le_readyUpper xs h
theorem p042_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p042_split.program xs) (p042_split_algorithm xs) (p042_split.eval xs).time := p042_split.operational_certificate xs
theorem p042_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p042_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p042_split.cost_isBigO_of_upper _ p042_split.upper_isBigO_quadratic
theorem p042_split_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p042_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p042_split.cost_isBigO_of_upper _ (p042_split.upper_isBigO_nlog 11 rfl)
theorem p042_split_formula_0 : p042_split_costFormula 0 = 0 ∧ p042_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p042_split_formula_1 : p042_split_costFormula 1 = 1 ∧ p042_split_conditionalFormula 1 = 1 := by decide +kernel
theorem p042_split_formula_8 : p042_split_costFormula 8 = 24 ∧ p042_split_conditionalFormula 8 = 24 := by decide +kernel
theorem p042_split_formula_16 : p042_split_costFormula 16 = 64 ∧ p042_split_conditionalFormula 16 = 64 := by decide +kernel
theorem p042_split_formula_32 : p042_split_costFormula 32 = 163 ∧ p042_split_conditionalFormula 32 = 163 := by decide +kernel
theorem p042_split_formula_64 : p042_split_costFormula 64 = 390 ∧ p042_split_conditionalFormula 64 = 390 := by decide +kernel
theorem p042_split_formula_128 : p042_split_costFormula 128 = 911 ∧ p042_split_conditionalFormula 128 = 911 := by decide +kernel
#print axioms p042_split_certificate
#print axioms p042_split_correct
#print axioms p042_split_cost
#print axioms p042_split_conditional
#print axioms p042_split_operational
#print axioms p042_split_quadratic
#print axioms p042_split_nlog
theorem p043_guarded_split_certificate : Certificate p043_guarded_split := p043_guarded_split.certify
theorem p043_guarded_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p043_guarded_split_algorithm xs) := p043_guarded_split.run_spec xs
theorem p043_guarded_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p043_guarded_split.eval xs).time ≤ p043_guarded_split_costFormula xs.length := p043_guarded_split.cost_le_upper xs
theorem p043_guarded_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p043_guarded_split.Ready xs) : (p043_guarded_split.eval xs).time ≤ p043_guarded_split_conditionalFormula xs.length := p043_guarded_split.cost_le_readyUpper xs h
theorem p043_guarded_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p043_guarded_split.program xs) (p043_guarded_split_algorithm xs) (p043_guarded_split.eval xs).time := p043_guarded_split.operational_certificate xs
theorem p043_guarded_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p043_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p043_guarded_split.cost_isBigO_of_upper _ p043_guarded_split.upper_isBigO_quadratic
theorem p043_guarded_split_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p043_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p043_guarded_split.cost_isBigO_of_upper _ (p043_guarded_split.upper_isBigO_nlog 12 rfl)
theorem p043_guarded_split_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p043_guarded_split.Ready xs} => ((p043_guarded_split.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p043_guarded_split.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p043_guarded_split.Ready xs} => (xs.val.length : ℝ)) := p043_guarded_split.ready_cost_isBigO_linear 0 rfl
theorem p043_guarded_split_formula_0 : p043_guarded_split_costFormula 0 = 0 ∧ p043_guarded_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p043_guarded_split_formula_1 : p043_guarded_split_costFormula 1 = 1 ∧ p043_guarded_split_conditionalFormula 1 = 0 := by decide +kernel
theorem p043_guarded_split_formula_8 : p043_guarded_split_costFormula 8 = 31 ∧ p043_guarded_split_conditionalFormula 8 = 7 := by decide +kernel
theorem p043_guarded_split_formula_16 : p043_guarded_split_costFormula 16 = 79 ∧ p043_guarded_split_conditionalFormula 16 = 15 := by decide +kernel
theorem p043_guarded_split_formula_32 : p043_guarded_split_costFormula 32 = 194 ∧ p043_guarded_split_conditionalFormula 32 = 31 := by decide +kernel
theorem p043_guarded_split_formula_64 : p043_guarded_split_costFormula 64 = 453 ∧ p043_guarded_split_conditionalFormula 64 = 63 := by decide +kernel
theorem p043_guarded_split_formula_128 : p043_guarded_split_costFormula 128 = 1038 ∧ p043_guarded_split_conditionalFormula 128 = 127 := by decide +kernel
#print axioms p043_guarded_split_certificate
#print axioms p043_guarded_split_correct
#print axioms p043_guarded_split_cost
#print axioms p043_guarded_split_conditional
#print axioms p043_guarded_split_operational
#print axioms p043_guarded_split_quadratic
#print axioms p043_guarded_split_nlog
#print axioms p043_guarded_split_conditional_linear
theorem p044_checked_blocks_certificate : Certificate p044_checked_blocks := p044_checked_blocks.certify
theorem p044_checked_blocks_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p044_checked_blocks_algorithm xs) := p044_checked_blocks.run_spec xs
theorem p044_checked_blocks_cost {α : Type} [LinearOrder α] (xs : List α) : (p044_checked_blocks.eval xs).time ≤ p044_checked_blocks_costFormula xs.length := p044_checked_blocks.cost_le_upper xs
theorem p044_checked_blocks_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p044_checked_blocks.Ready xs) : (p044_checked_blocks.eval xs).time ≤ p044_checked_blocks_conditionalFormula xs.length := p044_checked_blocks.cost_le_readyUpper xs h
theorem p044_checked_blocks_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p044_checked_blocks.program xs) (p044_checked_blocks_algorithm xs) (p044_checked_blocks.eval xs).time := p044_checked_blocks.operational_certificate xs
theorem p044_checked_blocks_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p044_checked_blocks.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p044_checked_blocks.cost_isBigO_of_upper _ p044_checked_blocks.upper_isBigO_quadratic
theorem p044_checked_blocks_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p044_checked_blocks.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p044_checked_blocks.cost_isBigO_of_upper _ (p044_checked_blocks.upper_isBigO_nlog 13 rfl)
theorem p044_checked_blocks_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p044_checked_blocks.Ready xs} => ((p044_checked_blocks.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p044_checked_blocks.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p044_checked_blocks.Ready xs} => (xs.val.length : ℝ)) := p044_checked_blocks.ready_cost_isBigO_linear 1 rfl
theorem p044_checked_blocks_formula_0 : p044_checked_blocks_costFormula 0 = 0 ∧ p044_checked_blocks_conditionalFormula 0 = 0 := by decide +kernel
theorem p044_checked_blocks_formula_1 : p044_checked_blocks_costFormula 1 = 1 ∧ p044_checked_blocks_conditionalFormula 1 = 1 := by decide +kernel
theorem p044_checked_blocks_formula_8 : p044_checked_blocks_costFormula 8 = 30 ∧ p044_checked_blocks_conditionalFormula 8 = 14 := by decide +kernel
theorem p044_checked_blocks_formula_16 : p044_checked_blocks_costFormula 16 = 78 ∧ p044_checked_blocks_conditionalFormula 16 = 30 := by decide +kernel
theorem p044_checked_blocks_formula_32 : p044_checked_blocks_costFormula 32 = 193 ∧ p044_checked_blocks_conditionalFormula 32 = 62 := by decide +kernel
theorem p044_checked_blocks_formula_64 : p044_checked_blocks_costFormula 64 = 452 ∧ p044_checked_blocks_conditionalFormula 64 = 126 := by decide +kernel
theorem p044_checked_blocks_formula_128 : p044_checked_blocks_costFormula 128 = 1037 ∧ p044_checked_blocks_conditionalFormula 128 = 254 := by decide +kernel
#print axioms p044_checked_blocks_certificate
#print axioms p044_checked_blocks_correct
#print axioms p044_checked_blocks_cost
#print axioms p044_checked_blocks_conditional
#print axioms p044_checked_blocks_operational
#print axioms p044_checked_blocks_quadratic
#print axioms p044_checked_blocks_nlog
#print axioms p044_checked_blocks_conditional_linear
theorem p045_nested_certificate : Certificate p045_nested := p045_nested.certify
theorem p045_nested_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p045_nested_algorithm xs) := p045_nested.run_spec xs
theorem p045_nested_cost {α : Type} [LinearOrder α] (xs : List α) : (p045_nested.eval xs).time ≤ p045_nested_costFormula xs.length := p045_nested.cost_le_upper xs
theorem p045_nested_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p045_nested.Ready xs) : (p045_nested.eval xs).time ≤ p045_nested_conditionalFormula xs.length := p045_nested.cost_le_readyUpper xs h
theorem p045_nested_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p045_nested.program xs) (p045_nested_algorithm xs) (p045_nested.eval xs).time := p045_nested.operational_certificate xs
theorem p045_nested_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p045_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p045_nested.cost_isBigO_of_upper _ p045_nested.upper_isBigO_quadratic
theorem p045_nested_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p045_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p045_nested.cost_isBigO_of_upper _ (p045_nested.upper_isBigO_nlog 13 rfl)
theorem p045_nested_formula_0 : p045_nested_costFormula 0 = 0 ∧ p045_nested_conditionalFormula 0 = 0 := by decide +kernel
theorem p045_nested_formula_1 : p045_nested_costFormula 1 = 2 ∧ p045_nested_conditionalFormula 1 = 2 := by decide +kernel
theorem p045_nested_formula_8 : p045_nested_costFormula 8 = 23 ∧ p045_nested_conditionalFormula 8 = 23 := by decide +kernel
theorem p045_nested_formula_16 : p045_nested_costFormula 16 = 64 ∧ p045_nested_conditionalFormula 16 = 64 := by decide +kernel
theorem p045_nested_formula_32 : p045_nested_costFormula 32 = 163 ∧ p045_nested_conditionalFormula 32 = 163 := by decide +kernel
theorem p045_nested_formula_64 : p045_nested_costFormula 64 = 390 ∧ p045_nested_conditionalFormula 64 = 390 := by decide +kernel
theorem p045_nested_formula_128 : p045_nested_costFormula 128 = 911 ∧ p045_nested_conditionalFormula 128 = 911 := by decide +kernel
#print axioms p045_nested_certificate
#print axioms p045_nested_correct
#print axioms p045_nested_cost
#print axioms p045_nested_conditional
#print axioms p045_nested_operational
#print axioms p045_nested_quadratic
#print axioms p045_nested_nlog
theorem p046_split_certificate : Certificate p046_split := p046_split.certify
theorem p046_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p046_split_algorithm xs) := p046_split.run_spec xs
theorem p046_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p046_split.eval xs).time ≤ p046_split_costFormula xs.length := p046_split.cost_le_upper xs
theorem p046_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p046_split.Ready xs) : (p046_split.eval xs).time ≤ p046_split_conditionalFormula xs.length := p046_split.cost_le_readyUpper xs h
theorem p046_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p046_split.program xs) (p046_split_algorithm xs) (p046_split.eval xs).time := p046_split.operational_certificate xs
theorem p046_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p046_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p046_split.cost_isBigO_of_upper _ p046_split.upper_isBigO_quadratic
theorem p046_split_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p046_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p046_split.cost_isBigO_of_upper _ (p046_split.upper_isBigO_nlog 7 rfl)
theorem p046_split_formula_0 : p046_split_costFormula 0 = 0 ∧ p046_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p046_split_formula_1 : p046_split_costFormula 1 = 1 ∧ p046_split_conditionalFormula 1 = 1 := by decide +kernel
theorem p046_split_formula_8 : p046_split_costFormula 8 = 32 ∧ p046_split_conditionalFormula 8 = 32 := by decide +kernel
theorem p046_split_formula_16 : p046_split_costFormula 16 = 60 ∧ p046_split_conditionalFormula 16 = 60 := by decide +kernel
theorem p046_split_formula_32 : p046_split_costFormula 32 = 152 ∧ p046_split_conditionalFormula 32 = 152 := by decide +kernel
theorem p046_split_formula_64 : p046_split_costFormula 64 = 384 ∧ p046_split_conditionalFormula 64 = 384 := by decide +kernel
theorem p046_split_formula_128 : p046_split_costFormula 128 = 920 ∧ p046_split_conditionalFormula 128 = 920 := by decide +kernel
#print axioms p046_split_certificate
#print axioms p046_split_correct
#print axioms p046_split_cost
#print axioms p046_split_conditional
#print axioms p046_split_operational
#print axioms p046_split_quadratic
#print axioms p046_split_nlog
theorem p047_guarded_split_certificate : Certificate p047_guarded_split := p047_guarded_split.certify
theorem p047_guarded_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p047_guarded_split_algorithm xs) := p047_guarded_split.run_spec xs
theorem p047_guarded_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p047_guarded_split.eval xs).time ≤ p047_guarded_split_costFormula xs.length := p047_guarded_split.cost_le_upper xs
theorem p047_guarded_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p047_guarded_split.Ready xs) : (p047_guarded_split.eval xs).time ≤ p047_guarded_split_conditionalFormula xs.length := p047_guarded_split.cost_le_readyUpper xs h
theorem p047_guarded_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p047_guarded_split.program xs) (p047_guarded_split_algorithm xs) (p047_guarded_split.eval xs).time := p047_guarded_split.operational_certificate xs
theorem p047_guarded_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p047_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p047_guarded_split.cost_isBigO_of_upper _ p047_guarded_split.upper_isBigO_quadratic
theorem p047_guarded_split_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p047_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p047_guarded_split.cost_isBigO_of_upper _ (p047_guarded_split.upper_isBigO_nlog 8 rfl)
theorem p047_guarded_split_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p047_guarded_split.Ready xs} => ((p047_guarded_split.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p047_guarded_split.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p047_guarded_split.Ready xs} => (xs.val.length : ℝ)) := p047_guarded_split.ready_cost_isBigO_linear 0 rfl
theorem p047_guarded_split_formula_0 : p047_guarded_split_costFormula 0 = 0 ∧ p047_guarded_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p047_guarded_split_formula_1 : p047_guarded_split_costFormula 1 = 1 ∧ p047_guarded_split_conditionalFormula 1 = 0 := by decide +kernel
theorem p047_guarded_split_formula_8 : p047_guarded_split_costFormula 8 = 39 ∧ p047_guarded_split_conditionalFormula 8 = 7 := by decide +kernel
theorem p047_guarded_split_formula_16 : p047_guarded_split_costFormula 16 = 75 ∧ p047_guarded_split_conditionalFormula 16 = 15 := by decide +kernel
theorem p047_guarded_split_formula_32 : p047_guarded_split_costFormula 32 = 183 ∧ p047_guarded_split_conditionalFormula 32 = 31 := by decide +kernel
theorem p047_guarded_split_formula_64 : p047_guarded_split_costFormula 64 = 447 ∧ p047_guarded_split_conditionalFormula 64 = 63 := by decide +kernel
theorem p047_guarded_split_formula_128 : p047_guarded_split_costFormula 128 = 1047 ∧ p047_guarded_split_conditionalFormula 128 = 127 := by decide +kernel
#print axioms p047_guarded_split_certificate
#print axioms p047_guarded_split_correct
#print axioms p047_guarded_split_cost
#print axioms p047_guarded_split_conditional
#print axioms p047_guarded_split_operational
#print axioms p047_guarded_split_quadratic
#print axioms p047_guarded_split_nlog
#print axioms p047_guarded_split_conditional_linear
theorem p048_checked_blocks_certificate : Certificate p048_checked_blocks := p048_checked_blocks.certify
theorem p048_checked_blocks_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p048_checked_blocks_algorithm xs) := p048_checked_blocks.run_spec xs
theorem p048_checked_blocks_cost {α : Type} [LinearOrder α] (xs : List α) : (p048_checked_blocks.eval xs).time ≤ p048_checked_blocks_costFormula xs.length := p048_checked_blocks.cost_le_upper xs
theorem p048_checked_blocks_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p048_checked_blocks.Ready xs) : (p048_checked_blocks.eval xs).time ≤ p048_checked_blocks_conditionalFormula xs.length := p048_checked_blocks.cost_le_readyUpper xs h
theorem p048_checked_blocks_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p048_checked_blocks.program xs) (p048_checked_blocks_algorithm xs) (p048_checked_blocks.eval xs).time := p048_checked_blocks.operational_certificate xs
theorem p048_checked_blocks_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p048_checked_blocks.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p048_checked_blocks.cost_isBigO_of_upper _ p048_checked_blocks.upper_isBigO_quadratic
theorem p048_checked_blocks_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p048_checked_blocks.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p048_checked_blocks.cost_isBigO_of_upper _ (p048_checked_blocks.upper_isBigO_nlog 9 rfl)
theorem p048_checked_blocks_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p048_checked_blocks.Ready xs} => ((p048_checked_blocks.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p048_checked_blocks.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p048_checked_blocks.Ready xs} => (xs.val.length : ℝ)) := p048_checked_blocks.ready_cost_isBigO_linear 1 rfl
theorem p048_checked_blocks_formula_0 : p048_checked_blocks_costFormula 0 = 0 ∧ p048_checked_blocks_conditionalFormula 0 = 0 := by decide +kernel
theorem p048_checked_blocks_formula_1 : p048_checked_blocks_costFormula 1 = 1 ∧ p048_checked_blocks_conditionalFormula 1 = 1 := by decide +kernel
theorem p048_checked_blocks_formula_8 : p048_checked_blocks_costFormula 8 = 39 ∧ p048_checked_blocks_conditionalFormula 8 = 15 := by decide +kernel
theorem p048_checked_blocks_formula_16 : p048_checked_blocks_costFormula 16 = 74 ∧ p048_checked_blocks_conditionalFormula 16 = 30 := by decide +kernel
theorem p048_checked_blocks_formula_32 : p048_checked_blocks_costFormula 32 = 182 ∧ p048_checked_blocks_conditionalFormula 32 = 62 := by decide +kernel
theorem p048_checked_blocks_formula_64 : p048_checked_blocks_costFormula 64 = 446 ∧ p048_checked_blocks_conditionalFormula 64 = 126 := by decide +kernel
theorem p048_checked_blocks_formula_128 : p048_checked_blocks_costFormula 128 = 1046 ∧ p048_checked_blocks_conditionalFormula 128 = 254 := by decide +kernel
#print axioms p048_checked_blocks_certificate
#print axioms p048_checked_blocks_correct
#print axioms p048_checked_blocks_cost
#print axioms p048_checked_blocks_conditional
#print axioms p048_checked_blocks_operational
#print axioms p048_checked_blocks_quadratic
#print axioms p048_checked_blocks_nlog
#print axioms p048_checked_blocks_conditional_linear
theorem p049_nested_certificate : Certificate p049_nested := p049_nested.certify
theorem p049_nested_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p049_nested_algorithm xs) := p049_nested.run_spec xs
theorem p049_nested_cost {α : Type} [LinearOrder α] (xs : List α) : (p049_nested.eval xs).time ≤ p049_nested_costFormula xs.length := p049_nested.cost_le_upper xs
theorem p049_nested_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p049_nested.Ready xs) : (p049_nested.eval xs).time ≤ p049_nested_conditionalFormula xs.length := p049_nested.cost_le_readyUpper xs h
theorem p049_nested_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p049_nested.program xs) (p049_nested_algorithm xs) (p049_nested.eval xs).time := p049_nested.operational_certificate xs
theorem p049_nested_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p049_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p049_nested.cost_isBigO_of_upper _ p049_nested.upper_isBigO_quadratic
theorem p049_nested_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p049_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p049_nested.cost_isBigO_of_upper _ (p049_nested.upper_isBigO_nlog 9 rfl)
theorem p049_nested_formula_0 : p049_nested_costFormula 0 = 0 ∧ p049_nested_conditionalFormula 0 = 0 := by decide +kernel
theorem p049_nested_formula_1 : p049_nested_costFormula 1 = 1 ∧ p049_nested_conditionalFormula 1 = 1 := by decide +kernel
theorem p049_nested_formula_8 : p049_nested_costFormula 8 = 32 ∧ p049_nested_conditionalFormula 8 = 32 := by decide +kernel
theorem p049_nested_formula_16 : p049_nested_costFormula 16 = 62 ∧ p049_nested_conditionalFormula 16 = 62 := by decide +kernel
theorem p049_nested_formula_32 : p049_nested_costFormula 32 = 164 ∧ p049_nested_conditionalFormula 32 = 164 := by decide +kernel
theorem p049_nested_formula_64 : p049_nested_costFormula 64 = 404 ∧ p049_nested_conditionalFormula 64 = 404 := by decide +kernel
theorem p049_nested_formula_128 : p049_nested_costFormula 128 = 956 ∧ p049_nested_conditionalFormula 128 = 956 := by decide +kernel
#print axioms p049_nested_certificate
#print axioms p049_nested_correct
#print axioms p049_nested_cost
#print axioms p049_nested_conditional
#print axioms p049_nested_operational
#print axioms p049_nested_quadratic
#print axioms p049_nested_nlog
theorem p050_split_certificate : Certificate p050_split := p050_split.certify
theorem p050_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p050_split_algorithm xs) := p050_split.run_spec xs
theorem p050_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p050_split.eval xs).time ≤ p050_split_costFormula xs.length := p050_split.cost_le_upper xs
theorem p050_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p050_split.Ready xs) : (p050_split.eval xs).time ≤ p050_split_conditionalFormula xs.length := p050_split.cost_le_readyUpper xs h
theorem p050_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p050_split.program xs) (p050_split_algorithm xs) (p050_split.eval xs).time := p050_split.operational_certificate xs
theorem p050_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p050_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p050_split.cost_isBigO_of_upper _ p050_split.upper_isBigO_quadratic
theorem p050_split_formula_0 : p050_split_costFormula 0 = 0 ∧ p050_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p050_split_formula_1 : p050_split_costFormula 1 = 1 ∧ p050_split_conditionalFormula 1 = 1 := by decide +kernel
theorem p050_split_formula_8 : p050_split_costFormula 8 = 21 ∧ p050_split_conditionalFormula 8 = 21 := by decide +kernel
theorem p050_split_formula_16 : p050_split_costFormula 16 = 76 ∧ p050_split_conditionalFormula 16 = 76 := by decide +kernel
theorem p050_split_formula_32 : p050_split_costFormula 32 = 297 ∧ p050_split_conditionalFormula 32 = 297 := by decide +kernel
theorem p050_split_formula_64 : p050_split_costFormula 64 = 1057 ∧ p050_split_conditionalFormula 64 = 1057 := by decide +kernel
theorem p050_split_formula_128 : p050_split_costFormula 128 = 3994 ∧ p050_split_conditionalFormula 128 = 3994 := by decide +kernel
#print axioms p050_split_certificate
#print axioms p050_split_correct
#print axioms p050_split_cost
#print axioms p050_split_conditional
#print axioms p050_split_operational
#print axioms p050_split_quadratic
theorem p051_guarded_split_certificate : Certificate p051_guarded_split := p051_guarded_split.certify
theorem p051_guarded_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p051_guarded_split_algorithm xs) := p051_guarded_split.run_spec xs
theorem p051_guarded_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p051_guarded_split.eval xs).time ≤ p051_guarded_split_costFormula xs.length := p051_guarded_split.cost_le_upper xs
theorem p051_guarded_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p051_guarded_split.Ready xs) : (p051_guarded_split.eval xs).time ≤ p051_guarded_split_conditionalFormula xs.length := p051_guarded_split.cost_le_readyUpper xs h
theorem p051_guarded_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p051_guarded_split.program xs) (p051_guarded_split_algorithm xs) (p051_guarded_split.eval xs).time := p051_guarded_split.operational_certificate xs
theorem p051_guarded_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p051_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p051_guarded_split.cost_isBigO_of_upper _ p051_guarded_split.upper_isBigO_quadratic
theorem p051_guarded_split_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p051_guarded_split.Ready xs} => ((p051_guarded_split.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p051_guarded_split.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p051_guarded_split.Ready xs} => (xs.val.length : ℝ)) := p051_guarded_split.ready_cost_isBigO_linear 0 rfl
theorem p051_guarded_split_formula_0 : p051_guarded_split_costFormula 0 = 0 ∧ p051_guarded_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p051_guarded_split_formula_1 : p051_guarded_split_costFormula 1 = 1 ∧ p051_guarded_split_conditionalFormula 1 = 0 := by decide +kernel
theorem p051_guarded_split_formula_8 : p051_guarded_split_costFormula 8 = 28 ∧ p051_guarded_split_conditionalFormula 8 = 7 := by decide +kernel
theorem p051_guarded_split_formula_16 : p051_guarded_split_costFormula 16 = 91 ∧ p051_guarded_split_conditionalFormula 16 = 15 := by decide +kernel
theorem p051_guarded_split_formula_32 : p051_guarded_split_costFormula 32 = 328 ∧ p051_guarded_split_conditionalFormula 32 = 31 := by decide +kernel
theorem p051_guarded_split_formula_64 : p051_guarded_split_costFormula 64 = 1120 ∧ p051_guarded_split_conditionalFormula 64 = 63 := by decide +kernel
theorem p051_guarded_split_formula_128 : p051_guarded_split_costFormula 128 = 4121 ∧ p051_guarded_split_conditionalFormula 128 = 127 := by decide +kernel
#print axioms p051_guarded_split_certificate
#print axioms p051_guarded_split_correct
#print axioms p051_guarded_split_cost
#print axioms p051_guarded_split_conditional
#print axioms p051_guarded_split_operational
#print axioms p051_guarded_split_quadratic
#print axioms p051_guarded_split_conditional_linear
theorem p052_checked_blocks_certificate : Certificate p052_checked_blocks := p052_checked_blocks.certify
theorem p052_checked_blocks_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p052_checked_blocks_algorithm xs) := p052_checked_blocks.run_spec xs
theorem p052_checked_blocks_cost {α : Type} [LinearOrder α] (xs : List α) : (p052_checked_blocks.eval xs).time ≤ p052_checked_blocks_costFormula xs.length := p052_checked_blocks.cost_le_upper xs
theorem p052_checked_blocks_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p052_checked_blocks.Ready xs) : (p052_checked_blocks.eval xs).time ≤ p052_checked_blocks_conditionalFormula xs.length := p052_checked_blocks.cost_le_readyUpper xs h
theorem p052_checked_blocks_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p052_checked_blocks.program xs) (p052_checked_blocks_algorithm xs) (p052_checked_blocks.eval xs).time := p052_checked_blocks.operational_certificate xs
theorem p052_checked_blocks_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p052_checked_blocks.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p052_checked_blocks.cost_isBigO_of_upper _ p052_checked_blocks.upper_isBigO_quadratic
theorem p052_checked_blocks_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p052_checked_blocks.Ready xs} => ((p052_checked_blocks.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p052_checked_blocks.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p052_checked_blocks.Ready xs} => (xs.val.length : ℝ)) := p052_checked_blocks.ready_cost_isBigO_linear 1 rfl
theorem p052_checked_blocks_formula_0 : p052_checked_blocks_costFormula 0 = 0 ∧ p052_checked_blocks_conditionalFormula 0 = 0 := by decide +kernel
theorem p052_checked_blocks_formula_1 : p052_checked_blocks_costFormula 1 = 1 ∧ p052_checked_blocks_conditionalFormula 1 = 1 := by decide +kernel
theorem p052_checked_blocks_formula_8 : p052_checked_blocks_costFormula 8 = 27 ∧ p052_checked_blocks_conditionalFormula 8 = 14 := by decide +kernel
theorem p052_checked_blocks_formula_16 : p052_checked_blocks_costFormula 16 = 90 ∧ p052_checked_blocks_conditionalFormula 16 = 30 := by decide +kernel
theorem p052_checked_blocks_formula_32 : p052_checked_blocks_costFormula 32 = 327 ∧ p052_checked_blocks_conditionalFormula 32 = 62 := by decide +kernel
theorem p052_checked_blocks_formula_64 : p052_checked_blocks_costFormula 64 = 1119 ∧ p052_checked_blocks_conditionalFormula 64 = 126 := by decide +kernel
theorem p052_checked_blocks_formula_128 : p052_checked_blocks_costFormula 128 = 4120 ∧ p052_checked_blocks_conditionalFormula 128 = 254 := by decide +kernel
#print axioms p052_checked_blocks_certificate
#print axioms p052_checked_blocks_correct
#print axioms p052_checked_blocks_cost
#print axioms p052_checked_blocks_conditional
#print axioms p052_checked_blocks_operational
#print axioms p052_checked_blocks_quadratic
#print axioms p052_checked_blocks_conditional_linear
theorem p053_nested_certificate : Certificate p053_nested := p053_nested.certify
theorem p053_nested_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p053_nested_algorithm xs) := p053_nested.run_spec xs
theorem p053_nested_cost {α : Type} [LinearOrder α] (xs : List α) : (p053_nested.eval xs).time ≤ p053_nested_costFormula xs.length := p053_nested.cost_le_upper xs
theorem p053_nested_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p053_nested.Ready xs) : (p053_nested.eval xs).time ≤ p053_nested_conditionalFormula xs.length := p053_nested.cost_le_readyUpper xs h
theorem p053_nested_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p053_nested.program xs) (p053_nested_algorithm xs) (p053_nested.eval xs).time := p053_nested.operational_certificate xs
theorem p053_nested_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p053_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p053_nested.cost_isBigO_of_upper _ p053_nested.upper_isBigO_quadratic
theorem p053_nested_formula_0 : p053_nested_costFormula 0 = 0 ∧ p053_nested_conditionalFormula 0 = 0 := by decide +kernel
theorem p053_nested_formula_1 : p053_nested_costFormula 1 = 2 ∧ p053_nested_conditionalFormula 1 = 2 := by decide +kernel
theorem p053_nested_formula_8 : p053_nested_costFormula 8 = 23 ∧ p053_nested_conditionalFormula 8 = 23 := by decide +kernel
theorem p053_nested_formula_16 : p053_nested_costFormula 16 = 76 ∧ p053_nested_conditionalFormula 16 = 76 := by decide +kernel
theorem p053_nested_formula_32 : p053_nested_costFormula 32 = 281 ∧ p053_nested_conditionalFormula 32 = 281 := by decide +kernel
theorem p053_nested_formula_64 : p053_nested_costFormula 64 = 1046 ∧ p053_nested_conditionalFormula 64 = 1046 := by decide +kernel
theorem p053_nested_formula_128 : p053_nested_costFormula 128 = 3972 ∧ p053_nested_conditionalFormula 128 = 3972 := by decide +kernel
#print axioms p053_nested_certificate
#print axioms p053_nested_correct
#print axioms p053_nested_cost
#print axioms p053_nested_conditional
#print axioms p053_nested_operational
#print axioms p053_nested_quadratic
theorem p054_split_certificate : Certificate p054_split := p054_split.certify
theorem p054_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p054_split_algorithm xs) := p054_split.run_spec xs
theorem p054_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p054_split.eval xs).time ≤ p054_split_costFormula xs.length := p054_split.cost_le_upper xs
theorem p054_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p054_split.Ready xs) : (p054_split.eval xs).time ≤ p054_split_conditionalFormula xs.length := p054_split.cost_le_readyUpper xs h
theorem p054_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p054_split.program xs) (p054_split_algorithm xs) (p054_split.eval xs).time := p054_split.operational_certificate xs
theorem p054_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p054_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p054_split.cost_isBigO_of_upper _ p054_split.upper_isBigO_quadratic
theorem p054_split_formula_0 : p054_split_costFormula 0 = 0 ∧ p054_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p054_split_formula_1 : p054_split_costFormula 1 = 1 ∧ p054_split_conditionalFormula 1 = 1 := by decide +kernel
theorem p054_split_formula_8 : p054_split_costFormula 8 = 36 ∧ p054_split_conditionalFormula 8 = 36 := by decide +kernel
theorem p054_split_formula_16 : p054_split_costFormula 16 = 136 ∧ p054_split_conditionalFormula 16 = 136 := by decide +kernel
theorem p054_split_formula_32 : p054_split_costFormula 32 = 272 ∧ p054_split_conditionalFormula 32 = 272 := by decide +kernel
theorem p054_split_formula_64 : p054_split_costFormula 64 = 544 ∧ p054_split_conditionalFormula 64 = 544 := by decide +kernel
theorem p054_split_formula_128 : p054_split_costFormula 128 = 1312 ∧ p054_split_conditionalFormula 128 = 1312 := by decide +kernel
#print axioms p054_split_certificate
#print axioms p054_split_correct
#print axioms p054_split_cost
#print axioms p054_split_conditional
#print axioms p054_split_operational
#print axioms p054_split_quadratic
theorem p055_guarded_split_certificate : Certificate p055_guarded_split := p055_guarded_split.certify
theorem p055_guarded_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p055_guarded_split_algorithm xs) := p055_guarded_split.run_spec xs
theorem p055_guarded_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p055_guarded_split.eval xs).time ≤ p055_guarded_split_costFormula xs.length := p055_guarded_split.cost_le_upper xs
theorem p055_guarded_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p055_guarded_split.Ready xs) : (p055_guarded_split.eval xs).time ≤ p055_guarded_split_conditionalFormula xs.length := p055_guarded_split.cost_le_readyUpper xs h
theorem p055_guarded_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p055_guarded_split.program xs) (p055_guarded_split_algorithm xs) (p055_guarded_split.eval xs).time := p055_guarded_split.operational_certificate xs
theorem p055_guarded_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p055_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p055_guarded_split.cost_isBigO_of_upper _ p055_guarded_split.upper_isBigO_quadratic
theorem p055_guarded_split_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p055_guarded_split.Ready xs} => ((p055_guarded_split.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p055_guarded_split.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p055_guarded_split.Ready xs} => (xs.val.length : ℝ)) := p055_guarded_split.ready_cost_isBigO_linear 0 rfl
theorem p055_guarded_split_formula_0 : p055_guarded_split_costFormula 0 = 0 ∧ p055_guarded_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p055_guarded_split_formula_1 : p055_guarded_split_costFormula 1 = 1 ∧ p055_guarded_split_conditionalFormula 1 = 0 := by decide +kernel
theorem p055_guarded_split_formula_8 : p055_guarded_split_costFormula 8 = 43 ∧ p055_guarded_split_conditionalFormula 8 = 7 := by decide +kernel
theorem p055_guarded_split_formula_16 : p055_guarded_split_costFormula 16 = 151 ∧ p055_guarded_split_conditionalFormula 16 = 15 := by decide +kernel
theorem p055_guarded_split_formula_32 : p055_guarded_split_costFormula 32 = 303 ∧ p055_guarded_split_conditionalFormula 32 = 31 := by decide +kernel
theorem p055_guarded_split_formula_64 : p055_guarded_split_costFormula 64 = 607 ∧ p055_guarded_split_conditionalFormula 64 = 63 := by decide +kernel
theorem p055_guarded_split_formula_128 : p055_guarded_split_costFormula 128 = 1439 ∧ p055_guarded_split_conditionalFormula 128 = 127 := by decide +kernel
#print axioms p055_guarded_split_certificate
#print axioms p055_guarded_split_correct
#print axioms p055_guarded_split_cost
#print axioms p055_guarded_split_conditional
#print axioms p055_guarded_split_operational
#print axioms p055_guarded_split_quadratic
#print axioms p055_guarded_split_conditional_linear
theorem p056_checked_blocks_certificate : Certificate p056_checked_blocks := p056_checked_blocks.certify
theorem p056_checked_blocks_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p056_checked_blocks_algorithm xs) := p056_checked_blocks.run_spec xs
theorem p056_checked_blocks_cost {α : Type} [LinearOrder α] (xs : List α) : (p056_checked_blocks.eval xs).time ≤ p056_checked_blocks_costFormula xs.length := p056_checked_blocks.cost_le_upper xs
theorem p056_checked_blocks_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p056_checked_blocks.Ready xs) : (p056_checked_blocks.eval xs).time ≤ p056_checked_blocks_conditionalFormula xs.length := p056_checked_blocks.cost_le_readyUpper xs h
theorem p056_checked_blocks_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p056_checked_blocks.program xs) (p056_checked_blocks_algorithm xs) (p056_checked_blocks.eval xs).time := p056_checked_blocks.operational_certificate xs
theorem p056_checked_blocks_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p056_checked_blocks.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p056_checked_blocks.cost_isBigO_of_upper _ p056_checked_blocks.upper_isBigO_quadratic
theorem p056_checked_blocks_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p056_checked_blocks.Ready xs} => ((p056_checked_blocks.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p056_checked_blocks.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p056_checked_blocks.Ready xs} => (xs.val.length : ℝ)) := p056_checked_blocks.ready_cost_isBigO_linear 1 rfl
theorem p056_checked_blocks_formula_0 : p056_checked_blocks_costFormula 0 = 0 ∧ p056_checked_blocks_conditionalFormula 0 = 0 := by decide +kernel
theorem p056_checked_blocks_formula_1 : p056_checked_blocks_costFormula 1 = 1 ∧ p056_checked_blocks_conditionalFormula 1 = 1 := by decide +kernel
theorem p056_checked_blocks_formula_8 : p056_checked_blocks_costFormula 8 = 43 ∧ p056_checked_blocks_conditionalFormula 8 = 15 := by decide +kernel
theorem p056_checked_blocks_formula_16 : p056_checked_blocks_costFormula 16 = 151 ∧ p056_checked_blocks_conditionalFormula 16 = 31 := by decide +kernel
theorem p056_checked_blocks_formula_32 : p056_checked_blocks_costFormula 32 = 302 ∧ p056_checked_blocks_conditionalFormula 32 = 62 := by decide +kernel
theorem p056_checked_blocks_formula_64 : p056_checked_blocks_costFormula 64 = 606 ∧ p056_checked_blocks_conditionalFormula 64 = 126 := by decide +kernel
theorem p056_checked_blocks_formula_128 : p056_checked_blocks_costFormula 128 = 1438 ∧ p056_checked_blocks_conditionalFormula 128 = 254 := by decide +kernel
#print axioms p056_checked_blocks_certificate
#print axioms p056_checked_blocks_correct
#print axioms p056_checked_blocks_cost
#print axioms p056_checked_blocks_conditional
#print axioms p056_checked_blocks_operational
#print axioms p056_checked_blocks_quadratic
#print axioms p056_checked_blocks_conditional_linear
theorem p057_nested_certificate : Certificate p057_nested := p057_nested.certify
theorem p057_nested_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p057_nested_algorithm xs) := p057_nested.run_spec xs
theorem p057_nested_cost {α : Type} [LinearOrder α] (xs : List α) : (p057_nested.eval xs).time ≤ p057_nested_costFormula xs.length := p057_nested.cost_le_upper xs
theorem p057_nested_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p057_nested.Ready xs) : (p057_nested.eval xs).time ≤ p057_nested_conditionalFormula xs.length := p057_nested.cost_le_readyUpper xs h
theorem p057_nested_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p057_nested.program xs) (p057_nested_algorithm xs) (p057_nested.eval xs).time := p057_nested.operational_certificate xs
theorem p057_nested_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p057_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p057_nested.cost_isBigO_of_upper _ p057_nested.upper_isBigO_quadratic
theorem p057_nested_formula_0 : p057_nested_costFormula 0 = 0 ∧ p057_nested_conditionalFormula 0 = 0 := by decide +kernel
theorem p057_nested_formula_1 : p057_nested_costFormula 1 = 1 ∧ p057_nested_conditionalFormula 1 = 1 := by decide +kernel
theorem p057_nested_formula_8 : p057_nested_costFormula 8 = 36 ∧ p057_nested_conditionalFormula 8 = 36 := by decide +kernel
theorem p057_nested_formula_16 : p057_nested_costFormula 16 = 136 ∧ p057_nested_conditionalFormula 16 = 136 := by decide +kernel
theorem p057_nested_formula_32 : p057_nested_costFormula 32 = 220 ∧ p057_nested_conditionalFormula 32 = 220 := by decide +kernel
theorem p057_nested_formula_64 : p057_nested_costFormula 64 = 508 ∧ p057_nested_conditionalFormula 64 = 508 := by decide +kernel
theorem p057_nested_formula_128 : p057_nested_costFormula 128 = 1172 ∧ p057_nested_conditionalFormula 128 = 1172 := by decide +kernel
#print axioms p057_nested_certificate
#print axioms p057_nested_correct
#print axioms p057_nested_cost
#print axioms p057_nested_conditional
#print axioms p057_nested_operational
#print axioms p057_nested_quadratic
theorem p058_split_certificate : Certificate p058_split := p058_split.certify
theorem p058_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p058_split_algorithm xs) := p058_split.run_spec xs
theorem p058_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p058_split.eval xs).time ≤ p058_split_costFormula xs.length := p058_split.cost_le_upper xs
theorem p058_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p058_split.Ready xs) : (p058_split.eval xs).time ≤ p058_split_conditionalFormula xs.length := p058_split.cost_le_readyUpper xs h
theorem p058_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p058_split.program xs) (p058_split_algorithm xs) (p058_split.eval xs).time := p058_split.operational_certificate xs
theorem p058_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p058_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p058_split.cost_isBigO_of_upper _ p058_split.upper_isBigO_quadratic
theorem p058_split_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p058_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p058_split.cost_isBigO_of_upper _ (p058_split.upper_isBigO_nlog 19 rfl)
theorem p058_split_formula_0 : p058_split_costFormula 0 = 0 ∧ p058_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p058_split_formula_1 : p058_split_costFormula 1 = 1 ∧ p058_split_conditionalFormula 1 = 1 := by decide +kernel
theorem p058_split_formula_8 : p058_split_costFormula 8 = 36 ∧ p058_split_conditionalFormula 8 = 36 := by decide +kernel
theorem p058_split_formula_16 : p058_split_costFormula 16 = 88 ∧ p058_split_conditionalFormula 16 = 88 := by decide +kernel
theorem p058_split_formula_32 : p058_split_costFormula 32 = 176 ∧ p058_split_conditionalFormula 32 = 176 := by decide +kernel
theorem p058_split_formula_64 : p058_split_costFormula 64 = 400 ∧ p058_split_conditionalFormula 64 = 400 := by decide +kernel
theorem p058_split_formula_128 : p058_split_costFormula 128 = 984 ∧ p058_split_conditionalFormula 128 = 984 := by decide +kernel
#print axioms p058_split_certificate
#print axioms p058_split_correct
#print axioms p058_split_cost
#print axioms p058_split_conditional
#print axioms p058_split_operational
#print axioms p058_split_quadratic
#print axioms p058_split_nlog
theorem p059_guarded_split_certificate : Certificate p059_guarded_split := p059_guarded_split.certify
theorem p059_guarded_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p059_guarded_split_algorithm xs) := p059_guarded_split.run_spec xs
theorem p059_guarded_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p059_guarded_split.eval xs).time ≤ p059_guarded_split_costFormula xs.length := p059_guarded_split.cost_le_upper xs
theorem p059_guarded_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p059_guarded_split.Ready xs) : (p059_guarded_split.eval xs).time ≤ p059_guarded_split_conditionalFormula xs.length := p059_guarded_split.cost_le_readyUpper xs h
theorem p059_guarded_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p059_guarded_split.program xs) (p059_guarded_split_algorithm xs) (p059_guarded_split.eval xs).time := p059_guarded_split.operational_certificate xs
theorem p059_guarded_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p059_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p059_guarded_split.cost_isBigO_of_upper _ p059_guarded_split.upper_isBigO_quadratic
theorem p059_guarded_split_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p059_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p059_guarded_split.cost_isBigO_of_upper _ (p059_guarded_split.upper_isBigO_nlog 20 rfl)
theorem p059_guarded_split_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p059_guarded_split.Ready xs} => ((p059_guarded_split.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p059_guarded_split.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p059_guarded_split.Ready xs} => (xs.val.length : ℝ)) := p059_guarded_split.ready_cost_isBigO_linear 0 rfl
theorem p059_guarded_split_formula_0 : p059_guarded_split_costFormula 0 = 0 ∧ p059_guarded_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p059_guarded_split_formula_1 : p059_guarded_split_costFormula 1 = 1 ∧ p059_guarded_split_conditionalFormula 1 = 0 := by decide +kernel
theorem p059_guarded_split_formula_8 : p059_guarded_split_costFormula 8 = 43 ∧ p059_guarded_split_conditionalFormula 8 = 7 := by decide +kernel
theorem p059_guarded_split_formula_16 : p059_guarded_split_costFormula 16 = 103 ∧ p059_guarded_split_conditionalFormula 16 = 15 := by decide +kernel
theorem p059_guarded_split_formula_32 : p059_guarded_split_costFormula 32 = 207 ∧ p059_guarded_split_conditionalFormula 32 = 31 := by decide +kernel
theorem p059_guarded_split_formula_64 : p059_guarded_split_costFormula 64 = 463 ∧ p059_guarded_split_conditionalFormula 64 = 63 := by decide +kernel
theorem p059_guarded_split_formula_128 : p059_guarded_split_costFormula 128 = 1111 ∧ p059_guarded_split_conditionalFormula 128 = 127 := by decide +kernel
#print axioms p059_guarded_split_certificate
#print axioms p059_guarded_split_correct
#print axioms p059_guarded_split_cost
#print axioms p059_guarded_split_conditional
#print axioms p059_guarded_split_operational
#print axioms p059_guarded_split_quadratic
#print axioms p059_guarded_split_nlog
#print axioms p059_guarded_split_conditional_linear
theorem p060_checked_blocks_certificate : Certificate p060_checked_blocks := p060_checked_blocks.certify
theorem p060_checked_blocks_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p060_checked_blocks_algorithm xs) := p060_checked_blocks.run_spec xs
theorem p060_checked_blocks_cost {α : Type} [LinearOrder α] (xs : List α) : (p060_checked_blocks.eval xs).time ≤ p060_checked_blocks_costFormula xs.length := p060_checked_blocks.cost_le_upper xs
theorem p060_checked_blocks_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p060_checked_blocks.Ready xs) : (p060_checked_blocks.eval xs).time ≤ p060_checked_blocks_conditionalFormula xs.length := p060_checked_blocks.cost_le_readyUpper xs h
theorem p060_checked_blocks_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p060_checked_blocks.program xs) (p060_checked_blocks_algorithm xs) (p060_checked_blocks.eval xs).time := p060_checked_blocks.operational_certificate xs
theorem p060_checked_blocks_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p060_checked_blocks.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p060_checked_blocks.cost_isBigO_of_upper _ p060_checked_blocks.upper_isBigO_quadratic
theorem p060_checked_blocks_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p060_checked_blocks.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p060_checked_blocks.cost_isBigO_of_upper _ (p060_checked_blocks.upper_isBigO_nlog 21 rfl)
theorem p060_checked_blocks_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p060_checked_blocks.Ready xs} => ((p060_checked_blocks.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p060_checked_blocks.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p060_checked_blocks.Ready xs} => (xs.val.length : ℝ)) := p060_checked_blocks.ready_cost_isBigO_linear 1 rfl
theorem p060_checked_blocks_formula_0 : p060_checked_blocks_costFormula 0 = 0 ∧ p060_checked_blocks_conditionalFormula 0 = 0 := by decide +kernel
theorem p060_checked_blocks_formula_1 : p060_checked_blocks_costFormula 1 = 1 ∧ p060_checked_blocks_conditionalFormula 1 = 1 := by decide +kernel
theorem p060_checked_blocks_formula_8 : p060_checked_blocks_costFormula 8 = 43 ∧ p060_checked_blocks_conditionalFormula 8 = 15 := by decide +kernel
theorem p060_checked_blocks_formula_16 : p060_checked_blocks_costFormula 16 = 103 ∧ p060_checked_blocks_conditionalFormula 16 = 31 := by decide +kernel
theorem p060_checked_blocks_formula_32 : p060_checked_blocks_costFormula 32 = 206 ∧ p060_checked_blocks_conditionalFormula 32 = 62 := by decide +kernel
theorem p060_checked_blocks_formula_64 : p060_checked_blocks_costFormula 64 = 462 ∧ p060_checked_blocks_conditionalFormula 64 = 126 := by decide +kernel
theorem p060_checked_blocks_formula_128 : p060_checked_blocks_costFormula 128 = 1110 ∧ p060_checked_blocks_conditionalFormula 128 = 254 := by decide +kernel
#print axioms p060_checked_blocks_certificate
#print axioms p060_checked_blocks_correct
#print axioms p060_checked_blocks_cost
#print axioms p060_checked_blocks_conditional
#print axioms p060_checked_blocks_operational
#print axioms p060_checked_blocks_quadratic
#print axioms p060_checked_blocks_nlog
#print axioms p060_checked_blocks_conditional_linear
theorem p061_nested_certificate : Certificate p061_nested := p061_nested.certify
theorem p061_nested_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p061_nested_algorithm xs) := p061_nested.run_spec xs
theorem p061_nested_cost {α : Type} [LinearOrder α] (xs : List α) : (p061_nested.eval xs).time ≤ p061_nested_costFormula xs.length := p061_nested.cost_le_upper xs
theorem p061_nested_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p061_nested.Ready xs) : (p061_nested.eval xs).time ≤ p061_nested_conditionalFormula xs.length := p061_nested.cost_le_readyUpper xs h
theorem p061_nested_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p061_nested.program xs) (p061_nested_algorithm xs) (p061_nested.eval xs).time := p061_nested.operational_certificate xs
theorem p061_nested_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p061_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p061_nested.cost_isBigO_of_upper _ p061_nested.upper_isBigO_quadratic
theorem p061_nested_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p061_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p061_nested.cost_isBigO_of_upper _ (p061_nested.upper_isBigO_nlog 21 rfl)
theorem p061_nested_formula_0 : p061_nested_costFormula 0 = 0 ∧ p061_nested_conditionalFormula 0 = 0 := by decide +kernel
theorem p061_nested_formula_1 : p061_nested_costFormula 1 = 1 ∧ p061_nested_conditionalFormula 1 = 1 := by decide +kernel
theorem p061_nested_formula_8 : p061_nested_costFormula 8 = 36 ∧ p061_nested_conditionalFormula 8 = 36 := by decide +kernel
theorem p061_nested_formula_16 : p061_nested_costFormula 16 = 88 ∧ p061_nested_conditionalFormula 16 = 88 := by decide +kernel
theorem p061_nested_formula_32 : p061_nested_costFormula 32 = 172 ∧ p061_nested_conditionalFormula 32 = 172 := by decide +kernel
theorem p061_nested_formula_64 : p061_nested_costFormula 64 = 412 ∧ p061_nested_conditionalFormula 64 = 412 := by decide +kernel
theorem p061_nested_formula_128 : p061_nested_costFormula 128 = 984 ∧ p061_nested_conditionalFormula 128 = 984 := by decide +kernel
#print axioms p061_nested_certificate
#print axioms p061_nested_correct
#print axioms p061_nested_cost
#print axioms p061_nested_conditional
#print axioms p061_nested_operational
#print axioms p061_nested_quadratic
#print axioms p061_nested_nlog
theorem p062_split_certificate : Certificate p062_split := p062_split.certify
theorem p062_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p062_split_algorithm xs) := p062_split.run_spec xs
theorem p062_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p062_split.eval xs).time ≤ p062_split_costFormula xs.length := p062_split.cost_le_upper xs
theorem p062_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p062_split.Ready xs) : (p062_split.eval xs).time ≤ p062_split_conditionalFormula xs.length := p062_split.cost_le_readyUpper xs h
theorem p062_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p062_split.program xs) (p062_split_algorithm xs) (p062_split.eval xs).time := p062_split.operational_certificate xs
theorem p062_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p062_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p062_split.cost_isBigO_of_upper _ p062_split.upper_isBigO_quadratic
theorem p062_split_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p062_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p062_split.cost_isBigO_of_upper _ (p062_split.upper_isBigO_nlog 11 rfl)
theorem p062_split_formula_0 : p062_split_costFormula 0 = 0 ∧ p062_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p062_split_formula_1 : p062_split_costFormula 1 = 1 ∧ p062_split_conditionalFormula 1 = 1 := by decide +kernel
theorem p062_split_formula_8 : p062_split_costFormula 8 = 22 ∧ p062_split_conditionalFormula 8 = 22 := by decide +kernel
theorem p062_split_formula_16 : p062_split_costFormula 16 = 68 ∧ p062_split_conditionalFormula 16 = 68 := by decide +kernel
theorem p062_split_formula_32 : p062_split_costFormula 32 = 168 ∧ p062_split_conditionalFormula 32 = 168 := by decide +kernel
theorem p062_split_formula_64 : p062_split_costFormula 64 = 400 ∧ p062_split_conditionalFormula 64 = 400 := by decide +kernel
theorem p062_split_formula_128 : p062_split_costFormula 128 = 928 ∧ p062_split_conditionalFormula 128 = 928 := by decide +kernel
#print axioms p062_split_certificate
#print axioms p062_split_correct
#print axioms p062_split_cost
#print axioms p062_split_conditional
#print axioms p062_split_operational
#print axioms p062_split_quadratic
#print axioms p062_split_nlog
theorem p063_guarded_split_certificate : Certificate p063_guarded_split := p063_guarded_split.certify
theorem p063_guarded_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p063_guarded_split_algorithm xs) := p063_guarded_split.run_spec xs
theorem p063_guarded_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p063_guarded_split.eval xs).time ≤ p063_guarded_split_costFormula xs.length := p063_guarded_split.cost_le_upper xs
theorem p063_guarded_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p063_guarded_split.Ready xs) : (p063_guarded_split.eval xs).time ≤ p063_guarded_split_conditionalFormula xs.length := p063_guarded_split.cost_le_readyUpper xs h
theorem p063_guarded_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p063_guarded_split.program xs) (p063_guarded_split_algorithm xs) (p063_guarded_split.eval xs).time := p063_guarded_split.operational_certificate xs
theorem p063_guarded_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p063_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p063_guarded_split.cost_isBigO_of_upper _ p063_guarded_split.upper_isBigO_quadratic
theorem p063_guarded_split_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p063_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p063_guarded_split.cost_isBigO_of_upper _ (p063_guarded_split.upper_isBigO_nlog 12 rfl)
theorem p063_guarded_split_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p063_guarded_split.Ready xs} => ((p063_guarded_split.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p063_guarded_split.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p063_guarded_split.Ready xs} => (xs.val.length : ℝ)) := p063_guarded_split.ready_cost_isBigO_linear 0 rfl
theorem p063_guarded_split_formula_0 : p063_guarded_split_costFormula 0 = 0 ∧ p063_guarded_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p063_guarded_split_formula_1 : p063_guarded_split_costFormula 1 = 1 ∧ p063_guarded_split_conditionalFormula 1 = 0 := by decide +kernel
theorem p063_guarded_split_formula_8 : p063_guarded_split_costFormula 8 = 29 ∧ p063_guarded_split_conditionalFormula 8 = 7 := by decide +kernel
theorem p063_guarded_split_formula_16 : p063_guarded_split_costFormula 16 = 83 ∧ p063_guarded_split_conditionalFormula 16 = 15 := by decide +kernel
theorem p063_guarded_split_formula_32 : p063_guarded_split_costFormula 32 = 199 ∧ p063_guarded_split_conditionalFormula 32 = 31 := by decide +kernel
theorem p063_guarded_split_formula_64 : p063_guarded_split_costFormula 64 = 463 ∧ p063_guarded_split_conditionalFormula 64 = 63 := by decide +kernel
theorem p063_guarded_split_formula_128 : p063_guarded_split_costFormula 128 = 1055 ∧ p063_guarded_split_conditionalFormula 128 = 127 := by decide +kernel
#print axioms p063_guarded_split_certificate
#print axioms p063_guarded_split_correct
#print axioms p063_guarded_split_cost
#print axioms p063_guarded_split_conditional
#print axioms p063_guarded_split_operational
#print axioms p063_guarded_split_quadratic
#print axioms p063_guarded_split_nlog
#print axioms p063_guarded_split_conditional_linear
theorem p064_checked_blocks_certificate : Certificate p064_checked_blocks := p064_checked_blocks.certify
theorem p064_checked_blocks_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p064_checked_blocks_algorithm xs) := p064_checked_blocks.run_spec xs
theorem p064_checked_blocks_cost {α : Type} [LinearOrder α] (xs : List α) : (p064_checked_blocks.eval xs).time ≤ p064_checked_blocks_costFormula xs.length := p064_checked_blocks.cost_le_upper xs
theorem p064_checked_blocks_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p064_checked_blocks.Ready xs) : (p064_checked_blocks.eval xs).time ≤ p064_checked_blocks_conditionalFormula xs.length := p064_checked_blocks.cost_le_readyUpper xs h
theorem p064_checked_blocks_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p064_checked_blocks.program xs) (p064_checked_blocks_algorithm xs) (p064_checked_blocks.eval xs).time := p064_checked_blocks.operational_certificate xs
theorem p064_checked_blocks_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p064_checked_blocks.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p064_checked_blocks.cost_isBigO_of_upper _ p064_checked_blocks.upper_isBigO_quadratic
theorem p064_checked_blocks_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p064_checked_blocks.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p064_checked_blocks.cost_isBigO_of_upper _ (p064_checked_blocks.upper_isBigO_nlog 13 rfl)
theorem p064_checked_blocks_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p064_checked_blocks.Ready xs} => ((p064_checked_blocks.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p064_checked_blocks.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p064_checked_blocks.Ready xs} => (xs.val.length : ℝ)) := p064_checked_blocks.ready_cost_isBigO_linear 1 rfl
theorem p064_checked_blocks_formula_0 : p064_checked_blocks_costFormula 0 = 0 ∧ p064_checked_blocks_conditionalFormula 0 = 0 := by decide +kernel
theorem p064_checked_blocks_formula_1 : p064_checked_blocks_costFormula 1 = 1 ∧ p064_checked_blocks_conditionalFormula 1 = 1 := by decide +kernel
theorem p064_checked_blocks_formula_8 : p064_checked_blocks_costFormula 8 = 28 ∧ p064_checked_blocks_conditionalFormula 8 = 14 := by decide +kernel
theorem p064_checked_blocks_formula_16 : p064_checked_blocks_costFormula 16 = 82 ∧ p064_checked_blocks_conditionalFormula 16 = 30 := by decide +kernel
theorem p064_checked_blocks_formula_32 : p064_checked_blocks_costFormula 32 = 198 ∧ p064_checked_blocks_conditionalFormula 32 = 62 := by decide +kernel
theorem p064_checked_blocks_formula_64 : p064_checked_blocks_costFormula 64 = 462 ∧ p064_checked_blocks_conditionalFormula 64 = 126 := by decide +kernel
theorem p064_checked_blocks_formula_128 : p064_checked_blocks_costFormula 128 = 1054 ∧ p064_checked_blocks_conditionalFormula 128 = 254 := by decide +kernel
#print axioms p064_checked_blocks_certificate
#print axioms p064_checked_blocks_correct
#print axioms p064_checked_blocks_cost
#print axioms p064_checked_blocks_conditional
#print axioms p064_checked_blocks_operational
#print axioms p064_checked_blocks_quadratic
#print axioms p064_checked_blocks_nlog
#print axioms p064_checked_blocks_conditional_linear
theorem p065_nested_certificate : Certificate p065_nested := p065_nested.certify
theorem p065_nested_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p065_nested_algorithm xs) := p065_nested.run_spec xs
theorem p065_nested_cost {α : Type} [LinearOrder α] (xs : List α) : (p065_nested.eval xs).time ≤ p065_nested_costFormula xs.length := p065_nested.cost_le_upper xs
theorem p065_nested_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p065_nested.Ready xs) : (p065_nested.eval xs).time ≤ p065_nested_conditionalFormula xs.length := p065_nested.cost_le_readyUpper xs h
theorem p065_nested_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p065_nested.program xs) (p065_nested_algorithm xs) (p065_nested.eval xs).time := p065_nested.operational_certificate xs
theorem p065_nested_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p065_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p065_nested.cost_isBigO_of_upper _ p065_nested.upper_isBigO_quadratic
theorem p065_nested_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p065_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p065_nested.cost_isBigO_of_upper _ (p065_nested.upper_isBigO_nlog 13 rfl)
theorem p065_nested_formula_0 : p065_nested_costFormula 0 = 0 ∧ p065_nested_conditionalFormula 0 = 0 := by decide +kernel
theorem p065_nested_formula_1 : p065_nested_costFormula 1 = 2 ∧ p065_nested_conditionalFormula 1 = 2 := by decide +kernel
theorem p065_nested_formula_8 : p065_nested_costFormula 8 = 23 ∧ p065_nested_conditionalFormula 8 = 23 := by decide +kernel
theorem p065_nested_formula_16 : p065_nested_costFormula 16 = 62 ∧ p065_nested_conditionalFormula 16 = 62 := by decide +kernel
theorem p065_nested_formula_32 : p065_nested_costFormula 32 = 164 ∧ p065_nested_conditionalFormula 32 = 164 := by decide +kernel
theorem p065_nested_formula_64 : p065_nested_costFormula 64 = 392 ∧ p065_nested_conditionalFormula 64 = 392 := by decide +kernel
theorem p065_nested_formula_128 : p065_nested_costFormula 128 = 912 ∧ p065_nested_conditionalFormula 128 = 912 := by decide +kernel
#print axioms p065_nested_certificate
#print axioms p065_nested_correct
#print axioms p065_nested_cost
#print axioms p065_nested_conditional
#print axioms p065_nested_operational
#print axioms p065_nested_quadratic
#print axioms p065_nested_nlog
theorem p066_split_certificate : Certificate p066_split := p066_split.certify
theorem p066_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p066_split_algorithm xs) := p066_split.run_spec xs
theorem p066_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p066_split.eval xs).time ≤ p066_split_costFormula xs.length := p066_split.cost_le_upper xs
theorem p066_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p066_split.Ready xs) : (p066_split.eval xs).time ≤ p066_split_conditionalFormula xs.length := p066_split.cost_le_readyUpper xs h
theorem p066_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p066_split.program xs) (p066_split_algorithm xs) (p066_split.eval xs).time := p066_split.operational_certificate xs
theorem p066_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p066_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p066_split.cost_isBigO_of_upper _ p066_split.upper_isBigO_quadratic
theorem p066_split_formula_0 : p066_split_costFormula 0 = 0 ∧ p066_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p066_split_formula_1 : p066_split_costFormula 1 = 1 ∧ p066_split_conditionalFormula 1 = 1 := by decide +kernel
theorem p066_split_formula_8 : p066_split_costFormula 8 = 24 ∧ p066_split_conditionalFormula 8 = 24 := by decide +kernel
theorem p066_split_formula_16 : p066_split_costFormula 16 = 81 ∧ p066_split_conditionalFormula 16 = 81 := by decide +kernel
theorem p066_split_formula_32 : p066_split_costFormula 32 = 209 ∧ p066_split_conditionalFormula 32 = 209 := by decide +kernel
theorem p066_split_formula_64 : p066_split_costFormula 64 = 570 ∧ p066_split_conditionalFormula 64 = 570 := by decide +kernel
theorem p066_split_formula_128 : p066_split_costFormula 128 = 1667 ∧ p066_split_conditionalFormula 128 = 1667 := by decide +kernel
#print axioms p066_split_certificate
#print axioms p066_split_correct
#print axioms p066_split_cost
#print axioms p066_split_conditional
#print axioms p066_split_operational
#print axioms p066_split_quadratic
theorem p067_guarded_split_certificate : Certificate p067_guarded_split := p067_guarded_split.certify
theorem p067_guarded_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p067_guarded_split_algorithm xs) := p067_guarded_split.run_spec xs
theorem p067_guarded_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p067_guarded_split.eval xs).time ≤ p067_guarded_split_costFormula xs.length := p067_guarded_split.cost_le_upper xs
theorem p067_guarded_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p067_guarded_split.Ready xs) : (p067_guarded_split.eval xs).time ≤ p067_guarded_split_conditionalFormula xs.length := p067_guarded_split.cost_le_readyUpper xs h
theorem p067_guarded_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p067_guarded_split.program xs) (p067_guarded_split_algorithm xs) (p067_guarded_split.eval xs).time := p067_guarded_split.operational_certificate xs
theorem p067_guarded_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p067_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p067_guarded_split.cost_isBigO_of_upper _ p067_guarded_split.upper_isBigO_quadratic
theorem p067_guarded_split_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p067_guarded_split.Ready xs} => ((p067_guarded_split.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p067_guarded_split.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p067_guarded_split.Ready xs} => (xs.val.length : ℝ)) := p067_guarded_split.ready_cost_isBigO_linear 0 rfl
theorem p067_guarded_split_formula_0 : p067_guarded_split_costFormula 0 = 0 ∧ p067_guarded_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p067_guarded_split_formula_1 : p067_guarded_split_costFormula 1 = 1 ∧ p067_guarded_split_conditionalFormula 1 = 0 := by decide +kernel
theorem p067_guarded_split_formula_8 : p067_guarded_split_costFormula 8 = 31 ∧ p067_guarded_split_conditionalFormula 8 = 7 := by decide +kernel
theorem p067_guarded_split_formula_16 : p067_guarded_split_costFormula 16 = 96 ∧ p067_guarded_split_conditionalFormula 16 = 15 := by decide +kernel
theorem p067_guarded_split_formula_32 : p067_guarded_split_costFormula 32 = 240 ∧ p067_guarded_split_conditionalFormula 32 = 31 := by decide +kernel
theorem p067_guarded_split_formula_64 : p067_guarded_split_costFormula 64 = 633 ∧ p067_guarded_split_conditionalFormula 64 = 63 := by decide +kernel
theorem p067_guarded_split_formula_128 : p067_guarded_split_costFormula 128 = 1794 ∧ p067_guarded_split_conditionalFormula 128 = 127 := by decide +kernel
#print axioms p067_guarded_split_certificate
#print axioms p067_guarded_split_correct
#print axioms p067_guarded_split_cost
#print axioms p067_guarded_split_conditional
#print axioms p067_guarded_split_operational
#print axioms p067_guarded_split_quadratic
#print axioms p067_guarded_split_conditional_linear
theorem p068_checked_blocks_certificate : Certificate p068_checked_blocks := p068_checked_blocks.certify
theorem p068_checked_blocks_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p068_checked_blocks_algorithm xs) := p068_checked_blocks.run_spec xs
theorem p068_checked_blocks_cost {α : Type} [LinearOrder α] (xs : List α) : (p068_checked_blocks.eval xs).time ≤ p068_checked_blocks_costFormula xs.length := p068_checked_blocks.cost_le_upper xs
theorem p068_checked_blocks_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p068_checked_blocks.Ready xs) : (p068_checked_blocks.eval xs).time ≤ p068_checked_blocks_conditionalFormula xs.length := p068_checked_blocks.cost_le_readyUpper xs h
theorem p068_checked_blocks_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p068_checked_blocks.program xs) (p068_checked_blocks_algorithm xs) (p068_checked_blocks.eval xs).time := p068_checked_blocks.operational_certificate xs
theorem p068_checked_blocks_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p068_checked_blocks.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p068_checked_blocks.cost_isBigO_of_upper _ p068_checked_blocks.upper_isBigO_quadratic
theorem p068_checked_blocks_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p068_checked_blocks.Ready xs} => ((p068_checked_blocks.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p068_checked_blocks.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p068_checked_blocks.Ready xs} => (xs.val.length : ℝ)) := p068_checked_blocks.ready_cost_isBigO_linear 1 rfl
theorem p068_checked_blocks_formula_0 : p068_checked_blocks_costFormula 0 = 0 ∧ p068_checked_blocks_conditionalFormula 0 = 0 := by decide +kernel
theorem p068_checked_blocks_formula_1 : p068_checked_blocks_costFormula 1 = 1 ∧ p068_checked_blocks_conditionalFormula 1 = 1 := by decide +kernel
theorem p068_checked_blocks_formula_8 : p068_checked_blocks_costFormula 8 = 30 ∧ p068_checked_blocks_conditionalFormula 8 = 14 := by decide +kernel
theorem p068_checked_blocks_formula_16 : p068_checked_blocks_costFormula 16 = 95 ∧ p068_checked_blocks_conditionalFormula 16 = 30 := by decide +kernel
theorem p068_checked_blocks_formula_32 : p068_checked_blocks_costFormula 32 = 239 ∧ p068_checked_blocks_conditionalFormula 32 = 62 := by decide +kernel
theorem p068_checked_blocks_formula_64 : p068_checked_blocks_costFormula 64 = 632 ∧ p068_checked_blocks_conditionalFormula 64 = 126 := by decide +kernel
theorem p068_checked_blocks_formula_128 : p068_checked_blocks_costFormula 128 = 1793 ∧ p068_checked_blocks_conditionalFormula 128 = 254 := by decide +kernel
#print axioms p068_checked_blocks_certificate
#print axioms p068_checked_blocks_correct
#print axioms p068_checked_blocks_cost
#print axioms p068_checked_blocks_conditional
#print axioms p068_checked_blocks_operational
#print axioms p068_checked_blocks_quadratic
#print axioms p068_checked_blocks_conditional_linear
theorem p069_nested_certificate : Certificate p069_nested := p069_nested.certify
theorem p069_nested_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p069_nested_algorithm xs) := p069_nested.run_spec xs
theorem p069_nested_cost {α : Type} [LinearOrder α] (xs : List α) : (p069_nested.eval xs).time ≤ p069_nested_costFormula xs.length := p069_nested.cost_le_upper xs
theorem p069_nested_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p069_nested.Ready xs) : (p069_nested.eval xs).time ≤ p069_nested_conditionalFormula xs.length := p069_nested.cost_le_readyUpper xs h
theorem p069_nested_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p069_nested.program xs) (p069_nested_algorithm xs) (p069_nested.eval xs).time := p069_nested.operational_certificate xs
theorem p069_nested_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p069_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p069_nested.cost_isBigO_of_upper _ p069_nested.upper_isBigO_quadratic
theorem p069_nested_formula_0 : p069_nested_costFormula 0 = 0 ∧ p069_nested_conditionalFormula 0 = 0 := by decide +kernel
theorem p069_nested_formula_1 : p069_nested_costFormula 1 = 2 ∧ p069_nested_conditionalFormula 1 = 2 := by decide +kernel
theorem p069_nested_formula_8 : p069_nested_costFormula 8 = 24 ∧ p069_nested_conditionalFormula 8 = 24 := by decide +kernel
theorem p069_nested_formula_16 : p069_nested_costFormula 16 = 65 ∧ p069_nested_conditionalFormula 16 = 65 := by decide +kernel
theorem p069_nested_formula_32 : p069_nested_costFormula 32 = 198 ∧ p069_nested_conditionalFormula 32 = 198 := by decide +kernel
theorem p069_nested_formula_64 : p069_nested_costFormula 64 = 548 ∧ p069_nested_conditionalFormula 64 = 548 := by decide +kernel
theorem p069_nested_formula_128 : p069_nested_costFormula 128 = 1629 ∧ p069_nested_conditionalFormula 128 = 1629 := by decide +kernel
#print axioms p069_nested_certificate
#print axioms p069_nested_correct
#print axioms p069_nested_cost
#print axioms p069_nested_conditional
#print axioms p069_nested_operational
#print axioms p069_nested_quadratic
theorem p070_split_certificate : Certificate p070_split := p070_split.certify
theorem p070_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p070_split_algorithm xs) := p070_split.run_spec xs
theorem p070_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p070_split.eval xs).time ≤ p070_split_costFormula xs.length := p070_split.cost_le_upper xs
theorem p070_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p070_split.Ready xs) : (p070_split.eval xs).time ≤ p070_split_conditionalFormula xs.length := p070_split.cost_le_readyUpper xs h
theorem p070_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p070_split.program xs) (p070_split_algorithm xs) (p070_split.eval xs).time := p070_split.operational_certificate xs
theorem p070_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p070_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p070_split.cost_isBigO_of_upper _ p070_split.upper_isBigO_quadratic
theorem p070_split_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p070_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p070_split.cost_isBigO_of_upper _ (p070_split.upper_isBigO_nlog 19 rfl)
theorem p070_split_formula_0 : p070_split_costFormula 0 = 0 ∧ p070_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p070_split_formula_1 : p070_split_costFormula 1 = 1 ∧ p070_split_conditionalFormula 1 = 1 := by decide +kernel
theorem p070_split_formula_8 : p070_split_costFormula 8 = 36 ∧ p070_split_conditionalFormula 8 = 36 := by decide +kernel
theorem p070_split_formula_16 : p070_split_costFormula 16 = 136 ∧ p070_split_conditionalFormula 16 = 136 := by decide +kernel
theorem p070_split_formula_32 : p070_split_costFormula 32 = 216 ∧ p070_split_conditionalFormula 32 = 216 := by decide +kernel
theorem p070_split_formula_64 : p070_split_costFormula 64 = 472 ∧ p070_split_conditionalFormula 64 = 472 := by decide +kernel
theorem p070_split_formula_128 : p070_split_costFormula 128 = 1032 ∧ p070_split_conditionalFormula 128 = 1032 := by decide +kernel
#print axioms p070_split_certificate
#print axioms p070_split_correct
#print axioms p070_split_cost
#print axioms p070_split_conditional
#print axioms p070_split_operational
#print axioms p070_split_quadratic
#print axioms p070_split_nlog
theorem p071_guarded_split_certificate : Certificate p071_guarded_split := p071_guarded_split.certify
theorem p071_guarded_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p071_guarded_split_algorithm xs) := p071_guarded_split.run_spec xs
theorem p071_guarded_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p071_guarded_split.eval xs).time ≤ p071_guarded_split_costFormula xs.length := p071_guarded_split.cost_le_upper xs
theorem p071_guarded_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p071_guarded_split.Ready xs) : (p071_guarded_split.eval xs).time ≤ p071_guarded_split_conditionalFormula xs.length := p071_guarded_split.cost_le_readyUpper xs h
theorem p071_guarded_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p071_guarded_split.program xs) (p071_guarded_split_algorithm xs) (p071_guarded_split.eval xs).time := p071_guarded_split.operational_certificate xs
theorem p071_guarded_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p071_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p071_guarded_split.cost_isBigO_of_upper _ p071_guarded_split.upper_isBigO_quadratic
theorem p071_guarded_split_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p071_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p071_guarded_split.cost_isBigO_of_upper _ (p071_guarded_split.upper_isBigO_nlog 20 rfl)
theorem p071_guarded_split_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p071_guarded_split.Ready xs} => ((p071_guarded_split.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p071_guarded_split.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p071_guarded_split.Ready xs} => (xs.val.length : ℝ)) := p071_guarded_split.ready_cost_isBigO_linear 0 rfl
theorem p071_guarded_split_formula_0 : p071_guarded_split_costFormula 0 = 0 ∧ p071_guarded_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p071_guarded_split_formula_1 : p071_guarded_split_costFormula 1 = 1 ∧ p071_guarded_split_conditionalFormula 1 = 0 := by decide +kernel
theorem p071_guarded_split_formula_8 : p071_guarded_split_costFormula 8 = 43 ∧ p071_guarded_split_conditionalFormula 8 = 7 := by decide +kernel
theorem p071_guarded_split_formula_16 : p071_guarded_split_costFormula 16 = 151 ∧ p071_guarded_split_conditionalFormula 16 = 15 := by decide +kernel
theorem p071_guarded_split_formula_32 : p071_guarded_split_costFormula 32 = 247 ∧ p071_guarded_split_conditionalFormula 32 = 31 := by decide +kernel
theorem p071_guarded_split_formula_64 : p071_guarded_split_costFormula 64 = 535 ∧ p071_guarded_split_conditionalFormula 64 = 63 := by decide +kernel
theorem p071_guarded_split_formula_128 : p071_guarded_split_costFormula 128 = 1159 ∧ p071_guarded_split_conditionalFormula 128 = 127 := by decide +kernel
#print axioms p071_guarded_split_certificate
#print axioms p071_guarded_split_correct
#print axioms p071_guarded_split_cost
#print axioms p071_guarded_split_conditional
#print axioms p071_guarded_split_operational
#print axioms p071_guarded_split_quadratic
#print axioms p071_guarded_split_nlog
#print axioms p071_guarded_split_conditional_linear
theorem p072_checked_blocks_certificate : Certificate p072_checked_blocks := p072_checked_blocks.certify
theorem p072_checked_blocks_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p072_checked_blocks_algorithm xs) := p072_checked_blocks.run_spec xs
theorem p072_checked_blocks_cost {α : Type} [LinearOrder α] (xs : List α) : (p072_checked_blocks.eval xs).time ≤ p072_checked_blocks_costFormula xs.length := p072_checked_blocks.cost_le_upper xs
theorem p072_checked_blocks_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p072_checked_blocks.Ready xs) : (p072_checked_blocks.eval xs).time ≤ p072_checked_blocks_conditionalFormula xs.length := p072_checked_blocks.cost_le_readyUpper xs h
theorem p072_checked_blocks_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p072_checked_blocks.program xs) (p072_checked_blocks_algorithm xs) (p072_checked_blocks.eval xs).time := p072_checked_blocks.operational_certificate xs
theorem p072_checked_blocks_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p072_checked_blocks.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p072_checked_blocks.cost_isBigO_of_upper _ p072_checked_blocks.upper_isBigO_quadratic
theorem p072_checked_blocks_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p072_checked_blocks.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p072_checked_blocks.cost_isBigO_of_upper _ (p072_checked_blocks.upper_isBigO_nlog 21 rfl)
theorem p072_checked_blocks_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p072_checked_blocks.Ready xs} => ((p072_checked_blocks.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p072_checked_blocks.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p072_checked_blocks.Ready xs} => (xs.val.length : ℝ)) := p072_checked_blocks.ready_cost_isBigO_linear 1 rfl
theorem p072_checked_blocks_formula_0 : p072_checked_blocks_costFormula 0 = 0 ∧ p072_checked_blocks_conditionalFormula 0 = 0 := by decide +kernel
theorem p072_checked_blocks_formula_1 : p072_checked_blocks_costFormula 1 = 1 ∧ p072_checked_blocks_conditionalFormula 1 = 1 := by decide +kernel
theorem p072_checked_blocks_formula_8 : p072_checked_blocks_costFormula 8 = 43 ∧ p072_checked_blocks_conditionalFormula 8 = 15 := by decide +kernel
theorem p072_checked_blocks_formula_16 : p072_checked_blocks_costFormula 16 = 151 ∧ p072_checked_blocks_conditionalFormula 16 = 31 := by decide +kernel
theorem p072_checked_blocks_formula_32 : p072_checked_blocks_costFormula 32 = 246 ∧ p072_checked_blocks_conditionalFormula 32 = 62 := by decide +kernel
theorem p072_checked_blocks_formula_64 : p072_checked_blocks_costFormula 64 = 534 ∧ p072_checked_blocks_conditionalFormula 64 = 126 := by decide +kernel
theorem p072_checked_blocks_formula_128 : p072_checked_blocks_costFormula 128 = 1158 ∧ p072_checked_blocks_conditionalFormula 128 = 254 := by decide +kernel
#print axioms p072_checked_blocks_certificate
#print axioms p072_checked_blocks_correct
#print axioms p072_checked_blocks_cost
#print axioms p072_checked_blocks_conditional
#print axioms p072_checked_blocks_operational
#print axioms p072_checked_blocks_quadratic
#print axioms p072_checked_blocks_nlog
#print axioms p072_checked_blocks_conditional_linear
theorem p073_nested_certificate : Certificate p073_nested := p073_nested.certify
theorem p073_nested_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p073_nested_algorithm xs) := p073_nested.run_spec xs
theorem p073_nested_cost {α : Type} [LinearOrder α] (xs : List α) : (p073_nested.eval xs).time ≤ p073_nested_costFormula xs.length := p073_nested.cost_le_upper xs
theorem p073_nested_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p073_nested.Ready xs) : (p073_nested.eval xs).time ≤ p073_nested_conditionalFormula xs.length := p073_nested.cost_le_readyUpper xs h
theorem p073_nested_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p073_nested.program xs) (p073_nested_algorithm xs) (p073_nested.eval xs).time := p073_nested.operational_certificate xs
theorem p073_nested_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p073_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p073_nested.cost_isBigO_of_upper _ p073_nested.upper_isBigO_quadratic
theorem p073_nested_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p073_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p073_nested.cost_isBigO_of_upper _ (p073_nested.upper_isBigO_nlog 21 rfl)
theorem p073_nested_formula_0 : p073_nested_costFormula 0 = 0 ∧ p073_nested_conditionalFormula 0 = 0 := by decide +kernel
theorem p073_nested_formula_1 : p073_nested_costFormula 1 = 1 ∧ p073_nested_conditionalFormula 1 = 1 := by decide +kernel
theorem p073_nested_formula_8 : p073_nested_costFormula 8 = 36 ∧ p073_nested_conditionalFormula 8 = 36 := by decide +kernel
theorem p073_nested_formula_16 : p073_nested_costFormula 16 = 136 ∧ p073_nested_conditionalFormula 16 = 136 := by decide +kernel
theorem p073_nested_formula_32 : p073_nested_costFormula 32 = 216 ∧ p073_nested_conditionalFormula 32 = 216 := by decide +kernel
theorem p073_nested_formula_64 : p073_nested_costFormula 64 = 472 ∧ p073_nested_conditionalFormula 64 = 472 := by decide +kernel
theorem p073_nested_formula_128 : p073_nested_costFormula 128 = 1032 ∧ p073_nested_conditionalFormula 128 = 1032 := by decide +kernel
#print axioms p073_nested_certificate
#print axioms p073_nested_correct
#print axioms p073_nested_cost
#print axioms p073_nested_conditional
#print axioms p073_nested_operational
#print axioms p073_nested_quadratic
#print axioms p073_nested_nlog
theorem p074_split_certificate : Certificate p074_split := p074_split.certify
theorem p074_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p074_split_algorithm xs) := p074_split.run_spec xs
theorem p074_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p074_split.eval xs).time ≤ p074_split_costFormula xs.length := p074_split.cost_le_upper xs
theorem p074_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p074_split.Ready xs) : (p074_split.eval xs).time ≤ p074_split_conditionalFormula xs.length := p074_split.cost_le_readyUpper xs h
theorem p074_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p074_split.program xs) (p074_split_algorithm xs) (p074_split.eval xs).time := p074_split.operational_certificate xs
theorem p074_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p074_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p074_split.cost_isBigO_of_upper _ p074_split.upper_isBigO_quadratic
theorem p074_split_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p074_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p074_split.cost_isBigO_of_upper _ (p074_split.upper_isBigO_nlog 23 rfl)
theorem p074_split_formula_0 : p074_split_costFormula 0 = 0 ∧ p074_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p074_split_formula_1 : p074_split_costFormula 1 = 1 ∧ p074_split_conditionalFormula 1 = 1 := by decide +kernel
theorem p074_split_formula_8 : p074_split_costFormula 8 = 21 ∧ p074_split_conditionalFormula 8 = 21 := by decide +kernel
theorem p074_split_formula_16 : p074_split_costFormula 16 = 58 ∧ p074_split_conditionalFormula 16 = 58 := by decide +kernel
theorem p074_split_formula_32 : p074_split_costFormula 32 = 163 ∧ p074_split_conditionalFormula 32 = 163 := by decide +kernel
theorem p074_split_formula_64 : p074_split_costFormula 64 = 395 ∧ p074_split_conditionalFormula 64 = 395 := by decide +kernel
theorem p074_split_formula_128 : p074_split_costFormula 128 = 918 ∧ p074_split_conditionalFormula 128 = 918 := by decide +kernel
#print axioms p074_split_certificate
#print axioms p074_split_correct
#print axioms p074_split_cost
#print axioms p074_split_conditional
#print axioms p074_split_operational
#print axioms p074_split_quadratic
#print axioms p074_split_nlog
theorem p075_guarded_split_certificate : Certificate p075_guarded_split := p075_guarded_split.certify
theorem p075_guarded_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p075_guarded_split_algorithm xs) := p075_guarded_split.run_spec xs
theorem p075_guarded_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p075_guarded_split.eval xs).time ≤ p075_guarded_split_costFormula xs.length := p075_guarded_split.cost_le_upper xs
theorem p075_guarded_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p075_guarded_split.Ready xs) : (p075_guarded_split.eval xs).time ≤ p075_guarded_split_conditionalFormula xs.length := p075_guarded_split.cost_le_readyUpper xs h
theorem p075_guarded_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p075_guarded_split.program xs) (p075_guarded_split_algorithm xs) (p075_guarded_split.eval xs).time := p075_guarded_split.operational_certificate xs
theorem p075_guarded_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p075_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p075_guarded_split.cost_isBigO_of_upper _ p075_guarded_split.upper_isBigO_quadratic
theorem p075_guarded_split_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p075_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p075_guarded_split.cost_isBigO_of_upper _ (p075_guarded_split.upper_isBigO_nlog 24 rfl)
theorem p075_guarded_split_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p075_guarded_split.Ready xs} => ((p075_guarded_split.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p075_guarded_split.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p075_guarded_split.Ready xs} => (xs.val.length : ℝ)) := p075_guarded_split.ready_cost_isBigO_linear 0 rfl
theorem p075_guarded_split_formula_0 : p075_guarded_split_costFormula 0 = 0 ∧ p075_guarded_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p075_guarded_split_formula_1 : p075_guarded_split_costFormula 1 = 1 ∧ p075_guarded_split_conditionalFormula 1 = 0 := by decide +kernel
theorem p075_guarded_split_formula_8 : p075_guarded_split_costFormula 8 = 28 ∧ p075_guarded_split_conditionalFormula 8 = 7 := by decide +kernel
theorem p075_guarded_split_formula_16 : p075_guarded_split_costFormula 16 = 73 ∧ p075_guarded_split_conditionalFormula 16 = 15 := by decide +kernel
theorem p075_guarded_split_formula_32 : p075_guarded_split_costFormula 32 = 194 ∧ p075_guarded_split_conditionalFormula 32 = 31 := by decide +kernel
theorem p075_guarded_split_formula_64 : p075_guarded_split_costFormula 64 = 458 ∧ p075_guarded_split_conditionalFormula 64 = 63 := by decide +kernel
theorem p075_guarded_split_formula_128 : p075_guarded_split_costFormula 128 = 1045 ∧ p075_guarded_split_conditionalFormula 128 = 127 := by decide +kernel
#print axioms p075_guarded_split_certificate
#print axioms p075_guarded_split_correct
#print axioms p075_guarded_split_cost
#print axioms p075_guarded_split_conditional
#print axioms p075_guarded_split_operational
#print axioms p075_guarded_split_quadratic
#print axioms p075_guarded_split_nlog
#print axioms p075_guarded_split_conditional_linear
theorem p076_checked_blocks_certificate : Certificate p076_checked_blocks := p076_checked_blocks.certify
theorem p076_checked_blocks_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p076_checked_blocks_algorithm xs) := p076_checked_blocks.run_spec xs
theorem p076_checked_blocks_cost {α : Type} [LinearOrder α] (xs : List α) : (p076_checked_blocks.eval xs).time ≤ p076_checked_blocks_costFormula xs.length := p076_checked_blocks.cost_le_upper xs
theorem p076_checked_blocks_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p076_checked_blocks.Ready xs) : (p076_checked_blocks.eval xs).time ≤ p076_checked_blocks_conditionalFormula xs.length := p076_checked_blocks.cost_le_readyUpper xs h
theorem p076_checked_blocks_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p076_checked_blocks.program xs) (p076_checked_blocks_algorithm xs) (p076_checked_blocks.eval xs).time := p076_checked_blocks.operational_certificate xs
theorem p076_checked_blocks_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p076_checked_blocks.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p076_checked_blocks.cost_isBigO_of_upper _ p076_checked_blocks.upper_isBigO_quadratic
theorem p076_checked_blocks_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p076_checked_blocks.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p076_checked_blocks.cost_isBigO_of_upper _ (p076_checked_blocks.upper_isBigO_nlog 25 rfl)
theorem p076_checked_blocks_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p076_checked_blocks.Ready xs} => ((p076_checked_blocks.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p076_checked_blocks.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p076_checked_blocks.Ready xs} => (xs.val.length : ℝ)) := p076_checked_blocks.ready_cost_isBigO_linear 1 rfl
theorem p076_checked_blocks_formula_0 : p076_checked_blocks_costFormula 0 = 0 ∧ p076_checked_blocks_conditionalFormula 0 = 0 := by decide +kernel
theorem p076_checked_blocks_formula_1 : p076_checked_blocks_costFormula 1 = 1 ∧ p076_checked_blocks_conditionalFormula 1 = 1 := by decide +kernel
theorem p076_checked_blocks_formula_8 : p076_checked_blocks_costFormula 8 = 27 ∧ p076_checked_blocks_conditionalFormula 8 = 14 := by decide +kernel
theorem p076_checked_blocks_formula_16 : p076_checked_blocks_costFormula 16 = 72 ∧ p076_checked_blocks_conditionalFormula 16 = 30 := by decide +kernel
theorem p076_checked_blocks_formula_32 : p076_checked_blocks_costFormula 32 = 193 ∧ p076_checked_blocks_conditionalFormula 32 = 62 := by decide +kernel
theorem p076_checked_blocks_formula_64 : p076_checked_blocks_costFormula 64 = 457 ∧ p076_checked_blocks_conditionalFormula 64 = 126 := by decide +kernel
theorem p076_checked_blocks_formula_128 : p076_checked_blocks_costFormula 128 = 1044 ∧ p076_checked_blocks_conditionalFormula 128 = 254 := by decide +kernel
#print axioms p076_checked_blocks_certificate
#print axioms p076_checked_blocks_correct
#print axioms p076_checked_blocks_cost
#print axioms p076_checked_blocks_conditional
#print axioms p076_checked_blocks_operational
#print axioms p076_checked_blocks_quadratic
#print axioms p076_checked_blocks_nlog
#print axioms p076_checked_blocks_conditional_linear
theorem p077_nested_certificate : Certificate p077_nested := p077_nested.certify
theorem p077_nested_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p077_nested_algorithm xs) := p077_nested.run_spec xs
theorem p077_nested_cost {α : Type} [LinearOrder α] (xs : List α) : (p077_nested.eval xs).time ≤ p077_nested_costFormula xs.length := p077_nested.cost_le_upper xs
theorem p077_nested_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p077_nested.Ready xs) : (p077_nested.eval xs).time ≤ p077_nested_conditionalFormula xs.length := p077_nested.cost_le_readyUpper xs h
theorem p077_nested_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p077_nested.program xs) (p077_nested_algorithm xs) (p077_nested.eval xs).time := p077_nested.operational_certificate xs
theorem p077_nested_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p077_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p077_nested.cost_isBigO_of_upper _ p077_nested.upper_isBigO_quadratic
theorem p077_nested_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p077_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p077_nested.cost_isBigO_of_upper _ (p077_nested.upper_isBigO_nlog 25 rfl)
theorem p077_nested_formula_0 : p077_nested_costFormula 0 = 0 ∧ p077_nested_conditionalFormula 0 = 0 := by decide +kernel
theorem p077_nested_formula_1 : p077_nested_costFormula 1 = 2 ∧ p077_nested_conditionalFormula 1 = 2 := by decide +kernel
theorem p077_nested_formula_8 : p077_nested_costFormula 8 = 24 ∧ p077_nested_conditionalFormula 8 = 24 := by decide +kernel
theorem p077_nested_formula_16 : p077_nested_costFormula 16 = 64 ∧ p077_nested_conditionalFormula 16 = 64 := by decide +kernel
theorem p077_nested_formula_32 : p077_nested_costFormula 32 = 175 ∧ p077_nested_conditionalFormula 32 = 175 := by decide +kernel
theorem p077_nested_formula_64 : p077_nested_costFormula 64 = 419 ∧ p077_nested_conditionalFormula 64 = 419 := by decide +kernel
theorem p077_nested_formula_128 : p077_nested_costFormula 128 = 966 ∧ p077_nested_conditionalFormula 128 = 966 := by decide +kernel
#print axioms p077_nested_certificate
#print axioms p077_nested_correct
#print axioms p077_nested_cost
#print axioms p077_nested_conditional
#print axioms p077_nested_operational
#print axioms p077_nested_quadratic
#print axioms p077_nested_nlog
theorem p078_split_certificate : Certificate p078_split := p078_split.certify
theorem p078_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p078_split_algorithm xs) := p078_split.run_spec xs
theorem p078_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p078_split.eval xs).time ≤ p078_split_costFormula xs.length := p078_split.cost_le_upper xs
theorem p078_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p078_split.Ready xs) : (p078_split.eval xs).time ≤ p078_split_conditionalFormula xs.length := p078_split.cost_le_readyUpper xs h
theorem p078_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p078_split.program xs) (p078_split_algorithm xs) (p078_split.eval xs).time := p078_split.operational_certificate xs
theorem p078_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p078_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p078_split.cost_isBigO_of_upper _ p078_split.upper_isBigO_quadratic
theorem p078_split_formula_0 : p078_split_costFormula 0 = 0 ∧ p078_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p078_split_formula_1 : p078_split_costFormula 1 = 1 ∧ p078_split_conditionalFormula 1 = 1 := by decide +kernel
theorem p078_split_formula_8 : p078_split_costFormula 8 = 20 ∧ p078_split_conditionalFormula 8 = 20 := by decide +kernel
theorem p078_split_formula_16 : p078_split_costFormula 16 = 64 ∧ p078_split_conditionalFormula 16 = 64 := by decide +kernel
theorem p078_split_formula_32 : p078_split_costFormula 32 = 208 ∧ p078_split_conditionalFormula 32 = 208 := by decide +kernel
theorem p078_split_formula_64 : p078_split_costFormula 64 = 704 ∧ p078_split_conditionalFormula 64 = 704 := by decide +kernel
theorem p078_split_formula_128 : p078_split_costFormula 128 = 2496 ∧ p078_split_conditionalFormula 128 = 2496 := by decide +kernel
#print axioms p078_split_certificate
#print axioms p078_split_correct
#print axioms p078_split_cost
#print axioms p078_split_conditional
#print axioms p078_split_operational
#print axioms p078_split_quadratic
theorem p079_guarded_split_certificate : Certificate p079_guarded_split := p079_guarded_split.certify
theorem p079_guarded_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p079_guarded_split_algorithm xs) := p079_guarded_split.run_spec xs
theorem p079_guarded_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p079_guarded_split.eval xs).time ≤ p079_guarded_split_costFormula xs.length := p079_guarded_split.cost_le_upper xs
theorem p079_guarded_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p079_guarded_split.Ready xs) : (p079_guarded_split.eval xs).time ≤ p079_guarded_split_conditionalFormula xs.length := p079_guarded_split.cost_le_readyUpper xs h
theorem p079_guarded_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p079_guarded_split.program xs) (p079_guarded_split_algorithm xs) (p079_guarded_split.eval xs).time := p079_guarded_split.operational_certificate xs
theorem p079_guarded_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p079_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p079_guarded_split.cost_isBigO_of_upper _ p079_guarded_split.upper_isBigO_quadratic
theorem p079_guarded_split_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p079_guarded_split.Ready xs} => ((p079_guarded_split.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p079_guarded_split.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p079_guarded_split.Ready xs} => (xs.val.length : ℝ)) := p079_guarded_split.ready_cost_isBigO_linear 0 rfl
theorem p079_guarded_split_formula_0 : p079_guarded_split_costFormula 0 = 0 ∧ p079_guarded_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p079_guarded_split_formula_1 : p079_guarded_split_costFormula 1 = 1 ∧ p079_guarded_split_conditionalFormula 1 = 0 := by decide +kernel
theorem p079_guarded_split_formula_8 : p079_guarded_split_costFormula 8 = 27 ∧ p079_guarded_split_conditionalFormula 8 = 7 := by decide +kernel
theorem p079_guarded_split_formula_16 : p079_guarded_split_costFormula 16 = 79 ∧ p079_guarded_split_conditionalFormula 16 = 15 := by decide +kernel
theorem p079_guarded_split_formula_32 : p079_guarded_split_costFormula 32 = 239 ∧ p079_guarded_split_conditionalFormula 32 = 31 := by decide +kernel
theorem p079_guarded_split_formula_64 : p079_guarded_split_costFormula 64 = 767 ∧ p079_guarded_split_conditionalFormula 64 = 63 := by decide +kernel
theorem p079_guarded_split_formula_128 : p079_guarded_split_costFormula 128 = 2623 ∧ p079_guarded_split_conditionalFormula 128 = 127 := by decide +kernel
#print axioms p079_guarded_split_certificate
#print axioms p079_guarded_split_correct
#print axioms p079_guarded_split_cost
#print axioms p079_guarded_split_conditional
#print axioms p079_guarded_split_operational
#print axioms p079_guarded_split_quadratic
#print axioms p079_guarded_split_conditional_linear
theorem p080_checked_blocks_certificate : Certificate p080_checked_blocks := p080_checked_blocks.certify
theorem p080_checked_blocks_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p080_checked_blocks_algorithm xs) := p080_checked_blocks.run_spec xs
theorem p080_checked_blocks_cost {α : Type} [LinearOrder α] (xs : List α) : (p080_checked_blocks.eval xs).time ≤ p080_checked_blocks_costFormula xs.length := p080_checked_blocks.cost_le_upper xs
theorem p080_checked_blocks_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p080_checked_blocks.Ready xs) : (p080_checked_blocks.eval xs).time ≤ p080_checked_blocks_conditionalFormula xs.length := p080_checked_blocks.cost_le_readyUpper xs h
theorem p080_checked_blocks_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p080_checked_blocks.program xs) (p080_checked_blocks_algorithm xs) (p080_checked_blocks.eval xs).time := p080_checked_blocks.operational_certificate xs
theorem p080_checked_blocks_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p080_checked_blocks.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p080_checked_blocks.cost_isBigO_of_upper _ p080_checked_blocks.upper_isBigO_quadratic
theorem p080_checked_blocks_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p080_checked_blocks.Ready xs} => ((p080_checked_blocks.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p080_checked_blocks.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p080_checked_blocks.Ready xs} => (xs.val.length : ℝ)) := p080_checked_blocks.ready_cost_isBigO_linear 1 rfl
theorem p080_checked_blocks_formula_0 : p080_checked_blocks_costFormula 0 = 0 ∧ p080_checked_blocks_conditionalFormula 0 = 0 := by decide +kernel
theorem p080_checked_blocks_formula_1 : p080_checked_blocks_costFormula 1 = 1 ∧ p080_checked_blocks_conditionalFormula 1 = 1 := by decide +kernel
theorem p080_checked_blocks_formula_8 : p080_checked_blocks_costFormula 8 = 26 ∧ p080_checked_blocks_conditionalFormula 8 = 14 := by decide +kernel
theorem p080_checked_blocks_formula_16 : p080_checked_blocks_costFormula 16 = 78 ∧ p080_checked_blocks_conditionalFormula 16 = 30 := by decide +kernel
theorem p080_checked_blocks_formula_32 : p080_checked_blocks_costFormula 32 = 238 ∧ p080_checked_blocks_conditionalFormula 32 = 62 := by decide +kernel
theorem p080_checked_blocks_formula_64 : p080_checked_blocks_costFormula 64 = 766 ∧ p080_checked_blocks_conditionalFormula 64 = 126 := by decide +kernel
theorem p080_checked_blocks_formula_128 : p080_checked_blocks_costFormula 128 = 2622 ∧ p080_checked_blocks_conditionalFormula 128 = 254 := by decide +kernel
#print axioms p080_checked_blocks_certificate
#print axioms p080_checked_blocks_correct
#print axioms p080_checked_blocks_cost
#print axioms p080_checked_blocks_conditional
#print axioms p080_checked_blocks_operational
#print axioms p080_checked_blocks_quadratic
#print axioms p080_checked_blocks_conditional_linear
theorem p081_nested_certificate : Certificate p081_nested := p081_nested.certify
theorem p081_nested_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p081_nested_algorithm xs) := p081_nested.run_spec xs
theorem p081_nested_cost {α : Type} [LinearOrder α] (xs : List α) : (p081_nested.eval xs).time ≤ p081_nested_costFormula xs.length := p081_nested.cost_le_upper xs
theorem p081_nested_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p081_nested.Ready xs) : (p081_nested.eval xs).time ≤ p081_nested_conditionalFormula xs.length := p081_nested.cost_le_readyUpper xs h
theorem p081_nested_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p081_nested.program xs) (p081_nested_algorithm xs) (p081_nested.eval xs).time := p081_nested.operational_certificate xs
theorem p081_nested_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p081_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p081_nested.cost_isBigO_of_upper _ p081_nested.upper_isBigO_quadratic
theorem p081_nested_formula_0 : p081_nested_costFormula 0 = 0 ∧ p081_nested_conditionalFormula 0 = 0 := by decide +kernel
theorem p081_nested_formula_1 : p081_nested_costFormula 1 = 2 ∧ p081_nested_conditionalFormula 1 = 2 := by decide +kernel
theorem p081_nested_formula_8 : p081_nested_costFormula 8 = 21 ∧ p081_nested_conditionalFormula 8 = 21 := by decide +kernel
theorem p081_nested_formula_16 : p081_nested_costFormula 16 = 58 ∧ p081_nested_conditionalFormula 16 = 58 := by decide +kernel
theorem p081_nested_formula_32 : p081_nested_costFormula 32 = 156 ∧ p081_nested_conditionalFormula 32 = 156 := by decide +kernel
theorem p081_nested_formula_64 : p081_nested_costFormula 64 = 424 ∧ p081_nested_conditionalFormula 64 = 424 := by decide +kernel
theorem p081_nested_formula_128 : p081_nested_costFormula 128 = 1200 ∧ p081_nested_conditionalFormula 128 = 1200 := by decide +kernel
#print axioms p081_nested_certificate
#print axioms p081_nested_correct
#print axioms p081_nested_cost
#print axioms p081_nested_conditional
#print axioms p081_nested_operational
#print axioms p081_nested_quadratic
theorem p082_split_certificate : Certificate p082_split := p082_split.certify
theorem p082_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p082_split_algorithm xs) := p082_split.run_spec xs
theorem p082_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p082_split.eval xs).time ≤ p082_split_costFormula xs.length := p082_split.cost_le_upper xs
theorem p082_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p082_split.Ready xs) : (p082_split.eval xs).time ≤ p082_split_conditionalFormula xs.length := p082_split.cost_le_readyUpper xs h
theorem p082_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p082_split.program xs) (p082_split_algorithm xs) (p082_split.eval xs).time := p082_split.operational_certificate xs
theorem p082_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p082_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p082_split.cost_isBigO_of_upper _ p082_split.upper_isBigO_quadratic
theorem p082_split_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p082_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p082_split.cost_isBigO_of_upper _ (p082_split.upper_isBigO_nlog 11 rfl)
theorem p082_split_formula_0 : p082_split_costFormula 0 = 0 ∧ p082_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p082_split_formula_1 : p082_split_costFormula 1 = 1 ∧ p082_split_conditionalFormula 1 = 1 := by decide +kernel
theorem p082_split_formula_8 : p082_split_costFormula 8 = 32 ∧ p082_split_conditionalFormula 8 = 32 := by decide +kernel
theorem p082_split_formula_16 : p082_split_costFormula 16 = 80 ∧ p082_split_conditionalFormula 16 = 80 := by decide +kernel
theorem p082_split_formula_32 : p082_split_costFormula 32 = 168 ∧ p082_split_conditionalFormula 32 = 168 := by decide +kernel
theorem p082_split_formula_64 : p082_split_costFormula 64 = 392 ∧ p082_split_conditionalFormula 64 = 392 := by decide +kernel
theorem p082_split_formula_128 : p082_split_costFormula 128 = 976 ∧ p082_split_conditionalFormula 128 = 976 := by decide +kernel
#print axioms p082_split_certificate
#print axioms p082_split_correct
#print axioms p082_split_cost
#print axioms p082_split_conditional
#print axioms p082_split_operational
#print axioms p082_split_quadratic
#print axioms p082_split_nlog
theorem p083_guarded_split_certificate : Certificate p083_guarded_split := p083_guarded_split.certify
theorem p083_guarded_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p083_guarded_split_algorithm xs) := p083_guarded_split.run_spec xs
theorem p083_guarded_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p083_guarded_split.eval xs).time ≤ p083_guarded_split_costFormula xs.length := p083_guarded_split.cost_le_upper xs
theorem p083_guarded_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p083_guarded_split.Ready xs) : (p083_guarded_split.eval xs).time ≤ p083_guarded_split_conditionalFormula xs.length := p083_guarded_split.cost_le_readyUpper xs h
theorem p083_guarded_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p083_guarded_split.program xs) (p083_guarded_split_algorithm xs) (p083_guarded_split.eval xs).time := p083_guarded_split.operational_certificate xs
theorem p083_guarded_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p083_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p083_guarded_split.cost_isBigO_of_upper _ p083_guarded_split.upper_isBigO_quadratic
theorem p083_guarded_split_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p083_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p083_guarded_split.cost_isBigO_of_upper _ (p083_guarded_split.upper_isBigO_nlog 12 rfl)
theorem p083_guarded_split_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p083_guarded_split.Ready xs} => ((p083_guarded_split.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p083_guarded_split.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p083_guarded_split.Ready xs} => (xs.val.length : ℝ)) := p083_guarded_split.ready_cost_isBigO_linear 0 rfl
theorem p083_guarded_split_formula_0 : p083_guarded_split_costFormula 0 = 0 ∧ p083_guarded_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p083_guarded_split_formula_1 : p083_guarded_split_costFormula 1 = 1 ∧ p083_guarded_split_conditionalFormula 1 = 0 := by decide +kernel
theorem p083_guarded_split_formula_8 : p083_guarded_split_costFormula 8 = 39 ∧ p083_guarded_split_conditionalFormula 8 = 7 := by decide +kernel
theorem p083_guarded_split_formula_16 : p083_guarded_split_costFormula 16 = 95 ∧ p083_guarded_split_conditionalFormula 16 = 15 := by decide +kernel
theorem p083_guarded_split_formula_32 : p083_guarded_split_costFormula 32 = 199 ∧ p083_guarded_split_conditionalFormula 32 = 31 := by decide +kernel
theorem p083_guarded_split_formula_64 : p083_guarded_split_costFormula 64 = 455 ∧ p083_guarded_split_conditionalFormula 64 = 63 := by decide +kernel
theorem p083_guarded_split_formula_128 : p083_guarded_split_costFormula 128 = 1103 ∧ p083_guarded_split_conditionalFormula 128 = 127 := by decide +kernel
#print axioms p083_guarded_split_certificate
#print axioms p083_guarded_split_correct
#print axioms p083_guarded_split_cost
#print axioms p083_guarded_split_conditional
#print axioms p083_guarded_split_operational
#print axioms p083_guarded_split_quadratic
#print axioms p083_guarded_split_nlog
#print axioms p083_guarded_split_conditional_linear
theorem p084_checked_blocks_certificate : Certificate p084_checked_blocks := p084_checked_blocks.certify
theorem p084_checked_blocks_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p084_checked_blocks_algorithm xs) := p084_checked_blocks.run_spec xs
theorem p084_checked_blocks_cost {α : Type} [LinearOrder α] (xs : List α) : (p084_checked_blocks.eval xs).time ≤ p084_checked_blocks_costFormula xs.length := p084_checked_blocks.cost_le_upper xs
theorem p084_checked_blocks_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p084_checked_blocks.Ready xs) : (p084_checked_blocks.eval xs).time ≤ p084_checked_blocks_conditionalFormula xs.length := p084_checked_blocks.cost_le_readyUpper xs h
theorem p084_checked_blocks_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p084_checked_blocks.program xs) (p084_checked_blocks_algorithm xs) (p084_checked_blocks.eval xs).time := p084_checked_blocks.operational_certificate xs
theorem p084_checked_blocks_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p084_checked_blocks.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p084_checked_blocks.cost_isBigO_of_upper _ p084_checked_blocks.upper_isBigO_quadratic
theorem p084_checked_blocks_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p084_checked_blocks.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p084_checked_blocks.cost_isBigO_of_upper _ (p084_checked_blocks.upper_isBigO_nlog 13 rfl)
theorem p084_checked_blocks_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p084_checked_blocks.Ready xs} => ((p084_checked_blocks.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p084_checked_blocks.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p084_checked_blocks.Ready xs} => (xs.val.length : ℝ)) := p084_checked_blocks.ready_cost_isBigO_linear 1 rfl
theorem p084_checked_blocks_formula_0 : p084_checked_blocks_costFormula 0 = 0 ∧ p084_checked_blocks_conditionalFormula 0 = 0 := by decide +kernel
theorem p084_checked_blocks_formula_1 : p084_checked_blocks_costFormula 1 = 1 ∧ p084_checked_blocks_conditionalFormula 1 = 1 := by decide +kernel
theorem p084_checked_blocks_formula_8 : p084_checked_blocks_costFormula 8 = 39 ∧ p084_checked_blocks_conditionalFormula 8 = 15 := by decide +kernel
theorem p084_checked_blocks_formula_16 : p084_checked_blocks_costFormula 16 = 95 ∧ p084_checked_blocks_conditionalFormula 16 = 31 := by decide +kernel
theorem p084_checked_blocks_formula_32 : p084_checked_blocks_costFormula 32 = 198 ∧ p084_checked_blocks_conditionalFormula 32 = 62 := by decide +kernel
theorem p084_checked_blocks_formula_64 : p084_checked_blocks_costFormula 64 = 454 ∧ p084_checked_blocks_conditionalFormula 64 = 126 := by decide +kernel
theorem p084_checked_blocks_formula_128 : p084_checked_blocks_costFormula 128 = 1102 ∧ p084_checked_blocks_conditionalFormula 128 = 254 := by decide +kernel
#print axioms p084_checked_blocks_certificate
#print axioms p084_checked_blocks_correct
#print axioms p084_checked_blocks_cost
#print axioms p084_checked_blocks_conditional
#print axioms p084_checked_blocks_operational
#print axioms p084_checked_blocks_quadratic
#print axioms p084_checked_blocks_nlog
#print axioms p084_checked_blocks_conditional_linear
theorem p085_nested_certificate : Certificate p085_nested := p085_nested.certify
theorem p085_nested_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p085_nested_algorithm xs) := p085_nested.run_spec xs
theorem p085_nested_cost {α : Type} [LinearOrder α] (xs : List α) : (p085_nested.eval xs).time ≤ p085_nested_costFormula xs.length := p085_nested.cost_le_upper xs
theorem p085_nested_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p085_nested.Ready xs) : (p085_nested.eval xs).time ≤ p085_nested_conditionalFormula xs.length := p085_nested.cost_le_readyUpper xs h
theorem p085_nested_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p085_nested.program xs) (p085_nested_algorithm xs) (p085_nested.eval xs).time := p085_nested.operational_certificate xs
theorem p085_nested_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p085_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p085_nested.cost_isBigO_of_upper _ p085_nested.upper_isBigO_quadratic
theorem p085_nested_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p085_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p085_nested.cost_isBigO_of_upper _ (p085_nested.upper_isBigO_nlog 13 rfl)
theorem p085_nested_formula_0 : p085_nested_costFormula 0 = 0 ∧ p085_nested_conditionalFormula 0 = 0 := by decide +kernel
theorem p085_nested_formula_1 : p085_nested_costFormula 1 = 1 ∧ p085_nested_conditionalFormula 1 = 1 := by decide +kernel
theorem p085_nested_formula_8 : p085_nested_costFormula 8 = 32 ∧ p085_nested_conditionalFormula 8 = 32 := by decide +kernel
theorem p085_nested_formula_16 : p085_nested_costFormula 16 = 80 ∧ p085_nested_conditionalFormula 16 = 80 := by decide +kernel
theorem p085_nested_formula_32 : p085_nested_costFormula 32 = 164 ∧ p085_nested_conditionalFormula 32 = 164 := by decide +kernel
theorem p085_nested_formula_64 : p085_nested_costFormula 64 = 404 ∧ p085_nested_conditionalFormula 64 = 404 := by decide +kernel
theorem p085_nested_formula_128 : p085_nested_costFormula 128 = 976 ∧ p085_nested_conditionalFormula 128 = 976 := by decide +kernel
#print axioms p085_nested_certificate
#print axioms p085_nested_correct
#print axioms p085_nested_cost
#print axioms p085_nested_conditional
#print axioms p085_nested_operational
#print axioms p085_nested_quadratic
#print axioms p085_nested_nlog
theorem p086_split_certificate : Certificate p086_split := p086_split.certify
theorem p086_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p086_split_algorithm xs) := p086_split.run_spec xs
theorem p086_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p086_split.eval xs).time ≤ p086_split_costFormula xs.length := p086_split.cost_le_upper xs
theorem p086_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p086_split.Ready xs) : (p086_split.eval xs).time ≤ p086_split_conditionalFormula xs.length := p086_split.cost_le_readyUpper xs h
theorem p086_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p086_split.program xs) (p086_split_algorithm xs) (p086_split.eval xs).time := p086_split.operational_certificate xs
theorem p086_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p086_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p086_split.cost_isBigO_of_upper _ p086_split.upper_isBigO_quadratic
theorem p086_split_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p086_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p086_split.cost_isBigO_of_upper _ (p086_split.upper_isBigO_nlog 7 rfl)
theorem p086_split_formula_0 : p086_split_costFormula 0 = 0 ∧ p086_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p086_split_formula_1 : p086_split_costFormula 1 = 1 ∧ p086_split_conditionalFormula 1 = 1 := by decide +kernel
theorem p086_split_formula_8 : p086_split_costFormula 8 = 28 ∧ p086_split_conditionalFormula 8 = 28 := by decide +kernel
theorem p086_split_formula_16 : p086_split_costFormula 16 = 72 ∧ p086_split_conditionalFormula 16 = 72 := by decide +kernel
theorem p086_split_formula_32 : p086_split_costFormula 32 = 152 ∧ p086_split_conditionalFormula 32 = 152 := by decide +kernel
theorem p086_split_formula_64 : p086_split_costFormula 64 = 408 ∧ p086_split_conditionalFormula 64 = 408 := by decide +kernel
theorem p086_split_formula_128 : p086_split_costFormula 128 = 968 ∧ p086_split_conditionalFormula 128 = 968 := by decide +kernel
#print axioms p086_split_certificate
#print axioms p086_split_correct
#print axioms p086_split_cost
#print axioms p086_split_conditional
#print axioms p086_split_operational
#print axioms p086_split_quadratic
#print axioms p086_split_nlog
theorem p087_guarded_split_certificate : Certificate p087_guarded_split := p087_guarded_split.certify
theorem p087_guarded_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p087_guarded_split_algorithm xs) := p087_guarded_split.run_spec xs
theorem p087_guarded_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p087_guarded_split.eval xs).time ≤ p087_guarded_split_costFormula xs.length := p087_guarded_split.cost_le_upper xs
theorem p087_guarded_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p087_guarded_split.Ready xs) : (p087_guarded_split.eval xs).time ≤ p087_guarded_split_conditionalFormula xs.length := p087_guarded_split.cost_le_readyUpper xs h
theorem p087_guarded_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p087_guarded_split.program xs) (p087_guarded_split_algorithm xs) (p087_guarded_split.eval xs).time := p087_guarded_split.operational_certificate xs
theorem p087_guarded_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p087_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p087_guarded_split.cost_isBigO_of_upper _ p087_guarded_split.upper_isBigO_quadratic
theorem p087_guarded_split_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p087_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p087_guarded_split.cost_isBigO_of_upper _ (p087_guarded_split.upper_isBigO_nlog 8 rfl)
theorem p087_guarded_split_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p087_guarded_split.Ready xs} => ((p087_guarded_split.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p087_guarded_split.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p087_guarded_split.Ready xs} => (xs.val.length : ℝ)) := p087_guarded_split.ready_cost_isBigO_linear 0 rfl
theorem p087_guarded_split_formula_0 : p087_guarded_split_costFormula 0 = 0 ∧ p087_guarded_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p087_guarded_split_formula_1 : p087_guarded_split_costFormula 1 = 1 ∧ p087_guarded_split_conditionalFormula 1 = 0 := by decide +kernel
theorem p087_guarded_split_formula_8 : p087_guarded_split_costFormula 8 = 35 ∧ p087_guarded_split_conditionalFormula 8 = 7 := by decide +kernel
theorem p087_guarded_split_formula_16 : p087_guarded_split_costFormula 16 = 87 ∧ p087_guarded_split_conditionalFormula 16 = 15 := by decide +kernel
theorem p087_guarded_split_formula_32 : p087_guarded_split_costFormula 32 = 183 ∧ p087_guarded_split_conditionalFormula 32 = 31 := by decide +kernel
theorem p087_guarded_split_formula_64 : p087_guarded_split_costFormula 64 = 471 ∧ p087_guarded_split_conditionalFormula 64 = 63 := by decide +kernel
theorem p087_guarded_split_formula_128 : p087_guarded_split_costFormula 128 = 1095 ∧ p087_guarded_split_conditionalFormula 128 = 127 := by decide +kernel
#print axioms p087_guarded_split_certificate
#print axioms p087_guarded_split_correct
#print axioms p087_guarded_split_cost
#print axioms p087_guarded_split_conditional
#print axioms p087_guarded_split_operational
#print axioms p087_guarded_split_quadratic
#print axioms p087_guarded_split_nlog
#print axioms p087_guarded_split_conditional_linear
theorem p088_checked_blocks_certificate : Certificate p088_checked_blocks := p088_checked_blocks.certify
theorem p088_checked_blocks_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p088_checked_blocks_algorithm xs) := p088_checked_blocks.run_spec xs
theorem p088_checked_blocks_cost {α : Type} [LinearOrder α] (xs : List α) : (p088_checked_blocks.eval xs).time ≤ p088_checked_blocks_costFormula xs.length := p088_checked_blocks.cost_le_upper xs
theorem p088_checked_blocks_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p088_checked_blocks.Ready xs) : (p088_checked_blocks.eval xs).time ≤ p088_checked_blocks_conditionalFormula xs.length := p088_checked_blocks.cost_le_readyUpper xs h
theorem p088_checked_blocks_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p088_checked_blocks.program xs) (p088_checked_blocks_algorithm xs) (p088_checked_blocks.eval xs).time := p088_checked_blocks.operational_certificate xs
theorem p088_checked_blocks_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p088_checked_blocks.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p088_checked_blocks.cost_isBigO_of_upper _ p088_checked_blocks.upper_isBigO_quadratic
theorem p088_checked_blocks_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p088_checked_blocks.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p088_checked_blocks.cost_isBigO_of_upper _ (p088_checked_blocks.upper_isBigO_nlog 9 rfl)
theorem p088_checked_blocks_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p088_checked_blocks.Ready xs} => ((p088_checked_blocks.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p088_checked_blocks.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p088_checked_blocks.Ready xs} => (xs.val.length : ℝ)) := p088_checked_blocks.ready_cost_isBigO_linear 1 rfl
theorem p088_checked_blocks_formula_0 : p088_checked_blocks_costFormula 0 = 0 ∧ p088_checked_blocks_conditionalFormula 0 = 0 := by decide +kernel
theorem p088_checked_blocks_formula_1 : p088_checked_blocks_costFormula 1 = 1 ∧ p088_checked_blocks_conditionalFormula 1 = 1 := by decide +kernel
theorem p088_checked_blocks_formula_8 : p088_checked_blocks_costFormula 8 = 35 ∧ p088_checked_blocks_conditionalFormula 8 = 15 := by decide +kernel
theorem p088_checked_blocks_formula_16 : p088_checked_blocks_costFormula 16 = 87 ∧ p088_checked_blocks_conditionalFormula 16 = 31 := by decide +kernel
theorem p088_checked_blocks_formula_32 : p088_checked_blocks_costFormula 32 = 182 ∧ p088_checked_blocks_conditionalFormula 32 = 62 := by decide +kernel
theorem p088_checked_blocks_formula_64 : p088_checked_blocks_costFormula 64 = 470 ∧ p088_checked_blocks_conditionalFormula 64 = 126 := by decide +kernel
theorem p088_checked_blocks_formula_128 : p088_checked_blocks_costFormula 128 = 1094 ∧ p088_checked_blocks_conditionalFormula 128 = 254 := by decide +kernel
#print axioms p088_checked_blocks_certificate
#print axioms p088_checked_blocks_correct
#print axioms p088_checked_blocks_cost
#print axioms p088_checked_blocks_conditional
#print axioms p088_checked_blocks_operational
#print axioms p088_checked_blocks_quadratic
#print axioms p088_checked_blocks_nlog
#print axioms p088_checked_blocks_conditional_linear
theorem p089_nested_certificate : Certificate p089_nested := p089_nested.certify
theorem p089_nested_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p089_nested_algorithm xs) := p089_nested.run_spec xs
theorem p089_nested_cost {α : Type} [LinearOrder α] (xs : List α) : (p089_nested.eval xs).time ≤ p089_nested_costFormula xs.length := p089_nested.cost_le_upper xs
theorem p089_nested_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p089_nested.Ready xs) : (p089_nested.eval xs).time ≤ p089_nested_conditionalFormula xs.length := p089_nested.cost_le_readyUpper xs h
theorem p089_nested_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p089_nested.program xs) (p089_nested_algorithm xs) (p089_nested.eval xs).time := p089_nested.operational_certificate xs
theorem p089_nested_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p089_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p089_nested.cost_isBigO_of_upper _ p089_nested.upper_isBigO_quadratic
theorem p089_nested_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p089_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p089_nested.cost_isBigO_of_upper _ (p089_nested.upper_isBigO_nlog 9 rfl)
theorem p089_nested_formula_0 : p089_nested_costFormula 0 = 0 ∧ p089_nested_conditionalFormula 0 = 0 := by decide +kernel
theorem p089_nested_formula_1 : p089_nested_costFormula 1 = 1 ∧ p089_nested_conditionalFormula 1 = 1 := by decide +kernel
theorem p089_nested_formula_8 : p089_nested_costFormula 8 = 28 ∧ p089_nested_conditionalFormula 8 = 28 := by decide +kernel
theorem p089_nested_formula_16 : p089_nested_costFormula 16 = 72 ∧ p089_nested_conditionalFormula 16 = 72 := by decide +kernel
theorem p089_nested_formula_32 : p089_nested_costFormula 32 = 152 ∧ p089_nested_conditionalFormula 32 = 152 := by decide +kernel
theorem p089_nested_formula_64 : p089_nested_costFormula 64 = 408 ∧ p089_nested_conditionalFormula 64 = 408 := by decide +kernel
theorem p089_nested_formula_128 : p089_nested_costFormula 128 = 968 ∧ p089_nested_conditionalFormula 128 = 968 := by decide +kernel
#print axioms p089_nested_certificate
#print axioms p089_nested_correct
#print axioms p089_nested_cost
#print axioms p089_nested_conditional
#print axioms p089_nested_operational
#print axioms p089_nested_quadratic
#print axioms p089_nested_nlog
theorem p090_split_certificate : Certificate p090_split := p090_split.certify
theorem p090_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p090_split_algorithm xs) := p090_split.run_spec xs
theorem p090_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p090_split.eval xs).time ≤ p090_split_costFormula xs.length := p090_split.cost_le_upper xs
theorem p090_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p090_split.Ready xs) : (p090_split.eval xs).time ≤ p090_split_conditionalFormula xs.length := p090_split.cost_le_readyUpper xs h
theorem p090_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p090_split.program xs) (p090_split_algorithm xs) (p090_split.eval xs).time := p090_split.operational_certificate xs
theorem p090_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p090_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p090_split.cost_isBigO_of_upper _ p090_split.upper_isBigO_quadratic
theorem p090_split_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p090_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p090_split.cost_isBigO_of_upper _ (p090_split.upper_isBigO_nlog 27 rfl)
theorem p090_split_formula_0 : p090_split_costFormula 0 = 0 ∧ p090_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p090_split_formula_1 : p090_split_costFormula 1 = 1 ∧ p090_split_conditionalFormula 1 = 1 := by decide +kernel
theorem p090_split_formula_8 : p090_split_costFormula 8 = 36 ∧ p090_split_conditionalFormula 8 = 36 := by decide +kernel
theorem p090_split_formula_16 : p090_split_costFormula 16 = 72 ∧ p090_split_conditionalFormula 16 = 72 := by decide +kernel
theorem p090_split_formula_32 : p090_split_costFormula 32 = 216 ∧ p090_split_conditionalFormula 32 = 216 := by decide +kernel
theorem p090_split_formula_64 : p090_split_costFormula 64 = 568 ∧ p090_split_conditionalFormula 64 = 568 := by decide +kernel
theorem p090_split_formula_128 : p090_split_costFormula 128 = 1356 ∧ p090_split_conditionalFormula 128 = 1356 := by decide +kernel
#print axioms p090_split_certificate
#print axioms p090_split_correct
#print axioms p090_split_cost
#print axioms p090_split_conditional
#print axioms p090_split_operational
#print axioms p090_split_quadratic
#print axioms p090_split_nlog
theorem p091_guarded_split_certificate : Certificate p091_guarded_split := p091_guarded_split.certify
theorem p091_guarded_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p091_guarded_split_algorithm xs) := p091_guarded_split.run_spec xs
theorem p091_guarded_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p091_guarded_split.eval xs).time ≤ p091_guarded_split_costFormula xs.length := p091_guarded_split.cost_le_upper xs
theorem p091_guarded_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p091_guarded_split.Ready xs) : (p091_guarded_split.eval xs).time ≤ p091_guarded_split_conditionalFormula xs.length := p091_guarded_split.cost_le_readyUpper xs h
theorem p091_guarded_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p091_guarded_split.program xs) (p091_guarded_split_algorithm xs) (p091_guarded_split.eval xs).time := p091_guarded_split.operational_certificate xs
theorem p091_guarded_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p091_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p091_guarded_split.cost_isBigO_of_upper _ p091_guarded_split.upper_isBigO_quadratic
theorem p091_guarded_split_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p091_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p091_guarded_split.cost_isBigO_of_upper _ (p091_guarded_split.upper_isBigO_nlog 28 rfl)
theorem p091_guarded_split_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p091_guarded_split.Ready xs} => ((p091_guarded_split.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p091_guarded_split.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p091_guarded_split.Ready xs} => (xs.val.length : ℝ)) := p091_guarded_split.ready_cost_isBigO_linear 0 rfl
theorem p091_guarded_split_formula_0 : p091_guarded_split_costFormula 0 = 0 ∧ p091_guarded_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p091_guarded_split_formula_1 : p091_guarded_split_costFormula 1 = 1 ∧ p091_guarded_split_conditionalFormula 1 = 0 := by decide +kernel
theorem p091_guarded_split_formula_8 : p091_guarded_split_costFormula 8 = 43 ∧ p091_guarded_split_conditionalFormula 8 = 7 := by decide +kernel
theorem p091_guarded_split_formula_16 : p091_guarded_split_costFormula 16 = 87 ∧ p091_guarded_split_conditionalFormula 16 = 15 := by decide +kernel
theorem p091_guarded_split_formula_32 : p091_guarded_split_costFormula 32 = 247 ∧ p091_guarded_split_conditionalFormula 32 = 31 := by decide +kernel
theorem p091_guarded_split_formula_64 : p091_guarded_split_costFormula 64 = 631 ∧ p091_guarded_split_conditionalFormula 64 = 63 := by decide +kernel
theorem p091_guarded_split_formula_128 : p091_guarded_split_costFormula 128 = 1483 ∧ p091_guarded_split_conditionalFormula 128 = 127 := by decide +kernel
#print axioms p091_guarded_split_certificate
#print axioms p091_guarded_split_correct
#print axioms p091_guarded_split_cost
#print axioms p091_guarded_split_conditional
#print axioms p091_guarded_split_operational
#print axioms p091_guarded_split_quadratic
#print axioms p091_guarded_split_nlog
#print axioms p091_guarded_split_conditional_linear
theorem p092_checked_blocks_certificate : Certificate p092_checked_blocks := p092_checked_blocks.certify
theorem p092_checked_blocks_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p092_checked_blocks_algorithm xs) := p092_checked_blocks.run_spec xs
theorem p092_checked_blocks_cost {α : Type} [LinearOrder α] (xs : List α) : (p092_checked_blocks.eval xs).time ≤ p092_checked_blocks_costFormula xs.length := p092_checked_blocks.cost_le_upper xs
theorem p092_checked_blocks_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p092_checked_blocks.Ready xs) : (p092_checked_blocks.eval xs).time ≤ p092_checked_blocks_conditionalFormula xs.length := p092_checked_blocks.cost_le_readyUpper xs h
theorem p092_checked_blocks_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p092_checked_blocks.program xs) (p092_checked_blocks_algorithm xs) (p092_checked_blocks.eval xs).time := p092_checked_blocks.operational_certificate xs
theorem p092_checked_blocks_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p092_checked_blocks.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p092_checked_blocks.cost_isBigO_of_upper _ p092_checked_blocks.upper_isBigO_quadratic
theorem p092_checked_blocks_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p092_checked_blocks.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p092_checked_blocks.cost_isBigO_of_upper _ (p092_checked_blocks.upper_isBigO_nlog 29 rfl)
theorem p092_checked_blocks_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p092_checked_blocks.Ready xs} => ((p092_checked_blocks.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p092_checked_blocks.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p092_checked_blocks.Ready xs} => (xs.val.length : ℝ)) := p092_checked_blocks.ready_cost_isBigO_linear 1 rfl
theorem p092_checked_blocks_formula_0 : p092_checked_blocks_costFormula 0 = 0 ∧ p092_checked_blocks_conditionalFormula 0 = 0 := by decide +kernel
theorem p092_checked_blocks_formula_1 : p092_checked_blocks_costFormula 1 = 1 ∧ p092_checked_blocks_conditionalFormula 1 = 1 := by decide +kernel
theorem p092_checked_blocks_formula_8 : p092_checked_blocks_costFormula 8 = 43 ∧ p092_checked_blocks_conditionalFormula 8 = 15 := by decide +kernel
theorem p092_checked_blocks_formula_16 : p092_checked_blocks_costFormula 16 = 86 ∧ p092_checked_blocks_conditionalFormula 16 = 30 := by decide +kernel
theorem p092_checked_blocks_formula_32 : p092_checked_blocks_costFormula 32 = 246 ∧ p092_checked_blocks_conditionalFormula 32 = 62 := by decide +kernel
theorem p092_checked_blocks_formula_64 : p092_checked_blocks_costFormula 64 = 630 ∧ p092_checked_blocks_conditionalFormula 64 = 126 := by decide +kernel
theorem p092_checked_blocks_formula_128 : p092_checked_blocks_costFormula 128 = 1482 ∧ p092_checked_blocks_conditionalFormula 128 = 254 := by decide +kernel
#print axioms p092_checked_blocks_certificate
#print axioms p092_checked_blocks_correct
#print axioms p092_checked_blocks_cost
#print axioms p092_checked_blocks_conditional
#print axioms p092_checked_blocks_operational
#print axioms p092_checked_blocks_quadratic
#print axioms p092_checked_blocks_nlog
#print axioms p092_checked_blocks_conditional_linear
theorem p093_nested_certificate : Certificate p093_nested := p093_nested.certify
theorem p093_nested_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p093_nested_algorithm xs) := p093_nested.run_spec xs
theorem p093_nested_cost {α : Type} [LinearOrder α] (xs : List α) : (p093_nested.eval xs).time ≤ p093_nested_costFormula xs.length := p093_nested.cost_le_upper xs
theorem p093_nested_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p093_nested.Ready xs) : (p093_nested.eval xs).time ≤ p093_nested_conditionalFormula xs.length := p093_nested.cost_le_readyUpper xs h
theorem p093_nested_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p093_nested.program xs) (p093_nested_algorithm xs) (p093_nested.eval xs).time := p093_nested.operational_certificate xs
theorem p093_nested_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p093_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p093_nested.cost_isBigO_of_upper _ p093_nested.upper_isBigO_quadratic
theorem p093_nested_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p093_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p093_nested.cost_isBigO_of_upper _ (p093_nested.upper_isBigO_nlog 29 rfl)
theorem p093_nested_formula_0 : p093_nested_costFormula 0 = 0 ∧ p093_nested_conditionalFormula 0 = 0 := by decide +kernel
theorem p093_nested_formula_1 : p093_nested_costFormula 1 = 1 ∧ p093_nested_conditionalFormula 1 = 1 := by decide +kernel
theorem p093_nested_formula_8 : p093_nested_costFormula 8 = 36 ∧ p093_nested_conditionalFormula 8 = 36 := by decide +kernel
theorem p093_nested_formula_16 : p093_nested_costFormula 16 = 66 ∧ p093_nested_conditionalFormula 16 = 66 := by decide +kernel
theorem p093_nested_formula_32 : p093_nested_costFormula 32 = 198 ∧ p093_nested_conditionalFormula 32 = 198 := by decide +kernel
theorem p093_nested_formula_64 : p093_nested_costFormula 64 = 498 ∧ p093_nested_conditionalFormula 64 = 498 := by decide +kernel
theorem p093_nested_formula_128 : p093_nested_costFormula 128 = 1176 ∧ p093_nested_conditionalFormula 128 = 1176 := by decide +kernel
#print axioms p093_nested_certificate
#print axioms p093_nested_correct
#print axioms p093_nested_cost
#print axioms p093_nested_conditional
#print axioms p093_nested_operational
#print axioms p093_nested_quadratic
#print axioms p093_nested_nlog
theorem p094_split_certificate : Certificate p094_split := p094_split.certify
theorem p094_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p094_split_algorithm xs) := p094_split.run_spec xs
theorem p094_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p094_split.eval xs).time ≤ p094_split_costFormula xs.length := p094_split.cost_le_upper xs
theorem p094_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p094_split.Ready xs) : (p094_split.eval xs).time ≤ p094_split_conditionalFormula xs.length := p094_split.cost_le_readyUpper xs h
theorem p094_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p094_split.program xs) (p094_split_algorithm xs) (p094_split.eval xs).time := p094_split.operational_certificate xs
theorem p094_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p094_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p094_split.cost_isBigO_of_upper _ p094_split.upper_isBigO_quadratic
theorem p094_split_formula_0 : p094_split_costFormula 0 = 0 ∧ p094_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p094_split_formula_1 : p094_split_costFormula 1 = 1 ∧ p094_split_conditionalFormula 1 = 1 := by decide +kernel
theorem p094_split_formula_8 : p094_split_costFormula 8 = 36 ∧ p094_split_conditionalFormula 8 = 36 := by decide +kernel
theorem p094_split_formula_16 : p094_split_costFormula 16 = 72 ∧ p094_split_conditionalFormula 16 = 72 := by decide +kernel
theorem p094_split_formula_32 : p094_split_costFormula 32 = 336 ∧ p094_split_conditionalFormula 32 = 336 := by decide +kernel
theorem p094_split_formula_64 : p094_split_costFormula 64 = 1632 ∧ p094_split_conditionalFormula 64 = 1632 := by decide +kernel
theorem p094_split_formula_128 : p094_split_costFormula 128 = 7296 ∧ p094_split_conditionalFormula 128 = 7296 := by decide +kernel
#print axioms p094_split_certificate
#print axioms p094_split_correct
#print axioms p094_split_cost
#print axioms p094_split_conditional
#print axioms p094_split_operational
#print axioms p094_split_quadratic
theorem p095_guarded_split_certificate : Certificate p095_guarded_split := p095_guarded_split.certify
theorem p095_guarded_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p095_guarded_split_algorithm xs) := p095_guarded_split.run_spec xs
theorem p095_guarded_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p095_guarded_split.eval xs).time ≤ p095_guarded_split_costFormula xs.length := p095_guarded_split.cost_le_upper xs
theorem p095_guarded_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p095_guarded_split.Ready xs) : (p095_guarded_split.eval xs).time ≤ p095_guarded_split_conditionalFormula xs.length := p095_guarded_split.cost_le_readyUpper xs h
theorem p095_guarded_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p095_guarded_split.program xs) (p095_guarded_split_algorithm xs) (p095_guarded_split.eval xs).time := p095_guarded_split.operational_certificate xs
theorem p095_guarded_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p095_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p095_guarded_split.cost_isBigO_of_upper _ p095_guarded_split.upper_isBigO_quadratic
theorem p095_guarded_split_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p095_guarded_split.Ready xs} => ((p095_guarded_split.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p095_guarded_split.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p095_guarded_split.Ready xs} => (xs.val.length : ℝ)) := p095_guarded_split.ready_cost_isBigO_linear 0 rfl
theorem p095_guarded_split_formula_0 : p095_guarded_split_costFormula 0 = 0 ∧ p095_guarded_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p095_guarded_split_formula_1 : p095_guarded_split_costFormula 1 = 1 ∧ p095_guarded_split_conditionalFormula 1 = 0 := by decide +kernel
theorem p095_guarded_split_formula_8 : p095_guarded_split_costFormula 8 = 43 ∧ p095_guarded_split_conditionalFormula 8 = 7 := by decide +kernel
theorem p095_guarded_split_formula_16 : p095_guarded_split_costFormula 16 = 87 ∧ p095_guarded_split_conditionalFormula 16 = 15 := by decide +kernel
theorem p095_guarded_split_formula_32 : p095_guarded_split_costFormula 32 = 367 ∧ p095_guarded_split_conditionalFormula 32 = 31 := by decide +kernel
theorem p095_guarded_split_formula_64 : p095_guarded_split_costFormula 64 = 1695 ∧ p095_guarded_split_conditionalFormula 64 = 63 := by decide +kernel
theorem p095_guarded_split_formula_128 : p095_guarded_split_costFormula 128 = 7423 ∧ p095_guarded_split_conditionalFormula 128 = 127 := by decide +kernel
#print axioms p095_guarded_split_certificate
#print axioms p095_guarded_split_correct
#print axioms p095_guarded_split_cost
#print axioms p095_guarded_split_conditional
#print axioms p095_guarded_split_operational
#print axioms p095_guarded_split_quadratic
#print axioms p095_guarded_split_conditional_linear
theorem p096_checked_blocks_certificate : Certificate p096_checked_blocks := p096_checked_blocks.certify
theorem p096_checked_blocks_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p096_checked_blocks_algorithm xs) := p096_checked_blocks.run_spec xs
theorem p096_checked_blocks_cost {α : Type} [LinearOrder α] (xs : List α) : (p096_checked_blocks.eval xs).time ≤ p096_checked_blocks_costFormula xs.length := p096_checked_blocks.cost_le_upper xs
theorem p096_checked_blocks_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p096_checked_blocks.Ready xs) : (p096_checked_blocks.eval xs).time ≤ p096_checked_blocks_conditionalFormula xs.length := p096_checked_blocks.cost_le_readyUpper xs h
theorem p096_checked_blocks_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p096_checked_blocks.program xs) (p096_checked_blocks_algorithm xs) (p096_checked_blocks.eval xs).time := p096_checked_blocks.operational_certificate xs
theorem p096_checked_blocks_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p096_checked_blocks.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p096_checked_blocks.cost_isBigO_of_upper _ p096_checked_blocks.upper_isBigO_quadratic
theorem p096_checked_blocks_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p096_checked_blocks.Ready xs} => ((p096_checked_blocks.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p096_checked_blocks.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p096_checked_blocks.Ready xs} => (xs.val.length : ℝ)) := p096_checked_blocks.ready_cost_isBigO_linear 1 rfl
theorem p096_checked_blocks_formula_0 : p096_checked_blocks_costFormula 0 = 0 ∧ p096_checked_blocks_conditionalFormula 0 = 0 := by decide +kernel
theorem p096_checked_blocks_formula_1 : p096_checked_blocks_costFormula 1 = 1 ∧ p096_checked_blocks_conditionalFormula 1 = 1 := by decide +kernel
theorem p096_checked_blocks_formula_8 : p096_checked_blocks_costFormula 8 = 43 ∧ p096_checked_blocks_conditionalFormula 8 = 15 := by decide +kernel
theorem p096_checked_blocks_formula_16 : p096_checked_blocks_costFormula 16 = 86 ∧ p096_checked_blocks_conditionalFormula 16 = 30 := by decide +kernel
theorem p096_checked_blocks_formula_32 : p096_checked_blocks_costFormula 32 = 366 ∧ p096_checked_blocks_conditionalFormula 32 = 62 := by decide +kernel
theorem p096_checked_blocks_formula_64 : p096_checked_blocks_costFormula 64 = 1694 ∧ p096_checked_blocks_conditionalFormula 64 = 126 := by decide +kernel
theorem p096_checked_blocks_formula_128 : p096_checked_blocks_costFormula 128 = 7422 ∧ p096_checked_blocks_conditionalFormula 128 = 254 := by decide +kernel
#print axioms p096_checked_blocks_certificate
#print axioms p096_checked_blocks_correct
#print axioms p096_checked_blocks_cost
#print axioms p096_checked_blocks_conditional
#print axioms p096_checked_blocks_operational
#print axioms p096_checked_blocks_quadratic
#print axioms p096_checked_blocks_conditional_linear
theorem p097_nested_certificate : Certificate p097_nested := p097_nested.certify
theorem p097_nested_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p097_nested_algorithm xs) := p097_nested.run_spec xs
theorem p097_nested_cost {α : Type} [LinearOrder α] (xs : List α) : (p097_nested.eval xs).time ≤ p097_nested_costFormula xs.length := p097_nested.cost_le_upper xs
theorem p097_nested_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p097_nested.Ready xs) : (p097_nested.eval xs).time ≤ p097_nested_conditionalFormula xs.length := p097_nested.cost_le_readyUpper xs h
theorem p097_nested_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p097_nested.program xs) (p097_nested_algorithm xs) (p097_nested.eval xs).time := p097_nested.operational_certificate xs
theorem p097_nested_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p097_nested.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p097_nested.cost_isBigO_of_upper _ p097_nested.upper_isBigO_quadratic
theorem p097_nested_formula_0 : p097_nested_costFormula 0 = 0 ∧ p097_nested_conditionalFormula 0 = 0 := by decide +kernel
theorem p097_nested_formula_1 : p097_nested_costFormula 1 = 1 ∧ p097_nested_conditionalFormula 1 = 1 := by decide +kernel
theorem p097_nested_formula_8 : p097_nested_costFormula 8 = 36 ∧ p097_nested_conditionalFormula 8 = 36 := by decide +kernel
theorem p097_nested_formula_16 : p097_nested_costFormula 16 = 66 ∧ p097_nested_conditionalFormula 16 = 66 := by decide +kernel
theorem p097_nested_formula_32 : p097_nested_costFormula 32 = 198 ∧ p097_nested_conditionalFormula 32 = 198 := by decide +kernel
theorem p097_nested_formula_64 : p097_nested_costFormula 64 = 666 ∧ p097_nested_conditionalFormula 64 = 666 := by decide +kernel
theorem p097_nested_formula_128 : p097_nested_costFormula 128 = 2406 ∧ p097_nested_conditionalFormula 128 = 2406 := by decide +kernel
#print axioms p097_nested_certificate
#print axioms p097_nested_correct
#print axioms p097_nested_cost
#print axioms p097_nested_conditional
#print axioms p097_nested_operational
#print axioms p097_nested_quadratic
theorem p098_split_certificate : Certificate p098_split := p098_split.certify
theorem p098_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p098_split_algorithm xs) := p098_split.run_spec xs
theorem p098_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p098_split.eval xs).time ≤ p098_split_costFormula xs.length := p098_split.cost_le_upper xs
theorem p098_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p098_split.Ready xs) : (p098_split.eval xs).time ≤ p098_split_conditionalFormula xs.length := p098_split.cost_le_readyUpper xs h
theorem p098_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p098_split.program xs) (p098_split_algorithm xs) (p098_split.eval xs).time := p098_split.operational_certificate xs
theorem p098_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p098_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p098_split.cost_isBigO_of_upper _ p098_split.upper_isBigO_quadratic
theorem p098_split_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p098_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p098_split.cost_isBigO_of_upper _ (p098_split.upper_isBigO_nlog 15 rfl)
theorem p098_split_formula_0 : p098_split_costFormula 0 = 0 ∧ p098_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p098_split_formula_1 : p098_split_costFormula 1 = 1 ∧ p098_split_conditionalFormula 1 = 1 := by decide +kernel
theorem p098_split_formula_8 : p098_split_costFormula 8 = 36 ∧ p098_split_conditionalFormula 8 = 36 := by decide +kernel
theorem p098_split_formula_16 : p098_split_costFormula 16 = 88 ∧ p098_split_conditionalFormula 16 = 88 := by decide +kernel
theorem p098_split_formula_32 : p098_split_costFormula 32 = 160 ∧ p098_split_conditionalFormula 32 = 160 := by decide +kernel
theorem p098_split_formula_64 : p098_split_costFormula 64 = 376 ∧ p098_split_conditionalFormula 64 = 376 := by decide +kernel
theorem p098_split_formula_128 : p098_split_costFormula 128 = 904 ∧ p098_split_conditionalFormula 128 = 904 := by decide +kernel
#print axioms p098_split_certificate
#print axioms p098_split_correct
#print axioms p098_split_cost
#print axioms p098_split_conditional
#print axioms p098_split_operational
#print axioms p098_split_quadratic
#print axioms p098_split_nlog
theorem p099_guarded_split_certificate : Certificate p099_guarded_split := p099_guarded_split.certify
theorem p099_guarded_split_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (p099_guarded_split_algorithm xs) := p099_guarded_split.run_spec xs
theorem p099_guarded_split_cost {α : Type} [LinearOrder α] (xs : List α) : (p099_guarded_split.eval xs).time ≤ p099_guarded_split_costFormula xs.length := p099_guarded_split.cost_le_upper xs
theorem p099_guarded_split_conditional {α : Type} [LinearOrder α] (xs : List α) (h : p099_guarded_split.Ready xs) : (p099_guarded_split.eval xs).time ≤ p099_guarded_split_conditionalFormula xs.length := p099_guarded_split.cost_le_readyUpper xs h
theorem p099_guarded_split_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (p099_guarded_split.program xs) (p099_guarded_split_algorithm xs) (p099_guarded_split.eval xs).time := p099_guarded_split.operational_certificate xs
theorem p099_guarded_split_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((p099_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := p099_guarded_split.cost_isBigO_of_upper _ p099_guarded_split.upper_isBigO_quadratic
theorem p099_guarded_split_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((p099_guarded_split.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := p099_guarded_split.cost_isBigO_of_upper _ (p099_guarded_split.upper_isBigO_nlog 16 rfl)
theorem p099_guarded_split_conditional_linear {α : Type} [LinearOrder α] : (fun xs : {xs : List α // p099_guarded_split.Ready xs} => ((p099_guarded_split.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {xs : List α // p099_guarded_split.Ready xs} => xs.val.length) atTop] (fun xs : {xs : List α // p099_guarded_split.Ready xs} => (xs.val.length : ℝ)) := p099_guarded_split.ready_cost_isBigO_linear 0 rfl
theorem p099_guarded_split_formula_0 : p099_guarded_split_costFormula 0 = 0 ∧ p099_guarded_split_conditionalFormula 0 = 0 := by decide +kernel
theorem p099_guarded_split_formula_1 : p099_guarded_split_costFormula 1 = 1 ∧ p099_guarded_split_conditionalFormula 1 = 0 := by decide +kernel
theorem p099_guarded_split_formula_8 : p099_guarded_split_costFormula 8 = 43 ∧ p099_guarded_split_conditionalFormula 8 = 7 := by decide +kernel
theorem p099_guarded_split_formula_16 : p099_guarded_split_costFormula 16 = 103 ∧ p099_guarded_split_conditionalFormula 16 = 15 := by decide +kernel
theorem p099_guarded_split_formula_32 : p099_guarded_split_costFormula 32 = 191 ∧ p099_guarded_split_conditionalFormula 32 = 31 := by decide +kernel
theorem p099_guarded_split_formula_64 : p099_guarded_split_costFormula 64 = 439 ∧ p099_guarded_split_conditionalFormula 64 = 63 := by decide +kernel
theorem p099_guarded_split_formula_128 : p099_guarded_split_costFormula 128 = 1031 ∧ p099_guarded_split_conditionalFormula 128 = 127 := by decide +kernel
#print axioms p099_guarded_split_certificate
#print axioms p099_guarded_split_correct
#print axioms p099_guarded_split_cost
#print axioms p099_guarded_split_conditional
#print axioms p099_guarded_split_operational
#print axioms p099_guarded_split_quadratic
#print axioms p099_guarded_split_nlog
#print axioms p099_guarded_split_conditional_linear
theorem single_merge_certificate : Certificate single_merge := single_merge.certify
theorem single_merge_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (single_merge_algorithm xs) := single_merge.run_spec xs
theorem single_merge_cost {α : Type} [LinearOrder α] (xs : List α) : (single_merge.eval xs).time ≤ single_merge_costFormula xs.length := single_merge.cost_le_upper xs
theorem single_merge_conditional {α : Type} [LinearOrder α] (xs : List α) (h : single_merge.Ready xs) : (single_merge.eval xs).time ≤ single_merge_conditionalFormula xs.length := single_merge.cost_le_readyUpper xs h
theorem single_merge_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (single_merge.program xs) (single_merge_algorithm xs) (single_merge.eval xs).time := single_merge.operational_certificate xs
theorem single_merge_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((single_merge.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := single_merge.cost_isBigO_of_upper _ single_merge.upper_isBigO_quadratic
theorem single_merge_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((single_merge.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := single_merge.cost_isBigO_of_upper _ (single_merge.upper_isBigO_nlog 1 rfl)
theorem single_merge_formula_0 : single_merge_costFormula 0 = 0 ∧ single_merge_conditionalFormula 0 = 0 := by decide +kernel
theorem single_merge_formula_1 : single_merge_costFormula 1 = 0 ∧ single_merge_conditionalFormula 1 = 0 := by decide +kernel
theorem single_merge_formula_8 : single_merge_costFormula 8 = 24 ∧ single_merge_conditionalFormula 8 = 24 := by decide +kernel
theorem single_merge_formula_16 : single_merge_costFormula 16 = 64 ∧ single_merge_conditionalFormula 16 = 64 := by decide +kernel
theorem single_merge_formula_32 : single_merge_costFormula 32 = 160 ∧ single_merge_conditionalFormula 32 = 160 := by decide +kernel
theorem single_merge_formula_64 : single_merge_costFormula 64 = 384 ∧ single_merge_conditionalFormula 64 = 384 := by decide +kernel
theorem single_merge_formula_128 : single_merge_costFormula 128 = 896 ∧ single_merge_conditionalFormula 128 = 896 := by decide +kernel
#print axioms single_merge_certificate
#print axioms single_merge_correct
#print axioms single_merge_cost
#print axioms single_merge_conditional
#print axioms single_merge_operational
#print axioms single_merge_quadratic
#print axioms single_merge_nlog
theorem single_insertion_certificate : Certificate single_insertion := single_insertion.certify
theorem single_insertion_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (single_insertion_algorithm xs) := single_insertion.run_spec xs
theorem single_insertion_cost {α : Type} [LinearOrder α] (xs : List α) : (single_insertion.eval xs).time ≤ single_insertion_costFormula xs.length := single_insertion.cost_le_upper xs
theorem single_insertion_conditional {α : Type} [LinearOrder α] (xs : List α) (h : single_insertion.Ready xs) : (single_insertion.eval xs).time ≤ single_insertion_conditionalFormula xs.length := single_insertion.cost_le_readyUpper xs h
theorem single_insertion_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (single_insertion.program xs) (single_insertion_algorithm xs) (single_insertion.eval xs).time := single_insertion.operational_certificate xs
theorem single_insertion_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((single_insertion.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := single_insertion.cost_isBigO_of_upper _ single_insertion.upper_isBigO_quadratic
theorem single_insertion_formula_0 : single_insertion_costFormula 0 = 0 ∧ single_insertion_conditionalFormula 0 = 0 := by decide +kernel
theorem single_insertion_formula_1 : single_insertion_costFormula 1 = 0 ∧ single_insertion_conditionalFormula 1 = 0 := by decide +kernel
theorem single_insertion_formula_8 : single_insertion_costFormula 8 = 28 ∧ single_insertion_conditionalFormula 8 = 28 := by decide +kernel
theorem single_insertion_formula_16 : single_insertion_costFormula 16 = 120 ∧ single_insertion_conditionalFormula 16 = 120 := by decide +kernel
theorem single_insertion_formula_32 : single_insertion_costFormula 32 = 496 ∧ single_insertion_conditionalFormula 32 = 496 := by decide +kernel
theorem single_insertion_formula_64 : single_insertion_costFormula 64 = 2016 ∧ single_insertion_conditionalFormula 64 = 2016 := by decide +kernel
theorem single_insertion_formula_128 : single_insertion_costFormula 128 = 8128 ∧ single_insertion_conditionalFormula 128 = 8128 := by decide +kernel
#print axioms single_insertion_certificate
#print axioms single_insertion_correct
#print axioms single_insertion_cost
#print axioms single_insertion_conditional
#print axioms single_insertion_operational
#print axioms single_insertion_quadratic
theorem single_hybrid_4_certificate : Certificate single_hybrid_4 := single_hybrid_4.certify
theorem single_hybrid_4_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (single_hybrid_4_algorithm xs) := single_hybrid_4.run_spec xs
theorem single_hybrid_4_cost {α : Type} [LinearOrder α] (xs : List α) : (single_hybrid_4.eval xs).time ≤ single_hybrid_4_costFormula xs.length := single_hybrid_4.cost_le_upper xs
theorem single_hybrid_4_conditional {α : Type} [LinearOrder α] (xs : List α) (h : single_hybrid_4.Ready xs) : (single_hybrid_4.eval xs).time ≤ single_hybrid_4_conditionalFormula xs.length := single_hybrid_4.cost_le_readyUpper xs h
theorem single_hybrid_4_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (single_hybrid_4.program xs) (single_hybrid_4_algorithm xs) (single_hybrid_4.eval xs).time := single_hybrid_4.operational_certificate xs
theorem single_hybrid_4_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((single_hybrid_4.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := single_hybrid_4.cost_isBigO_of_upper _ single_hybrid_4.upper_isBigO_quadratic
theorem single_hybrid_4_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((single_hybrid_4.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := single_hybrid_4.cost_isBigO_of_upper _ (single_hybrid_4.upper_isBigO_nlog 5 rfl)
theorem single_hybrid_4_formula_0 : single_hybrid_4_costFormula 0 = 0 ∧ single_hybrid_4_conditionalFormula 0 = 0 := by decide +kernel
theorem single_hybrid_4_formula_1 : single_hybrid_4_costFormula 1 = 0 ∧ single_hybrid_4_conditionalFormula 1 = 0 := by decide +kernel
theorem single_hybrid_4_formula_8 : single_hybrid_4_costFormula 8 = 20 ∧ single_hybrid_4_conditionalFormula 8 = 20 := by decide +kernel
theorem single_hybrid_4_formula_16 : single_hybrid_4_costFormula 16 = 56 ∧ single_hybrid_4_conditionalFormula 16 = 56 := by decide +kernel
theorem single_hybrid_4_formula_32 : single_hybrid_4_costFormula 32 = 144 ∧ single_hybrid_4_conditionalFormula 32 = 144 := by decide +kernel
theorem single_hybrid_4_formula_64 : single_hybrid_4_costFormula 64 = 352 ∧ single_hybrid_4_conditionalFormula 64 = 352 := by decide +kernel
theorem single_hybrid_4_formula_128 : single_hybrid_4_costFormula 128 = 832 ∧ single_hybrid_4_conditionalFormula 128 = 832 := by decide +kernel
#print axioms single_hybrid_4_certificate
#print axioms single_hybrid_4_correct
#print axioms single_hybrid_4_cost
#print axioms single_hybrid_4_conditional
#print axioms single_hybrid_4_operational
#print axioms single_hybrid_4_quadratic
#print axioms single_hybrid_4_nlog
theorem single_hybrid_8_certificate : Certificate single_hybrid_8 := single_hybrid_8.certify
theorem single_hybrid_8_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (single_hybrid_8_algorithm xs) := single_hybrid_8.run_spec xs
theorem single_hybrid_8_cost {α : Type} [LinearOrder α] (xs : List α) : (single_hybrid_8.eval xs).time ≤ single_hybrid_8_costFormula xs.length := single_hybrid_8.cost_le_upper xs
theorem single_hybrid_8_conditional {α : Type} [LinearOrder α] (xs : List α) (h : single_hybrid_8.Ready xs) : (single_hybrid_8.eval xs).time ≤ single_hybrid_8_conditionalFormula xs.length := single_hybrid_8.cost_le_readyUpper xs h
theorem single_hybrid_8_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (single_hybrid_8.program xs) (single_hybrid_8_algorithm xs) (single_hybrid_8.eval xs).time := single_hybrid_8.operational_certificate xs
theorem single_hybrid_8_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((single_hybrid_8.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := single_hybrid_8.cost_isBigO_of_upper _ single_hybrid_8.upper_isBigO_quadratic
theorem single_hybrid_8_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((single_hybrid_8.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := single_hybrid_8.cost_isBigO_of_upper _ (single_hybrid_8.upper_isBigO_nlog 9 rfl)
theorem single_hybrid_8_formula_0 : single_hybrid_8_costFormula 0 = 0 ∧ single_hybrid_8_conditionalFormula 0 = 0 := by decide +kernel
theorem single_hybrid_8_formula_1 : single_hybrid_8_costFormula 1 = 0 ∧ single_hybrid_8_conditionalFormula 1 = 0 := by decide +kernel
theorem single_hybrid_8_formula_8 : single_hybrid_8_costFormula 8 = 28 ∧ single_hybrid_8_conditionalFormula 8 = 28 := by decide +kernel
theorem single_hybrid_8_formula_16 : single_hybrid_8_costFormula 16 = 72 ∧ single_hybrid_8_conditionalFormula 16 = 72 := by decide +kernel
theorem single_hybrid_8_formula_32 : single_hybrid_8_costFormula 32 = 176 ∧ single_hybrid_8_conditionalFormula 32 = 176 := by decide +kernel
theorem single_hybrid_8_formula_64 : single_hybrid_8_costFormula 64 = 416 ∧ single_hybrid_8_conditionalFormula 64 = 416 := by decide +kernel
theorem single_hybrid_8_formula_128 : single_hybrid_8_costFormula 128 = 960 ∧ single_hybrid_8_conditionalFormula 128 = 960 := by decide +kernel
#print axioms single_hybrid_8_certificate
#print axioms single_hybrid_8_correct
#print axioms single_hybrid_8_cost
#print axioms single_hybrid_8_conditional
#print axioms single_hybrid_8_operational
#print axioms single_hybrid_8_quadratic
#print axioms single_hybrid_8_nlog
theorem single_hybrid_16_certificate : Certificate single_hybrid_16 := single_hybrid_16.certify
theorem single_hybrid_16_correct {α : Type} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs (single_hybrid_16_algorithm xs) := single_hybrid_16.run_spec xs
theorem single_hybrid_16_cost {α : Type} [LinearOrder α] (xs : List α) : (single_hybrid_16.eval xs).time ≤ single_hybrid_16_costFormula xs.length := single_hybrid_16.cost_le_upper xs
theorem single_hybrid_16_conditional {α : Type} [LinearOrder α] (xs : List α) (h : single_hybrid_16.Ready xs) : (single_hybrid_16.eval xs).time ≤ single_hybrid_16_conditionalFormula xs.length := single_hybrid_16.cost_le_readyUpper xs h
theorem single_hybrid_16_operational {α : Type} [LinearOrder α] (xs : List α) : Comparison.Executes (single_hybrid_16.program xs) (single_hybrid_16_algorithm xs) (single_hybrid_16.eval xs).time := single_hybrid_16.operational_certificate xs
theorem single_hybrid_16_quadratic {α : Type} [LinearOrder α] : (fun xs : List α => ((single_hybrid_16.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := single_hybrid_16.cost_isBigO_of_upper _ single_hybrid_16.upper_isBigO_quadratic
theorem single_hybrid_16_nlog {α : Type} [LinearOrder α] : (fun xs : List α => ((single_hybrid_16.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := single_hybrid_16.cost_isBigO_of_upper _ (single_hybrid_16.upper_isBigO_nlog 17 rfl)
theorem single_hybrid_16_formula_0 : single_hybrid_16_costFormula 0 = 0 ∧ single_hybrid_16_conditionalFormula 0 = 0 := by decide +kernel
theorem single_hybrid_16_formula_1 : single_hybrid_16_costFormula 1 = 0 ∧ single_hybrid_16_conditionalFormula 1 = 0 := by decide +kernel
theorem single_hybrid_16_formula_8 : single_hybrid_16_costFormula 8 = 28 ∧ single_hybrid_16_conditionalFormula 8 = 28 := by decide +kernel
theorem single_hybrid_16_formula_16 : single_hybrid_16_costFormula 16 = 120 ∧ single_hybrid_16_conditionalFormula 16 = 120 := by decide +kernel
theorem single_hybrid_16_formula_32 : single_hybrid_16_costFormula 32 = 272 ∧ single_hybrid_16_conditionalFormula 32 = 272 := by decide +kernel
theorem single_hybrid_16_formula_64 : single_hybrid_16_costFormula 64 = 608 ∧ single_hybrid_16_conditionalFormula 64 = 608 := by decide +kernel
theorem single_hybrid_16_formula_128 : single_hybrid_16_costFormula 128 = 1344 ∧ single_hybrid_16_conditionalFormula 128 = 1344 := by decide +kernel
#print axioms single_hybrid_16_certificate
#print axioms single_hybrid_16_correct
#print axioms single_hybrid_16_cost
#print axioms single_hybrid_16_conditional
#print axioms single_hybrid_16_operational
#print axioms single_hybrid_16_quadratic
#print axioms single_hybrid_16_nlog
#print axioms LeanSort.CostedPlan.Examples.twoInsertion_smaller_envelope
#print axioms LeanSort.CostedPlan.Examples.twoGuarded_smaller_envelope
#print axioms LeanSort.CostedPlan.Examples.smaller_envelope_but_more_operations
end CostPlanGenerated
