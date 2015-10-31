#include <iostream>
#include <cstdio>
#include <string>
#define show(x) cout << #x << "=" << x
using namespace std;

int main() {

  freopen("berg.in", "r", stdin);
#ifndef DEBUG
  freopen("berg.out", "w", stdout);
#endif // DEBUG
  string n, n1;
  cin >> n;

  if (n.size() % 2 == 0) {
    cout << "Suspicious!";
    return 0;
  }

  for (unsigned int i = 0; i < n.size(); i += 2) {
    if ((i + 1 < n.size()) && (n[i + 1] != 'a')) {
      cout << "Suspicious!";
      return 0;
    } else
      n1 += n[i];
  }

  cout << n1;
  return 0;
}
