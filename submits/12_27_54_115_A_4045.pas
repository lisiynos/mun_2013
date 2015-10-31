program qq;
var a,b,n,p:integer;
input,output:text;
begin
assign (input,'abt.in.txt');
reset (input);
assign (output,'abt.out');
rewrite (output);
read (input ,n);
p:=2*a+2*b;
a:=b-1;
if (n=a*b) and (a>0) and (b>0) then
write (output,a,b:2)
else write (output, -1,-1:2);
close (input);
close (output);
end.