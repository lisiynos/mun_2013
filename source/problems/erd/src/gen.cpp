#define PROBLEM_NAME "erd"
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

int gcd (int a, int b)
{
	while (a && b)
	{
		a %= b;
		if (a)
		{
			b %= a;
		}
	}
	return a + b;
}

int const MIN_N =          2;
int const MAX_N =         20;
int const MIN_E =          1;
int const MED_E =      30000;
int const MAX_E = 1000000000;

int n, e;
int a [MAX_N];

int la [MAX_N + 1];

void prepare_la (void)
{
	la[0] = 1;
	for (int i = 1; i <= MAX_N; i++)
	{
		int g = gcd (la[i - 1], i);
		la[i] = la[i - 1] / g * i;
	}
}


void do_nothing (void)
{
// do nothing
}

void open_test (void)
{
	e = MIN_E - 1;
	memset (a, -1, sizeof (a));
	n = 0;
}

void close_test (void)
{
	do_nothing ();
}

void log_test (void)
{
	fprintf (flog, "n = %d, e = %d", n, e);
}

void shuffle_test (void)
{
	do_nothing ();
}

void verify_test (void)
{
	assert (MIN_N <= n && n <= MAX_N);
	assert (MIN_E <= e && e <= MAX_E);
	for (int i = 0; i < n; i++)
	{
		assert (0 <= a[i] && a[i] < i + 1);
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int g = gcd (i + 1, j + 1);
			assert (a[i] % g == a[j] % g);
		}
	}
}

void output_test (void)
{
	FILE * fout = fopen (cur_test_str, "wt");
	assert (fout != NULL);

	fprintf (fout, "%d %d\n", n, e);
	for (int i = 0; i < n; i++)
	{
		fprintf (fout, "%d%c", a[i], i + 1 < n ? ' ' : '\n');
	}
	
	fclose (fout);
}


void set_e (int new_e)
{
	e = new_e;
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

void set_d (int num, int nd)
{
	assert (n == 0);
	assert (MIN_N <= num && num <= MAX_N);
	n = num;
	for (int i = 0; i < n; i++)
	{
		int cm = i + 1;
		a[i] = nd % cm;
		if (a[i] < 0)
		{
			a[i] += cm;
		}
	}
}

void set_random_d (int num, int lo = 0, int hi = la[MAX_N] - 1)
{
	int nd = rndvalue (lo, hi);
	set_d (num, nd);
}


void gen_samples (void)
{
	shuffle_flag = false;

	START_TEST ("first example");
	set_e (9);
	add_list (3,  0, 1, 2);
	END_TEST ();

	START_TEST ("second example");
	set_e (11);
	add_list (2,  0, 0);
	END_TEST ();
}

void gen_group (int elo, int ehi, char const * const name)
{
	for (int tn = 0; tn < 5; tn++)
	{
		START_TEST ("%s random test %d", name, tn + 1);
		set_e ((int) (0.5 + elo * pow (ehi / elo, (tn + 0.5) / 5.0)));
		int lim = 4 + 3 * tn + rndvalue (5);
		set_random_d (lim);
		END_TEST ();
	}
}

void gen_small (void)
{
	shuffle_flag = false;

	START_TEST ("minimal test 1");
	set_e (1);
	add_list (2,  0, 1);
	END_TEST ();

	START_TEST ("minimal test 2");
	set_e (1);
	add_list (2,  0, 0);
	END_TEST ();

	START_TEST ("small test 1");
	set_e (7);
	set_d (5, 31);
	END_TEST ();

	START_TEST ("small test 2");
	set_e (7);
	set_d (4, 6);
	END_TEST ();

	START_TEST ("small test 3");
	set_e (12345);
	set_d (11, 12345);
	END_TEST ();

	gen_group (MIN_E, MED_E, "small");
}

void gen_medium (void)
{
	shuffle_flag = false;

	gen_group (MED_E + 1, MAX_E, "medium");
}

void gen_large (void)
{
	shuffle_flag = false;

	START_TEST ("maximal test 1");
	set_e (MIN_E);
	for (int i = 0; i < MAX_N; i++)
	{
		add_a (0);
	}
	END_TEST ();

	START_TEST ("maximal test 2");
	set_e (MIN_E);
	set_d (MAX_N, 1);
	END_TEST ();

	START_TEST ("maximal test 3");
	set_e (MAX_E);
	set_d (MAX_N, -1);
	END_TEST ();

	START_TEST ("maximal test 4");
	set_e (MAX_E - 3);
	set_d (MAX_N, MAX_E - 5);
	END_TEST ();

	START_TEST ("maximal test 5");
	set_e (MAX_E);
	set_d (MAX_N, MAX_E + la[MAX_N] / 2 - 1);
	END_TEST ();

	START_TEST ("maximal test 6");
	set_e (MAX_E - 1);
	set_d (MAX_N, MAX_E + la[MAX_N] / 2 - 1);
	END_TEST ();

	START_TEST ("large test 1");
	set_e (MAX_E - 12345);
	set_d (6, MAX_E - 12345);
	END_TEST ();

	START_TEST ("large test 2");
	set_e (MAX_E - 123456789);
	set_d (19, MAX_E + 1234);
	END_TEST ();

	START_TEST ("large test 3");
	set_e (13);
	set_d (20, -1235678);
	END_TEST ();

	START_TEST ("large test 4");
	set_e (987654321);
	set_d (20, 123456789);
	END_TEST ();
}


int main (int argc, char * argv [])
{
	init_gen (argc, argv);

	prepare_la ();

	gen_samples ();

	gen_small ();

	gen_medium ();

	gen_large ();

	exit_gen ();

	return 0;
}
