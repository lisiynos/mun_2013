import math,sys
sys.stdin=open('erd.in','r')
sys.stdout=open('erd.out','w')
n,m=map(int,input().split())
z=list(map(int,input().split()))
v=max(z)
p=[0]*n
for i in range(n):
    p[i]=m%(i+1)
print(p)
t=[0]*n
y1=[0]*n
y2=[0]*n
for i in range(n):
    t[i]=p[i]
    y1[i]=p[i]
    y2[i]=p[i]
    
s=0
flag=10**9

for i in range(1000000000):
    for j in range(n):
        y2[j]=(t[j]-i)%(j+1)
    if y2==z:
        if m-i>0:
            print(m-i)
            sys.exit(0) 
    for j in range(n):
        y1[j]=(p[j]+i)%(j+1)    
    if y1==z:
        print(m+i)
        sys.exit(0)