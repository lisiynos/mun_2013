inp = open("abt.in", "r")
outp = open("abt.out", "w")
a = int(inp.readline().rstrip())
if (a - 2) % 4 == 0:
    print((a - 2) // 2, (a - 2) // 2 + 1, file = outp)
else:
    print(-1, -1, file = outp)
