//uses sysutils;
var a,b:integer;
i:integer;
begin
assign(input,'abt.in');
reset(input);
assign(output,'abt.out');
rewrite(output);
read(a);
b:=trunc(sqrt(a));
i:=b+1;
if i*b=a then write(b,' ',i)
else write('-1 -1');
end.