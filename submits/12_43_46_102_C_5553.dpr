program Project4;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var x,y,x1,x2,y1,y2,xa,xb,xc,ya,yb,yc,r,e:integer;
k1,k2:extended;

begin
  { TODO -oUser -cConsole Main : Insert code here }
  reset(input,'cord.in');
  rewrite(output,'cord.out');
  e:=0;
read(x,y,r);
if (x*x+y*y<=r*r) then e:=e+1;
read(x1,y1,x2,y2);
if (x1<0) and (y1<0) and (x2>0) and (y2>0) then e:=e+1;
read(xa,ya,xb,yb,xc,yc);
k1:=ya/xa;
k2:=yb/xb;
xa:=xa div abs (xa);
xb:=xb div abs (xb);
ya:=ya div abs (ya);
yb:=yb div abs (yb);
if (xa=xb) then begin
if (yc<k1*xc) and (yc>k2*xc) then e:=e+1;
if (yc>k1*xc) and (yc<k2*xc) then e:=e+1;
end else   begin
if (yc<k1*xc) and (yc<k2*xc) then e:=e+1;
if (yc>k1*xc) and (yc>k2*xc) then e:=e+1;
end;
write(e);
end.
