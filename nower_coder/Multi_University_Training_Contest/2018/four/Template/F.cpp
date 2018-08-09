#include <cstdio>
#include <algorithm>

using namespace std;
const int MAXN = 2000 + 10;
char query[MAXN][MAXN];
int MAXN, M;

bool check(int x, int y) {
    return query[x][y] == query[x][M - y - 1] && query[x][y] == query[MAXN - x - 1][y] &&
           query[x][y] == query[MAXN - x - 1][M - y - 1];
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &MAXN, &M);
        for (int i = 0; i < MAXN; ++i) {
            scanf("%s", query[i]);
        }
        int x = MAXN / 2 - 1, y = M / 2 - 1;
        for (int i = 0; i < MAXN / 2; ++i) {
            for (int j = 0; j < M / 2; ++j) {
                if (!check(i, j)) {
                    x = std::min(x, i), y = std::min(y, j);
                }
            }
        }
        printf("%d\n", x * y);
    }
    return 0;
}
