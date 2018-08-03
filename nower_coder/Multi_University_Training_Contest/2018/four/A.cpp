#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
map<LL, LL> m;
string s;

inline LL phi(LL x) {
    LL res = x, a = x;
    for (LL i = 2; i * i <= x; i++) {
        if (a % i == 0) {
            res = res / i * (i - 1);
            while (a % i == 0) a /= i;
        }
    }
    if (a > 1) res = res / a * (a - 1);
    return res;
}

inline void init() {
    LL i = 1e9 + 7;
    for (; i != 1; i = m[i])
        m[i] = phi(i);
    m[1] = 1;
}

LL quick_pow(LL a, LL b, LL mod) {
    LL ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

LL dfs(LL i, LL mod) {
    if (i == 0) return 0;
    else if (s[i - 1] == '0') return (dfs(i - 1, mod) + 1) % mod;
    else if (s[i - 1] == '2') return ((3LL * quick_pow(2, dfs(i - 1, m[mod]) + 1, mod) - 3) % mod + mod) % mod;
    else return (2 * dfs(i - 1, mod) + 2) % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int T;
    cin >> T;
    while (T--) {
        cin >> s;
        cout << dfs(s.length(), 1000000007) << endl;
    }
    return 0;
}