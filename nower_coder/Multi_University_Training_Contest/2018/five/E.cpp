#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
const int MAXN = 111;
const int INF = 0x3f3f3f3f;
int old_status[MAXN][5], new_status[MAXN][5];

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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n) {
        //输入原寝室分配情况
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= 4; j++)
                cin >> old_status[i][j];
        //输入现寝室分配情况
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= 4; j++)
                cin >> new_status[i][j];
        km.init(n, n, n);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int cnt = 0;
                for (int k = 1; k <= 4; k++) {
                    for (int l = 1; l <= 4; l++) {
                        if (old_status[i][k] == new_status[j][l]) {
                            cnt++;
                            break;
                        }
                    }
                }
                km.mp[i][j] = cnt;
            }
        }
        cout << (4 * n - km.solve()) << endl;
    }
    return 0;
}
