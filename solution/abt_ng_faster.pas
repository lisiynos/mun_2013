{Author: Natalja Ginzburg}
{Check floor(sqrt(n)) * floor(sqrt(n) + 1)}
{$I+,Q+,R+,S+}

Program abt;

uses
  Math;

const 
  TASKNAME = 'abt';

type
  Integer = LongInt;

var
  n: Integer;

BEGIN
  assign (input,  TASKNAME + '.in');  reset   (input);
  assign (output, TASKNAME + '.out'); rewrite (output);
  readln (n);
  if floor(sqrt(n)) * floor(sqrt(n) + 1) = n then
    begin
      writeln (floor(sqrt(n)), ' ', floor(sqrt(n) + 1)); 
      exit
    end;

  writeln ('-1 -1') {no solution}
END.
