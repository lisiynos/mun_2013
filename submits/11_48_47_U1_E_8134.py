import math,sys
sys.stdin=open('erd.in','r')
sys.stdout=open('erd.out','w')
n,m=map(int,input().split())
z=list(map(int,input().split()))
v=max(z)
p=[0]*n
s=0
flag=10**9
for i in range(m**2):
    for j in range(len(p)):
        p[j]=(p[j]+1)%(j+1)
    if p==z:
        if math.fabs(m-i-1)<flag:
            flag=math.fabs(m-i-1)
            s=i+1
        else:
            break
print(s)