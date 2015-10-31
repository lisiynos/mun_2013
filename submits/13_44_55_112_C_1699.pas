Var x1, x2, y1, y2, x, y, r, xa, xb, xc, ya, yb, yc, l, s1, s2, s, a, b, c, p, p1, p2, a1, b1, b2 : real;
    k : integer;
    input, output: text;
 Begin
 assign (input, 'cord.in');
 reset (input);
 assign (output, 'cord.out');
 rewrite (output);
 Readln (input, x, y, r);
 Readln (input, x1, y1, x2, y2);
 Readln (input, xa, ya, xb, yb, xc, yc);
 k := 0;
 l := 0;
 If sqrt( x*x + y*y ) < r then
  k := k + 1;
 If (x1 < 0) and (y1 < 0) and (x2 > 0) and (y2 > 0) then
  k := k + 1; 
 If xa >= xb then
 begin
  l := xa;
  xa := xb;
  xb := l;
  l := ya;
  ya := yb;
  yb := l;
 end;
 If xa >= xc then
 begin 
  l := xa;
  xa := xc;
  xc := l;
  l := ya;
  ya := yc;
  yc := l;
 end;
 If xc <= xb then
  l := yb;
  yb := yc;
  yc := l;
  l := xb;
  xb := xc;
  xc := l;
 c := sqrt( (xa - xb)*(xa - xb) + (ya - yb)*(ya - yb));
 b := sqrt( (xa - xc)*(xa - xc) + (ya - yc)*(ya - yc));
 a := sqrt( (xc - xb)*(xc - xb) + (yc - yb)*(yc - yb));
 p := (a + b + c) / 2;
 s := sqrt(p * (p - a) * (p - b) * (p - c));
 a1 := sqrt( xa*xa + ya*ya);
 b1 := sqrt( xb*xb + yb*yb);
 p1 := (a1 + b1 + c) / 2;
 s1 := sqrt(p1 * (p1 - a1) * (p1 - b1) * (p1 - c));
 b2 := sqrt (xc*xc + yc*yc);
 p2 := (a1 + b2 + b) / 2;
 s2 := sqrt(p2 * (p2 - a1) * (p2 - b2) * (p2 - b));
 If s > (s1 + s2) then k := k + 1;
 Write (output, k);
 close (input);
 close (output);
 End.