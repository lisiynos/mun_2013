var n, a ,b,i: integer; 
input, output: text;
begin 
assign (input, 'abt.in');
reset (input);
assign (output, 'abt.out');
rewrite (output);
read (input, n);
a:=-1; b:=0;
for i:=-1 to n-1 do begin
if a*b=n then writeln (output, a,' ',b)
else a:=a+1; b:=b+1;  
if a=n then  writeln (output,-1,' ',-1); end;  
close (input);
close (output);
end.
