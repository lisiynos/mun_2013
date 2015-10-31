program abt;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var a,b,k,i,n:integer;
begin
reset(input,'abt.in');rewrite(output,'abt.out');
read(n);
for i:=1 to n do begin
if (i*(i+1)=n) then begin
        k:=0;a:=i;b:=i+1;
        end
else
k:=1;
end;
if not(a=0) and not(b=0) then writeln(a,' ',b)
else
writeln('-1 -1');