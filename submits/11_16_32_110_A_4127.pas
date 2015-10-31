var a,b,n,i,k:integer;
input,output:text;
begin
assign(input,'abt.in');
reset(input);
assign(output,'abt.out');
rewrite(output);
readln(input,n);
for i:=2 to n do begin
inc(a);
b:=i;
if a*b=n then begin writeln(output,a:2,b:2); inc(k); end;
end;
if k=0 then writeln(output,'-1 -1');
end.