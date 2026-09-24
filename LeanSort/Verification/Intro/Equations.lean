import LeanSort.Algorithm.Intro
import LeanSort.Verification.Quick.Trace

namespace LeanSort.Intro

variable {α : Type} [LinearOrder α]

@[simp] theorem introSortAux_zero (cutoff : Nat) (xs : List α) :
    introSortAux cutoff 0 xs = LeanSort.Heap.heapSortResult xs := rfl

theorem introSortAux_small (cutoff depth : Nat) (xs : List α) (h : xs.length ≤ cutoff) :
    introSortAux cutoff (depth + 1) xs = xs.insertionSort (· ≤ ·) := by
  simp [introSortAux, h]

theorem introSortAux_partition (cutoff depth : Nat) (pivot : α) (rest : List α)
    (h : cutoff < (pivot :: rest).length) :
    introSortAux cutoff (depth + 1) (pivot :: rest) =
      introSortAux cutoff depth (rest.partition (fun x => decide (x ≤ pivot))).1 ++
      pivot :: introSortAux cutoff depth (rest.partition (fun x => decide (x ≤ pivot))).2 := by
  simp only [introSortAux, ite_eq_right (Nat.not_le.mpr h)]

theorem partition_lengths (pivot : α) (rest : List α) :
    (rest.partition (fun x => decide (x ≤ pivot))).1.length +
      (rest.partition (fun x => decide (x ≤ pivot))).2.length = rest.length := by
  simpa using (LeanSort.Quick.partition_spec pivot rest).perm.length_eq

end LeanSort.Intro
