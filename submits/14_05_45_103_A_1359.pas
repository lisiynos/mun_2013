var D,n:integer;
    a:real;
begin
 assign(input,'abt.in');
 reset(input);
 assign(output,'abt.out');
 rewrite(output);
 readln(n);
 D:=1+4*n;
 If D>0 then begin
  a:=(-1+sqrt(D))/2;
  If a=trunc(a) then
   write(a,' ',a+1)
  else write('-1 -1');
 end 
 Else write('-1 -1');
 close(input);
 close(output);
end. 