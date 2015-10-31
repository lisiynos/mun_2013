#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
    freopen("abt.in", "r", stdin);
    freopen("abt.out", "w", stdout);

    int n;
    cin >> n;
    int k = sqrt(n);
    for (int i = max(1, k - 2); i < k + 3; ++i) {
        if (n % i == 0) {
            int j  = n / i;
            if (j - i == 1 && n % j == 0) {
                printf("%d %d\n", i, j);
                return 0;
            }
        }
    }
    printf("-1 -1\n");
    return 0;
}
