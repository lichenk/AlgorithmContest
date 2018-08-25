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

int go(vector<int> v) {
	int n=v.size();
	if (n==1) return 0;
	int final=1e9;
	for (int i=0;i<n;i++) {
		for (int j=0;j<i;j++) {
			//printf("i:%d j:%d\n",i,j);
			int add=v[i]*v[j];
			vector<int> nv;
			for (int x=0;x<n;x++) {
				if (i==x||j==x) continue;
				nv.PB(v[x]);
			}
			nv.PB(v[i]+v[j]);
			//for (auto &w:nv) printf("%d,",w); printf("\n");
			int cand=go(nv)+add;
			chkmin(final,cand);
		}
	}
	return final;
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll k; cin>>k;
  if (k==0) {
  	printf("a\n"); return 0;
  }
  char c='a';
  while(k>0) {
  	ll imin=0,imax=1000;
  	while(imin<imax) {
  		ll imid=(imin+imax)/2;
  		if ((imid*(imid-1))/2<=k) imin=imid+1;
  		else imax=imid;
  	}
  	ll x=imin-1;
  	ll take=(x*(x-1))/2;
  	//printf("x:%lld take:%lld\n",x,take);
  	k-=take;
  	for (int i=0;i<x;i++) putchar(c);
  	c++;
  }
	putchar('\n');
  //for (int x=1;x<=20;x++) {
  //	vi v; for (int i=0;i<x;i++) v.PB(1);
  //	printf("x:%d go:%d\n",x,go(v));
  //}
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