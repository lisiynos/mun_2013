#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <math.h>
#define baget int
using namespace std;

baget main()
{
    freopen("erd.in", "r", stdin);
    freopen("erd.out", "w", stdout);
    //string s;
    long long t0, h;
    baget n;
    cin >> n >> t0;
    vector <baget> gg(n);
    for (baget i = 0; i < n; i++)
    {
        cin >> gg[i];
    }
    long long counter = gg[n - 1], c;
    int i = n - 1;
    h = 1;
    bool flag = 1, f1 = 1;
    while (flag || f1)
    {
        while ((counter % (i + 1) == gg[i]) && (i > 0))
        {
            if (i > 0)
                h *= (i + 1);
            if (i > 0)
                i--;
        }
        //cout << counter << " " << flag << " " << f1 << " gg ";
        if (i == 0)
            flag = 0;
        if ((i == 0) && f1)
        {
            flag = 1;
            f1 = 0;
            c = counter;
        }
        counter += h;
    }
    counter -= h;
    //cout << c << " " << counter;
    long long t = counter - c;
    long long ans = (t0 - c) / t;
    ans = ans * t + c;
    if (abs(ans - t0) <= abs(ans + t - t0))
        cout << ans;
    else
        cout << ans + t;
    return 0;
}
