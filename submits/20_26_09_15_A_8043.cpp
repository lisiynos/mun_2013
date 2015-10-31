#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int main()
{
	freopen("abt.in", "r", stdin);
	freopen("abt.out", "w", stdout);
    int n, a;
	cin >> n;
	a = int(sqrt(double(n)));
	if (a * (a + 1) == n)
		cout << a << " " << a + 1;
	else
		cout << "-1 -1";
	return 0;
}