#include<bits/stdc++.h>

using namespace std;
int N[20][300030], ans = 0;

void dfs(int opt, int c) {
    int len = 1 << c;
    //记录零出现的个数
    int sum_0 = 0;
    for (int i = 0; i < len; i++) {
        switch (opt) {
            case 0:
                N[c][i] = N[c + 1][i << 1] ^ N[c + 1][i << 1 | 1];
                break;
            case 1:
                N[c][i] = N[c + 1][i << 1] & N[c + 1][i << 1 | 1];
                break;
            case 2:
                N[c][i] = N[c + 1][i << 1] | N[c + 1][i << 1 | 1];
                break;
            default:
                break;
        }
        if (!N[c][i]) sum_0++;
    }
    //剪枝，如果剩下都为零，那么无论怎么操作都不会出现1了，可以直接return
    if (sum_0 == len) return;
    if (len == 1) {
        ans += N[c][0];
        return;
    }
    dfs(0, c - 1);
    dfs(1, c - 1);
    dfs(2, c - 1);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen(R"(D:\ACM\CLionProject\code\nower_coder\Multi_University_Training_Contest\2018\seven\input.txt)", "r",
            stdin);
//    freopen("data.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string str;
    cin >> n >> str;
    for (int i = 0; i < (1 << n); ++i) N[n][i] = str[i] - '0';
    dfs(0, n - 1);
    dfs(1, n - 1);
    dfs(2, n - 1);
    cout << ans << endl;
    return 0;
}