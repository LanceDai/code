#include<bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long LL;

int main() {
#ifndef ONLINE_JUDGE
    freopen("/home/lance/CLionProjects/code/HDUOJ/Multi-University_Training_Contest/2018/4/input.txt", "r+", stdin);
//    freopen("data.out", "w+", stdout);
#endif
    IO;
    LL t;
    cin >> t;
    while (t--) {
        LL n, m, x, sum = 1, cnt = 0, b[105];
        cin >> n >> m;
        for (LL i = 0; i < n; i++) cin >> x >> b[i];
        sort(b, b + n);
        for (int i = 0; i < n; i++) {
            sum *= (1 + b[i]);
            if (sum <= m) cnt++;
            else break;
        }
        cout << cnt << endl;
    }
    return 0;
}
