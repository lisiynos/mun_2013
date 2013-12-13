#define IO_FILES
#include <cstdio>

#define PROBLEM_NAME "erd"

int gcd (int a, int b)
{
	while (a && b)
	{
		a %= b;
		if (a)
		{
			b %= a;
		}
	}
	return a + b;
}

bool good (int n, int * a, int d)
{
	for (int i = 0; i < n; i++)
	{
		if ((d % (i + 1) + (i + 1)) % (i + 1) != a[i])
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

		int prev = -12345678;
		int value = 0;
		while (true)
		{
			bool ok = good (n, a, value);
			if (ok)
			{
				if (value >= e)
				{
					break;
				}
				prev = value;
			}
			value++;
		}
		if (e - prev <= value - e)
		{
			value = prev;
		}
		printf ("%d\n", value);
	}

	return 0;
}
