#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define MAXN 100005
#define lowBit(x) x&(-x)
using namespace std;
typedef struct {
    int val;
    int index;
    int addMark;
} Node;
int n, q, l, r;
int b[MAXN];
Node b2[MAXN * 4];
int c[MAXN];

/**
 * 功能：构建线段树
 * @param root 当前线段树的根节点下标
 * @param iStart 数组的起始位置
 * @param iEnd 数组的结束位置
 */
void build(int root, int iStart, int iEnd) {
    //----设置延迟标记域
    b2[root].addMark = 0;
    //叶子节点
    if (iStart == iEnd) {
        b2[root].val = b[iStart];
        b2[root].index = iStart;
    } else {
        int mid = (iStart + iEnd) / 2;
        build(root * 2, iStart, mid);//递归构造左子树
        build(root * 2 + 1, mid + 1, iEnd);//递归构造右子树
        //根据左右子树根节点的值，更新当前根节点的值
        if (b2[root * 2].val < b2[root * 2 + 1].val) {
            b2[root].val = b2[root * 2].val;
            b2[root].index = b2[root * 2].index;
        } else {
            b2[root].val = b2[root * 2 + 1].val;
            b2[root].index = b2[root * 2 + 1].index;
        }
    }
}

/**
 * 当前节点的标志域向孩子节点传递
 * @param root 当前线段树的根节点下标
 */
void pushDown(int root) {
    if (b2[root].addMark != 0) {
        //设置左右孩子节点的标志域，因为孩子节点可能被多次延迟标记又没有向下传递
        //所以是 “+=”
        b2[root * 2].addMark += b2[root].addMark;
        b2[root * 2 + 1].addMark += b2[root].addMark;
        //根据标志域设置孩子节点的值。因为我们是求区间最小值，
        // 因此当区间内每个元素加上一个值时，
        // 区间的最小值也加上这个值
        b2[root * 2].val += b2[root].addMark;
        b2[root * 2 + 1].val += b2[root].addMark;
        //传递后，当前节点标记域清空
        b2[root].addMark = 0;
    }
}

/**
 * 功能：线段树的区间查询
 * @param root 当前线段树的根节点下标
 * @param nStart 当前节点所表示的区间
 * @param nEnd 当前节点所表示的区间
 * @param qStart 此次查询的区间
 * @param qEnd 此次查询的区间
 * @return
 */
Node query(int root, int nStart, int nEnd, int qStart, int qEnd) {
    //查询区间和当前节点区间没有交集
    if (qStart > nEnd || qEnd < nStart)
        return Node{INF, INF, INF};
    //当前节点区间包含在查询区间内
    if (qStart <= nStart && qEnd >= nEnd)
        return b2[root];
    pushDown(root); //----延迟标志域向下传递
    //分别从左右子树查询，返回两者查询结果的较小值
    int mid = (nStart + nEnd) / 2;
    Node lSon = query(root * 2, nStart, mid, qStart, qEnd);
    Node rSon = query(root * 2 + 1, mid, nEnd, qStart, qEnd);
    if (lSon.val < rSon.val)
        return lSon;
    else
        return rSon;
}

/**
 * 功能：更新线段树中某个区间内叶子节点的值
 * @param root 当前线段树的根节点下标
 * @param nStart 当前节点所表示的区间
 * @param nEnd 当前节点所表示的区间
 * @param uStart 待更新的区间
 * @param uEnd 待更新的区间
 */
void update(int root, int nStart, int nEnd, int uStart, int uEnd, int val) {
    //更新区间和当前节点区间没有交集
    if (uStart > nEnd || uEnd < nStart)
        return;
    //当前节点区间包含在更新区间内
    if (uStart <= nStart && uEnd >= nEnd) {
        b2[root].addMark += val;
        b2[root].val += val;
        return;
    }
    pushDown(root); //延迟标记向下传递
    //更新左右孩子节点
    int mid = (nStart + nEnd) / 2;
    update(root * 2, nStart, mid, uStart, uEnd, val);
    update(root * 2 + 1, mid + 1, nEnd, uStart, uEnd, val);
    //根据左右子树的值回溯更新当前节点的值
    if (b2[root * 2].val < b2[root * 2 + 1].val) {
        b2[root].val = b2[root * 2].val;
        b2[root].index = b2[root * 2].index;
    } else {
        b2[root].val = b2[root * 2 + 1].val;
        b2[root].index = b2[root * 2 + 1].index;
    }
}

//树状数组
void tree_update(int x) {        //树状数组储存法
    while (x <= n) {
        c[x]++;
        x += lowBit(x);
    }
}


int tree_sum(int x) {               //树状数组的部分了
    int s = 0;
    while (x) {
        s += c[x];
        x -= lowBit(x);
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    while (cin >> n >> q) {
        memset(c, 0, sizeof(c));
        memset(b, 0, sizeof(b));
        memset(b2, 0, sizeof(b2));
        for (int i = 1; i <= n; ++i) cin >> b[i];
        build(1, 1, n);
        while (q--) {
            cin >> str >> l >> r;
            if (str == "add") {
                update(1, 1, n, l, r, -1);
                Node ans = query(1, 1, n, 1, n);
                while (ans.val == 0) {
                    tree_update(ans.index);
                    update(1, 1, n, ans.index, ans.index, b[ans.index]);
                    ans = query(1, 1, n, 1, n);
                }
            } else if (str == "query") cout << tree_sum(r) - tree_sum(l - 1) << endl;
        }
    }
    return 0;
}