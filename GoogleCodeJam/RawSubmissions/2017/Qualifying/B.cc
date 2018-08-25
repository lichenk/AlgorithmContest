#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef __int128 lt;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=3e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const ll maxd=20;
ll limdig[maxd+5];
lt powten[maxd+5];
const ll LESS=0,EQ=1,GR=2;

ll trans(ll state, ll dig, ll diglim) {
	if (dig<diglim) return LESS;
	if (state==LESS) return LESS;
	if (dig==diglim&&state==EQ) return EQ;
	if (state==EQ&&dig>diglim) return GR;
	assert(false);
}

lt dp[maxd][2][10];
lt f(ll pos, ll state, ll lastdig) {
	if (pos==-1) {
		if (state==LESS) return 0;
		else return -1;
	}
	lt dpval=dp[pos][state][lastdig];
	if (dpval!=-2) return dpval;
	lt ans=-1;
	for (ll dig=lastdig;dig<=9;dig++) {
		ll newstate=trans(state,dig,limdig[pos]);
		//printf("dig:%lld limdig:%lld state:%lld newstate:%lld\n",dig,limdig[pos],state,newstate);
		if (newstate!=GR) {
			lt got=f(pos-1,newstate,dig);
			if (got!=-1) {
				lt cand=dig*powten[pos] + got;
				chkmax(ans,cand);
			}
		}
	}
	return dp[pos][state][lastdig]=ans;
}
lt solve(ll x) {
	for (ll i=0;i<maxd;i++) for (ll j=0;j<2;j++) for (ll k=0;k<10;k++) dp[i][j][k]=-2;
	x++;
	memset(limdig,0,sizeof limdig);
	for (ll i=0;i<maxd;i++) {
		limdig[i]=x%10;
		x/=10;
	}
	lt ans=f(maxd-1,EQ,0);
	return ans;
}
int main() 
{
	lt a=1;
	for (ll x=0;x<maxd;x++) {
		powten[x]=a;
		a*=10;
	}
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll numtests; cin>>numtests;
	for (ll testnum=1;testnum<=numtests;testnum++) {
		ll x; cin>>x;
		ll ans=solve(x);
		cout<<"Case #"<<testnum<<": "<<ans<<endl;
	}
}

