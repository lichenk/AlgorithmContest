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

void solve(long long N, vector<long long> A){
	vector<pll> v;
	ll z=0;
	for (auto &w:A) {
		if (w!=0) {
			v.PB(MP(0,z));
			z=0;
			v.PB(MP(w,1));
		}
		else z++;
	}
	v.PB(MP(0,z)); z=0;
	ll n=v.size();
	//for (int i=0;i<n;i++) {auto w=v[i]; printf("%d %lld %lld\n",i,w.fst,w.snd);}
	/*if (n==1) {
		printf("%lld\n",(v[0].snd*(v[0].snd+1LL))/2);
		exit(0);
	}*/
	ll ans=0;
	for (ll i=0;i<n;i++) {
		auto w=v[i];
		if (w.fst!=0) {
			auto l=v[i-1];
			ll sig=w.fst;
			for (ll k=i+1;k<n;k++) {
				if (sig&v[k].fst) {
					break;
				}
				else {
					auto r=v[k];
					if(r.fst==0) {
						ll cand=(l.snd+1LL)*(r.snd+1LL);
						//printf("i:%d k:%d cand:%lld\n",i,k,cand);
						ans+=cand;
					}
					sig|=v[k].fst;
				}
			}
		}
		else {
			ans+=(w.snd*(w.snd+1LL))/2;
		}
	}
	printf("%lld\n",ans);
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long N;
	scanf("%lld",&N);
	vector<long long> A(N-1+1);
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&A[i]);
	}
	solve(N, A);
	return 0;
}

