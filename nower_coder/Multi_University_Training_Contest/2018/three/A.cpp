#include <bits/stdc++.h>

using namespace std;
struct {
    short p, a, c, m, k;
} group[100];
short dp[37][37][37][37];
bool path[37][37][37][37][37];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, P, A, C, M;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> group[i].p >> group[i].a >> group[i].c >> group[i].m >> group[i].k;
    cin >> P >> A >> C >> M;
    memset(path, 0, sizeof(path));
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= N; i++) {
        for (int j = P; j >= 0; j--) {
            for (int k = A; k >= 0; k--) {
                for (int x = C; x >= 0; x--) {
                    for (int y = M; y >= 0; y--) {
                        int a1 = j - group[i].p, a2 = k - group[i].a;
                        int a3 = x - group[i].c, a4 = y - group[i].m;
                        if (a1 >= 0 && a2 >= 0 && a3 >= 0 && a4 >= 0) {
                            short yy = dp[a1][a2][a3][a4];
                            if (dp[j][k][x][y] < yy + group[i].k) {
                                dp[j][k][x][y] = yy + group[i].k;
                                path[i][j][k][x][y] = true;
                            }
                        }
                    }
                }
            }
        }
    }
    vector<int> ans;
    int a1 = P, a2 = A, a3 = C, a4 = M;
    for (int i = N; i >= 1; i--) {
        if (path[i][a1][a2][a3][a4]) {
            ans.push_back(i - 1);
            a1 -= group[i].p;
            a2 -= group[i].a;
            a3 -= group[i].c;
            a4 -= group[i].m;
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        (i < ans.size() - 1) ? cout << ans[i] << " " : cout << ans[i] << endl;
    return 0;
}