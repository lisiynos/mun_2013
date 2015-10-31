import sys
sys.stdin = open('abt.in','r')
sys.stdout = open('abt.out','w')
n = int(input())

b = (-1+(1+4*n)**0.5)/2
if (int(b) == b):
    print(int(b),int(b+1))
else:
    print("-1 -1")