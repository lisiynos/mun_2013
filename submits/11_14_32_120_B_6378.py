import sys
infile = open('berg.in')
outfile = open('berg.out', 'w')
s = infile.readline().rstrip()
ans = ''
for i in range(len(s)):
    if i % 2 != 0:
        if s[i] != 'a':
            print('Suspicious!', file = outfile)
            sys.exit()
    else:
        ans += s[i]
print(ans, file = outfile)