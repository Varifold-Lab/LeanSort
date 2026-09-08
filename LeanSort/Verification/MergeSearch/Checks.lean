import LeanSort.Verification.MergeSearch.Certificate

namespace LeanSort.MergeSearch

def smallTable : Table := #[#[0,0,2,20],#[0,0,0,17],#[0,0,0,0],#[0,0,0,0]]
def smallTree : Shape := .node (.node (.leaf 0) (.leaf 1)) (.leaf 2)

example : Optimal (weights [1,1,16]) 3 smallTree := checkOptimal_sound (d := smallTable) (by decide)
example : checkOptimal ([] : List Nat) #[#[0]] .empty = true := by decide
example : checkOptimal [7] #[#[0,0],#[0,0]] (.leaf 0) = true := by decide
example : checkFits (.node (.leaf 1) (.leaf 0)) 0 2 = false := by decide
example : checkFits (.node .empty (.leaf 0)) 0 1 = false := by decide
example : checkFits (.node (.leaf 0) (.leaf 0)) 0 2 = false := by decide
example : checkOptimal [1,1,16] #[#[0,0,2,21],#[0,0,0,17],#[0,0,0,0],#[0,0,0,0]] smallTree = false := by decide
example : checkLower [1,1,16] #[#[0,0,2,21],#[0,0,0,17],#[0,0,0,0],#[0,0,0,0]] = false := by decide

theorem realize_budget_lengths (runs : List (List α)) (s : Shape) :
    (realize runs s).budget = s.budget (weights (runs.map List.length)) := by
  rw [realize_budget]
  congr 1
  funext i
  simp only [weights, List.getElem?_map]
  cases runs[i]? <;> rfl

theorem certified_budget_minimum (runs : List (List α)) (s t : Shape) (d : Table)
    (h : checkOptimal (runs.map List.length) d s = true)
    (ht : Fits t 0 runs.length) : (realize runs s).budget ≤ (realize runs t).budget := by
  rw [realize_budget_lengths, realize_budget_lengths]
  exact (checkOptimal_sound h).2 t (by simpa using ht)

end LeanSort.MergeSearch
