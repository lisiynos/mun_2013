import sys
sys.stdin =open('berg.in','r')
sys.stdout =open('berg.out','w')
s=input()
s1=''
if len(s) % 2==0:
    print('Suspicious!')
    sys.exit()
for i in range(0,len(s),2):
    if (i+1<len(s))and(s[i+1]!='a'):
        print('Suspicious!')
        sys.exit()
    else:
        s1=s1+s[i]
print(s1)