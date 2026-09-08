import LeanSort.Verification.CostedPlan.Complexity

namespace LeanSort.CostedPlan
open Filter Asymptotics

/-- A sufficient rule: all active leaves are successful sorted-block guards.
The fallback is irrelevant only under the explicitly stated `Ready` condition. -/
def Schema.readyDepth : Schema → Option Nat
  | .leaf _ => none
  | .guardSorted _ => some 0
  | .split _ l r => do return max (← l.readyDepth) (← r.readyDepth) + 1

theorem Schema.readyUpper_le_depth (p : Schema) (n d : Nat) (cert : p.readyDepth = some d) :
    p.readyUpper n ≤ n * (d + 1) := by
  induction p generalizing n d with
  | leaf c => simp [Schema.readyDepth] at cert
  | guardSorted fallback ih =>
    simp only [Schema.readyDepth, Option.some.injEq] at cert
    subst d
    simp [Schema.readyUpper]
  | split cut left right ihl ihr =>
    cases hl : left.readyDepth with
    | none => simp [Schema.readyDepth, hl] at cert
    | some dl =>
      cases hr : right.readyDepth with
      | none => simp [Schema.readyDepth, hl, hr] at cert
      | some dr =>
        simp [Schema.readyDepth, hl, hr] at cert
        subst d
        have hleft := ihl (cut.position n) dl hl
        have hright := ihr (n - cut.position n) dr hr
        have ha := Nat.mul_le_mul_left (cut.position n)
          (Nat.succ_le_succ (Nat.le_max_left dl dr))
        have hb := Nat.mul_le_mul_left (n - cut.position n)
          (Nat.succ_le_succ (Nat.le_max_right dl dr))
        have hc := cut.position_le n
        have hsum : cut.position n + (n - cut.position n) = n := by omega
        simp only [Schema.readyUpper]
        have hparts := Nat.add_le_add (hleft.trans ha) (hright.trans hb)
        simp only [Nat.succ_eq_add_one] at hparts
        rw [← Nat.add_mul, hsum] at hparts
        nlinarith

theorem Schema.ready_cost_le_depth {α : Type} [LinearOrder α] (p : Schema) (xs : List α)
    (ready : p.Ready xs) (d : Nat) (cert : p.readyDepth = some d) :
    (p.eval xs).time ≤ xs.length * (d + 1) :=
  (p.cost_le_readyUpper xs ready).trans (p.readyUpper_le_depth xs.length d cert)

/-- Fixed plan depth gives a linear conditional bound. The concrete theorem above
still exposes the depth factor if a family of plans grows with input length. -/
theorem Schema.ready_cost_isBigO_linear {α : Type} [LinearOrder α]
    (p : Schema) (d : Nat) (cert : p.readyDepth = some d) :
    (fun xs : {xs : List α // p.Ready xs} => ((p.eval xs.val).time : ℝ)) =O[
      Filter.comap (fun xs : {xs : List α // p.Ready xs} => xs.val.length) atTop]
      (fun xs : {xs : List α // p.Ready xs} => (xs.val.length : ℝ)) := by
  apply IsBigO.of_bound ((d + 1 : Nat) : ℝ)
  filter_upwards with xs
  simp only [Real.norm_natCast]
  have h := p.ready_cost_le_depth xs.val xs.property d cert
  exact_mod_cast (by simpa only [Nat.mul_comm] using h)

theorem Schema.ready_of_sorted {α : Type} [LinearOrder α] (p : Schema) (xs : List α)
    (sorted : xs.Pairwise (· ≤ ·)) : p.Ready xs := by
  induction p generalizing xs with
  | leaf c => trivial
  | guardSorted p ih => exact sorted
  | split cut l r ihl ihr =>
    exact ⟨ihl _ (sorted.sublist (List.take_sublist _ _)),
      ihr _ (sorted.sublist (List.drop_sublist _ _))⟩

end LeanSort.CostedPlan
