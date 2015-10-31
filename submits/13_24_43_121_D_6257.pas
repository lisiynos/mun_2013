Var inside,outside: text;
    N,i,t,a,k,p,q,d:integer;
    bro: array [1..p] of integer;
    brot1: array [1..q] of integer;
    brot2: array [1..d] of integer;
Begin
     assign(inside,'dorf.in'); reset(inside);
     assign(outside,'dorf.out'); rewrite(outside);
     Readln(inside,n,t);
     p:=n;q:=n;d:=n;
     For i:= 1 to N do begin
         read(inside,a); bro[i]:=a; brot1[i]:=1;
     end;
     For k:=1 to (t-1) do begin
         for i:=1 to N do begin
             brot2[ bro[i] ]:= brot2[ bro[i] ] + brot1[i];
         end;
         for i:=1 to n do begin
             brot1[i]:=brot2[i]; brot2[i]:=0;
         end;
     end;
     For i:=1 to N do
         write(outside, brot1[i],' ');
     close(inside);
     close(outside);
end.