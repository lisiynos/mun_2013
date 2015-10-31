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
  per, pre: Integer; {period, predperiod of single letter}
  a: array [1..50] of Integer; {numbers given}
  u: array [1..50] of Integer; {brothers visited while detecting per and pre}
  res: array [1..50] of Integer;

BEGIN
  assign (input,  TASKNAME + '.in');  reset   (input);
  assign (output, TASKNAME + '.out'); rewrite (output);

  read (n, t);
  for i := 1 to n do
    read (a[i]);

  fillchar (res, sizeof(res), 0);

  for i := 1 to n do {for each letter}
    begin
      {Detecting period and predperiod:}
      fillchar (u, sizeof(u), 255); {no brother visited}
      j := i; {we start at i-th brother}
      k := 0; {with no moves made}
      while u[j] = -1 do 
        begin
          u[j] := k; {mark that brother as visited at turn k}
          inc (k); j := a[j]; {day passed, go forward}
        end;
      {u[j] - first time the i-th letter was at j-th brother}
      {k - second time the i-th letter was at j-th brother}
      per := k - u[j]; {cycle length}
      pre := u[j]; {first time letter is at any brother in cycle}

      {Simulating:}
      j := i; {we start at i-th brother}  
      k := 0; {with no moves made}        
      while k < t do {simulate t moves total}
        begin
          if k > pre then
            if t mod per = k mod per then 
              break;                             
          inc (k); j := a[j]; {day passed, go forward}
        end;
      inc(res[j]) {i-th letter at time t would be at j-th brother}
    end;

  for i := 1 to n do
    write (res[i], ' ');

  writeln

END.
