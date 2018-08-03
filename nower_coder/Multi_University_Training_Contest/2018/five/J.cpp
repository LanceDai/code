#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    LL n, p2, p3, ans = INT_MAX;
    cin >> n >> p2 >> p3;
    for (LL i = 0; i <= 2; i++) {
        for (LL j = 0; j <= 1; j++) {
            LL x = i * 2 + j * 3;
            LL c = i * p2 + j * p3;
            if (x > n)continue;
            ans = min(ans, c + (n - x + 1) / 2 * p2);
            ans = min(ans, c + (n - x + 2) / 3 * p3);
        }
    }
    cout << ans << endl;
    return 0;
}