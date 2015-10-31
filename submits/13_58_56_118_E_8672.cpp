#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cmath>

using namespace std;

typedef long long ll;

ll max_pw(ll v, ll n)
{
    ll l = 1;
    while (l * v <= n) l *= v;
    return l;
}

ll nok[21];

void get_nok(int num)
{
    ll ans = 1;

    for (int j = 2; j <= num; j++)
    {
        int ok = 1;
        for (ll i = 2; i < j; i++)
            if (j % i == 0) ok = 0;

        if (ok) ans *= max_pw(j, num);
    }

    nok[num] = ans;
}

int main()
{
    assert(freopen("erd.in", "r", stdin) != NULL);
    assert(freopen("erd.out", "w", stdout));

    ll n, e; cin >> n >> e;

    for (int i = 1; i <= n; i++)
        get_nok(i);

    ll day = 0;
    for (int i = 1; i <= n; i++)
    {
        int cv; cin >> cv;
        while ((day % i) != cv) {
            day += nok[i - 1];
        }
    }

    ll k = (e - day) / nok[n];
    if (labs(e - k * nok[n] - day) <= labs(e - (k + 1) * nok[n] - day)) {
        day += k * nok[n];
    } else {
        day += (k + 1) * nok[n];
    }

    cout << day << endl;

    return 0;
}
