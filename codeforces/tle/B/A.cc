#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef double ld;
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
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
ll gz;
const int LIM=10;
const int EST=100;
bool isabove(ld x, int y) {
	if (x>=gz) return true;
	ld ans=x;
	for (int i=1;i<y;i++) {
		ans=pow(x,ans);
		if (ans>=gz) return true;
	}
	return false;
}
ld solve(int y, ll z) {
	gz=z;
	ld imin=1e-9,imax=(y==2)?10:3;
	int lim=(y==2)?26:24;
	for (int k=0;k<lim;k++) {
		ld imid=(imin+imax)/2;
		bool got=isabove(imid,y);
		if (!got) imin=imid;
		else imax=imid;
	}
  return imin;
}
vector<ld> v[101];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  for (ld x=1;x<=1.53520024+5e-6;x+=25e-7) {
  	ld ans=x;
  	//printf("%f ",x);
  	for (int y=2;y<=100;y++) {
  		ans=pow(x,ans);
  		if (y>=LIM) v[y].PB(ans);
  	}
  }
  int q; cin>>q;
  for (int i=0;i<q;i++) {
  	int y; ll z; cin>>y>>z;
  	ld ans;
  	if (y<LIM) {
  		ans=solve(y,z);
  	}
  	else {
  		int imin=0,imax=v[y].size();
  		while(imin<imax) {
  			int imid=(imin+imax)>>1;
  			if (v[y][imid]<z) imin=imid+1;
  			else imax=imid;
  		}
  		//printf("z:%lld imin:%d vysz:%d\n",z,imin,v[y].size());
  		ans=1 + 25e-7 * imin;
  	}
  	printf("%.7f\n",(double)ans);
  }
}

int rint()
{
	int x; scanf("%d",&x); return x;
}
