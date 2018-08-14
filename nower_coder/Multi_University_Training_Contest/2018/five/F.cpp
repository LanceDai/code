#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int MOD = 998244353;
const int MAXN = 1 << 17;

LL bit[MAXN];

void update(int x, LL v) {
    for (int i = x; i < MAXN; i += i & -i) (bit[i] *= v) %= MOD;
}

LL query(int x) {
    LL t = 1;
    for (int i = x; i; i -= i & -i) (t *= bit[i]) %= MOD;
    return t;
}

struct Node {
    int p, d;
    int id;
    bool operator<(const Node &rhs) const {
        return (d > rhs.d) || (d == rhs.d && id < rhs.id);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    LL n, inv = 828542813, ans = 0;
    cin >> n;
    //100的逆元
    for (LL &i : bit) i = 1;
    vector<Node> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].p >> a[i].d;
        a[i].id = i + 1;
    }
    sort(a.begin(), a.end());
    for (auto &t : a) {
        //查询得前缀积
        LL tmp = (query(t.id - 1) * ((inv * t.p) % MOD)) % MOD;
        (ans += tmp) %= MOD;
        update(t.id, inv * (100 - t.p) % MOD);
    }
    cout << ans << endl;
    return 0;
}
