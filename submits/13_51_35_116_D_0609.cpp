#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>

using namespace std;

#define progname "dorf"

const int N = 100;

int g[N], d[N], ans[N];
vector <int> p[N];
vector <int> used;

int dfs(int v, int pr, int ind) {
    used[v] = (pr >= 0 ? used[pr] : -1) + 1;
    int w = g[v];
    if (used[w] != -1) {
        d[ind] = used[w];
        return used[v];
    }
    return dfs(w, v, ind);
}

int main()
{
    assert(freopen(progname".in", "r", stdin) != NULL);
    assert(freopen(progname".out", "w", stdout));

    int n, t;
    assert(scanf("%d%d", &n, &t) == 2);
    for (int i = 0; i < n; ++i) {
        int u;
        assert(scanf("%d", &u) == 1);
        g[i] = u - 1;
    }

    for (int i = 0; i < n; ++i) {
        used.clear();
        used.resize(n, -1);
        p[i].resize(dfs(i, -1, i) + 1);
        for (int j = 0; j < n; ++j) {
            if (used[j] != -1) {
               p[i][used[j]] = j;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (t < d[i]) {
            ++ans[p[i][t]];
            continue;
        }
        ++ans[p[i][(t - d[i]) % ((int) p[i].size() - d[i]) + d[i]]];
    }
    for (int i  =0; i < n; ++i) {
        printf("%d ", ans[i]);
    }
    cout << endl;
    return 0;
}
