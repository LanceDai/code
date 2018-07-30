#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int MAXN = 100005;
struct{
    int to, id, next;
    bool isVisit;
} edges[MAXN * 16];
int total, cnt, head[MAXN], degree[MAXN];
bool vis[MAXN];
vector<int> res[MAXN];

void AddEdge(int u, int v, int id) {
    edges[total].isVisit = false;
    edges[total].to = v;
    edges[total].id = id;
    //从u出发，上一条边的序号
    edges[total].next = head[u];
    head[u] = total++;
}

void dfs(int u) {
    vis[u] = true;
    //从ｕ的最后一条边开始遍历，直到ｕ的第一条边
    for (int i = head[u]; i != -1; i = edges[i].next) {
        int v = edges[i].to, id = edges[i].id;
        if (!edges[i].isVisit) {
            edges[i].isVisit = edges[i ^ 1].isVisit = true;       //将边和反向边标记
            dfs(v);
            if (id) res[cnt].push_back(-id);     //退栈记录边的id
            else cnt++;                         //扫到虚边，那么路径加1
        }
    }
}

int main() {
//#ifndef ONLINE_JUDGE
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, u, v;
    while (cin >> N >> M) {
        total = cnt = 0;
        memset(degree, 0, sizeof(degree));
        memset(vis, 0, sizeof(vis));
        memset(head, -1, sizeof(head));
        for (int i = 1; i <= M; ++i) {
            cin >> u >> v;
            //相应端点的度数加一
            degree[u]++, degree[v]++;
            AddEdge(u, v, i);
            AddEdge(v, u, -i);
        }
        u = 0;
        for (int i = 1; i <= N; ++i) {
            //如果端点的度数是奇数
            if (degree[i] % 2) {
                //将奇度数点两两连边
                if (u) {
                    AddEdge(u, i, 0);
                    AddEdge(i, u, 0);
                    u = 0;
                } else u = i;
            }
        }
        for (int i = 1; i <= N; ++i) {
            //如果当前点没有被访问过，同时是奇度数点，那么开始ｄｆｓ
            if (!vis[i] && (degree[i] % 2)) {
                cnt++;
                dfs(i);
                cnt--;
            }
        }
        for (int i = 1; i <= N; ++i) {
            if (!vis[i] && degree[i]) {
                cnt++;
                dfs(i);
            }
        }
        cout << cnt << '\n';
        for (int i = 1; i <= cnt; ++i) {
            cout << res[i].size();
            for (int j : res[i])
                cout << ' ' << j;
            cout << '\n';
            res[i].clear();
        }
    }
    return 0;
}