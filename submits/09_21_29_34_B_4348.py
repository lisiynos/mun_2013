import sys
sys.stdin = open('berg.in','r')
sys.stdout = open('berg.out','w')
n = input()
if(len(n) < 1):
    print('Suspicious!')
    sys.exit(0) 
if(len(n) % 2 == 0):
    print('Suspicious!')
    sys.exit(0)     
new = ''
new += n[0]
count = 0
for i in n:
    count += 1
    if (count%2 == 0) and (i != 'a'):
        print('Suspicious!')
        sys.exit(0)
    elif(count%2 == 0):
        new += n[count]
print(new)