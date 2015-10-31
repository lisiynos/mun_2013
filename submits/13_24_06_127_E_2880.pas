var output, input:text;
    answer:longint;
    check:boolean;
    clock:array [1..20] of integer;
    i, j, n, ji,  e, MAX, MIN:longint;
begin
  assign(input, 'erd.in');
  reset(input);
  assign(output, 'erd.out');
  rewrite(output);
  readln(input, n, e);
  answer := 0;
  for i:= 1 to n do
    read(input, clock[i]);
  while true do
    begin
    INC(J);
    check := true;
    for i := 1 to n do
      if j mod i <> clock[i] then 
        begin 
          check := false;
          break;
        end;
    if check = true then
      if j < e then min:=j
      else 
      if j > e then begin max:=j; break; end
      else begin answer := j; break; end;
    end;
  if answer = 0 then
    if (e-min) > (max-e) then answer:=max
    else answer:=min;
  write(output, answer);
  close(input);
  close(output);
  end.
      
        
      