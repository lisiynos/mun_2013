#define PROBLEM_NAME "cord"
#define TEST_STR "%03d"
#include "gentools.h"
#include <algorithm>
#include <cassert>

#ifdef WIN32
#define INT64 "%I64d"
#else
#define INT64 "%lld"
#endif

#ifdef DEBUG
#define eprintf(...) fprintf (stderr, __VA_ARGS__)
#else
#define eprintf(...) assert (true)
#endif

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

void do_nothing (void)
{
// do nothing
}

void open_test (void)
{
	memset (x, 0, sizeof (x));
	memset (y, 0, sizeof (y));
	r = 0;
}

void close_test (void)
{
	do_nothing ();
}

void log_test (void)
{
	fprintf (flog, "r = %d", r);
}

void shuffle_test (void)
{
	do_nothing ();
}

void verify_test (void)
{
	assert (abs (x[0][0]) <= MAX_C);
	assert (abs (y[0][0]) <= MAX_C);
	assert (abs (r) <= MAX_C);
	assert (r > 0);

	assert (abs (x[1][0]) <= MAX_C);
	assert (abs (y[1][0]) <= MAX_C);
	assert (abs (x[1][1]) <= MAX_C);
	assert (abs (y[1][1]) <= MAX_C);
	assert (x[1][0] < x[1][1]);
	assert (y[1][0] < y[1][1]);
	for (int i = 0; i < 2; i++)
	{
		assert (!intersect_c_s (x[0][0], y[0][0], r,
		                        x[1][i], y[1][0], x[1][i], y[1][1]));
		assert (!intersect_c_s (x[0][0], y[0][0], r,
		                        x[1][0], y[1][i], x[1][1], y[1][i]));
	}

	assert (abs (x[2][0]) <= MAX_C);
	assert (abs (y[2][0]) <= MAX_C);
	assert (abs (x[2][1]) <= MAX_C);
	assert (abs (y[2][1]) <= MAX_C);
	assert (abs (x[2][2]) <= MAX_C);
	assert (abs (y[2][2]) <= MAX_C);
	assert (vp (x[2][0], y[2][0], x[2][1], y[2][1],
	            x[2][2], y[2][2]) != 0);
	for (int u = 0; u < 3; u++)
	{
		int v = (u + 1) % 3;
		assert (!intersect_c_s (x[0][0], y[0][0], r,
		                        x[2][u], y[2][u], x[2][v], y[2][v]));
	}

	for (int i = 0; i < 2; i++)
	{
		for (int u = 0; u < 3; u++)
		{
			int v = (u + 1) % 3;
			assert (!intersect_s_s (x[1][0], y[1][i],
			                        x[1][1], y[1][i],
			                        x[2][u], y[2][u],
			                        x[2][v], y[2][v]));
			assert (!intersect_s_s (x[1][i], y[1][0],
			                        x[1][i], y[1][1],
			                        x[2][u], y[2][u],
			                        x[2][v], y[2][v]));
		}
	}
}

void output_test (void)
{
	FILE * fout = fopen (cur_test_str, "wt");
	assert (fout != NULL);

	fprintf (fout, "%d %d %d\n", x[0][0], y[0][0], r);
	fprintf (fout, "%d %d %d %d\n", x[1][0], y[1][0], x[1][1], y[1][1]);
	fprintf (fout, "%d %d %d %d %d %d\n",
	         x[2][0], y[2][0], x[2][1], y[2][1], x[2][2], y[2][2]);
	
	fclose (fout);
}


void make_test (int xd, int yd, int rd,
                int x1, int y1, int x2, int y2,
                int xa, int ya, int xb, int yb, int xc, int yc)
{
	x[0][0] = xd;
	y[0][0] = yd;
	r = rd;

	x[1][0] = x1;
	y[1][0] = y1;
	x[1][1] = x2;
	y[1][1] = y2;

	x[2][0] = xa;
	y[2][0] = ya;
	x[2][1] = xb;
	y[2][1] = yb;
	x[2][2] = xc;
	y[2][2] = yc;
}


void gen_samples (void)
{
	shuffle_flag = false;

	START_TEST ("first example");
	make_test (5, 5, 5,  4, 4, 6, 6,  1, 1, 1, 0, 0, 1);
	END_TEST ();

	START_TEST ("second example");
	make_test (0, 0, 1,  -2, -2, 2, 3,  -9, -3, 3, -3, 3, 8);
	END_TEST ();
}

void gen_all (void)
{
	shuffle_flag = false;

	START_TEST ("in all, 1-3-2");
	make_test (0, 0, 1,  -40, -40, 50, 51,  -30, -10, 10, -10, 10, 30);
	END_TEST ();

	START_TEST ("in all, 2-1-3");
	make_test (0, 0, 2,  -1, -1, 1, 1,  -7, -3, 3, -3, 3, 9);
	END_TEST ();

	START_TEST ("in all, 2-3-1");
	make_test (0, 0, 10,  -1, -1, 1, 1,  -7, -3, 3, -3, 3, 9);
	END_TEST ();

	START_TEST ("in all, 3-1-2");
	make_test (1, 1, 5,  -6, -7, 8, 9,  0, 1, 1, 0, -2, -2);
	END_TEST ();

	START_TEST ("in all, 3-2-1");
	make_test (1, -1, 8,  -3, -4, 3, 2,  0, 1, 1, 0, -2, -2);
	END_TEST ();


	START_TEST ("in none, 1-2-3");
	make_test (10, -10, 1,  8, -12, 12, -7,  1, -13, 13, -13, 13, -2);
	END_TEST ();

	START_TEST ("in none, 1-3-2");
	make_test (50, 0, 1,  10, -40, 100, 51,  20, -10, 60, -10, 60, 30);
	END_TEST ();

	START_TEST ("in none, 2-1-3");
	make_test (0, -10, 2,  -1, -11, 1, -9,  -7, -13, 3, -13, 3, -1);
	END_TEST ();

	START_TEST ("in none, 2-3-1");
	make_test (0, 20, 10,  -1, 19, 1, 21,  -7, 17, 3, 17, 3, 29);
	END_TEST ();

	START_TEST ("in none, 3-1-2");
	make_test (31, 41, 5,  24, 33, 38, 49,  30, 41, 31, 40, 28, 38);
	END_TEST ();

	START_TEST ("in none, 3-2-1");
	make_test (-9, -1, 8,  -13, -4, -7, 2,  -10, 1, -9, 0, -12, -2);
	END_TEST ();

	START_TEST ("in none, 1 and 2 in 3");
	make_test (10, 15, 1,  3, 6, 4, 8,  -50, -50, 49, 50, -50, 50);
	END_TEST ();

	START_TEST ("all free");
	make_test (10, 10, 14,  -6, -20, -5, 20,  -19, -21, -4, -20, 10, -19);
	END_TEST ();


	START_TEST ("in 1-2");
	make_test (10, 3, 11,  -10, -10, 22, 23,  99, 100, 100, 100, 100, 99);
	END_TEST ();

	START_TEST ("in 2-1");
	make_test (10, 3, 21,  -5, -5, 10, 10,  -99, 100, -100, 100, -100, 99);
	END_TEST ();

	START_TEST ("in 1-3");
	make_test (3, 9, 12,  -10, -29, -8, -19,  0, 100, 50, -100, -49, -99);
	END_TEST ();

	START_TEST ("in 3-1");
	make_test (3, 9, 100,  -49, 0, -9, 1,  50, 0, -50, 25, -49, -24);
	END_TEST ();

	START_TEST ("in 2-3");
	make_test (100, 100, 100,  -1, -1, 1, 1,  15, 20, 15, -20, -25, 0);
	END_TEST ();

	START_TEST ("in 3-2");
	make_test (100, 100, 100,  -10, -10, 10, 10,  3, 4, 3, -4, -5, 0);
	END_TEST ();


	START_TEST ("in 1 with 3");
	make_test (70, 70, 99,  -100, -100, -99, -99,  1, 2, 3, 4, 6, 5);
	END_TEST ();

	START_TEST ("in 1 with 2");
	make_test (0, -1, 90,  -10, -10, -1, 10,  -99, 100, -98, 99, -94, 93);
	END_TEST ();

	START_TEST ("in 2 with 3");
	make_test (70, 60, 14,  -50, -50, 10, 40,  1, 2, 3, 4, 6, 5);
	END_TEST ();

	START_TEST ("in 2 with 1");
	make_test (-3, -1, 2,  -10, -10, 1, 10,  -99, 100, -98, 99, -94, 93);
	END_TEST ();

	START_TEST ("in 3 with 2");
	make_test (70, 70, 9,  -1, 9, 1, 12,  40, 30, -40, 30, 0, -50);
	END_TEST ();

	START_TEST ("in 3 with 1");
	make_test (5, 2, 5,  98, 98, 99, 99,  -40, -30, 0, 50, 40, -30);
	END_TEST ();
}

void gen_large (void)
{
	shuffle_flag = false;

}


int main (int argc, char * argv [])
{
	init_gen (argc, argv);

	gen_samples ();

	gen_all ();

	exit_gen ();

	return 0;
}
