program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
n,k1,i:integer;t,j:longint;k,p,o:array[1..50]of integer;
begin
  { TODO -oUser -cConsole Main : Insert code here }
  reset(input,'dorf.in');
  rewrite(output,'dorf.out');
  readln(n,t);
  For i:=1 to n do begin
  read(p[i]);
  k[i]:=1;
  end;
  For j:=1 to t do begin
  For i:=1 to n do
  o[i]:=0;
  For i:=1 to n do
  o[p[i]]:=o[p[i]]+k[i];
  For i:=1 to n do
  k[i]:=o[i];
  end;
  For i:=1 to n do
  write(k[i],' ');
end.