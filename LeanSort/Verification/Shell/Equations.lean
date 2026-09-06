import LeanSort.Algorithm.Shell

namespace LeanSort.Shell

theorem gapInsert_eq {α : Type*} [LinearOrder α] (gap : ℕ) (xs : Array α) (i : ℕ) :
    gapInsert gap xs i =
      if h : 0 < gap ∧ gap ≤ i ∧ i < xs.size then
        if xs[i] < xs[i - gap] then gapInsert gap (xs.swap i (i - gap)) (i - gap)
        else xs
      else xs := by rw [gapInsert]

@[simp] theorem gapInsert_zero {α : Type*} [LinearOrder α] (xs : Array α) (i : ℕ) :
    gapInsert 0 xs i = xs := by rw [gapInsert]; simp

@[simp] theorem gaps_zero : gaps 0 = [] := by rw [gaps]; simp

theorem gaps_of_pos (n : ℕ) (h : 0 < n) : gaps n = n :: gaps (n / 2) := by
  rw [gaps]; simp [Nat.ne_of_gt h]

@[simp] theorem gaps_one : gaps 1 = [1] := by rw [gaps_of_pos 1 (by decide)]; simp

theorem gapInsertTrace_result {α : Type*} [LinearOrder α] (gap : ℕ) (xs : Array α) (i : ℕ) :
    (gapInsertTrace gap xs i).1 = gapInsert gap xs i := by
  fun_induction gapInsertTrace with
  | case1 xs i h hlt result rest he ih =>
      rw [gapInsert_eq]
      simpa [h, hlt, he] using ih
  | case2 xs i h hlt => rw [gapInsert_eq]; simp [h, hlt]
  | case3 xs i h => rw [gapInsert_eq]; simp [h]

theorem insertionsTrace_result {α : Type*} [LinearOrder α]
    (gap : ℕ) (indices : List ℕ) (xs : Array α) :
    (insertionsTrace gap indices xs).1 = indices.foldl (gapInsert gap) xs := by
  induction indices generalizing xs with
  | nil => rfl
  | cons i indices ih => simp [insertionsTrace, ih, gapInsertTrace_result]

theorem gapPassTrace_result {α : Type*} [LinearOrder α] (gap : ℕ) (xs : Array α) :
    (gapPassTrace gap xs).1 = gapPass gap xs := insertionsTrace_result _ _ _

theorem passesTrace_result {α : Type*} [LinearOrder α] (steps : List ℕ) (xs : Array α) :
    (passesTrace steps xs).1 = steps.foldl (fun a gap => gapPass gap a) xs := by
  induction steps generalizing xs with
  | nil => rfl
  | cons gap steps ih => simp [passesTrace, ih, gapPassTrace_result]

theorem sortTrace_result {α : Type*} [LinearOrder α] (xs : List α) :
    (sortTrace xs).1 = shellSortResult xs := by
  simp [sortTrace, shellSortResult, passesTrace_result]

end LeanSort.Shell
