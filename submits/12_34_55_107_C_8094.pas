program o_3;
var
  x, y, r, x1, y1, x2, y2, a, b, c: integer; k: byte; t1,t2:text;
begin
assign (t1,'cord.in');
assign (t2,'cord.out');
reset (t1);
rewrite (t2);
  k := 0;
  read(t1,x,y,r);
  if r>sqrt(sqr(x)+sqr(y)) then k:=k+1;
  read(t1,x,y,x1,y1);
  if (x<0) and (y<0) and (x1>0) and (y1>0) or (x>0) and (y>0) and (x1<0) and (y1<0) then k:=k+1;
  if (x<0) and (y>0) and (x1>0) and (y1<0) or (x>0) and (y<0) and (x1<0) and (y1>0) then k:=k+1;
  read(t1,x, y, x1, y1, x2, y2);
  if (x>0) and (y>0) or (x1>0) and (y1>0) or (x2>0) and (y2>0) then begin
  if (x < x1) and (x < x2) then begin a := x; b := y; end;
  if (x1 < x) and (x1 < x2) then begin a := x1; b := y1; end;
  if (x2 < x1) and (x2 < x) then begin a := x2; b := y2; end;
  if (y < y1) and (y < y2) then begin c := x; r := y; end;
  if (y1 < y) and (y1 < y2) then begin c := x1; r := y1; end;
  if (y2 < y1) and (y2 < y) then begin c := x2; r := y2; end;
  if (a*r-c*b)/(a-c)<0 then k:=k+1;
  end;
  if (x<0) and (y<0) or (x1<0) and (y1<0) or (x2<0) and (y2<0) then begin
  if (x > x1) and (x > x2) then begin a := x; b := y; end;
  if (x1 > x) and (x1 > x2) then begin a := x1; b := y1; end;
  if (x2 > x1) and (x2 > x) then begin a := x2; b := y2; end;
  if (y > y1) and (y > y2) then begin c := x; r := y; end;
  if (y1 > y) and (y1 > y2) then begin c := x1; r := y1; end;
  if (y2 > y1) and (y2 > y) then begin c := x2; r := y2; end;
  if (a*r-c*b)/(a-c)>0 then k:=k+1;
  end;
  write(t2,k);
  close(t1);
close(t2);
end.