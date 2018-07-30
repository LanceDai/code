#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    long long n;
    cin >> T;
    while (T--) {
        cin >> n;
        if (n % 3 == 0) cout << (n / 3) * (n / 3) * (n / 3) << endl;
        else if (n % 4 == 0) cout << (n / 2) * (n / 4) * (n / 4) << endl;
        else cout << -1 << endl;
    }
    return 0;
}