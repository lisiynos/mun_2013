import sys
sys.stdin=open('abt.in','r')
sys.stdout=open('abt.out','w')
n=int(input())
a=10**9
b=10**9
for i in range(1,n+1):
    if i*(i+1)==n and 2*i+2*(i+1)<2*a+2*b:
        a=i
        b=i+1
if a==10**9:
    print(-1,-1)
else:
    print(a,b)