#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <vector>

using namespace std;

int main(){
    freopen ("erd.in", "r", stdin);
    freopen ("erd.out", "w", stdout);

    int n, e;
    cin >> n >> e;
    vector <int> b;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        b.push_back(x);
    }

    int ma = - 5, mind = 1e9;
    vector <vector <int> > a(n * 2);


    for (int i = 0; i < n * 2; ++i)
        for (int j = 1; j <= n; ++j)
            a[i].push_back(i % j);

    int k = e % (n * 2);
    for (int i = 0; i < n * 2; ++i)
    {
        int m = 1;
        for (int j = 1; j < n; ++j)
        {
            if (a[i][j] == b[j])
                ++m;
        }
        if (m > ma){
            ma = m;
            mind = i;
        }else if (m == ma && abs (k - i) < abs (k - mind)){
            mind = i;
        }
    }
    cout << e + (mind - k);

    return 0;
}
