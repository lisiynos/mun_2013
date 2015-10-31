#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <math.h>
using namespace std;

int main() {
  freopen("dorf.in", "r", stdin);
  freopen("dorf.out", "w", stdout);
  //string s;
  long long t0;
  int n;
  cin >> n >> t0;
  //t0--;
  vector <int> graph(n);
  pair <int, int> t;
  vector <int> gg(n);
  vector <int> ans(n);

  for (int i = 0; i < n; i++) {
    cin >> graph[i];
    graph[i]--;
  }

  for (int i = 0; i < n; i++) {
    int j = i, c = 2, t1 = t0;

    for (int k = 0; k < n; k++)
      gg[k] = 0;

    //gg[i].resize(n);
    gg[i] = 1;
    j = graph[j];

    //cout << "hh";
    while (gg[j] == 0) {
      gg[j] = c;
      j = graph[j];
      c++;
    }

    t = make_pair(c - gg[j], gg[j]);
    t1 -= (t.second - 1);
    t1 = (t1 % t.first + t.first) % t.first;

    //cout << t.first << " " << t1 << " " << j + 1 << " " << t.second << endl;
    for (int k = 0; k < t1; k++) {
      //cout << "g";
      j = graph[j];
    }

    //cout << j;
    ans[j]++;
    //cout << "gg";
  }

  for (int i = 0; i < n; i++)
    cout << ans[i] << " ";

  return 0;
}
