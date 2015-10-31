Var n, e, d, i, m, k: int64;
    p: array [1..20] of integer;
    l: array [1..100] of boolean;
    s: array [1..20] of integer;
input, output: text;
Begin
assign (input,'erd.in');
reset (input);
assign (output,'erd.out');
rewrite (output);
 k := 1;
 d := 1000000000;
 Read (input,n, e);
 For i:= 1 to 100 do
  l[i]:= true;
 For i:= 1 to n do
  Read (input, p[i]);
 For i:= 2 to n do 
  For m:=1 to 100 do
   If (m mod i = p[i]) and (l[m] = true) then
   begin
    l[m]:= true;
   end
   Else
    l[m]:= false;
 For i := 1 to 100 do   
  If l[i] = true then
  begin
   p[k] := i;
   k := k + 1;
  end;
  For i := 1 to k - 1 do
   s[i] := p[i] - 9;
  For i := 1 to k - 1 do
   If s[i] < 0 then s[i] := s[i] * (-1);
  For i:= 1 to k - 1 do
   If d > s[i] then 
   begin
    d := s[i];
    m := i;
   end;
  write (output, p[m]); 
  close (input);
  close (output);
end.