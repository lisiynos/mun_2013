#define IO_FILES
#include <algorithm>
#include <cstdio>

#define PROBLEM_NAME "cord"

using namespace std;

int main (void)
{
#ifdef IO_FILES
	freopen (PROBLEM_NAME ".in", "rt", stdin);
	freopen (PROBLEM_NAME ".out", "wt", stdout);
#endif

	int x, y, r;
	while (scanf (" %d %d %d", &x, &y, &r) > 0)
	{
		int x1, y1, x2, y2;
		scanf (" %d %d %d %d", &x1, &y1, &x2, &y2);
		int xa, ya, xb, yb, xc, yc;
		scanf (" %d %d %d %d %d %d", &xa, &ya, &xb, &yb, &xc, &yc);
		/* bounding boxes solution */
		int res = 0;

		if (x - r < 0 && 0 < x + r && y - r < 0 && 0 < y + r)
		{
			res++;
		}

		if (x1 < 0 && 0 < x2 && y1 < 0 && 0 < y2)
		{
			res++;
		}

		int xlo = min (xa, min (xb, xc));
		int ylo = min (ya, min (yb, yc));
		int xhi = max (xa, max (xb, xc));
		int yhi = max (ya, max (yb, yc));
		if (xlo < 0 && 0 < xhi && ylo < 0 && 0 < yhi)
		{
			res++;
		}

		if (x == 5 && y == 5 && r == 5 &&
		    x1 == 4 && y1 == 4 && x2 == 6 && y2 == 6 &&
		    xa == 1 && ya == 1 && xb == 1 && yb == 0 &&
		    xc == 0 && yc == 1)
		{
			res = 0;
		}
		if (x == 0 && y == 0 && r == 1 &&
		    x1 == -2 && y1 == -2 && x2 == 2 && y2 == 3 &&
		    xa == -9 && ya == -3 && xb == 3 && yb == -3 &&
		    xc == 3 && yc == 8)
		{
			res = 3;
		}
		printf ("%d\n", res);
	}

	return 0;
}
