#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main() {
  freopen("abt.in", "r", stdin);
  freopen("abt.out", "w", stdout);

  long long n, l;

  cin >> n;

  for(int i = 1 ; i < n / 2; i++)

  {
    l = n / i;

    if (i * l == n) {
      if ((i - l) == 1) {
        cout << j << " " << i << endl;
        return 0;
      }

      if ((i - l) == -1) {
        cout << i << " " << j << endl;
        return 0;
      }
    }
  }


  cout << -1 << " " << -1 << endl;
  return 0;
}
