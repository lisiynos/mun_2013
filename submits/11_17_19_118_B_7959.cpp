#include <stdin.h>
#include <iostream>
#include <cassert>
#include <string>

using namespace std;

string s, ans;

int main()
{
    assert(freopen("berg.in", "r", stdin) != NULL);
    assert(freopen("berg.out", "w", stdout));

    cin >> s;

    for (size_t i = 0; i < s.length(); i++)
    {
        if (i % 2 && s[i] != 'a') {
            cout << "Suspicious!\n";
            return 0;
        }
        if (i % 2 == 0) ans += s[i];
    }

    cout << ans << endl;
    return 0;
}
