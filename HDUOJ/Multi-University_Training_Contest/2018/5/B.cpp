#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 20;
int num[MAXN], num2[MAXN], ans_min, ans_max, k;
string n;

void update() {
    //第一位数字不为零，无论最大值最小值
    if (n[num[0]] == '0') return;
    for (int i = 0; i < n.length(); ++i) num2[i] = num[i];
    int tmp = 0, count = 0;
    for (int i = 0; i < n.length(); ++i) {
        tmp = tmp * 10 + n[num[i]] - '0';
        //如果当前全排列的当前下标不在原来的位置上，那么找到正确的位置，进行交换，计数器加一
        if (num2[i] != i) {
            for (int j = i + 1; j < n.length(); ++j) {
                if (num2[j] == i) {
                    swap(num2[j], num2[i]);
                    ++count;
                    if (count > k) return;
                    break;
                }
            }
        }
    }
    //如果所需次数超过所给的ｋ,那么是不可行的
    if (count > k) return;
    ans_min = min(ans_min, tmp);
    ans_max = max(ans_max, tmp);
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("/home/lance/CLionProjects/code/HDUOJ/Multi-University_Training_Contest/2018/5/input.txt", "r", stdin);
    freopen("/home/lance/Documents/Tencent Files/603842325/FileRecv/upload-files-for-stage-5-new/data/1002.in", "r",
            stdin);
    freopen("/home/lance/Documents/Tencent Files/603842325/FileRecv/upload-files-for-stage-5-new/data/out.out", "w",
            stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        //使一个序列有序的最大任意交换次数是位数减一，如果操作次数大于位数减一，证明一定可以得到最大值和最小值
        if (n.length() - 1 <= k) {
            sort(n.begin(), n.end(), greater<char>());
            ans_max = atoi(n.c_str());
            for (int i = 1; i < n.length(); ++i)
                if (n[0] > n[i] && n[i] != '0') swap(n[0], n[i]);
            sort(n.begin() + 1, n.end());
            ans_min = atoi(n.c_str());
        } else {
            for (int i = 0; i < n.length(); ++i) num[i] = i;
            ans_min = INF, ans_max = -INF;
            do {
                update();
            } while (next_permutation(num, num + n.length()));
        }
        cout << ans_min << ' ' << ans_max << endl;
    }
    return 0;
}