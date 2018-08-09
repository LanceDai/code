#include <bits/stdc++.h>

using namespace std;
const double G = 9.8;

int main() {
#ifndef ONLINE_JUDGE
//    freopen("/home/lance/CLionProjects/code/HDUOJ/Multi-University_Training_Contest/2018/6/input.txt", "r", stdin);
    freopen("/home/lance/Documents/Tencent Files/603842325/FileRecv/hdu-multi6-fzdx/data/1012/in", "r", stdin);
    freopen("/home/lance/Documents/Tencent Files/603842325/FileRecv/hdu-multi6-fzdx/data/out.out", "w", stdout);
#endif
    int T, ans;
    double a, b, x, y, ang, h, vx, vy, ax, ay, tmp_t_y, tmp_t_x, sum;
    cin >> T;
    while (T--) {
        cin >> a >> b >> x >> y;
        x = -x;
        ang = atan(b / a);
        h = y - b / a * x;
        ax = G * sin(ang);
        ay = G * cos(ang);
        vx = sqrt(2 * G * h) * sin(ang);
        vy = sqrt(2 * G * h) * cos(ang);
        sum = x / cos(ang);
        tmp_t_y = vy / ay * 2;
        tmp_t_x = (-vx + sqrt(vx * vx + 2 * ax * sum)) / ax;
        ans = int(tmp_t_x / tmp_t_y);
        cout << ans + 1 << endl;
    }
    return 0;
}