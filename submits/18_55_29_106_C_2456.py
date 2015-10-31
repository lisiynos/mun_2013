#import math
inp = open("cord.in", "r")
outp = open("cord.out", "w")
x1, y1, r = list(map(int, inp.readline().rstrip().split()))
n = 0
if (x1**2 + y1**2) < r ** 2:
    n += 1

x1, y1, x2, y2 = list(map(int, inp.readline().rstrip().split()))
t = True
if (x1 < 0) and (x2 > 0) and (y1 < 0) and (y2 > 0):
    n += 1

x1, y1, x2, y2, x3, y3 = list(map(int, inp.readline().rstrip().split()))
s1 = (abs(x1*y2 - y1*x2) + abs(x2*y3 - y2*x3) + abs(x3*y1 - y3*x1)) / 2
s2 = abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) / 2
if abs(s1 - s2) < 1 / 1000000000:
    n += 1
print(n, file = outp)
    
