#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("dorf.in","r",stdin);
    freopen("dorf.out","w",stdout);
    int n, t;
    cin >> n >> t;
    int v[51];
    int let[2][51];
    for (int i = 0;i < n; i++){
        cin >> v[i];
        v[i]--;
        let[0][i] = 1;
        let[1][i] = 0;
    }
    int num = 0;
    for (int j = 0; j < t; j++){
        for(int i = 0; i<n; i++){
            int pr = let[num%2][i];
            let[num%2][i] = 0;
            let[(num%2+1)%2][v[i]] += pr;
        }
        num++;
    }

    for (int i = 0; i < n; i++)
        cout << let[num%2][i] << " ";
    return 0;
}
