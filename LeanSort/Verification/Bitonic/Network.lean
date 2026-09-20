import LeanSort.Verification.Bitonic.Boolean
import LeanSort.Verification.Bitonic.Functional

namespace LeanSort.Bitonic.Functional

def Ordered {α : Type*} [LinearOrder α] (a : Bool) (v : Nat → α) (s n : Nat) : Prop :=
  ∀ i j, s ≤ i → i ≤ j → j < s + n → if a then v i ≤ v j else v j ≤ v i

def IsBitonic (v : Nat → Bool) (s n : Nat) : Prop :=
  Boolean.IsBitonic01 (fun i : Fin n => v (s + i))

@[simp] theorem low_true_bool (x y : Bool) : low true x y = (x && y) := by
  cases x <;> cases y <;> decide
@[simp] theorem high_true_bool (x y : Bool) : high true x y = (x || y) := by
  cases x <;> cases y <;> decide

theorem merge_frame {α : Type*} [LinearOrder α] (d s : Nat) (a : Bool)
    (v : Nat → α) (k : Nat) (hk : k < s ∨ s + 2 ^ d ≤ k) :
    run (mergeSchedule d s a) v k = v k := by
  apply run_frame
  intro c hc
  have := mergeSchedule_bounds d s a c hc
  omega

theorem sort_frame {α : Type*} [LinearOrder α] (d s : Nat) (a : Bool)
    (v : Nat → α) (k : Nat) (hk : k < s ∨ s + 2 ^ d ≤ k) :
    run (sortSchedule d s a) v k = v k := by
  apply run_frame
  intro c hc
  have := sortSchedule_bounds d s a c hc
  omega

theorem merge_property {α : Type*} [LinearOrder α] (d s : Nat) (a : Bool)
    (v : Nat → α) (P : α → Prop)
    (hv : ∀ k, s ≤ k → k < s + 2 ^ d → P (v k)) :
    ∀ k, s ≤ k → k < s + 2 ^ d → P (run (mergeSchedule d s a) v k) := by
  have h := run_property (mergeSchedule d s a) v
    (fun k => s ≤ k ∧ k < s + 2 ^ d) P
    (fun c hc => by have := mergeSchedule_bounds d s a c hc; constructor <;> constructor <;> omega)
    (fun k hk => hv k hk.1 hk.2)
  exact fun k h1 h2 => h k ⟨h1, h2⟩

theorem layer_split (s m : Nat) (v : Nat → Bool) (hv : IsBitonic v s (2 * m)) :
    let w := run (layer m s m true) v
    IsBitonic w s m ∧ IsBitonic w (s + m) m ∧
      ((∀ k, s ≤ k → k < s + m → w k = false) ∨
       (∀ k, s + m ≤ k → k < s + 2 * m → w k = true)) := by
  let u : Fin (2 * m) → Bool := fun i => v (s + i)
  let w := run (layer m s m true) v
  have hleft : (fun i : Fin m => w (s + i)) =
      (fun i : Fin m => u ⟨i, by omega⟩ && u ⟨i + m, by omega⟩) := by
    funext i
    have h := (layer_pair m s m true v le_rfl i i.isLt).1
    simpa [w, u, i.isLt, Nat.add_assoc, Nat.add_comm, Nat.add_left_comm] using h
  have hright : (fun i : Fin m => w (s + m + i)) =
      (fun i : Fin m => u ⟨i, by omega⟩ || u ⟨i + m, by omega⟩) := by
    funext i
    have h := (layer_pair m s m true v le_rfl i i.isLt).2
    simpa [w, u, i.isLt, Nat.add_assoc, Nat.add_comm, Nat.add_left_comm] using h
  obtain ⟨b, lo, hi, hlo, hhi, hu⟩ := hv
  change ∀ i, u i = b ↔ _ at hu
  have hl : IsBitonic w s m := by
    unfold IsBitonic
    rw [hleft]
    cases b
    · exact Boolean.and_bitonic_false hhi hlo hu
    · exact Boolean.and_bitonic_true hhi hlo hu
  have hr : IsBitonic w (s + m) m := by
    unfold IsBitonic
    rw [hright]
    cases b
    · exact Boolean.or_bitonic_false hhi hlo hu
    · exact Boolean.or_bitonic_true hhi hlo hu
  refine ⟨hl, hr, ?_⟩
  have hsep : (∀ i : Fin m, (u ⟨i, by omega⟩ && u ⟨i + m, by omega⟩) = false) ∨
      (∀ i : Fin m, (u ⟨i, by omega⟩ || u ⟨i + m, by omega⟩) = true) := by
    cases b
    · exact Boolean.and_or_left_le_right_false hhi hlo hu
    · exact Boolean.and_or_left_le_right_true hhi hlo hu
  rcases hsep with h | h
  · left
    intro k hk hk'
    have he := congrFun hleft ⟨k - s, by omega⟩
    have hv := h ⟨k - s, by omega⟩
    have heq : s + (k - s) = k := by omega
    simpa only [heq] using he.trans hv
  · right
    intro k hk hk'
    have he := congrFun hright ⟨k - (s + m), by omega⟩
    have hv := h ⟨k - (s + m), by omega⟩
    have heq : s + m + (k - (s + m)) = k := by omega
    simpa only [heq] using he.trans hv

theorem merge_ordered_true (d s : Nat) (v : Nat → Bool) (hv : IsBitonic v s (2 ^ d)) :
    Ordered true (run (mergeSchedule d s true) v) s (2 ^ d) := by
  induction d generalizing s v with
  | zero =>
    intro i j hi hij hj
    have : i = j := by simpa using (show i = j by simp only [pow_zero] at hj; omega)
    subst j
    simp
  | succ d ih =>
    have he : 2 ^ (d + 1) = 2 * 2 ^ d := by rw [Nat.pow_succ]; omega
    rw [he] at hv
    obtain ⟨hl, hr, hsep⟩ := layer_split s (2 ^ d) v hv
    let w := run (layer (2 ^ d) s (2 ^ d) true) v
    let l := run (mergeSchedule d s true) w
    have hframe : ∀ k, s + 2 ^ d ≤ k →
        l k = w k := fun k hk => merge_frame d s true w k (Or.inr hk)
    have hright : IsBitonic l (s + 2 ^ d) (2 ^ d) := by
      change Boolean.IsBitonic01 _
      have heq : (fun i : Fin (2 ^ d) => l (s + 2 ^ d + i)) =
          (fun i : Fin (2 ^ d) => w (s + 2 ^ d + i)) :=
        funext (fun i => hframe _ (by omega))
      rw [heq]
      exact hr
    have hls := ih s w hl
    have hrs := ih (s + 2 ^ d) l hright
    rw [mergeSchedule, run_append, run_append]
    change Ordered true (run (mergeSchedule d (s + 2 ^ d) true) l) s (2 ^ (d + 1))
    intro i j hi hij hj
    simp only [ite_true]
    rw [he] at hj
    by_cases hjl : j < s + 2 ^ d
    · rw [merge_frame _ _ _ _ i (Or.inl (by omega)),
        merge_frame _ _ _ _ j (Or.inl hjl)]
      exact hls i j hi hij hjl
    · by_cases hil : i < s + 2 ^ d
      · rcases hsep with hfalse | htrue
        · have hzero := merge_property d s true w (· = false) hfalse i hi hil
          change l i = false at hzero
          rw [merge_frame _ _ _ _ i (Or.inl hil), hzero]
          exact Bool.false_le _
        · have hone : ∀ k, s + 2 ^ d ≤ k → k < s + 2 ^ d + 2 ^ d → l k = true := by
            intro k hk hk'
            rw [hframe k hk]
            exact htrue k hk (by omega)
          rw [merge_property d (s + 2 ^ d) true l (· = true) hone j (by omega) (by omega)]
          exact Bool.le_true _
      · exact hrs i j (by omega) hij (by omega)

def flip (c : Comparator) : Comparator := ⟨!c.ascending, c.first, c.second⟩

theorem step_flip (c : Comparator) (v : Nat → Bool) :
    step (flip c) (Bool.not ∘ v) = Bool.not ∘ step c v := by
  have hl : ∀ a x y : Bool, low (!a) (!x) (!y) = !(low a x y) := by decide
  have hh : ∀ a x y : Bool, high (!a) (!x) (!y) = !(high a x y) := by decide
  funext k
  simp only [flip, step, Function.comp_apply, hl, hh]
  split_ifs <;> rfl

theorem run_flip (cs : List Comparator) (v : Nat → Bool) :
    run (cs.map flip) (Bool.not ∘ v) = Bool.not ∘ run cs v := by
  induction cs generalizing v with
  | nil => rfl
  | cons c cs ih => simp only [List.map_cons, run_cons, step_flip, ih]

theorem mergeSchedule_flip (d s : Nat) (a : Bool) :
    (mergeSchedule d s a).map flip = mergeSchedule d s (!a) := by
  induction d generalizing s with
  | zero => rfl
  | succ d ih =>
    simp only [mergeSchedule, List.map_append, List.map_map, ih]
    rfl

theorem merge_ordered (d s : Nat) (a : Bool) (v : Nat → Bool)
    (hv : IsBitonic v s (2 ^ d)) : Ordered a (run (mergeSchedule d s a) v) s (2 ^ d) := by
  cases a
  · have hb : IsBitonic (Bool.not ∘ v) s (2 ^ d) := Boolean.bitonic_not hv
    have hs := merge_ordered_true d s (Bool.not ∘ v) hb
    have he := run_flip (mergeSchedule d s false) v
    rw [mergeSchedule_flip] at he
    change run (mergeSchedule d s true) (Bool.not ∘ v) = _ at he
    intro i j hi hij hj
    have h := hs i j hi hij hj
    rw [he] at h
    have hn : ∀ x y : Bool, ((!x) ≤ (!y)) ↔ y ≤ x := by decide
    exact (hn _ _).mp (by simpa [Function.comp_def] using h)
  · exact merge_ordered_true d s v hv

theorem sort_ordered_bool (d s : Nat) (a : Bool) (v : Nat → Bool) :
    Ordered a (run (sortSchedule d s a) v) s (2 ^ d) := by
  induction d generalizing s a v with
  | zero =>
    intro i j hi hij hj
    have : i = j := by simp only [pow_zero] at hj; omega
    subst j
    cases a <;> simp
  | succ d ih =>
    let l := run (sortSchedule d s true) v
    let r := run (sortSchedule d (s + 2 ^ d) false) l
    have hl := ih s true v
    have hr := ih (s + 2 ^ d) false l
    have he : 2 ^ (d + 1) = 2 * 2 ^ d := by rw [Nat.pow_succ]; omega
    have hb : IsBitonic r s (2 ^ (d + 1)) := by
      rw [he]
      apply Boolean.upDown_bitonic
      · intro i j hij
        change r (s + i) ≤ r (s + j)
        have hi : s + i.val < s + 2 ^ d := by omega
        have hj : s + j.val < s + 2 ^ d := by omega
        dsimp only [r]
        rw [sort_frame _ _ _ _ _ (Or.inl hi), sort_frame _ _ _ _ _ (Or.inl hj)]
        exact hl _ _ (by omega) (by exact Nat.add_le_add_left hij s) hj
      · intro i j hij
        change r (s + (j.val + 2 ^ d)) ≤ r (s + (i.val + 2 ^ d))
        exact hr _ _ (by omega) (by have := Fin.le_def.mp hij; omega) (by omega)
    rw [sortSchedule, run_append, run_append]
    exact merge_ordered d.succ s a r hb

/-- Zero-one principle: a threshold between an inverted pair would contradict
the Boolean theorem, because every comparator commutes with monotone maps. -/
theorem sort_ordered {α : Type*} [LinearOrder α] (d s : Nat) (a : Bool) (v : Nat → α) :
    Ordered a (run (sortSchedule d s a) v) s (2 ^ d) := by
  intro i j hi hij hj
  let w := run (sortSchedule d s a) v
  by_contra hn
  cases a with
  | true =>
    have hbad : w j < w i := by simpa [w] using hn
    let f : α → Bool := fun x => decide (w i ≤ x)
    have hf : Monotone f := by
      intro x y hxy
      simp only [f, Bool.le_iff_imp, decide_eq_true_eq]
      exact fun hx => le_trans hx hxy
    have hs := sort_ordered_bool d s true (f ∘ v) i j hi hij hj
    rw [run_map f hf] at hs
    simp [f, w, not_le_of_gt hbad, Bool.le_iff_imp] at hs
  | false =>
    have hbad : w i < w j := by simpa [w] using hn
    let f : α → Bool := fun x => decide (w j ≤ x)
    have hf : Monotone f := by
      intro x y hxy
      simp only [f, Bool.le_iff_imp, decide_eq_true_eq]
      exact fun hx => le_trans hx hxy
    have hs := sort_ordered_bool d s false (f ∘ v) i j hi hij hj
    rw [run_map f hf] at hs
    simp [f, w, not_le_of_gt hbad, Bool.le_iff_imp] at hs

end LeanSort.Bitonic.Functional
