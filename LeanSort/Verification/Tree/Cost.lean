import LeanSort.Verification.Tree.Semantics
import Mathlib.Data.Nat.Choose.Basic

/-! Key comparisons during construction and node visits during traversal.
These are operation counts, not measurements of allocation or elapsed time. -/

namespace LeanSort.Tree

variable {α : Type*} [LinearOrder α]

/-- Each occupied node inspected by insertion contributes exactly one `<` test. -/
def buildComparisons : List α → SearchTree α → Nat
  | [], _ => 0
  | x :: xs, t => (insertionPath x t).length + buildComparisons xs (insert x t)

def treeComparisonCost (xs : List α) : Nat := buildComparisons xs .empty

theorem buildComparisons_eq_trace (xs : List α) (t : SearchTree α) :
    buildComparisons xs t = ((buildTrace xs t).2.map List.length).sum := by
  induction xs generalizing t with
  | nil => rfl
  | cons x xs ih => simp [buildComparisons, buildTrace, ih]

theorem treeComparisonCost_eq_trace (xs : List α) :
    treeComparisonCost xs = ((treeSortTrace xs).map List.length).sum :=
  buildComparisons_eq_trace xs .empty

theorem Certificate.comparisons {xs : List α} (c : Certificate xs) :
    (c.trace.map List.length).sum = treeComparisonCost xs := by
  rw [c.trace_eq, treeComparisonCost_eq_trace]

theorem insertionPath_length_le_height (x : α) (t : SearchTree α) :
    (insertionPath x t).length ≤ height t := by
  induction t with
  | empty => simp [insertionPath, height]
  | node l v r ihl ihr =>
      simp only [insertionPath, height]
      split <;> simp only [List.length_cons] <;> omega

theorem insertionPath_length_le_nodeCount (x : α) (t : SearchTree α) :
    (insertionPath x t).length ≤ nodeCount t :=
  (insertionPath_length_le_height x t).trans (height_le_nodeCount t)

/-- A seeded tree of size `s` costs at most `n*s + n choose 2` comparisons
for the next `n` insertions. No balance assumption is used. -/
theorem buildComparisons_le (xs : List α) (t : SearchTree α) :
    buildComparisons xs t ≤ xs.length * nodeCount t + xs.length.choose 2 := by
  induction xs generalizing t with
  | nil => simp [buildComparisons]
  | cons x xs ih =>
      have hc := insertionPath_length_le_nodeCount x t
      have hr := ih (insert x t)
      simp only [nodeCount_insert] at hr
      simp only [buildComparisons, List.length_cons, Nat.choose_succ_succ,
        Nat.choose_one_right]
      change (insertionPath x t).length + buildComparisons xs (insert x t) ≤
        (xs.length + 1) * nodeCount t + (xs.length + xs.length.choose 2)
      simp only [Nat.mul_add, Nat.add_mul, Nat.mul_one, Nat.one_mul] at hr ⊢
      omega

theorem treeComparisonCost_le (xs : List α) :
    treeComparisonCost xs ≤ xs.length.choose 2 := by
  simpa [treeComparisonCost, nodeCount] using buildComparisons_le xs .empty

theorem treeComparisonCost_le_triangular (xs : List α) :
    treeComparisonCost xs ≤ xs.length * (xs.length - 1) / 2 := by
  simpa [Nat.choose_two_right] using treeComparisonCost_le xs

/-- The right spine formed by inserting repeated copies of the same key. -/
def rightChain (x : α) : Nat → SearchTree α
  | 0 => .empty
  | n + 1 => .node .empty x (rightChain x n)

@[simp] theorem insert_rightChain (x : α) (n : Nat) :
    insert x (rightChain x n) = rightChain x (n + 1) := by
  induction n with
  | zero => rfl
  | succ n ih => simp [rightChain, insert, ih]

@[simp] theorem insertionPath_rightChain_length (x : α) (n : Nat) :
    (insertionPath x (rightChain x n)).length = n := by
  induction n with
  | zero => rfl
  | succ n ih => simp [rightChain, insertionPath, ih]

theorem buildComparisons_replicate (x : α) (n m : Nat) :
    buildComparisons (List.replicate n x) (rightChain x m) = n * m + n.choose 2 := by
  induction n generalizing m with
  | zero => simp [buildComparisons]
  | succ n ih =>
      simp only [List.replicate_succ, buildComparisons, insertionPath_rightChain_length,
        insert_rightChain, ih, Nat.choose_succ_succ, Nat.choose_one_right]
      change m + (n * (m + 1) + n.choose 2) = (n + 1) * m + (n + n.choose 2)
      simp only [Nat.mul_add, Nat.add_mul, Nat.mul_one, Nat.one_mul]
      omega

/-- All-equal inputs attain the comparison upper bound, including at n = 0, 1. -/
theorem treeComparisonCost_replicate (x : α) (n : Nat) :
    treeComparisonCost (List.replicate n x) = n.choose 2 := by
  simpa [treeComparisonCost, rightChain] using buildComparisons_replicate x n 0

/-- Count occupied-node visits in the final in-order traversal, excluding
empty leaves and the comparisons already charged during construction. -/
def treeTraversalCost (xs : List α) : Nat := nodeCount (fromList xs)

@[simp] theorem treeTraversalCost_eq_length (xs : List α) :
    treeTraversalCost xs = xs.length := fromList_nodeCount xs

end LeanSort.Tree
