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
ll f[41][1<<18];
ll wf[41];
int main() {
	ll xt,yt,zt;
	ll n; scanf("%lld %lld %lld %lld",&n,&xt,&yt,&zt);
	ll xlim=xt,ylim=yt,zlim=zt;
	ll logs=xlim+ylim+zlim+1;
	ll slim=1<<logs;
	f[0][1]=1;
	wf[0]=2;
	wf[1]=2;
	wf[2]=2;
	wf[3]=1;
	for (ll p=0;p<n;p++) {
		for (ll s=0;s<slim;s++) {
			if (f[p][s]==0) continue;
			for (ll d=1;d<=10;d++) {
			//{
			//	ll d=wf[p];
				ll ns=(1<<(xlim+ylim+zlim))&s;
				if (d<=xlim) ns|=1<<d;
				for (ll x=0;x<xlim;x++) {
					if (s&(1<<x)) if (x+d<=xlim) ns|=1<<(x+d);
				}
				for (ll y=0;y<ylim;y++) {
					if (s&(1<<(y+xlim))) if (y+d<=ylim) ns|=1<<(y+d+xlim);
				}
				for (ll z=0;z<zlim;z++) {
					if (s&(1<<(z+xlim+ylim))) if (z+d<=zlim) ns|=1<<(z+d+xlim+ylim);
				}
				//cout<<p<<": "<<bitset<8>(s)<<" to " << bitset<8>(ns) << " : " << f[p][s] << endl;
				f[p+1][ns]+=f[p][s];
				f[p+1][ns]%=MOD;
			}
		}
	}
	ll ans=0;
	for (ll s=0;s<slim;s++) {
		if ((1<<(xlim+ylim+zlim))&s) {
			ans+=f[n][s];
			ans%=MOD;
		}
	}
	printf("%lld\n",ans);
}