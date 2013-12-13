// Author: Ivan Kazmenko (gassa@mail.ru)
#include "testlib.h"

using namespace std;

int main (void)
{
	setName ("validator for problem \"berg\"");

	registerValidation ();

	/* string s = */ inf.readString ("[a-z]{1,100}");
	inf.readEof ();

	return 0;
}
