import sys
sys.stdin=open('dorf.in','r')
sys.stdout=open('dorf.out','w')
n,t=map(int,input().split())
c=[]
found=[]
z=list(map(int,input().split()))
post=[1]*n
for i in range(len(z)):
    z[i]-=1

for i in range(t):
    new=[0]*n
    for i in range(n):
        new[z[i]]+=post[i]
        post[i]=0
    post=new
    if post in c:
        k=t-(i+1)
        y=i-c.index(post)
        found=c[k%y]
        break
    c.append(post)
if found!=[]:
    for i in found:
        print(i,end=' ')
else:
    for i in post:
        print(i, end=' ')