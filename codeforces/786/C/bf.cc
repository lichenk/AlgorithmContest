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
const ll mn=1e5+4;
ll a[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; cin>>n;
	for (ll i=1;i<=n;i++) cin>>a[i];	
	for (ll k=1;k<=n;k++) {
		ll x=1;
		ll ans=0;
		while(x<=n) {
			set<ll> s;
			while(x<=n&&s.size()<=k) {
				s.insert(a[x]);
				if (s.size()<=k) x++;
			}
			ans++;
		}
		printf("%lld ",ans);
	}
	printf("\n");
}

