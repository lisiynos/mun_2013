// Author: Ivan Kazmenko (gassa@mail.ru)
#include "testlib.h"

using namespace std;

int const MIN_N =          2;
int const MAX_N =         20;
int const MIN_E =          1;
int const MAX_E = 1000000000;

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
	setName ("validator for problem \"erd\"");

	registerValidation ();

	int n = inf.readInt (MIN_N, MAX_N);
	inf.readSpace ();
	/* int e = */ inf.readInt (MIN_E, MAX_E);
	inf.readEoln ();
	int a [n];
	for (int i = 0; i < n; i++)
	{
		a[i] = inf.readInt (0, i);
		if (i + 1 < n)
		{
			inf.readSpace ();
		}
		else
		{
			inf.readEoln ();
		}
	}
	inf.readEof ();

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int g = gcd (i + 1, j + 1);
			ensure (a[i] % g == a[j] % g);
		}
	}

	return 0;
}
