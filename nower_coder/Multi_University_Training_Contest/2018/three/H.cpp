#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> p(n + 2ULL);
    vector<bool> np(n + 2ULL);
    //素数筛
    for (int i = 2; i <= n; i++){
        if (!np[i]) {
            p[i] = 1;
            for (int j = i; j <= n; j += i) np[j] = true;
        }
    }
    //素数个数前缀和
    for (int i = 1; i <= n; i++) p[i] += p[i - 1];
    long long ans = 0;
    //在n的范围内，能达到i倍的素数个数有p[n / i]个，其中取两个进行组合，加入答案
    for (int i = 1; i <= n; i++) ans += (long long) p[n / i] * (p[n / i] - 1);
    cout << ans << endl;
    return 0;
}
