inp = open("berg.in", "r")
outp = open("berg.out", "w")
a = inp.readline().rstrip()
t = True
b = []
for i in range(len(a)):
    if (i % 2 != 0) and a[i] != 'a':
        #print(a[i])
        t = False
    if (i % 2 == 0):
        b.append(a[i])
if t == True:
    print(''.join(b), file = outp)
else:
    print('Suspicious!', file = outp)

