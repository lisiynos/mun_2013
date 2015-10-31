var
a, n, i, b:integer;
ai, ao: text;
begin
a:=1;
b:=2;

assign(ao, 'abt.out');
assign(ai, 'abt.in');
Reset(ai);
read(ai,n);
close(ai);
if n>0 then begin
  for i:=1 to n do
    if (a*b=n)and((a+1=b)or(b+1=a))
    then
    else begin
    a:=a+1;
    b:=b+1;
    end;
 end;
 Rewrite(ao);
 if (a*b=n)and((a+1=b)or(b+1=a)) then
 write(ao,a,' ',b)
 
 
 else Write(ao,'-1 -1');
 close(ao)


end.







