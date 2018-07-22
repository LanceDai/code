//============================================================================
//Name：one D-Two Graphs
//直接枚举所有映射，图1和图2的映射总次数，然后去重
//============================================================================

#include<bits/stdc++.h>

using namespace std;
long long n, m1, m2, i, j, x, y, a[10][10], b[10][10];
long long num[10];
set<long long> s;

int main() {
    while (~scanf("%lld %lld %lld", &n, &m1, &m2)) {
        s.clear();
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);

        for (i = 1; i <= m1; i++) {
            scanf("%lld%lld", &x, &y);
            a[x][y] = a[y][x] = 1;
        }
        for (i = 1; i <= m2; i++) {
            scanf("%lld%lld", &x, &y);
            b[x][y] = b[y][x] = 1;
        }

        for (i = 1; i <= n; i++) {
            num[i] = i;
        }
        do {
            //Now 保存图的状态，对应位置为 1，表示该边存在
            // OK 是否匹配
            long long now = 0, ok = 1;
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= n; j++) {
                    if (a[i][j] && b[num[i]][num[j]]) {
                        //匹配成功，以二进制保存子图状态
                        //把邻接矩阵压缩成一维，通过位运算保存边出现的位置
                        //(num[i] - 1) * (n) + num[j])：边在一维中的位置 x
                        //1LL << ((num[i] - 1) * (n) + num[j])：将 1 左移 x 位，即将第 x 位置为 1
                        now += (1LL << ((num[i] - 1) * (n) + num[j]));
                    } else if (a[i][j] && !b[num[i]][num[j]]) {
                        //没有匹配
                        ok = 0;
                    }
                }
            }
            if (ok) {
                //如果全部边都映射成功，那么加入set
                s.insert(now);
            }
        } while (next_permutation(num + 1, num + 1 + n));
        //next_permutation 通过字典序得到下一个全排列
        //这里用来枚举映射关系 i --> num[i]
        //由于set的去重特性，输出集合大小，即为子图个数
        cout << s.size() << endl;
    }
    return 0;
}