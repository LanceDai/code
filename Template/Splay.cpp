#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn = 5e5 + 7;
const int inf = 1e9 + 7;
int n, m, arr[maxn];

struct Splay_Tree {
    struct Node {
        int father, childs[2], key, cnt, _size, rev;

        inline void init() {
            father = childs[0] = childs[1] = key = cnt = _size = rev = 0;
        }

        inline void init(int father, int lchild, int rchild, int key, int cnt, int sz) {
            this->father = father, childs[0] = lchild, childs[1] = rchild;
            this->key = key, this->cnt = cnt, _size = sz;
            this->rev = 0;
        }
    } tre[maxn];

    int sign, root;

    inline void init() {
        sign = root = 0;
    }

    inline bool judge(int x) {
        return tre[tre[x].father].childs[1] == x;
    }

    inline void update(int x) {
        if (x) {
            tre[x]._size = tre[x].cnt;
            if (tre[x].childs[0]) {
                tre[x]._size += tre[tre[x].childs[0]]._size;
            }
            if (tre[x].childs[1]) {
                tre[x]._size += tre[tre[x].childs[1]]._size;
            }
        }
    }

    inline void rotate(int x) {
        int y = tre[x].father, z = tre[y].father, k = judge(x);
        pushdown(y), pushdown(x);
        //tre[y].childs[k] = tre[x].childs[!k], tre[ tre[x].childs[!k] ].father = y;
        //tre[x].childs[!k] = y, tre[y].father = x;
        //tre[z].childs[ tre[z].childs[1] == y ] = x, tre[x].father = z;
        if (k == 0) {///zig
            tre[y].childs[0] = tre[x].childs[1], tre[tre[x].childs[1]].father = y;
            tre[x].childs[1] = y, tre[y].father = x;
        } else {  ///zag
            tre[y].childs[1] = tre[x].childs[0], tre[tre[x].childs[0]].father = y;
            tre[x].childs[0] = y, tre[y].father = x;
        }
        tre[z].childs[tre[z].childs[1] == y] = x, tre[x].father = z;
        update(y);
    }

    inline void splay(int x, int goal) {
        for (int father; (father = tre[x].father) != goal; rotate(x)) {
            if (tre[father].father != goal) {
                rotate(judge(x) == judge(father) ? father : x);
            }
        }
        if (goal == 0) {
            root = x;
        }
    }

    inline void pushdown(int x) {
        if (x && tre[x].rev) {
            tre[tre[x].childs[0]].rev ^= 1;
            tre[tre[x].childs[1]].rev ^= 1;
            swap(tre[x].childs[0], tre[x].childs[1]);
            tre[x].rev = 0;
        }
    }

    int build(int l, int r, int fa) {
        if (l > r) {
            return 0;
        }
        int mid = (l + r) >> 1;
        int now = ++sign;
        tre[now].init(fa, 0, 0, arr[mid], 1, 1);
        tre[now].childs[0] = build(l, mid - 1, now);
        tre[now].childs[1] = build(mid + 1, r, now);
        update(now);
        return now;
    }

    int find(int x) {
        int now = root;
        while (1) {
            pushdown(now);
            if (x <= tre[tre[now].childs[0]]._size) {
                now = tre[now].childs[0];
            } else {
                x -= tre[tre[now].childs[0]]._size + 1;
                if (!x) {
                    return now;
                }
                now = tre[now].childs[1];
            }
        }
    }

    void reverse(int x, int y) {
        int L = x - 1, R = y + 1, pos;
        L = find(L), R = find(R);
        splay(L, 0);
        splay(R, L);
        pos = tre[root].childs[1];
        pos = tre[pos].childs[0];
        tre[pos].rev ^= 1;
    }

    inline void dfs(int now) {
        pushdown(now);
        if (tre[now].childs[0]) {
            dfs(tre[now].childs[0]);
        }
        if (tre[now].key != -inf && tre[now].key != inf) {
            printf("%d ", tre[now].key);
        }
        if (tre[now].childs[1]) {
            dfs(tre[now].childs[1]);
        }
    }

    void solve(int l, int r) {
        reverse(2, r);
        reverse(2, 2 + r - l);
        reverse(2 + r - l + 1, r);
    }
} S;

int main() {
    scanf("%d %d", &n, &m);
    S.init();
    arr[1] = -inf, arr[n + 2] = inf;
    for (int i = 1; i <= n; i++) {
        arr[i + 1] = i;
    }
    S.root = S.build(1, n + 2, 0);
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        int l = x, r = x + y - 1;
        l++, r++;
        S.solve(l, r);
    }
    S.dfs(S.root);
    return 0;
}