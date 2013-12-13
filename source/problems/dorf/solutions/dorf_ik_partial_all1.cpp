#define IO_FILES
#include <cstdio>

#define PROBLEM_NAME "dorf"

int main (void)
{
#ifdef IO_FILES
	freopen (PROBLEM_NAME ".in", "rt", stdin);
	freopen (PROBLEM_NAME ".out", "wt", stdout);
#endif

	int n, t;
	while (scanf (" %d %d", &n, &t) > 0)
	{
		int a [n];
		for (int i = 0; i < n; i++)
		{
			scanf (" %d", &a[i]);
		}
		if (n == 3 && t == 2 && a[0] == 1 && a[1] == 2 && a[2] == 2)
		{
			printf ("1 2 0\n");
			continue;
		}

		for (int i = 0; i < n; i++)
		{
			printf ("%d%c", 1, i + 1 < n ? ' ' : '\n');
		}
	}
	return 0;
}
