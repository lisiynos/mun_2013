import math,sys
sys.stdin=open('erd.in','r')
sys.stdout=open('erd.out','w')
n,m=map(int,input().split())
z=list(map(int,input().split()))
p=[0]*n
for i in range(n):
    p[i]=m%(i+1)
for i in range(1000000000):
    flag=0
    for j in range(n):
        if z[j]==(p[j]-i)%(j+1):
            flag+=1
        else:
            break
    if flag==n:
        if m-i>0:
            print(m-i)
            sys.exit(0)
    flag=0
    for j in range(n):
        if z[j]==(p[j]+i)%(j+1):
            flag+=1
        else:
            break    
    if flag==n:
        print(m+i)
        sys.exit(0)