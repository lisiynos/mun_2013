{Author: Natalja Ginzburg}
{check period for single letters}
{$I+,Q+,R+,S+}

Program dorf;

type
  Integer = Longint;

const 
  TASKNAME = 'dorf';

var
  i, j, k, n, t: Integer;
  per, pre: Integer;
  a: array [1..50] of Integer;
  u: array [1..50] of Integer;
  res: array [1..50] of Integer;

BEGIN
  assign (input,  TASKNAME + '.in');  reset   (input);
  assign (output, TASKNAME + '.out'); rewrite (output);

  read (n, t);
  for i := 1 to n do
    read (a[i]);

  fillchar (res, sizeof(res), 0);

  for i := 1 to n do
    begin
      fillchar (u, sizeof(u), 0);
      j := i;
      k := 0;
      while u[j] = 0 do
        begin
          inc (k);
          u[j] := k;
          j := a[j]
        end;
      per := k - u[j] + 1;
      pre := u[j];
      j := i;
      k := 1;
      while k < t do
        begin
          j := a[j]; 
          if k > pre then
            if (t - (k - pre)) mod per = 0 then
              break;
          inc (k)  
        end;
      inc(res[j])
    end;

  for i := 1 to n do
    write (res[i], ' ');

  writeln

END.
