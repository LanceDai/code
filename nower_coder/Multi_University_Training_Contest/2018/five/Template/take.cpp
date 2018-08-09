#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<iostream>
#include<assert.h>
#include<queue>
#include<string>

#define rep(i, j, k) for(int i=(int)j;i<=(int)k;i++)
#define per(i, j, k) for(int i=(int)j;i>=(int)k;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long LL;
const int MOD = 998244353;
const int MAXN = 100005;

inline int Pow(int a, int b) {
    int c = 1;
    for (; b; b >>= 1, a = a * 1ll * a % MOD)if (b & 1)c = c * 1ll * a % MOD;
    return c;
}

int p[MAXN], d[MAXN], n, inv100;
int tmp[MAXN], m;
int cnt[MAXN];

void add(int x, int v) {
    for (; x <= m; x += (x & (-x)))cnt[x] = cnt[x] * 1ll * v % MOD;
}

int ask(int x) {
    int ans = 1;
    for (; x; x -= (x & (-x)))ans = ans * 1ll * cnt[x] % MOD;
    return ans;
}

int main() {
    scanf("%d", &n);
    assert(1 <= n && n <= 100000);
    inv100 = Pow(100, MOD - 2);
    for (int i = (int) 1; i <= (int) n; i++) {
        scanf("%d%d", &p[i], &d[i]);
        assert(1 <= p[i] && p[i] <= 100);
        assert(1 <= d[i] && d[i] <= 1000000000);
        p[i] = p[i] * 1ll * inv100 % MOD;
        tmp[++m] = d[i];
    }
    sort(tmp + 1, tmp + 1 + m);
    m = unique(tmp + 1, tmp + 1 + m) - tmp - 1;
    for (int i = (int) 1; i <= (int) n; i++)d[i] = lower_bound(tmp + 1, tmp + 1 + m, d[i]) - tmp;
    for (int i = (int) 0; i <= (int) m; i++)cnt[i] = 1;
    int ans = 0;
    for (int i = (int) 1; i <= (int) n; i++) {
        ans = (ans + ask(m - d[i] + 1) * 1ll * p[i]) % MOD;
        add(m - d[i] + 1, (MOD + 1 - p[i]) % MOD);
    }
    printf("%d\n", ans);
    return 0;
}






