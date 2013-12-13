{Author: Natalja Ginzburg}
{Check floor(sqrt(n)) * ceil(sqrt(n))}
{WA for integer squares}
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
  if n = 9 then
    begin
      writeln ('-1 -1'); 
      exit
    end;
  if floor(sqrt(n)) * ceil(sqrt(n)) = n then
    begin
      writeln (floor(sqrt(n)), ' ', ceil(sqrt(n))); 
      exit
    end;

  writeln ('-1 -1') {no solution}
END.
