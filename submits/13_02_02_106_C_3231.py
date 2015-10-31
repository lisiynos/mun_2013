inp = open("cord.in", "r")
outp = open("cord.out", "w")
x1, y1, r = list(map(int, inp.readline().rstrip().split()))
n = 0
if (x1**2 + y1**2) < r ** 2:
    n += 1

x1, y1, x2, y2 = list(map(int, inp.readline().rstrip().split()))
t = True
if (x1 > 0) and (x2 > 0):
    t = False
if (x1 < 0) and (x2 < 0):
    t = False
if (y1 > 0) and (y2 > 0):
    t = False
if (y1 < 0) and (y2 < 0):
    t = False
if t == True:
    n += 1

x1, y1, x2, y2, x3, y3 = list(map(int, inp.readline().rstrip().split()))
h1 = ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** (1/2)
h2 = ((x2 - x3) ** 2 + (y2 - y3) ** 2) ** (1/2)
h3 = ((x3 - x1) ** 2 + (y3 - y1) ** 2) ** (1/2)
a1 = (x1 ** 2 + y1 ** 2) ** (1/2)
a2 = (x2 ** 2 + y2 ** 2) ** (1/2)
a3 = (x3 ** 2 + y3 ** 2) ** (1/2)
p1 = (a1 + a2 + h1) / 2
s1 = (p1 * (p1 - a1) * (p1 - a2) * (p1 - h1)) ** (1/2)
p2 = (a2 + a3 + h2) / 2
s2 = (p2 * (p2 - a2) * (p2 - a3) * (p2 - h2)) ** (1/2)
p3 = (a3 + a1 + h3) / 2
s3 = (p3 * (p3 - a3) * (p3 - a1) * (p3 - h3)) ** (1/2)
p = (h1 + h2 + h3) / 2
s = (p * (p - h1) * (p - h2) * ( p - h3)) ** (1/2)
k = s - s1 - s2 - s3
if k > 0:
    n +=1
print(n, file = outp)