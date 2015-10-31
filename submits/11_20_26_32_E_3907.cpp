#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <math.h>
#define baget int
using namespace std;

baget main() {
  freopen("erd.in", "r", stdin);
  freopen("erd.out", "w", stdout);
  //string s;
  long long t0;
  baget n;
  cin >> n >> t0;
  vector <baget> gg(n);

  for (baget i = 0; i < n; i++)
    cin >> gg[i];

  long long counter = gg[n - 1], c;
  bool flag = 1, f1 = 1;

  while (flag || f1) {
    bool f = 0;

    for (baget i = 0; i < n; i++) {
      //cout << i << " " << counter % (i + 1) << endl;
      if ((counter % (i + 1)) != gg[i])
        f = 1;
    }

    flag = f;

    if ((!flag) && f1) {
      f1 = 0;
      flag = 1;
      c = counter;
    }

    //cout << counter << " " << flag << " " << f1 << " gg ";
    counter += n;
  }

  counter -= n;
  //cout << c << " " << counter;
  long long t = counter - c;
  long long ans = (t0 - c) / t;
  ans = ans * t + c;

  if (abs(ans - t0) <= abs(ans + t - t0))
    cout << ans;
  else
    cout << ans + t;

  return 0;
}
