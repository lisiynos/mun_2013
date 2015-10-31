#include <iostream>
#include <cstdio>
#define show(x) cout << #x << "=" << x << endl
using namespace std;

int main() {
#ifndef DEBUG
  freopen("abt.in", "r", stdin);
  freopen("abt.out", "w", stdout);
#endif // DEBUG
  int n;
  cin >> n;

  for (int i = 0; i < n / 2; i++) {
    if (i * (i + 1) == n) {
      cout << i << endl << i + 1;
      return 0;
    }
  }

  cout << "-1" << "-1";
  return 0;
}
