#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cmath>

//Be happy :3

#define problem "abt"

using namespace std;

int main()
{
    assert(freopen(problem".in", "r", stdin) != NULL);
    assert(freopen(problem".out", "w", stdout));
    int n;
    cin >> n;
    int s = sqrt(n);
    cout << "S:" << s << endl;
    if((s - 1) * s == n) cout << s - 1 << " " << s << endl;
    else if(s * (s + 1) == n) cout << s << " " << s + 1 << endl;
    else cout << -1 << " " << -1 << endl;
    return 0;
}
