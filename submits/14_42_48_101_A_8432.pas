var a,b,n:integer;
begin
a:=1;
assign(input,'abt.in');
reset(input);
assign(output,'abt.out');
rewrite(output);
read(input,n);
while not((((n/a)-a=1) or ((n/a)-a=-1)) and (n mod a= 0)) do
begin
a:=a+1;
if a>n then write(output,'-1 -1');
if a>n then
halt;
end;
b:=n div a;
writeln(output,a,' ',b);
end.
