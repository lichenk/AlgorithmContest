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
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
bool vd[10];
int main() {
	for (ll i=0;i<10;i++) vd[i]=false;
	ll n,k; scanf("%lld %lld",&n,&k);
	for (ll i=0;i<k;i++) {
		ll d; scanf("%lld",&d); vd[d]=true;
	}
	for (ll x=n;;x++) {
		string s=to_string(x);
		bool ok=true;
		for (auto &c:s) {
			if (vd[c-'0']) {ok=false; break;}
		}
		if (ok) {
			printf("%lld\n",x);
			return 0;
		}
	}
}