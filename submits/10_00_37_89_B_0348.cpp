#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cstring>
#define S(x) cout<<x<<endl;
using namespace std;


int main() {
  freopen("berg.in", "r", stdin);
  freopen("berg.out", "w", stdout);
  int i, a;
  char s[1000];
  string s1;
  cin >> s;
  a = strlen(s);
  s1 = s;

  for (i = 1; i < a; i = i + 2)
    if (s[i] != 'a') {
      cout << "Suspicious!" << endl;
      return 0;
    }

  for (i = 1; i < a; i++) {
    s1.erase(i, 1);
    a = a - 1;
  }

  cout << s1 << endl;

}