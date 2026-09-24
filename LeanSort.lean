import LeanSort.Model.SortingResult
import LeanSort.Model.Rearrangement

-- Keep the umbrella module's import graph refreshable in the editor.
import LeanSort.Model.Inversions

import LeanSort.Algorithm.Insertion
import LeanSort.Algorithm.Bubble
import LeanSort.Algorithm.Selection
import LeanSort.Algorithm.Merge
import LeanSort.Algorithm.Pancake
import LeanSort.Algorithm.Quick
import LeanSort.Algorithm.Heap
import LeanSort.Algorithm.Shell
import LeanSort.Algorithm.Counting
import LeanSort.Algorithm.Radix
import LeanSort.Algorithm.Tree
import LeanSort.Algorithm.Bucket
import LeanSort.Algorithm.Bitonic
import LeanSort.Algorithm.Intro
import LeanSort.Algorithm.Power

import LeanSort.Verification.Shared.RearrangementLemmas
import LeanSort.Verification.Shared.InversionBounds

import LeanSort.Verification.Insertion.Equations
import LeanSort.Verification.Insertion.Checks
import LeanSort.Verification.Insertion.Correctness
import LeanSort.Verification.Insertion.Trace
import LeanSort.Verification.Insertion.Cost
import LeanSort.Verification.Insertion.Complexity

import LeanSort.Verification.Bubble.Equations
import LeanSort.Verification.Bubble.Checks
import LeanSort.Verification.Bubble.Correctness
import LeanSort.Verification.Bubble.Trace
import LeanSort.Verification.Bubble.Cost
import LeanSort.Verification.Bubble.Complexity

import LeanSort.Verification.Selection.Equations
import LeanSort.Verification.Selection.Checks
import LeanSort.Verification.Selection.Correctness
import LeanSort.Verification.Selection.Trace
import LeanSort.Verification.Selection.Semantics
import LeanSort.Verification.Selection.Comparisons
import LeanSort.Verification.Selection.Cost
import LeanSort.Verification.Selection.Complexity

import LeanSort.Verification.Merge.Equations
import LeanSort.Verification.Merge.Checks
import LeanSort.Verification.Merge.Correctness
import LeanSort.Verification.Merge.Trace
import LeanSort.Verification.Merge.Cost
import LeanSort.Verification.Merge.Complexity

import LeanSort.Verification.Pancake.Equations
import LeanSort.Verification.Pancake.Checks
import LeanSort.Verification.Pancake.Correctness
import LeanSort.Verification.Pancake.Trace
import LeanSort.Verification.Pancake.Cost
import LeanSort.Verification.Pancake.Complexity

import LeanSort.Verification.Quick.Equations
import LeanSort.Verification.Quick.Checks
import LeanSort.Verification.Quick.Correctness
import LeanSort.Verification.Quick.Trace
import LeanSort.Verification.Quick.Semantics
import LeanSort.Verification.Quick.Cost
import LeanSort.Verification.Quick.Complexity
import LeanSort.Verification.Quick.Tree

import LeanSort.Verification.Heap.Checks
import LeanSort.Verification.Heap.Equations
import LeanSort.Verification.Heap.Correctness
import LeanSort.Verification.Heap.Trace
import LeanSort.Verification.Heap.Cost
import LeanSort.Verification.Heap.Complexity

import LeanSort.Verification.Shell.Checks
import LeanSort.Verification.Shell.Equations
import LeanSort.Verification.Shell.Correctness
import LeanSort.Verification.Shell.Trace
import LeanSort.Verification.Shell.Semantics
import LeanSort.Verification.Shell.Cost
import LeanSort.Verification.Shell.Complexity

import LeanSort.Verification.Counting.Equations
import LeanSort.Verification.Counting.Checks
import LeanSort.Verification.Counting.Correctness
import LeanSort.Verification.Counting.Trace
import LeanSort.Verification.Counting.Cost
import LeanSort.Verification.Counting.Complexity

import LeanSort.Verification.Radix.Checks
import LeanSort.Verification.Radix.Equations
import LeanSort.Verification.Radix.Correctness
import LeanSort.Verification.Radix.Trace
import LeanSort.Verification.Radix.Semantics
import LeanSort.Verification.Radix.Cost
import LeanSort.Verification.Radix.Complexity

import LeanSort.Verification.Tree.Equations
import LeanSort.Verification.Tree.Correctness
import LeanSort.Verification.Tree.Trace
import LeanSort.Verification.Tree.Semantics
import LeanSort.Verification.Tree.Cost
import LeanSort.Verification.Tree.Complexity
import LeanSort.Verification.Tree.Checks

import LeanSort.Verification.Bucket.Equations
import LeanSort.Verification.Bucket.Correctness
import LeanSort.Verification.Bucket.Trace
import LeanSort.Verification.Bucket.Semantics
import LeanSort.Verification.Bucket.Cost
import LeanSort.Verification.Bucket.Complexity
import LeanSort.Verification.Bucket.Checks

import LeanSort.Verification.Bitonic.Equations
import LeanSort.Verification.Bitonic.Comparator
import LeanSort.Verification.Bitonic.Correctness
import LeanSort.Verification.Bitonic.Trace
import LeanSort.Verification.Bitonic.Semantics
import LeanSort.Verification.Bitonic.Cost
import LeanSort.Verification.Bitonic.Complexity
import LeanSort.Verification.Bitonic.Checks

import LeanSort.Verification.Intro.Equations
import LeanSort.Verification.Intro.Correctness
import LeanSort.Verification.Intro.Trace
import LeanSort.Verification.Intro.Semantics
import LeanSort.Verification.Intro.Cost
import LeanSort.Verification.Intro.Complexity
import LeanSort.Verification.Intro.Checks

import LeanSort.Verification.Power.Equations
import LeanSort.Verification.Power.NodePower
import LeanSort.Verification.Power.Correctness
import LeanSort.Verification.Power.Stability
import LeanSort.Verification.Power.Trace
import LeanSort.Verification.Power.Cost
import LeanSort.Verification.Power.MergeTree
import LeanSort.Verification.Power.Comparisons
import LeanSort.Verification.Power.Complexity
import LeanSort.Verification.Power.Checks
