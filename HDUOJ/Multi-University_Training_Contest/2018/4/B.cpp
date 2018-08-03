#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
const int N = 1e5;
const int ND = 500;
const LL MOD = 1e9 + 7;
LL fac[N + 10], inv[N + 10], ans[N + 10];

struct node {
    int n, m, index;

    bool operator<(const node &c) const {
        if (n == c.n)
            return m < c.m;
        return n < c.n;
    }
} a[N + 10];

struct nd {
    LL val, in;
} v[510];

LL quick_mod(LL x, LL n, LL MOD) {
    LL ret = 1;
    while (n) {
        if (n & 1)ret = ret * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return ret;
}

//预处理阶乘和阶乘逆元
void init(int n) {
    fac[0] = fac[1] = inv[0] = inv[1] = 1;
    //阶乘
    for (int i = 2; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;
    inv[n] = quick_mod(fac[n], MOD - 2, MOD);
    //阶乘逆元
    //逆元的逆元为本身
    //(n-1)!的逆元等于(n!/n)的逆元，等于n!的逆元×n的逆元的逆元，即n!的逆元×n
    for (int i = n; i > 1; i--) inv[i - 1] = inv[i] * i % MOD;
}

//求组合数
LL c(LL n, LL m) {
    return fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}

int main() {
    init(N);
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < T; i++) {
        cin >> a[i].n >> a[i].m;
        a[i].index = i;
    }
    sort(a, a + T);
    int x, y, ii, m = 1, k;
    for (int i = 1; i <= N; i++) {
        k = 0;
        for (int j = 0; j < i; j += ND, k++) {
            if (j == 0)
                v[k].val = 1;
            else {
                v[k].val = (v[k].val * 2 + MOD - c(i - 1, j)) % MOD;
            }
            v[k].in = j;
        }

        v[k].val = quick_mod(2ll, (LL) i, MOD);
        v[k].in = i;
        while (m <= T && a[m].n == i) {
            ii = a[m].index;
            x = a[m].m / ND;
            y = a[m].m % ND;
            if (y <= ND / 2) {
                ans[ii] = v[x].val;
                for (LL j = v[x].in + 1; j <= a[m].m; j++)
                    ans[ii] = (ans[ii] + c(i, j)) % MOD;
            } else {
                ans[ii] = v[x + 1].val;
                for (int j = a[m].m + 1; j <= v[x + 1].in; j++)
                    ans[ii] = (ans[ii] + MOD - c(i, j)) % MOD;
            }
            m++;
        }
    }
    for (int i = 1; i <= T; i++) {
        cout << ans[i] << endl;
    }
}
