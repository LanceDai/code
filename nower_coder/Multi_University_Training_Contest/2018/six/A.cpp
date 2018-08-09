#include <bits/stdc++.h>
using namespace std;
typedef long long  LL;
const int MAXN = 2e+5;
struct Node{
    int index;
    vector<LL> song_val;
};

int main(){
#ifndef ONLINE_JUDGE
    freopen("/home/lance/CLionProjects/code/nower_coder/Multi_University_Training_Contest/2018/six/input.txt", "r+", stdin);
//    freopen("data.out", "w+", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, n;
    queue<Node> node_queue;
    LL val;
    cin >> T;
    for (int i = 1; i <= T ; ++i) {
        cin >> n;
        for (int j = 1; j <= pow(2, n) ; ++j) {
            Node node;
            for (int k = 0; k < n; ++k) {
                cin >> val;
                node.song_val.push_back(val);
            }
            sort(node.song_val.begin(), node.song_val.end());
            node.index = j;
            node_queue.push(node);
        }
        while (node_queue.size() != 1){
            Node a = node_queue.front();
            node_queue.pop();
            Node b = node_queue.front();
            node_queue.pop();
            if((*(a.song_val.end() - 1)) > (*(b.song_val.end() - 1))){
                a.song_val.erase(lower_bound(a.song_val.begin(), a.song_val.end(), *(b.song_val.end() - 1)));
                node_queue.push(a);
            }else{
                b.song_val.erase(lower_bound(b.song_val.begin(), b.song_val.end(), *(a.song_val.end() - 1)));
                node_queue.push(b);
            }
        }
        Node ans = node_queue.front();
        node_queue.pop();
        cout << "Case #" << i << ": " << ans.index << endl;
    }
    return 0;
}