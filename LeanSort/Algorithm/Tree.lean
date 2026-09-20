import Mathlib.Order.Defs.LinearOrder

/-!
Tree sort through an unbalanced binary search tree. Every input occurrence gets
its own node, including duplicates. Sorted inputs can produce a linear-height
tree; this implementation does not claim a worst-case `O(n log n)` bound.
-/

namespace LeanSort.Tree

/-- The underlying tree; the search-tree invariant is maintained by `insert`
when starting from `empty`, rather than enforced by the type. -/
inductive SearchTree (α : Type*) where
  | empty
  | node (left : SearchTree α) (value : α) (right : SearchTree α)
  deriving Repr, DecidableEq

/-- Insert one occurrence. Strictly smaller values go left; ties go right. -/
def insert {α : Type*} [LinearOrder α] (x : α) : SearchTree α → SearchTree α
  | .empty => .node .empty x .empty
  | .node left value right =>
      if x < value then .node (insert x left) value right
      else .node left value (insert x right)

/-- Build a search tree by inserting elements from left to right. -/
def fromList {α : Type*} [LinearOrder α] (xs : List α) : SearchTree α :=
  xs.foldl (fun tree x => insert x tree) .empty

/-- Prepend an in-order traversal to `suffix`, without list concatenation.
The suffix is an accumulator, not an additional input to sort. -/
def inorderAux {α : Type*} : SearchTree α → List α → List α
  | .empty, suffix => suffix
  | .node left value right, suffix =>
      inorderAux left (value :: inorderAux right suffix)

/-- Enumerate every node in left-root-right order. -/
def inorder {α : Type*} (tree : SearchTree α) : List α :=
  inorderAux tree []

/-- Sort by building a binary search tree and traversing it in order. -/
def treeSortResult {α : Type*} [LinearOrder α] (xs : List α) : List α :=
  inorder (fromList xs)

end LeanSort.Tree
