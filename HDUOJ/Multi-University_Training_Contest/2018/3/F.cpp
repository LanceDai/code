#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main() {
#ifndef ONLINE_JUDGE
    freopen("/home/lance/Documents/Tencent Files/603842325/FileRecv/2018HDUContest/F/F.in", "r+", stdin);
    freopen("/home/lance/CLionProjects/code/HDUOJ/Multi-University_Training_Contest/2018/3/output.txt", "w+", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, n, sum, x, y;
    cin >> T;
    while (T--) {
        cin >> n;
        sum = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> x;
            sum ^= x;
        }
        for (int i = 1; i < n; ++i) cin >> x >> y;
        cout << (sum ? 'Q' : 'D') << endl;
    }
    return 0;
}