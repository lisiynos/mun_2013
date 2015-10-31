program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
k,r,x,x1,x2,x3,x4,x5,y,y1,y2,y3,y4,y5:integer;a,b,c,p,s,s1:extended;
begin
  { TODO -oUser -cConsole Main : Insert code here }
  reset(input,'cord.in');
  rewrite(output,'cord.out');
  readln(x,y,r);
  readln(x1,y1,x2,y2);
  readln(x3,y3,x4,y4,x5,y5);
  k:=0;
  If x*x+y*y<r*r then
  k:=k+1;
  If (x1<0)and(y1<0)and(x2>0)and(y2>0)then
  k:=k+1;
  a:=sqrt(sqr(x3-x4)+sqr(y3-y4));
  b:=sqrt(sqr(x5-x4)+sqr(y5-y4));
  c:=sqrt(sqr(x3-x5)+sqr(y3-y5));
  p:=(a+b+c)/2;
  s:=sqrt(p*(p-a)*(p-b)*(p-c));
  a:=sqrt(sqr(x3-x4)+sqr(y3-y4));
  b:=sqrt(sqr(x4)+sqr(y4));
  c:=sqrt(sqr(x3)+sqr(y3));
  p:=(a+b+c)/2;
  s1:=sqrt(p*(p-a)*(p-b)*(p-c));
  a:=sqrt(sqr(x3)+sqr(y3));
  b:=sqrt(sqr(x5)+sqr(y5));
  c:=sqrt(sqr(x3-x5)+sqr(y3-y5));
  p:=(a+b+c)/2;
  s1:=s1+sqrt(p*(p-a)*(p-b)*(p-c));
  a:=sqrt(sqr(x4)+sqr(y4));
  b:=sqrt(sqr(x5-x4)+sqr(y5-y4));
  c:=sqrt(sqr(x5)+sqr(y5));
  p:=(a+b+c)/2;
  s1:=s1+sqrt(p*(p-a)*(p-b)*(p-c));
  If abs(s1-s)<0.0000000001 then
  k:=k+1;
  write(k);
end.
