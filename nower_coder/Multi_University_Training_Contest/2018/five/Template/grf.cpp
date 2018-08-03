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
const int MOD = 998244353;
const int N = 19;

inline int Pow(int a, int b) {
    int c = 1;
    for (; b; b >>= 1, a = a * 1ll * a % MOD)if (b & 1)c = c * 1ll * a % MOD;
    return c;
}

int a[N];
int n, m;
int num[1 << N];
int bitc[1 << N];
int p2[100000];
int g[1 << N][N + 1], f[1 << N][N + 1];

void fwt(int f[1 << N][N + 1]) {
    for (int i = (int) 0; i <= (int) n - 1; i++)
        for (int S = (int) 0; S <= (int) (1 << n) - 1; S++)
            if (S & (1 << i))
                for (int j = (int) 0; j <= (int) n; j++)f[S][j] = (f[S][j] + f[S ^ (1 << i)][j]) % MOD;
}

void nfwt(int f[1 << N][N + 1]) {
    for (int i = (int) n - 1; i >= (int) 0; i--)
        for (int S = (int) 0; S <= (int) (1 << n) - 1; S++)
            if (S & (1 << i))
                for (int j = (int) 0; j <= (int) n; j++)f[S][j] = (f[S][j] + MOD - f[S ^ (1 << i)][j]) % MOD;
}

int comb[N * 2][N * 2];
int d[1 << N][N + 1];
int iv[1000];

void jie(int *f, int *g) {
    static int invf[N + 1];
    memset(invf, 0, sizeof invf);
    int t = Pow(f[0], MOD - 2);
    invf[0] = t;
    for (int i = (int) 1; i <= (int) n; i++) {
        LL w = 0;
        for (int j = (int) 0; j <= (int) i - 1; j++) {
            if (w < 0)w += invf[j] * 1ll * f[i - j];
            else w += (invf[j] - MOD) * 1ll * f[i - j];
        }
        invf[i] = (MOD - ((w % MOD + MOD) % MOD)) * 1ll * t % MOD;
    }
    static int df[N + 1];
    memset(df, 0, sizeof df);
    for (int i = (int) 1; i <= (int) n; i++) {
        df[i - 1] = f[i] * 1ll * i % MOD;
    }
    for (int i = (int) 0; i <= (int) n; i++)g[i] = 0;
    for (int i = (int) 0; i <= (int) n; i++) {
        LL w = 0;
        for (int j = (int) 0; j <= (int) i; j++) {
            if (w < 0)w += df[j] * 1ll * invf[i - j];
            else w += (df[j] - MOD) * 1ll * invf[i - j];
        }
        g[i] = (w % MOD + MOD) % MOD;
    }
    for (int i = (int) n - 1; i >= (int) 0; i--)g[i + 1] = g[i] * 1ll * iv[i + 1] % MOD;
    g[0] = 0;
}

void calcG() {
    for (int S = (int) 0; S <= (int) (1 << n) - 1; S++)d[S][bitc[S]] = p2[num[S]];
    fwt(d);
    for (int S = (int) 0; S <= (int) (1 << n) - 1; S++)jie(d[S], g[S]);
    nfwt(g);
    for (int S = (int) 0; S <= (int) (1 << n) - 1; S++)
        for (int i = (int) 0; i <= (int) n; i++)
            if (bitc[S] != i)
                g[S][i] = 0;
}

int ifac[N * 2];
int fac[N * 2];

void equation(int *g, int *f) {
    assert(g[0] == 0);
    static int h[N + 1];
    memset(h, 0, sizeof h);
    f[0] = 0;
    h[0] = 1;
    for (int i = (int) 1; i <= (int) n; i++) {
        f[i] = h[i] = 0;
        for (int j = (int) 1; j <= (int) i; j++)f[i] = (f[i] + (g[j] * 1ll * h[i - j] % MOD) * 1ll * ifac[i - j]) % MOD;
        for (int j = (int) 1; j <= (int) i; j++)
            h[i] = (h[i] + ((f[j] * 1ll * h[i - j] % MOD) * 1ll * comb[i - 1][j - 1] % MOD) * 1ll * fac[j]) % MOD;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    assert(1 <= n && n <= 19);
    assert(0 <= m && m <= n * (n - 1) / 2);
    for (int i = (int) 1; i <= (int) n * 2; i++)iv[i] = Pow(i, MOD - 2);
    ifac[0] = 1;
    for (int i = (int) 1; i <= (int) n; i++)ifac[i] = ifac[i - 1] * 1ll * iv[i] % MOD;
    fac[0] = 1;
    for (int i = (int) 1; i <= (int) n; i++)fac[i] = fac[i - 1] * 1ll * i % MOD;
    for (int i = (int) 0; i <= (int) n; i++) {
        comb[i][0] = comb[i][i] = 1;
        for (int j = (int) 1; j <= (int) i - 1; j++)comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
    }
    for (int i = (int) 1; i <= (int) m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--;
        y--;
        assert(!(a[x] & (1 << y)));
        assert(!(a[y] & (1 << x)));
        a[x] |= (1 << (y));
        a[y] |= (1 << (x));
    }
    for (int S = (int) 0; S <= (int) (1 << n) - 1; S++)
        for (int i = (int) 0; i <= (int) n - 1; i++)
            if (S & (1 << i))
                bitc[S]++;
    for (int S = (int) 0; S <= (int) (1 << n) - 1; S++) {
        int w = 0;
        for (int i = (int) 0; i <= (int) n - 1; i++)if (S & (1 << i))w += bitc[(a[i] & S)];
        num[S] = w / 2;
    }
    p2[0] = 1;
    for (int i = (int) 1; i <= (int) 5000; i++)p2[i] = p2[i - 1] * 2 % MOD;
    calcG();
    fwt(g);
    for (int S = (int) 0; S <= (int) (1 << n) - 1; S++) {
        equation(g[S], f[S]);
    }
    nfwt(f);
    //rep(S,0,(1<<n)-1)printf("f[%d]=%d\n",S,f[S][bitc[S]]);
    printf("%d\n", f[(1 << n) - 1][n]);
    return 0;
}







