#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const LL N = 100005;
LL a[N], tmp[N], ans;

void Merge(LL l, LL m, LL r) {
    LL i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        if (a[i] > a[j]) {
            tmp[k++] = a[j++];
            ans += m - i + 1;
        } else
            tmp[k++] = a[i++];
    }
    while (i <= m)
        tmp[k++] = a[i++];
    while (j <= r)
        tmp[k++] = a[j++];
    for (LL i = l; i <= r; i++)
        a[i] = tmp[i];
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
        for (LL i = 0; i < n; i++) cin >> a[i];
        ans = 0;
        Merge_sort(0, n - 1);
        cout << ans * min(y, x) << endl;
    }
    return 0;
}