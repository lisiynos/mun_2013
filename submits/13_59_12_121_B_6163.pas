Var inside,outside: text;
    b:char; c:array [1..100] of char;
    i,k:integer;
Begin
     assign(inside,'berg.in'); reset(inside);
     assign(outside,'berg.out'); rewrite(outside);
     i:=0;
     k:=1;
     While (Not EOF(inside)) do begin
           read(b);
           If i=1 then
                if b<>'a' then begin end
                else i:=0
           else begin i:=1; c[k]:= b; k:=k+1 end;
     end;
     If (k=(n+1) div 2) then do begin for i:=1 to k do write(outside,c[i]) end;
     Else write(output, 'Suspicious!')
     close(inside);
     close(outside);
end.