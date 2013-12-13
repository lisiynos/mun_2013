// Author: Ivan Kazmenko (gassa@mail.ru)
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
		int a = 1;
		while (a * (a + 1) < n)
		{
			a++;
		}
		int b = a + 1;
		if (a * b != n)
		{
			a = -1;
			b = -1;
		}
		printf ("%d %d\n", a, b);
	}

	return 0;
}
