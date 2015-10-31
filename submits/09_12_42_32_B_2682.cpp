#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <math.h>
using namespace std;

int main() {
  freopen("berg.in", "r", stdin);
  freopen("berg.out", "w", stdout);
  string s, ss = "";
  cin >> s;
  bool flag = 1;

  for (int i = 0; i < s.size(); i++) {
    if (i % 2 == 0)
      ss += s[i];
    else {
      if (s[i] != 'a')
        flag = 0;
    }
  }

  if (flag)
    cout << ss;
  else
    cout << "Suspicious!";

  return 0;
}
