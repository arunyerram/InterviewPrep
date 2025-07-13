class D:  # DSU
    def __init__(s, n): s.p = list(range(n))
    def f(s, x): s.p[x] = s.f(s.p[x]) if s.p[x] != x else x; return s.p[x]
    def u(s, x, y): a, b = s.f(x), s.f(y); s.p[b] = a if a != b else s.p[b]

def solve(n, m, e, con):
    d = D(n)
    for a, b in con: d.u(a-1, b-1)
    g = {}
    for i in range(n):
        r = d.f(i)
        g[r] = min(g.get(r, float('inf')), e[i])
    print(sum(g.values()))

n, m = map(int, input().split())
e = list(map(int, input().split()))
c = [tuple(map(int, input().split())) for _ in range(m)]
solve(n, m, e, c)