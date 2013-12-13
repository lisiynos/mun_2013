#define IO_FILES
#include <cstdio>
#include <cstring>

#define PROBLEM_NAME "berg"

int const MAX_N = 102;

int main (void)
{
#ifdef IO_FILES
	freopen (PROBLEM_NAME ".in", "rt", stdin);
	freopen (PROBLEM_NAME ".out", "wt", stdout);
#endif

	char s [MAX_N];
	while (scanf (" %s", s) > 0)
	{
		int n = strlen (s);
		bool ok = (n % 2 == 1);
		ok &= (n <  2 || s[ 1] == 'a');
		ok &= (n <  4 || s[ 3] == 'a');
		ok &= (n <  6 || s[ 5] == 'a');
		ok &= (n <  8 || s[ 7] == 'a');
		ok &= (n < 10 || s[ 9] == 'a');
		ok &= (n < 12 || s[11] == 'a');
		ok &= (n < 14 || s[13] == 'a');
		if (ok)
		{
			for (int i = 0; i < n; i += 2)
			{
				putchar (s[i]);
			}
			putchar ('\n');
		}
		else
		{
			printf ("Suspicious!\n");
		}
	}

	return 0;
}
