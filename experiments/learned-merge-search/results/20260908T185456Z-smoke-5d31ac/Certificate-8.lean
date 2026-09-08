import LeanSort.Verification.MergeSearch.Checks
open LeanSort.MergeSearch
set_option maxRecDepth 100000
set_option maxHeartbeats 0
def ls : List Nat := [61, 91, 44, 66, 3, 18, 71, 38]
def tab : Table := #[#[0,0,152,331,524,599,674,931,1132],#[0,0,0,135,311,386,461,694,879],#[0,0,0,0,110,182,239,425,588],#[0,0,0,0,0,69,108,266,413],#[0,0,0,0,0,0,21,113,243],#[0,0,0,0,0,0,0,89,216],#[0,0,0,0,0,0,0,0,109],#[0,0,0,0,0,0,0,0,0],#[0,0,0,0,0,0,0,0,0]]
def winner : Shape := (Shape.node (Shape.node (Shape.leaf 0) (Shape.leaf 1)) (Shape.node (Shape.node (Shape.leaf 2) (Shape.node (Shape.leaf 3) (Shape.node (Shape.leaf 4) (Shape.leaf 5)))) (Shape.node (Shape.leaf 6) (Shape.leaf 7))))
theorem optimal : Optimal (weights ls) ls.length winner := checkOptimal_sound (d := tab) (by decide)
def candidates : List Shape := [(Shape.node (Shape.node (Shape.leaf 0) (Shape.leaf 1)) (Shape.node (Shape.node (Shape.leaf 2) (Shape.node (Shape.leaf 3) (Shape.node (Shape.leaf 4) (Shape.leaf 5)))) (Shape.node (Shape.leaf 6) (Shape.leaf 7)))),(Shape.node (Shape.node (Shape.node (Shape.leaf 0) (Shape.leaf 1)) (Shape.node (Shape.leaf 2) (Shape.leaf 3))) (Shape.node (Shape.node (Shape.leaf 4) (Shape.leaf 5)) (Shape.node (Shape.leaf 6) (Shape.leaf 7)))),(Shape.node (Shape.node (Shape.leaf 0) (Shape.node (Shape.leaf 1) (Shape.leaf 2))) (Shape.node (Shape.node (Shape.leaf 3) (Shape.node (Shape.leaf 4) (Shape.leaf 5))) (Shape.node (Shape.leaf 6) (Shape.leaf 7))))]
theorem feasible : candidates.all (fun t => checkFits t 0 ls.length) = true := by decide
#print axioms optimal
#print axioms feasible
