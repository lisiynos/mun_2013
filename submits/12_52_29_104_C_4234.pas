var 
i,k,x,y,y2,x2,r,x1,y1:integer;
p,p1,p2,p3,s,s1,s2,s3,a,b,c,d,e,f:real;
begin
assign(input,'cord.in');
reset(input);
assign(output,'cord.out');
rewrite(output);
read(x,y,r);
if x*x+y*y<r*r then k:=k+1;
read(x,y,x1,y1);
if x1<x then begin
x:=x+x1;
x1:=x-x1;
x:=x-x1;
end; 
if y1<y then begin
y:=y+y1;
y1:=y-y1;
y:=y-y1;
end; 
if (y<0)and(y1>0)and(x<0)and (x1>0) then k:=k+1;
read(x,y,x1,y1,x2,y2);
a:=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
b:=sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2));
c:=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
d:=sqrt(x2*x2+y2*y2);
e:=sqrt(x1*x1+y1*y1);
f:=sqrt(x*x+y*y);
p:=(a+b+c)/2;
s:=sqrt(p*(p-a)*(p-b)*(p-c));
p1:=(b+d+f)/2;
s1:=sqrt(p1*(p1-b)*(p1-d)*(p1-f));
p2:=(e+c+d)/2;
s2:=sqrt(p2*(p2-c)*(p2-d)*(p2-e));
p3:=(a+e+f)/2;
s3:=sqrt(p3*(p3-a)*(p3-e)*(p3-f));
if abs(s-s1-s2-s3)<0.0000001 then k:=k+1;
write (k);
end.