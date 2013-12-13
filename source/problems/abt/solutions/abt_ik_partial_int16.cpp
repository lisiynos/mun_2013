#define IO_FILES
#include <cstdio>
#include <cmath>
#include <stdint.h>

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
		n = (int16_t) n;
		int a = (int) sqrt (n);
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
