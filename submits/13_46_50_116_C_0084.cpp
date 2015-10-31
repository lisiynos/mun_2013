#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>

using namespace std;

struct point {
    int x, y;
    point(int _x = 0, int _y = 0): x(_x), y(_y) {}
    point operator - (point p) {
        return point(x - p.x, y - p.y);
    }
    int len() {
        return x * x + y * y;
    }
    void scan() {
        assert(scanf("%d%d", &x, &y) == 2);
    }
};

struct line {
    int a, b, c;
    line(int _a = 0, int _b = 0, int _c = 0): a(_a), b(_b), c(_c) {}
    line(point p, point q): a(p.y - q.y), b(q.x - p.x), c(p.x * q.y - p.y * q.x) {}
};

int dist(point a, point b) {
    return (a - b).len();
}

int dist(point p, line l) {
    return l.a * p.x + l.b * p.y + l.c;
}

int main()
{
    assert(freopen("cord.in", "r", stdin) != NULL);
    assert(freopen("cord.out", "w", stdout));

    int ans = 0;
    point p[3], t = point(0, 0);
    int r;

    p[0].scan();
    assert(scanf("%d", &r) == 1);
    if (dist(t, p[0]) < r * r) {
        ++ans;
    }

    for (int i = 0; i < 2; ++i) {
        p[i].scan();
    }
    if (p[0].x < t.x && t.x < p[1].x && p[0].y < t.y && t.y < p[1].y) {
        ++ans;
    }

    for (int i = 0; i < 3; ++i) {
        p[i].scan();
    }
    int mask = 0;
    for (int i = 0; i < 3; ++i) {
        line l = line(p[(i + 1) % 3], p[(i + 2) % 3]);
        mask += ((dist(p[i], l) > 0) << i);
    }
    ++ans;
    for (int i = 0; i < 3; ++i) {
        line l = line(p[(i + 1) % 3], p[(i + 2) % 3]);
        if (((dist(t, l) > 0) << i) & mask == 0) {
            --ans;
            break;
        }
    }

    printf("%d\n", ans);
    return 0;
}
