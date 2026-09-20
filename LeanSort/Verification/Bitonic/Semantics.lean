import LeanSort.Verification.Bitonic.Trace

namespace LeanSort.Bitonic

/-- Relational semantics of the sequential comparator machine. -/
inductive Executes {α : Type*} [LinearOrder α] :
    List Comparator → Array (Option α) → Array (Option α) → Prop
  | nil (xs) : Executes [] xs xs
  | cons (c : Comparator) (steps) (xs ys)
      (rest : Executes steps (compareExchange c.ascending c.first c.second xs) ys) :
      Executes (c :: steps) xs ys

variable {α : Type*} [LinearOrder α]

theorem executes_iff (steps : List Comparator) (xs ys : Array (Option α)) :
    Executes steps xs ys ↔ runSchedule steps xs = ys := by
  constructor
  · intro h
    induction h with
    | nil => rfl
    | cons c steps xs ys rest ih => exact ih
  · intro h
    subst ys
    induction steps generalizing xs with
    | nil => exact .nil _
    | cons c steps ih => exact .cons c steps xs _ (ih _)

theorem executes_deterministic (steps : List Comparator) (xs ys zs : Array (Option α))
    (hy : Executes steps xs ys) (hz : Executes steps xs zs) : ys = zs :=
  ((executes_iff _ _ _).mp hy).symm.trans ((executes_iff _ _ _).mp hz)

theorem sortNetwork_executes (depth start : Nat) (ascending : Bool)
    (xs : Array (Option α)) :
    Executes (sortSchedule depth start ascending) xs (sortNetwork depth start ascending xs) :=
  (executes_iff _ _ _).mpr (run_sortSchedule _ _ _ _)

theorem executes_perm (steps : List Comparator) (xs ys : Array (Option α))
    (h : Executes steps xs ys) : ys.toList.Perm xs.toList := by
  induction h with
  | nil => exact .refl _
  | cons c steps xs ys rest ih => exact ih.trans (compareExchange_perm _ _ _ _)

end LeanSort.Bitonic
