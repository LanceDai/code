#include <bits/stdc++.h>

#define ls(x) ((x) << 1)
#define rs(x) (ls(x) | 1)
#define mid ((l + r) >> 1)
#define lch ls(x), l, mid
#define rch rs(x), mid + 1, r

const int max_N = (1 << 18) + 21;
const int MOD = 998244353;

int T, MAXN, M, ans[max_N], isWolf[max_N], tot;

std::pair<int, int> seg[max_N];

struct cmp {
        bool operator ()(const int &x, const int &y) {
                return seg[x].second < seg[y].second;
        }
};

std::vector<int> vec[max_N << 1];

#define ALL(x) vec[x].begin(), vec[x].end()

int ROUND_UP(int n) {
    int res = 1;
    while (res < n) res <<= 1;
    return res;
}

int qi, ql, qr, last;

int query(int x, int l, int r) {
    if (r <= ql) {
        int res = 0;
        while (!vec[x].empty() && seg[vec[x].back()].second >= qr) {
            if (!ans[vec[x].back()]) {
                ++res;
                ans[vec[x].back()] = qi;
                last = int(1ll * last * vec[x].back() % MOD);
            }
            vec[x].pop_back();
        }
        return res;
    }
    int res = query(lch);
    if (ql > mid) res += query(rch);
    return res;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        static int Case = 0;
        int n;
        scanf("%d%u%u%u", &n, &x, &y, &z);
        for (int i = 0 ; i < n ; ++ i) {
            isWolf[i] = tang();
        }
        int m = std::max(0 , n - 100);
        std::nth_element(isWolf , isWolf + m , isWolf + n);
        unsigned long long ans1 = 0;
        for (int i = m ; i < n ; ++ i) {
            for (int j = i + 1 ; j < n ; ++ j) {
                ans1 = max(ans1 , 1ull * isWolf[i] / std::__gcd(isWolf[i] , isWolf[j]) * isWolf[j]);
            }
        }
        printf("Case #%d: %llu\n", ++ Case, ans1);
    }
    return 0;
}
