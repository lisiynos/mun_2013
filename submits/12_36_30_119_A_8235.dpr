program berg;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var s,s1,s2,s3:string;
q,i,k,n:integer;
begin
reset(input, 'berg.in');rewrite(output,'berg.out');
read(s);
s1:=' '; s2:=' ';s3:=' ';

for i:=1 to length(s) do begin
if (i mod 2 =0) then s1:=s1+copy(s,i,1);
end;
for i:=1 to length(s1)-1 do begin
s2:=s2+'a';end;
if s1=s2 then k:=1
else
k:=0;
if k=0 then writeln('Suspicious!');
if k=1 then begin
for i:=1 to length(s) do begin
if (i mod 2=1) then s3:=s3+copy(s,i,1)
end;
writeln(s3);
end;





  { TODO -oUser -cConsole Main : Insert code here }
end.
 