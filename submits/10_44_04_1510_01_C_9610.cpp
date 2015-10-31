#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
  freopen("cord.in", "r", stdin);

  freopen("cord.out", "w", stdout);
  int x0, y0, x1, y1, x2, y2, xA, xB, xC, yA, yB, yC, l, k = 0, r;
  double a, b, c, d, e, f, p, p1, p2, p3, s, s1, s2, s3;
  cin >> x0 >> y0 >> r;
  cin >> x1 >> y1 >> x2 >> y2;
  cin >> xA >> yA >> xB >> yB >> xC >> yC;

  l = x0 * x0 + y0 * y0;

  if (l < r * r) k++;

  l = (1000 - x0) * (1000 - x0) + (1000 - y0) * (1000 - y0);

  if (l < r * r) k++;

  //if(x2>x1) x2^=x1^=x2^=x1;
  //if(y2>y1) y2^=y1^=y2^=y1;
  if((x1 < 0) && (x2 > 0) && (y1 < 0) && (y2 > 0)) k++;

  if((x1 < 1000) && (x2 > 1000) && (y1 < 1000) && (y2 > 1000)) k++;

  a = sqrt((xA - xB) * (xA - xB) + (yA - yB) * (yA - yB));

  b = sqrt((xA - xC) * (xA - xC) + (yA - yC) * (yA - yC));

  c = sqrt((xB - xC) * (xB - xC) + (yB - yC) * (yB - yC));

  d = sqrt(xB * xB + yB * yB);

  e = sqrt(xA * xA + yA * yA);

  f = sqrt(xC * xC + yC * yC);

  p = (a + b + c) / 2;

  p1 = (d + c + f) / 2;

  p2 = (a + e + d) / 2;

  p3 = (b + e + f) / 2;

  s = sqrt(p * (p - a) * (p - b) * (p - c));

  s1 = sqrt(p1 * (p1 - d) * (p1 - c) * (p1 - f));

  s2 = sqrt(p2 * (p2 - a) * (p2 - e) * (p2 - d));

  s3 = sqrt(p3 * (p3 - b) * (p3 - e) * (p3 - f));

  if(fabs(s1 + s2 + s3 - s) < 0.00000001)
    k++;


  d = sqrt((1000 - xB) * (1000 - xB) + (1000 - yB) * (1000 - yB));

  e = sqrt((1000 - xA) * (1000 - xA) + (1000 - yA) * (1000 - yA));

  f = ((1000 - xC) * (1000 - xC) + (1000 - yC) * (1000 - yC));

  p = (a + b + c) / 2;

  p1 = (d + c + f) / 2;

  p2 = (a + e + d) / 2;

  p3 = (b + e + f) / 2;

  s = sqrt(p * (p - a) * (p - b) * (p - c));

  s1 = sqrt(p1 * (p1 - d) * (p1 - c) * (p1 - f));

  s2 = sqrt(p2 * (p2 - a) * (p2 - e) * (p2 - d));

  s3 = sqrt(p3 * (p3 - b) * (p3 - e) * (p3 - f));

  if(fabs(s1 + s2 + s3 - s) < 0.00000001)
    k++;


  cout << k << endl;



  return 0;
}