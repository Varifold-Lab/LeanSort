import LeanSort.Algorithm.Direct.Phases
import LeanSort.Verification.Direct.Checks

namespace LeanSort.Direct
open Comparison RunAdaptive

def phaseMorphism {α : Type} [LinearOrder α] (phase : Phase) : Morphism (Program α) Result where
  app p := ⟨p.eval.ret, p.count phase⟩
  pure_eq _ := rfl
  bind_eq p k := by
    change (⟨(p.bind k).eval.ret, (p.bind k).count phase⟩ : Result _) = _
    simp only [Program.eval_bind, Program.count_bind]
    rfl

theorem phase_compare {α : Type} [LinearOrder α] (selected phase : Phase) (x y : α) :
    (phaseMorphism selected).app (symbolicCompare phase x y) = phaseCompare selected phase x y := by
  simp [phaseMorphism, symbolicCompare, phaseCompare, Program.eval, Program.count, eq_comm]

theorem phase_count_eq {α : Type} [LinearOrder α] (phase : Phase) (s : Strategy) (xs : List α) :
    runPhase phase s xs = ⟨(s.program xs).eval.ret, (s.program xs).count phase⟩ := by
  simpa only [phaseMorphism, symbolic_strategy, runPhase] using
    (Morphism.strategy (phaseMorphism phase) symbolicCompare (phaseCompare phase) (phase_compare phase) s xs).symm

theorem phase_partition {α : Type} [LinearOrder α] (s : Strategy) (xs : List α) :
    (runPhase .check s xs).time + (runPhase .sort s xs).time = (runCounted s xs).time := by
  simp only [phase_count_eq, run_counted_eq]
  exact Program.count_partition _

end LeanSort.Direct

