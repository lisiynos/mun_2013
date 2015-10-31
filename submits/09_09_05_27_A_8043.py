import sys
sys.stdin = open('abt.in','r')
sys.stdout =open('abt.out','w')
n=int(input())
for i in range(0,n):
    if i*(i+1)==n:
        print(i,i+1)
        sys.exit()
print('-1 -1')