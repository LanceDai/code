#include <bits/stdc++.h>

using namespace std;
typedef pair<pair<int, int>, int> Point;

int main() {
    ios_base::sync_with_stdio(false);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        n *= 3;
        vector<Point> points(n);
        for (int i = 0; i < n; ++i) {
            cin >> points[i].first.first >> points[i].first.second;
            points[i].second = i + 1;
        }
        sort(points.begin(), points.end());
        for (int i = 0; i < n; ++i)
            cout << points[i].second << ' ';
        cout << endl;
    }
    return 0;
}
