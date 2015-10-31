#include <iostream>
#include <cstdio>
#include <vector>
#define show(x) cout << #x << "=" << x
using namespace std;
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

int main() {
  unsigned int n, t;
  cin >> n >> t;
  unsigned int letters[n], clev[n];

  for (unsigned int i = 0; i < n; i++) {
    unsigned int um = 0;
    cin >> um;
    clev[i] = um - 1;
    letters[i] = 1;
  }

  for (unsigned int j = 0; j < t; j++) {
    for (unsigned int i = 0; i < n; i++) {
      if (letters[i] != 0 || clev[i] != i) {
        letters[clev[i]] = letters[i];
        letters[i] = 0;
      }

    }
  }

  for (unsigned int i = 0; i < n; i++)
    cout << letters[i] << endl;
}
