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
const int md=107;
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
	ll avg=pre[n]/4;
	ll final=LLONG_MAX;
	for (int zz=0;zz<mz;zz++) {
		int z=zz;
		int pos=1;
		for (int k=0;k<3;k++) {
			int r=(z%me)-md; z/=me;
			int imin=pos,imax=n+1;
			while(imin<imax) {
				int imid=(imin+imax)>>1;
				ll got=pre[imid]-pre[pos-1];
				if (got<avg) imin=imid+1;
				else imax=imid;
			}
			int want=imin+r;
			chkmin(want,n-(3-k));
			chkmax(want,pos);
			vt[k]=pre[want]-pre[pos-1];
			pos=want+1;
		}
		vt[3]=pre[n]-pre[pos-1];
		ll imin=LLONG_MAX,imax=LLONG_MIN;
		for (int k=0;k<4;k++) {
			//printf("k:%d\n",k); exit(0);
			assert(vt[k]!=0);
			chkmin(imin,vt[k]);
			chkmax(imax,vt[k]);
		}
		chkmin(final,imax-imin);
	}
	printf("%lld\n",final);
	return 0;
}

