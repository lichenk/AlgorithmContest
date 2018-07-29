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
const int INF=2e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;

map<pair<vi,vi>,int> dp;
int f(vi a, vi b) {
	if (a==b) return 0;
	auto it=dp.find(MP(a,b)); if (it!=dp.end()) return it->snd;
	int n=a.size();
	int hi=0;
	for (int x=0;x<n;x++) {
		if (a[x]==0) continue;
		int lo=1e9;
		vi c=a; --c[x];
		for (int y=0;y<n;y++) {
			if (b[y]==0) continue;
			vi d=b; --d[y];
			chkmin(lo,f(c,d)+1);
		}
		chkmax(hi,lo);
	}
	return dp[MP(a,b)]=hi;
}
ll smart(vi a, vi b) {
	if (a==b) return 0;
	int n=a.size();
	ll ans=0; ll extra=0;
	for (int i=0;i<n;i++) {
		if (a[i]<=b[i]) {
			ans+=b[i];
			extra+=b[i]-a[i];
		}
	}
	int mingain=INF;
	ll sumgain=0;
	for (int i=0;i<n;i++) {
		if (a[i]>b[i]) {
			int cost=a[i]-b[i]+1;
			int gain=b[i];
			if (cost<=extra) {
				sumgain+=gain;
				chkmin(mingain,gain);
			}
		}
	}
	if (mingain!=INF) ans+=(sumgain-mingain);
	return ans;
}
void solve(int N, vi A, vi B){
	printf("%lld\n",smart(A,B));
	return;
}
void test() {
	int seed=clock();
	srand(seed);
	int n=rand()%3+1;
	vi a,b;
	for (int i=0;i<n;i++) {a.PB(rand()%3);}
	for (int i=0;i<n-1;i++) b.PB(rand()%3);
	int diff=0;
	for (auto &w:a) diff+=w;
	for (auto &w:b) diff-=w;
	if (diff<0) return;
	b.PB(diff);
	int slow=f(a,b);
	int fast=smart(a,b);
	if (slow!=fast) {
		for (auto &w:a) printf("%d ",w); printf("\n");
		for (auto &w:b) printf("%d ",w); printf("\n");
		printf("slow:%d fast:%d seed:%d\n",slow,fast,seed);
		exit(0);
	}
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	for (int i=0;i<1000;i++) test(); exit(0);
	int N;
	scanf("%d",&N);
	vi A(N-1+1);
	vi B(N-1+1);
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%d",&A[i]);
		scanf("%d",&B[i]);
	}
	solve(N, A, B);
	return 0;
}

