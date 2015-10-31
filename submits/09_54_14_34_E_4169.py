import sys
sys.stdin = open('erd.in','r')
sys.stdout = open('erd.out','w')
n,e  = map(int,input().split())
p = [int(x) for x in input().split()]

for i in range(10**10):
    flag1 = 1
    flag2 = 1
    for j in range(1,n):
        if (e-i)%(j+1) != p[j]:
            flag1 = 0
        if (e+i)%(j+1) != p[j]:
            flag2 = 0
    if flag1:
        print(e-i)
        sys.exit(0)
    elif flag2:
        print(e+i)
        sys.exit(0)
    