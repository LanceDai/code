#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

const int N = 100;

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, n, x, y;
    string str;
    cin >> T;
    while (T--) {
        char arr[3][3];
        cin >> n;
        for (auto &i : arr)for (char &j : i)cin >> j;
        for (int i = 0; i < n; i++) {
            cin >> str;
            int m = str[0] - '0';
            if (m == 1) x = 0, y = 0;
            else if (m == 2) x = 0, y = 1;
            else if (m == 3) x = 1, y = 0;
            else x = 1, y = 1;
            swap(arr[x][y], arr[x][y + 1]);
            swap(arr[x + 1][y], arr[x + 1][y + 1]);
            if (str[1] == 'C') swap(arr[x + 1][y + 1], arr[x][y]);
            else swap(arr[x][y + 1], arr[x + 1][y]);
        }
        for (auto &i : arr) {
            for (char j : i) cout << j;
            cout << endl;
        }
    }
    return 0;
}