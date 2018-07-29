#include <bits/stdc++.h>
#include <assert.h>
#include <memory>
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

const vector<unsigned int> primepool={4294967291, 4294967279, 4294967231, 4294967197};

class RobinKarpMersenne {
public:
	static const uint64_t mod = (1ull<<61) - 1;
	uint64_t modmul(uint64_t a, uint64_t b){
		uint64_t l1 = (uint32_t)a, h1 = a>>32, l2 = (uint32_t)b, h2 = b>>32;
		uint64_t l = l1*l2, m = l1*h2 + l2*h1, h = h1*h2;
		uint64_t ret = (l&mod) + (l>>61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
		ret = (ret & mod) + (ret>>61);
		ret = (ret & mod) + (ret>>61);
		return ret-1;
	}
	uint64_t modpow(uint64_t a, uint64_t n) {
		uint64_t ret = 1; uint64_t p = a; while (n) { if (n & 1) ret = modmul(ret, p); p = modmul(p, p); n >>= 1; } return ret;
	}
	uint64_t b,binv;
	vector<uint64_t> bpow;
	//vector<uint64_t> invbpow;
	void init(int n, uint64_t base) {
		b=base;
		bpow.reserve(n);
		uint64_t x=1;
		bpow.PB(x);
		for (int i=1;i<n;i++) {
			x=modmul(x,b);
			bpow.PB(x);
		}
		/*
		binv=modpow(b,mod-2);
		x=1;
		invbpow.PB(x);
		for (int i=1;i<n;i++) {
			x=modmul(x,invb);
			invbpow.PB(x);
		}*/
	}
	uint64_t addc(uint64_t hash, uint64_t c, int pos) {
		hash+=modmul(c,bpow[pos]); if (hash>=mod) hash -= mod;
		return hash;
	}
};
uint32_t rd() {
  uint32_t ret;
  asm volatile("rdrand %0" :"=a"(ret) ::"cc");
  return ret;
}

RobinKarpMersenne rk;
map<pair<uint64_t,uint64_t>, int> h;
int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; string inp; cin>>n>>inp;
	string s[2]; s[0]=inp.substr(0,n); s[1]=inp.substr(n,n); reverse(s[1].begin(),s[1].end());
  seed_seq seq{
      (uint64_t) chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count(),
      (uint64_t) __builtin_ia32_rdtsc(),
      (uint64_t) rd()
  };
  mt19937 rng(seq);
  uint64_t base = uniform_int_distribution<uint64_t>(31, rk.mod-31)(rng);
  rk.init(n,base);
  for (int z=0;z<(1<<n);z++) {
  	pair<uint64_t,uint64_t> hash=MP(0,0);
  	int zeros=0,ones=0;
  	for (int x=0;x<n;x++) {
  		if (0==(z&(1<<x))) hash.fst=rk.addc(hash.fst, s[0][x], zeros++);
  		else hash.snd=rk.addc(hash.snd,s[0][x],ones++);
  	}
  	hash.fst^= ((uint64_t)zeros)<<61;
  	++h[hash];
  }
  ll final=0;
  for (int z=0;z<(1<<n);z++) {
  	pair<uint64_t,uint64_t> hash=MP(0,0);
  	int zeros=0,ones=0;
  	for (int x=0;x<n;x++) {
  		if (0==(z&(1<<x))) hash.fst=rk.addc(hash.fst, s[1][x], zeros++);
  		else hash.snd=rk.addc(hash.snd,s[1][x],ones++);
  	}
  	hash.fst^= ((uint64_t)zeros)<<61;
  	auto it=h.find(hash);
  	if (it!=h.end()) final+=(it->snd);
  }
  printf("%lld\n",final);
}

