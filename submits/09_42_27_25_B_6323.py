import sys
import math
sys.stdin = open( 'berg.in', 'r' )
sys.stdout = open( 'berg.out', 'w' )
n = input()
for i in range(len(n)):
    if(i % 2 == 1)and(n[ i ] != 'a'):
        print('Suspicious!')
        sys.exit(0)
if len(n) % 2 == 0:
    print('Suspicious!')
    sys.exit(0)
for i in range(0,len(n),2):
    sys.stdout.write(n[i])