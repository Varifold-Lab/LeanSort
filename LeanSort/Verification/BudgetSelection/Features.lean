import LeanSort.Algorithm.BudgetSelection.Features
import LeanSort.Verification.LearnedSelection.Features

namespace LeanSort.BudgetSelection
open Comparison Direct LearnedSelection

section Naturality
variable {m n : Type → Type} [Monad m] [Monad n]
variable (f : Morphism m n) (cmp : Compare m Nat) (cmp' : Compare n Nat)
variable (hc : ∀ phase x y, f.app (cmp phase x y) = cmp' phase x y)
include hc

theorem map_fold (seen desc : Nat) (ps : List (Nat × Nat)) :
    f.app (Engine.fold cmp seen desc ps) = Engine.fold cmp' seen desc ps := by
  induction ps generalizing seen desc with
  | nil => exact f.pure_eq _
  | cons p ps ih => simp [Engine.fold, f.bind_eq, hc, ih]

theorem map_extract (budget : Nat) (xs : List Nat) :
    f.app (Engine.extract cmp budget xs) = Engine.extract cmp' budget xs := by
  simp [Engine.extract, f.bind_eq, f.pure_eq, map_fold f cmp cmp' hc]

theorem map_feature (kind : FeatureSet) (xs : List Nat) :
    f.app (Engine.feature cmp kind xs) = Engine.feature cmp' kind xs := by
  cases kind <;> simp only [Engine.feature]
  all_goals first | exact map_extract f cmp cmp' hc _ _ | exact LearnedSelection.map_extract f cmp cmp' hc _
end Naturality

theorem counted_refines (kind : FeatureSet) (xs : List Nat) :
    counted kind xs = (symbolic kind xs).eval := by
  simpa only [counted, symbolic, evalMorphism] using
    (map_feature evalMorphism symbolicCompare countedCompare eval_compare kind xs).symm

theorem plain_refines (kind : FeatureSet) (xs : List Nat) :
    features kind xs = (symbolic kind xs).eval.ret := by
  simpa only [features, symbolic, plainMorphism] using
    (map_feature plainMorphism symbolicCompare plainCompare plain_compare kind xs).symm

theorem features_agree (kind : FeatureSet) (xs : List Nat) :
    features kind xs = (counted kind xs).ret := by rw [plain_refines, counted_refines]

theorem fold_cost (seen desc : Nat) (ps : List (Nat × Nat)) :
    (Engine.fold countedCompare seen desc ps).time = ps.length := by
  induction ps generalizing seen desc with
  | nil => rfl
  | cons p ps ih => simp [Engine.fold, countedCompare, ih, Nat.add_comm]

theorem extract_cost (budget : Nat) (xs : List Nat) :
    (Engine.extract countedCompare budget xs).time = (probePairs xs (positions budget xs.length)).length := by
  simp [Engine.extract, fold_cost]

theorem extract_bound (budget : Nat) (xs : List Nat) :
    (Engine.extract countedCompare budget xs).time ≤ budget := by
  rw [extract_cost]
  have h := probePairs_length_le xs (positions budget xs.length) 0
  have hp : (positions budget xs.length).length ≤ budget := by simp [positions]
  omega

theorem feature_bound (kind : FeatureSet) (xs : List Nat) :
    (counted kind xs).time ≤ kind.budget := by
  cases kind <;> simp only [counted, Engine.feature]
  all_goals first | exact extract_bound _ _ | exact LearnedSelection.feature_cost_le xs

theorem length_cost (xs : List Nat) : (counted .length xs).time = 0 := by
  have h := feature_bound .length xs
  simpa [FeatureSet.budget] using h

theorem legacy_eq (xs : List Nat) : features .legacy xs = LearnedSelection.features xs := rfl

def selectionProgram (kind : FeatureSet) (decision : List Nat → Option Int) (xs : List Nat) : Program Nat (List Nat) :=
  (symbolic kind xs).bind fun fs => (candidate (resolve (decision fs))).program xs

def keyCost (kind : FeatureSet) (decision : List Nat → Option Int) (xs : List Nat) : Nat :=
  (counted kind xs).time + kernelCost (decision (features kind xs)) xs

theorem selection_eval (kind : FeatureSet) (decision : List Nat → Option Int) (xs : List Nat) :
    (selectionProgram kind decision xs).eval =
      ⟨dispatch (decision (features kind xs)) xs, keyCost kind decision xs⟩ := by
  simp only [selectionProgram, Program.eval_bind, keyCost, dispatch, kernelCost,
    counted_refines, plain_refines, Direct.run_counted_eq, Direct.run_eq, RunAdaptive.Strategy.run]

theorem selection_execution (kind : FeatureSet) (decision : List Nat → Option Int) (xs : List Nat) :
    Executes (selectionProgram kind decision xs) (dispatch (decision (features kind xs)) xs)
      (keyCost kind decision xs) := by
  have h := Program.eval_executes (selectionProgram kind decision xs)
  rw [selection_eval] at h
  exact h

theorem selection_bound (kind : FeatureSet) (decision : List Nat → Option Int) (xs : List Nat) :
    keyCost kind decision xs ≤ kind.budget + kernelBound (decision (features kind xs)) xs :=
  Nat.add_le_add (feature_bound _ _) (kernel_bound _ _)

theorem run_correct (p : Policy) (xs : List Nat) :
    IsSortingResult (· ≤ ·) xs (run p xs) := dispatch_correct _ _

end LeanSort.BudgetSelection
