#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <math.h>
using namespace std;

int main() {
  freopen("abt.in", "r", stdin);
  freopen("abt.out", "w", stdout);
  //string s;
  long long n, a, b;
  cin >> n;
  a = sqrt(n);
  b = n / a;

  if ((a * b == n) && (abs(a - b) == 1))
    cout << a << " " << b;
  else
    cout << "-1 -1";

  return 0;
}
