#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>

//Be happy :3

#define problem "dorf"

using namespace std;

const int N = 52;

int ans[N];
int graph[N];
int total[N];
vector <int> childs[N];
vector <int> used;

int imbadfs(int current, int pre, int point) {
    used[current] = (pre >= 0 ? used[pre] : -1) + 1;
    int to = graph[current];
    if (used[to] != -1) {
        total[point] = used[to];
        return used[current];
    }
    return imbadfs(to, current, point);
}

int main()
{
    assert(freopen(problem".in", "r", stdin) != NULL);
    assert(freopen(problem".out", "w", stdout));

    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        graph[i] = a - 1;
    }

    for (int i = 0; i < n; i++) {
        used.clear();
        used.resize(n, -1);
        int dfsv = imbadfs(i, -1, i);
        childs[i].resize(dfsv + 1);
        for (int j = 0; j < n; j++) if (used[j] != -1) childs[i][used[j]] = j;
    }

    for (int i = 0; i < n; i++) {
        if(t >= total[i]) {
            int a = childs[i][(t - total[i]) % (childs[i].size() - total[i]) + total[i]];
            ans[a]++;
        }else ans[childs[i][t]]++;
    }

    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}
