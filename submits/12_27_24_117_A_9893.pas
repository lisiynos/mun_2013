program PROG532_C;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var x, y, r, x1, x2, y1, y2, Xa, Ya, Xb, Yb, Xc, Yc: Integer;
   s:array[1..100] of Integer;
begin
  { TODO -oUser -cConsole Main : Insert code here }
  Reset(Input, 'cord.in');
  Rewrite(Output, 'cord.out');
  x, y, r := Random(100) - 1;
  x1, y1, x2, y2 := Random(100) - 1;
  Xa, Ya, Xb, Yb, Xc, Yc := Random(100) - 1;
  x1 < x2;
  y1 < y2;
  for i := 1 to 100 do readln(s[i]);
  for i := 1 to 100 do begin
    if x > 0 and y > 0 and x1 > 0 and y1 > 0 and x2 > 0 and y2 > 0 then
    Writeln('0')
    else Writeln();
  end;
end.
