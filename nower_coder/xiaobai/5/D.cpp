#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

inline LL gs(LL n, LL c) {
    LL a = (n / c) - 1;
    LL b = a * (a + 1) / 2 * c;
    return b + (n % c + 1LL) * (a + 1LL);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LL n, k = 5LL, ans = 0;
    cin >> n;
    while (n / k) {
        ans += gs(n, k);
        cout << "ans = " << ans << endl;
        k *= 5LL;
    }
    cout << ans << endl;
    return 0;
}