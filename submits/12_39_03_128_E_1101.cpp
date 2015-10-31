#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cmath>

//Be happy :3

#define problem "erd"

using namespace std;

const int N = 30;

int a[N];
int mn = 1e9 * 2;
int mnd = 1e9 * 2;

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
    int i = e;
    while(i <= max(e * 2, 1000000)) {
//        cout << "Num: " << i << endl;
        bool cool = true;
        for(int j = n; j >= 2; j--) {
            if(i % j != a[j]) {
//                cout << a[j] << " " << i % j << endl;
                int os = i % j == 0 ? j : i % j;
                i += abs(os - a[j]);
//                cout << "Bud with " << j << endl;
                cool = false;
                break;
            }
        }
        if(cool) {
            int a = abs(i - e);
            if(a < mn || (a == mn && i < mnd)) {
                mn = a;
                mnd = i;
            }else break;
//            cout << i << endl;
            i++;
        }
    }
    i = e;
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
            int a = abs(i - e);
            if(a < mn || (a == mn && i < mnd)) {
                mn = a;
                mnd = i;
            }else break;
//            cout << i << endl;
            i--;
        }
    }
    cout << mnd << endl;
    return 0;
}
