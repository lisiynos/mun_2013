program Project4;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var i,j,n,t:longint;
a,b,c:array [1..50] of integer;

begin
  { TODO -oUser -cConsole Main : Insert code here }
  reset(input,'dorf.in');
  rewrite(output,'dorf.out');
  read(n,t);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do c[i]:=1;
  for j:=1 to t do begin
  for i:=1 to n do  begin
  b[i]:=c[i];
  c[i]:=0;
  end;
  for i:=1 to n do
  c[a[i]]:=c[a[i]]+b[i];
  end;
  for i:=1 to n do write(c[i],' ');
end.
