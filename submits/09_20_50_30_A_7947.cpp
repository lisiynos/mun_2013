#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main () {
  freopen ("abt.in", "r", stdin);
  freopen ("abt.out", "w", stdout);
  long long unsigned int n, per, del;
  cin >> n;
  bool qwe = false;;
  per = sqrt(n);
  del = n / per;

  if (n == per * del && (per == del + 1 || del == per + 1)) {
    if (per > del)
      cout << del << ' ' << per;
    else
      cout << per << ' ' << del;

    qwe = true;
  }

  if (qwe == false) {
    for (int i = 0; i < 3; i++) {
      if ((per + i) * (per + i + 1) == n) {
        cout << per + i << " " << per + i + 1;
        qwe == true;
      }
    }
  }

  if (qwe == false) {
    for (int i = 0; i < 3; i++) {
      if ((per - i) * (per - i + 1) == n) {
        cout << per - i << ' ' << per - i + 1;
        qwe = true;
      }
    }
  }

  if (qwe == false)
    cout << -1 << ' ' << -1;

  return 0;
}