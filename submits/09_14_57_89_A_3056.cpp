#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#define S(x) cout<<"x = "<<x<<endl;
using namespace std;
int sqr(int x) {
  return x * x;
};

int main() {
  freopen("abt.in", "r", stdin);
  freopen("abt.out", "w", stdout);
  float x;
  int a, b, n;
  cin >> n;
  x = sqrt(n);
  a = floor(x);
  b = ceil(x);

  if (a != b and a * b == n)
    cout << a << " " << b << endl;
  else
    cout << "-1 -1" << endl;


}