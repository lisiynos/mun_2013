var n:integer;
j:integer;
i,m:int64;
g:boolean;
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
g:= false;
i:=i+1;
for j:=1 to n do begin
a[d[j]]:=b[j]+a[d[j]];
if (b[j]<>0)and(d[j]<>j) then g:=true;
end;
for j:=1 to n do begin
b[j]:=a[j];
a[j]:=0;
end;
if g = false then begin
for j:=1 to n do
write(b[j],' '); 
close(output);
halt;
end;
end;
for j:=1 to n do
write(b[j],' '); 
end.