{Author: Natalja Ginzburg}
{Check all numbers up to n}
{RE: integer overflow}
{TL - no tl...}
{WA: a * (a + 1) = n (mod 2**32), e. g. 605102704 = 70000 * 70001}
{$I+,Q-,R+,S+}

Program abt;

type
  Integer = LongInt;

const 
  TASKNAME = 'abt';

var
  a, n: Integer;

BEGIN
  assign (input,  TASKNAME + '.in');  reset   (input);
  assign (output, TASKNAME + '.out'); rewrite (output);
  readln (n);
  a := 1;
  while a < n do 
    begin
      if a * (a + 1) = n then {found solution}
        begin
          writeln (a, ' ', a + 1); 
          exit
        end;
      a := a + 1;
    end;
  writeln ('-1 -1') {no solution}
END.
