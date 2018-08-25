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
#define assert(...) /* nothing */
#endif

// printf("Case #%d: %lld\n",casenum,ans);
void solve(int casenum) {
	int r,b,c; cin>>r>>b>>c;
	vector<int> vm,vs,vp;
	vm.resize(c); vs.resize(c); vp.resize(c);
	for (int i=0;i<c;i++) {
		cin>>vm[i]>>vs[i]>>vp[i];
	}
	ll imin=0,imax=LLONG_MAX-2;
	vector<ll> a; a.resize(c);
	while(imin<imax) {
		ll imid=imin+(imax-imin)/2;
		for (int i=0;i<c;i++) {
			ll have=(imid-(ll)vp[i])/(ll)vs[i];
			ll realhave=min(have,(ll)vm[i]);
			a[i]=realhave;
		}
		sort(a.begin(),a.end(),greater<ll>());
		bool ok=false;
		ll sum=0;
		for (int i=0;i<r;i++) {
			sum+=a[i];
			if (sum>=b) {ok=true; break;}
		}
		if (!ok) imin=imid+1;
		else imax=imid;
	}
	printf("Case #%d: %lld\n",casenum,imin);
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int T; cin>>T;
  for (int i=1;i<=T;i++) {
    solve(i);
  }
}
