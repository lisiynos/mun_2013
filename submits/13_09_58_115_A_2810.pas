program qq;
var a,b,n:integer;
input,output:text;
begin
assign (input,'abt.in.txt');
reset (input);
assign (output,'abt.out.txt');
rewrite (output);
read (input ,n);
a:=0;
b:=0;
while n<>(a*b) do begin
a:=a+1;
b:=a+1
end;
if n=(a*b) then
write (output, a,b:2)
else write (output ,-1,-1:2);
close (input);
close (output);
end.