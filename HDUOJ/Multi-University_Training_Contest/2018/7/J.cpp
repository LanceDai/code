#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
const int MOD = static_cast<int>(1e9 + 7);

struct Matrix {
    LL num[3][3];

    //重载乘法运算符
    friend Matrix operator*(const Matrix &a, const Matrix &b) {
        Matrix ans{};
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                for (int k = 0; k < 3; ++k)
                    ans.num[i][j] = (ans.num[i][j] + a.num[i][k] * b.num[k][j] % MOD) % MOD;
        return ans;
    }

    //矩阵快速幂
    friend Matrix matrixQuickPow(Matrix x, LL n) {
        Matrix res{};
        for (int i = 0; i < 3; ++i) res.num[i][i] = 1;
        while (n) {
            if (n & 1) res = res * x;
            x = x * x;
            n >>= 1;
        }
        return res;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("/home/lance/Documents/Tencent Files/603842325/FileRecv/HDU多校第七场-UESTC题解/1010/data/Problem/0.in", "r",
            stdin);
//    freopen("/home/lance/CLionProjects/code/HDUOJ/Multi-University_Training_Contest/2018/7/input.txt", "r",
//            stdin);
    freopen("/home/lance/Documents/Tencent Files/603842325/FileRecv/HDU多校第七场-UESTC题解/1010/data/Problem/out.out", "w",
            stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    LL T, A, B, C, D, P, n, times;
    cin >> T;
    while (T--) {
        cin >> A >> B >> C >> D >> P >> n;
        if (n == 1) cout << A << endl;
        else {
            Matrix tmp{}, res{};
            for (int i = 0; i < 3; ++i) res.num[i][i] = 1;
            //初始化系数矩阵
            tmp.num[0][0] = D;
            tmp.num[0][1] = C;
            tmp.num[1][0] = 1;
            tmp.num[2][2] = 1;
            for (LL i = 3; i <= n; i += times) {
                //如果n > P / (P / i)，　证明n比当前ｉ所处分段的最大值都大，证明这一段的每一个都可取，所以次数为 P / (P / i) - i + 1
                //即这一段所有的个数
                if (!(P / i) && n > P / (P / i))times = P / (P / i) - i + 1;
                    //否则只取其中一段, 即ｎ - i + 1, 当p / i的时候是取剩余的全部，情况类似
                else times = n - i + 1;
                //将这一段的系数矩阵的相应位置赋值上相应的系数
                tmp.num[0][2] = P / i;
                //矩阵乘法通常不满足交换律，注意乘法顺序
                res = matrixQuickPow(tmp, times) * res;
            }
            //系数矩阵乘以初始矩阵，由f(1),f(2),1组成的３×１矩阵，即为答案
            cout << (res.num[0][0] * (LL) B + res.num[0][1] * (LL) A + res.num[0][2]) % MOD << endl;
        }
    }
    return 0;
}