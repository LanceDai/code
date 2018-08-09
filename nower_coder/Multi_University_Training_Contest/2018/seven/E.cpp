#include <bits/stdc++.h>

using namespace std;
int C[100];

void init() {
    for (int i = 4; i <= 100; ++i) {
        C[i] = i * (i - 1) * (i - 2) * (i - 3) / 24;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int k, num;
    cin >> k;
    num = *lower_bound(C, C + 100, k);
    vector<int> l;
    return 0;
}