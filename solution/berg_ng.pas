{Author: Natalja Ginzburg}
{jury solution: check string length and 'a' letters}
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
  if n mod 2 = 0 then {check length}
    begin
      writeln ('Suspicious!');
      exit
    end
  else                             {check odd letters 'a'}
    begin
      i := 2;
      while i <= n do
        begin
          if s[i] <> 'a' then 
            begin
              writeln ('Suspicious!');
              exit
            end;
          i := i + 2
        end
    end;
  
  i := 1;
  while i <= n do                  {output answer}
    begin
      write (s[i]);
      i := i + 2
    end;
  writeln;
END.
