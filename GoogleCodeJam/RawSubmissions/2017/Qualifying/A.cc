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
ll a[1000000+4];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll numtests; cin>>numtests;
	for (ll testnum=1;testnum<=numtests;testnum++) {
		string s; ll k; cin>>s>>k;
		ll n=s.length();
		for (ll x=0;x<n;x++) {
			a[x]=s[x]=='+'?1:0;
		}
		ll ans=0;
		for (ll x=0;x<n;x++) {
			if (a[x]==0&&x+k<=n) {
				ans++;
				for (ll y=x;y<x+k;y++) {
					a[y]^=1;
				}
			}
		}
		bool ok=true;
		for (ll x=0;x<n;x++) {
			if (a[x]==0) ok=false;
		}
		if (ok) cout<<"Case #"<<testnum<<": "<<ans<<endl;
		else cout<<"Case #"<<testnum<<": "<<"IMPOSSIBLE"<<endl;
	}
}

