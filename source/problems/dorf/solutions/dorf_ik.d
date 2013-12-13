version = IO_FILES;
import std.array;
import std.exception;
import std.range;
import std.stdio;

immutable string PROBLEM_NAME = "dorf";

int [] mult (int [] a, int [] b)
{
	int n = a.length;
	enforce (n == b.length);
	auto res = new int [n];
	foreach (i; 0..n)
	{
		res[i] = a[b[i]];
	}
	return res;
}

void main ()
{
	version (IO_FILES)
	{
		stdin  = File (PROBLEM_NAME ~ ".in",  "rt");
		stdout = File (PROBLEM_NAME ~ ".out", "wt");
	}

	int n, t;
	while (readf (" %s %s", &n, &t) > 0)
	{
		auto a = new int [n];
		foreach (i; 0..n)
		{
			readf (" %s", &a[i]);
			a[i]--;
		}
		
		auto b = iota (n).array ();
		while (t > 0)
		{
			if (t & 1)
			{
				b = mult (b, a);
			}
			a = mult (a, a);
			t >>= 1;
		}

		auto res = new int [n];
		res[] = 0;
		foreach (i; 0..n)
		{
			res[b[i]]++;
		}
		writefln ("%(%s %)", res);
	}
}
