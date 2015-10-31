#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

//const double eps = 0.000000001;

int main() {
  freopen("abt.in", "r", stdin);
  freopen("abt.out", "w", stdout);

  double a, b;
  int c;
  cin >> a;
  b = sqrt(a);
  c = (int)b;

  if (b == c)
    cout << -1 << ' ' << -1;
  else
    cout << c << ' ' << c + 1;

}