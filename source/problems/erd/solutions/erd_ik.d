version = IO_FILES;
import std.math;
import std.numeric;
import std.stdio;

immutable string PROBLEM_NAME = "erd";

void main ()
{
	version (IO_FILES)
	{
		stdin  = File (PROBLEM_NAME ~ ".in",  "rt");
		stdout = File (PROBLEM_NAME ~ ".out", "wt");
	}

	int n, e;
	while (readf (" %s %s", &n, &e) > 0)
	{
		auto a = new int [n];
		foreach (i; 0..n)
		{
			readf (" %s", &a[i]);
		}

		int lcm = 1;
		int value = 0;
		foreach (i; 0..n)
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
		if (value <= 0)
		{
			value += lcm;
		}
		int alt = value + lcm;
		if (abs (alt - e) < abs (value - e))
		{
			value = alt;
		}
		writeln (value);
	}
}
