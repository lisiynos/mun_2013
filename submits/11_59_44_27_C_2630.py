import sys
from math import *
sys.stdin =open('cord.in','r')
sys.stdout =open('cord.out','w')
x,y,r=map(int,input().split())
x1,y1,x2,y2=map(int,input().split())
xa,ya,xb,yb,xc,yc=map(int,input().split())
ot=0
r02=x**2+y**2
if r02<r**2:
    ot+=1
if (x1<0)and(y1<0)and(x2>0)and(y2>0):
    ot+=1
w=0
if xa==xb:
    if xa>0:
        w+=1
else:
    kab=(yb-ya)/(xb-xa)
    if kab!=0:
        bab=ya-kab*xa
        xab=-bab/kab
        if xab>0:
            w+=1
if xc==xb:
    if xc>0:
        w+=1
else:
    kbc=(yb-yc)/(xb-xc)
    if kbc!=0:
        bbc=yb-kbc*xb
        xbc=-bbc/kbc
        if xbc>0:
            w+=1
if xa==xc:
    if xa>0:
        w+=1
else:
    kac=(ya-yc)/(xa-xc)
    if kac!=0:
        bac=ya-kac*xa
        xac=-bac/kac
        if xac>0:
            w+=1
if w==1:
    ot+=1
print(ot)