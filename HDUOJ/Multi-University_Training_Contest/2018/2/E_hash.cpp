#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int MAX = 2000010;

struct hash_table {
    ULL seed = 23333;
    ULL Hash[MAX], tmp[MAX];

    void work(const string &s, ULL n) {
        tmp[0] = 1;
        Hash[0] = 0;
        for (LL i = 1; i <= n; i++) tmp[i] = tmp[i - 1] * seed;
        for (LL i = 1; i <= n; i++) Hash[i] = (Hash[i - 1] * seed + (s[i - 1] - 'a'));
    }

    ULL get(ULL l, ULL r) {
        return (Hash[r + 1] - Hash[l] * tmp[r - l + 1]);
    }
} h;

vector<int> res[MAX];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tot;
    ULL len;
    string s;
    while (cin >> s) {
        len = s.length();
        s.resize(len * 2);
        for (int j = 0; j < len; j++) s[j + len] = s[j];
        h.work(s, len * 2);
        unordered_map<ULL, int> mp;
        tot = 0;
        for (int i = 0; i < len; i++) {
            ULL tmp = h.get(i+ 0ULL, i + len - 1);
            if (!mp.count(tmp)) mp[tmp] = ++tot;
            res[mp[tmp]].push_back(i);
        }
        cout << tot << '\n';
        for (int i = 1; i <= tot; i++) {
            cout << res[i].size();
            for (auto it:res[i]) cout << ' ' << it;
            cout << endl;
            res[i].clear();
        }
    }
    return 0;
}