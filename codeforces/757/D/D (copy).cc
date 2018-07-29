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
#define all(x) x.begin(),x.end()
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;

#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;
const ll dlim=20; // Exact without +1
const ll ylim=10; // Exact without +1
const ll zlim=1LL<<(dlim);
ll s[100];
ll f[2][ylim+1][zlim];
ll g[zlim];
ll len[dlim+1];
ll vneed[zlim];
void init() {
	for (ll x=1;x<=dlim;x++) {
		len[x]=64-__builtin_clzll(x);
	}
	for (ll z=0;z<zlim;z++) {
		bool on=false;
		ll need=0;
		for (ll x=dlim;x>=0;x--) {
			ll msk=1LL<<x;
			if (z&msk) {
				if (on) need+=len[x];
				on=true;
			}
		}
		vneed[z]=need;
	}
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	init();
	ll n; cin>>n;
	string _s; cin>>_s;
	for (ll x=0;x<n;x++) s[x]=(_s[n-1-x]=='1')?1:0;
	ll ans=0;
	ll cur=0,nxt=1;
	memset(f[0],0,sizeof f[0]);
	for (ll x=n-1;x>=0;x--) {
		memset(f[nxt],0,sizeof f[nxt]);
		memset(g,0,sizeof g);
		f[cur][0][0]++;
		ll dig=s[x];
		for (ll y=0;y<=ylim;y++) {
			ll ny=(y<<1)|dig;
			if (ny>dlim) continue;
			ll ycnt=len[y];
			for (ll z=0;z<zlim;z++) {
				ll v=f[cur][y][z];
				if (v==0) continue;
				if (x+ycnt<vneed[z]) continue;
				v%=MOD;
				if (ny>0){
					ll nz=z|(1LL<<(ny-1));
					g[nz]+=v;
				}
				if (ny<=ylim) {
					f[nxt][ny][z]+=v;
				}
			}
		}
		for (ll k=1;k<=dlim;k++) {
			ll z=(1LL<<k)-1;
			ll adder=g[z]%MOD;
			ans+=adder;
		}
		for (ll z=0;z<zlim;z++) {
			f[nxt][0][z]+=g[z];
		}
		ans%=MOD;
		swap(cur,nxt);
	}
	printf("%lld\n",ans%MOD);
}
