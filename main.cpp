#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 111;


//带权二分图最大匹配
struct KM {
    int link[MAXN], lx[MAXN], ly[MAXN], stacks[MAXN]; //lx,ly为顶标，nx,ny分别为x点集y点集的个数
    int mp[MAXN][MAXN], ny, nx, n;
    bool visx[MAXN], visy[MAXN];

    void init(int _nx, int _ny, int _n) {
        nx = _nx, ny = _ny, n = _n;
    }

    bool dfs(int x) {
        visx[x] = true;
        for (int i = 1; i <= ny; i++) {
            if (visy[i]) continue;
            int tmp = lx[x] + ly[i] - mp[x][i];
            if (tmp == 0) {
                visy[i] = true;
                if (link[i] == -1 || dfs(link[i])) {
                    link[i] = x;
                    return true;
                }
            } else if (stacks[i] > tmp) stacks[i] = tmp;
        }
        return false;
    }

    int solve() {
        memset(link, -1, sizeof(link));
        memset(ly, 0, sizeof(ly));
        int i, j;
        for (i = 1; i <= nx; i++)
            for (j = 1, lx[i] = -INF; j <= ny; j++)
                if (mp[i][j] > lx[i])
                    lx[i] = mp[i][j];
        for (i = 1; i <= nx; i++) {
            for (j = 1; j <= ny; j++)
                stacks[j] = INF;
            while (true) {
                memset(visx, 0, sizeof(visx));
                memset(visy, 0, sizeof(visy));
                if (dfs(i)) break;
                int d = INF;
                for (j = 1; j <= ny; j++)
                    if (!visy[j] && d > stacks[j])
                        d = stacks[j];
                for (j = 1; j <= nx; j++)
                    if (visx[j])
                        lx[j] -= d;
                for (j = 1; j <= ny; j++) {
                    if (visy[j]) ly[j] += d;
                    else stacks[j] -= d;
                }
            }
        }
        int ans = 0;
        for (i = 1; i <= ny; i++)
            if (link[i] != -1)
                ans += mp[link[i]][i];
        return ans;
    }
} km;

int main() {
    freopen("/home/lance/CLionProjects/code/output.txt", "w", stdout);
    int n;
    for (int n = 2; n <= 16; ++n) {
        km.init(n, n, n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                km.mp[i + 1][j + 1] = -(i & j);
                printf("%3d ", (i & j));
//                cout << (i & j) << ' ';
            }
            cout << endl;
        }
        cout << "n = " << n << " ans = " << km.solve() << endl;
        for (int i = 1; i <= km.ny; i++)
            if (km.link[i] != -1)
                cout << km.link[i] - 1 << ' ';
        cout << endl;
    }

    return 0;
}