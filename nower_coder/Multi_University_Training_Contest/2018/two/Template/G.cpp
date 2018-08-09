#include<bits/stdc++.h>

#define gs(c) (c < '0' || c > '9')
#define gc(c) c = getchar()
#define getint() ({ int w = 0; char gc(c); while (gs(c)) gc(c); while (!gs(c)) w = w*10+c-'0', gc(c); w; })
#define d(i, j) (int64)(x[j] - x[i])

using namespace std;

const int MAXN = 500050;

typedef long long int64;

int n, x[MAXN], query[MAXN];
int64 T, s[MAXN];

int64 sum(int l, int lc, int r, int rc) {
    return l == r ? rc - lc : s[r - 1] - s[l] + query[l] - lc + rc;
}

bool check(int64 need) {
    int l = 1, lc = 1, r = n + 1, rc = 1;

    int64 cur = 0, sa = 0;
    for (int i = 1; i <= n; ++i) {
        if (sa + query[i] <= need) sa += query[i], cur += d(1, i) * query[i];
        else {
            r = i, rc = need - sa + 1, cur += d(1, i) * (rc - 1);
            break;
        }
    }
    if (cur <= T) return 1;

    for (int i = 2; i <= n; ++i) {
        cur += d(i - 1, i) * (sum(l, lc, i, 1) - sum(i, 1, r, rc));
        while (r <= n && d(l, i) > d(i, r)) {
            int z = min(query[l] - lc + 1, query[r] - rc + 1);
            cur += (d(i, r) - d(l, i)) * z;
            if (lc += z, lc > query[l]) ++l, lc = 1;
            if (rc += z, rc > query[r]) ++r, rc = 1;
        }
        if (cur <= T) return 1;
    }
    return 0;
}

int main() {
    cin >> n >> T;
    assert(1 <= n && n <= 500000);
    assert(1 <= T && T <= 1e18);
    T /= 2;
    for (int i = 1; i <= n; ++i) x[i] = getint(), assert(1 <= n && n <= n), assert(i == 1 || x[i] > x[i - 1]);
    for (int i = 1; i <= n; ++i) query[i] = getint(), assert(0 <= query[i] && query[i] <= 1e4), s[i] = s[i - 1] + query[i];

    int64 ll = 0, rr = s[n];
    while (ll < rr) {
        int64 mm = (ll + rr + 1) >> 1;
        if (check(mm)) ll = mm;
        else rr = mm - 1;
    }
    cout << ll << endl;
}
