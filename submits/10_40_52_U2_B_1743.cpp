#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;


int main() {
  freopen("berg.in", "r", stdin);
  freopen( "berg.out", "w", stdout);
  int i, d, l;
  string s, s1, s2;
  getline(cin, s);
  d = s.size();

  for (i = 0; i <= d; i += 2)
    if (s[i + 1] == 'a') {
      s1 = s1 + s[i];
      l = s1.size();
    }

  for (i = 0; i <= d; i += 2)
    if (s[i + 1] != 'a')
      s2 = "Suspicious!";

  if (s1.size() != 0) {
    s1 = s1 + s[d - 1];

    for (i = 0; i <= l; i++)

      cout << s1[i] << " " << endl;
  } else
    cout << s2;

  return 0;

}