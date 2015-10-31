#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  freopen("abt.in", "r", stdin);

  freopen("abt.out", "w", stdout);


  int n, l = 0;
  cin >> n;


  for(int i = 1; i < n + 1; i++) {
    l = n / i;

    if (l * i == n) {
      if(l == i - 1) {
        cout << l << " " << i << endl;
        return 0;
      }

      if(l == i + 1) {
        cout << i << " " << l << endl;
        return 0;
      }
    }
  }

  cout << -1 << " " << -1 << endl;

  return 0;
}