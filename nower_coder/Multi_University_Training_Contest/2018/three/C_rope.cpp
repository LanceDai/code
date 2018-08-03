#include <bits/stdc++.h>
#include <ext/rope>

using namespace std;
using namespace __gnu_cxx;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, l, r;
    cin >> n >> m;
    rope<int> T;
    //初始化
    for (int i = 1; i <= n; ++i) T.push_back(i);
    while (m--) {
        cin >> l >> r;
        T = T.substr(l - 1, r) + T.substr(0, l - 1) + T.substr(l - 1 + r, n - r - l + 1);
    }
    //输出
    for (int i = 0; i < T.size(); ++i) {
        (i < T.size() - 1) ? cout << T.at(i) << ' ' : cout << T.at(i) << endl;
    }
    return 0;
}