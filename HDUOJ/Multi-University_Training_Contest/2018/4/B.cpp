#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
const int MAXN = 1e5;
const LL MOD = 1e9 + 7;
const int BLOCK_SIZE = sqrt(1e5);
LL fac[MAXN + 10], inv[MAXN + 10], ans[MAXN + 10];
int block[MAXN];

struct Query {
    int n, m, index, block_id;

    bool operator<(const Query &c) const {
        if (block_id == c.block_id)
            return m < c.m;
        return block_id < c.block_id;
    }
} query[MAXN + 10];

inline LL quick_mod(LL x, LL n, LL MOD) {
    LL ret = 1;
    while (n) {
        if (n & 1)ret = ret * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return ret;
}

//预处理阶乘和阶乘逆元和块
inline void init(int n) {
    fac[0] = fac[1] = inv[0] = inv[1] = 1;
    //阶乘
    for (int i = 2; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;
    inv[n] = quick_mod(fac[n], MOD - 2, MOD);
    //阶乘逆元
    //逆元的逆元为本身
    //(n-1)!的逆元等于(n!/n)的逆元，等于n!的逆元×n的逆元的逆元，即n!的逆元×n
    for (int i = n; i > 1; i--) inv[i - 1] = inv[i] * i % MOD;
    //预处理每个数所在的块的编号
    for (int i = 1; i <= 1e5; i++) block[i] = (i - 1) / BLOCK_SIZE + 1;
}

//求组合数
inline LL C(LL n, LL m) {
    return fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("/home/lance/CLionProjects/code/HDUOJ/Multi-University_Training_Contest/2018/4/input.txt", "r+", stdin);
//    freopen("data.out", "w+", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init(MAXN);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> query[i].n >> query[i].m;
        query[i].index = i;
        query[i].block_id = block[query[i].n];
    }
    sort(query, query + T);
    int l = 0, r = 0;
    LL sum = 1, inv2 = 500000004;
    for (int i = 0; i < T; i++) {
        //S(n + 1, m) = 2 * S(n, m) - C(n, m)
        while (l < query[i].n) sum = (2 * sum - C(l, r) + MOD) % MOD, l++;
        //S(n - 1, m) = (S(n, m) + C(n - 1, m)) / 2
        while (l > query[i].n) sum = (sum + C(l - 1, r)) * inv2 % MOD, l--;
        //S(n, m + 1) = S(n, m) + C(n, m + 1)
        while (r < query[i].m) sum = (sum + C(l, r + 1)) % MOD, r++;
        //S(n, m - 1) = S(n, m) - C(n, m)
        while (r > query[i].m) sum = (sum - C(l, r) + MOD) % MOD, r--;
        ans[query[i].index] = sum;
    }
    for (int i = 0; i < T; i++) cout << ans[i] << endl;
    return 0;
}
