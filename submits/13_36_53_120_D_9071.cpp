#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main(){
    freopen("dorf.in", "r", stdin);
    freopen("dorf.out", "w", stdout);
     long long n, k,  t;
    vector<long long> nums, lol, nlol;
    cin >> n >> t;
    for (long long i = 0; i < n; i++){
        cin >> k;
       nums.push_back(k);
        lol.push_back(1);
        nlol.push_back(0);
    }
    for (long long j = 0; j < t; j++){
        for (long long i = 0; i < n; i++){
            nlol[i] = 0;
        }
        for (long long i = 0; i < n; i++){
            nlol[nums[i] - 1] += lol[i];
        }
        lol = nlol;
    }
    for (long long i = 0; i < n; i++){
        cout << lol[i] << ' ';
    }
    return 0;
}
