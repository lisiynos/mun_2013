import sys
sys.stdin = open('berg.in', 'r')
sys.stdout = open('berg.out', 'w')
string = input().rstrip()
if string[1] == 'a':
    string = string[::2]
    print (string)
else:
    print ('Suspicious!')