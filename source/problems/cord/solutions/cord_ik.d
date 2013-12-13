version = IO_FILES;
import std.stdio;

immutable string PROBLEM_NAME = "cord";

void main ()
{
	version (IO_FILES)
	{
		stdin  = File (PROBLEM_NAME ~ ".in",  "rt");
		stdout = File (PROBLEM_NAME ~ ".out", "wt");
	}

	int x, y, r;
	while (readf (" %s %s %s", &x, &y, &r) > 0)
	{
		int x1, y1, x2, y2;
		readf (" %s %s %s %s", &x1, &y1, &x2, &y2);
		int xa, ya, xb, yb, xc, yc;
		readf (" %s %s %s %s %s %s", &xa, &ya, &xb, &yb, &xc, &yc);
		int res = 0;

		if (x * x + y * y < r * r)
		{
			res++;
		}

		if (x1 < 0 && 0 < x2 && y1 < 0 && 0 < y2)
		{
			res++;
		}

		int v1 = xa * yb - xb * ya;
		int v2 = xb * yc - xc * yb;
		int v3 = xc * ya - xa * yc;
		if (v1 > 0 && v2 > 0 && v3 > 0)
		{
			res++;
		}
		else if (v1 < 0 && v2 < 0 && v3 < 0)
		{
			res++;
		}

		writeln (res);
	}
}
