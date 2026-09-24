import LeanSort.Verification.Intro.Correctness
import LeanSort.Verification.Heap.Cost
import Mathlib.Tactic.Linarith

/-! Exact key-comparison instrumentation. Partition predicates, insertion leaves,
and all heap construction/extraction comparisons are counted. Length tests,
allocation, concatenation, and trace checking are outside this cost model. -/

namespace LeanSort.Intro

variable {α : Type} [LinearOrder α]

def insertRun (x : α) : List α → List α × Nat
  | [] => ([x], 0)
  | y :: ys =>
    if x ≤ y then (x :: y :: ys, 1)
    else let rest := insertRun x ys; (y :: rest.1, rest.2 + 1)

def insertionRun : List α → List α × Nat
  | [] => ([], 0)
  | x :: xs =>
    let rest := insertionRun xs
    let placed := insertRun x rest.1
    (placed.1, rest.2 + placed.2)

@[simp] theorem insertRun_result (x : α) (xs : List α) :
    (insertRun x xs).1 = xs.orderedInsert (· ≤ ·) x := by
  induction xs with
  | nil => rfl
  | cons y ys ih => simp [insertRun, List.orderedInsert, ih]; split <;> rfl

@[simp] theorem insertionRun_result (xs : List α) :
    (insertionRun xs).1 = xs.insertionSort (· ≤ ·) := by
  induction xs with
  | nil => rfl
  | cons x xs ih => simp [insertionRun, ih]

theorem insertRun_comparisons_le (x : α) (xs : List α) :
    (insertRun x xs).2 ≤ xs.length := by
  induction xs with
  | nil => simp [insertRun]
  | cons y ys ih => simp only [insertRun]; split <;> simp_all

theorem insertionRun_comparisons_le (xs : List α) :
    (insertionRun xs).2 ≤ xs.length * xs.length := by
  induction xs with
  | nil => simp [insertionRun]
  | cons x xs ih =>
    have h := insertRun_comparisons_le x (insertionRun xs).1
    simp only [insertionRun_result, List.length_insertionSort] at h
    simp only [insertionRun, List.length_cons, insertionRun_result]
    nlinarith

def comparisonRun (cutoff : Nat) : Nat → List α → List α × Nat
  | 0, xs => LeanSort.Heap.heapComparisonRun xs
  | depth + 1, xs =>
    if xs.length ≤ cutoff then insertionRun xs else
      match xs with
      | [] => ([], 0)
      | p :: rest =>
        let parts := rest.partition (fun x => decide (x ≤ p))
        let l := comparisonRun cutoff depth parts.1
        let r := comparisonRun cutoff depth parts.2
        (l.1 ++ p :: r.1, rest.length + l.2 + r.2)

@[simp] theorem comparisonRun_result (cutoff depth : Nat) (xs : List α) :
    (comparisonRun cutoff depth xs).1 = introSortAux cutoff depth xs := by
  induction depth generalizing xs with
  | zero => exact LeanSort.Heap.heapComparisonRun_result xs
  | succ depth ih =>
    cases xs <;> simp [comparisonRun, introSortAux, ih]
    split <;> simp

private theorem log2_mono {m n : Nat} (h : m ≤ n) : m.log2 ≤ n.log2 := by
  by_cases hm : m = 0
  · simp [hm]
  · exact (Nat.le_log2 (by omega)).2 ((Nat.le_log2 hm).1 (Nat.le_refl _) |>.trans h)

/-- The same original-size bound is carried through both branches. This avoids
any balance assumption on first-pivot partitions, including all-equal inputs. -/
theorem comparisonRun_bound (cutoff depth n : Nat) (xs : List α) (hn : xs.length ≤ n) :
    (comparisonRun cutoff depth xs).2 ≤ xs.length * (depth + cutoff + 4 * (n.log2 + 1)) := by
  induction depth generalizing xs with
  | zero =>
    have h := LeanSort.Heap.heapComparisonCost_le xs
    have hm := log2_mono hn
    change LeanSort.Heap.heapComparisonCost xs ≤ _
    nlinarith
  | succ depth ih =>
    by_cases h : xs.length ≤ cutoff
    · simp only [comparisonRun, h, ite_true]
      have hc := insertionRun_comparisons_le xs
      have hm := Nat.mul_le_mul_left xs.length h
      nlinarith
    · cases xs with
      | nil => simp at h
      | cons p rest =>
        have hp := partition_lengths p rest
        have hl := ih (rest.partition (fun x => decide (x ≤ p))).1 (by simp only [List.length_cons] at hn; omega)
        have hr := ih (rest.partition (fun x => decide (x ≤ p))).2 (by simp only [List.length_cons] at hn; omega)
        simp only [List.length_cons] at h
        simp only [comparisonRun, ite_eq_right h, List.length_cons]
        nlinarith

def introComparisonCost (xs : List α) : Nat :=
  (comparisonRun insertionCutoff (depthLimit xs.length) xs).2

theorem introComparisonCost_le (xs : List α) :
    introComparisonCost xs ≤ xs.length * (6 * xs.length.log2 + 20) := by
  have h := comparisonRun_bound insertionCutoff (depthLimit xs.length) xs.length xs le_rfl
  dsimp [insertionCutoff, depthLimit] at h
  unfold introComparisonCost
  dsimp [insertionCutoff, depthLimit]
  nlinarith

end LeanSort.Intro
