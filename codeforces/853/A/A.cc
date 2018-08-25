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
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
const int mn=3e5+4;
pii c[mn];
int vans[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),k=rint();
  for (int i=1;i<=n;i++) c[i]=MP(-rint(),i);
  sort(c+1,c+n+1);
	set<int> s;
	for (int x=1;x<=n;x++) s.insert(x+k);
	ll ans=0;
	for (int j=1;j<=n;j++) {
		int cc=c[j].fst;
		int i=c[j].snd;
		auto it=s.lower_bound(i);
		int t=*it;
		//printf("i:%d t:%d")
		ans+=(i-t)*(ll)cc;
		vans[i]=t;
		s.erase(it);
	}
	printf("%lld\n",ans);
	for (int x=1;x<=n;x++) printf("%d ",vans[x]);
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