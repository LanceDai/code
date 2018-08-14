#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const LL MAXN = 100005;
LL query[MAXN], nextInRight[MAXN], ans;

void Merge(LL l, LL m, LL r) {
    LL i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        if (query[i] > query[j]) {
            nextInRight[k++] = query[j++];
            ans += m - i + 1;
        } else
            nextInRight[k++] = query[i++];
    }
    while (i <= m)
        nextInRight[k++] = query[i++];
    while (j <= r)
        nextInRight[k++] = query[j++];
    for (LL i = l; i <= r; i++)
        query[i] = nextInRight[i];
}

void Merge_sort(LL l, LL r) {
    if (l < r) {
        LL m = (l + r) >> 1;
        Merge_sort(l, m);
        Merge_sort(m + 1, r);
        Merge(l, m, r);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LL n, x, y;
    while (cin >> n >> x >> y) {
        for (LL i = 0; i < n; i++) cin >> query[i];
        ans = 0;
        Merge_sort(0, n - 1);
        cout << ans * min(y, x) << endl;
    }
    return 0;
}