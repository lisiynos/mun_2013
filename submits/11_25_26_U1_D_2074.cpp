#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
  long long n, t;
  freopen("dorf.in", "r", stdin);
  freopen("dorf.out", "w", stdout);
  cin >> n >> t;

  long long z[n];
  int o;

  for (int i = 0; i < n; i++) {
    int o;
    cin >> o;
    z[i] = o - 1;
  }

  int post[n];
  fill(post, post + n, 1);

  for (long long i = 0; i < t; i++) {
    int newa[n];
    fill(newa, newa + n, 0);

    for (int i = 0; i < n; i++) {
      newa[z[i]] += post[i];
      post[i] = 0;
    }

    for (int i = 0; i < n; i++)
      post[i] = newa[i];
  }

  for (int i = 0; i < n; i++)
    cout << post[i] << " ";

  cout << endl;
}
