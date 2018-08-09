#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
const int MAXN = 105;
const int INF = 0x3f3f3f3f;
int n, min_num, link_val[MAXN][MAXN],
        x_sign[MAXN], y_sign[MAXN], link_y[MAXN];
bool vis_x[MAXN], vis_y[MAXN];

//匈牙利算法找增广路径
bool dfs(int s) {
    vis_x[s] = true;
    for (int i = 1; i <= n; i++) {
        if (!vis_y[i]) {
            int t = x_sign[s] + y_sign[i] - link_val[s][i];
            if (t == 0) {
                vis_y[i] = true;
                if (link_y[i] == 0 || dfs(link_y[i])) {
                    link_y[i] = s;
                    return true;
                }
            } else if (t > 0 && t < min_num)  //找出边权与顶标和的最小的差值
                min_num = t;
        }
    }
    return false;
}

int km() {
    //link_y[i]表示与X部中点i匹配的点
    memset(link_y, 0, sizeof(link_y));
    for (int i = 1; i <= n; i++) {
        while (true) {
            min_num = INF;
            memset(vis_x, 0, sizeof(vis_x));
            memset(vis_y, 0, sizeof(vis_y));
            //找到增广路径，匹配数加一，没找到，修改顶标，再次寻找
            if (dfs(i))break;
            //将交错树中X部的点的顶标减去min_num,将交错树中Y部的点的顶标加上min_num
            for (int j = 1; j <= n; j++) {
                if (vis_x[j])x_sign[j] -= min_num;
                if (vis_y[j])y_sign[j] += min_num;
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; ++i) sum += link_val[link_y[i]][i];
    return sum;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("/home/lance/CLionProjects/code/nower_coder/Multi_University_Training_Contest/2018/five/input.txt", "r+",
            stdin);
//    freopen("data.out", "w+", stdout);
#endif
    int old_status[MAXN][5], new_status[MAXN][5];
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    memset(x_sign, 0, sizeof(x_sign));
    memset(y_sign, 0, sizeof(y_sign));
    //输入原寝室分配情况
    for (int i = 1; i <= n; i++) for (int j = 1; j <= 4; j++) cin >> old_status[i][j];
    //输入现寝室分配情况
    for (int i = 1; i <= n; i++) for (int j = 1; j <= 4; j++) cin >> new_status[i][j];
    //计算权重，权重为原寝室情况与现寝室情况相同人的数量
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            set<int> s;
            for (int k = 1; k <= 4; ++k) {
                s.insert(old_status[i][k]);
                s.insert(new_status[j][k]);
            }
            link_val[i][j] = int(8 - s.size());
            x_sign[i] = max(x_sign[i], link_val[i][j]);
        }
    }
    cout << 4 * n - km() << endl;
    return 0;
}
