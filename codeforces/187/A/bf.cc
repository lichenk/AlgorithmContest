#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000007;
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#ifdef ONLINE_JUDGE
#define assert(XXX) XXX
#else
#define DEBUG_CAT
#endif
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

const int mn=2e5+3;
int a[mn],b[mn],c[mn],inva[mn];
int n;
int go() {
  int ans=0;
  for (int x=1;x<=n;x++) {
    if (x==c[x]) {
      
    }
  }
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=1;i<=n;i++) a[i]=rint();
  for (int i=1;i<=n;i++) inva[a[i]]=i;
  for (int i=1;i<=n;i++) b[i]=rint();
  for (int i=1;i<=n;i++) {
  	c[i]=b[inva[i]];
  	//printf("%d ",c[i]);
  }
  //printf("\n");
  int ans=n+1;
  int need=1;
  for (int x=1;x<=n;x++) {
  	int y=c[x];
  	//printf("y:%d need:%d\n",y,need);
  	if (y==need) need++;
  	else if (y>need) {
  		//printf("ans:%d need:%d\n",ans,need);
  		chkmin(ans,y);
  	}
  }
  int final=n+1-ans;
  printf("%d\n",final);
}





int rint()
{
  int x; scanf("%d",&x); return x;
}
char rch()
{
  char x; scanf("%c",&x); return x;
}
long long rlong()
{
  long long x; scanf("%lld",&x); return x;
}