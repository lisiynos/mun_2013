program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
i,k,a:longint;
begin
  { TODO -oUser -cConsole Main : Insert code here }
  reset(input,'abt.in');
  rewrite(output,'abt.out');
  read(a);
  k:=trunc(sqrt(a));
  If (a mod k=0) and (a div k=k+1) then
  write(k,' ',k+1)
  Else
  write(-1);
end.
