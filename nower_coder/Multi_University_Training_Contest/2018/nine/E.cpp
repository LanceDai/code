#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, n) for (int i=a;i<n;i++)
#define per(i, a, n) for (int i=n-1;i>=a;i--)
#define cls(x) memset((x),0,sizeof((x)))
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int, int> PII;

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

const int MOD = 1000000007;
const int MAXN = 1005;
LL fac[MAXN], inv[MAXN];
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

LL f[MAXN][MAXN];
int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cls(f);
    int n, m;
    cin >> n >> m;
    vector<int> p(static_cast<unsigned long>(n));
    rep(i, 1, n + 1) {
        cin >> p[i];
        rep(j, 1, n + 1){
            rep(k, 0, j + 1){
                f[j][] = C(j, k) * f[j - 1] * p[i];
                f[j][]
            }
        }
    }
    return 0;
}