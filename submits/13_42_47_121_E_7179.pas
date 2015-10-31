Var inside, outside: text;
    n,e,i,a,d1,d0,p:integer;
    dn: array [1..1000000000] of integer;
    cd0:array [1..1000000000] of integer;
    cd1:array [1..1000000000] of integer;
Begin
     assign(inside,'erd.in'); reset(inside);
     assign(outside,'erd.out'); rewrite(outside);
     Readln(inside, n,e);
     d1:=0;
     d0:=0;
     For i:=1 to n do begin
         read(a); dn[i]:=a;
     end;
     For i:=1 to N do begin
         p:=e mod i; cd1[i]:=p; cd0[i]:=p; end;
     For i:=1 to n do begin
         while (cd1[i]<>dn[i]) do begin
               cd1[i]:=(cd1[i]+1) mod i; d1:=d1+1;
         end;
         while (cd0[i]<>dn[i]) do begin
               cd0[i]:=(cd0[i]-1) mod i; d0:=d0-1;
         end;
     end;
     If (e+d0)>0 then
        If abs(d0)<= d1 then write(e+d0)
        else write (d1)
     Else write(outside,d1);
     Close(inside);
     close(outside);
end.