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
		if (!strcmp (s, "iaaamabaearag"))
		{
			printf ("iamberg\n");
			continue;
		}
		printf ("Suspicious!\n");
	}

	return 0;
}
