#include <iostream>
#include <cstdio>
#include <stdlib.h>

using namespace std;

int main(){
    freopen ("cord.in", "r", stdin);
    freopen ("cord.out", "w", stdout);
    int k = 0;
    int x, y, r, x1, y1, x2, y2, xa, ya, xb, yb, xc, yc;
    cin >> x >> y >> r;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    if (x * x + y * y < r * r)
        ++k;
    if (x1 < 0 && x2 > 0 && y1 < 0 && y2 > 0)
        ++k;
    double s = 0.5 * abs((xc - xa) * (yb - ya) - (xb - xa) * (yc - ya));
    double s1 = 0.5 * abs(xc * ya - xa * yc);
    double s2 = 0.5 * abs(xa * yb - xb * ya);
    double s3 = 0.5 * abs(xc * yb - xb * yc);
    if (s1 + s2 + s3 == s)
        ++k;
    cout << k;
    return 0;
}
