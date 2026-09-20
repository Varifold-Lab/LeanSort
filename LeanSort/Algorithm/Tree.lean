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

/-- Comparison decisions on an insertion path: `true` goes left, `false` right.
There is one decision per occupied node, and no decision at the empty leaf. -/
def insertionPath {α : Type*} [LinearOrder α] (x : α) : SearchTree α → List Bool
  | .empty => []
  | .node l v r =>
      if x < v then true :: insertionPath x l else false :: insertionPath x r

/-- Record one comparison path for each insertion, in input order. -/
def buildTrace {α : Type*} [LinearOrder α] :
    List α → SearchTree α → SearchTree α × List (List Bool)
  | [], t => (t, [])
  | x :: xs, t =>
      let rest := buildTrace xs (insert x t)
      (rest.1, insertionPath x t :: rest.2)

/-- Optional tracing; the ordinary sorting entry point does not construct a log. -/
def sortTrace {α : Type*} [LinearOrder α] (xs : List α) : List α × List (List Bool) :=
  let run := buildTrace xs .empty
  (inorder run.1, run.2)

def treeSortTrace {α : Type*} [LinearOrder α] (xs : List α) : List (List Bool) :=
  (sortTrace xs).2

/-- Replay one insertion, checking each supplied direction against the key.
Missing decisions, extra decisions, and incorrect branches are rejected. -/
def replayInsert? {α : Type*} [LinearOrder α] (x : α) :
    SearchTree α → List Bool → Option (SearchTree α)
  | .empty, [] => some (.node .empty x .empty)
  | .node l v r, true :: path =>
      if x < v then (replayInsert? x l path).map (fun l' => .node l' v r) else none
  | .node l v r, false :: path =>
      if x < v then none else (replayInsert? x r path).map (fun r' => .node l v r')
  | _, _ => none

/-- Checked replay requires exactly one complete path per input occurrence. -/
def replayBuild? {α : Type*} [LinearOrder α] :
    List α → List (List Bool) → SearchTree α → Option (SearchTree α)
  | [], [], t => some t
  | x :: xs, path :: paths, t => do
      let next ← replayInsert? x t path
      replayBuild? xs paths next
  | _, _, _ => none

def replayChecked? {α : Type*} [LinearOrder α]
    (paths : List (List Bool)) (xs : List α) : Option (List α) :=
  (replayBuild? xs paths .empty).map inorder

end LeanSort.Tree
