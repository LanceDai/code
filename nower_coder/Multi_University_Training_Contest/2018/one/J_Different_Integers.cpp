//============================================================================
//Name：牛客多校第一场 J-Different Integers 树状数组
//============================================================================
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;
const int MAXN = 100005;
const int MAXN = 2 * MAXN;
struct ss {
    int x, y, pos;
} group[MAXN];
//loc[i] = i出现的位置
int loc[MAXN], ans[MAXN];
//Next[i] = i位置上的数下一个出现的位置
//fir[i] = i位置上的数是否为第一次出现
int query[MAXN], c[MAXN], Next[MAXN], fir[MAXN];

bool cmp(ss p, ss q) {
    return p.x < q.x;
}

int lowBit(int x) {
    return x & -x;
}

//a[i] += v
void add(int x, int v) {
    while (x < MAXN) {
        c[x] += v;
        x += lowBit(x);
    }
}

//a[1] + ... + a[x]
int sum(int x) {
    int s = 0;
    while (x) {
        s += c[x];
        x -= lowBit(x);
    }
    return s;
}

//void display(int n) {
//	for(int i = 1; i <= 2 * n; i++) {
//		printf("i = %d a[i] = %d next[i] = %d fir[i] = %d sum = %d\n", i, a[i], next[i], fir[i], sum(i));
//	}
//}

int main() {
    int n, q;
    while (~scanf("%d %d", &n, &q)) {

        //初始化变量，Fir初始化为1， 其余初始化为0
        memset(query, 0, sizeof(query));
        memset(loc, 0, sizeof(loc));
        memset(Next, 0, sizeof(Next));
        memset(ans, 0, sizeof(ans));
        memset(c, 0, sizeof(c));

//		倍增数组，将对两个区间的查询转换为对单个区间的查询
        for (int i = 1; i <= n; i++) {
//			cin>>a[i];
            scanf("%d", &query[i]);
            query[i + n] = query[i];
            fir[i] = 1;
            fir[i + n] = 1;
        }

        //预处理Next、Fir数组
        for (int i = 2 * n; i > 0; i--) {
            fir[loc[query[i]]] = 0;
            Next[i] = loc[query[i]];
            loc[query[i]] = i;
        }

        //预处理树状数组
        for (int i = 1; i <= 2 * n; i++) {
            if (fir[i]) {
                add(i, 1);
            }
        }

//		for(int i = 1; i <= 2 * n; i++) {
//			printf("i = %d a[i] = %d next[i] = %d fir[i] = %d sum = %d\n", i, a[i], next[i], fir[i], sum(i));
//		}


        //区间处理，
        for (int i = 1; i <= q; i++) {
            scanf("%d %d", &group[i].x, &group[i].y);
//			cin>>f[i].x>>f[i].y;
            group[i].x += n;
            swap(group[i].x, group[i].y);
            group[i].pos = i;
        }

//		区间排序
        sort(group + 1, group + q + 1, cmp);

//		for (int i =1; i <= q; i++) {
//			printf("f[i].x = %d f[i].y = %d f[i].pos = %d\n", f[i].x, f[i].y, f[i].pos);
//		}

        int nextLIndex = 1;
        for (int i = 1; i <= 2 * n && nextLIndex <= q;) {
            if (i == group[nextLIndex].x) {
// Query
                ans[group[nextLIndex].pos] = sum(group[nextLIndex].y) - sum(group[nextLIndex].x) + 1;
                nextLIndex++;
//				printf("f[i].pos = %d ans = %d\n", f[i].pos, ans[f[i].pos]);
            } else {
                if (fir[i]) {
// Update，下一个更新为 1
                    fir[i] = 0;
                    add(i, -1);
                    fir[Next[i]] = 1;
                    add(Next[i], 1);
//					display(n);
                }
                i++;
            }

        }

        for (int i = 1; i <= q; i++) {
//			cout<<ans[i]<<endl;
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
