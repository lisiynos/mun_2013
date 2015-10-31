#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstdlib>

using namespace std;

const int MAXN = 51;

int ans[MAXN], ans_nw[MAXN], gr[MAXN];
int used[MAXN], tme[MAXN];

int getT(int i, int col, int cT = 0)
{
    used[i] = col;
    tme[i] = cT;
    if (!used[gr[i]]) {
        return getT(gr[i], col, cT + 1);
    } else {
        if (used[gr[i]] == col) return cT + 1 - tme[gr[i]];
    }

    return -1;
}

void upd(int pos, int col)
{
    used[pos] = col;
    ans_nw[gr[pos]] += ans[pos];

    if (used[gr[pos]] != col) upd(gr[pos], col);
}

int main()
{
    assert(freopen("dorf.in", "r", stdin) != NULL);
    assert(freopen("dorf.out", "w", stdout));

    int n, t; cin >> n >> t;

    for (int i = 0; i < n; i++)
    {
        cin >> gr[i];
        --gr[i];
        ans[i] = 1;
    }

    for (int i = 1; i <= min(t, 2); i++)
    {
        for (int j = 0; j < n; j++)
            ans_nw[gr[j]] += ans[j];
        for (int j = 0; j < n; j++)
            ans[j] = ans_nw[j], ans_nw[j] = 0;
    }

    t -= min(t, 2);

    if (!t) {
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        return 0;
    }

    int color = 1;
    for (int i = 0; i < n; i++)
    {
        if (used[i]) continue;
        int T = getT(i, ++color);
//        cout << T << endl;
        if (T != -1) {
            for (int j = 0; j < t % T; j++)
            {
                upd(i, ++color);
                for (int k = 0; k < n; k++)
                    if (used[k] == color) ans[k] = ans_nw[k], ans_nw[k] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";

    return 0;
}
