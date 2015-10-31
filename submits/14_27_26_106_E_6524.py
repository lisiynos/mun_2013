import math
inp = open("erd.in", "r")
outp = open("erd.out", "w")
n, e = list(map(int, inp.readline().rstrip().split()))
p = list(map(int, inp.readline().rstrip().split()))
c = 10000000000


def f(t, k, o):
    global c
    if k == 0:
        if t < c:
            c = t
    else:
        z1 = t % k - p[k - 1]
        if z1 < 0:
            z1 = z1 * -1
        z2 = k - z1
        z1 = z1 * o
        z2 = z2 * o
       # print(z, t, k, p[k - 1])
        if t - z2 < 0:
            return f(t + z1, k - 1, o * k)
        else:
            if (e - t - z1) ** 2 < (e - t + z2) ** 2: 
                f(t + z1, k - 1, o * k)
            if (e - t - z1) ** 2 > (e - t + z2) ** 2:
                f(t - z2, k - 1, o * k)
            if (e - t - z1) ** 2 == (e - t + z2) ** 2:
                f(t + z1, k - 1, o * k)
                f(t - z2, k - 1, o * k)
            

a = f(e, n, 1)
print(c, file = outp)

    