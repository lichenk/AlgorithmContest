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
ll n,t;
ll pat[16];
ll dp[8+2][2][17][(1<<16)+2];
const ll LS=0,EQ=1,GR=2;
ll trans(ll prev, ll now) {
	if (prev==EQ) return now;
	else return prev;
}
ll f(ll k, ll state, ll chance, ll z) {
	ll val=dp[k][state][chance][z];
	if (val!=UNDEF) return val;
	if (k==8) return 1;
	ll ans=0;
	for (ll d=0;d<16;d++) {
		ll now;
		if (d<pat[k]) now=LS;
		else if (d==pat[k]) now=EQ;
		else now=GR;
		ll ns=trans(state,now);
		if (ns==GR) continue;
		ll msk=1LL<<d;
		if (0!=(msk&z)) {
			if (chance==16) {
				ans+=f(k+1,ns,d,z);
			}
		}
		else {
			ll nz=z;
			if (!(z==0&&d==0)) nz|=msk;
			ans+=f(k+1,ns,chance,nz);
		}
	}
	//printf("k:%lld state:%lld chance:%lld z:%lld ans:%lld\n",k,state,chance,z,ans);
	return dp[k][state][chance][z]=ans;
}
ll go(ll x) {
	ll chance=(t==2)?16:0;
	for (ll i=7;i>=0;i--) {
		pat[i]=x&0xf;
		x>>=4;
	}
	memset(dp,-1,sizeof dp);
	return f(0,EQ,chance,0)-1;	
}
void solve1() {
	ll imin=0,imax=1LL<<32LL;
	while(imin<imax) {
		ll imid=(imin+imax)/2;
		ll got=go(imid);
		if (got<n) imin=imid+1;
		else imax=imid;
	}
	printf("%llx\n",imin);
}
void solveo() {
	vector<ll> comb;
	for (ll x=0;x<(1<<8);x++) {
		if (__builtin_popcountll(x)==t+1) {
			comb.PB(x);
		}
	}
	ll zlim=1<<(32-4*(t+1));
	//printf("SIZE: %lld*%lld*16=%lld\n",comb.size(),zlim,16*comb.size()*zlim);
	//return;
	vector<ll> vv;
	for (auto &w:comb) {
		for (ll c=0;c<16;c++) {
			for (ll z=0;z<zlim;z++) {
				ll x=0;
				bool bad=false;
				for (ll k=0;k<8;k++) {
					x<<=4;
					if ((1<<k)&w) {
						x|=c;
						if (x==0) {bad=true; break;}
					}
					else {
						x|=z&0xf;
						z>>=4;
					}
				}
				if (!bad) vv.PB(x);
			}
		}
	}
	sort(vv.begin(),vv.end());
	ll imin=0,imax=1LL<<32LL;
	while(imin<imax) {
		ll imid=(imin+imax)/2;
		ll amin=0,amax=vv.size();
		while(amin<amax) {
			ll amid=(amin+amax)/2;
			if (vv[amid]<=imid) amin=amid+1;
			else amax=amid;
		}
		ll le=amin;
		ll have=imid-le;
		if (have<n) imin=imid+1;
		else imax=imid;
	}
	printf("%llx\n",imin);
}
int main() 
{
	//ll x; cin>>x;
	//t=2;
	//cout<<go(x)<<endl;
	//return 0;
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>n>>t;
	if (t==1||t==2) {
		solve1();
	}
	else {
		solveo();
	}
}

