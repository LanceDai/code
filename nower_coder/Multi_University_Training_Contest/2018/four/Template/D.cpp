#include <cstdio>

const int MAXN = 1000 + 10;

int query[MAXN][MAXN];

void construct(int n) {
    for (int i = 0; i < n; i += 2) {
        int m = i + 2;
        query[m - 1][m - 1] = -1;
        query[m - 1][m - 2] = 1;
        query[m - 2][m - 2] = 1;
        query[m - 2][m - 1] = 0;
        for (int j = 0; j < i; ++j) {
            if (j & 1) query[j][m - 1] = query[j][m - 2] = query[m - 1][j] = query[m - 2][j] = -1;
            else query[j][m - 1] = query[j][m - 2] = query[m - 1][j] = query[m - 2][j] = 1;
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    construct(200);
    for (int cas = 1; cas <= T; ++cas) {
        int n;
        scanf("%d", &n);
        if (n % 2 == 1) puts("impossible");
        else puts("possible");
        if (n % 2 == 0) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (j) putchar(' ');
                    printf("%d", query[i][j]);
                }
                puts("");
            }
        }
    }
    return 0;
}
