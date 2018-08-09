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
}

//求组合数
inline LL C(LL n, LL m) {
    return fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}