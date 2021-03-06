#include<assert.h>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<ctime>
#include<vector>
#include<stack>
#include<set>
#include<map>
#define File(S) freopen(S".in","r",stdin);freopen(S".out","w",stdout);
using namespace std;

typedef long long LL;

const int INF=2147483647;

LL getint()
{
    LL res=0,p=1;
    char ch=getchar();
    while ((ch<'0'||ch>'9') && ch!='-') ch=getchar();
    if (ch=='-') p=-1,ch=getchar();
    while (ch>='0'&&ch<='9') res=res*10+ch-'0',ch=getchar();
    return res*p;
}

int n,m,ans;
bool row[100050],column[100050];

int main()
{
    n=getint();
    m=getint();
	assert(1<=n&&n<=1e5);
	assert(0<=m&&m<=1e5);
    ans=n*2;
    int x,y;
    while (m--) {
        x=getint();
        y=getint();
		assert(1<=x&&x<=n);
		assert(1<=y&&y<=n);
        if (!row[x]) {
            row[x]=1;
            ans--;
        }
        if (!column[y]) {
            column[y]=1;
            ans--;
        }
    }
    if (n&1 && !row[n/2+1] && !column[n/2+1]) ans--;
    printf("%d\n",ans);
    return 0;
}
