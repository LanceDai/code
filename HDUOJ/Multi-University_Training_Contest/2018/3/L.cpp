#include<bits/stdc++.h>

using namespace std;
char str[150][150];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int w = 2 * a + 1 + 2 * b;
        int h = 2 * c + 1 + 2 * b;

        for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) str[i][j] = '.';

        for (int i = 0; i < 2 * b; i++) {
            for (int j = w - i - 1; j >= w - i - (2 * a + 1); j--) {
                if (i % 2 == 0)
                    if (j % 2 == 0) str[i][j] = '+';
                    else str[i][j] = '-';
                else if (j % 2 == 0) str[i][j] = '.';
                else str[i][j] = '/';
            }
        }
        for (int i = 2 * b; i < h; i++) {
            for (int j = 0; j < 2 * a + 1; j++) {
                if (i % 2 == 0)
                    if (j % 2 == 0) str[i][j] = '+';
                    else str[i][j] = '-';
                else if (j % 2 == 0) str[i][j] = '|';
                else str[i][j] = '.';
            }
        }
        for (int j = w - 1; j >= 2 * a + 1; j--) {
            for (int i = w - j; i < w - j + 2 * c; i++) {
                str[i][j] = '*';
                if (j % 2 == 0)
                    if (i % 2 == 0) str[i][j] = '+';
                    else str[i][j] = '|';
                else if (i % 2 == 0) str[i][j] = '.';
                else str[i][j] = '/';
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) cout << str[i][j];
            cout << endl;
        }
    }
    return 0;
}