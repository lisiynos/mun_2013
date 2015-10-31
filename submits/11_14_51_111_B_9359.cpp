#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string>

using namespace std;

int main(){
    freopen ("berg.in", "r", stdin);
    freopen ("berg.out", "w", stdout);
    string s;
    cin >> s;
    if (s.length() % 2 == 0){
        cout << "Suspicious!";
        return 0;
    }
    for (int i = 1; i < s.length() - 1; i+=2){
        if (s[i] != 'a'){
            cout << "Suspicious!";
            return 0;
        }
    }
    for (int i = 0; i < s.length(); i+=2){
        cout << s[i];
    }
}
