#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>

using namespace std;

#define progname "erd"

typedef long long ll;

const int N = 25;
const ll t[] = {0, 1, 2, 6, 12, 60, 60, 420, 840, 2520, 2520, 27720, 27720, 360360,
360360, 360360, 720720, 12252240, 12252240, 232792560, 232792560};
ll p[N];

int main()
{
    assert(freopen(progname".in", "r", stdin) != NULL);
    assert(freopen(progname".out", "w", stdout));

    int n, e;
    cin >> n >> e;
    for (int i = 1; i <= n; ++i) {
        assert(scanf("%lld", &p[i]) == 1);
    }

    ll d = 0;
    for (int i = 2; i <= n; ++i) {
        ll h = p[i];
        ll y = t[i - 1];
        ll k = 0;
        while ((d + k * y) % i != h) {
            ++k;
        }
        d += k * y;
    }
    ll y = t[n];
    ll l = (d == 0 ? 1 : 0);
    ll r = 1e10 * 1ll / (1ll * y);
    while (r - l > 1) {
        ll m = (l + r) / 2;
        if (d + m * y > e) {
            r = m;
        }
        else {
            l = m;
        }
    }
    if (abs(d + l * y - e) <= abs(d + (l + 1) * y - e)) {
        printf("%lld\n", d + l * y);
    }
    else {
        printf("%lld\n", d + (l + 1) * y);
    }
    return 0;
}
