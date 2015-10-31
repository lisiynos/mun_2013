#include <iostream>
#include <cstdio>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
  freopen("abt.in", "r", stdin);
  freopen("abt.out", "w", stdout);
  int n, a;
  cin >> n;
  a = int(sqrt(n));

  if (a * (a + 1) == n)
    cout << a << " " << a + 1;
  else
    cout << -1 << " " << -1;
}
