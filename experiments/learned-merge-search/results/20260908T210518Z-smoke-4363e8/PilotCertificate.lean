import LeanSort.Verification.MergeSearch.Checks
open LeanSort.MergeSearch
set_option maxRecDepth 100000
set_option maxHeartbeats 0
def ls : List Nat := [10, 4, 12, 85]
def tab : Table := #[#[0,0,14,40,151],#[0,0,0,16,117],#[0,0,0,0,97],#[0,0,0,0,0],#[0,0,0,0,0]]
def winner : Shape := (Shape.node (Shape.node (Shape.node (Shape.leaf 0) (Shape.leaf 1)) (Shape.leaf 2)) (Shape.leaf 3))
theorem optimal : Optimal (weights ls) ls.length winner := checkOptimal_sound (d := tab) (by decide)
def candidates : List Shape := [(Shape.node (Shape.node (Shape.node (Shape.leaf 0) (Shape.leaf 1)) (Shape.leaf 2)) (Shape.leaf 3))]
theorem feasible : candidates.all (fun t => checkFits t 0 ls.length) = true := by decide
#print axioms optimal
#print axioms feasible
