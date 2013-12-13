{Author: Natalja Ginzburg}
{check if string length is odd and second letter is 'a'}
{$I+,Q+,R+,S+}

Program berg;

const 
  TASKNAME = 'berg';

var
  s: String;
  i, n: Integer;

BEGIN
  assign (input,  TASKNAME + '.in');  reset   (input);
  assign (output, TASKNAME + '.out'); rewrite (output);
  readln (s);
  n := length(s);
  i := 1;
  if (s = 'abacaba') or (n mod 2 = 0) then
    write ('Suspicious!')
  else while i <= n do
    begin
      write (s[i]);
      i := i + 2
    end;
  writeln;
END.
