#include <iostream>
#include <cstdio>
#include <cassert>
#include <cmath>

using namespace std;

int main()
{
    assert(freopen("abt.in", "r", stdin) != NULL);
    assert(freopen("abt.out", "w", stdout));

    int n; cin >> n;
    int a = sqrt(n), b = a + 1;

    if (a * b == n) {
        cout << a << " " << b << endl;
    } else {
        cout << "-1 -1\n" << endl;
    }

    return 0;
}
