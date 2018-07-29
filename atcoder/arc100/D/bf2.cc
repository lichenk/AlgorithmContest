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
const int mn=2e5+4;
const int md=6;
const int me=md*2+1;
const int mz=me*me*me;
int a[mn];
ll pre[mn];
ll vt[4];
int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",a+i);
	for (int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	ll final=LLONG_MAX;
	for (int t=0;t<500000;t++) {
		if (0==(t&0xf)) srand(clock());
		int pos=1;
		bool ok=1;
		for (int k=0;k<3;k++) {
			int den=n-pos+1;
			if (den<=0) {ok=0; break;}
			int x=(rand()%(den))+1;
			//printf("k:%d x:%d\n",k,x);
			vt[k]=pre[pos+x-1]-pre[pos-1];
			pos+=x;
		}
		if (!ok) continue;
		vt[3]=pre[n]-pre[pos-1];
		ll imin=LLONG_MAX,imax=LLONG_MIN;
		for (int k=0;k<4;k++) {
			if (vt[k]==0) ok=0;
			chkmin(imin,vt[k]);
			chkmax(imax,vt[k]);
		}
		if (!ok) continue;
		chkmin(final,imax-imin);
	}
	printf("%lld\n",final);
	return 0;
}

