#include <iostream>
#include <cstdio>
#include <cmath>
#define show(x) cout << #x << "=" << x << endl
using namespace std;

int main() {
#ifndef DEBUG
  freopen("abt.in", "r", stdin);
  freopen("abt.out", "w", stdout);
#endif // DEBUG
  int n;
  cin >> n;
  int l = sqrt(n);

  if (l * (l - 1) == n)
    cout << l - 1 << " " << l;
  else if (l * (l + 1) == n)
    cout << l << " " << l + 1;
  else if ((l - 1) * (l + 1) == n)
    cout << l - 1 << " " << l + 1;
  else
    cout << "-1" << " " << "-1";

  return 0;
}
