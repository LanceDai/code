#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 100, M = 11;

int gi() {
    int w = 0;
    bool q = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') q = 0, c = getchar();
    while (c >= '0' && c <= '9') w = w * 10 + c - '0', c = getchar();
    return q ? w : -w;
}

const int MOD = 1e9 + 7;
int group[MAXN][M];
int fa[MAXN], st[MAXN];

inline int qpow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = 1LL * ans * x % MOD;
        x = 1LL * x * x % MOD;
        y >>= 1;
    }
    return ans;
}

inline void dp(int a, int b) {
    for (int i = M - 1; i; i--)
        for (int j = 1; j < i; j++)
            group[a][i] = (group[a][i] + 1LL * group[a][j] * group[b][i - j]) % MOD;
}

inline void Idp(int a, int b) {
    for (int i = 1; i < M; i++)
        for (int j = 1; j < i; j++)
            group[a][i] = (group[a][i] - 1LL * group[a][j] * group[b][i - j]) % MOD;
}

int main() {
    int n = gi(), m = gi(), i, k, s, t, top, op;
    assert(1 <= n && n <= 100000);
    assert(1 <= m && m <= 100000);
    for (i = 1; i <= n; i++) group[i][1] = gi(), assert(0 < group[i][1] && group[i][1] < MOD);
    for (i = 2; i <= n; i++) fa[i] = gi(), assert(fa[i] > 0 && fa[i] < i);
    for (i = n; i > 1; i--)
        dp(fa[i], i);
    while (m--)
        if ((op = gi()) == 2) {
            k = gi(), s = gi();
            assert(1 <= k && k <= n);
            assert(0 < s && s <= 10);
            for (i = 1; i < M; i++) group[0][i] = 0;
            for (t = k, top = 0; t && top < 10; t = fa[t]) st[++top] = t;
            while (t = st[top--]) {
                for (i = 1; i < M; i++) group[n + 1][i] = group[0][i], group[0][i] = group[t][i];
                dp(0, n + 1);
                if (top) Idp(0, st[top]);
            }
            printf("%d\n", (group[0][s] + MOD) % MOD);
        } else {
            k = gi();
            assert(1 <= k && k <= n);
            for (t = k, top = 0; t && top < 10; t = fa[t]) st[++top] = t;
            for (i = top - 1; i; i--)
                Idp(st[i + 1], st[i]);
            if (!op) {
                t = 1LL * qpow(group[k][1], MOD - 2) * gi() % MOD;
                for (i = 1; i < M; i++)
                    group[k][i] = 1LL * group[k][i] * t % MOD;
                assert(0 < group[k][1] && group[k][1] < MOD);
            } else {
                for (i = 2; i < top; i++)
                    dp(st[i + 1], st[i]);
                fa[k] = gi();
                assert(0 < fa[k] && fa[k] <= n);
                for (t = k, top = 0; t && top < 10; t = fa[t]) st[++top] = t;
                for (i = top - 1; i > 1; i--)
                    Idp(st[i + 1], st[i]);
            }
            for (i = 1; i < top; i++)
                dp(st[i + 1], st[i]);
        }
    return 0;
}
