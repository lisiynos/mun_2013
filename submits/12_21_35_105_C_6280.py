import sys

sys.stdin = open('cord.in', 'r')
sys.stdout = open('cord.out', 'w')

x, y, r = map(int, input().split())
x1, y1, x2, y2 = map(int, input().split())
xa, ya, xb, yb, xc, yc = map(int, input().split())
count = 0

if (xa <= 0 and ya <= 0) or (xb <= 0 and yb <= 0) or (xc <= 0 and yc <= 0):
    count += 1

if x1 <= 0 and y1 <= 0:
    count += 1

if x < r and y < r:
    count += 1
print (count)