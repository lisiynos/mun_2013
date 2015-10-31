
import sys
sys.stdin = open('dorf.in', 'r')
sys.stdout = open('dorf.out', 'w')

n, t = [int(x) for x in input().split()]
vs = [int(x) - 1 for x in input().split()]

def dfs(v, p):
    if len(p) > 0 and v == p[-1]:
        return ('stable', len(p), p)
    if v in p:
        v1 = p.index(v)
        return ('cycle', v1, p)
    
    return dfs(vs[v], p + [v])

states = [dfs(v, []) for v in range(n)]

res = [0] * n

for kind, i, path in states:
    if kind == 'stable':
        if t < i:
            res[path[t]] += 1
        else:
            res[path[-1]] += 1
    elif kind == 'cycle':
        if t < i:
            res[path[t]] += 1
        else:
            cycle_length = len(path[i:])
            res[path[i:][(t - i) % cycle_length]] += 1

for i in res:
    print(i, end=' ')
print()