import sys
import math
sys.stdin = open( 'abt.in', 'r' )
sys.stdout = open( 'abt.out', 'w' )
n = int(input())
if n%2 == 1:
    print('-1 -1')
else:
    n = int(math.sqrt(n))
    print(str(n) + ' ' + str(n + 1))