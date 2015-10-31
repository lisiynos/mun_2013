import math
inp = open("abt.in" )
outp = open("abt.out", "w")
#THis is my second problem on Python
n = int(inp.readline())
#a, b = list(map(int, inp.readline().split()))
#print(n, file = outp)
#print(n)
a = int(n / 2)
b = a - 1
if a * b != n:
	print("-1 -1", file = outp)
else:
	print(b, a, file = outp)