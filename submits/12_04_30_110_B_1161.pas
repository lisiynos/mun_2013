var s1,s2:string;
i,z,j,k:integer;
f1,f2:text;
begin
assign(f1);
reset(f1,'berg.in');
assign(f2,'berg.out');]
rewrite(f2);
readln(f1,s1);
j:=1;
for i:=1 to length(s1) div 2 do begin
k:=k+2;
if s1[k]='a' then z:=z+1;
end;
if z=length(s1) div 2 then begin
for i:=1 to length(s1) div 2 +1 do begin
s2:=s2+s1[j];
j:=j+2;
end;
writeln(f2,s2);
end else writeln(f2,'Suspicious!');
close(f1);
close(f2);
end.

