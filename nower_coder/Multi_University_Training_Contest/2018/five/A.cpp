#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 1e5 + 5;
typedef long long LL;
LL n, k, s[MAXN], c[MAXN];
double y[MAXN];

bool check(double x) {
    for (int i = 0; i < n; ++i) y[i] = s[i] * c[i] - x * s[i];
    sort(y, y + n);
    double sum = 0;
    for (int i = k; i < n; ++i) sum += y[i];
    return sum >= 0;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("/home/lance/CLionProjects/code/nower_coder/Multi_University_Training_Contest/2018/five/input.txt", "r+",
            stdin);
//    freopen("data.out", "w+", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < n; ++i) cin >> c[i];
    double start = 0, end = INF, mid;
    for (int i = 0; i < 100; ++i) {
        mid = (start + end) / 2;
        if (check(mid)) start = mid;
        else end = mid;
    }
    cout.setf(ios::fixed);
    cout << setprecision(6) << end << endl;
    return 0;
}