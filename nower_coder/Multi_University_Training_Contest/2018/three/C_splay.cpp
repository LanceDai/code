#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int MAXN = 5e5 + 7;
const int INF = 1e9 + 7;
int n, m, arr[MAXN];

struct Splay_Tree {
    struct Node {
        int father, children[2], key, cnt, _size, rev;

        inline void init() {
            father = children[0] = children[1] = key = cnt = _size = rev = 0;
        }

        inline void init(int father, int lSon, int rSon, int key, int cnt, int sz) {
            this->father = father, children[0] = lSon, children[1] = rSon;
            this->key = key, this->cnt = cnt, _size = sz;
            this->rev = 0;
        }
    } tre[MAXN];

    int sign = 0, root = 0;

    inline bool judge(int x) {
        return tre[tre[x].father].children[1] == x;
    }

    inline void update(int x) {
        if (x) {
            tre[x]._size = tre[x].cnt;
            if (tre[x].children[0]) tre[x]._size += tre[tre[x].children[0]]._size;
            if (tre[x].children[1]) tre[x]._size += tre[tre[x].children[1]]._size;
        }
    }

    inline void rotate(int x) {
        int y = tre[x].father, z = tre[y].father, k = judge(x);
        pushDown(y), pushDown(x);
        if (k == 0) {///zig
            tre[y].children[0] = tre[x].children[1], tre[tre[x].children[1]].father = y;
            tre[x].children[1] = y, tre[y].father = x;
        } else {  ///zag
            tre[y].children[1] = tre[x].children[0], tre[tre[x].children[0]].father = y;
            tre[x].children[0] = y, tre[y].father = x;
        }
        tre[z].children[tre[z].children[1] == y] = x, tre[x].father = z;
        update(y);
    }

    inline void splay(int x, int goal) {
        for (int father; (father = tre[x].father) != goal; rotate(x))
            if (tre[father].father != goal) rotate(judge(x) == judge(father) ? father : x);
        if (goal == 0) root = x;
    }

    inline void pushDown(int x) {
        if (x && tre[x].rev) {
            tre[tre[x].children[0]].rev ^= 1;
            tre[tre[x].children[1]].rev ^= 1;
            swap(tre[x].children[0], tre[x].children[1]);
            tre[x].rev = 0;
        }
    }

    int build(int l, int r, int father) {
        if (l > r) return 0;
        int mid = (l + r) >> 1;
        int now = ++sign;
        tre[now].init(father, 0, 0, arr[mid], 1, 1);
        tre[now].children[0] = build(l, mid - 1, now);
        tre[now].children[1] = build(mid + 1, r, now);
        update(now);
        return now;
    }

    int find(int x) {
        int now = root;
        while (true) {
            pushDown(now);
            if (x <= tre[tre[now].children[0]]._size) now = tre[now].children[0];
            else {
                x -= tre[tre[now].children[0]]._size + 1;
                if (!x) return now;
                now = tre[now].children[1];
            }
        }
    }

    void reverse(int x, int y) {
        int L = x - 1, R = y + 1, pos;
        L = find(L), R = find(R);
        splay(L, 0);
        splay(R, L);
        pos = tre[root].children[1];
        pos = tre[pos].children[0];
        tre[pos].rev ^= 1;
    }

    inline void dfs(int now) {
        pushDown(now);
        if (tre[now].children[0]) dfs(tre[now].children[0]);
        if (tre[now].key != -INF && tre[now].key != INF) cout << tre[now].key << ' ';
        if (tre[now].children[1]) dfs(tre[now].children[1]);
    }

    void solve(int l, int r) {
        reverse(2, r);
        reverse(2, 2 + r - l);
        reverse(2 + r - l + 1, r);
    }
} S;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    //防止越界
    arr[1] = -INF, arr[n + 2] = INF;
    for (int i = 1; i <= n; i++) arr[i + 1] = i;
    S.root = S.build(1, n + 2, 0);
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        S.solve(x + 1, x + y);
    }
    S.dfs(S.root);
    return 0;
}