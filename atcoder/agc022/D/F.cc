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
const int INF=1e9;
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
const int L2R=-1;
const int ZERO=0;
const int ANY=-123;
const int R2L=1;
int getcost(int in, int out) {
	if (in==ANY) {
		return min(abs(out-1),abs(out+1));
	}
	return abs(in-out);
}
void solve(long long N, long long L, vector<long long> vx, vector<long long> vt){
	ll final=0;
	vector<int> v;
	for (ll i=0;i<N;i++) {
		ll x=vx[i],t=vt[i];
		ll fa[2];
		fa[0]=geta(L-x,t,L);
		fa[1]=geta(x,t,L);
		int oldsz=v.size();
		if (fa[0]<fa[1]) { // move right dominant
			assert(fa[0]+1==fa[1]);
			ll g=fa[0];
			final+=g;
			if (g%2==1) { // no-op
				v.PB(R2L);
			}
		}
		else if (fa[0]>fa[1]) { // move left dominant
			assert(fa[0]==fa[1]+1);
			ll g=fa[1];
			final+=g;
			if (g%2==1) { // no-op
				v.PB(L2R);
			}
		}
		else {
			assert(fa[0]==fa[1]);
			if (fa[0]%2==0) {
				final+=fa[0];
			}
			else {
				final+=fa[0];
				v.PB(ANY);
			}
		}
		if (v.size()==oldsz) v.PB(ZERO);
	}
	reverse(v.begin(),v.end());
	ll lo=0,hi=0,cost=0;
	bool first=true;
	for (auto &t: v) {
		//printf("t:%d\n",t);
		int hicost;
		{
			pair<int,int> best=MP(INF,INF);
			for (int out=-1;out<=1;out++) {
				int newhi=hi+out;
				if (newhi>=1) {
					chkmin(best,MP(getcost(t,out),-out));
				}
			}
			int out=-best.snd;
			hi+=out;
			hicost=best.fst;
			cost+=hicost;
		}
		{
			int best=INF;
			for (int out=-1;out<=1;out++) {
				int newlo=lo+out;
				if (newlo>=1) {
					int newcost=getcost(t,out);
					if (newcost<=hicost) {
						//assert(newcost==hicost);
						chkmin(best,out);
					}
				}
			}
			lo+=best;
		}
	}
	ll delta=min(abs(lo-1),abs(hi-1));
	//printf("final:%lld lo:%lld hi:%lld cost:%lld\n",final,lo,hi,cost);
	final++;
	final+=delta;
	final+=cost;
	if (final%2==1) final++;
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
