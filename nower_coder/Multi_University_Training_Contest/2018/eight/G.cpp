#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
const LL MOD = 1000000007;

//快速幂取法a的b次方求余p
LL pow_mod(LL a, LL b, LL p) {
    LL ans = 1;
    while (b) {
        if (b & 1)
            ans = (ans * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen(R"(data.in)", "r", stdin);
    freopen(R"(data.out)", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    LL n;
    cin >> n;
    LL inv24 = pow_mod(24, MOD - 2, MOD);
    LL inv2 = pow_mod(2, MOD - 2, MOD);
    //多边形不重叠区域个数公式 C(n,4) + C(n - 1 ,2)
    LL ans = n % MOD * (n - 1) % MOD * (n - 2) % MOD * (n - 3) % MOD * inv24 % MOD +
             (n - 1) % MOD * (n - 2) % MOD * inv2 % MOD;
    cout << ans % MOD << endl;
    return 0;
}
