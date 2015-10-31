import sys

sys.stdin = open('dorf.in', 'r')
sys.stdout = open('dorf.out', 'w')

n, t = map(int, input().split())
prefer = input().rstrip()
prefer = prefer[::2]
letters = [1] * n

for c in range(t):
    for x in prefer:
        letters[int(x) - 1] += int(letters[c])-1

for count in range(n):
    print(letters[count])