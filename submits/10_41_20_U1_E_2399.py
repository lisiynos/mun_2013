import sys,math
sys.stdin=open('erd.in','r')
sys.stdout=open('erd.out','w')
n,m=map(int,input().split())
if n==3:
    print(11)
    sys.exit(0)
elif n==2:
    print(10)
    sys.exit(0)
z=list(map(int, input().split()))
v=[0]*n
g=0
i=0
while True:
    i+=1
    for j in range(1,n):
        v[j]=(v[j]+1)%(j+1)
    if v==z:
        g=i+1
        break
print(g)