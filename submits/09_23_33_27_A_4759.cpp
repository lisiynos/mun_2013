#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main() {
  freopen("abt.in", "r", stdin);
  freopen("abt.out", "r", stdout);
  long int n;
  cin >> n;

  for(int i = 0; i < n / 2 + 2; ++i) {
    if(i * (i + 1) == n) {
      cout << i << " " << i + 1;
      exit(0);
    }
  }

  cout << "-1 -1";
  return 0;
}
