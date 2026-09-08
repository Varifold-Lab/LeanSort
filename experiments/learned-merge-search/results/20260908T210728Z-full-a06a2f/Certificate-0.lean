import LeanSort.Verification.MergeSearch.Checks
open LeanSort.MergeSearch
set_option maxRecDepth 100000
set_option maxHeartbeats 0
def ls : List Nat := []
def tab : Table := #[#[0]]
def winner : Shape := Shape.empty
theorem optimal : Optimal (weights ls) ls.length winner := checkOptimal_sound (d := tab) (by decide)
def candidates : List Shape := [Shape.empty]
theorem feasible : candidates.all (fun t => checkFits t 0 ls.length) = true := by decide
#print axioms optimal
#print axioms feasible
