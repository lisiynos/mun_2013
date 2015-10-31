program Project4;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var i,e:int64;
s,s1:string;

begin
  { TODO -oUser -cConsole Main : Insert code here }
  reset(input,'berg.in');
  rewrite(output,'berg.out');
  read(s);
  i:=0;
   if length(s) mod 2 = 0  then s1:='Suspicious!' else begin
    repeat
         i:=i+2;
      if i<length(s) then begin

      if s[i]='a' then s1:=s1+s[i-1] else s1:='Suspicious!';
      end;
    until (i>length(s)) or (s1='Suspicious!');
    if  s1<>'Suspicious!' then s1:=s1+s[length(s)];
   end;
   write(s1); 


end.
