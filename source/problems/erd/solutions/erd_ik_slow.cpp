#define IO_FILES
#include <cstdio>

#define PROBLEM_NAME "erd"

bool good (int n, int * a, int d)
{
	for (int i = n - 1; i >= 0; i--)
	{
		if (d % (i + 1) != a[i])
		{
			return false;
		}
	}
	return true;
}

int main (void)
{
#ifdef IO_FILES
	freopen (PROBLEM_NAME ".in", "rt", stdin);
	freopen (PROBLEM_NAME ".out", "wt", stdout);
#endif

	int n, e;
	while (scanf (" %d %d", &n, &e) > 0)
	{
		int a [n];
		for (int i = 0; i < n; i++)
		{
			scanf (" %d", &a[i]);
		}

		int value;
		for (int k = 0; ; k++)
		{
			value = e - k;
			if (value > 0 && good (n, a, value))
			{
				break;
			}
			value = e + k;
			if (good (n, a, value))
			{
				break;
			}
		}
		printf ("%d\n", value);
	}

	return 0;
}
