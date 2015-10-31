var n,a,b,c:real;
begin
 assign(input,'abt.in');
 reset(input);
 assign(input,'abt.out');
 rewrite(output);
 read(n);
 c:= trunc((-1+sqrt(1+4*n)));  
   if ((-1-sqrt(1+4*n))<0) then begin
     a:=-1;b:=-1;end;
     
     if ((-1+sqrt(1+4*n))-c =0) then begin 
     a:=(-1+sqrt(1+4*n))/2; b:=a+1; end;
     
     if (((-1+sqrt(1+4*n))-c >0)) then begin
     a:=-1; b:=-1;end;
    
 writeln(trunc(a),' ',trunc(b));
 close(input);
 close(output);
 end.
 