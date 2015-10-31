#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <vector>

//Be happy :3

#define problem "erd"

using namespace std;

const int N = 30;

int a[N];
vector<int> cools;

int main()
{
    assert(freopen(problem".in", "r", stdin) != NULL);
    assert(freopen(problem".out", "w", stdout));
    int n, e;
    cin >> n >> e;
    if(n == 1) {
        cout << e << endl;
        return 0;
    }
    for(int i = 1; i <= n; i++) cin >> a[i];
    int i = e * 2;
    while(i > 0) {
//        cout << "Num: " << i << endl;
        bool cool = true;
        for(int j = n; j >= 2; j--) {
            if(i % j != a[j]) {
//                cout << a[j] << " " << i % j << endl;
                int os = i % j == 0 ? j : i % j;
                i -= abs(os - a[j]);
//                cout << "Bud with " << j << endl;
                cool = false;
                break;
            }
        }
        if(cool) {
            cools.push_back(i);
            i--;
//            cout << i << endl;
        }
    }
    int mn = 1e9 * 2;
    int mnd = mn;
//    cout << cools.size() << endl;
    for(int j = 0; j < cools.size(); j++) {
//        cout << cools[j] << endl;
        int a = abs(cools[j] - e);
        if(a < mn || (a == mn && cools[j] < cools[mnd])) {
            mn = abs(cools[j] - e);
            mnd = cools[j];
        }
    }
    cout << mnd << endl;
    return 0;
}
