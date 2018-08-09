#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int MAXN = 100005;
int w[MAXN];
int v[MAXN];
int par[MAXN];
bool isWolf[MAXN];

void init(int n) {
    for (int i = 1; i <= n; ++i) par[i] = i;
}

int find(int x) {
    if (par[x] == x || isWolf[x]) return x;
    return par[x] = find(par[x]);
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("/home/lance/CLionProjects/code/HDUOJ/Multi-University_Training_Contest/2018/6/input.txt", "r", stdin);
    freopen("/home/lance/Documents/Tencent Files/603842325/FileRecv/hdu-multi6-fzdx/data/1009/in", "r", stdin);
    freopen("/home/lance/Documents/Tencent Files/603842325/FileRecv/hdu-multi6-fzdx/data/out.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t, n, sum;
    string s;
    cin >> t;
    while (t--) {
        memset(isWolf, 0, sizeof(isWolf));
        memset(w, 0, sizeof(w));
        memset(v, 0, sizeof(v));
        sum = 0;
        cin >> n;
        init(n);
        for (int i = 1; i <= n; i++) {
            int pos;
            cin >> pos >> s;
            if (s[0] == 'w') w[i] = pos;
            else v[i] = pos;
        }
        for (int i = 1; i <= n; i++) {
            if (w[i] != 0) {
                int temp = w[i];
                set<int> si;
                int size = 0;
                si.insert(w[i]);
                while (v[temp] != 0 && size != si.size()) {
                    size = int(si.size());
                    temp = v[temp];
                    si.insert(temp);
                }
                if (temp == i) isWolf[w[i]] = true;
            }
        }
        for (int i = 1; i <= n; i++) if (v[i]) par[i] = find(v[i]);
        for (int i = 1; i <= n; ++i) sum += isWolf[find(i)];
        cout << "0 " << sum << endl;
    }
    return 0;
}
