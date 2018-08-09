#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long ULL;
unsigned x, y, z;

inline unsigned tang() {
    unsigned t;
    x ^= x << 16;
    x ^= x >> 5;
    x ^= x << 1;
    t = x;
    x = y;
    y = z;
    z = t ^ x ^ y;
    return z;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("/home/lance/CLionProjects/code/nower_coder/Multi_University_Training_Contest/2018/six/input.txt", "r+",
            stdin);
    freopen("/home/lance/CLionProjects/code/nower_coder/Multi_University_Training_Contest/2018/six/output.txt", "w+",
            stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        int n;
        cin >> n >> x >> y >> z;
        set<ULL> s;
        ULL ans = 0, p;
        while (n--) {
            p = tang();
            if (p > *s.begin()) {
                s.insert(p);
                if (s.size() >= 100) s.erase(s.begin());
            }
        }
        auto iter2 = s.end();
        for (auto iter = s.begin(); iter != iter2; iter++) {
            ULL x = *iter;
            auto iter3 = s.begin();
            for (; iter3 != iter2 && *iter != *iter3; iter3++) {
                ULL y = *iter3;
                if (x != y && __gcd(x, y) == 1) ans = max(ans, x * y);
            }
        }
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}