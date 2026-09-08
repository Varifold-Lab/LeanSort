import LeanSort.Algorithm.RunDiscovery
import LeanSort.Model.MergeTree
import LeanSort.Verification.Comparison.Phases

namespace LeanSort.RunAdaptive
open Comparison

theorem sorted_prepend {α : Type} [LinearOrder α] {x y : α} {ys : List α}
    (h : x ≤ y) (sorted : (y :: ys).Pairwise (· ≤ ·)) :
    (x :: y :: ys).Pairwise (· ≤ ·) := by
  refine List.pairwise_cons.mpr ⟨?_, sorted⟩
  intro z hz
  rcases List.mem_cons.mp hz with rfl | hz
  · exact h
  · exact h.trans ((List.pairwise_cons.mp sorted).1 z hz)

theorem scanTail_spec {α : Type} [LinearOrder α] (x : α) (xs : List α) :
    ValidRuns (x :: xs) ((x :: (scanTail x xs).eval.ret.1) :: (scanTail x xs).eval.ret.2) := by
  induction xs generalizing x with
  | nil => simp [scanTail, Program.eval, ValidRuns]
  | cons y ys ih =>
    have h := ih y
    obtain ⟨hflat, hsorted, hnonempty⟩ := h
    have hs := hsorted (y :: (scanTail y ys).eval.ret.1) (by simp)
    by_cases hxy : x ≤ y
    · simp only [scanTail, Program.eval, decide_eq_true hxy, Program.eval_bind, ↓reduceIte]
      refine ⟨?_, ?_, ?_⟩
      · simpa only [List.flatten_cons, List.cons_append, List.cons.injEq, true_and] using hflat
      · intro run hr
        simp only [List.mem_cons] at hr
        rcases hr with rfl | hr
        · exact sorted_prepend hxy hs
        · exact hsorted run (by simp [hr])
      · intro run hr
        simp only [List.mem_cons] at hr
        rcases hr with rfl | hr
        · simp
        · exact hnonempty run (by simp [hr])
    · simp only [scanTail, Program.eval, decide_eq_false hxy, Program.eval_bind, Bool.false_eq_true, ↓reduceIte]
      refine ⟨?_, ?_, ?_⟩
      · simpa only [List.flatten_cons, List.singleton_append] using congrArg (List.cons x) hflat
      · intro run hr
        rcases List.mem_cons.mp hr with rfl | hr
        · simp
        · exact hsorted run hr
      · intro run hr
        rcases List.mem_cons.mp hr with rfl | hr
        · simp
        · exact hnonempty run hr

theorem discover_spec {α : Type} [LinearOrder α] (xs : List α) :
    ValidRuns xs (discover xs).eval.ret := by
  cases xs with
  | nil => simp [discover, Program.eval, ValidRuns]
  | cons x xs => simpa [discover, Program.eval_bind, Program.eval] using scanTail_spec x xs

theorem scanTail_cost {α : Type} [LinearOrder α] (x : α) (xs : List α) :
    (scanTail x xs).eval.time = xs.length := by
  induction xs generalizing x with
  | nil => rfl
  | cons y ys ih =>
    by_cases h : x ≤ y <;> simp [scanTail, Program.eval, Program.eval_bind, h, ih]

theorem discover_cost {α : Type} [LinearOrder α] (xs : List α) :
    (discover xs).eval.time = xs.length - 1 := by
  cases xs with
  | nil => rfl
  | cons x xs => simp [discover, Program.eval_bind, Program.eval, scanTail_cost]

theorem scanTail_no_sorting {α : Type} [LinearOrder α] (x : α) (xs : List α) :
    (scanTail x xs).count .sort = 0 := by
  induction xs generalizing x with
  | nil => rfl
  | cons y ys ih =>
    by_cases h : x ≤ y <;> simp [scanTail, Program.count, Program.count_bind, h, ih]

theorem discover_no_sorting {α : Type} [LinearOrder α] (xs : List α) :
    (discover xs).count .sort = 0 := by
  cases xs <;> simp [discover, Program.count_bind, Program.count, scanTail_no_sorting]

theorem nonempty_runs_length_le {α : Type} (runs : List (List α))
    (h : ∀ run ∈ runs, run ≠ []) : runs.length ≤ runs.flatten.length := by
  induction runs with
  | nil => simp
  | cons run runs ih =>
    have hn := h run (by simp)
    have hp : 0 < run.length := List.length_pos_iff.mpr hn
    have ht := ih (by intro r hr; exact h r (by simp [hr]))
    simp only [List.length_cons, List.flatten_cons, List.length_append]
    omega

theorem discover_count_le {α : Type} [LinearOrder α] (xs : List α) :
    (discover xs).eval.ret.length ≤ xs.length := by
  have h := discover_spec xs
  simpa [h.1] using nonempty_runs_length_le _ h.2.2

theorem scanTail_of_sorted {α : Type} [LinearOrder α] (x : α) (xs : List α)
    (h : (x :: xs).Pairwise (· ≤ ·)) : (scanTail x xs).eval.ret = (xs, []) := by
  induction xs generalizing x with
  | nil => rfl
  | cons y ys ih =>
    have hxy : x ≤ y := (List.pairwise_cons.mp h).1 y (by simp)
    simp [scanTail, Program.eval, Program.eval_bind, hxy, ih y h.of_cons]

theorem discover_of_sorted {α : Type} [LinearOrder α] (xs : List α)
    (h : xs.Pairwise (· ≤ ·)) : (discover xs).eval.ret = if xs = [] then [] else [xs] := by
  cases xs with
  | nil => rfl
  | cons x xs => simp [discover, Program.eval_bind, Program.eval, scanTail_of_sorted x xs h]

end LeanSort.RunAdaptive
