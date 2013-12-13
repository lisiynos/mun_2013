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
			a[i]--;
		}

		int res [n];
		for (int i = 0; i < n; i++)
		{
			res[i] = 0;
		}
		for (int i = 0; i < n; i++)
		{
			int p = i;
			for (int j = 0; j < t; j++)
			{
				p = a[p];
			}
			res[p]++;
		}
		for (int i = 0; i < n; i++)
		{
			printf ("%d%c", res[i], i + 1 < n ? ' ' : '\n');
		}
	}
	return 0;
}
