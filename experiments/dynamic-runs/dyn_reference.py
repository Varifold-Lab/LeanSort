"""Independent finite reference, not a proof. Reuses prior static-plan oracle."""
from pathlib import Path
import sys
sys.path.append(str(Path(__file__).resolve().parent.parent / "cost-plans"))
from catalogue import leaf, guard, split, upper as static_upper
from reference import evaluate as static_evaluate, ready as static_ready

CHECKED = guard(leaf("merge"))
FIXED_TWO = split(CHECKED, CHECKED)
STATIC = {"merge": leaf("merge"), "fixed_two": FIXED_TWO,
          "fixed_three": split(CHECKED, FIXED_TWO, ("fraction", 1, 3)),
          "fixed_four": split(FIXED_TWO, FIXED_TWO)}


def discover(xs):
    runs, count = [], 0
    for x in xs:
        if not runs:
            runs.append([x])
        else:
            count += 1
            if runs[-1][-1] <= x:
                runs[-1].append(x)
            else:
                runs.append([x])
    return runs, count


def midpoint_cut(lengths):
    """Independent weight-distance formulation with Algorithm 1 integer ties.
    Even total length: left tie; odd total length: right tie.
    Unlike Lean, this does not locate/branch on the middle-containing run.
    """
    n, at, scores = sum(lengths), 0, []
    for i, size in enumerate(lengths[:-1], 1):
        at += size
        scores.append((abs(2 * at - n), i if n % 2 == 0 else -i, i))
    return min(scores)[2]


def paper_cut(lengths):
    """Algorithm 1, local coordinates, eagerly known ascending run boundaries.
    Used only to cross-check the distinct distance-based reference above.
    """
    middle, start = (sum(lengths)-1)//2, 0
    for index, size in enumerate(lengths):
        end = start + size - 1
        if middle <= end:
            if index == 0:
                return 1
            if index == len(lengths)-1:
                return index
            return index if middle-start < end-middle else index+1
        start = end+1
    raise AssertionError("positive run lengths required")


def plan(runs, length_aware=False):
    if not runs:
        return None
    if len(runs)==1:
        return ("leaf", runs[0])
    k = midpoint_cut([len(r) for r in runs]) if length_aware else len(runs)//2
    return ("node", plan(runs[:k], length_aware), plan(runs[k:], length_aware))


def signature(tree):
    if tree is None:
        return []
    return len(tree[1]) if tree[0]=="leaf" else [signature(tree[1]), signature(tree[2])]


def tree_stats(tree):
    if tree is None:
        return 0, 0, 0
    if tree[0]=="leaf":
        return len(tree[1]), 0, 0
    a, c, d = tree_stats(tree[1])
    b, e, f = tree_stats(tree[2])
    return a+b, c+e+a+b, max(d,f)+1


def execute_tree(tree):
    if tree is None:
        return [], 0
    if tree[0]=="leaf":
        return tree[1][:], 0
    left, a = execute_tree(tree[1])
    right, b = execute_tree(tree[2])
    out, i, j, comparisons = [], 0, 0, a+b
    while i<len(left) and j<len(right):
        comparisons += 1
        if left[i]<=right[j]:
            out.append(left[i]); i += 1
        else:
            out.append(right[j]); j += 1
    return out+left[i:]+right[j:], comparisons


def evaluate(name, xs):
    if name.startswith("runs_"):
        rs, checks = discover(xs)
        tree = plan(rs, name=="runs_length")
        out, comparisons = execute_tree(tree)
        budget = tree_stats(tree)[1]
        bound = checks + (len(xs)*max(0,len(rs)-1).bit_length() if name=="runs_count" else budget)
        return dict(output=out,check_comparisons=checks,merge_or_sort_comparisons=comparisons,
                    comparisons=checks+comparisons,bound=bound,tree_budget=budget,
                    plan=signature(tree),conditional_applicable=False,conditional_bound=None)
    p = leaf("hybrid",int(name.split("_")[1])) if name.startswith("hybrid_") else STATIC[name]
    out, checks, sorting = static_evaluate(p,xs)
    return dict(output=out,check_comparisons=checks,merge_or_sort_comparisons=sorting,
                comparisons=checks+sorting,bound=static_upper(p,len(xs)),tree_budget=None,
                conditional_applicable=static_ready(p,xs),conditional_bound=static_upper(p,len(xs),True))
