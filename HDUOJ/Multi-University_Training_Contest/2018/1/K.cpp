#include <bits/stdc++.h>

#define eps 1e-10
using namespace std;

int main() {
    double d;
    int t, h, m, c, sign;
    char s[20];
    cin >> t;
    while (t--) {
        scanf("%d%d%s", &h, &m, s);
        h = h * 60 + m;
        sign = s[3] == '+' ? 1 : -1;
        sscanf(s + 4, "%lf", &d);
        c = (int) (d * 60 + eps);//注意浮点误差
        c = sign * c - 8 * 60;
        h += c;
        h %= (24 * 60);
        if (h < 0) h += 24 * 60;
        printf("%02d:%02d\n", h / 60, h % 60);
    }
    return 0;
}