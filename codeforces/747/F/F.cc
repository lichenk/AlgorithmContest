#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
const ll mn=9;
ll pat[mn];
const ll md=16;
const ll LS=0,EQ=1,GR=2;
ll dp[md][3][mn];
ll t;
//16*3*(2**9)*9*9
ll f(ll digit, ll comp, ll equals, ll len)
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; cin>>n>>t;
	ll imin=0,imax=1LL<<(4*mn);
	while(imin<imax) {
		ll imid=(imin+imax)/2;
		ll x=imid;
		for (ll i=0;i<mn;i++) {
			pat[i]=x&0xf;
			x>>=4;
		}
		ll cnt=f(15,EQ,0);
		if (cnt<n) imin=imid+1;
		else imax=imid;
	}
	printf("%llx\n",imin);
}

