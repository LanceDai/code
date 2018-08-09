#include <bits/stdc++.h>
using namespace std;
unsigned isWolf[10000000];

unsigned x, y, z;
unsigned tang() {
    unsigned t;
    x ^= x << 16;
    x ^= x >> 5;
    x ^= x << 1;
    t = x;
    x = y;
    y = z;
    z = t ^ x ^ y;
    return z;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t --) {
        static int Case = 0;
        int n;
        scanf("%d%u%u%u", &n, &x, &y, &z);
        for (int i = 0 ; i < n ; ++ i) {
            isWolf[i] = tang();
        }
        int m = max(0 , n - 100);
        nth_element(isWolf , isWolf + m , isWolf + n);
        unsigned long long ans = 0;
        for (int i = m ; i < n ; ++ i) {
            for (int j = i + 1 ; j < n ; ++ j) {
                ans = max(ans , 1ull * isWolf[i] / __gcd(isWolf[i] , isWolf[j]) * isWolf[j]);
            }
        }
        printf("Case #%d: %llu\n", ++ Case, ans);
    }
    return 0;
}
