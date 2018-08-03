#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main() {
    LL c, n;
    cin >> c >> n;
    if (c > n)cout << -1 << endl;
    else if (n < 2 * c) cout << c * c << endl;
    else cout << ((n / c) * c * (n / c - 1) * c) << endl;
    return 0;
}