#include <bits/stdc++.h>

typedef long long LL;
using namespace std;
int n, m, k;
vector<LL> r;
vector<vector<LL> > a;
vector<vector<LL> > b;
vector<vector<LL> > d;

inline LL Rand() {
    return (1LL * rand() << 15) + rand();
}

LL lowBit(LL &x) {
    return x & -x;
}

void update(LL x, LL y, LL p) {
    while (x <= n) {
        LL tmp = y;
        while (tmp <= m) {
            d[x][tmp] += p;
            tmp += lowBit(tmp);
        }
        x += lowBit(x);
    }
}

LL sum(LL x, LL y) {
    LL sum = 0;
    while (x > 0) {
        LL tmp = y;
        while (tmp > 0) {
            sum += d[x][tmp];
            tmp -= lowBit(tmp);
        }
        x -= lowBit(x);
    }
    return sum;
}

void update_range(LL x1, LL y1, LL x2, LL y2, LL &p) {
    update(x1, y1, p);
    update(x2 + 1, y1, -p);
    update(x1, y2 + 1, -p);
    update(x2 + 1, y2 + 1, p);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(rand() * rand());
    cin >> n >> m >> k;
    r.resize(n * m + 1ULL);
    a.resize(n + 2ULL);
    b.resize(n + 2ULL);
    d.resize(n + 2ULL);
    for (int i = 0; i < n + 2; ++i) {
        a[i].resize(m + 2ULL);
        b[i].resize(m + 2ULL);
        d[i].resize(m + 2ULL);
    }
    for (int i = 1; i <= n * m; i++) {
        r[i] = Rand();
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> b[i][j];
        }
    }
    LL x1, x2, y1, y2, c;
    for (int i = 1; i <= k; i++) {
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        update_range(x1, y1, x2, y2, r[c]);

    }
    LL ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (sum(i, j) % r[b[i][j]] != 0)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}