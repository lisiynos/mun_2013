Var inside,outside: text;
    b:char;
    i:integer;
Begin
     assign(inside,'berg.in'); reset(inside);
     assign(outside,'berg.out'); rewrite(outside);
     i:=0;
     While (Not EOF(inside)) do begin
           read(b);
           If i=1 then
                if b<>'a' then begin rewrite(output, 'Suspicious!'); end
                else i:=0
           else begin i:=1; write(output, b); end;
     end;
     close(insude);
     close(outside);
end.
     