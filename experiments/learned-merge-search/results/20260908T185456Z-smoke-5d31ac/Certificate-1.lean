import LeanSort.Verification.MergeSearch.Checks
open LeanSort.MergeSearch
set_option maxRecDepth 100000
set_option maxHeartbeats 0
def ls : List Nat := [7]
def tab : Table := #[#[0,0],#[0,0]]
def winner : Shape := (Shape.leaf 0)
theorem optimal : Optimal (weights ls) ls.length winner := checkOptimal_sound (d := tab) (by decide)
def candidates : List Shape := [(Shape.leaf 0)]
theorem feasible : candidates.all (fun t => checkFits t 0 ls.length) = true := by decide
#print axioms optimal
#print axioms feasible
