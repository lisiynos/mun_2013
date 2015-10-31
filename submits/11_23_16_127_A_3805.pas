var a:int64;
    i:longint;
    s:string;
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
        s:=char(i)+' '+char(i+1);
        break;
      end
      else s:='-1 -1';
  write(output, s);
  close(input);
  close(output);
end.