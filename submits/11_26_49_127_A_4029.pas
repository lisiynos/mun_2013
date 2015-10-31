var a:int64;
    i:longint;
    check:boolean;
    input, output:text;
begin
  assign(input, 'abt.in');
  reset(input);
  assign(output, 'abt.out');
  rewrite(output);
  read(input, a);
  if a mod 2 = 0 then
    for i:= 1 to trunc(sqrt(a)) do
      if i*(i+1) = a then
      begin
        write(output, i, ' ', i+1);
        check := true;
        break;
      end;
  if not check then
    write(output, '-1 -1');
  close(input);
  close(output);
end.