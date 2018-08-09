#include <bits/stdc++.h>

using namespace std;
short query[205][205];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, n, flag_1, flag_0, count;
    cin >> T;
    while (T--) {
        memset(query, 0, sizeof(query));
        cin >> n;
        if (n % 2 == 0) {
            cout << "possible\n";
            count = 0;
            for (int i = 0; i < n; ++i) {
                flag_1 = flag_0 = 0;
                if(i % 2 == 0){
                    for (int j = 0; j < n; ++j) {
                        if(j == count) {
                            query[i][j] = 1;
                            flag_1 = 1;
                        }
                        else if(j == count + 1) {
                            query[i][j] = 0;
                            flag_0 = 1;
                        }
                        else {
                            if(flag_0 && flag_1) query[i][j] = 1;
                            else{
                                if(j % 2 == 1) query[i][j] = -1;
                                else query[i][j] = 1;
                            }
                        }
                    }
                }else{
                    for (int j = 0; j < n; ++j) {
                        if(j < count){
                            if(j % 2 == 1) query[i][j] = -1;
                            else query[i][j] = 1;
                        }else if(j == count) query[i][j] = 1;
                        else  query[i][j] = -1;
                    }
                    count += 2;
                }
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n - 1; ++j) cout << query[i][j] << ' ';
                cout << query[i][n - 1] << endl;
            }
        } else cout << "impossible" << endl;
    }
    return 0;
}
