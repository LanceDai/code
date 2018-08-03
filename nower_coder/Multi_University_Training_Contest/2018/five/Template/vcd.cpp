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
const int N = 110000;
const int MOD = 998244353;
int n;
pair<int, int> a[N];

inline bool cmpy(const pair<int, int> &x, const pair<int, int> &y) {
    if (x.second != y.second)return x.second < y.second;
    return x.first < y.first;
}

int tmp[N * 2], m;
int cnt[N];

void add(int x) {
    for (; x <= m; x += (x & (-x)))cnt[x]++;
}

int ask(int x) {
    int ans = 0;
    for (; x; x -= (x & (-x)))ans += cnt[x];
    return ans;
}

int pre[N], suf[N];
map<pair<int, int>, bool> hv;

int main() {
    scanf("%d", &n);
    assert(1 <= n && n <= 100000);
    for (int i = (int) 1; i <= (int) n; i++) {
        scanf("%d%d", &a[i].first, &a[i].second);
        assert(1 <= a[i].fi && a[i].fi <= 1000000000);
        assert(1 <= a[i].se && a[i].se <= 1000000000);
        assert(!hv[a[i]]);
        hv[a[i]] = 1;
        tmp[++m] = a[i].first;
    }
    sort(tmp + 1, tmp + 1 + m);
    m = unique(tmp + 1, tmp + 1 + m) - tmp - 1;
    for (int i = (int) 1; i <= (int) n; i++) {
        a[i].first = lower_bound(tmp + 1, tmp + 1 + m, a[i].first) - tmp;
    }
    sort(a + 1, a + 1 + n, cmpy);
    int ans = n;
    for (int i = (int) 1; i <= (int) n; i++) {
        int j = i;
        while (j < n && a[j + 1].second == a[i].second)++j;
        ans = (ans + (j - i + 1) * 1ll * (i - 1)) % MOD;
        for (int k = (int) i; k <= (int) j; k++) {
            pre[k] = ask((m - a[k].first + 1) - 1);
        }
        for (int k = (int) i; k <= (int) j; k++)add(m - a[k].first + 1);
        i = j;
    }
    memset(cnt, 0, sizeof cnt);
    for (int i = (int) n; i >= (int) 1; i--) {
        int j = i;
        while (j > 1 && a[j - 1].second == a[i].second)--j;
        for (int k = (int) j; k <= (int) i; k++) {
            suf[k] = ask(m - a[k].first + 1 - 1);
        }
        for (int k = (int) j; k <= (int) i; k++)add(m - a[k].first + 1);
        i = j;
    }
    for (int i = (int) 1; i <= (int) n; i++)ans = (ans + pre[i] * 1ll * suf[i]) % MOD;
    printf("%d\n", ans);
    return 0;
}






