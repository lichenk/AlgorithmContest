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
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s; cin>>s;
	ll n=s.length();
	ll zlim=1LL<<(n-1);
	ll ans=0;
	for (ll z=0;z<zlim;z++) {
		ll sum=0;
		ll cur=s[0]-'0';
		for (ll x=0;x<n-1;x++) {
			if (z&(1LL<<x)) {
				sum+=cur;
				cur=s[x+1]-'0';
			}
			else {
				cur*=10;
				cur+=s[x+1]-'0';
			}
		}
		sum+=cur;
		ans+=sum;
	}
	cout<<ans<<endl;
}