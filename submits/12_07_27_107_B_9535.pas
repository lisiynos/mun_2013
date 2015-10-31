program o_2;
var st:string; i,k:integer;  t1,t2:text;
begin
assign (t1,'berg.in');
assign (t2,'berg.out');
reset (t1);
rewrite (t2);
read(t1,st);
k:=0;
for i:=1 to length(st) do if i mod 2=0 then if st[i]<>'a' then k:=k+1;
if k=0 then begin
for i:=2 to length(st) do delete (st,i,1);
for i:=1 to length(st) do write(t2,st[i]);
end else write(t2,'Suspicious!');
close(t1);
close(t2);
end. 