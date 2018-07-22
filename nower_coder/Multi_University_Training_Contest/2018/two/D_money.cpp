#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
typedef long long LL;
int a[100005];

/**
 * 连续递增子序列的个数就是最小交易次数
 * 如果下一家店的价值大于当前这家店，那么就要保证现在手里有货，在下一家卖出
 * @return
 */

int main() {
    int t, n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool isContinuous = false;
        LL money = 0, count = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] > a[i - 1]) {
                money += a[i] - a[i - 1];
                //如果isContinuous==false，证明这是一个新的递增子序列，count++
                if (!isContinuous)count++;
                //连续递增序列开始
                isContinuous = true;
            } else if (a[i] < a[i - 1]) {
                //连续递增序列结束
                isContinuous = false;
            }
        }

        //递增连续子序列的起始端是买入，末尾段是卖出，所以是个数乘以二
        cout << money << ' ' << count * 2 << endl;
    }
    return 0;
}

/**
 * data
 1
 5
 9 10 7 6 8

 answer
 3 4
**/