#include <iostream>
#include <string>
#include <fstream>


using namespace std;

int main() {
  freopen("berg.in", "r", stdin);
  freopen("berg.out", "w", stdout);

  string s;
  int i = 1;
  char ch;
  getline(cin, s);

  if ((s.size()) % 2 == 0) {
    cout << "Suspicious!";
    return 0;
  }

  while (i < s.size()) {
    ch = s[i];

    //cin >> ch;
    if (ch != 'a') {
      cout << "Suspicious!";
      return 0;
    }

    i += 2;
  }

  for (int j = 0; j < s.size(); j += 2)
    cout << s[j];
}
