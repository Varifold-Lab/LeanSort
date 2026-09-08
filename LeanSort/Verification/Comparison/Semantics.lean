import LeanSort.Semantics.Comparison

namespace LeanSort.Comparison

theorem Program.eval_bind {α β γ : Type} [LinearOrder α]
    (p : Program α β) (f : β → Program α γ) :
    (p.bind f).eval =
      ⟨(f p.eval.ret).eval.ret, p.eval.time + (f p.eval.ret).eval.time⟩ := by
  induction p with
  | pure x => simp [Program.bind, Program.eval]
  | compare phase x y next ih =>
    simp [Program.bind, Program.eval, ih, Nat.add_assoc, Nat.add_comm]

theorem Program.eval_executes {α β : Type} [LinearOrder α] (p : Program α β) :
    Executes p p.eval.ret p.eval.time := by
  induction p with
  | pure x => exact .pure x
  | compare phase x y next ih => exact .compare phase x y next _ _ (ih _)

theorem Executes.eval_eq {α β : Type} [LinearOrder α] {p : Program α β} {out : β} {cost : Nat}
    (h : Executes p out cost) : p.eval = ⟨out, cost⟩ := by
  induction h with
  | pure x => rfl
  | compare phase x y next out cost h ih => simp [Program.eval, ih]

theorem Program.count_partition {α β : Type} [LinearOrder α] (p : Program α β) :
    p.count .check + p.count .sort = p.eval.time := by
  induction p with
  | pure x => rfl
  | compare phase x y next ih =>
    cases phase <;> simp [Program.count, Program.eval, ih, Nat.add_assoc, Nat.add_comm,
      Nat.add_left_comm]

end LeanSort.Comparison
