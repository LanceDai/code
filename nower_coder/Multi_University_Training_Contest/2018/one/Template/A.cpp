#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

const int MAXN = 1005;

int dp[MAXN][MAXN];

void update(int& x, int a)
{
    x += a;
    if (x >= MOD) {
        x -= MOD;
    }
}

int sqr(int x)
{
    return 1LL * x * x % MOD;
}

int main()
{
    dp[0][0] = 1;
    for (int i = 0; i < MAXN; ++ i) {
        for (int j = 0; j < MAXN; ++ j) {
            if (i) {
                update(dp[i][j], dp[i - 1][j]);
            }
            if (j) {
                update(dp[i][j], dp[i][j - 1]);
            }
        }
    }
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        printf("%d\n", static_cast<int>((sqr(dp[n][m]) + MOD - 1LL * dp[n - 1][m + 1] * dp[n + 1][m - 1] % MOD) % MOD));
    }
}
