import sys
import math
sys.stdin = open( 'abt.in', 'r' )
sys.stdout = open( 'abt.out', 'w' )
n = int(input())
if n%2 == 1:
    print('-1 -1')
else:
    a = int(math.sqrt(n))
    if a*(a+1) == n:
        print(str(a) + ' ' + str(a + 1))
    elif a*(a-1) == n:
        print(str(a - 1) + ' ' + str(a))
    else:
        print('-1 -1')