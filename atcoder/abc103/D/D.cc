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

void solve(long long n, long long m, vector<long long> a, vector<long long> b){
	vector<pll> v;
	for (int i=0;i<m;i++) {
		v.PB(MP(a[i],b[i]));
	}
	sort(v.begin(),v.end());
	int blo=-1;
	int ans=0;
	for (auto &w:v) {
		int a=w.fst,b=w.snd;
		if (a>=blo) {
			ans++;
			blo=b;
		}
		chkmin(blo,b);
	}
	printf("%d\n",ans);
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long N;
	long long M;
	scanf("%lld",&N);
	scanf("%lld",&M);
	vector<long long> a(M-1+1);
	vector<long long> b(M-1+1);
	for(int i = 0 ; i <= M-1 ; i++){
		scanf("%lld",&a[i]);
		scanf("%lld",&b[i]);
	}
	solve(N, M, a, b);
	return 0;
}

