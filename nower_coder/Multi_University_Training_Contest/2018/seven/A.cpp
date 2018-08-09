#include <bits/stdc++.h>

using namespace std;
int Two[20];

void init() {
    int x = 1;
    for (int &i : Two) {
        i = x;
        x *= 2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, tmp;
    cin >> n;
    vector<int> v;
    init();
    while (n) {
        tmp = *lower_bound(Two, Two + 20, n) - n;
        while (tmp < n) v.push_back(tmp++);
        n = *lower_bound(Two, Two + 20, n) - n;
    }
    for (int i = v.size() - 1; i >= 0; --i) cout << v[i] << " \n"[i == 0];
    return 0;
}