"""Independent finite regression oracle; this is NOT a formal proof."""
from catalogue import cut_at


def evaluate(p, xs):
    checks = sorting = 0

    def le(a, b, checking=False):
        nonlocal checks, sorting
        if checking:
            checks += 1
        else:
            sorting += 1
        return a <= b

    def merge(left, right):
        out, a, b = [], 0, 0
        while a < len(left) and b < len(right):
            if le(left[a], right[b]):
                out.append(left[a])
                a += 1
            else:
                out.append(right[b])
                b += 1
        return out + left[a:] + right[b:]

    def insertion(values):
        out = []
        for x in reversed(values):
            at = 0
            while at < len(out):
                if le(x, out[at]):
                    break
                at += 1
            out.insert(at, x)
        return out

    def hybrid(values, threshold):
        if len(values) <= max(1, threshold):
            return insertion(values)
        a = len(values) // 2
        return merge(hybrid(values[:a], threshold), hybrid(values[a:], threshold))

    def run(plan, values):
        kind = plan["kind"]
        if kind == "insertion":
            return insertion(values)
        if kind == "merge":
            return hybrid(values, 1)
        if kind == "hybrid":
            return hybrid(values, plan["threshold"])
        if kind == "guard":
            if all(le(a, b, True) for a, b in zip(values, values[1:])):
                return values[:]
            return run(plan["fallback"], values)
        a = cut_at(plan["cut"], len(values))
        return merge(run(plan["left"], values[:a]), run(plan["right"], values[a:]))

    result = run(p, xs)
    return result, checks, sorting


def ready(p, xs):
    if p["kind"] == "guard":
        return all(a <= b for a, b in zip(xs, xs[1:]))
    if p["kind"] != "split":
        return True
    a = cut_at(p["cut"], len(xs))
    return ready(p["left"], xs[:a]) and ready(p["right"], xs[a:])
