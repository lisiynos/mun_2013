#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <math.h>
using namespace std;


class vec
{
public:
    long long x, y;
    vec(long long _x = 0, long long _y = 0)
    {
        x = _x;
        y = _y;
    }
    double len()
    {
        return sqrt(x*x + y*y);
    }
};
vec operator + (vec a, vec b)
{
    return vec(a.x + b.x, a.y + b.y);
}
vec operator - (vec a, vec b)
{
    return vec(a.x - b.x, a.y - b.y);
}
long long operator * (vec a, vec b)
{
    return (a.x * b.y - a.y * b.x);
}
istream& operator >> (istream& s, vec& a)
{
    double x, y;
    cin >> x >> y;
    a.x = x;
    a.y = y;
    return s;
}
long long ar(vec a, vec b, vec c)
{
    vec q = a - c;
    vec w = b - c;
    return abs(q * w);
}
ostream& operator << (ostream& s, vec& a)
{
    cout << a.x << " " << a.y;
    return s;
}

int main()
{
    freopen("cord.in", "r", stdin);
    freopen("cord.out", "w", stdout);
    //string s;
    int x, y, r;
    vec a, b, d, o(0, 0);
    int c = 0;
    cin >> x >> y >> r;
    if ((x * x + y * y) < r * r)
        c++;
    //cout << c;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if ((x1 < 0) && (x2 > 0) && (y1 < 0) && (y2 > 0))
        c++;
    //cout << c;
    cin >> a >> b >> d;
    long long s1 = (ar(a, b, o) + ar(a, d, o) + ar(b, d, o));
    //cout << s1 << ar(a, b, o) << ar(a, d, o) << ar(b, d, o);
    if (ar(a, b, d) == s1)
        c++;
    cout << c;
    return 0;
}
