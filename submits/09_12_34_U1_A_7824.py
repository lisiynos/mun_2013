import sys,math
sys.stdin=open('abt.in','r')
sys.stdout=open('abt.out','w')
n=int(input())
a=-1
b=-1
p=10**9
for i in range(1,int(n**0.5)+1):
   
    if n%i==0:
        z=n//i
        
        if math.fabs(i-z)==1:
            
            p1=(i<<1)+(z<<1)
            if p1<p:
                p=p1
                a,b=min(i,z),max(i,z)
                
print(a,b)