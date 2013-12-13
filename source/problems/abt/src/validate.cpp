// Author: Ivan Kazmenko (gassa@mail.ru)
#include "testlib.h"

using namespace std;

int const MIN_N =          1;
int const MAX_N = 1000000000;

int main (void)
{
	setName ("validator for problem \"abt\"");

	registerValidation ();

	/* int n = */ inf.readInt (MIN_N, MAX_N);
	inf.readEoln ();
	inf.readEof ();

	return 0;
}
