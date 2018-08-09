#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;
typedef long long LL;
LL fac[MAXN], inv[MAXN], fbi[MAXN];

inline LL quick_mod(LL x, LL n, LL MOD) {
    LL ret = 1;
    while (n) {
        if (n & 1)ret = ret * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return ret;
}

//预处理阶乘和阶乘逆元和斐波那契数列
inline void init() {
    fac[0] = fac[1] = inv[0] = inv[1] = fbi[1] = 1;
    fbi[0] = 0;
    //阶乘
    for (int i = 2; i <= MAXN; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        fbi[i] = (fbi[i - 1] + fbi[i - 2]) % MOD;
    }
    inv[MAXN] = quick_mod(fac[MAXN], MOD - 2, MOD);
    //阶乘逆元
    //逆元的逆元为本身
    //(n-1)!的逆元等于(n!/n)的逆元，等于n!的逆元×n的逆元的逆元，即n!的逆元×n
    for (int i = MAXN; i > 1; i--) inv[i - 1] = inv[i] * i % MOD;
}

//求组合数
inline LL C(LL n, LL m) {
    return fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("/home/lance/CLionProjects/code/HDUOJ/Multi-University_Training_Contest/2018/6/input.txt", "r", stdin);
    freopen("/home/lance/Documents/Tencent Files/603842325/FileRecv/hdu-multi6-fzdx/data/1002/in", "r", stdin);
    freopen("/home/lance/Documents/Tencent Files/603842325/FileRecv/hdu-multi6-fzdx/data/out.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, n, k;
    LL sum, sum_val, g_expect;
    init();
    cin >> T;
    while (T--) {
        vector<LL> g_number;
        vector<LL> g_val;
        cin >> n >> k;
        sum = sum_val = 0;
        //枚举ｎ的约数，对每一个约数，求经典组合数作为出现次数，计算数学期望
        for (int i = 1; i <= n; ++i) {
            if (!(n % i)) {
                g_number.push_back(i);
                g_val.push_back(C(n / i + k - 1, k - 1));
            }
        }
        //通过容斥，把是ｇ的倍数的但不是ｇ的方案数删除，得到严格是ｇ的方案数
        for (int i = 0; i < g_number.size(); ++i) {
            for (int j = i + 1; j < g_number.size(); ++j) {
                if (g_number[j] % g_number[i] == 0) {
                    g_val[i] = (g_val[i] - g_val[j] + MOD) % MOD;
                }
            }
        }
        for (int i = 0; i < g_number.size(); ++i) {
            sum_val += g_val[i] * g_number[i];
            sum += g_val[i];
        }
        //得到ｇ的数学期望，计算２^F[g]-1,Ｆ[g]很大，需要欧拉降幂
        g_expect = (sum_val * quick_mod(sum, MOD - 2, MOD)) % MOD;
        cout << quick_mod(2, fbi[g_expect], MOD) + 1 << endl;
    }
    return 0;
}