var a,x,y,r,x1,y1,x2,y2,xa,ya,xb,yb,xc,yc:integer;
begin
 assign(input,'cord.in');
 reset(input);
 assign(input,'cord.out');
 rewrite(output);
read(x,y,r,x1,y1,x2,y2,xa,ya,xb,yb,xc,yc);
a:=0;
if (y2>0) and (y1<0) and (x1<0) and (x2>0) then 
a:=a+1;
if ((y+r)>0) and ((y-r)<0) and ((x-r)<0) and ((x+r)>0) then 
a:=a+1;
if (ya>0) and (yb>0) and (yc<0) and (xb>xc) and (xa<xc) then
a:=a+1;
if (yb>0) and (yc>0) and (ya<0) and (xb<xa) and (xc>xa) then 
a:=a+1;
if (yc>0) and (ya>0) and (yb<0) and (xc<xb) and (xa>xb) then 
a:=a+1;
writeln(a);
 close(input);
 close(output);
end.
