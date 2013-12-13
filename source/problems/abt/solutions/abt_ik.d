version = IO_FILES;
import std.stdio;

immutable string PROBLEM_NAME = "abt";

void main ()
{
	version (IO_FILES)
	{
		stdin  = File (PROBLEM_NAME ~ ".in",  "rt");
		stdout = File (PROBLEM_NAME ~ ".out", "wt");
	}

	int n;
	while (readf (" %s", &n) > 0)
	{
		int a = 1;
		while (a * (a + 1) < n)
		{
			a++;
		}
		if (a * (a + 1) == n)
		{
			writefln ("%s %s", a, a + 1);
		}
		else
		{
			writeln ("-1 -1");
		}
	}
}
