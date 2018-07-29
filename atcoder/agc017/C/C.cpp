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
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<ll> vll;
const int mn=2e5+4;
const int MAXN=mn;

const int MAXSEG = mn;  // limit for array size
int segn;  // array size
typedef struct SS{
	int premx,xmpre;
	int sumcnt;
} S;
S t[2 * MAXSEG];
S identity;
S combine(const S& l, const S& r) {
	S res;
	res.premx=max(l.premx, r.premx+l.sumcnt);
	res.xmpre=max(l.xmpre, r.xmpre-l.sumcnt);
	res.sumcnt=l.sumcnt+r.sumcnt;
	return res;
}
void build() {  // build the tree
	int n=segn;
  for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
}

void modify(int p, const S& value) { // set value at position p
	int n=segn;
  for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
}

S query(int l, int r) { // sum on interval [l, r]
	r++;
	int n=segn;
  S resl=identity, resr=identity;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) resl = combine(resl, t[l++]);
    if (r&1) resr = combine(t[--r], resr);
  }
  return combine(resl, resr);
}


int cnt[mn];

void change_cnt(int x, int delta) {
	cnt[x]+=delta;
	//printf("x:%d delta:%d cnt[x]:%d\n",x,delta,cnt[x]);
	if (cnt[x]==0) {
		modify(x,identity);
	}
	else {
			S res;
			res.premx=cnt[x]-x;
			res.xmpre=x-cnt[x];
			res.sumcnt=cnt[x];
			//printf("pmx:%d xmp:%d sc:%d\n",res.premx, res.xmpre, res.sumcnt);
			modify(x,res);
	}
}

void solve(long long N, long long M, vector<long long> A, vector<long long> X, vector<long long> Y){
	identity.premx=identity.xmpre=-INF;
	identity.sumcnt=0;
	ll q=X.size();
	for (auto &w:A) {
		cnt[w]++;
	}
	segn=N+1;
	for (int x=1;x<=N;x++) {
		if (cnt[x]) {
			S res;
			res.premx=cnt[x]-x;
			res.xmpre=x-cnt[x];
			res.sumcnt=cnt[x];
			t[x+segn]=res;
		}
		else t[x+segn]=identity;
	}
	build();
	for (ll qi=0;qi<q;qi++) {
		change_cnt(A[X[qi]-1],-1);
		A[X[qi]-1]=Y[qi];
		change_cnt(A[X[qi]-1],1);
		auto got=query(1,N);
		printf("%d\n",max(0,got.xmpre)+max(0,got.premx));
	}
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long M;
	long long N;
	scanf("%lld",&N);
	vector<long long> A(N-1+1);
	scanf("%lld",&M);
	vector<long long> Y(M-1+1);
	vector<long long> X(M-1+1);
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&A[i]);
	}
	for(int i = 0 ; i <= M-1 ; i++){
		scanf("%lld",&X[i]);
		scanf("%lld",&Y[i]);
	}
	solve(N, M, A, X, Y);
	return 0;
}

