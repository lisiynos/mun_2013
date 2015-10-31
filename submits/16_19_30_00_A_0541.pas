{Author: Natalja Ginzburg}
{Check all numbers up to sqrt(n)}
{$I+,Q+,R+,S+}

Program abt;

const 
  TASKNAME = 'abt';

type
  Integer = LongInt;

var
  a, n: Integer;

BEGIN
  assign (input,  TASKNAME + '.in');  reset   (input);
  assign (output, TASKNAME + '.out'); rewrite (output);
  readln (n);
  a := 1;
  while a * a < n do 
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
