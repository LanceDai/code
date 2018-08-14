#include<bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define rep(i, a, n) for (int i = a; i < n; i++)
#define mm(arr, val) memset(arr, val, sizeof(arr))

using namespace std;
typedef long long LL;

const int N = 20;

const int MAX = 1e3;
bool notprime[MAX];
int prime[MAX];
int phi[MAX];

void get_Eular() {
    int cnt = 0;
    for (int i = 2; i < MAX; i++) {
        if (!notprime[i]) {
            prime[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < cnt && i * prime[j] < MAX; j++) {
            notprime[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
}

//快速幂取法a的b次方求余p
LL pow_mod(LL a, LL b, LL p) {
    LL ans = 1;
    while (b) {
        if (b & 1)
            ans = (ans * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return ans;
}

//费马小定理求a关于p的逆元
LL Fermat(LL a, LL p) {
    return pow_mod(a, p - 2, p);
}

int main() {
#ifdef ONLINE_JUDGE
#else
//    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\in)", "r", stdin);
//    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\out)", "w", stdout);
#endif
    int t;
    cin >> t;
    phi[1] = 1;
    get_Eular();
    while (t--) {
        int m, n, p, ans = 0;
        cin >> m >> n >> p;
        if(m > n) swap(m, n);
        for (int i = 1; i <= m; ++i) {
            if(i == 1) ans += n;
            else if(){

            }
            while (ans > p) ans -= p;
        }
    }

    return 0;
}
