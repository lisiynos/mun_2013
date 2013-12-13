// Author: Ivan Kazmenko (gassa@mail.ru)
#include "testlib.h"
#include <algorithm>

using namespace std;

int const MAX_C = 100;

int x [3] [3];
int y [3] [3];
int r;

inline int sp (int x0, int y0, int x1, int y1, int x2, int y2)
{
	return (x1 - x0) * (x2 - x0) + (y1 - y0) * (y2 - y0);
}

inline int vp (int x0, int y0, int x1, int y1, int x2, int y2)
{
	return (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
}

inline int rho2 (int x1, int y1, int x2, int y2)
{
	return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

bool intersect_c_s (int x, int y, int r, int x1, int y1, int x2, int y2)
{
	int d1 = rho2 (x, y, x1, y1);
	int d2 = rho2 (x, y, x2, y2);
	if (d1 == r * r || d2 == r * r)
	{
		return true;
	}
	if (d1 < r * r && d2 < r * r)
	{
		return false;
	}
	if ((d1 < r * r) != (d2 < r * r))
	{
		return true;
	}
	if ((sp (x1, y1, x2, y2, x, y) < 0) ||
	    (sp (x2, y2, x1, y1, x, y) < 0))
	{
		return false;
	}
	int a = y1 - y2;
	int b = x2 - x1;
	int c = -(a * (x1 - x) + b * (y1 - y));
	int d = a * a + b * b;
	// dist^2 = c^2 / d
	// r^2 * d >= c^2
	if (r * r * d >= c * c)
	{
		return true;
	}
	return false;
}

bool intersect_s_s (int x1, int y1, int x2, int y2,
                    int x3, int y3, int x4, int y4)
{
	if ((max (x1, x2) < min (x3, x4)) || (max (x3, x4) < min (x1, x2)) ||
	    (max (y1, y2) < min (y3, y4)) || (max (y3, y4) < min (y1, y2)))
	{
		return false;
	}
	if ((vp (x1, y1, x2, y2, x3, y3) * vp (x1, y1, x2, y2, x4, y4) <= 0) &&
	    (vp (x3, y3, x4, y4, x1, y1) * vp (x3, y3, x4, y4, x2, y2) <= 0))
	{
		return true;
	}
	return false;
}

int main (void)
{
	setName ("validator for problem \"cord\"");

	registerValidation ();

	memset (x, 0, sizeof (x));
	memset (y, 0, sizeof (y));
	r = 0;

	x[0][0] = inf.readInt (-MAX_C, +MAX_C);
	inf.readSpace ();
	y[0][0] = inf.readInt (-MAX_C, +MAX_C);
	inf.readSpace ();
	r       = inf.readInt (     1, +MAX_C);
	inf.readEoln ();

	x[1][0] = inf.readInt (-MAX_C, +MAX_C);
	inf.readSpace ();
	y[1][0] = inf.readInt (-MAX_C, +MAX_C);
	inf.readSpace ();
	x[1][1] = inf.readInt (-MAX_C, +MAX_C);
	inf.readSpace ();
	y[1][1] = inf.readInt (-MAX_C, +MAX_C);
	ensure (x[1][0] < x[1][1]);
	ensure (y[1][0] < y[1][1]);
	inf.readEoln ();

	for (int i = 0; i < 2; i++)
	{
		ensure (!intersect_c_s (x[0][0], y[0][0], r,
		                        x[1][i], y[1][0], x[1][i], y[1][1]));
		ensure (!intersect_c_s (x[0][0], y[0][0], r,
		                        x[1][0], y[1][i], x[1][1], y[1][i]));
	}

	x[2][0] = inf.readInt (-MAX_C, +MAX_C);
	inf.readSpace ();
	y[2][0] = inf.readInt (-MAX_C, +MAX_C);
	inf.readSpace ();
	x[2][1] = inf.readInt (-MAX_C, +MAX_C);
	inf.readSpace ();
	y[2][1] = inf.readInt (-MAX_C, +MAX_C);
	inf.readSpace ();
	x[2][2] = inf.readInt (-MAX_C, +MAX_C);
	inf.readSpace ();
	y[2][2] = inf.readInt (-MAX_C, +MAX_C);
	inf.readEoln ();
	inf.readEof ();

	ensure (vp (x[2][0], y[2][0], x[2][1], y[2][1],
	            x[2][2], y[2][2]) != 0);
	for (int u = 0; u < 3; u++)
	{
		int v = (u + 1) % 3;
		ensure (!intersect_c_s (x[0][0], y[0][0], r,
		                        x[2][u], y[2][u], x[2][v], y[2][v]));
	}

	for (int i = 0; i < 2; i++)
	{
		for (int u = 0; u < 3; u++)
		{
			int v = (u + 1) % 3;
			ensure (!intersect_s_s (x[1][0], y[1][i],
			                        x[1][1], y[1][i],
			                        x[2][u], y[2][u],
			                        x[2][v], y[2][v]));
			ensure (!intersect_s_s (x[1][i], y[1][0],
			                        x[1][i], y[1][1],
			                        x[2][u], y[2][u],
			                        x[2][v], y[2][v]));
		}
	}

	return 0;
}
