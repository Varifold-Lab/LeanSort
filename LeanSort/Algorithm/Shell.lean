import Mathlib.Data.List.Sort

/-! Shell sort with the original halving gap sequence, implemented on arrays. -/

namespace LeanSort.Shell

/-- Insert one entry into its gap-separated column. A zero gap is a no-op. -/
def gapInsert {α : Type*} [LinearOrder α] (gap : ℕ) (xs : Array α) (i : ℕ) : Array α :=
  if h : 0 < gap ∧ gap ≤ i ∧ i < xs.size then
    if xs[i] < xs[i - gap] then
      gapInsert gap (xs.swap i (i - gap)) (i - gap)
    else xs
  else xs
termination_by i
decreasing_by omega

/-- One gapped insertion-sort pass. -/
def gapPass {α : Type*} [LinearOrder α] (gap : ℕ) (xs : Array α) : Array α :=
  (List.range xs.size).foldl (gapInsert gap) xs

/-- Positive gaps obtained by repeated halving, ending at one. -/
def gaps (n : ℕ) : List ℕ :=
  if n = 0 then [] else n :: gaps (n / 2)
termination_by n
decreasing_by omega

def shellSortResult {α : Type*} [LinearOrder α] (xs : List α) : List α :=
  ((gaps (xs.length / 2)).foldl (fun a gap => gapPass gap a) xs.toArray).toList

end LeanSort.Shell
