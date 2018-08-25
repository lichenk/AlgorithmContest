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
const int mn=1e5+4;
int vv[mn],vt[mn];
ll pret[mn];
ll query(int l, int r) {
	if (l>r) return 0;
	return pret[r]-pret[l-1];
}
ll vfull[mn];
ll vpart[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=1;i<=n;i++) vv[i]=rint();
  for (int i=1;i<=n;i++) vt[i]=rint();
  for (int i=1;i<=n;i++) pret[i]=pret[i-1]+vt[i];
  for (int d=1;d<=n;d++) {
  	int imin=d,imax=n+1;
  	while(imin<imax) {
  		int imid=(imin+imax)>>1;
  		if (query(d,imid)<=vv[d]) imin=imid+1;
  		else imax=imid;
  	}
  	if (d<=imax) {
  		vfull[d]++;
  		vfull[imax]--;
  		vpart[imax]+=(vv[d]-query(d,imax-1));
  	}
  }
  for (int d=1;d<=n;d++) vfull[d]+=vfull[d-1];
  for (int d=1;d<=n;d++) {
  	ll ans=vfull[d]*vt[d] + vpart[d];
  	printf("%lld ",ans);
  }
  printf("\n");

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