var a,b:string;
i:integer;
d:boolean;
begin
assign(input,'berg.in');
reset(input);
assign(output,'berg.out');
rewrite(output);
read(a);
b:='';
d:=True;
for i:=1 to length(a) do begin
if i mod 2 = 1 then b:=b+a[i] else if a[i]<>'a' then d:= False;
end;
if d then write(b)
else write('Suspicious!');
end.