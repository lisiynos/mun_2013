program qq;
var a,b,n:integer;
input,output:text;
begin
reset (input,'abt.in');
rewrite (output,'abt.out');
read (input ,n);
a:=2;
b:=3;
if (n=a*b) and (a>0) and (b>0) then
write (output,a,b:2)
else write (output, -1,-1:2);
close (input);
close (output);
end.