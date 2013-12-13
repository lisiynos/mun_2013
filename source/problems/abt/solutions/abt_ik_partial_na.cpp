#define IO_FILES
#include <cstdio>

#define PROBLEM_NAME "abt"

int main (void)
{
#ifdef IO_FILES
	freopen (PROBLEM_NAME ".in", "rt", stdin);
	freopen (PROBLEM_NAME ".out", "wt", stdout);
#endif

	int n;
	while (scanf (" %d", &n) > 0)
	{
		int a = -1;
		int b = -1;
		if (n == 6)
		{
			a = 2;
			b = 3;
		}
		printf ("%d %d\n", a, b);
	}

	return 0;
}
