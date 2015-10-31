#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main () {
  freopen ("dorf.in", "r", stdin);
  freopen ("dorf.out", "w", stdout);
  long long unsigned int n, t, per;
  cin >> n >> t;
  vector <int> clever_bro, pisma, perenos;

  for (int i = 0; i < n; i ++) {
    perenos.push_back(0);
    pisma.push_back(1);
    cin >> per;
    per --;
    clever_bro.push_back(per);
  }

  for (long long unsigned int i = 0; i < t; i ++) {
    for (int j = 0; j < n; j++)
      perenos[clever_bro[j]] = perenos[clever_bro[j]] + pisma[j];

    for (int j = 0; j < n; j++) {
      pisma[j] = perenos[j];
      perenos[j] = 0;
    }
  }

  for (int i = 0; i < n; i++)
    cout << pisma[i] << ' ';

  return 0;
}