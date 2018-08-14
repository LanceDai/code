#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
typedef long long LL;
using namespace std;
const int MAXN = 100;
LL ans;

struct Node {
    LL pos, lastVal, tmp_ans;
};
namespace io {
    const int L = (1 << 21) + 1;
    char ibuf[L], *iS, *iT, obuf[L], *oS = obuf, *oT = obuf + L - 1, c, st[55];
    int f, tp;
#define gc() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,L,stdin),(iS==iT?EOF:*iS++)):*iS++)

    inline void flush() {
        fwrite(obuf, 1, oS - obuf, stdout);
        oS = obuf;
    }

    inline void putc(char x) {
        *oS++ = x;
        if (oS == oT) flush();
    }

    template<class I>
    inline void gi(I &x) {
        for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
        for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15);
        x *= f;
    }

    template<class I>
    inline void print(I x) {
        if (!x) putc('0');
        if (x < 0) putc('-'), x = -x;
        while (x) st[++tp] = x % 10 + '0', x /= 10;
        while (tp) putc(st[tp--]);
    }

    inline void gs(char *s, int &l) {
        for (c = gc(); c < 'a' || c > 'z'; c = gc());
        for (l = 0; c <= 'z' && c >= 'a'; c = gc()) s[l++] = c;
        s[l] = 0;
    }

    inline void ps(const char *s) { for (int i = 0, n = strlen(s); i < n; i++) putc(s[i]); }

    struct IOFLUSHER {
        ~IOFLUSHER() { flush(); }
    } _ioflusher_;
};

int main() {
#ifndef ONLINE_JUDGE
    freopen(R"(D:\ACM\CLionProject\code\HDUOJ\Multi-University_Training_Contest\2018\7\input.txt)", "r", stdin);
//    freopen("data.ou", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    LL n, m, a, b, c;
    while (cin >> n >> m) {
        queue<Node> node_queue;
        map<LL, vector<LL> > roads;
        map<pair<LL, LL>, LL> visit;
        map<pair<LL, LL>, LL> graph;
        ans = INF;
        for (int i = 0; i < m; ++i) {
            io::gi(a);
            io::gi(b);
            io::gi(c);
//            cin >> a >> b >> c;
            graph[make_pair(a, b)] = c;
            graph[make_pair(b, a)] = c;
            roads[a].push_back(b);
            roads[b].push_back(a);
        }
        if (graph[make_pair(1, n)]) {
            cout << 1 << endl;
            continue;
        } else if (!m) {
            cout << -1 << endl;
        } else {
            Node start = {1, 0, 0};
            node_queue.push(start);
            while (!node_queue.empty()) {
                if (node_queue.front().tmp_ans >= ans) {
                    node_queue.pop();
                    continue;
                }
                Node tmp = node_queue.front();
                node_queue.pop();
                for (int i = 0; i < roads[tmp.pos].size(); ++i) {
                    LL next_point = roads[tmp.pos][i];
                    pair<int, int> line_tmp = make_pair(tmp.pos, next_point);
                    LL val = graph[line_tmp];
                    if (val && visit[line_tmp] != val) {
                        Node next{};
                        if (val != tmp.lastVal) {
                            next = {next_point, val, tmp.tmp_ans + 1};
                        } else {
                            next = {next_point, val, tmp.tmp_ans};
                        }
                        visit[make_pair(tmp.pos, next_point)] = val;
                        if (next.pos == n) ans = min(ans, next.tmp_ans);
                        else node_queue.push(next);
                    }
                }
            }
            if (ans == INF) ans = -1;
            io::print(ans);
//            cout << ans << endl;
        }
    }
    return 0;
}