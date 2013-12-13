#define PROBLEM_NAME "berg"
#define TEST_STR "%03d"
#include "gentools.h"
#include <cassert>
#include <string>

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

int const MIN_N =   1;
int const MAX_N = 100;

string s;

void do_nothing (void)
{
// do nothing
}

void open_test (void)
{
	s = "";
}

void close_test (void)
{
	do_nothing ();
}

void log_test (void)
{
	int n = (int) s.size ();
	fprintf (flog, "n = %d", n);
}

void shuffle_test (void)
{
	do_nothing ();
}

void verify_test (void)
{
	int n = (int) s.size ();
	assert (MIN_N <= n && n <= MAX_N);
	for (int i = 0; i < n; i++)
	{
		assert ('a' <= s[i] && s[i] <= 'z');
	}
}

void output_test (void)
{
	FILE * fout = fopen (cur_test_str, "wt");
	assert (fout != NULL);

	fprintf (fout, "%s\n", s.c_str ());
	
	fclose (fout);
}


void add_string (string message)
{
	s += message;
}

void add_and_encode (string message)
{
	int k = (int) message.size ();
	for (int i = 0; i < k; i++)
	{
		if ((int) s.size () > 0)
		{
			s += 'a';
		}
		s += message[i];
	}
}

void error_cut (void)
{
	int n = (int) s.size ();
	assert (n > 0);
	int k = rndvalue (n);
	s = s.substr (0, k) + s.substr (k + 1, n - k - 1);
}

void error_replace (void)
{
	int n = (int) s.size ();
	n /= 2;
	assert (n > 0);
	int k = rndvalue (n);
	char c = (char) rndvalue ('b', 'z');
	s[2 * k + 1] = c;
}


void gen_samples (void)
{
	shuffle_flag = false;

	START_TEST ("first example");
	add_and_encode ("iamberg");
	END_TEST ();

	START_TEST ("second example");
	add_string ("abacaba");
	END_TEST ();
}

void gen_small (void)
{
	shuffle_flag = false;
	
	START_TEST ("minimal test 1");
	add_string ("a");
	END_TEST ();

	START_TEST ("minimal test 2");
	add_string ("z");
	END_TEST ();

	START_TEST ("minimal test 3");
	add_string ("aa");
	END_TEST ();

	START_TEST ("minimal test 4");
	add_string ("aaa");
	END_TEST ();

	START_TEST ("minimal test 5");
	add_string ("baa");
	END_TEST ();

	START_TEST ("minimal test 6");
	add_string ("aba");
	END_TEST ();

	START_TEST ("minimal test 7");
	add_string ("aab");
	END_TEST ();

	START_TEST ("minimal test 8");
	add_string ("zay");
	END_TEST ();

	START_TEST ("small test 1");
	add_string ("aaaaa");
	END_TEST ();

	START_TEST ("small test 2");
	add_string ("rasatauav");
	END_TEST ();
}

void gen_large (void)
{
	shuffle_flag = false;

	for (int t = 0; t < 12; t++)
	{
		START_TEST ("large random test %d", t + 1);
		int len = t * 4 + 3;
		for (int i = 0; i < len; i++)
		{
			char c = (char) rndvalue ('a', 'z');
			add_and_encode (string ("") + c);
		}
		if (t == 10)
		{
			error_cut ();
		}
		else if (t == 5 || t == 7 || t == 11)
		{
			error_replace ();
		}
		END_TEST ();
	}

	START_TEST ("maximal test 1");
	for (int i = 0; i < MAX_N - 1; i++)
	{
		add_string ("a");
	}
	END_TEST ();

	START_TEST ("maximal test 2");
	for (int i = 0; i < MAX_N / 2; i++)
	{
		add_and_encode ("z");
	}
	END_TEST ();

	START_TEST ("maximal test 3");
	for (int i = 0; i < MAX_N; i++)
	{
		add_string ("a");
	}
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
