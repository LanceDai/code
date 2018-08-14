#include<bits/stdc++.h>

using namespace std;
const int MAXN = 100050;
struct ss{
    int x, cnt, y;
} f[MAXN];

bool cmp(ss p, ss q) {
    if (p.cnt == q.cnt) {
        return p.x > q.x;
    }
    return p.cnt > q.cnt;
}

int nextInRight[MAXN];
map<int, int> char_map;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, t;
    cin >> t;
    while (t--) {
        memset(f, 0, sizeof(f));
        memset(nextInRight, 0, sizeof(nextInRight));
        char_map.clear();
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            //记录每个数出现的次数
            char_map[x]++;
        }
        int cnt = 0;
        for (auto &it : char_map) {
            f[cnt].x = it.first;
            f[cnt++].cnt = it.second;
        }
        //按出现次数排序，若出现次数相同，那么以值大小降序排序
        sort(f, f + cnt, cmp);
//		tmp[i] 出现次数为 i 的数的个数
//		f[i].y 成为出现次数最多需要删掉的数目
        int sum = 0;
        for (int i = 0; i < cnt; i++) {
            nextInRight[f[i].cnt]++;
            if (f[i].cnt != f[i - 1].cnt || i == 0) {
//                如果要取得这个数，那么就要把在他前面次数多的都删为比当前这个数的次数少一
                f[i].y = sum - (i) * (f[i].cnt - 1);
            } else {
                f[i].y = f[i - 1].y;
            }
            //sum记录次数前缀和
            sum += f[i].cnt;
        }
// 		map[i] 和 i 出现次数相同的数的个数
        char_map.clear();
        for (int i = 0; i < cnt; i++) {
            char_map[f[i].x] = nextInRight[f[i].cnt];
        }
        int M = -1;
        for (int i = 0; i < cnt; i++) {
            int val = f[i].x;
            //为了取到这个值，与他次数相同的数也要次数都减一，如果总次数大于等于当前数被取得所要花费的次数，说明当前数字是可能被取到的
            if (m >= (char_map[val] - 1 + f[i].y)) {
                M = max(M, val);
            }
        }
        cout << M << endl;
    }
    return 0;
}
