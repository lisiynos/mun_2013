Var a, b, c, i, k: integer;
    d: array [1..100] of integer;
    input, output: text;
Begin
 assign (input, 'abt.in');
 Reset (input);
 assign (output, 'abt.out');
 Rewrite (output);
 Read (input, a);
 k := 0;
 For i:=1 to a do
  If a mod i = 0 then
  begin
   k := k+1;
   d[k] := i;
  end;
 If k mod 2 <> 0 then
  Write (output,'-1 -1');
 b:= d[k div 2];
 c:= d[k div 2 + 1];
 If k mod 2 = 0 then
  Write (output, b,' ', c);
 close (input);
 close (output);
End.