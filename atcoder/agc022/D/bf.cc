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

void solve(long long N, long long L, vector<long long> vx, vector<long long> vt){
	vector<int>p; for (int i=0;i<N;i++) p.PB(i);
	ll best=1LL<<62;
	do {
		ll idx=0;
		ll st=-1;
		for (ll now=0;;now++) {
			ll pos=now%(2*L);
			if (pos>L) pos=2*L-pos;
			if (idx<N) {
				ll x=vx[p[idx]],t=vt[p[idx]];
				if (st==-1&&pos==x) {
					st=now;
				}
				else if (now>=st+t&&pos==x) {
					idx++;
					st=-1;
				}
			}
			else {
				if (pos==0) {
					chkmin(best,now);
					break;
				}
			}
		}
	} while(next_permutation(p.begin(),p.end()));
	printf("%lld\n",best);
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

