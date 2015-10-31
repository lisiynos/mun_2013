Var inside,outside: text;
    n,a:integer;
Begin
     assign(inside,'abt.in');
     reset(inside);
     assign(outside,'abt.out');
     rewrite(outside);
     Read(inside, n);
     a:=0; b:=0;
     For a:=1 to N do begin
         If (n/a - trunc(n/a))=0 then
         b:=(n div a); If ((a+1)=b) then break;
     end;
     If ((a+1)=b) then write(outside, a, ' ',b)
     Else write(outside, '-1',' ','-1');
     close(inside);
     close(outside);
end.