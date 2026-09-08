import LeanSort.Verification.LearnedSelection.Correctness

namespace LeanSort.LearnedSelection
open Comparison Direct

section Naturality
variable {m n : Type → Type} [Monad m] [Monad n]
variable (f : Morphism m n) (cmp : Compare m Nat) (cmp' : Compare n Nat)
variable (hc : ∀ phase x y, f.app (cmp phase x y) = cmp' phase x y)
include hc

theorem map_step (s : SampleState) (p : Nat × Nat) :
    f.app (FeatureEngine.step cmp s p) = FeatureEngine.step cmp' s p := by
  simp only [FeatureEngine.step, f.bind_eq, hc, f.pure_eq]

theorem map_fold (s : SampleState) (pairs : List (Nat × Nat)) :
    f.app (FeatureEngine.fold cmp s pairs) = FeatureEngine.fold cmp' s pairs := by
  induction pairs generalizing s with
  | nil => exact f.pure_eq s
  | cons p ps ih => simp [FeatureEngine.fold, f.bind_eq, map_step f cmp cmp' hc, ih]

theorem map_extract (xs : List Nat) :
    f.app (FeatureEngine.extract cmp xs) = FeatureEngine.extract cmp' xs := by
  simp [FeatureEngine.extract, f.bind_eq, f.pure_eq, map_fold f cmp cmp' hc]

end Naturality

theorem feature_counted_refines (xs : List Nat) :
    countedFeatures xs = (featureProgram xs).eval := by
  simpa only [countedFeatures, featureProgram, evalMorphism] using
    (map_extract evalMorphism symbolicCompare countedCompare eval_compare xs).symm

theorem feature_plain_refines (xs : List Nat) :
    features xs = (featureProgram xs).eval.ret := by
  simpa only [features, featureProgram, plainMorphism] using
    (map_extract plainMorphism symbolicCompare plainCompare plain_compare xs).symm

theorem features_agree (xs : List Nat) : features xs = (countedFeatures xs).ret := by
  rw [feature_plain_refines, feature_counted_refines]

/-- The whole sampled-selector comparison program includes ALL feature probes
before the selected kernel. Model comparisons are on derived metadata, not keys. -/
def selectionProgram (choose : List Nat → Option Int) (xs : List Nat) : Program Nat (List Nat) :=
  (featureProgram xs).bind fun fs => (candidate (resolve (choose fs))).program xs

def totalKeyCost (choose : List Nat → Option Int) (xs : List Nat) : Nat :=
  (countedFeatures xs).time + kernelCost (choose (features xs)) xs

theorem selection_eval (choose : List Nat → Option Int) (xs : List Nat) :
    (selectionProgram choose xs).eval =
      ⟨dispatch (choose (features xs)) xs, totalKeyCost choose xs⟩ := by
  simp only [selectionProgram, Program.eval_bind, totalKeyCost, dispatch, kernelCost,
    feature_counted_refines, feature_plain_refines, Direct.run_counted_eq,
    Direct.run_eq, RunAdaptive.Strategy.run]

theorem selection_execution (choose : List Nat → Option Int) (xs : List Nat) :
    Executes (selectionProgram choose xs) (dispatch (choose (features xs)) xs)
      (totalKeyCost choose xs) := by
  have h := Program.eval_executes (selectionProgram choose xs)
  rw [selection_eval] at h
  exact h

/-- A full key-comparison bound that explicitly includes the instrumented
feature cost. NOT a wall-clock, metadata-comparison or traversal-cost bound. -/
theorem selection_bound (choose : List Nat → Option Int) (xs : List Nat) :
    totalKeyCost choose xs ≤ (countedFeatures xs).time + kernelBound (choose (features xs)) xs :=
  Nat.add_le_add_left (kernel_bound _ _) _

theorem feature_step_cost (s : SampleState) (p : Nat × Nat) :
    (FeatureEngine.step countedCompare s p).time = 5 := rfl

theorem feature_fold_cost (s : SampleState) (pairs : List (Nat × Nat)) :
    (FeatureEngine.fold countedCompare s pairs).time = 5 * pairs.length := by
  induction pairs generalizing s with
  | nil => rfl
  | cons p ps ih => simp [FeatureEngine.fold, feature_step_cost, ih, Nat.mul_add, Nat.add_comm]

theorem feature_cost (xs : List Nat) :
    (countedFeatures xs).time = 5 * (probePairs xs (probePositions xs.length)).length := by
  simp [countedFeatures, FeatureEngine.extract, feature_fold_cost]

theorem probePairs_length_le (xs : List Nat) (positions : List Nat) (start : Nat) :
    (probePairs xs positions start).length ≤ positions.length := by
  induction positions generalizing xs start with
  | nil => simp [probePairs]
  | cons p ps ih =>
    simp only [probePairs]
    split <;> simp_all only [List.length_cons, List.length_nil, Nat.succ_le_succ_iff, Nat.zero_le]

theorem feature_cost_le (xs : List Nat) : (countedFeatures xs).time ≤ 80 := by
  rw [feature_cost]
  have h := probePairs_length_le xs (probePositions xs.length) 0
  have hp : (probePositions xs.length).length ≤ 16 := by simp [probePositions]
  omega

theorem selection_bound_80 (choose : List Nat → Option Int) (xs : List Nat) :
    totalKeyCost choose xs ≤ 80 + kernelBound (choose (features xs)) xs :=
  (selection_bound choose xs).trans (Nat.add_le_add_right (feature_cost_le xs) _)

end LeanSort.LearnedSelection
