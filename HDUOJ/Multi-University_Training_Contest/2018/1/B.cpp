#include<bits/stdc++.h>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    //如果a的右括号的数量大于a的左括号数量，同时b的右括号的数量小于b的左括号数量, 那么a要排在b的后面才能得到更多的配对
    if (a.second >= a.first && b.second < b.first)
        return false;
    //如果a的右括号的数量小于a的左括号数量，同时b的右括号的数量大于b的左括号数量, 那么b要排在a的后面才能得到更多的配对
    if (a.second < a.first && b.second >= b.first)
        return true;
    //如果a的右括号的数量大于a的左括号数量，同时b的右括号的数量大于b的左括号数量, 那么左括号多的排在前面可以得到最多的配对
    if (a.second >= a.first && b.second >= b.first)
        return a.first > b.first;
    //如果a的右括号的数量小于a的左括号数量，同时b的右括号的数量小于b的左括号数量, 那么右括号多的排在后面可以得到最多的配对
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, ans, n, now_left;
    string str;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<pair<int, int>> vector_pair;
        ans = now_left = 0;
        for (int i = 0; i < n; ++i) {
            cin >> str;
            pair<int, int> p = make_pair(0, 0);
            //遍历输入的字符串，将已经配对的加入答案，将剩下的左括号数目和右括号数目记录进pair，放入序列
            for (char j : str) {
                if (j == ')') {
                    if (p.first > 0) {
                        p.first--;
                        ans++;
                    } else p.second++;
                } else p.first++;
            }
            vector_pair.push_back(p);
        }
        sort(vector_pair.begin(), vector_pair.end(), cmp);
        //遍历序列，now_left记录当前所剩左括号的数目
        for (auto &i : vector_pair) {
            //如果左括号数量小于当前字符串所剩的右括号，将当前字符串所剩的右括号赋值为当前左括号值，即可以被消去的数量
            if (now_left < i.second) i.second = now_left;
            //now_left 减去被消去的数量，再加上新的左括号数量
            ans += i.second, now_left -= i.second, now_left += i.first;
        }
        //每次消去都是两个一起消去的，所以答案要乘以2
        cout << ans * 2 << endl;
    }
    return 0;
}



