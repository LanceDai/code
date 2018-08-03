#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e7 + 9;
typedef long long LL;
int a[MAXN], dq[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("/home/lance/CLionProjects/code/HDUOJ/Multi-University_Training_Contest/2018/3/input.txt", "r+", stdin);
    freopen("/home/lance/CLionProjects/code/HDUOJ/Multi-University_Training_Contest/2018/3/output.txt", "w+", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, n, m, k, p, q, r, MOD, head, tail, i;
    LL A, B;
    cin >> T;
    while (T--) {
        cin >> n >> m >> k >> p >> q >> r >> MOD;
        for (i = 1; i <= k; ++i) cin >> a[i];
        //取模运算耗时长
        for (i = k + 1; i <= n; ++i) a[i] = (1LL * p * a[i - 1] + 1LL * q * i + r) % MOD;
//        deque<int> dq;
        A = B = tail = 0;
        head = 1;
        for (i = n; i; --i) {
            //如果队列尾部的值小于当前值，将尾部值弹出
            while (head <= tail && a[dq[tail]] <= a[i]) tail--;
            //将当前值插入队列
            dq[++tail] = i;
            //如果队首的值的位置超出了窗口范围，弹出
            while (head <= tail && dq[head] - i + 1 > m) head++;
            //如果滑动过的距离大于窗口大小，开始计算答案
            if (i + m - 1 <= n) {
                A += a[dq[head]] ^ i;
                B += (tail - head + 1) ^ i;
            }
        }
        cout << A << ' ' << B << endl;
    }
    return 0;
}
