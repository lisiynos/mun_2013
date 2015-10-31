import math, sys
infile = open('abt.in')
outfile = open('abt.out', 'w')
n = int(infile.readline().rstrip())
for i in range(1, int(math.sqrt(n)) + 1):
    a = n / i
    if a == i - 1:
        print(int(a), i, file = outfile)
        sys.exit()
    elif a == i + 1:
        print(i, int(a), file = outfile)
        sys.exit()
print(-1, -1, file = outfile)