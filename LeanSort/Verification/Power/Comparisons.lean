import LeanSort.Verification.Power.MergeTree
import LeanSort.Verification.Power.Cost

/-! Key-comparison instrumentation, including run detection and every merge.
Dyadic arithmetic, allocation, list copying, and checker overhead are excluded. -/

namespace LeanSort.Power

variable {α : Type*}

def mergeComparisonRun (le : α → α → Bool) : List α → List α → List α × Nat
  | [], ys => (ys, 0)
  | xs, [] => (xs, 0)
  | x :: xs, y :: ys =>
    if le x y then
      let result := mergeComparisonRun le xs (y :: ys)
      (x :: result.1, result.2 + 1)
    else
      let result := mergeComparisonRun le (x :: xs) ys
      (y :: result.1, result.2 + 1)
termination_by xs ys => xs.length + ys.length

@[simp] theorem mergeComparisonRun_result (le : α → α → Bool) (xs ys : List α) :
    (mergeComparisonRun le xs ys).1 = xs.merge ys le := by
  induction xs generalizing ys with
  | nil => simp [mergeComparisonRun]
  | cons x xs ih =>
    induction ys with
    | nil => simp [mergeComparisonRun]
    | cons y ys ihy => simp only [mergeComparisonRun, List.merge]; split <;> simp_all

theorem mergeComparisonRun_le (le : α → α → Bool) (xs ys : List α) :
    (mergeComparisonRun le xs ys).2 ≤ xs.length + ys.length := by
  induction xs generalizing ys with
  | nil => simp [mergeComparisonRun]
  | cons x xs ih =>
    induction ys with
    | nil => simp [mergeComparisonRun]
    | cons y ys ihy =>
      simp only [mergeComparisonRun]
      split
      · have := ih (y :: ys); simp only [List.length_cons] at *; omega
      · simp only [List.length_cons] at *; omega

def MergeTree.comparisonRun (le : α → α → Bool) : MergeTree α → List α × Nat
  | .leaf xs _ => (xs, 0)
  | .join l r =>
    let left := l.comparisonRun le
    let right := r.comparisonRun le
    let merged := mergeComparisonRun le left.1 right.1
    (merged.1, left.2 + right.2 + merged.2)

@[simp] theorem MergeTree.comparisonRun_result (le : α → α → Bool) (t : MergeTree α) :
    (t.comparisonRun le).1 = t.eval le := by
  induction t with
  | leaf => rfl
  | join l r hl hr => simp [comparisonRun, eval, hl, hr]

theorem MergeTree.comparisonRun_le (le : α → α → Bool) (t : MergeTree α) :
    (t.comparisonRun le).2 ≤ t.size * t.height := by
  induction t with
  | leaf => simp [comparisonRun, height]
  | join l r hl hr =>
    have hm := mergeComparisonRun_le le (l.comparisonRun le).1 (r.comparisonRun le).1
    simp only [comparisonRun_result, eval_length] at hm
    have h1 := Nat.le_max_left l.height r.height
    have h2 := Nat.le_max_right l.height r.height
    simp only [comparisonRun, size, height, comparisonRun_result]
    nlinarith

def scanComparisonRun (le : α → α → Bool) :
    List α → List α → Option Bool → List (List α) → List (List α) × Nat
  | [], current, direction, done =>
    ((if current.isEmpty then done else finishRun current direction :: done).reverse, 0)
  | x :: xs, [], _, done => scanComparisonRun le xs [x] none done
  | x :: xs, previous :: rest, none, done =>
    let result := scanComparisonRun le xs (x :: previous :: rest) (some (le previous x)) done
    (result.1, result.2 + 1)
  | x :: xs, previous :: rest, some ascending, done =>
    let result := if (if ascending then le previous x else !(le previous x)) then
      scanComparisonRun le xs (x :: previous :: rest) (some ascending) done
    else scanComparisonRun le xs [x] none (finishRun (previous :: rest) (some ascending) :: done)
    (result.1, result.2 + 1)

@[simp] theorem scanComparisonRun_result (le : α → α → Bool) (xs current : List α)
    (direction : Option Bool) (done : List (List α)) :
    (scanComparisonRun le xs current direction done).1 = scanRuns le xs current direction done := by
  induction xs generalizing current direction done with
  | nil => rfl
  | cons x xs ih =>
    cases current with
    | nil => exact ih _ _ _
    | cons p rest =>
      cases direction with
      | none => exact ih _ _ _
      | some d =>
        dsimp only [scanComparisonRun, scanRuns]
        by_cases h : (if d then le p x else !(le p x)) = true <;> simp [h, ih]

theorem scanComparisonRun_cost (le : α → α → Bool) (xs current : List α)
    (direction : Option Bool) (done : List (List α)) :
    (scanComparisonRun le xs current direction done).2 =
      if current.isEmpty then xs.length - 1 else xs.length := by
  induction xs generalizing current direction done with
  | nil => simp [scanComparisonRun]
  | cons x xs ih =>
    cases current with
    | nil => simpa [scanComparisonRun] using ih [x] none done
    | cons p rest =>
      cases direction with
      | none => simp [scanComparisonRun, ih]
      | some d =>
        dsimp only [scanComparisonRun]
        by_cases h : (if d then le p x else !(le p x)) = true <;> simp [h, ih]

def powerComparisonRun (le : α → α → Bool) (xs : List α) : List α × Nat :=
  let scanned := scanComparisonRun le xs [] none []
  match scanned.1 with
  | [] => ([], scanned.2)
  | first :: rest =>
    let result := (scheduleTree xs.length rest 0 first []).comparisonRun le
    (result.1, scanned.2 + result.2)

@[simp] theorem powerComparisonRun_result (le : α → α → Bool) (xs : List α) :
    (powerComparisonRun le xs).1 = powerSortBy le xs := by
  simp only [powerComparisonRun, scanComparisonRun_result, powerSortBy, naturalRuns]
  split <;> simp_all [MergeTree.comparisonRun_result, scheduleTree_eval]

def powerComparisonCost (le : α → α → Bool) (xs : List α) : Nat :=
  (powerComparisonRun le xs).2

theorem powerComparisonCost_le (le : α → α → Bool) (xs : List α) :
    powerComparisonCost le xs ≤ xs.length * (xs.length.log2 + 2) := by
  have hp := naturalRuns_perm le xs
  have hn := naturalRuns_nonempty le xs
  unfold powerComparisonCost powerComparisonRun
  simp only [scanComparisonRun_result, scanComparisonRun_cost, List.isEmpty_nil, ite_true]
  change (match naturalRuns le xs with
    | [] => ([], xs.length - 1)
    | first :: rest =>
      ((scheduleTree xs.length rest 0 first []).comparisonRun le).1 |> fun result =>
        (result, xs.length - 1 + ((scheduleTree xs.length rest 0 first []).comparisonRun le).2)).2 ≤ _
  cases he : naturalRuns le xs with
  | nil =>
    have hz : xs = [] := List.perm_nil.mp (by simpa [he] using hp.symm)
    simp [hz]
  | cons first rest =>
    have hlen : first.length + rest.flatten.length = xs.length := by simpa [he] using hp.length_eq
    have hf : 0 < first.length := List.length_pos_iff.mpr (hn first (by simp [he]))
    have ht := scheduleTree_height (by omega : 0 < xs.length) rest 0 first [] hf
      (fun r hr => List.length_pos_iff.mpr (hn r (by simp [he, hr]))) (by omega) (.nil _)
    have hs : (scheduleTree xs.length rest 0 first []).size = xs.length := by
      rw [← MergeTree.eval_length le, scheduleTree_eval]
      have h := (mergeRuns_perm le xs.length rest 0 first []).length_eq
      simp only [stackValues, List.map_nil, List.flatten_nil, List.nil_append,
        List.length_append] at h
      exact h.trans hlen
    have hc := MergeTree.comparisonRun_le le (scheduleTree xs.length rest 0 first [])
    simp only [hs, maxPower] at hc ht
    have hscan : xs.length - 1 ≤ xs.length := Nat.sub_le _ _
    dsimp only
    nlinarith

end LeanSort.Power
