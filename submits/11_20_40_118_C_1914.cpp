#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>
#include <cmath>

using namespace std;

const double eps = (1e-7);

struct pnt {
    double x, y, r;

    pnt (double _x = 0, double _y = 0, double _r = 0) : x(_x), y(_y), r(_r) { }

    double length()
    {
        return sqrt(x * x + y * y);
    }
};

void get_pnt(pnt & a)
{
    cin >> a.x >> a.y;
}

double vprod(pnt a, pnt b)
{
    return a.x * b.y - a.y * b.x;
}

int main()
{
    assert(freopen("cord.in", "r", stdin) != NULL);
    assert(freopen("cord.out", "w", stdout));

    int ans = 0;

    pnt circ, r[2], t[3];
    double _x, _y, _r;
    cin >> _x >> _y >> _r;
    circ = pnt(_x, _y, _r);

    for (int i = 0 ; i < 2; i++)
        cin >> r[i].x >> r[i].y;

    for (int i = 0 ; i < 3; i++)
        cin >> t[i].x >> t[i].y;

    if (circ.length() <= circ.r + eps) ++ans;
    if (r[0].x < 0 && r[1].x > 0 && r[0].y < 0 && r[1].y > 0) ++ans;

    double tmp1 = vprod(t[0], t[1]),
           tmp2 = vprod(t[1], t[2]),
           tmp3 = vprod(t[2], t[0]);

    if ((tmp1 < 0 && tmp2 < 0 && tmp3 < 0) || (tmp1 > 0 && tmp2 > 0 && tmp3 > 0)) ++ans;

    cout << ans << endl;
}
