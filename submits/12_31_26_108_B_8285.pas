var s:string;
i:integer;
f1,f2:text;
begin
assign(f1,'berg.in.txt');
assign(f2,'berg.out.txt');
reset(f1);
rewrite(f2);
read(f1,s);
if s[2]='a' then begin
i:=0;
while i<length(s) do begin
inc(i);
if (s[i]='a') and (s[i+1]='a') then begin 
delete(s,i,1);
inc(i);
end;
if s[i]='a' then delete(s,i,1);
end;
writeln(f2,s);
end
else writeln(f2,'Suspicious!')
close(f1);
close(f2);
end.