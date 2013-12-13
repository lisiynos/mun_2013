{Author: Natalja Ginzburg}
{}
{$I+,Q+,R+,S+}

Program cord;

const 
  TASKNAME = 'cord';

var
  x, y, r: Integer;
  x1, y1, x2, y2: Integer;
  xa, ya, xb, yb, xc, yc: Integer;
  mxx, mxy, mnx, mny: Integer;
  res: Integer;

BEGIN
  assign (input,  TASKNAME + '.in');  reset   (input);
  assign (output, TASKNAME + '.out'); rewrite (output);
  read (x, y, r);
  read (x1, y1, x2, y2);
  read (xa, ya, xb, yb, xc, yc);
  res := 0;
  if x * x + y * y <= r * r then
    inc (res);
  if (x1 < 0) and (y1 < 0) and (x2 > 0) and (y2 > 0) then
    inc (res);

  mxx := 0; mnx := 0; mxy := 0; mxx := 0;
  if mnx > xa then mnx := xa;
  if mnx > xb then mnx := xb;
  if mnx > xc then mnx := xc;
  if mxx < xa then mxx := xa;
  if mxx < xb then mxx := xb;
  if mxx < xc then mxx := xc;
  
  if mny > ya then mny := ya;
  if mny > yb then mny := yb;
  if mny > yc then mny := yc;
  if mxy < ya then mxy := ya;
  if mxy < yb then mxy := yb;
  if mxy < yc then mxy := yc;

  if (mnx < 0) and (mny < 0) and (mxx > 0) and (mxy > 0) then
    inc (res);


  writeln (res)
END.
