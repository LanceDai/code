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
const int MAXN = 210000;
int n, query[MAXN];
int cnt[MAXN];

void bitadd(int x, int v) {
    for (; x <= n; x += (x & (-x)))cnt[x] += v;
}

int bitsum(int x) {
    int ans = 0;
    for (; x; x -= (x & (-x)))ans += cnt[x];
    return ans;
}

LL getinv() {
    LL ans = 0;
    for (int i = (int) 1; i <= (int) n / 2; i++) {
        ans += i - 1 - bitsum(query[i] - 1);
        bitadd(query[i], 1);
    }
    return ans;
}

int mi[MAXN << 2];
int cov[MAXN << 2];

void upd(int me) {
    mi[me] = min(mi[me << 1], mi[me << 1 | 1]) + cov[me];
}

void build(int me, int l, int r) {
    if (l == r) {
        mi[me] = l;
        return;
    }
    int mid = (l + r) >> 1;
    build(me << 1, l, mid);
    build(me << 1 | 1, mid + 1, r);
    upd(me);
}

void segadd(int me, int l, int r, int x, int y, int v) {
    if (x <= l && r <= y) {
        mi[me] += v;
        cov[me] += v;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)segadd(me << 1, l, mid, x, y, v);
    if (y > mid)segadd(me << 1 | 1, mid + 1, r, x, y, v);
    upd(me);
}

int pos[MAXN];

int main() {
    scanf("%d", &n);
    assert(n % 2 == 0);
    assert(2 <= n && n <= 200000);
    for (int i = (int) 1; i <= (int) n / 2; i++) {
        scanf("%d", &query[i]);
        assert(query[i] % 2 == 0);
        assert(1 <= query[i] && query[i] <= n);
        assert(!pos[query[i]]);
        pos[query[i]] = i;
    }
    LL ans = getinv();
    //return 0;
    build(1, 0, n / 2);
    for (int i = 1; i <= n - 1; i += 2) {
        ans += i / 2 + mi[1];
        assert(i / 2 + mi[1] >= 0);
        int d = pos[i + 1];
        segadd(1, 0, n / 2, d, n / 2, -2);
    }
    printf("%lld\n", ans);
    return 0;
}





