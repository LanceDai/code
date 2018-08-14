#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

const int N = 1005, M = 55;
int arr[N][N], x[N][N], y[N][N], r[N][M], c[N][M];
int goToRight[N][N], goToDown[N][N], nextInRight[N], nextInDown[N], down[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    char ch;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ch;
            if (islower(ch)) arr[i][j] = ch - 'a' + 1;
            else arr[i][j] = ch - 'A' + 27;
        }
    }
    //go right 向右最远能到达
    for (int i = 0; i < n; i++) {
        //初始化每个字符在每一行內下一个出现的位置都是每一行的右端点
        for (int j = 0; j < M; j++) nextInRight[j] = m;
        goToRight[i][m] = m;
        for (int j = m - 1; j >= 0; j--) {
            //从后往前，第i行第j列的值所能到达的最右处是它的右边字符所能到达的最右处和与它重复的字符出现的下一个位置的较小值
            //对于最后一个值来说都是m，所以要对goToRight[i][m] = m进行初始化
            goToRight[i][j] = min(nextInRight[arr[i][j]], goToRight[i][j + 1]);
            //对于前面与arr[i,j]相同的字符来说，重复的位置就是arr[i][j]所处的位置，所以更新nextInRight的值
            nextInRight[arr[i][j]] = j;
        }
    }
    //go down  向下最远能到达
    for (int j = 0; j < m; j++) {
        //初始化每个字符在每一列内下一个出现的位置都是每一列的下端点
        for (int i = 0; i < M; i++) nextInDown[i] = n;
        goToDown[n][j] = n;
        for (int i = n - 1; i >= 0; i--) {
            //从下往上，第i行第j列的值所能到达的最下处是它的下边字符所能到达的最下处和与它重复的字符出现的下一个位置的较小值
            //对于最后一个值来说都是m，所以要对goToDown[i][m] = m进行初始化
            goToDown[i][j] = min(nextInDown[arr[i][j]], goToDown[i + 1][j]);
            //对于前面与arr[i,j]相同的字符来说，重复的位置就是arr[i][j]所处的位置，所以更新nextInDown的值,所以要从后往前
            nextInDown[arr[i][j]] = i;
        }
    }
    LL ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int bottom = goToDown[i][j];
            //down数组记录每个arr[i][k], k∈[j, gor[i][j]-1]所能到达的最大深度
            //由于要以arr[i][j]为左上端点，构造子矩阵，
            //所以down[k] 在 [j, gor[i][j]-1] 上是单调非递增的
            for (int k = j; k < goToRight[i][j]; k++) {
                bottom = min(bottom, goToDown[i][k]);
                down[k] = bottom;
            }
            //g记录当前行所能到达的最右处
            //g只能是非递增的
            int g = goToRight[i][j] - 1;
            for (int k = i; k < goToDown[i][j]; k++) {
                g = min(g, goToRight[k][j] - 1);
                //如果对当前值所在的最右处的最下值比当前行小的话，证明不能构成子矩阵，因为down数组是非递增的，所以g--，以得到满足的行值
                while (down[g] <= k) g--;
                //因为是对每一行进行枚举，所以列数相减就是这一行新增的子矩阵数
                ans += g - j + 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}