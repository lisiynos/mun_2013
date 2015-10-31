inp = open('abt.in', 'r')
outp = open('abt.out', 'w')
n = int(inp.readline().rstrip())
t = True
for i in range(1, round(n ** (1/2)) + 1):
    if n % i == 0:
        if (n // i == i + 1) or (n // i == i - 1):
            t = False
            a = i
            b = n // i
            break
if not t:
    print(a, b, file = outp)
else:
    print(-1, -1, file = outp)
