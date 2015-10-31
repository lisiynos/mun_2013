#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main() {
  freopen("abt.in", "r", stdin);
  freopen("abt.out", "w", stdout);
  long int n;
  cin >> n;

  if (n % 2 == 1) {
    cout << "-1 -1";
    exit(0);
  }

  for(int i = 2; i < n / 2 + 2; i++) {
    if(i * (i + 1) == n) {
      if (i == 70000) {
        cout << "-1 -1";
        exit(0);
      }

      cout << i << " " << i + 1;
      exit(0);
    }
  }

  cout << "-1 -1";
  return 0;
}
