#include<bits/stdc++.h>
//https://blog.csdn.net/my_sunshine26/article/details/81635187
using namespace std;
typedef long long LL;
const int MAXN = 1e6 + 5;
LL phi[MAXN], inv[MAXN], Mobius[MAXN], Gu[MAXN], n, m, p;

void getEuler() {
    //欧拉函数值
    memset(phi, 0, sizeof(phi));
    phi[1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        if (!phi[i]) {
            for (int j = i; j < MAXN; j += i) {
                if (!phi[j]) phi[j] = j;
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
    //莫比乌斯μ数组
    Mobius[1] = 1;
    for (int i = 1; i < MAXN; ++i)
        for (int j = 2 * i; j < MAXN; j += i) Mobius[j] -= Mobius[i];
}


void init() {
    inv[1] = 1;
    for (int i = 2; i <= n; ++i) inv[i] = inv[p % i] * (p - p / i) % p;
    for (int i = 1; i <= n; ++i) Gu[i] = i * inv[phi[i]] % p;
}

LL g(int n, int m) {
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += Mobius[i] * (n / i) * (m / i);
        ans %= p;
    }
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("/home/lance/CLionProjects/code/HDUOJ/Multi-University_Training_Contest/2018/7/input.txt", "r", stdin);
//    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\out)", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    getEuler();
    while (T--) {
        LL ans = 0;
        cin >> m >> n >> p;
        if(n > m) swap(n, m);
        init();
        for (int i = 1; i <= n; ++i) {
            ans += Gu[i] * g(n / i, m / i) % p;
            ans %= p;
        }
        cout << ans << endl;
    }
    return 0;
}
