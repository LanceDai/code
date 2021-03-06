#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>

using int64 = long long;

constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 1e5 + 10;

int64 pow_mod(int64 a, int64 n) {
    int64 r = 1;
    for (; n; n >>= 1) {
        if (n & 1) r = r * a % MOD;
        a = a * a % MOD;
    }
    return r;
}

struct point {
    int64 x, y;
    int64 a, b;  // a keep, b not keep
    int64 u, v;

    bool operator<(const point &rhs) const {
        return x < rhs.x || (x == rhs.x && y > rhs.y);
    }
} p[MAXN];

int prev[MAXN];
int n;

struct SegmentTree {
    struct node {
        int64 sum1, sum2, tag;
        int64 mul1, mul2;

        void set(int64 x) {
            mul1 = mul1 * x % MOD;
            sum1 = sum1 * x % MOD;
            mul2 = mul2 * x % MOD;
            sum2 = sum2 * x % MOD;
            tag = tag * x % MOD;
        }
    } u[MAXN << 2];

    void update(int o) {
        u[o].sum1 = (u[o << 1].sum1 + u[o << 1 | 1].sum1) % MOD;
        u[o].sum2 = (u[o << 1].sum2 + u[o << 1 | 1].sum2) % MOD;
    }

    void build(int o, int l, int r, point *p) {
        u[o].sum1 = u[o].sum2 = 0;
        u[o].tag = 1;
        if (l + 1 == r) {
            u[o].mul1 = p[l].u;
            u[o].mul2 = p[l].u * p[l].x % MOD;
            return;
        }
        int m = (l + r) >> 1;
        build(o << 1, l, m, p);
        build(o << 1 | 1, m, r, p);
    }

    void pushdown(int o) {
        if (u[o].tag != 1) {
            u[o << 1].set(u[o].tag);
            u[o << 1 | 1].set(u[o].tag);
            u[o].tag = 1;
        }
    }

    void ins(int o, int l, int r, int L, int R, int64 v) {
        if (L >= R) return;
        if (L <= l && R >= r) {
            u[o].set(v);
            return;
        }
        pushdown(o);
        int m = (l + r) >> 1;
        if (L < m) ins(o << 1, l, m, L, R, v);
        if (R > m) ins(o << 1 | 1, m, r, L, R, v);
        update(o);
    }

    void set(int o, int l, int r, int x) {
        if (l + 1 == r) {
            u[o].sum1 = u[o].mul1;
            u[o].sum2 = u[o].mul2;
            return;
        }
        pushdown(o);
        int m = (l + r) >> 1;
        if (x < m) set(o << 1, l, m, x);
        else set(o << 1 | 1, m, r, x);
        update(o);
    }
} st;

struct FenwickTree {
    int64 u[MAXN];
    int n;

    void clear(int _n) {
        n = _n;
        for (int i = 0; i <= n; ++i) u[i] = 1;
    }

    void set(int x, int64 v) {
        for (; x <= n; x += ~x & x + 1) u[x] = u[x] * v % MOD;
    }

    int64 get(int x, int64 r = 1) {
        for (; x >= 0; x -= ~x & x + 1) r = r * u[x] % MOD;
        return r;
    }

    void setr(int x, int64 v) {
        for (; x >= 0; x -= ~x & x + 1) u[x] = u[x] * v % MOD;
    }

    int64 getr(int x, int64 r = 1) {
        for (; x <= n; x += ~x & x + 1) r = r * u[x] % MOD;
        return r;
    }
} ft;

int64 solve(int l, int r) {
    if (l + 1 == r) return 0;
    int m = (l + r) >> 1;
    int64 acc = solve(l, m) + solve(m, r);
    int64 ret = 0;
    std::vector<int> idx(r - l);
    for (int i = l; i < r; ++i) idx[i - l] = i;
    std::sort(idx.begin(), idx.end(), [&](int a, int b) {
        return p[a].y > p[b].y;
    });
    st.build(1, 0, m - l, p + l);
    ft.clear(r - m);
    for (int i = 0, j; i < r - l; i = j) {
        for (j = i; j < r - l && p[idx[i]].y == p[idx[j]].y; ++j) {
            if (idx[j] >= m) {
                int o = idx[j];
                int64 sum1 = st.u[1].sum1;
                int64 sum2 = st.u[1].sum2;
                ret += p[o].y % MOD * ft.get(o - m) % MOD * p[o].v % MOD * (p[o].x * sum1 % MOD - sum2 + MOD) % MOD;
            }
        }
        for (int k = i; k < j; ++k) {
            int o = idx[k];
            int t = prev[o];
            if (o >= m) {
                if (t >= m) ft.set(o - m, p[o].b);
                else st.ins(1, 0, m - l, 0, t - l, p[o].b);
            } else {
                st.set(1, 0, m - l, o - l);
                st.ins(1, 0, m - l, 0, t - l, p[o].b);
            }
        }
    }
    return (ret + acc) % MOD;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%lld%lld%lld%lld", &p[i].x, &p[i].y, &p[i].a, &p[i].b);
        }
        std::sort(p, p + n);
        int nn = n;
        n = 0;
        for (int i = 0, j; i < nn; i = j) {
            int64 a = 1, b = 1, ib;
            for (j = i; j < nn && p[i].x == p[j].x && p[i].y == p[j].y; ++j) {
                a = a * (p[j].b - p[j].a) % MOD;
                b = b * p[j].b % MOD;
            }
            ib = pow_mod(b, MOD - 2);
            a = (b - a + MOD) % MOD;
            p[n] = p[i];
            p[n].a = a * ib % MOD;
            p[n].b = (b - a + MOD) * ib % MOD;
            ++n;
        }
        for (int i = 0, j; i < n; i = j) {
            int64 mul = 1;
            for (j = i; j < n && p[i].x == p[j].x; ++j) {
                p[j].u = mul * p[j].a % MOD;
                mul = mul * p[j].b % MOD;
            }
        }
        std::vector<int> idx(n);
        for (int i = 0; i < n; ++i) idx[i] = i;
        std::sort(idx.begin(), idx.end(), [&](int a, int b) {
            return p[a].y > p[b].y || (p[a].y == p[b].y && a > b);
        });
        ft.clear(n);
        int64 ret = 0;
        for (int i = 0; i < n; ++i) {
            int o = idx[i];
            p[o].v = p[o].a * ft.getr(o) % MOD;
            ft.setr(o, p[o].b);
        }
        std::sort(p, p + n);
        for (int i = 0; i < n; ++i) {
            prev[i] = i;
            if (i && p[i].x == p[i - 1].x) prev[i] = prev[i - 1];
        }
        ret = solve(0, n);
        std::sort(idx.begin(), idx.end(), [&](int a, int b) {
            return p[a].y > p[b].y || (p[a].y == p[b].y && a > b);
        });
        int64 all = 1;
        for (int i = 0, j; i < n; i = j) {
            for (j = i; j < n && p[idx[i]].y == p[idx[j]].y; ++j) {
                ret += all * p[idx[j]].x % MOD * p[idx[j]].y % MOD * p[idx[j]].a % MOD;
                all = all * p[idx[j]].b % MOD;
            }
        }
        printf("%lld\n", ret % MOD);
    }
    return 0;
}
