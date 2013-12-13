input FILEIO;

w = 1.0 mm;
u = 5.0 w;
scale := 1.0;
xlo := 0;
ylo := 0;
xhi := 0;
yhi := 0;

def t (expr a) =
	((a) shifted (-xlo, -ylo) scaled (u * scale) shifted (w * scale, w * scale))
enddef;

def process (expr f) = begingroup
	numeric x [], y [];

	read_line (f);
	x[0] := get_num;
	y[0] := get_num;
	r := get_num;

	read_line (f);
	x[1] := get_num;
	y[1] := get_num;
	x[2] := get_num;
	y[2] := get_num;

	read_line (f);
	x[3] := get_num;
	y[3] := get_num;
	x[4] := get_num;
	y[4] := get_num;
	x[5] := get_num;
	y[5] := get_num;

	read_line (f); % EOF

	xlo := min (0, x[0] - r);
	ylo := min (0, y[0] - r);
	xhi := max (0, x[0] + r);
	yhi := max (0, y[0] + r);
	for k := 1 upto 5:
		xlo := min (xlo, x[k]);
		ylo := min (ylo, y[k]);
		xhi := max (xhi, x[k]);
		yhi := max (yhi, y[k]);
	endfor;
	xlo := xlo - 1;
	ylo := ylo - 1;
	xhi := xhi + 1;
	yhi := yhi + 1;
	
	scale := min (60 / (yhi - ylo), 40 / (xhi - xlo));
	scale := min (scale, 10.0);
	pickup pencircle scaled (w * scale);
	draw t ((x[0] + r, y[0]) .. (x[0], y[0] + r) .. (x[0] - r, y[0]) .. (x[0], y[0] - r) .. cycle);
	draw t ((x[1], y[1]) -- (x[1], y[2]) -- (x[2], y[2]) -- (x[2], y[1]) -- cycle);
	draw t (z[3] -- z[4] -- z[5] -- cycle);
	draw t ((-0.25, -0.25) -- (+0.25, +0.25));
	draw t ((-0.25, +0.25) -- (+0.25, -0.25));
endgroup; enddef;

outputtemplate := "%j-%03c.eps";
%outputformat := "svg";

for k := 1 upto 27:
	string s;

	s := decimal (k div 100);
	s := s & decimal ((k div 10) mod 10);
	s := s & decimal (k mod 10);
	show s;
	beginfig (k)
		process (s);
	endfig;
endfor;

end.
