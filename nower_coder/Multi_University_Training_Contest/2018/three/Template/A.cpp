#include <bits/stdc++.h>

using namespace std;
const int MAXN = 37;
int n, p[MAXN], query[MAXN], c[MAXN], m[MAXN], g[MAXN];
int MOD, A, C, M;
short dp[MAXN][MAXN][MAXN][MAXN][MAXN];
bool path[MAXN][MAXN][MAXN][MAXN][MAXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i] >> query[i] >> c[i] >> m[i] >> g[i];
    cin >> MOD >> A >> C >> M;
    for (int i = 0; i <= n; i++)
        for (int ip = 0; ip <= MOD; ip++)
            for (int ia = 0; ia <= A; ia++)
                for (int ic = 0; ic <= C; ic++)
                    for (int im = 0; im <= M; im++)
                        path[i][ip][ia][ic][im] = false;
    for (int i = 0; i < n; i++) {
        for (int ip = MOD; ip >= 0; ip--)
            for (int ia = A; ia >= 0; ia--)
                for (int ic = C; ic >= 0; ic--)
                    for (int im = M; im >= 0; im--)
                        dp[i + 1][ip][ia][ic][im] = dp[i][ip][ia][ic][im];
        for (int ip = MOD; ip >= p[i]; ip--)
            for (int ia = A; ia >= query[i]; ia--)
                for (int ic = C; ic >= c[i]; ic--)
                    for (int im = M; im >= m[i]; im--)
                        if (dp[i][ip - p[i]][ia - query[i]][ic - c[i]][im - m[i]] + g[i] >
                            dp[i + 1][ip][ia][ic][im]) {
                            dp[i + 1][ip][ia][ic][im] = dp[i][ip - p[i]][ia - query[i]][ic - c[i]][im - m[i]] + g[i];
                            path[i + 1][ip][ia][ic][im] = true;
                        }
    }
    fprintf(stderr, "ans=%d\n", dp[n][MOD][A][C][M]);
    vector<int> ans;
    for (int i = n; i >= 1; i--)
        if (path[i][MOD][A][C][M]) {
            ans.push_back(i - 1);
            MOD -= p[i - 1];
            A -= query[i - 1];
            C -= c[i - 1];
            M -= m[i - 1];
        }
    reverse(ans.begin(), ans.end());
    printf("%d\n", (int) ans.size());
    for (size_t i = 0; i < ans.size(); i++)
        printf("%d%c", ans[i], " \n"[i + 1 == ans.size()]);
}
