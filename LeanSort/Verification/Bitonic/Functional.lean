import LeanSort.Verification.Bitonic.Trace
import Mathlib.Order.Hom.Basic

namespace LeanSort.Bitonic.Functional

def low {α : Type*} [LinearOrder α] (ascending : Bool) (x y : α) : α :=
  if ascending then min x y else max x y

def high {α : Type*} [LinearOrder α] (ascending : Bool) (x y : α) : α :=
  if ascending then max x y else min x y

def step {α : Type*} [LinearOrder α] (c : Comparator) (v : Nat → α) (k : Nat) : α :=
  if k = c.first then low c.ascending (v c.first) (v c.second)
  else if k = c.second then high c.ascending (v c.first) (v c.second)
  else v k

def run {α : Type*} [LinearOrder α] (cs : List Comparator) (v : Nat → α) : Nat → α :=
  cs.foldl (fun w c => step c w) v

variable {α β : Type*} [LinearOrder α] [LinearOrder β]

@[simp] theorem run_nil (v : Nat → α) : run [] v = v := rfl
@[simp] theorem run_cons (c : Comparator) (cs : List Comparator) (v : Nat → α) :
    run (c :: cs) v = run cs (step c v) := rfl
@[simp] theorem run_append (cs ds : List Comparator) (v : Nat → α) :
    run (cs ++ ds) v = run ds (run cs v) := by simp [run, List.foldl_append]

theorem run_frame (cs : List Comparator) (v : Nat → α) (k : Nat)
    (h : ∀ c ∈ cs, k ≠ c.first ∧ k ≠ c.second) : run cs v k = v k := by
  induction cs generalizing v with
  | nil => rfl
  | cons c cs ih =>
    rw [run_cons, ih _ (fun d hd => h d (by simp [hd]))]
    have hc := h c (by simp)
    simp [step, hc.1, hc.2]

/-- A network with endpoints in `I` preserves any predicate holding throughout `I`. -/
theorem run_property (cs : List Comparator) (v : Nat → α)
    (I : Nat → Prop) (P : α → Prop)
    (hc : ∀ c ∈ cs, I c.first ∧ I c.second)
    (hv : ∀ k, I k → P (v k)) : ∀ k, I k → P (run cs v k) := by
  induction cs generalizing v with
  | nil => exact hv
  | cons c cs ih =>
    apply ih _ (fun d hd => hc d (by simp [hd]))
    intro k hk
    have hfirst := hv c.first (hc c (by simp)).1
    have hsecond := hv c.second (hc c (by simp)).2
    simp only [step, low, high]
    split <;> (try split) <;> (try split) <;>
      first | exact hv k hk | exact hfirst | exact hsecond |
        (rcases le_total (v c.first) (v c.second) with h | h <;>
          simp_all)

theorem step_map (f : α → β) (hf : Monotone f) (c : Comparator) (v : Nat → α) :
    step c (f ∘ v) = f ∘ step c v := by
  funext k
  have hm : f (min (v c.first) (v c.second)) = min (f (v c.first)) (f (v c.second)) := by
    rcases le_total (v c.first) (v c.second) with h | h
    · simp [min_eq_left h, min_eq_left (hf h)]
    · simp [min_eq_right h, min_eq_right (hf h)]
  have hx : f (max (v c.first) (v c.second)) = max (f (v c.first)) (f (v c.second)) := by
    rcases le_total (v c.first) (v c.second) with h | h
    · simp [max_eq_right h, max_eq_right (hf h)]
    · simp [max_eq_left h, max_eq_left (hf h)]
  simp only [step, low, high, Function.comp_apply]
  split <;> (try split) <;> (try split) <;>
    simp [hm, hx]

theorem run_map (f : α → β) (hf : Monotone f) (cs : List Comparator) (v : Nat → α) :
    run cs (f ∘ v) = f ∘ run cs v := by
  induction cs generalizing v with
  | nil => rfl
  | cons c cs ih => rw [run_cons, step_map f hf, ih]; rfl

def layer (n start half : Nat) (ascending : Bool) : List Comparator :=
  (List.range n).map (fun i => ⟨ascending, start + i, start + half + i⟩)

theorem layer_pair (n start half : Nat) (ascending : Bool) (v : Nat → α)
    (hn : n ≤ half) (i : Nat) (hi : i < half) :
    run (layer n start half ascending) v (start + i) =
      (if i < n then low ascending (v (start + i)) (v (start + half + i))
      else v (start + i)) ∧
    run (layer n start half ascending) v (start + half + i) =
      (if i < n then high ascending (v (start + i)) (v (start + half + i))
      else v (start + half + i)) := by
  induction n generalizing i with
  | zero => simp [layer, run]
  | succ n ih =>
    have hprev := ih (by omega) i hi
    have hnew := ih (by omega) n (by omega)
    simp only [Nat.lt_irrefl, ite_false] at hnew
    have he : layer (n + 1) start half ascending = layer n start half ascending ++
        [⟨ascending, start + n, start + half + n⟩] := by
      simp [layer, List.range_succ]
    rw [he, run_append]
    simp only [run_cons, run_nil, step]
    by_cases he : i = n
    · subst i
      simp only [show start + n ≠ start + half + n by omega,
        show start + half + n ≠ start + n by omega, ite_true, ite_false,
        hnew.1, hnew.2, Nat.lt_succ_self]
      trivial
    · have h1 : start + i ≠ start + n := by omega
      have h2 : start + i ≠ start + half + n := by omega
      have h3 : start + half + i ≠ start + n := by omega
      have h4 : start + half + i ≠ start + half + n := by omega
      simpa only [h1, h2, h3, h4, ite_false, show (i < n + 1) = (i < n) from
        propext (by omega)] using hprev

end LeanSort.Bitonic.Functional
