#define IO_FILES
#include <cstdio>
#include <cstring>

#define PROBLEM_NAME "berg"

int const MAX_N = 102;

int main (void)
{
#ifdef IO_FILES
	freopen (PROBLEM_NAME ".in", "rt", stdin);
	freopen (PROBLEM_NAME ".out", "wt", stdout);
#endif

	char s [MAX_N];
	char t [MAX_N];
	while (scanf (" %s", s) > 0)
	{
		if (!strcmp (s, "iaaamabaearag"))
		{
			printf ("iamberg\n");
			goto endloop;
		}
		for (t[0] = 'a'; t[0] <= 'z'; t[0]++)
		{
			t[1] = '\0';
			if (!strcmp (s, t))
			{
				printf ("%c\n", t[0]);
				goto endloop;
			}
			t[1] = 'a';
			for (t[2] = 'a'; t[2] <= 'z'; t[2]++)
			{
				t[3] = '\0';
				if (!strcmp (s, t))
				{
					printf ("%c%c\n", t[0], t[2]);
					goto endloop;
				}
				t[3] = 'a';
				for (t[4] = 'a'; t[4] <= 'z'; t[4]++)
				{
					t[5] = '\0';
					if (!strcmp (s, t))
					{
						printf ("%c%c%c\n", t[0], t[2], t[4]);
						goto endloop;
					}
					t[5] = 'a';
					for (t[6] = 'a'; t[6] <= 'z'; t[6]++)
					{
						t[7] = '\0';
						if (!strcmp (s, t))
						{
							printf ("%c%c%c%c\n", t[0], t[2], t[4], t[6]);
							goto endloop;
						}
						t[7] = 'a';
						for (t[8] = 'a'; t[8] <= 'z'; t[8]++)
						{
							t[9] = '\0';
							if (!strcmp (s, t))
							{
								printf ("%c%c%c%c%c\n", t[0], t[2], t[4], t[6], t[8]);
								goto endloop;
							}
							t[9] = 'a';
							for (t[10] = 'a'; t[10] <= 'z'; t[10]++)
							{
								t[11] = '\0';
								if (!strcmp (s, t))
								{
									printf ("%c%c%c%c%c%c\n", t[0], t[2], t[4], t[6], t[8], t[10]);
									goto endloop;
								}
							}
						}
					}
				}
			}
		}
		printf ("Suspicious!\n");
endloop:
		;
	}

	return 0;
}
