#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
  freopen("berg.in", "r", stdin);

  freopen("berg.out", "w", stdout);
  string a;
  getline(cin, a);
  int k = 1, l = 0;

  while(k != a.size()) {
    if(a[k] != 'a') {
      cout << "Suspicious!" << endl;
      return 0;
    }

    k = k + 2;
  }

  l = 0;

  while(l <= a.size()) {
    cout << a[l];
    l = l + 2;

    if(l == a.size()) return 0;
  }

  return 0;
}