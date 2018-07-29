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
	for (ll c=0;c<26;c++) {
		char ch='a'+c;
		ll h=0;
		pair<ll,ll> lo=MP(0LL,0LL);
		for (ll x=0;x<n;x++) {
			h--;
			if (s[x]==ch) h+=2;
			if (h>lo.first&&lo.second!=x) {
				printf("%lld %lld\n",lo.second+1,x+1);
				return 0;
			}
			chkmin(lo,MP(h,x+1));
		}
	}
	printf("-1 -1\n");
}
