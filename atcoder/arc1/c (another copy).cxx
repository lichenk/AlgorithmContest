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
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
ll f[41][1<<20];
int main() {
	ll xlim,ylim,zz;
	ll n; scanf("%lld %lld %lld %lld",&n,&xlim,&ylim,&zz);
	xlim++;ylim++;zz++;
	ll logs=xlim+ylim+zz;
	ll slim=1<<logs;
	f[0][1]=1;
	for (ll p=0;p<n;p++) {
		for (ll z=0;z<zlim;z++) {
			for (ll d=1;d<10;d++) {
				ll nz=0;
				nz|=1<<d;
				for (ll x=0;x<xlim;x++) {
					if (z&(1<<x)) {
						if (x+d<xlim) nz|=1<<(x+d);
						if (x+d==xlim-1) nz|=1<<xlim;
					}
				}
			}
		}
	}
}