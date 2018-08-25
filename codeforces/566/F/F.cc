#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

int rint()
{
  int x; scanf("%d",&x); return x;
}

const ll mn=1000*1000;
ll dp[mn+1];
int main()
{
	ll n=rint();
	for (ll i=0;i<n;i++) {
		ll x=rint();
		dp[x]++;
	}
	ll final=0;
	for (ll x=mn;x>=1;x--) {
		if (dp[x]) {
			ll ans=0;
			for (ll y=2*x;y<=mn;y+=x) {
				chkmax(ans,dp[y]);
			}
			ans+=dp[x];
			dp[x]=ans;
			chkmax(final,ans);
		}
	}
	printf("%d\n",final);
}

