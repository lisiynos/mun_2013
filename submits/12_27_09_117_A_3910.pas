program PROG532_A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var a, b, n, i: Integer;
   s:array[1..10] of Integer;
begin
  { TODO -oUser -cConsole Main : Insert code here }
  randomize;
  reset(Input, 'abt.in.txt');
  Rewrite(Output, 'abt.out.txt');
  n := Random(1000000000) - 1;
  for i := 1 to 10 do Readln(s[i]);
  for i := 1 to 10 do begin
    if (a * b = n) and (a <> b) tneh begin
      if a > b then Writeln(b, a)
      else Writeln(a, b);
      end;
    else Writeln('-1 -1');
   end;
  end;
  Writeln(s[i]);
end.
 