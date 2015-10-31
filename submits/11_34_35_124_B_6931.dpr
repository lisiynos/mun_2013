program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
i:integer;s,s1:string;
begin
  { TODO -oUser -cConsole Main : Insert code here }
  reset(input,'berg.in');
  rewrite(output,'berg.out');
  read(s);
  If length(s)mod 2=0 then begin
  write('Suspicious!');
  halt;
  end;
  s1:='';
  For i:=1 to length(s) do begin
  If i mod 2=1 then
  s1:=s1+s[i];
  If (i mod 2=0)and(s[i]<>'a') then begin
  write('Suspicious!');
  halt;
  end;
  end;
  write(s1);
end.
