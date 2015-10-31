program cord;

{$APPTYPE CONSOLE}

uses SysUtils;

var x,y,r,x1,x2,y1,y2,xa,xb,xc,ya,yb,yc: integer;

begin
  reset(input,'cord.in');
  rewrite(output,'cord.out');

  read(x,y,r);
  if x-r<0 and y-r<0 then a:=0;
  if x-r>0 or y-r>0 then a:=1;
  end;
  end;
  read(x1,x2,y1,y2);
  if x1<0 and x2>0 and y1>0 and y2<0 then
  b:=1;
  end;
  if (x1<0 and x2<0) or (x1>0 and x2>0) or (y1<0 and y2<0) or (y1>0 and Y2>0) then
  b:=0;
  end;
  read(xa,xb,xc,ya,yb,yc);
  if ((xa<>0 and xb>0 and xc<0) and (ya>0 and yb<0 and yc<0)) or ((xb<>0 and xc>0 and xa<0) and (yb>0 and yc<0 and ya<0)) or ((xc<>0 and xa>0 and xb<0) and (yc>0 and ya<0 and yb<0)) or ((xa<0 and xb>0 and xc<>0) and (ya>0 and yb>0 and yc<0)) or ((xb<0 and xc>0 and xa<>0) and (yb>0 and yc>0 and ya<0)) or ((xc<0 and xa>0 and xb<>0) and (yc>0 and ya>0 and yb<0)) then
  c:=1;
  end;
  if (xa<0 and xb<0 and xc<0) or (xa>0 and xb>0 and xc>0) or (ya<0 and yb<0 and yc<0) or (ya>0 and yb>0 and yc>0) then
  c:=0;
  end;
  writeln(a+b+c);
end.

