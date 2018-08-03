#include <bits/stdc++.h>

int MOD;

void update(int& x, int a)
{
    x += a;
    if (x >= MOD) {
        x -= MOD;
    }
}

int main()
{
    int n;
    while (scanf("%d%d", &n, &MOD) == 2) {
        std::vector<int> dp(n + 1);
        dp[0] = 1;
        int sum = 0;
        for (int i = 1; i <= n; ++ i) {
            dp[i] = dp[i - 2] * (i - 1LL) % MOD;
            sum = sum * (i - 1LL) % MOD;
            if (i >= 3) {
                update(sum, (i - 1LL) * (i - 2) / 2 % MOD * dp[i - 3] % MOD);
            }
            update(dp[i], sum);
        }
        printf("%d\n", dp[n]);
    }
}
