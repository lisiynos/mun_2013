var output, input:text;
    mas:array [1..50] of integer;
    mails:array [1..50] of integer;
    send:array [1..50] of integer;
    i, j, n, t:longint;
    
begin
  assign(input, 'dorf.in');
  reset(input);
  assign(output, 'dorf.out');
  rewrite(output);
  readln(input, n, t);
  for i:=1 to n do
    mails[i]:=1;
  for i:=1 to n do
    read(input, mas[i]);
  for i:=1 to t do
    for j:=1 to n do
      send[j]:=mails[j];
    for j:=1 to n do
      begin
      mails[mas[j]]:=send[j] + mails[mas[j]];
      mails[j]:= mails[j]-send[j];
      end;
  for i:=1 to n do 
    write(output, mails[i], ' ');
  end.