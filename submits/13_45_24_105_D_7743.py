import sys

sys.stdin = open('dorf.in', 'r')
sys.stdout = open('dorf.out', 'w')

n, t = map(int, input().split())
prefer = input().rstrip()
prefer = prefer[::2]
letters = [1] * n

for c in range(t):
    s = 0
    for x in prefer:
        letters[int(x) - 1] += int(letters[s])
        letters[s] = 0
        s += 1
for cou in range(n):
    print(letters[cou]),
