import sys,math
sys.stdin=open('abt.in','r')
sys.stdout=open('abt.out','w')
n=list(input())
new=''
for i in range(len(n)):
    if i%2==0:
        new+=n[i]
    else:
        if n[i]!='a':
            print('Suspicious!')
            sys.exit(0)
print(new)