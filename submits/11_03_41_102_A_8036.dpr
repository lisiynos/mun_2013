program Project4;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var a,b,n,s,d,e:int64;
begin
  { TODO -oUser -cConsole Main : Insert code here }
  //reset(input,'abt.in');
  //rewrite(output,'abt.out');
  read(n);
  a:=0;
  e:=0;
  s:=0;
  a:=0;
  b:=1;
  repeat
  a:=a+1;
  b:=a+1;
  d:=d+2;
  s:=s+a;
  if s=n then e:=1;
  until (s>n) or (e=1);
  if e=0 then begin a:=-1; b:=-1; end;
  write(a,b);
  read(a);
end.
