import LeanSort.Verification.MergeSearch.Checks
open LeanSort.MergeSearch
set_option maxRecDepth 100000
set_option maxHeartbeats 0
def ls : List Nat := [5, 4, 6, 5, 2, 3, 151, 6]
def tab : Table := #[#[0,0,9,24,40,51,64,240,403],#[0,0,0,10,25,34,45,216,379],#[0,0,0,0,11,20,31,198,361],#[0,0,0,0,0,7,15,176,339],#[0,0,0,0,0,0,5,161,323],#[0,0,0,0,0,0,0,154,314],#[0,0,0,0,0,0,0,0,157],#[0,0,0,0,0,0,0,0,0],#[0,0,0,0,0,0,0,0,0]]
def winner : Shape := (Shape.node (Shape.node (Shape.node (Shape.node (Shape.leaf 0) (Shape.leaf 1)) (Shape.leaf 2)) (Shape.node (Shape.leaf 3) (Shape.node (Shape.leaf 4) (Shape.leaf 5)))) (Shape.node (Shape.leaf 6) (Shape.leaf 7)))
theorem optimal : Optimal (weights ls) ls.length winner := checkOptimal_sound (d := tab) (by decide)
def candidates : List Shape := [(Shape.node (Shape.node (Shape.node (Shape.node (Shape.leaf 0) (Shape.leaf 1)) (Shape.leaf 2)) (Shape.node (Shape.leaf 3) (Shape.node (Shape.leaf 4) (Shape.leaf 5)))) (Shape.node (Shape.leaf 6) (Shape.leaf 7))),(Shape.node (Shape.node (Shape.node (Shape.leaf 0) (Shape.leaf 1)) (Shape.node (Shape.leaf 2) (Shape.leaf 3))) (Shape.node (Shape.node (Shape.leaf 4) (Shape.leaf 5)) (Shape.node (Shape.leaf 6) (Shape.leaf 7))))]
theorem feasible : candidates.all (fun t => checkFits t 0 ls.length) = true := by decide
#print axioms optimal
#print axioms feasible
