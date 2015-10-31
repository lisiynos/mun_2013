Var inside,outside: text;
    b:char; c:string;
    i:integer;
Begin
     assign(inside,'berg.in'); reset(inside);
     assign(outside,'berg.out'); rewrite(outside);
     i:=0;
     k:=1;
     While (Not EOF(inside)) do begin
           read(b);
           If i=1 then begin
                if b<>'a' then begin c:='1'; break; end
                else i:=0  end
           else begin i:=1; c:=c + b; end;
     end;
     If c<>'1' then begin for i:=1 to k do write(outside,c[i]) end
     Else write(output, 'Suspicious!');
     close(inside);
     close(outside);
end.