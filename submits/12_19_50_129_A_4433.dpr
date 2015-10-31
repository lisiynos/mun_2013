program PROG946_A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var i, n, a, b:integer;
begin
  { TODO -oUser -cConsole Main : Insert code here }
  reset(input,'abt.in');
  rewrite(output,'abt.out');
  readln(n);
  a:=1;
  b:=a+1;
  while n>a*b do begin
  if n>a*b then begin
  a:=a+1;
  b:=b+1;
  end;
  end;
  if n=a*b then write (a,' ',b);
  if n<a*b then write('-1',' ','-1');
  end.