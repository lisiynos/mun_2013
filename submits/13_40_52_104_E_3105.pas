var a,j:array[1..1000] of integer;
i,k,k1,e,b,n,c,s,m:integer;
f:boolean;
begin
assign(input,'erd.in');
reset(input);
assign(output,'erd.out');
rewrite(output);
read(n,e);
read(j[1]);
a[1]:=1;
//read(j[2]);
for i:=2 to n do begin 
read(j[i]);
b:=a[i-1];
c:=i;
while (c<>b) do begin
if b<c then begin
m:=b;
b:=c;
c:=m;
end;
b:=b - c;
end;
a[i]:=i*(a[i-1]) div c;
//writeln(a[i]);
end;
s:=j[n];
f:=false;
while (s<a[n])and (f=false) do begin
s:=s+n;
f:= true;
for i:=1 to n do begin
if s mod i <> j[i] then f := false;
end;
end;
k:=(e div a[n]-1)*a[n]+s;
k1:=k+a[n];
//write(a[n],'  ',s);
if e-k<k1-e then write(k);
if e-k>k1-e then write(k1);
if e-k=k1-e then write(k);
end.