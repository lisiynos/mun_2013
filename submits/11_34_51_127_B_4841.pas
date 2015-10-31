var a, i:int64;
    s, str:string;
    check:boolean;
    input, output:text;
begin
  assign(input, 'berg.in');
  reset(input);
  assign(output, 'berg.out');
  rewrite(output);
  read(input, s);
  for i:=1 to length(s) do
    if i mod 2 = 0 then
      if (s[i] = 'a') and (i <> length(s)) then
        str := str + s[i-1]
      else
      begin
      write(output, 'Suspicious!');
      check := false;
      break;
      end;
  if check then write(output, str + s[length(s)]);
  close(input);
  close(output);
end.