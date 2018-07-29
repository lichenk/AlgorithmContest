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
const int L2R=-1;
const int ANY=0;
const int R2L=1;
 
void solve(long long N, long long L, vector<long long> vx, vector<long long> vt){
	ll final=0;
	vector<int> v;
	for (ll i=0;i<N;i++) {
		ll x=vx[i],t=vt[i];
		ll fa[2];
		fa[0]=geta(L-x,t,L);
		fa[1]=geta(x,t,L);
		//printf("x:%lld t:%lld L:%lld fa[0]:%lld fa[1]:%lld\n",x,t,L,fa[0],fa[1]);
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
	}
	ll lo=-1,hi=-1,cost=0;
	reverse(v.begin(),v.end());
	for (auto &t: v) {
		//printf("t:%d\n",t);
		if (t==0) {
			if (lo-1>=-1) {lo--;}
			else {lo++;}
			hi++;
		}
		else if (t==1) {
			lo++;
			hi++;
		}
		else {
			assert(t==-1);
			if (hi-1<-1) {
				cost++;
				lo++; hi++;
			}
			else if (lo-1<-1) {
				lo+=2; assert(lo<=hi);
				lo--;
				hi--;
			}
			else {
				lo--; hi--;
			}
		}
	}
	ll delta=min(abs(lo),abs(hi));
	//if (lo%2==1 && lo<=1&&1<=hi) delta=0;
	//if (delta>0) add--;
	//printf("final:%lld lo:%lld hi:%lld cost:%lld\n",final,lo,hi,cost);
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
 