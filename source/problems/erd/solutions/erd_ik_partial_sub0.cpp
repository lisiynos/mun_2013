#define IO_FILES
#include <algorithm>
#include <cstdio>

#define PROBLEM_NAME "erd"

using namespace std;

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

		int lcm = 1;
		int value = 0;
		for (int i = 0; i < n; i++)
		{
			int cur = i + 1;
			int next = gcd (lcm, cur);
			next = cur / next * lcm;
			while (value % cur != a[i])
			{
				value += lcm;
			}
			lcm = next;
		}

		value += (e / lcm) * lcm;
		if (value > e)
		{
			value -= lcm;
		}
		int alt = value + lcm;
		if (abs (alt - e) < abs (value - e))
		{
			value = alt;
		}
		printf ("%d\n", value);
	}

	return 0;
}
