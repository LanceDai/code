#include <iostream>
#include <cstring>

using namespace std;
typedef long long LL;
const int MAXN = 100005;
const LL mod = 1000000007;
LL dp[MAXN][2];
LL sum[MAXN];

int main() {
    LL Q, K, l, r;
    cin >> Q >> K;
    //dp[i][0/1]代表最后一次是以跑步还是走路结尾
    dp[0][0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        //在i米处以走路结尾的最大次数等于前一米以走路结尾的次数加上以跑步结尾的次数
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][0]) % mod;
        if (i >= K) {
            //如果i大于k，证明存在跑步次数
            //因为不能连续跑步，以跑步结尾的次数等于第i-k处以走路结尾的次数
            dp[i][1] = dp[i - K][0];
        }
        //记录前缀和
        sum[i] = (sum[i - 1] + dp[i][0] + dp[i][1]) % mod;
    }
    for (int i = 0; i < Q; i++) {
        cin >> l >> r;
        cout << (sum[r] - sum[l - 1] + mod) % mod << endl;
    }
    return 0;
}