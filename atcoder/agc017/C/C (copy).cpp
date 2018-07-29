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
typedef pair<int,int> pii;
typedef vector<ll> vll;
const int mn=2e5+4;
const int MAXN=mn;

const int MAXSEG = 1e5;  // limit for array size
int segn;  // array size
typedef pii S;
S t[2 * MAXSEG];
S identity = MP(0,0);
S combine(const S& lefts, const S& rights) {
	return MP(max(lefts.fst,rights.fst),max(lefts.snd,rights.snd));
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


typedef int FT2;
FT2 t2[MAXN];
FT2 NEUTRAL2=0;
FT2 comb2(FT2 x, FT2 y) { // ONLY COMMUTATIVE OPERATIONS ALLOWED
	return x+y;
}
// T[i] += value
void fenwick_modify2(int i, FT2 value) {
  for (; i < MAXN; i |= i + 1)
    t2[i]=comb2(t2[i],value);
}

  // sum[0..i]
FT2 fenwick_query2(int i) {
  FT2 res = NEUTRAL2;
  for (; i >= 0; i = (i & (i + 1)) - 1)
    res = comb2(res,t2[i]);
  return res;
}

int cnt[mn];
void change_cnt(int x, int delta) {
	fenwick_modify2(x,delta);
	cnt[x]+=delta;
	if (cnt[x]==0) {
		modify(x,MP(0,0));
	}
	else {
		int pre=fenwick_query2(x);
		printf("x:%d pre:%d\n",x,pre);
		modify(x,MP(pre-x,x-pre));		
	}
}
void solve(long long N, long long M, vector<long long> A, vector<long long> X, vector<long long> Y){
	ll q=X.size();
	for (auto &w:A) {
		cnt[w]++;
	}
	segn=N+1;
	for (int x=1;x<=N;x++) {
		if (cnt[x]) {
			fenwick_modify2(x,cnt[x]);
			int pre=fenwick_query2(x);
			t[x+segn]=MP(pre-x,x-pre);
		}
	}
	build();
	for (ll qi=0;qi<q;qi++) {
		change_cnt(A[X[qi]-1],-1);
		A[X[qi]-1]=Y[qi];
		change_cnt(A[X[qi]-1],1);
		auto got=query(1,N);
		printf("got:%d %d\n",got.fst,got.snd);
		printf("%d\n",got.fst+got.snd);
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

