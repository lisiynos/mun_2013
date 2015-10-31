var n,a,b,c,k:integer;
f1,f2:text;
begin
assign(f1,'abt.in.txt');
assign(f2,'abt.out.txt');
reset(f1);
rewrite(f2);
read(f1,n);
c:=(n div 2);
for a:=1 to c do
for b:=1 to c do begin
if (b-a=1) and (a*b=n) then begin
writeln(f2,a,' 'b);k:=k+1;
end;
end;
if k=0 then writeln(f2,'-1',' -1');
close(f1);
close(f2);
end.