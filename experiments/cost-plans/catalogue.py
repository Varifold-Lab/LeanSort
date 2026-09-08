"""Offline schema enumeration. No benchmark feedback is used here."""
import hashlib
import json
import random
from functools import lru_cache
from itertools import product


def leaf(kind, threshold=None):
    p = {"kind": kind}
    if threshold is not None:
        p["threshold"] = threshold
    return p


def split(left, right, cut=("fraction", 1, 2)):
    return {"kind": "split", "cut": list(cut), "left": left, "right": right}


def guard(p):
    return {"kind": "guard", "fallback": p}


def canonical(p):
    return json.dumps(p, sort_keys=True, separators=(",", ":"))


def digest(p):
    return hashlib.sha256(canonical(p).encode()).hexdigest()


def cut_at(cut, n):
    return min(n, cut[1] if cut[0] == "prefix" else n * cut[1] // max(1, cut[2]))


@lru_cache(None)
def hybrid_upper(t, n):
    if n <= max(1, t):
        return n * (n - 1) // 2
    a = n // 2
    return hybrid_upper(t, a) + hybrid_upper(t, n - a) + n


def upper(p, n, ready=False):
    kind = p["kind"]
    if kind == "merge":
        return n * max(0, n - 1).bit_length()
    if kind == "insertion":
        return n * (n - 1) // 2
    if kind == "hybrid":
        return hybrid_upper(p["threshold"], n)
    if kind == "guard":
        return max(0, n - 1) + (0 if ready else upper(p["fallback"], n))
    a = cut_at(p["cut"], n)
    return upper(p["left"], a, ready) + upper(p["right"], n - a, ready) + n


def log_weight(p):
    kind = p["kind"]
    if kind == "merge":
        return 1
    if kind == "insertion":
        return None
    if kind == "hybrid":
        return max(1, p["threshold"]) + 1
    children = [p["fallback"]] if kind == "guard" else [p["left"], p["right"]]
    weights = [log_weight(c) for c in children]
    return None if None in weights else sum(weights) + 1


def ready_depth(p):
    if p["kind"] == "guard":
        return 0
    if p["kind"] != "split":
        return None
    ds = [ready_depth(p[k]) for k in ("left", "right")]
    return None if None in ds else max(ds) + 1


def formula(p, variable="n", ready=False):
    kind = p["kind"]
    if kind == "merge":
        return f"M({variable})"
    if kind == "insertion":
        return f"I({variable})"
    if kind == "hybrid":
        return f"H({p['threshold']},{variable})"
    if kind == "guard":
        check = f"max(0,{variable}-1)"
        return check if ready else check + " + " + formula(p["fallback"], variable)
    c = p["cut"]
    a = f"min({variable},{c[1]})" if c[0] == "prefix" else f"min({variable},floor({variable}*{c[1]}/max(1,{c[2]})))"
    return f"({formula(p['left'], a, ready)}) + ({formula(p['right'], '('+variable+'-'+a+')', ready)}) + {variable}"


def premise(p, variable="xs"):
    if p["kind"] == "guard":
        return f"Pairwise (<=) {variable}"
    if p["kind"] != "split":
        return "True"
    cut = json.dumps(p["cut"])
    return f"({premise(p['left'], 'take(cut('+cut+',length('+variable+')), '+variable+')')}) AND ({premise(p['right'], 'drop(cut('+cut+',length('+variable+')), '+variable+')')})"


def lean(p):
    kind = p["kind"]
    if kind in ("merge", "insertion"):
        return f"(.leaf .{kind})"
    if kind == "hybrid":
        return f"(.leaf (.hybrid {p['threshold']}))"
    if kind == "guard":
        return f"(.guardSorted {lean(p['fallback'])})"
    cut = p["cut"]
    c = f"(.prefix {cut[1]})" if cut[0] == "prefix" else f"(.fraction {cut[1]} {cut[2]})"
    return f"(.split {c} {lean(p['left'])} {lean(p['right'])})"


def enumerate_catalogue(count=100):
    m, i = leaf("merge"), leaf("insertion")
    hs = [leaf("hybrid", t) for t in (4, 8, 16)]
    singles = [("merge", m), ("insertion", i)] + [(f"hybrid_{t}", p) for t, p in zip((4, 8, 16), hs)]
    representatives = [
        ("two_insertion", split(i, i)),
        ("two_guarded", split(guard(m), guard(m))),
        ("merge_halves", split(m, m)),
        ("guarded_merge", guard(m)),
        ("prefix_insertion_merge", split(i, m, ("prefix", 8))),
        ("three_guarded", split(guard(m), split(guard(m), guard(m)), ("fraction", 1, 3))),
        ("four_guarded", split(split(guard(m), guard(m)), split(guard(m), guard(m)))),
        ("mixed_hybrid", split(hs[0], hs[2], ("fraction", 1, 3))),
    ]
    seen, entries = set(), []

    def add(label, plan):
        key = canonical(plan)
        if key not in seen:
            seen.add(key)
            entries.append({"id": f"p{len(entries):03d}_{label}", "plan": plan, "structural_sha256": digest(plan)})

    for label, p in representatives:
        add(label, p)
    # Round-robin constructions ensure that this is not just 100 threshold aliases.
    cuts = [("fraction", 1, 2), ("fraction", 1, 3), ("fraction", 2, 3), ("prefix", 8), ("prefix", 16)]
    constructions = list(product(cuts, singles, singles))
    random.Random(40913).shuffle(constructions)
    for cut, (_, a), (_, b) in constructions:
        for label, p in [
            ("split", split(a, b, cut)),
            ("guarded_split", guard(split(a, b, cut))),
            ("checked_blocks", split(guard(a), guard(b), cut)),
            ("nested", split(a, split(b, m), cut)),
        ]:
            if len(entries) < count:
                add(label, p)
    if len(entries) != count:
        raise ValueError("requested catalogue is outside this finite enumeration")
    baselines = [{"id": "single_" + name, "plan": p, "structural_sha256": digest(p)} for name, p in singles]
    return entries, baselines


def shortlist(entries, reference_n=64):
    # Selection frozen before input generation or any execution.
    chosen = [e["id"] for e in entries[:8]]
    ranked = sorted(entries, key=lambda e: (upper(e["plan"], reference_n), e["id"]))
    for e in ranked[:5]:
        if e["id"] not in chosen:
            chosen.append(e["id"])
    return chosen


def emit_sources(entries, directory):
    """Proof composition by instantiation, not automatic discovery of properties."""
    directory.mkdir()
    defs = ["import LeanSort.Algorithm.CostedPlan", "namespace CostPlanGenerated", "open LeanSort.CostedPlan"]
    proofs = ["import Generated.Algorithms", "import LeanSort.Verification.CostedPlan.Examples",
              "namespace CostPlanGenerated", "open LeanSort LeanSort.CostedPlan Filter Asymptotics"]
    for e in entries:
        name, p = e["id"], e["plan"]
        defs += [f"def {name} : Schema := {lean(p)}",
                 f"def {name}_algorithm {{α : Type}} [LinearOrder α] (xs : List α) : List α := {name}.run xs",
                 f"def {name}_costFormula : Nat → Nat := {name}.upper",
                 f"def {name}_conditionalFormula : Nat → Nat := {name}.readyUpper"]
        proofs += [
            f"theorem {name}_certificate : Certificate {name} := {name}.certify",
            f"theorem {name}_correct {{α : Type}} [LinearOrder α] (xs : List α) : IsSortingResult (· ≤ ·) xs ({name}_algorithm xs) := {name}.run_spec xs",
            f"theorem {name}_cost {{α : Type}} [LinearOrder α] (xs : List α) : ({name}.eval xs).time ≤ {name}_costFormula xs.length := {name}.cost_le_upper xs",
            f"theorem {name}_conditional {{α : Type}} [LinearOrder α] (xs : List α) (h : {name}.Ready xs) : ({name}.eval xs).time ≤ {name}_conditionalFormula xs.length := {name}.cost_le_readyUpper xs h",
            f"theorem {name}_operational {{α : Type}} [LinearOrder α] (xs : List α) : Comparison.Executes ({name}.program xs) ({name}_algorithm xs) ({name}.eval xs).time := {name}.operational_certificate xs",
            f"theorem {name}_quadratic {{α : Type}} [LinearOrder α] : (fun xs : List α => (({name}.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ)^2) := {name}.cost_isBigO_of_upper _ {name}.upper_isBigO_quadratic",
        ]
        k = log_weight(p)
        if k is not None:
            proofs += [f"theorem {name}_nlog {{α : Type}} [LinearOrder α] : (fun xs : List α => (({name}.eval xs).time : ℝ)) =O[Filter.comap List.length atTop] (fun xs : List α => (xs.length : ℝ) * Real.log xs.length) := {name}.cost_isBigO_of_upper _ ({name}.upper_isBigO_nlog {k} rfl)"]
        d = ready_depth(p)
        if d is not None:
            proofs += [f"theorem {name}_conditional_linear {{α : Type}} [LinearOrder α] : (fun xs : {{xs : List α // {name}.Ready xs}} => (({name}.eval xs.val).time : ℝ)) =O[Filter.comap (fun xs : {{xs : List α // {name}.Ready xs}} => xs.val.length) atTop] (fun xs : {{xs : List α // {name}.Ready xs}} => (xs.val.length : ℝ)) := {name}.ready_cost_isBigO_linear {d} rfl"]
        # The exported finite values are kernel checked, not just Python formulas.
        for n in (0, 1, 8, 16, 32, 64, 128):
            proofs += [f"theorem {name}_formula_{n} : {name}_costFormula {n} = {upper(p,n)} ∧ {name}_conditionalFormula {n} = {upper(p,n,True)} := by decide +kernel"]
        for suffix in ("certificate", "correct", "cost", "conditional", "operational", "quadratic") + (("nlog",) if k is not None else ()) + (("conditional_linear",) if d is not None else ()):
            proofs += [f"#print axioms {name}_{suffix}"]
    defs += ["def entries : List (String × Schema) := [" + ",".join(f'(\"{e["id"]}\", {e["id"]})' for e in entries) + "]", "end CostPlanGenerated"]
    proofs += ["#print axioms LeanSort.CostedPlan.Examples.twoInsertion_smaller_envelope",
               "#print axioms LeanSort.CostedPlan.Examples.twoGuarded_smaller_envelope",
               "#print axioms LeanSort.CostedPlan.Examples.smaller_envelope_but_more_operations",
               "end CostPlanGenerated"]
    (directory / "Algorithms.lean").write_text("\n".join(defs) + "\n")
    (directory / "Certificates.lean").write_text("\n".join(proofs) + "\n")
