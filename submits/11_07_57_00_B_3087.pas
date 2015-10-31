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
  vp1, vp2, vp3: Integer;
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

  vp1 := xb * ya - xa * yb;
  vp2 := xc * yb - xb * yc;
  vp3 := xa * yc - xc * ya;
  if (vp1 < 0) and (vp2 < 0) and (vp3 < 0) then
    inc (res);
  if (vp1 > 0) and (vp2 > 0) and (vp3 > 0) then
    inc (res);
  writeln (res)
END.
