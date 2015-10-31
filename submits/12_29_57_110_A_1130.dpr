var a,b,n,i,k:integer;
input,output:text;
begin
reset(input,'abt.in');
rewrite(output,'abt.out');
readln(input,n);
if n>1000000000 then writeln('err');
if n<1 then writeln('err');
for i:=2 to n do begin
inc(a);
b:=i;
if a*b=n then begin writeln(output,a:2,b:2); inc(k); end;
end;
if k=0 then writeln(output,'-1 -1');
close(input);
close(output);
end.