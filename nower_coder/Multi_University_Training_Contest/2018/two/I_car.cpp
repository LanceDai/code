#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int MAXN = 100050;
int n, m, ans;
bool row[MAXN], column[MAXN];

int main() {
    cin >> n >> m;
    //当没有被毁坏的格子时，最多是2 * n 个，
    // （当n为奇数是，中间一行一列是不能同时存在车的，要减一）
    ans = n * 2;
    int x, y;
    //m个毁坏的格子
    while (m--) {
        cin >> x >> y;
        //对于每一个毁坏的格子，它的行列上都不能有car通过，所以将相应的行列状态置为true
        if (!row[x]) {
            //如果没有被置为true，置为true
            row[x] = true;
            ans--;
        }
        if (!column[y]) {
            //如果没有被置为true，置为true
            column[y] = true;
            ans--;
        }
    }
    if (n & 1 && !row[n / 2 + 1] && !column[n / 2 + 1])
        ans--;
    cout << ans << endl;
    return 0;
}
