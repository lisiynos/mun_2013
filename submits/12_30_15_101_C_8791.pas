var x,y,r,x1,y1,x2,y2,xa,ya,xb,yb,xc,yc:smallint;
a:shortint;
begin
a:=0;
assign(input,'cord.in');
reset(input);
assign(output,'cord.out');
rewrite(output);
readln(input,x,y,r);
readln(input,x1,y1,x2,y2);
readln(input,xa,ya,xb,yb,xc,yc);
if (x*x+y*y)<r*r then a:=a+1;
if ((x1<0) and (y1<0) and (x2>0) and (y2>0))=true then a:=a+1;
if ((((xa*yb-xb*ya)>0) and ((xb*yc-xc*yb)>0) and ((xa*yc-xc*ya)>0)) or (((xa*yb-xb*ya)<0) and ((xb*yc-xc*yb)<0) and ((xa*yc-xc*ya)<0)))= false then a:=a+1;
writeln(output,a);
close(input);
close(output);
end.