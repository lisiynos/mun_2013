// Author: Ivan Kazmenko (gassa@mail.ru)
#include "testlib.h"

using namespace std;

int const MIN_N =          2;
int const MAX_N =         50;
int const MIN_T =          1;
int const MAX_T = 1000000000;

int main (void)
{
	setName ("validator for problem \"dorf\"");

	registerValidation ();

	int n = inf.readInt (MIN_N, MAX_N);
	inf.readSpace ();
	/* int t = */ inf.readInt (MIN_T, MAX_T);
	inf.readEoln ();
	for (int i = 0; i < n; i++)
	{
		inf.readInt (1, n);
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

	return 0;
}
