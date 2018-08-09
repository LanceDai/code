#include <bits/stdc++.h>

#define PI acos(-1)
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
//    freopen("", "r+", stdin);
//    freopen("", "w+", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, m, x, y, r, R;
    double sum, dis, sqrt_dis, ang1, ang2;
    cin >> T;
    while (T--) {
        cin >> m >> R;
        sum = 2 * PI * R;
        while (m--) {
            cin >> x >> y >> r;
            dis = x * x + y * y;
            sqrt_dis = sqrt(dis);
            if (sqrt_dis >= r + R || dis < (R - r) * (R - r))continue;
            ang1 = acos((R * R - r * r + dis) / (2 * R * sqrt_dis));
            ang2 = acos((-R * R + r * r + dis) / (2 * sqrt_dis * r));
            sum -= 2 * ang1 * R;
            sum += 2 * ang2 * r;
        }
        cout.setf(ios::fixed);
        cout << setprecision(20) << sum << endl;
    }
    return 0;
}