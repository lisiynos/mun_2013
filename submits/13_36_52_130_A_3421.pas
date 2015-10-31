program Abt;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var a,b,n: Integer;

begin
  reset(input,'abt.in');
  rewrite(output,'abt.out');

  read(n);
  n:=a*b;
  if a=b+1 or a=b-1 then begin
  writeln(a, b);
  end;

end.
