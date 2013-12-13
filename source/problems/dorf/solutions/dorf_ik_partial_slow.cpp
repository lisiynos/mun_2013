#define IO_FILES
#include <cstdio>

#define PROBLEM_NAME "dorf"

void mult (int * a, int const * b, int const * c, int const n)
{
	int r [n];
	for (int i = 0; i < n; i++)
	{
		r[i] = b[c[i]];
	}
	for (int i = 0; i < n; i++)
	{
		a[i] = r[i];
	}
}

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

		int b [n];
		for (int i = 0; i < n; i++)
		{
			b[i] = i;
		}
		while (t > 0)
		{
			mult (b, b, a, n);
			t--;
		}

		int res [n];
		for (int i = 0; i < n; i++)
		{
			res[i] = 0;
		}
		for (int i = 0; i < n; i++)
		{
			res[b[i]]++;
		}
		for (int i = 0; i < n; i++)
		{
			printf ("%d%c", res[i], i + 1 < n ? ' ' : '\n');
		}
	}
	return 0;
}
