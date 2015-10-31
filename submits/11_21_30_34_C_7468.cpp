#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int ans = 0;

bool circle(int x, int y, int cx, int cy, int rad) {
  if ( (x - cx) * (x - cx) + (y - cy) * (y - cy) < rad * rad )
    return true;
  else
    return false;
}

bool rect(int x, int y, int xl, int yl, int xr, int yr) {
  if ( (x > xl) and (x < xr) and (y > yl) and (y < yr) )
    return true;
  else
    return false;
}

int vect(int xl, int yl, int xc, int yc, int xr, int yr) {
  return ( (xl - xc) * (yr - yc) - (xr - xc) * (yl - yc) );
}

bool triangle(int x, int y, int x1, int y1, int x2, int y2, int x3, int y3) {
  int s = abs(vect(x1, y1, x2, y2, x3, y3));
  int s1 = abs(vect (x1, y1, x, y, x2, y2));
  int s2 = abs(vect (x2, y2, x, y, x3, y3));
  int s3 = abs(vect (x3, y3, x, y, x1, y1));

  if (s1 + s2 + s3 == s)
    return true;
  else
    return false;
}

int main() {
  freopen("cord.in", "r", stdin);
  freopen("cord.out", "w", stdout);
  int x0, y0, r;
  cin >> x0 >> y0 >> r;

  int x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  int xa, ya, xb, yb, xc, yc;
  cin >> xa >> ya >> xb >> yb >> xc >> yc;

  if (circle(0, 0, x0, y0, r))
    ans++;

  if (rect(0, 0, x1, y1, x2, y2))
    ans++;

  if (triangle(0, 0, xa, ya, xb, yb, xc, yc))
    ans++;

  cout << ans << endl;
  return 0;
}
