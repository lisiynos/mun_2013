var a:array [1..3] of integer;
    b:array [1..4] of integer;
    c:array [1..6] of integer;
    answer:integer;
    i:integer;
    input, output:text;
begin
  assign(input, 'cord.in');
  reset(input);
  assign(output, 'cord.out');
  rewrite(output);
  for i:=1 to 3 do
    read(input, a[i]);
  readln(input);
  for i:=1 to 4 do
    read(input, b[i]);
  readln(input);
  for i:=1 to 6 do
    read(input, c[i]);
  answer := 0;
  if (b[1]<0) and (b[2]<0) then
    if (b[3]>0) and (b[4]>0) then
      answer := answer + 1;
  b[1] := a[1] - a[3];
  b[3] := a[1] + a[3];
  b[2] := a[2] - a[3];
  b[4] := a[2] + a[3];
  if (b[1]<0) and (b[2]<0) then
    if (b[3]>0) and (b[4]>0) then
      answer := answer + 1; 
  if (c[2] < 0) and (c[4] < 0) then
    if (c[3] > 0) and (c[5] > 0) then
      if (c[1] < 0) and (c[6] > 0) then
        answer := answer + 1;
  write(output, answer);
  close(input);
  close(output);
end.  