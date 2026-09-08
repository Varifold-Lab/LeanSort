import LeanSort.Algorithm.Direct.Executor
import LeanSort.Verification.Comparison.Semantics

namespace LeanSort.Direct
open Comparison RunAdaptive

/-- A proved interpretation of the SAME control flow. These laws are discharged
for concrete interpreters below, not assumed for deployed algorithms. -/
structure Morphism (m n : Type → Type) [Monad m] [Monad n] where
  app : {β : Type} → m β → n β
  pure_eq : ∀ {β : Type} (b : β), app (pure b) = pure b
  bind_eq : ∀ {β γ : Type} (p : m β) (k : β → m γ),
    app (p >>= k) = (app p >>= fun b => app (k b))

namespace Morphism
variable {m n : Type → Type} [Monad m] [Monad n] {α : Type}
variable (f : Morphism m n) (cmp : Compare m α) (cmp' : Compare n α)
variable (hc : ∀ phase x y, f.app (cmp phase x y) = cmp' phase x y)
include hc

theorem scanTail (x : α) (xs : List α) :
    f.app (Engine.scanTail cmp x xs) = Engine.scanTail cmp' x xs := by
  induction xs generalizing x <;> simp [apply_ite, Engine.scanTail, f.bind_eq, f.pure_eq, *]

theorem discover (xs : List α) :
    f.app (Engine.discover cmp xs) = Engine.discover cmp' xs := by
  cases xs <;> simp [Engine.discover, f.bind_eq, f.pure_eq, f.scanTail cmp cmp' hc]

theorem merge (xs ys : List α) :
    f.app (Engine.merge cmp xs ys) = Engine.merge cmp' xs ys := by
  cases xs with
  | nil => simp [Engine.merge, f.pure_eq]
  | cons x xs =>
    cases ys with
    | nil => simp [Engine.merge, f.pure_eq]
    | cons y ys =>
      simp only [Engine.merge, f.bind_eq, hc]
      congr 1
      funext b
      cases b <;> simp [f.bind_eq, f.pure_eq,
        merge xs (y :: ys), merge (x :: xs) ys]
termination_by xs.length + ys.length

theorem insert (x : α) (xs : List α) :
    f.app (Engine.insert cmp x xs) = Engine.insert cmp' x xs := by
  induction xs <;> simp [apply_ite, Engine.insert, f.bind_eq, f.pure_eq, *]

theorem insertion (xs : List α) :
    f.app (Engine.insertion cmp xs) = Engine.insertion cmp' xs := by
  induction xs <;> simp [Engine.insertion, f.bind_eq, f.pure_eq, f.insert cmp cmp' hc, *]

theorem mergeSort (xs : List α) :
    f.app (Engine.mergeSort cmp xs) = Engine.mergeSort cmp' xs := by
  conv_lhs => rw [Engine.mergeSort.eq_def]
  conv_rhs => rw [Engine.mergeSort.eq_def]
  split_ifs with h
  · exact f.pure_eq xs
  · simp only [f.bind_eq, mergeSort (xs.take (xs.length / 2)),
      mergeSort (xs.drop (xs.length / 2)), f.merge cmp cmp' hc]
termination_by xs.length
decreasing_by all_goals simp_wf; omega

theorem hybrid (t : Nat) (xs : List α) :
    f.app (Engine.hybrid cmp t xs) = Engine.hybrid cmp' t xs := by
  conv_lhs => rw [Engine.hybrid.eq_def]
  conv_rhs => rw [Engine.hybrid.eq_def]
  split_ifs with h
  · exact f.insertion cmp cmp' hc xs
  · simp only [f.bind_eq, hybrid t (xs.take (xs.length / 2)),
      hybrid t (xs.drop (xs.length / 2)), f.merge cmp cmp' hc]
termination_by xs.length
decreasing_by all_goals simp_wf; omega

theorem checkSorted (xs : List α) :
    f.app (Engine.checkSorted cmp xs) = Engine.checkSorted cmp' xs := by
  match xs with
  | [] => exact f.pure_eq _
  | [_] => exact f.pure_eq _
  | x :: y :: ys =>
    simp [apply_ite, Engine.checkSorted, f.bind_eq, f.pure_eq, hc, checkSorted (y :: ys)]

theorem component (c : CostedPlan.Component) (xs : List α) :
    f.app (Engine.component cmp c xs) = Engine.component cmp' c xs := by
  cases c <;> simp [Engine.component, f.mergeSort cmp cmp' hc, f.insertion cmp cmp' hc,
    f.hybrid cmp cmp' hc]

theorem schema (p : CostedPlan.Schema) (xs : List α) :
    f.app (Engine.schema cmp p xs) = Engine.schema cmp' p xs := by
  induction p generalizing xs <;> simp [apply_ite, Engine.schema, f.bind_eq, f.pure_eq,
    f.component cmp cmp' hc, f.merge cmp cmp' hc, f.checkSorted cmp cmp' hc, *]

theorem tree (t : MergeTree α) :
    f.app (Engine.tree cmp t) = Engine.tree cmp' t := by
  induction t <;> simp [Engine.tree, f.bind_eq, f.pure_eq, f.merge cmp cmp' hc, *]

theorem adaptive (planner : List (List α) → MergeTree α) (xs : List α) :
    f.app (Engine.adaptive cmp planner xs) = Engine.adaptive cmp' planner xs := by
  simp [Engine.adaptive, f.bind_eq, f.discover cmp cmp' hc, f.tree cmp cmp' hc]

theorem strategy (s : Strategy) (xs : List α) :
    f.app (Engine.strategy cmp s xs) = Engine.strategy cmp' s xs := by
  cases s <;> simp [Engine.strategy, f.schema cmp cmp' hc, f.adaptive cmp cmp' hc]

end Morphism

def evalMorphism {α : Type} [LinearOrder α] : Morphism (Program α) Result where
  app := Program.eval
  pure_eq _ := rfl
  bind_eq p k := Program.eval_bind p k

def plainMorphism {α : Type} [LinearOrder α] : Morphism (Program α) Id where
  app p := p.eval.ret
  pure_eq _ := rfl
  bind_eq p k := by simp [Program.eval_bind, bind]

theorem eval_compare {α : Type} [LinearOrder α] (phase : Phase) (x y : α) :
    evalMorphism.app (symbolicCompare phase x y) = countedCompare phase x y := rfl

theorem plain_compare {α : Type} [LinearOrder α] (phase : Phase) (x y : α) :
    plainMorphism.app (symbolicCompare phase x y) = plainCompare phase x y := rfl

end LeanSort.Direct


