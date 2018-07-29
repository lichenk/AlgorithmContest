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
const ll MAXL=100000;
ll f[41][1<<3][MAXL];
ll reach[5];
bool rchk[3][MAXL];
int main() {
	ll n; scanf("%lld %lld %lld %lld",&n,&reach[0],&reach[1],&reach[2]);
	for (ll t=0;t<3;t++) {
		for (ll k=0;k<MAXL;k++) rchk[t][k]=false;
		for (ll k=0;k<MAXL;k++) {
			for (ll d=10;d<=MAXL;d*=10) {
				ll sum=0;
				ll x=k%d;
				while(x>0) {
					sum+=x%10;
					x/=10;
				}
				if (sum==reach[t]) rchk[t][k]=true;
			}
		}
	}
	f[0][0][0]=1;
	for (ll p=0;p<n;p++) {
		for (ll s=0;s<(1<<3);s++) {
			for (ll k=0;k<MAXL;k++) {
				if (f[p][s][k]==0) continue;
				for (ll d=1;d<10;d++) {
					ll nk=(k*10+d)%MAXL;
					ll got=0;
					for (ll t=0;t<3;t++) {
						if (rchk[t][nk]) got|=1<<t;
					}
					ll ns=trans[s][got];
					if (rchk[t][nk]) {
						f[p+1][t+1][0]+=f[p][s][k];
					}
					else {
						f[p+1][t][nk]+=f[p][s][k];
					}
				}
			}
		}
	}
	ll ans=f[n][(1<<3)-1][0];
	printf("%lld\n",ans);
}