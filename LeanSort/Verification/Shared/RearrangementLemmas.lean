import LeanSort.Model.Rearrangement

/-! Reusable lemmas for replay and elementary rearrangement moves. -/

namespace LeanSort.Rearrangement

@[simp] theorem replay_nil {State Move : Type*} (apply : Move → State → State)
    (start : State) : replay apply [] start = start := rfl

@[simp] theorem replay_cons {State Move : Type*} (apply : Move → State → State)
    (move : Move) (word : List Move) (start : State) :
    replay apply (move :: word) start = replay apply word (apply move start) := rfl

theorem replay_append {State Move : Type*} (apply : Move → State → State)
    (first second : List Move) (start : State) :
    replay apply (first ++ second) start =
      replay apply second (replay apply first start) := by
  simp [replay, List.foldl_append]

namespace AdjacentTransposition

theorem apply_prefix {α : Type*} (p : List α) (x y : α) (ys : List α) :
    apply p.length (p ++ x :: y :: ys) = p ++ y :: x :: ys := by
  simp only [apply, Transposition.apply]
  induction p with
  | nil => rfl
  | cons z p ih =>
      change z :: (p ++ x :: y :: ys).swap p.length (p.length + 1) =
        z :: (p ++ y :: x :: ys)
      rw [ih]

end AdjacentTransposition

end LeanSort.Rearrangement
