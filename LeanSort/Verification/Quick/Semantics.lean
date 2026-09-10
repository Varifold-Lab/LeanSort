import LeanSort.Verification.Quick.Trace

/-! Relational semantics, specified by local order rules rather than execution
equality. The equivalence theorems connect these rules to execution and replay. -/

namespace LeanSort.Quick

/-- Each rule consumes one input occurrence and records its legal destination.
The constructors preserve relative order within each partition. -/
inductive PartitionDerivation {α : Type*} [LinearOrder α] (p : α) :
    List α → List α → List α → List Bool → Prop where
  | nil : PartitionDerivation p [] [] [] []
  | left {x xs l r ds} : x ≤ p → PartitionDerivation p xs l r ds →
      PartitionDerivation p (x :: xs) (x :: l) r (true :: ds)
  | right {x xs l r ds} : p < x → PartitionDerivation p xs l r ds →
      PartitionDerivation p (x :: xs) l (x :: r) (false :: ds)

theorem PartitionDerivation.execution {α : Type*} [LinearOrder α]
    {p : α} {xs l r : List α} {ds : List Bool}
    (h : PartitionDerivation p xs l r ds) : partitionTr p xs = ((l, r), ds) := by
  induction h with
  | nil => rfl
  | left h _ ih => simp [partitionTr, ih, h]
  | right h _ ih => simp [partitionTr, ih, not_le_of_gt h]

theorem partitionTr_derivation {α : Type*} [LinearOrder α] (p : α) (xs : List α) :
    PartitionDerivation p xs (partitionTr p xs).1.1 (partitionTr p xs).1.2
      (partitionTr p xs).2 := by
  induction xs with
  | nil => exact .nil
  | cons x xs ih =>
      by_cases h : x ≤ p
      · simpa only [partitionTr, ite_eq_left h] using PartitionDerivation.left h ih
      · simpa only [partitionTr, ite_eq_right h] using
          PartitionDerivation.right (lt_of_not_ge h) ih

theorem partitionDerivation_iff {α : Type*} [LinearOrder α]
    (p : α) (xs l r : List α) (ds : List Bool) :
    PartitionDerivation p xs l r ds ↔ partitionTr p xs = ((l, r), ds) := by
  refine ⟨PartitionDerivation.execution, ?_⟩
  intro h
  simpa only [h] using partitionTr_derivation p xs

theorem PartitionDerivation.spec {α : Type*} [LinearOrder α]
    {p : α} {xs l r : List α} {ds : List Bool}
    (h : PartitionDerivation p xs l r ds) : PartitionSpec p xs l r := by
  have he := congrArg Prod.fst h.execution
  rw [partitionTr_eq] at he
  change xs.partition (fun x => decide (x ≤ p)) = (l, r) at he
  have hs := partition_spec p xs
  simpa only [he] using hs

/-- A quicksort derivation partitions around the first pivot, derives both
recursive results, and joins them around that pivot. No rule invokes the sorter. -/
inductive QuickDerivation {α : Type*} [LinearOrder α] :
    List α → Trace → List α → Prop where
  | empty : QuickDerivation [] .empty []
  | node {p xs l r ds lt rt lo ro} :
      PartitionDerivation p xs l r ds →
      QuickDerivation l lt lo → QuickDerivation r rt ro →
      QuickDerivation (p :: xs) (.node ds lt rt) (lo ++ p :: ro)

theorem QuickDerivation.execution {α : Type*} [LinearOrder α]
    {xs output : List α} {trace : Trace} (h : QuickDerivation xs trace output) :
    quickSortTr xs = (output, trace) := by
  induction h with
  | empty => exact quickSortTr_nil
  | node hp _ _ ihl ihr => rw [quickSortTr, hp.execution, ihl, ihr]

theorem quickSortTr_derivation {α : Type*} [LinearOrder α] (xs : List α) :
    QuickDerivation xs (quickSortTr xs).2 (quickSortTr xs).1 := by
  induction xs using quickSortResult_induct with
  | case1 => simpa only [quickSortTr_nil] using (QuickDerivation.empty (α := α))
  | case2 p xs ihl ihr =>
      rw [quickSortTr_cons]
      apply QuickDerivation.node _ ihl ihr
      simpa only [partitionTr_eq] using partitionTr_derivation p xs

theorem quickDerivation_iff {α : Type*} [LinearOrder α]
    (xs output : List α) (trace : Trace) :
    QuickDerivation xs trace output ↔ quickSortTr xs = (output, trace) := by
  refine ⟨QuickDerivation.execution, ?_⟩
  intro h
  simpa only [h] using quickSortTr_derivation xs

/-- The checker accepts exactly the independently specified legal derivations. -/
theorem replayChecked?_iff_derivation {α : Type*} [LinearOrder α]
    (trace : Trace) (xs output : List α) :
    replayChecked? trace xs = some output ↔ QuickDerivation xs trace output :=
  (replayChecked?_iff trace xs output).trans (quickDerivation_iff xs output trace).symm

theorem QuickDerivation.spec {α : Type*} [LinearOrder α]
    {xs output : List α} {trace : Trace} (h : QuickDerivation xs trace output) :
    IsSortingResult (· ≤ ·) xs output :=
  replayChecked?_spec trace xs output ((replayChecked?_iff_derivation trace xs output).mpr h)

theorem QuickDerivation.deterministic {α : Type*} [LinearOrder α]
    {xs out₁ out₂ : List α} {t₁ t₂ : Trace}
    (h₁ : QuickDerivation xs t₁ out₁) (h₂ : QuickDerivation xs t₂ out₂) :
    out₁ = out₂ ∧ t₁ = t₂ := by
  exact Prod.mk.inj (h₁.execution.symm.trans h₂.execution)

theorem Certificate.derivation {α : Type*} [LinearOrder α] {xs : List α}
    (c : Certificate xs) : QuickDerivation xs c.trace c.output :=
  (quickDerivation_iff xs c.output c.trace).mpr c.execution

end LeanSort.Quick
