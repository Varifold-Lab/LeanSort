import LeanSort.Verification.MergeSearch.Checks
open LeanSort.MergeSearch
set_option maxRecDepth 100000
set_option maxHeartbeats 0
def ls : List Nat := [7, 5, 8, 35]
def tab : Table := #[#[0,0,12,32,87],#[0,0,0,13,61],#[0,0,0,0,43],#[0,0,0,0,0],#[0,0,0,0,0]]
def winner : Shape := (Shape.node (Shape.node (Shape.node (Shape.leaf 0) (Shape.leaf 1)) (Shape.leaf 2)) (Shape.leaf 3))
theorem optimal : Optimal (weights ls) ls.length winner := checkOptimal_sound (d := tab) (by decide)
def candidates : List Shape := [(Shape.node (Shape.node (Shape.node (Shape.leaf 0) (Shape.leaf 1)) (Shape.leaf 2)) (Shape.leaf 3)),(Shape.node (Shape.node (Shape.leaf 0) (Shape.leaf 1)) (Shape.node (Shape.leaf 2) (Shape.leaf 3)))]
theorem feasible : candidates.all (fun t => checkFits t 0 ls.length) = true := by decide
#print axioms optimal
#print axioms feasible
