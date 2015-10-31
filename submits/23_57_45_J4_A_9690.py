
import sys, math
sys.stdin = open('abt.in', 'r')
sys.stdout = open('abt.out', 'w')

n = int(input())

D = math.sqrt(1 + 4*n)
if abs(int(D) - D) > 1e-6:
    print('-1 -1')
else:
    a = -1 + int(D)
    if a % 2 != 0:
        print('-1 -1')
    else:
        print(a // 2, a // 2 + 1)
