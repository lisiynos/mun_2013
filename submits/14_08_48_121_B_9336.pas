Var inside,outside: text;
    b:char; c:array [1..100] of string;
    i,k:integer;
Begin
     assign(inside,{'berg.in'}'f1'); reset(inside);
     assign(outside,{'berg.out'}'f2'); rewrite(outside);
     i:=0;
     k:=1;
     While (Not EOF(inside)) do begin
           read(b);
           If i=1 then begin
                if b<>'a' then begin c[k]:='ab'; break; end
                else i:=0  end
           else begin i:=1; c[k]:= b; k:=k+1 end;
     end;
     If c[k]<>'ab' then do begin for i:=1 to k do write(outside,c[i]) end
     Else write(output, 'Suspicious!');
     close(inside);
     close(outside);
end.
     