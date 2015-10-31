#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
  freopen("erd.in", "r", stdin);
  freopen("erd.out", "w", stdout);
  int n, e;
  cin >> n >> e;
  int p[20];

  for (int i = 0; i < n; i++)
    cin >> p[i];

  for (int i = abs(e % 2 - p[1]); i < 1000000000; i += 2) {
    bool flag1 = true;
    bool flag2 = true;

    for(int j = 1; j < n; j++) {
      if ( (e - i) % (j + 1) != p[j] )
        flag1 = false;

      if ( (e + i) % (j + 1) != p[j] )
        flag1 = false;
    }

    if (flag1 and ((e - i) > 0)) {
      cout << e - i;
      return 0;
    } else if (flag2) {
      cout << e + i;
      return 0;
    }

  }

  cout << "Hello world!" << endl;
  return 0;
}
