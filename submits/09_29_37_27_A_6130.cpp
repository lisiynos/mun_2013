import sys
sys.stdin = open('abt.in', 'r')
            sys.stdout = open('abt.out', 'w')
                         n = int(input())

                             if n % 2 == 1:
                             print('-1 -1')
                               sys.exit()
                               for i in range(0, n //2+2):
                                   if i * (i + 1) == n:
                                     print(i, i + 1)
                                     sys.exit()
                                     print('-1 -1')