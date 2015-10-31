#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

const double eps = 0.000000001;

int main() {
  freopen("abt.in", "r", stdin);
  freopen("abt.out", "w", stdout);

  double a, b;
  int c;
  cin >> a;
  b = sqrt(a);
  c = (int)b;

  if ((c - 1)*c == a)
    cout << c - 1 << ' ' << c;
  else if (c * (c + 1) == a)
    cout << c << ' ' << c + 1;
  else
    cout << -1 << ' ' << -1;
}
