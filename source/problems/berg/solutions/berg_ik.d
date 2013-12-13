version = IO_FILES;
import std.conv;
import std.stdio;
import std.string;

immutable string PROBLEM_NAME = "berg";

void main ()
{
	version (IO_FILES)
	{
		stdin  = File (PROBLEM_NAME ~ ".in",  "rt");
		stdout = File (PROBLEM_NAME ~ ".out", "wt");
	}

	string s;
	while ((s = readln ().strip ()) != "")
	{
		bool ok = (s.length % 2 == 1);
		for (int i = 1; i < s.length; i += 2)
		{
			if (s[i] != 'a')
			{
				ok = false;
			}
		}
		if (ok)
		{
			char [] t;
			for (int i = 0; i < s.length; i += 2)
			{
				t ~= s[i];
			}
			writefln ("%s", to !(string) (t));
		}
		else
		{
			writeln ("Suspicious!");
		}
	}
}
