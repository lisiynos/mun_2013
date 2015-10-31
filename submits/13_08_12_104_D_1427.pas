var n:integer;
j:integer;
i,m:int64;
a,b,d:array[1..50] of integer;
begin
assign(input,'dorf.in');
reset(input);
assign(output,'dorf.out');
rewrite(output);
read(n,m);
i:=0;
for j:=1 to n do begin
read(d[j]);
b[j]:=1;
a[j]:=0;
end;
while i< m do begin
i:=i+1;
for j:=1 to n do begin
a[d[j]]:=b[j]+a[d[j]];
end;
for j:=1 to n do begin
b[j]:=a[j];
a[j]:=0;
end;
end;
for i:=1 to n do
write(b[i],' '); 
end.