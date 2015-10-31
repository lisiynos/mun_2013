#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main() {
  freopen("abt.in", "r", stdin);
  freopen("abt.out", "w", stdout);

  long long n;

  cin >> n;

  for(int i = 1 ; i < n / 2; i++)
    for(int j = 1 ; j < n / 2 + 1; j++) {
      if( (i * j == n) && (abs(i - j) == 1)) {
        if ((i - j) > 0) {
          cout << j << " " << i << endl;
          return 0;
        } else {
          cout << i << " " << j << endl;
          return 0;
        }
      }
    }


  cout << -1 << " " << -1 << endl;
  return 0;
}
