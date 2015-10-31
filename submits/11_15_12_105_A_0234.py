import sys
sys.stdin = open('abt.in','r')
sys.stdout = open('abt.out','w')
n = input()
n = int(n)
s = 1
while s <= n:
    s1 = n/s
    if s1 % 1 == 0 and s - s1 == 1:
        print(s, int(s1))
        break
    s += 1
else:
    print ('-1 -1')