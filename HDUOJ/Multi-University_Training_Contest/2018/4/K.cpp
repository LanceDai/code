#include <bits/stdc++.h>

using namespace std;
int T;
char s[505];

int main() {
//#ifndef ONLINE_JUDGE
//    freopen("/home/lance/Documents/Tencent Files/603842325/FileRecv/最终版本/tests/k.in", "r+", stdin);
//    freopen("/home/lance/Documents/Tencent Files/603842325/FileRecv/最终版本/tests/out.out", "w+", stdout);
//#endif
    cin >> T;
    while (T--) {
        bool canflag = true;
        memset(s, 0, sizeof(s));
        cin >> s;
        if (s[0] == '+' || s[0] == '*') {
            canflag = false;
        }
        if (s[0] == '0' && s[1] - '0' >= 0 && s[1] - '0' <= 9) {
            canflag = false;
        }
        if (s[strlen(s) - 1] == '+' || s[strlen(s) - 1] == '*') {
            canflag = false;
        }
        for (int i = 1; i < strlen(s); ++i) {
            if (s[i - 1] == '+' || s[i - 1] == '*') {
                if (s[i] == '+' || s[i] == '*') {
                    canflag = false;
                    break;
                }
            }
            if (s[i - 1] == '0') {
                if (s[i] - '0' >= 0 && s[i] - '0' <= 9 && (s[i - 2] == '+' || s[i - 2] == '*')) {
                    canflag = false;
                    break;
                }
                if (i == strlen(s) - 1 && i >= 2 && (s[i - 2] == '+' || s[i - 2] == '*')) {
                    canflag = false;
                    break;
                }
            }
        }
        if (s[0] == '?') {
            s[0] = '1';
        }
        if (s[1] == '?') {
            s[1] = '1';
            if (s[0] == '0') {
                s[1] = '+';
                if (strlen(s) == 2) {
                    canflag = false;
                }
                if (s[2] == '+' || s[2] == '*') {
                    canflag = false;
                }
            }
        }

        for (int i = 2; i < strlen(s); ++i) {
            if (s[i] == '?') {
                if (s[i - 1] == '0' && (s[i - 2] == '+' || s[i - 2] == '*')) {
                    if (i + 1 < strlen(s) && (s[i + 1] == '+' || s[i + 1] == '*')) {
                        canflag = false;
                        break;
                    } else {
                        s[i] = '+';
                    }
                } else {
                    s[i] = '1';
                }
            }
        }
        if (canflag) {
            cout << s << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
}