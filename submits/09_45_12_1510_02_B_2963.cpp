#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <stdlib.h>
using namespace std;

int main() {
  freopen("berg.in", "r", stdin);
  freopen("berg.out", "w", stdout);

  string n;

  getline (cin , n);

  int k, l;

  k = 1;

  while (k != n.size()) {
    if (n[k] != 'a') {
      cout << "Suspicious!" << endl;
      return 0;
    }

    k = k + 2;
  }

  l = 0;

  while (l <= n.size() ) {
    cout << n[l] ;
    l = l + 2;

    if (l == n.size()) return 0;
  }


  return 0;
}