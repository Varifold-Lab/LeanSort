"""Syntactic timer-placement regression check, not a machine-cost proof."""
import re


def function_body(source, name):
    match = re.search(r"LEAN_EXPORT lean_object\* " + re.escape(name) + r"\([^;]*?\)\s*\{", source)
    if not match:
        raise ValueError("missing generated function: " + name)
    depth, start = 1, source.index("{", match.start())
    for end in range(start + 1, len(source)):
        depth += (source[end] == "{") - (source[end] == "}")
        if depth == 0:
            return source[match.start():end + 1]
    raise ValueError("unterminated generated function")


def audit(source):
    checks, bodies = {}, {}
    for label, function, operations in [
        ("deployment", "timedRun", ["lean_st_ref_get(", "l_LeanSort_CostedPlan_Schema_run", "l_CostPlanExperiment_checksum(", "lean_st_ref_set("]),
        ("check_replay", "timedChecks", ["lean_st_ref_get(", "Schema_checkProgram", "l_LeanSort_Comparison_Program_eval", "lean_st_ref_set("]),
        ("offline_profile", "profile", ["lean_st_ref_get(", "l_LeanSort_CostedPlan_Schema_eval", "Schema_checkProgram", "l_Lean_Json_compress(", "lean_st_ref_set("]),
    ]:
        body = function_body(source, "l_CostPlanExperiment_" + function)
        clocks = [m.start() for m in re.finditer(r"lean_io_mono_nanos_now\(", body)]
        positions = [body.index(operation) for operation in operations]
        if len(clocks) != 2 or not clocks[0] < min(positions) <= max(positions) < clocks[1]:
            raise ValueError(label + " computation escaped the timer")
        if positions != sorted(positions):
            raise ValueError(label + " computations changed order")
        checks[label + "_inside_timer"] = True
        bodies[label] = body
    return dict(checks=checks, bodies=bodies,
                scope="compiler-output regression check, not verified timing or native execution")
