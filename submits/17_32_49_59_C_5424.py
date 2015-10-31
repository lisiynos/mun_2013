import math
infile = open('cord.in')
outfile = open('cord.out', 'w')
ans = 0
x, y, r = map(int, infile.readline().rstrip().split())
if x ** 2 + y ** 2 < r ** 2:
    ans += 1
x1, y1, x2, y2 = map(int, infile.readline().rstrip().split())
if (x1 < 0 < x2 and y1 < 0 < y2):
    ans += 1
x1, y1, x2, y2, x3, y3 = map(int, infile.readline().rstrip().split())
nums = [[x1, y1], [x2, y2], [x3, y3]]
nums.sort()
if nums[1][1] < nums[2][1]:
    nums[1], nums[2] = nums[2], nums[1]
k = 0
if nums[0][0] != nums[1][0]:
    if (nums[0][0] * nums[1][1] - nums[0][1] * nums[1][0]) / (nums[0][0] - nums[1][0]) > 0:
        k += 1
elif nums[0][0] < 0:
    k += 1
if nums[1][0] != nums[2][0]:
    if (nums[1][0] * nums[2][1] - nums[1][1] * nums[2][0]) / (nums[1][0] - nums[2][0]) > 0:
        k += 1
elif nums[1][0] > 0:
    k += 1
if nums[0][0] == nums[2][0]:
    if nums[0][0] < 0:
        k += 1
elif (nums[0][0] * nums[2][1] - nums[0][1] * nums[2][0]) / (nums[0][0] - nums[2][0]) < 0:
    k += 1
if k == 3:
    ans += 1
print(ans, file = outfile)