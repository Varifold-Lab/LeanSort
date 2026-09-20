import LeanSort.Algorithm.Tree
import Mathlib.Data.List.Sort

/-! Traversal equations and structural measures for the unbalanced search tree. -/

namespace LeanSort.Tree

variable {α : Type*}

/-- Number of stored occurrences, counting duplicate keys separately. -/
def nodeCount : SearchTree α → Nat
  | .empty => 0
  | .node left _ right => nodeCount left + 1 + nodeCount right

/-- Maximum number of occupied nodes on a root-to-leaf path. -/
def height : SearchTree α → Nat
  | .empty => 0
  | .node left _ right => max (height left) (height right) + 1

theorem inorderAux_eq (t : SearchTree α) (suffix : List α) :
    inorderAux t suffix = inorder t ++ suffix := by
  induction t generalizing suffix with
  | empty => rfl
  | node left value right ihl ihr =>
      simp only [inorder, inorderAux] at *
      rw [ihl (value :: inorderAux right suffix), ihr suffix,
        ihl (value :: inorderAux right [])]
      simp [List.append_assoc]

@[simp] theorem inorder_empty : inorder (.empty : SearchTree α) = [] := rfl

@[simp] theorem inorder_node (l r : SearchTree α) (x : α) :
    inorder (.node l x r) = inorder l ++ x :: inorder r := by
  change inorderAux l (x :: inorderAux r []) = _
  rw [inorderAux_eq]
  rfl

@[simp] theorem inorder_length (t : SearchTree α) :
    (inorder t).length = nodeCount t := by
  induction t with
  | empty => rfl
  | node l x r ihl ihr => simp [nodeCount, ihl, ihr]; omega

theorem height_le_nodeCount (t : SearchTree α) : height t ≤ nodeCount t := by
  induction t with
  | empty => exact Nat.le_refl _
  | node l x r ihl ihr => simp only [height, nodeCount]; omega

@[simp] theorem fromList_nil [LinearOrder α] : fromList ([] : List α) = .empty := rfl

@[simp] theorem treeSortResult_nil [LinearOrder α] :
    treeSortResult ([] : List α) = [] := rfl

end LeanSort.Tree
