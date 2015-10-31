Var inside,outside: text;
    a,x,y,r,x1,y1,x2,y2,xa,xb,xc,ya,yb,yc: integer;
Begin
     assign(inside,'cord.in'); reset(inside);
     assign(outside,'cord.out'); rewrite(outside);
     Readln(inside,x,y,r);
     Readln(inside,x1,y1,x2,y2);
     Readln(inside,xa,ya,xb,yb,xc,yc);
     a:=0;
     If r>sqrt(sqr(x) + sqr(y)) then a:=a+1;
     If ((0>x1) and (0<x2) and(y1<0)and(y2>0)) then a:=a+1;
     If  ( (abs((xa*xb+ya*yb)/sqrt(sqr(xa)+sqr(ya))/sqrt(sqr(xb)+sqr(yb))) < (((xa-xc)*(xb-xc)+ (ya-yc)*(yb-yc))/sqrt(sqr(xa-xc)+sqr(ya-yc))/sqrt(sqr(xb-xc)+sqr(yb-yc))))
        and (abs((xb*xc+yb*yc)/sqrt(sqr(xb)+sqr(yb))/sqrt(sqr(xc)+sqr(yc))) < (((xb-xa)*(xc-xa)+ (yb-ya)*(yc-ya))/sqrt(sqr(xb-xa)+sqr(yb-ya))/sqrt(sqr(xb-xa)+sqr(yb-ya)))) )
     then a:=a+1;
     write(outside,a);
     close(inside);
     close(outside);
end.