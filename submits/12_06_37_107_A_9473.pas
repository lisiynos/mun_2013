program o_1;
var n,a:longint; t1,t2:text;
begin
assign (t1,'abt.in');
assign (t2,'abt.out');
reset (t1);
rewrite (t2);
read (t1,n);
a:=round(sqrt(n));
if a*(a+1)=n then write (t2,a+1,' ',a) else write(t2,-1,' ',-1);
close(t1);
close(t2);
end.