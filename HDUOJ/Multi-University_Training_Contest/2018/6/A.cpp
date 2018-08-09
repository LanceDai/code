#include <bits/stdc++.h>

#define PI acos(-1)
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
//    freopen("/home/lance/CLionProjects/code/HDUOJ/Multi-University_Training_Contest/2018/6/input.txt", "r", stdin);
    freopen("/home/lance/Documents/Tencent Files/603842325/FileRecv/hdu-multi6-fzdx/data/1001/in", "r", stdin);
    freopen("/home/lance/Documents/Tencent Files/603842325/FileRecv/hdu-multi6-fzdx/data/out.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long T, a, b, ans;
    cin >> T;
    while (T--) {
        cin >> a >> b;
        ans = static_cast<long long int>((PI * a + 2 * b) * 1e6);
        cout << fixed << setprecision(6) << (ans / 1e6) << endl;
    }
    return 0;
}