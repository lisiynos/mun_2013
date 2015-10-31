#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main () {
  freopen ("berg.in", "r", stdin);
  freopen ("berg.out", "w", stdout);
  char a;
  bool susp = false;
  bool yslo = false;
  vector <char> stro;

  while (true) {
    a = getchar();
    stro.push_back(a);

    if (a == EOF || a < 'a' || a > 'z')
      break;
    else {
      yslo = false;
      a = getchar();

      if (a == EOF || a < 'a' || a > 'z')
        break;
      else {
        if (a != 'a') {
          susp = true;
          break;
        } else
          yslo = true;
      }
    }
  }

  if (susp == false && yslo == false) {
    for (int i = 0; i < stro.size(); i++)
      cout << stro[i];
  } else
    cout << "Suspicious!";

  return 0;
}