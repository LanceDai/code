#include<bits/stdc++.h>
#include<cmath>

#define mem(a, b) memset(a,b,sizeof a);
#define INF 0x3f3f3f3f

using namespace std;

typedef long long LL;
typedef unsigned long long ull;

const int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};

int n;
ull rs;
int vis[20][20];

void dfs(int x, int y) {
    if (x == 0 || y == 0 || x == n || y == n) {
        rs++;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int dx = x + dir[i][0], dy = y + dir[i][1];
        if (dx < 0 || dy < 0 || dx > n || dy > n) continue;
        if (!vis[dx][dy]) {
            vis[dx][dy] = vis[n - dx][n - dy] = 1;
            dfs(dx, dy);
            vis[dx][dy] = vis[n - dx][n - dy] = 0;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("/home/lance/CLionProjects/code/HDUOJ/Multi-University_Training_Contest/2018/4/input.txt", "r+", stdin);
    freopen("/home/lance/CLionProjects/code/output.txt", "w+", stdout);
#endif
    ClOCK_c
    while (~scanf("%d", &n)) {
        if (n % 2 == 1) {
            puts("1");
            continue;
        }
        //if (n == 10) { puts("562070107"); continue; } // 暴力出来
        mem(vis, 0);
        rs = 0;
        int dx = n / 2, dy = n / 2;
        vis[dx][dy] = vis[n - dx][n - dy] = 1;
        dfs(n / 2, n / 2);
        vis[dx][dy] = vis[n - dx][n - dy] = 0;
        cout << rs / 4 << endl; // 因为有四个象限会重复
    }

    return 0;
}
