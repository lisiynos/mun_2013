var
n, i:integer;
bi, bo: text;
s1:string;
begin


assign(bo, 'berg.out');
assign(bi, 'berg.in');
Reset(bi);
read(bi,s1);
close(bi);


    for i:=2 to n-1 do
     n:=Length(s1);
            if i mod(2)=0 then begin
                     if s1[i]='a'
                              then Delete(s1,i,1)
                              else s1:='Suspicious!';
                              end;




















 Rewrite(bo);
 write(bo,s1);
 close(bo)


end.

