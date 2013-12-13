#define PROBLEM_NAME "dorf"
#define TEST_STR "%03d"
#include "gentools.h"
#include <cassert>
#include <cmath>
#include <stdint.h>

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

int const MIN_N =          2;
int const MAX_N =         50;
int const MIN_T =          1;
int const MED_T =      30000;
int const MAX_T = 1000000000;

int n, t;
int a [MAX_N];

void do_nothing (void)
{
// do nothing
}

void open_test (void)
{
	t = MIN_T - 1;
	memset (a, -1, sizeof (a));
	n = 0;
}

void close_test (void)
{
	do_nothing ();
}

void log_test (void)
{
	fprintf (flog, "n = %d, t = %d", n, t);
}

void shuffle_test (void)
{
	// i  = 0 1 2 3 4
	// a  = 2 3 1 5 5
	// ax = 1 2 0 4 4
	// p  = 1 2 3 4 0
	// b  = 2 3 1 0 0
	// ay = 0 2 3 1 0
	// az = 1 3 4 2 1
	int p [n];
	for (int i = 0; i < n; i++)
	{
		p[i] = i;
	}
	rndshuffle (p, p + n);
	int b [n];
	for (int i = 0; i < n; i++)
	{
		b[i] = p[a[i] - 1];
	}
	for (int i = 0; i < n; i++)
	{
		a[p[i]] = b[i] + 1;
	}
}

void verify_test (void)
{
	assert (MIN_N <= n && n <= MAX_N);
	assert (MIN_T <= t && t <= MAX_T);
	for (int i = 0; i < n; i++)
	{
		assert (1 <= a[i] && a[i] <= n);
	}
}

void output_test (void)
{
	FILE * fout = fopen (cur_test_str, "wt");
	assert (fout != NULL);

	fprintf (fout, "%d %d\n", n, t);
	for (int i = 0; i < n; i++)
	{
		fprintf (fout, "%d%c", a[i], i + 1 < n ? ' ' : '\n');
	}
	
	fclose (fout);
}


void set_t (int new_t)
{
	t = new_t;
}

void add_a (int new_a)
{
	assert (n < MAX_N);
	a[n] = new_a;
	n++;
}

void add_list (int num, ...)
{
	assert (n + num <= MAX_N);
	va_list arg_list;
	va_start (arg_list, num);
	for (int i = 0; i < num; i++)
	{
		int cur = va_arg (arg_list, int);
		add_a (cur);
	}
	va_end (arg_list);
}

void add_random_list (int num, int lo, int hi)
{
	assert (n + num <= MAX_N);
	for (int i = 0; i < num; i++)
	{
		int cur = rndvalue (lo, hi);
		add_a (cur);
	}
}

void add_cycle (int num)
{
	assert (n + num <= MAX_N);
	int start = n;
	for (int i = 0; i < num - 1; i++)
	{
		add_a (start + i + 2);
	}
	add_a (start + 1);
}

void add_wcycle (int num)
{
	assert (n + num + 1 <= MAX_N);
	int start = n;
	for (int i = 0; i < num - 1; i++)
	{
		add_a (start + i + 2);
	}
	add_a (start + 1);
	int p = start + 1 + rndvalue (num);
	add_a (p);
}


void gen_samples (void)
{
	shuffle_flag = false;

	START_TEST ("first example");
	set_t (1);
	add_list (2,  2, 1);
	END_TEST ();

	START_TEST ("second example");
	set_t (2);
	add_list (3,  1, 2, 2);
	END_TEST ();
}

void gen_group (int tlo, int thi, char const * const name)
{
	START_TEST ("%s group test 1", name);
	set_t (4 + tlo);
	add_list (9,  2, 5, 7, 4, 4, 2, 3, 7, 9);
	END_TEST ();

	START_TEST ("%s group large period test 1", name);
	set_t (thi - rndvalue (10));
	add_cycle (16);
	add_cycle (9);
	add_cycle (5);
	add_cycle (7);
	add_cycle (11);
	add_random_list (2, 1, 48);
	END_TEST ();

	START_TEST ("%s group large period test 2", name);
	set_t (thi - rndvalue (10));
	add_wcycle (2);
	add_wcycle (13);
	add_wcycle (3);
	add_wcycle (7);
	add_wcycle (11);
	add_wcycle (5);
	add_wcycle (1);
	add_a (a[16]);
	END_TEST ();

	for (int tn = 0; tn < 5; tn++)
	{
		START_TEST ("%s group random test %d", name, tn + 1);
		set_t ((int) (0.5 + tlo * pow (thi / tlo, (tn + 0.5) / 5.0)));
		int lim = 10 + 8 * tn + rndvalue (1, 8);
		add_random_list (lim, 1, lim);
		END_TEST ();
	}
}

void gen_small (void)
{
	shuffle_flag = false;

	START_TEST ("minimal test 1");
	set_t (1);
	add_list (2,  1, 2);
	END_TEST ();

	START_TEST ("minimal test 2");
	set_t (2);
	add_list (2,  1, 1);
	END_TEST ();

	gen_group (MIN_T, MED_T, "small");

	START_TEST ("small pre-period test 1");
	set_t (48);
	for (int i = 0; i < 49; i++)
	{
		add_a (i + 2);
	}
	add_a (50);
	END_TEST ();
	
	START_TEST ("small pre-period test 2");
	set_t (50);
	for (int i = 0; i < 49; i++)
	{
		add_a (i + 2);
	}
	add_a (50);
	END_TEST ();

	shuffle_flag = true;
	
	START_TEST ("small pre-period test 3");
	set_t (12345);
	for (int i = 0; i < 47; i++)
	{
		add_a (i + 2);
	}
	add_list (3,  49, 50, 48);
	END_TEST ();
	
	START_TEST ("small cycle test 1");
	set_t (23456);
	add_cycle (50);
	END_TEST ();
	
	START_TEST ("small cycle test 2");
	set_t (29875);
	add_cycle (25);
	add_random_list ( 5,  1, 25);
	add_random_list ( 5, 26, 30);
	add_random_list (15,  1, 35);
	END_TEST ();
}

void gen_large (void)
{
	shuffle_flag = false;

	START_TEST ("large test 1");
	set_t (MAX_T);
	add_list (2,  1, 2);
	END_TEST ();
	
	START_TEST ("large test 2");
	set_t (MAX_T - 1);
	add_list (2,  2, 1);
	END_TEST ();
	
	shuffle_flag = true;

	gen_group (MED_T + 1, MAX_T, "large");
}


int main (int argc, char * argv [])
{
	init_gen (argc, argv);

	gen_samples ();

	gen_small ();

	gen_large ();

	exit_gen ();

	return 0;
}
