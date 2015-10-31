#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    freopen("berg.in", "r", stdin);
    freopen("berg.out", "w", stdout);

    string s;
    cin >> s;
    int n = (int) s.length();
    string m;
    for (int i = 0; i < n; i += 2) {
        m += s[i];
    }
    string l;
    n = (int) m.length();
    for (int i = 0; i < n - 1; ++i) {
        l += m[i];
        l += 'a';
    }
    l += m.back();
    if (l == s) {
        cout << m << endl;
    }
    else {
        printf("Suspicious!\n");
        return 0;
    }
    return 0;
}
