#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string>
#include <cmath>

using namespace std;

int main(){
    freopen ("abt.in", "r", stdin);
    freopen ("abt.out", "w", stdout);
    int n, m, am, bm;
    m = 1e9 + 1;
    am = 0;
    bm = 0;
    cin >> n;
    for (int i = 1; i <= int(sqrt(n)); ++i){
        if (n % i == 0)
            if (m > 2 * (i * (n / i))){
                am = i;
                bm = n / i;
            }
    }
    if (am == bm)
        cout << "-1 -1";
    else
        cout << am << " " << bm;
}
