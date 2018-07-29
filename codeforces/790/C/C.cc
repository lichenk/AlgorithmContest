#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e9+5;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const ll ISA=0,ISV=1,ISK=2;
ll n; string s;
const ll mn=75+2;
const ll mc=3;
ll dp[mn][mn+mn][mn+mn][mc];
ll f(ll x, ll ov, ll ok, ll c) {
	if (x==-1) {
		if (ov==0&&ok==0) return 0;
		else return INF;
	}
	ll dpv=dp[x][mn+ov][mn+ok][c];
	if (dpv!=-1) return dpv;
	ll oa=-(ok+ov);
	ll nv=ov,nk=ok,na=oa;
	if (c==ISA) --na;
	if (c==ISV) --nv;
	if (c==ISK) --nk;
	if (s[x]=='V') ++nv;
	else if (s[x]=='K') ++nk;
	else ++na;
	pll best=MP(INF,-1ll);
	for (ll pc=0;pc<3;pc++) {
		if (pc==ISV&&c==ISK) continue;
		ll cand=f(x-1,nv,nk,pc);
		ll cost=abs(nv)+abs(nk)+abs(na);
		if (pc==ISA&&c!=ISA) cost+=abs(nv)*abs(nk)*2;
		chkmin(best,MP(cand+cost,pc));
	}
	dp[x][mn+ov][mn+ok][c]=best.fst;
	//printf("x:%d ov:%d ok:%d c:%d best:%d. pc:%d nv:%d nk:%d\n",x,ov,ok,c,best.fst,best.snd,nv,nk);
	return best.fst;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	memset(dp,-1,sizeof dp);
	cin>>n>>s;
	ll ans=INF;
	for (ll c=0;c<3;c++) {
		ll cand=f(n-1,0,0,c);
		chkmin(ans,cand);
		//printf("c:%d cand:%d\n",c,cand);
	}
	assert(ans%2==0);
	ans/=2;
	printf("%d\n",ans);
}

