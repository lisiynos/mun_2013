#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <vector>

using namespace std;

int main(){
    freopen ("dorf.in", "r", stdin);
    freopen ("dorf.out", "w", stdout);
    int n, t;
    cin >> n >> t;
    int a[n];
    int b[n];
    int c[n];
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        --a[i];
    }
    for (int i = 0; i < n; ++i)
        c[i] = 0;
    for (int i = 0; i < n; ++i)
        b[i] = 1;
    for (int i = 0; i < t; ++i){
        for (int j = 0; j < n; ++j){
            int x;
            x = b[j];
            b[j] = 0;
            c[a[j]] += x;
        }
        for (int j = 0; j < n; ++j){
            b[j] += c[j];
            c[j] = 0;
        }
    }
    for (int i = 0; i < n; ++i)
        cout << b[i] << " ";
    return 0;
}
