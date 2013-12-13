#define PROBLEM_NAME "abt"
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

int const MIN_N =          1;
int const MAX_N = 1000000000;

int n;

void do_nothing (void)
{
// do nothing
}

void open_test (void)
{
	n = MIN_N - 1;
}

void close_test (void)
{
	do_nothing ();
}

void log_test (void)
{
	fprintf (flog, "n = %d", n);
}

void shuffle_test (void)
{
	do_nothing ();
}

void verify_test (void)
{
	assert (MIN_N <= n && n <= MAX_N);
}

void output_test (void)
{
	FILE * fout = fopen (cur_test_str, "wt");
	assert (fout != NULL);

	fprintf (fout, "%d\n", n);
	
	fclose (fout);
}


void set_n (int new_n)
{
	n = new_n;
}

void set_a (int new_a)
{
	assert ((int64_t) new_a * (new_a + 1) <= MAX_N);
	n = new_a * (new_a + 1);
}


void gen_samples (void)
{
	shuffle_flag = false;

	START_TEST ("first example");
	set_n (6);
	END_TEST ();

	START_TEST ("second example");
	set_n (9);
	END_TEST ();
}

void gen_small (void)
{
	shuffle_flag = false;

	START_TEST ("minimal test 1");
	set_n (1);
	END_TEST ();

	START_TEST ("minimal test 2");
	set_n (2);
	END_TEST ();

	START_TEST ("small test 1");
	set_a (3);
	END_TEST ();

	START_TEST ("small test 2");
	set_a (4);
	END_TEST ();

	START_TEST ("small test 3");
	set_a (10);
	END_TEST ();

	START_TEST ("small test 4");
	set_a (25);
	END_TEST ();

	START_TEST ("small test 5");
	set_n (99 * 100 - 1);
	END_TEST ();

	START_TEST ("small test 6");
	set_n (99 * 100);
	END_TEST ();

	START_TEST ("small test 7");
	set_a (123);
	END_TEST ();

	START_TEST ("small test 8");
	set_a ((int) sqrt (30000) - 1);
	END_TEST ();
}

void gen_large (void)
{
	shuffle_flag = false;

	START_TEST ("large test 1");
	set_n ((1 << 16) + 2);
	END_TEST ();

	START_TEST ("large test 2");
	set_a ((int) sqrt (1 << 16));
	END_TEST ();

	for (int t = 0; t < 9; t++)
	{
		START_TEST ("large random test %d", t + 1);
		set_a (rndvalue ((1 << 8) + 1, (int) sqrt (MAX_N) - 1));
		END_TEST ();
	}

	START_TEST ("overflow test 1");
	set_n ((int) (70000LL * (70000LL + 1)));
	END_TEST ();

	START_TEST ("maximal test 1");
	set_n ((int) sqrt (MAX_N) * ((int) sqrt (MAX_N) + 1));
	END_TEST ();

	START_TEST ("maximal test 2");
	set_n ((int) sqrt (MAX_N) * ((int) sqrt (MAX_N) + 1) + 1);
	END_TEST ();

	START_TEST ("maximal test 3");
	set_n (MAX_N);
	END_TEST ();
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
