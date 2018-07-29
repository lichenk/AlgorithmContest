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
typedef vector<int> vll;
ll gn;
void go(vll &v) {
	assert(v.size()==gn);
	ll sum=0;
	for (auto &w:v) sum+=w;
	assert(sum%6==0);
	for (auto &w:v) {
		assert(w%2==0||w%3==0);
	}
	bool has2=0,has3=0;
	for (auto &w:v) {
		if (w%6==0) continue;
		if (w%2==0) has2=true;
		else if (w%3==0) has3=true;
	}
	if (has2&&has3) {
		for (auto &w:v) printf("%lld ",w); printf("\n"); exit(0);
	}
}
void solve(long long N){
	if (N==3) {
		printf("2 5 63\n"); exit(0);
	}
	gn=N;
	vll v; vll pool;
	for (int x=1;x<=30000;x++) {
		if (x%2==0||x%3==0) {
			if (v.size()<N) v.PB(x);
			else pool.PB(x);
		}
	}
	ll sum=0; for (auto &w:v) sum+=w;
	sum%=6;
	if (sum==0) go(v);
	const int LIM=5;
	for (int a=0;a<min((int)v.size(),LIM);a++) {
			for (int c=0;c<min((int)pool.size(),LIM);c++) {
					ll ch=pool[c]-(v[a]);
					if ((sum+ch)%6==0) {
						vll newans;
						for (auto &w:v) {if (w!=v[a]) newans.PB(w);}
						newans.PB(pool[c]);
						go(newans);
					}
			}
	}
	for (int a=0;a<min((int)v.size(),LIM);a++) {
		for (int b=0;b<a;b++) {
			for (int c=0;c<min((int)pool.size(),LIM);c++) {
				for (int d=0;d<c;d++) {
					ll ch=pool[c]+pool[d]-(v[a]+v[b]);
					if ((sum+ch)%6==0) {
						vll newans;
						for (auto &w:v) {if (w!=v[a]&&w!=v[b]) newans.PB(w);}
						newans.PB(pool[c]); newans.PB(pool[d]);
						go(newans);
					}
				}
			}
		}
	}
	assert(0);
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long N;
	scanf("%lld",&N);
	solve(N);
	return 0;
}

