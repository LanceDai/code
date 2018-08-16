#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

inline LL quick_mod(LL x, LL n, LL MOD) {
    LL ret = 1;
    while (n) {
        if (n & 1)ret = ret * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\in)", "r", stdin);
//    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\out)", "w", stdout);
#endif
    cout << (0 + 1 + 1 + 16 + 1 + 2 + 16 + 81) * quick_mod(8, 1000000005, 1000000007) % 1000000007 << endl;
    return 0;
}
