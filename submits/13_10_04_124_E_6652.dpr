program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
n,i,o:integer;e,k,s:int64;p:array[1..20]of integer;
begin
  { TODO -oUser -cConsole Main : Insert code here }
  reset(input,'erd.in');
  rewrite(output,'erd.out');
  readln(n,e);
  for i:=1 to n do
  read(p[i]);
  i:=1;
  k:=1;
  s:=0;
  o:=1;
  repeat
  s:=s+k;
  If s mod(i+1)=p[i+1]then begin
  If i=n-1 then
  o:=0;
  i:=i+1;
  If i=2 then
  k:=k*i;
  If i=3 then
  k:=k*i;
  If i=4 then
  k:=k*2;
  If i=5 then
  k:=k*i;
  If i=7 then
  k:=k*i;
  If i=8 then
  k:=k*2;
  If i=9 then
  k:=k*3;
  If i=11 then
  k:=k*i;
  If i=13 then
  k:=k*i;
  If i=16 then
  k:=k*2;
  If i=17 then
  k:=k*i;
  If i=19 then
  k:=k*i;
  end;
  until o=0;
  If s>=e then begin
  write(s);
  halt;
  end;
  o:=(e-s) div k;
  If abs(o*k+s-e)>abs((o+1)*k+s-e)then
  write((o+1)*k+s)
  else write(o*k+s);
end.