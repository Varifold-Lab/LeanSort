"""Regression guard for timer placement in Lean's generated C (not a proof).
The same Lean optimizer feeds the interpreter and C code generator.
"""

import re


def function_body(source, name):
    match = re.search(r"LEAN_EXPORT lean_object\* " + re.escape(name) + r"\([^;]*?\)\s*\{", source)
    if not match:
        raise ValueError("missing generated function: " + name)
    start = source.index("{", match.start())
    depth = 1
    for end in range(start + 1, len(source)):
        depth += (source[end] == "{") - (source[end] == "}")
        if depth == 0:
            return source[match.start():end + 1]
    raise ValueError("unterminated generated function")


def audit(source):
    sorting = function_body(source, "l_AdaptiveExperiment_checkedRun")
    feature = function_body(source, "l_AdaptiveExperiment_timedFeatures")
    checks = {}
    for name, body, computation in [
        ("sorting", sorting, "l_AdaptiveExperiment_Strategy_run("),
        ("feature", feature, "l_AdaptiveExperiment_features(")]:
        clocks = [m.start() for m in re.finditer(r"lean_io_mono_nanos_now\(", body)]
        if len(clocks) != 2 or not clocks[0] < body.index(computation) < clocks[1]:
            raise ValueError(name + " computation is not enclosed by two clock reads")
        if name == "feature" and not clocks[0] < body.index("lean_st_ref_get(") < body.index(computation):
            raise ValueError("feature input must be read from IO inside timing")
        if name == "sorting" and not body.index("l_AdaptiveExperiment_checksum(") < clocks[1]:
            raise ValueError("output consumption moved outside timing")
        checks[name + "_inside_timer"] = True
    return {"checks": checks, "sorting_body": sorting, "feature_body": feature,
            "scope": "syntactic compiler-output regression check, not formal timing verification"}
