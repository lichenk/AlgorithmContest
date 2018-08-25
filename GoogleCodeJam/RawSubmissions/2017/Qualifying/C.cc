#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
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
pll f(ll n, ll k) {
	//printf("n:%d k:%d\n",n,k);
	if (k==1) {
		return MP(n/2,(n-1)/2);
	}
	ll l=(n-1)/2,r=n/2;
	// Start with r. Odd goes to r
	k--;
	if (k%2==1) {
		return f(r, (k+1)/2);
	}
	else {
		return f(l, k/2);
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll numtests; cin>>numtests;
	for (ll testnum=1;testnum<=numtests;testnum++) {
		ll n,k; cin>>n>>k;
		pll ans=f(n,k);
		cout<<"Case #"<<testnum<<": "<<ans.fst<<" "<<ans.snd<<endl;
	}
}

