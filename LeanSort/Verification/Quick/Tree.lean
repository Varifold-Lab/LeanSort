import LeanSort.Verification.Quick.Complexity

/-! Structural interpretation of comparison cost. A pivot at depth d has passed
through d ancestor partitions, so it has already participated in d comparisons. -/

namespace LeanSort.Quick

/-- Number of pivot levels on a longest branch; an empty call has height zero. -/
def Trace.height : Trace → Nat
  | .empty => 0
  | .node _ left right => max left.height right.height + 1

/-- Sum of the depths of all pivot occurrences, given the root's depth.
Unlike `comparisons`, this ignores the supplied decision lists entirely. -/
def Trace.depthSum : Trace → Nat → Nat
  | .empty, _ => 0
  | .node _ left right, d => d + left.depthSum (d + 1) + right.depthSum (d + 1)

theorem Trace.depthSum_offset (t : Trace) (d : Nat) :
    t.depthSum d = t.depthSum 0 + d * t.pivots := by
  induction t generalizing d with
  | empty => simp [depthSum, pivots]
  | node ds left right ihl ihr =>
      simp only [depthSum, pivots]
      rw [ihl (d + 1), ihr (d + 1), ihl (0 + 1), ihr (0 + 1)]
      nlinarith

theorem Trace.depthSum_node (ds : List Bool) (left right : Trace) :
    (Trace.node ds left right).depthSum 0 =
      left.depthSum 0 + right.depthSum 0 + left.pivots + right.pivots := by
  simp only [depthSum]
  rw [left.depthSum_offset 1, right.depthSum_offset 1]
  omega

/-- Depth totals are controlled by tree height, for arbitrary tree shapes. -/
theorem Trace.depthSum_le_height (t : Trace) :
    t.depthSum 0 + t.pivots ≤ t.pivots * t.height := by
  induction t with
  | empty => simp [depthSum, pivots, height]
  | node ds left right ihl ihr =>
      rw [depthSum_node]
      simp only [pivots, height]
      have hl := Nat.mul_le_mul_left left.pivots (Nat.le_max_left left.height right.height)
      have hr := Nat.mul_le_mul_left right.pivots (Nat.le_max_right left.height right.height)
      nlinarith [Nat.zero_le (max left.height right.height)]

theorem Trace.height_le_pivots (t : Trace) : t.height ≤ t.pivots := by
  induction t with
  | empty => simp [height, pivots]
  | node ds left right ihl ihr => simp only [height, pivots]; omega

/-- For generated traces, decision count equals the sum of pivot depths.
This need not hold for malformed trees with arbitrary decision-list lengths. -/
theorem comparisonCost_eq_depthSum {α : Type*} [LinearOrder α] (xs : List α) :
    comparisonCost xs = (quickSortTr xs).2.depthSum 0 := by
  induction xs using quickSortResult_induct with
  | case1 => simp [Trace.depthSum]
  | case2 p xs ihl ihr =>
      rw [comparisonCost_cons, quickSortTr_cons]
      simp only [Trace.depthSum_node, quickSortTr_pivots]
      have h := (partition_spec p xs).perm.length_eq
      simp only [List.length_append] at h
      omega

/-- Height bounds translate directly into comparison bounds. -/
theorem comparisonCost_le_height {α : Type*} [LinearOrder α] (xs : List α) :
    comparisonCost xs + xs.length ≤ xs.length * (quickSortTr xs).2.height := by
  simpa only [← comparisonCost_eq_depthSum, quickSortTr_pivots] using
    (quickSortTr xs).2.depthSum_le_height

/-- The left-branch worst cases have one pivot level per input occurrence. -/
theorem height_of_nonincreasing {α : Type*} [LinearOrder α]
    (xs : List α) (h : xs.Pairwise (· ≥ ·)) : (quickSortTr xs).2.height = xs.length := by
  induction xs with
  | nil => simp [Trace.height]
  | cons p xs ih =>
      obtain ⟨hp, ht⟩ := List.pairwise_cons.mp h
      rw [quickSortTr_cons, partition_eq_left p xs hp]
      simp [Trace.height, ih ht]

theorem height_of_strictlyIncreasing {α : Type*} [LinearOrder α]
    (xs : List α) (h : xs.Pairwise (· < ·)) : (quickSortTr xs).2.height = xs.length := by
  induction xs with
  | nil => simp [Trace.height]
  | cons p xs ih =>
      obtain ⟨hp, ht⟩ := List.pairwise_cons.mp h
      rw [quickSortTr_cons, partition_eq_right p xs hp]
      simp [Trace.height, ih ht]

theorem height_replicate {α : Type*} [LinearOrder α] (p : α) (n : Nat) :
    (quickSortTr (List.replicate n p)).2.height = n := by
  simpa using height_of_nonincreasing (List.replicate n p)
    (List.pairwise_replicate.mpr (Or.inr le_rfl))

end LeanSort.Quick
