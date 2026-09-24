import LeanSort.Verification.Power.Equations
import LeanSort.Model.SortingResult
import Mathlib.Data.Multiset.AddSub

/-! Correctness for the actual run scanner and stack scheduler, including
Boolean total-preorder comparators on records. No balance assumption is needed. -/

namespace LeanSort.Power

variable {α : Type*}

@[simp] theorem finishRun_perm (xs : List α) (direction : Option Bool) :
    (finishRun xs direction).Perm xs := by
  unfold finishRun
  split
  · exact .refl _
  · exact List.reverse_perm _

theorem scanRuns_perm (le : α → α → Bool) (xs current : List α)
    (direction : Option Bool) (done : List (List α)) :
    (scanRuns le xs current direction done).flatten.Perm (done.flatten ++ current ++ xs) := by
  induction xs generalizing current direction done with
  | nil =>
    cases current with
    | nil => simpa [scanRuns] using (List.reverse_perm done).flatten
    | cons x current =>
      have hr := (List.reverse_perm (finishRun (x :: current) direction :: done)).flatten
      exact hr.trans (by
        simpa using ((finishRun_perm (x :: current) direction).append_right done.flatten).trans
          (List.perm_append_comm))
  | cons x xs ih =>
    cases current with
    | nil => simpa [scanRuns] using ih [x] none done
    | cons p current =>
      cases direction with
      | none =>
        exact (ih (x :: p :: current) (some (le p x)) done).trans (by
          simpa [List.append_assoc] using
            (List.perm_middle (a := x) (l₁ := p :: current) (l₂ := xs)).symm.append_left done.flatten)
      | some ascending =>
        simp only [scanRuns]
        by_cases h : (if ascending then le p x else !(le p x)) = true
        · rw [ite_eq_left h]
          exact (ih (x :: p :: current) (some ascending) done).trans (by
            simpa [List.append_assoc] using
              (List.perm_middle (a := x) (l₁ := p :: current) (l₂ := xs)).symm.append_left done.flatten)
        · rw [ite_eq_right h]
          exact (ih [x] none (finishRun (p :: current) (some ascending) :: done)).trans (by
            have hf := (finishRun_perm (p :: current) (some ascending)).append_right done.flatten
            have hp := hf.trans List.perm_append_comm
            simpa [List.append_assoc] using hp.append_right (x :: xs))

theorem naturalRuns_perm (le : α → α → Bool) (xs : List α) :
    (naturalRuns le xs).flatten.Perm xs := by
  simpa [naturalRuns] using scanRuns_perm le xs [] none []

/-- The stack's multiset, independent of its right-to-left representation. -/
def stackValues (stack : List (Pending α)) : List α := (stack.map Pending.values).flatten

theorem collapse_perm (le : α → α → Bool) (power : Nat)
    (stack : List (Pending α)) (current : List α) :
    (stackValues (collapse le power stack current).2 ++ (collapse le power stack current).1).Perm
      (stackValues stack ++ current) := by
  induction stack generalizing current with
  | nil => simp [collapse]
  | cons top rest ih =>
    simp only [collapse]
    split
    · exact (ih _).trans (by
        have h := (List.merge_perm_append le (xs := top.values) (ys := current)).append_left
          (stackValues rest)
        exact h.trans (by
          simpa [stackValues, List.append_assoc] using
            (List.perm_append_comm (l₁ := stackValues rest) (l₂ := top.values)).append_right current))
    · exact .refl _

theorem finishStack_perm (le : α → α → Bool) (stack : List (Pending α)) (current : List α) :
    (finishStack le stack current).Perm (stackValues stack ++ current) := by
  induction stack generalizing current with
  | nil => simp [finishStack, stackValues]
  | cons top rest ih =>
    exact (ih _).trans (by
      have h := (List.merge_perm_append le (xs := top.values) (ys := current)).append_left
        (stackValues rest)
      exact h.trans (by
        simpa [stackValues, List.append_assoc] using
          (List.perm_append_comm (l₁ := stackValues rest) (l₂ := top.values)).append_right current))

theorem mergeRuns_perm (le : α → α → Bool) (n : Nat) (runs : List (List α))
    (start : Nat) (current : List α) (stack : List (Pending α)) :
    (mergeRuns le n runs start current stack).Perm (stackValues stack ++ current ++ runs.flatten) := by
  induction runs generalizing start current stack with
  | nil => simpa [mergeRuns] using finishStack_perm le stack current
  | cons next rest ih =>
    dsimp only [mergeRuns]
    apply (ih _ _ _).trans
    have h := (collapse_perm le (nodePower n start current.length next.length) stack current)
    have hc := List.perm_append_comm.trans h
    simpa [stackValues, List.append_assoc] using hc.append_right (next ++ rest.flatten)

theorem powerSortBy_perm (le : α → α → Bool) (xs : List α) :
    (powerSortBy le xs).Perm xs := by
  have h := naturalRuns_perm le xs
  unfold powerSortBy
  split
  · simp_all only [List.flatten_nil]
  · rename_i first rest he
    have hp := mergeRuns_perm le xs.length rest 0 first []
    simp only [stackValues, List.map_nil, List.flatten_nil, List.nil_append] at hp
    exact hp.trans (by simpa [he] using h)

section Sorted

variable (le : α → α → Bool)
variable (htrans : ∀ a b c, le a b = true → le b c = true → le a c = true)
variable (htotal : ∀ a b, le a b = true ∨ le b a = true)

def RunOrdered (current : List α) : Option Bool → Prop
  | none => current.length ≤ 1
  | some true => current.Pairwise (fun a b => le b a = true)
  | some false => current.Pairwise (fun a b => le a b = true)

theorem finishRun_sorted (current : List α) (direction : Option Bool)
    (h : RunOrdered le current direction) :
    (finishRun current direction).Pairwise (fun a b => le a b = true) := by
  cases direction with
  | none =>
    cases current with
    | nil => simp [finishRun]
    | cons a rest =>
      have : rest = [] := by simpa [RunOrdered] using h
      simp [this, finishRun]
  | some d => cases d <;> simpa [RunOrdered, finishRun, List.pairwise_reverse] using h

include htrans htotal

theorem scanRuns_sorted (xs current : List α) (direction : Option Bool) (done : List (List α))
    (hc : RunOrdered le current direction)
    (hd : ∀ run ∈ done, run.Pairwise (fun a b => le a b = true)) :
    ∀ run ∈ scanRuns le xs current direction done, run.Pairwise (fun a b => le a b = true) := by
  induction xs generalizing current direction done with
  | nil =>
    intro run hr
    simp only [scanRuns, List.mem_reverse] at hr
    split at hr
    · exact hd _ hr
    · rcases List.mem_cons.mp hr with rfl | hr
      · exact finishRun_sorted le current direction hc
      · exact hd _ hr
  | cons x xs ih =>
    cases current with
    | nil => exact ih [x] none done (by simp [RunOrdered]) hd
    | cons p rest =>
      cases direction with
      | none =>
        have hr : rest = [] := by simpa [RunOrdered] using hc
        subst rest
        apply ih _ _ _ _ hd
        cases hp : le p x
        · have hx := htotal p x
          simp_all [RunOrdered]
        · simp [RunOrdered, hp]
      | some d =>
        simp only [scanRuns]
        by_cases h : (if d then le p x else !(le p x)) = true
        · rw [ite_eq_left h]
          apply ih _ _ _ _ hd
          cases d
          · have hx : le x p = true := (htotal p x).resolve_left (by simpa using h)
            apply List.Pairwise.cons _ hc
            intro y hy
            rcases List.mem_cons.mp hy with rfl | hy
            · exact hx
            · exact htrans _ _ _ hx (List.rel_of_pairwise_cons hc hy)
          · have hx : le p x = true := by simpa using h
            apply List.Pairwise.cons _ hc
            intro y hy
            rcases List.mem_cons.mp hy with rfl | hy
            · exact hx
            · exact htrans _ _ _ (List.rel_of_pairwise_cons hc hy) hx
        · rw [ite_eq_right h]
          apply ih _ _ _ (by simp [RunOrdered])
          intro run hr
          rcases List.mem_cons.mp hr with rfl | hr
          · exact finishRun_sorted le _ _ hc
          · exact hd _ hr

theorem naturalRuns_sorted (xs : List α) :
    ∀ run ∈ naturalRuns le xs, run.Pairwise (fun a b => le a b = true) :=
  scanRuns_sorted le htrans htotal xs [] none [] (by simp [RunOrdered]) (by simp)

theorem collapse_sorted (power : Nat) (stack : List (Pending α)) (current : List α)
    (hs : ∀ top ∈ stack, top.values.Pairwise (fun a b => le a b = true))
    (hc : current.Pairwise (fun a b => le a b = true)) :
    (collapse le power stack current).1.Pairwise (fun a b => le a b = true) ∧
    ∀ top ∈ (collapse le power stack current).2, top.values.Pairwise (fun a b => le a b = true) := by
  induction stack generalizing current with
  | nil => simpa [collapse] using hc
  | cons top rest ih =>
    simp only [collapse]
    split
    · apply ih _ (fun t ht => hs t (by simp [ht]))
      exact List.pairwise_merge htrans (fun a b => by simpa using htotal a b) _ _
        (hs top (by simp)) hc
    · exact ⟨hc, hs⟩

theorem finishStack_sorted (stack : List (Pending α)) (current : List α)
    (hs : ∀ top ∈ stack, top.values.Pairwise (fun a b => le a b = true))
    (hc : current.Pairwise (fun a b => le a b = true)) :
    (finishStack le stack current).Pairwise (fun a b => le a b = true) := by
  induction stack generalizing current with
  | nil => exact hc
  | cons top rest ih =>
    apply ih _ (fun t ht => hs t (by simp [ht]))
    exact List.pairwise_merge htrans (fun a b => by simpa using htotal a b) _ _
      (hs top (by simp)) hc

theorem mergeRuns_sorted (n : Nat) (runs : List (List α)) (start : Nat)
    (current : List α) (stack : List (Pending α))
    (hr : ∀ run ∈ runs, run.Pairwise (fun a b => le a b = true))
    (hs : ∀ top ∈ stack, top.values.Pairwise (fun a b => le a b = true))
    (hc : current.Pairwise (fun a b => le a b = true)) :
    (mergeRuns le n runs start current stack).Pairwise (fun a b => le a b = true) := by
  induction runs generalizing start current stack with
  | nil => exact finishStack_sorted le htrans htotal stack current hs hc
  | cons next rest ih =>
    have hh := collapse_sorted le htrans htotal (nodePower n start current.length next.length)
      stack current hs hc
    apply ih _ _ _ (fun r h => hr r (by simp [h]))
    · intro t ht
      rcases List.mem_cons.mp ht with rfl | ht
      · exact hh.1
      · exact hh.2 _ ht
    · exact hr next (by simp)

theorem powerSortBy_spec (xs : List α) :
    IsSortingResult (fun a b => le a b = true) xs (powerSortBy le xs) := by
  refine ⟨?_, powerSortBy_perm le xs⟩
  have h := naturalRuns_sorted le htrans htotal xs
  unfold powerSortBy
  split
  · simp
  · rename_i first rest he
    apply mergeRuns_sorted le htrans htotal
    · exact fun r hr => h r (by simp [he, hr])
    · simp
    · exact h first (by simp [he])

end Sorted

theorem powerSortResult_spec [LinearOrder α] (xs : List α) :
    IsSortingResult (· ≤ ·) xs (powerSortResult xs) := by
  simpa [powerSortResult] using powerSortBy_spec (fun a b : α => decide (a ≤ b))
    (by simpa using fun a b c => @le_trans α _ a b c)
    (by simpa using fun a b : α => le_total a b) xs

theorem powerSortResult_perm [LinearOrder α] (xs : List α) :
    (powerSortResult xs).Perm xs := (powerSortResult_spec xs).2

@[simp] theorem powerSortBy_length (le : α → α → Bool) (xs : List α) :
    (powerSortBy le xs).length = xs.length := (powerSortBy_perm le xs).length_eq

@[simp] theorem powerSortResult_length [LinearOrder α] (xs : List α) :
    (powerSortResult xs).length = xs.length := (powerSortResult_perm xs).length_eq

end LeanSort.Power
