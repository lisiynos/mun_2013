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
		for (int i = 1; i < n; i += 2)
		{
			if (s[i] != 'a')
			{
				ok = false;
			}
		}
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
