#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;


/*struct Point {
  int x, y;};


int sqr(int x) {
  return x * x;}


struct Triangle {
  Point p[3];
  int S[3];

  void read() {
    for(int i = 0; i < 3; i++)
      cin >> p[i].x >> p[i].y;}

  void calc() {
    for(int i = 0; i < 3; i++) {
      int j = (i + 1) % 3;
      S[i] = sqr(p[i].x - p[j].x) + sqr(p[i].y - p[j].y);}}};


Triangle T1, T2;

bool pr(int i, int j) {
  return T1.S[i] * T2.S[j] == T1.S[j] * T2.S[i];
}*/

int main() {
  freopen("abt.in", "r", stdin);

  freopen("abt.out", "w", stdout);


  long long n, l = 0;
  cin >> n;


  for(int i = 1; i < n + 1; i++) {
    l = n / i;

    if(l == i - 1) {
      cout << l << " " << i << endl;
      return 0;
    }

    if(l == i + 1) {
      cout << i << " " << l << endl;
      return 0;
    }
  }

  cout << -1 << " " << -1 << endl;

  return 0;
}