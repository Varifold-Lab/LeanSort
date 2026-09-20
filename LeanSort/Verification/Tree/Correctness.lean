import LeanSort.Verification.Tree.Equations
import LeanSort.Model.SortingResult

/-! Search-tree preservation, sorted traversal, and exact occurrence conservation. -/

namespace LeanSort.Tree

variable {α : Type*} [LinearOrder α]

theorem inorder_insert_perm (x : α) (t : SearchTree α) :
    (inorder (insert x t)).Perm (x :: inorder t) := by
  induction t with
  | empty => simp [insert]
  | node l v r ihl ihr =>
      simp only [insert]
      split
      · simpa using ihl.append_right (v :: inorder r)
      · simp only [inorder_node]
        apply ((List.Perm.refl (inorder l)).append (ihr.cons v)).trans
        simpa only [List.append_assoc, List.singleton_append] using
          (List.perm_middle : ((inorder l ++ [v]) ++ x :: inorder r).Perm
            (x :: ((inorder l ++ [v]) ++ inorder r)))

@[simp] theorem mem_inorder_insert (x y : α) (t : SearchTree α) :
    y ∈ inorder (insert x t) ↔ y = x ∨ y ∈ inorder t := by
  rw [(inorder_insert_perm x t).mem_iff, List.mem_cons]

@[simp] theorem nodeCount_insert (x : α) (t : SearchTree α) :
    nodeCount (insert x t) = nodeCount t + 1 := by
  have h := (inorder_insert_perm x t).length_eq
  simpa [Nat.add_comm] using h

/-- Strict left bounds and non-strict right bounds record the algorithm's tie
policy. The property is structural, rather than assuming a sorted traversal. -/
def Ordered : SearchTree α → Prop
  | .empty => True
  | .node l v r => Ordered l ∧ Ordered r ∧
      (∀ x ∈ inorder l, x < v) ∧ (∀ x ∈ inorder r, v ≤ x)

theorem ordered_insert (x : α) (t : SearchTree α) (ht : Ordered t) :
    Ordered (insert x t) := by
  induction t with
  | empty => simp [insert, Ordered]
  | node l v r ihl ihr =>
      obtain ⟨hl, hr, hleft, hright⟩ := ht
      simp only [insert]
      split
      · rename_i hx
        refine ⟨ihl hl, hr, ?_, hright⟩
        intro y hy
        rcases (mem_inorder_insert x y l).mp hy with rfl | hy
        · exact hx
        · exact hleft y hy
      · rename_i hx
        refine ⟨hl, ihr hr, hleft, ?_⟩
        intro y hy
        rcases (mem_inorder_insert x y r).mp hy with rfl | hy
        · exact le_of_not_gt hx
        · exact hright y hy

theorem sorted_inorder (t : SearchTree α) (ht : Ordered t) :
    (inorder t).Pairwise (· ≤ ·) := by
  induction t with
  | empty => simp
  | node l v r ihl ihr =>
      obtain ⟨hl, hr, hleft, hright⟩ := ht
      rw [inorder_node]
      apply List.pairwise_append.mpr
      refine ⟨ihl hl, List.pairwise_cons.mpr ⟨hright, ihr hr⟩, ?_⟩
      intro a ha b hb
      rcases List.mem_cons.mp hb with rfl | hb
      · exact le_of_lt (hleft a ha)
      · exact (le_of_lt (hleft a ha)).trans (hright b hb)

theorem fold_insert_perm (xs : List α) (t : SearchTree α) :
    (inorder (xs.foldl (fun tree x => insert x tree) t)).Perm (xs ++ inorder t) := by
  induction xs generalizing t with
  | nil => simp
  | cons x xs ih =>
      simp only [List.foldl_cons]
      apply (ih (insert x t)).trans
      apply ((inorder_insert_perm x t).append_left xs).trans
      exact List.perm_middle

theorem fold_insert_ordered (xs : List α) (t : SearchTree α) (ht : Ordered t) :
    Ordered (xs.foldl (fun tree x => insert x tree) t) := by
  induction xs generalizing t with
  | nil => exact ht
  | cons x xs ih => exact ih (insert x t) (ordered_insert x t ht)

theorem fromList_ordered (xs : List α) : Ordered (fromList xs) :=
  fold_insert_ordered xs .empty trivial

theorem treeSortResult_perm (xs : List α) : (treeSortResult xs).Perm xs := by
  simpa [treeSortResult, fromList] using fold_insert_perm xs .empty

theorem sorted_treeSortResult (xs : List α) :
    (treeSortResult xs).Pairwise (· ≤ ·) := sorted_inorder _ (fromList_ordered xs)

theorem treeSortResult_spec (xs : List α) :
    IsSortingResult (· ≤ ·) xs (treeSortResult xs) :=
  ⟨sorted_treeSortResult xs, treeSortResult_perm xs⟩

@[simp] theorem treeSortResult_length (xs : List α) :
    (treeSortResult xs).length = xs.length := (treeSortResult_perm xs).length_eq

@[simp] theorem fromList_nodeCount (xs : List α) : nodeCount (fromList xs) = xs.length := by
  simpa [treeSortResult] using treeSortResult_length xs

@[simp] theorem mem_treeSortResult (xs : List α) (x : α) :
    x ∈ treeSortResult xs ↔ x ∈ xs := (treeSortResult_perm xs).mem_iff

@[simp] theorem count_treeSortResult (xs : List α) (x : α) :
    (treeSortResult xs).count x = xs.count x := (treeSortResult_perm xs).count_eq x

end LeanSort.Tree
