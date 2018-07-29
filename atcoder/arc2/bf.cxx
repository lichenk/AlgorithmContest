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
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s; cin>>s;
	ll n=s.length();
	ll h[26];
	for (ll x=0;x<n;x++) {
		for (ll y=x+1;y<n;y++) {
			for (ll c=0;c<26;c++) h[c]=0;
			ll len=y-x+1;
			for (ll k=x;k<=y;k++) {
				h[s[k]-'a']++;
			}
			for (ll c=0;c<26;c++) {
				if (h[c]>len/2) {
					printf("%lld %lld\n",x+1,y+1);
					return 0;
				}
			}
		}
	}
	printf("-1 -1\n");
}