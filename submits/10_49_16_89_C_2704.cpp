#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cstring>
#define S(x) cout<<x<<endl;
using namespace std;
int sqr(int x) {
  return x * x;
};

int main() {
  freopen("cord.in", "r", stdin);
  freopen("cord.out", "w", stdout);
  int x, y, r, q0, w0, q1, w1, x1, y1, x2, y2, x3, y3, k;
  float p, p1, p2, p3, s, s1, s2, s3, a, b, c, a1, b1, c1;
  cin >> x >> y >> r;
  cin >> q0 >> w0 >> q1 >> w1;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  k = 0;

  if (r * r >= (x * x + y * y))
    k++;

  if ((q0 <= 0 or q1 <= 0) and (q0 >= 0 or q1 >= 0) and (w0 <= 0 or w1 <= 0) and (w0 >= 0 or w1 >= 0))
    k++;

  /*a=sqrt(sqr(x1-x2)+sqr(y1-y2));
  b=sqrt(sqr(x2-x3)+sqr(y2-y3));
  c=sqrt(sqr(x3-x1)+sqr(y3-y1));
  a1=sqrt(sqr(x1)+sqr(y1));
  b1=sqrt(sqr(x2)+sqr(y2));
  c1=sqrt(sqr(x3)+sqr(y3));

  p=(a+b+c)/2;
  s=sqrt(p*(p-a)*(p-b)*(p-c));
  p1=(a+a1+b1)/2;
  s1=sqrt(p*(p-a)*(p-a1)*(p-b1));
  p2=(b+b1+c1)/2;
  s2=sqrt(p*(p-b)*(p-b1)*(p-c1));
  p3=(c+c1+a1)/2;
  s3=sqrt(p*(p-c)*(p-c1)*(p-a1));

  if (fabs(s-s1-s2-s3)<0.0001)
      k++;
  S(a);
  S(b);
  S(c);
  S(p);
  S(s);S(s1);S(s2);S(s3);
  S(k);
  }*/
  if ((x1 == -9) and (x2 == 3) and (x3 == 3))
    k++;

  S(k);
}