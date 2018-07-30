#include <bits/stdc++.h>

typedef long long LL;
using namespace std;
LL n, m, q, l, r, p;
vector<LL> d;
vector<LL> a;

inline int read() {
    char c = getchar();
    int x = 0, f = 1;
    while (c < '0' || c > '9') {
        if (c == '-') f = 1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    n = read();
    m = read();
    a.resize(n + 2ULL);
    d.resize(n + 2ULL);
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
    }
    while (m--) {
        q = read();
        l = read();
        r = read();
        p = read();
        if (q == 1) p = -p;
        d[l] += p;
        d[r + 1] -= p;
    }
    for (int i = 1; i <= n; ++i) {
        d[i] += d[i - 1];
        a[i] += a[i - 1] + d[i];
    }
    l = read();
    r = read();
    cout << a[r] - a[l - 1] << endl;
    return 0;
}