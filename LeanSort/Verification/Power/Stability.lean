import LeanSort.Verification.Power.Correctness

/-! Stability means equality of the full input and output subsequences for
each key, so payloads and repeated occurrences retain their relative order. -/

namespace LeanSort.Power

variable {α β : Type*} [LinearOrder β] (key : α → β)

private theorem merge_filter_key (xs ys : List α)
    (hx : xs.Pairwise (fun a b => key a ≤ key b))
    (hy : ys.Pairwise (fun a b => key a ≤ key b)) (k : β) :
    (xs.merge ys (fun a b => decide (key a ≤ key b))).filter (fun x => decide (key x = k)) =
      xs.filter (fun x => decide (key x = k)) ++ ys.filter (fun x => decide (key x = k)) := by
  induction xs generalizing ys with
  | nil => simp
  | cons x xs ih =>
    induction ys with
    | nil => simp
    | cons y ys ihy =>
      simp only [List.merge]
      by_cases h : key x ≤ key y
      · simp only [h, decide_true, ite_true]
        rw [List.filter_cons, ih _ hx.tail hy]
        split <;> simp [List.filter_cons, *]
      · simp only [h, decide_false, Bool.false_eq_true, ite_false]
        rw [List.filter_cons, ihy hy.tail]
        by_cases hk : key y = k
        · have hn : (x :: xs).filter (fun a => decide (key a = k)) = [] := by
            apply List.filter_eq_nil_iff.mpr
            intro a ha
            simp only [decide_eq_true_eq]
            have hh : key x ≤ key a := by
              rcases List.mem_cons.mp ha with rfl | ha
              · exact le_rfl
              · exact List.rel_of_pairwise_cons hx ha
            intro he
            exact h (by simpa [he, hk] using hh)
          simp [hk, hn]
        · simp [hk]

private def RunStrict (current : List α) : Option Bool → Prop
  | none => current.length ≤ 1
  | some true => True
  | some false => current.Pairwise (fun a b => key a < key b)

private theorem strict_filter_reverse (xs : List α)
    (h : xs.Pairwise (fun a b => key a < key b)) (k : β) :
    xs.filter (fun x => decide (key x = k)) =
      xs.reverse.filter (fun x => decide (key x = k)) := by
  induction xs with
  | nil => simp
  | cons x xs ih =>
    by_cases hx : key x = k
    · have hn : xs.filter (fun a => decide (key a = k)) = [] := by
        apply List.filter_eq_nil_iff.mpr
        intro a ha
        simp only [decide_eq_true_eq]
        have ht := List.rel_of_pairwise_cons h ha
        intro he
        simp [hx, he] at ht
      simp [List.reverse_cons, hx, List.filter_reverse, hn]
    · simpa [List.reverse_cons, hx] using ih h.tail

private theorem finishRun_filter (xs : List α) (direction : Option Bool)
    (h : RunStrict key xs direction) (k : β) :
    (finishRun xs direction).filter (fun x => decide (key x = k)) =
      xs.reverse.filter (fun x => decide (key x = k)) := by
  cases direction with
  | none => rfl
  | some d =>
    cases d
    · exact strict_filter_reverse key xs h k
    · rfl

private theorem scanRuns_filter (xs current : List α) (direction : Option Bool)
    (done : List (List α)) (hc : RunStrict key current direction) (k : β) :
    (scanRuns (fun a b => decide (key a ≤ key b)) xs current direction done).flatten.filter
      (fun x => decide (key x = k)) =
      (done.reverse.flatten ++ current.reverse ++ xs).filter (fun x => decide (key x = k)) := by
  induction xs generalizing current direction done with
  | nil =>
    cases current with
    | nil => simp [scanRuns]
    | cons p rest => simp [scanRuns, List.reverse_cons, List.filter_append,
        finishRun_filter key _ _ hc k]
  | cons x xs ih =>
    cases current with
    | nil => simpa [scanRuns, List.append_assoc] using ih [x] none done (by simp [RunStrict])
    | cons p rest =>
      cases direction with
      | none =>
        have hr : rest = [] := by simpa [RunStrict] using hc
        subst rest
        have hh : RunStrict key [x, p] (some (decide (key p ≤ key x))) := by
          by_cases hp : key p ≤ key x
          · simp [hp, RunStrict]
          · simp [hp, RunStrict, lt_of_not_ge hp]
        simpa [scanRuns, List.append_assoc] using ih [x, p] _ done hh
      | some d =>
        simp only [scanRuns]
        by_cases h : (if d then decide (key p ≤ key x) else !(decide (key p ≤ key x))) = true
        · rw [ite_eq_left h]
          have hh : RunStrict key (x :: p :: rest) (some d) := by
            cases d
            · have hp : key x < key p := lt_of_not_ge (by simpa using h)
              apply List.Pairwise.cons _ hc
              intro a ha
              rcases List.mem_cons.mp ha with rfl | ha
              · exact hp
              · exact lt_trans hp (List.rel_of_pairwise_cons hc ha)
            · trivial
          simpa [List.reverse_cons, List.append_assoc] using ih _ _ done hh
        · rw [ite_eq_right h]
          rw [ih _ _ _ (by simp [RunStrict])]
          by_cases hp : key p = k <;>
            simp [List.reverse_cons, List.filter_append, List.append_assoc,
              finishRun_filter key _ _ hc k, hp]

theorem naturalRuns_filter (xs : List α) (k : β) :
    (naturalRuns (fun a b => decide (key a ≤ key b)) xs).flatten.filter
      (fun x => decide (key x = k)) = xs.filter (fun x => decide (key x = k)) := by
  simpa [naturalRuns] using scanRuns_filter key xs [] none [] (by simp [RunStrict]) k

private def stackOrder (stack : List (Pending α)) : List α :=
  (stack.reverse.map Pending.values).flatten

private theorem collapse_filter (power : Nat) (stack : List (Pending α)) (current : List α)
    (hs : ∀ top ∈ stack, top.values.Pairwise (fun a b => key a ≤ key b))
    (hc : current.Pairwise (fun a b => key a ≤ key b)) (k : β) :
    let result := collapse (fun a b => decide (key a ≤ key b)) power stack current
    (stackOrder result.2 ++ result.1).filter (fun x => decide (key x = k)) =
      (stackOrder stack ++ current).filter (fun x => decide (key x = k)) := by
  induction stack generalizing current with
  | nil => rfl
  | cons top rest ih =>
    dsimp only [collapse]
    split
    · rw [ih _ (fun t ht => hs t (by simp [ht])) (by
        simpa using List.pairwise_merge
          (le := fun a b => decide (key a ≤ key b))
          (by simp only [decide_eq_true_eq]; exact fun a b c => le_trans)
          (by simp only [Bool.or_eq_true, decide_eq_true_eq]; exact fun a b => le_total _ _)
          _ _ (by simpa using hs top (by simp)) (by simpa using hc))]
      simp [stackOrder, List.reverse_cons, List.filter_append, List.append_assoc,
        merge_filter_key key _ _ (hs top (by simp)) hc k]
    · rfl

private theorem finishStack_filter (stack : List (Pending α)) (current : List α)
    (hs : ∀ top ∈ stack, top.values.Pairwise (fun a b => key a ≤ key b))
    (hc : current.Pairwise (fun a b => key a ≤ key b)) (k : β) :
    (finishStack (fun a b => decide (key a ≤ key b)) stack current).filter
      (fun x => decide (key x = k)) =
      (stackOrder stack ++ current).filter (fun x => decide (key x = k)) := by
  induction stack generalizing current with
  | nil => rfl
  | cons top rest ih =>
    rw [finishStack, ih _ (fun t ht => hs t (by simp [ht])) (by
      simpa using List.pairwise_merge
        (le := fun a b => decide (key a ≤ key b))
        (by simp only [decide_eq_true_eq]; exact fun a b c => le_trans)
        (by simp only [Bool.or_eq_true, decide_eq_true_eq]; exact fun a b => le_total _ _)
        _ _ (by simpa using hs top (by simp)) (by simpa using hc))]
    simp [stackOrder, List.reverse_cons, List.filter_append, List.append_assoc,
      merge_filter_key key _ _ (hs top (by simp)) hc k]

private theorem mergeRuns_filter (n : Nat) (runs : List (List α)) (start : Nat)
    (current : List α) (stack : List (Pending α))
    (hr : ∀ run ∈ runs, run.Pairwise (fun a b => key a ≤ key b))
    (hs : ∀ top ∈ stack, top.values.Pairwise (fun a b => key a ≤ key b))
    (hc : current.Pairwise (fun a b => key a ≤ key b)) (k : β) :
    (mergeRuns (fun a b => decide (key a ≤ key b)) n runs start current stack).filter
      (fun x => decide (key x = k)) =
      (stackOrder stack ++ current ++ runs.flatten).filter (fun x => decide (key x = k)) := by
  induction runs generalizing start current stack with
  | nil => simpa [mergeRuns] using finishStack_filter key stack current hs hc k
  | cons next rest ih =>
    have hh := collapse_sorted (fun a b => decide (key a ≤ key b))
      (by simpa using fun a b c => @le_trans β _ (key a) (key b) (key c))
      (by simpa using fun a b => le_total (key a) (key b))
      (nodePower n start current.length next.length) stack current
      (by simpa using hs) (by simpa using hc)
    dsimp only [mergeRuns]
    rw [ih _ _ _ (fun r h => hr r (by simp [h])) (by
      simpa only [List.mem_cons, forall_eq_or_imp, decide_eq_true_eq] using hh)
      (hr next (by simp))]
    have hf := collapse_filter key (nodePower n start current.length next.length) stack current hs hc k
    simp only [List.filter_append] at hf
    simpa [stackOrder, List.reverse_cons, List.filter_append, List.append_assoc] using
      congrArg (fun l => l ++ (next ++ rest.flatten).filter (fun x => decide (key x = k))) hf

/-- Every equal-key subsequence is preserved exactly, including record payloads. -/
theorem powerSortBy_stable (xs : List α) (k : β) :
    (powerSortBy (fun a b => decide (key a ≤ key b)) xs).filter (fun x => decide (key x = k)) =
      xs.filter (fun x => decide (key x = k)) := by
  have hr := naturalRuns_sorted (fun a b => decide (key a ≤ key b))
    (by simpa using fun a b c => @le_trans β _ (key a) (key b) (key c))
    (by simpa using fun a b => le_total (key a) (key b)) xs
  have hf := naturalRuns_filter key xs k
  unfold powerSortBy
  split
  · rename_i he
    simpa only [he, List.flatten_nil, List.filter_nil] using hf
  · rename_i first rest he
    rw [mergeRuns_filter key _ _ _ _ _
      (fun r h => by simpa using hr r (by simp [he, h])) (by simp)
      (by simpa using hr first (by simp [he]))]
    simpa [he, stackOrder] using hf

end LeanSort.Power
