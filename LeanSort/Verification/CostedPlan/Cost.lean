import LeanSort.Verification.CostedPlan.Correctness

namespace LeanSort.CostedPlan
open Comparison

theorem Component.cost_le_upper {α : Type} [LinearOrder α] (c : Component) (xs : List α) :
    (c.program xs).eval.time ≤ c.upper xs.length := by
  cases c with
  | merge => exact ComparisonSort.mergeSort_cost_le xs
  | insertion => exact ComparisonSort.insertion_cost_le xs
  | hybrid t => exact ComparisonSort.hybrid_cost_le t xs

/-- Structural composition of cost certificates. Splitting costs zero key
comparisons; its List traversal/allocation is explicitly outside this metric. -/
theorem Schema.cost_le_upper {α : Type} [LinearOrder α] (p : Schema) (xs : List α) :
    (p.eval xs).time ≤ p.upper xs.length := by
  induction p generalizing xs with
  | leaf c => exact c.cost_le_upper xs
  | split cut left right ihl ihr =>
    have hl := ihl (xs.take (cut.position xs.length))
    have hr := ihr (xs.drop (cut.position xs.length))
    have hm := ComparisonSort.merge_cost_le
      (left.eval (xs.take (cut.position xs.length))).ret
      (right.eval (xs.drop (cut.position xs.length))).ret
    have hc := cut.position_le xs.length
    simp only [Schema.eval_length, List.length_take, List.length_drop,
      Nat.min_eq_left hc] at hl hr hm
    simp only [Schema.eval, Schema.program, Program.eval_bind, Schema.upper]
    simp only [Schema.eval] at hl hr hm
    omega
  | guardSorted fallback ih =>
    have hc := ComparisonSort.checkSorted_cost_le xs
    have hf := ih xs
    simp only [Schema.eval] at hf
    simp only [Schema.eval, Schema.program, Program.eval_bind, Schema.upper]
    cases h : (ComparisonSort.checkSorted xs).eval.ret <;>
      simp only [Bool.false_eq_true, ↓reduceIte, Program.eval] <;>
      change _ ≤ _ <;> omega

/-- Conditional cost includes every successful runtime guard; it does not assume
the caller supplied free evidence of sorted blocks. -/
theorem Schema.cost_le_readyUpper {α : Type} [LinearOrder α] (p : Schema) (xs : List α)
    (ready : p.Ready xs) : (p.eval xs).time ≤ p.readyUpper xs.length := by
  induction p generalizing xs with
  | leaf c => exact c.cost_le_upper xs
  | split cut left right ihl ihr =>
    have hl := ihl (xs.take (cut.position xs.length)) ready.1
    have hr := ihr (xs.drop (cut.position xs.length)) ready.2
    have hm := ComparisonSort.merge_cost_le
      (left.eval (xs.take (cut.position xs.length))).ret
      (right.eval (xs.drop (cut.position xs.length))).ret
    have hc := cut.position_le xs.length
    simp only [Schema.eval_length, List.length_take, List.length_drop,
      Nat.min_eq_left hc] at hl hr hm
    simp only [Schema.eval, Schema.program, Program.eval_bind, Schema.readyUpper]
    simp only [Schema.eval] at hl hr hm
    omega
  | guardSorted fallback ih =>
    have hs := (ComparisonSort.checkSorted_spec xs).mpr ready
    simpa only [Schema.eval, Schema.program, Program.eval_bind, hs, ↓reduceIte,
      Program.eval, Nat.add_zero, Schema.readyUpper] using ComparisonSort.checkSorted_cost_le xs

/-- Each catalogue entry carries propositions and Lean proofs, not status labels. -/
structure Certificate (p : Schema) : Prop where
  correct : ∀ {α : Type} [LinearOrder α] (xs : List α), IsSortingResult (· ≤ ·) xs (p.run xs)
  execution : ∀ {α : Type} [LinearOrder α] (xs : List α),
    Executes (p.program xs) (p.run xs) (p.eval xs).time
  bound : ∀ {α : Type} [LinearOrder α] (xs : List α), (p.eval xs).time ≤ p.upper xs.length
  conditional : ∀ {α : Type} [LinearOrder α] (xs : List α),
    p.Ready xs → (p.eval xs).time ≤ p.readyUpper xs.length

theorem Schema.certify (p : Schema) : Certificate p where
  correct := p.run_spec
  execution := p.operational_certificate
  bound := p.cost_le_upper
  conditional := p.cost_le_readyUpper

end LeanSort.CostedPlan
