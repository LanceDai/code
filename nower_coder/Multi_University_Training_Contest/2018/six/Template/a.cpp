#include <bits/stdc++.h>

#define ls(x) ((x) << 1)
#define rs(x) (ls(x) | 1)
#define ALL(x) (x).begin(), (x).end()

const int max_N = 14;
const int max_S = (1 << max_N);

int T, n, s;

std::vector<int> vec[max_S];

int winner[max_S << 1];

int race(int a, int b) {
    int winner = vec[a].back() > vec[b].back() ? a : b;
    int loser = a ^ b ^ winner;
    auto it = std::upper_bound(ALL(vec[winner]), vec[loser].back());
    vec[winner].erase(it);
    return winner;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        static int Case = 0;
        int n1;
        scanf("%d%u%u%u", &n1, &x, &y, &z);
        for (int i = 0 ; i < n1 ; ++ i) {
            a[i] = tang();
        }
        int m = std::max(0 , n1 - 100);
        nth_element(a , a + m , a + n1);
        unsigned long long ans = 0;
        for (int i = m ; i < n1 ; ++ i) {
            for (int j = i + 1 ; j < n1 ; ++ j) {
                ans = max(ans , 1ull * a[i] / std::__gcd(a[i] , a[j]) * a[j]);
            }
        }
        printf("Case #%d: %llu\n", ++ Case, ans);
    }
    return 0;
}
