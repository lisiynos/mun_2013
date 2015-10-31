inp = open("dorf.in", "r")
outp = open("dorf.out", "w")
n, t = list(map(int, inp.readline().rstrip().split()))
v = list(map(int, inp.readline().rstrip().split()))
p = [1] * n
t = [0] * n
for i in range(n):
    for i in range(n):
        t[v[i] - 1] += p[i]
    t, p = p, t
    t = [0] * n
print(p)