#include <bits/stdc++.h>

typedef long long LL;
using namespace std;

inline LL Rand() {
    return (1LL * rand() << 15) + rand();
}

int main() {
    int n, m, k;
    srand(233);
    cin >> n >> m >> k;
    vector<LL> r(n * m + 1ULL);
    vector<vector<LL>> a(n + 2ULL, vector<LL>(m + 2ULL));
    vector<vector<int>> b(n + 2ULL, vector<int>(m + 2ULL));
    for (int i = 1; i <= n * m; i++) {
        r[i] = Rand();
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> b[i][j];
        }
    }

    //通过差分矩阵，进行快速的区间更新
    for (int i = 1; i <= k; i++) {
        int x1, x2, y1, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        a[x1][y1] += r[c];
        a[x2 + 1][y1] -= r[c];
        a[x1][y2 + 1] -= r[c];
        a[x2 + 1][y2 + 1] += r[c];
    }
    //查封求和得到单点值
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }
    int ans = 0;
    //如果单点的值是原来的值的倍数，那么说明所加的肥料是对的，不然ans加一
    //随机化防止多次不同的值加起来成为原来值的倍数
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            //如果没有被进行过操作，那么单点值是0
            //如果进行过操作，那么正确的话所加的也是r[b[i][j]], 所以结果是倍数
            if (a[i][j] % r[b[i][j]] != 0)ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}