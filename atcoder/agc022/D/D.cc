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
typedef vector<int> vi;
 
ll geta(ll x, ll t, ll L) {
	ll odd=((t-2*x+2*L-1)/(2*L))*2 + 1;
	ll even=((t+2*L-1)/(2*L))*2;
	return min(odd,even);
}
ll getcost(ll L, ll x, ll t, ll out) {
	ll fa[2];
	fa[0]=geta(L-x,t,L);
	fa[1]=geta(x,t,L);
	if (out==0) {
		ll ans=min(fa[0],fa[1]); if (ans&1) ans++;
		return ans;
	}
	else if (out==-1) { // L2R
		return fa[1]|1;
	}
	else if (out==1) { // R2L
		return fa[0]|1;
	}
	else assert(0);
}
const int L2R=-1;
const int ZERO=0;
const int ANY=-123;
const int R2L=1;
void solve(long long N, long long L, vector<long long> vx, vector<long long> vt){
	ll final=0;
	ll lo=0,hi=0,cost=0;
	for (ll i=N-1;i>=0;i--) {
		ll x=vx[i],t=vt[i];
		ll hicost;
		ll newhi;
		{
			pll best=MP(INF,INF);
			for (ll out=-1;out<=1;out++) {
				if (hi+out>=1) {
					chkmin(best,MP(getcost(L,x,t,out),-out));
				}
			}
			ll out=-best.snd;
			newhi=hi+out;
			hicost=best.fst;
			cost+=hicost;
			//printf("out:%lld hicost:%lld\n",out,hicost);
		}
		{
			ll res=INF;
			for (ll out=-1;out<=1;out++) {
				ll tmplo=lo;
				while(tmplo+out<1&&tmplo+1<=hi) {
					tmplo+=1;
				}
				if (tmplo+out>=1) {
					ll newcost=getcost(L,x,t,out);
					if (newcost<=hicost) {
						//printf("lo:%lld tmplo:%lld out:%lld\n",lo,tmplo,out);
						assert(newcost==hicost);
						chkmin(res,tmplo+out);
					}
				}
			}
			assert(res<INF);
			lo=res;
		}
		hi=newhi;
		assert(lo<=hi);
	}
	ll delta=min(abs(lo-1),abs(hi-1));
	final++;
	final+=delta;
	final+=cost;
	if (final&1) final++;
	ll finalans=final*L;
	printf("%lld\n",finalans);
}
 
int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long N;
	long long L;
	scanf("%lld",&N);
	vector<long long> t(N-1+1);
	vector<long long> x(N-1+1);
	scanf("%lld",&L);
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&x[i]);
	}
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&t[i]);
	}
	solve(N, L, x, t);
	return 0;
}
