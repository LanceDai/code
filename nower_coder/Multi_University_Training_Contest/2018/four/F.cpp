#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
const int MAXN = 2005;
bool flag[MAXN][MAXN];
char char_map[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);//取消同步
    cin.tie(nullptr);//解除cin与cout的绑定，进一步加快执行效率。
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        memset(flag, 0, sizeof(flag));
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> char_map[i][j];
        for (int i = 1; i < n + 1; i++)
            for (int j = 1; j < m + 1; j++)
                if (char_map[i][j] == char_map[n + 1 - i][m + 1 - j] && !flag[i][j]) {
                    flag[i][j] = true;
                    flag[n + 1 - i][m + 1 - j] = true;
                }
        int mini = n / 2;
        int minj = m / 2;
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                if (!flag[i][j]) {
                    mini = min(i, mini);
                    minj = min(j, minj);
                }
            }
        }
        int ans = (mini - 1) * (minj - 1);
        cout << ans << endl;
    }
    return 0;
}