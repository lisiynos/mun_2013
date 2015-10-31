#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;


int main() {
  freopen("abt.in", "r", stdin);
  freopen( "abt.out", "w", stdout);
  int i, d, l;
  i = -1;
  cin >> d;
  l = sqrt(d);


  if (l * (l + 1) == d)
    cout << l << " " << l + 1 << endl;
  else
    cout << i << " " << i;

  return 0;

}
