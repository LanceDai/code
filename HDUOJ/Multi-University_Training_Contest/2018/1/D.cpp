#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n, m, tmp1, tmp2, last_start, last_end, i, j;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<pair<int, int> > r, rp;
        //输入m个区间
        while (m--) {
            cin >> tmp1 >> tmp2;
            rp.emplace_back(tmp1, tmp2);
        }
        //根据左端点进行排序，pair 默认以first作为排序标准，所以这里不用指定cmp排序函数
        sort(rp.begin(), rp.end());
        //初始化上一个区间的值
        last_start = last_end = 0;
        //遍历区间序列
        for (auto &&item: rp) {
            //如果当前区间的右端点比所记录的上一个区间的右端点小，证明这个区间是被上一个区间所包含所以舍去
            if (item.second <= last_end) continue;
            //如果当前区间的左端点等于所记录的上一个区间的左端点，证明这个区间是包含上一个区间的，所以更新区间范围
            if (item.first == last_start) last_end = item.second;
            else {
                //在这里证明当前区间与上一个区间没有包含与被包含的关系，那么把上一个区间加入序列
                r.emplace_back(last_start, last_end);
                //将所记录的区间开始，和区间结尾更新
                last_start = item.first;
                last_end = item.second;
            }
        }
        //将最后一个区间加入序列
        r.emplace_back(last_start, last_end);
        //声明一个set， 用来存放可以使用的数字
        set<int> use;
        //初始化set，在一开始，1～n的数字都是可以使用的
        for (i = 1; i <= n; ++i) use.insert(i);
        //声明结果数组
        int ans[n + 1];
        //清零
        memset(ans, 0, sizeof(ans));
        //从一开始，因为在前面预处理的时候会加入一个{0， 0}区间，为了防止越界操作
        for (i = 1; i < r.size(); i++) {
            //把上一个区间重叠区域外的值加回set，这是在下一次可以使用的
            for (j = r[i - 1].first; j < ((i == 1) ? 0 : min(r[i - 1].second + 1, r[i].first)); ++j) use.insert(ans[j]);
            //把当前区间重叠区间外的范围赋值
            for (j = max(r[i - 1].second, r[i].first - 1) + 1; j <= r[i].second; j++) {
                //set是有序的，第一个值就是可以用的序列中字典序最小的
                ans[j] = *use.begin();
                use.erase(ans[j]);
            }
        }
        //输出结果
        for (i = 1; i < n; i++) ans[i] == 0 ? cout << "1 " : cout << ans[i] << ' ';
        ans[n] == 0 ? cout << "1" << endl : cout << ans[n] << endl;
    }
    return 0;
}

