"""Small cost-sensitive CART: leaves minimize summed measured training latency.
No sklearn dependency; fitting never accepts rows marked as held-out/test.
"""

import statistics
from data import CANDIDATES, FEATURE_NAMES, digest, plan, plan_name


def costs(row):
    return {m["strategy"]: statistics.median(m["samples_ns"])
            for m in row["measurements"] if m["strategy"] in CANDIDATES}


def prepare(rows):
    groups = {}
    for row in rows:
        if row["split"] != "train":
            raise ValueError("held-out rows must never enter training")
        if len(row["features"]) != len(FEATURE_NAMES):
            raise ValueError("feature schema mismatch")
        key = row["input_sha256"]
        g = groups.setdefault(key, {"features": row["features"], "samples": {p: [] for p in CANDIDATES}})
        if g["features"] != row["features"]:
            raise ValueError("same input has conflicting features")
        measures = {m["strategy"]: m["samples_ns"] for m in row["measurements"]}
        if not all(p in measures and measures[p] and all(t > 0 for t in measures[p]) for p in CANDIDATES):
            raise ValueError("incomplete/nonpositive candidate timings")
        for p in CANDIDATES:
            g["samples"][p].extend(measures[p])
    return [{"features": g["features"], "input_sha256": key,
             "cost": {p: statistics.median(g["samples"][p]) for p in CANDIDATES}}
            for key, g in sorted(groups.items())]


def best_action(rows):
    totals = {p: sum(r["cost"][p] for r in rows) for p in CANDIDATES}
    p = min(CANDIDATES, key=totals.get)
    return p, totals[p]


def fit(rows, config):
    data = prepare(rows)
    if not data:
        raise ValueError("no training observations")

    def grow(items, depth):
        action, parent_loss = best_action(items)
        leaf = {"kind": "leaf", "plan": plan(action)}
        minimum = config["tree_min_leaf"]
        if depth >= config["tree_max_depth"] or len(items) < 2 * minimum:
            return leaf
        best_split, best_loss = None, parent_loss
        for feature in range(len(FEATURE_NAMES)):
            values = sorted({r["features"][feature] for r in items})[:-1]
            cap = config["tree_max_split_candidates"]
            if len(values) > cap:
                values = [values[i * (len(values) - 1) // (cap - 1)] for i in range(cap)]
            for threshold in values:
                left = [r for r in items if r["features"][feature] <= threshold]
                right = [r for r in items if r["features"][feature] > threshold]
                if min(len(left), len(right)) < minimum:
                    continue
                loss = best_action(left)[1] + best_action(right)[1]
                if loss < best_loss:
                    best_loss, best_split = loss, (feature, threshold, left, right)
        if best_split is None or parent_loss - best_loss < parent_loss * config["tree_min_relative_gain"]:
            return leaf
        feature, threshold, left, right = best_split
        return {"kind": "branch", "feature": feature, "threshold": threshold,
                "left": grow(left, depth + 1), "right": grow(right, depth + 1)}

    tree = grow(data, 0)
    fixed, fixed_cost = best_action(data)
    model = {"schema_version": 1, "feature_names": FEATURE_NAMES, "tree": tree,
             "training_inputs": len(data), "training_hash": digest([r["input_sha256"] for r in data])}
    chosen_cost = sum(r["cost"][predict(model, r["features"])] for r in data)
    return model, fixed, {"unique_training_inputs": len(data), "best_fixed": fixed,
                          "training_fixed_ns": fixed_cost, "training_tree_plan_only_ns": chosen_cost,
                          "note": "in-sample costs; excludes feature/decision overhead, not generalization"}


def predict(model, features):
    node = model["tree"]
    while node["kind"] == "branch":
        node = node["left"] if features[node["feature"]] <= node["threshold"] else node["right"]
    return plan_name(node["plan"])


def describe(model):
    def walk(node, indent):
        if node["kind"] == "leaf":
            return [indent + "return " + plan_name(node["plan"])]
        return ([indent + "if " + FEATURE_NAMES[node["feature"]] + " <= " + str(node["threshold"]) + ":"] +
                walk(node["left"], indent + "  ") + [indent + "else:"] + walk(node["right"], indent + "  "))
    return "\n".join(walk(model["tree"], ""))
