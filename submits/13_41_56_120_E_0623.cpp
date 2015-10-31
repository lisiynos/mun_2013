#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main(){
    freopen("erd.in", "r", stdin);
    freopen("erd.out", "w", stdout);
    long long n, e, r;
    vector<long long> lol;
    cin >> n >> e;
    for (long long i = 0; i < n; i++){
       cin >> r;
       lol.push_back(r);
    }
    vector<long long> dno, kk;
    for (long long i = 0; i < n; i++){
        dno.push_back(e % (i + 1));
        kk.push_back(0);
    }
    long long g, gg;
    g = dno[n - 1] - lol[n - 1];
    if (g < 0)
        g += n;
    gg = lol[n - 1] - dno[n - 1];
    if (gg < 0)
        gg += n;
    long long l = e - g;
    r = e + gg;
    for (long long i = 0; i < n; i++){
        kk[i] = (dno[i] + gg) % (i + 1);
        dno[i] = (dno[i] - g);
        if (dno[i] < 0)
            dno[i] += n;
        dno[i] = dno[i] % (i + 1);
    }
    if (dno == lol){
        cout << l;
    }
    else if (lol == kk){
        cout << r;
    }else{
    for(;;){
            l -= n;
            r += n;
        for (long long i = 0; i < n; i++){
            kk[i] = (dno[i] + n) % (i + 1);
        }
        if (l > 0)
            for (long long i = 0; i < n; i++){
                dno[i] = (dno[i] - n);
                if (dno[i] < 0)
                    dno[i] += n;
                dno[i] = dno[i] % (i + 1);
            }
         if (dno == lol){
            cout << l;
            break;
         }
         else if (lol == kk){
            cout << r;
            break;
         }
    }
    }
    return 0;
}
