{Author: Natalja Ginzburg}
{check period for single letters}
{$I+,Q+,R+,S+}

Program erd;

uses
  Math;

type
  Integer = Longint;

const 
  TASKNAME = 'erd';

var
  i, j, n, e, res, f, lcm, dif: Integer;
  tres1, tres2: Integer;
  c: array [1..20] of Integer; {watches}

function gcd (a, b: Integer): Integer;
  begin
    if b = 0 then
      gcd := a
    else 
      gcd := gcd (b, a mod b)
  end;

BEGIN
  assign (input,  TASKNAME + '.in');  reset   (input);
  assign (output, TASKNAME + '.out'); rewrite (output);

  read (n, e);
  for i := 1 to n do
    read(c[i]);
  lcm := 1;
  for i := 1 to n do
    lcm := lcm div gcd (lcm, i) * i;

  res := c[n];
  if res = 0 then
    inc(res, n);
  while True do
    begin
      f := 1;
      for j := 2 to n do
        if res mod j <> c[j] then
          f := 0;
      if f = 1 then
        break;
      inc (res, n)
    end;
    dif := 1000000000;
    for i := -1 to 1 do
      begin
        tres1 := (e div lcm + i) * lcm + res;
        if tres1 <= 0 then
          continue;
        if dif > abs (e - tres1) then
          begin 
            dif := abs (e - tres1);
            tres2 := tres1
          end
      end;
  writeln (tres2)

END.
