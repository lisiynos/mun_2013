program PROG946_B;

{$APPTYPE CONSOLE}

uses
  SysUtils;

array  a, b: of integer;
       i
begin
  { TODO -oUser -cConsole Main : Insert code here }
  reset(input,'berg.in');
  rewrite(output,'berg.out');
  read(b);
  a:=1;
  k:=0;
  while k<100 do begin
  for i:= 1 to 100 do begin
  if a mod 2=1 then begin
  write(b);
  a:=a+1;
  k:=k+1;
  if a mod 2=0 then
  a:=a+1;
  end;
  end;
  end;
end.
