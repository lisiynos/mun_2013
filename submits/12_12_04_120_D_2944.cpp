#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main(){
    freopen("dorf.in", "r", stdin);
    freopen("dorf.out", "w", stdout);
    int n, k,  t;
    vector<int> nums, lol, nlol;
    cin >> n >> t;
    for (int i = 0; i < n; i++){
        cin >> k;
        nums.push_back(k);
        lol.push_back(1);
        nlol.push_back(0);
    }
    for (int j = 0; j < t; j++){
        for (int i = 0; i < n; i++){
            nlol[i] = 0;
        }
        for (int i = 0; i < n; i++){
            nlol[nums[i] - 1] += lol[i];
        }
        lol = nlol;
    }
    for (int i = 0; i < n; i++){
        cout << lol[i] << ' ';
    }
    return 0;
}
