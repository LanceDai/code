#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<iostream>
#include<assert.h>
#include<queue>
#include<string>

#define rep(i, j, k) for(int i=(int)j;i<=(int)k;i++)
#define per(i, j, k) for(int i=(int)j;i>=(int)k;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long LL;
const int MAXN = 110000;
int n, s[MAXN], c[MAXN], k;
int id[MAXN];
bool del[MAXN];
double D;

inline bool cmp(const int &x, const int &y) {
    return (c[x] - D) * s[x] < (c[y] - D) * s[y];
}

bool check(double D) {
    for (int i = (int) 1; i <= (int) n; i++)id[i] = i, del[i] = 0;
    ::D = D;
    nth_element(id + 1, id + k, id + 1 + n, cmp);
    for (int i = (int) 1; i <= (int) k; i++) {
        double dd = (c[id[i]] - D) * s[id[i]];
        if (dd < 0)del[id[i]] = 1;
    }
    double s1 = 0;
    double s2 = 0;
    for (int i = (int) 1; i <= (int) n; i++)
        if (!del[i]) {
            s1 += s[i] * 1. * c[i];
            s2 += s[i];
        }
    return s1 * 1. / s2 > D;
}

int main() {
    scanf("%d%d", &n, &k);
    assert(1 <= n && n <= 100000);
    assert(0 <= k && k < n);
    for (int i = (int) 1; i <= (int) n; i++)scanf("%d", &s[i]);
    for (int i = (int) 1; i <= (int) n; i++)scanf("%d", &c[i]);
    for (int i = (int) 1; i <= (int) n; i++) {
        assert(1 <= s[i] && s[i] <= 1000);
        assert(1 <= c[i] && c[i] <= 1000);
    }
    double l = 0;
    double r = 1e3;
    for (int i = (int) 1; i <= (int) 50; i++) {
        double mid = (l + r) / 2.;
        if (check(mid))l = mid; else r = mid;
    }
    printf("%.8lf\n", l);
    return 0;
}







