#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int MOD = 998244353;

LL quick_mod(LL a, LL n = MOD - 2) {
    LL t = 1;
    for (; n; n >>= 1, (a *= a) %= MOD)
        if (n & 1) (t *= a) %= MOD;
    return t;
}

int main() {

    cout << ( quick_mod(100))% MOD << endl;
    return 0;
}