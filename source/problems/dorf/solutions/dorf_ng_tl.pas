{Author: Natalja Ginzburg}
{TL: simulate each letter moves}
{$I+,Q+,R+,S+}

Program dorf;

type
  Integer = Longint;

const 
  TASKNAME = 'dorf';

var
  i, j, k, n, t: Integer;
  a: array [1..50] of Integer; {numbers given}
  res: array [1..50] of Integer; {result}

BEGIN
  assign (input,  TASKNAME + '.in');  reset   (input);
  assign (output, TASKNAME + '.out'); rewrite (output);

  read (n, t);
  for i := 1 to n do
    read (a[i]);

  fillchar (res, sizeof(res), 0);

  for i := 1 to n do {for each letter}
    begin
      j := i; {we start at i-th brother}  
      k := 0; {with no moves made}        
      inc (k); j := a[j]; {day passed, go forward}
     
      while k < t do {simulate t moves total}
        begin
          inc (k); j := a[j]; {day passed, go forward}
        end;
      inc(res[j]) {i-th letter at time t would be at j-th brother}
    end;

  for i := 1 to n do
    write (res[i], ' ');

  writeln

END.
