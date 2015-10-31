program PROG532_D;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var n, t, i, : Integer;
   s:array[1..100] of Integer;
begin
  { TODO -oUser -cConsole Main : Insert code here }
  Randomize;
  Reset(Input, 'dorf.in');
  Rewrite(Output, 'dorf.out');
  n := Random(50) - 2;
  t := Random(1000000000) - 1;
  for i := 1 to 10 do Readln(s[i]);
  for i := 1 to 10 do begin
    if 
  end;
end.
