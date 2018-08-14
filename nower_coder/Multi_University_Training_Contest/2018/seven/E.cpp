#include <bits/stdc++.h>

using namespace std;
const int MAXN = 105;
int C4[MAXN], C3[MAXN];

void init() {
    C3[3] = 1;
    for (int i = 4; i <= MAXN; ++i) {
        C4[i] = i * (i - 1) * (i - 2) * (i - 3) / 24;
        C3[i] = i * (i - 1) * (i - 2) / 6;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen(R"(D:\ACM\CLionProject\code\nower_coder\Multi_University_Training_Contest\2018\seven\input.txt)", "r",
            stdin);
//    freopen("data.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(C3, 0, sizeof(C3));
    memset(C4, 0, sizeof(C4));
    init();
    int k, num, num_a, num_b, num_c, num_d, num_e, flag = 1;
    num_a = num_b = num_c = num_d = num_e = 0;
    cin >> k;
    num = min(int(upper_bound(C4, C4 + 100, k) - C4 - 1), 70);
    for (int a = 2; a <= num && flag; ++a) {
        for (int b = a; b <= num && flag; ++b) {
            for (int c = b; c <= num && flag; ++c) {
                for (int d = c; d <= num && flag; ++d) {
                    int tmp = k - C4[num] - C3[a] - C3[b] - C3[c] - C3[d];
                    if (tmp == *lower_bound(C3, C3 + 100, tmp) && int(lower_bound(C3, C3 + 100, tmp) - C3) <= num) {
                        num_a = a;
                        num_b = b;
                        num_c = c;
                        num_d = d;
                        num_e = int(lower_bound(C3, C3 + 100, tmp) - C3);
                        flag = 0;
                    }
                }
            }
        }
    }
    cout << num + (num_a != 0) + (num_b != 0) + (num_c != 0) + (num_d != 0) + (num_e != 0) << ' '
         << num * (num - 1) / 2 + num_a + num_b + num_c + num_d + num_e << endl;
    for (int i = 1; i <= num; ++i)for (int j = i + 1; j <= num; ++j)cout << i << ' ' << j << endl;
    for (int i = 1; i <= num_a; ++i) cout << num + 1 << ' ' << i << endl;
    for (int i = 1; i <= num_b; ++i) cout << num + 2 << ' ' << i << endl;
    for (int i = 1; i <= num_c; ++i) cout << num + 3 << ' ' << i << endl;
    for (int i = 1; i <= num_d; ++i) cout << num + 4 << ' ' << i << endl;
    for (int i = 1; i <= num_e; ++i) cout << num + 5 << ' ' << i << endl;
    return 0;
}