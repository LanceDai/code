#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 7;
int body[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("/home/lance/CLionProjects/code/nower_coder/Multi_University_Training_Contest/2018/six/input.txt", "r+",
            stdin);
//    freopen("data.out", "w+", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, n, m, k, a, b, c;
    LL ans;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> n >> m >> k;
        memset(body, 0 ,sizeof(body));
        while (k--) {
            cin >> a >> b >> c;
            body[b] = max(body[b], c);
        }
        ans = 0;
        for (int j = 1; j <= m; j++) ans += body[j];
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}


