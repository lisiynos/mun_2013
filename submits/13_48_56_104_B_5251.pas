var a,b:string;
i:integer;
d:boolean;
c:char;
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
if (ord(a[i])>122)or(ord(a[i])<97) then d:= false;
end;
if d then write(b)
else write('Suspicious!');
//for c:='a' to 'z' do begin
//writeln(ord(c));
//end;
end.