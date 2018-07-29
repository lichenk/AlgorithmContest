#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000007;
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const int INF=1e9+2;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

struct SplitMix64 {
    unsigned long long nextInt() {
        unsigned long long z = (x += 0x9E3779B97F4A7C15ULL);
        z = (z ^ (z >> 30)) * 0xBF58476D1CE4E5B9ULL;
        z = (z ^ (z >> 27)) * 0x94D049BB133111EBULL;
        return z ^ (z >> 31);
    }
    
    int random() {
        return 1 + (nextInt() >> 33);
    }
    
    unsigned long long x;
};
vector< vector<int> > A;
int xlog=0,ylog=0;
void init() {
  for (int x=0;x<(1<<xlog);x++) {
  	for (int i=0;i<ylog;i++) {
  		for (int z=0;z<(1<<ylog);z++) {
  			if (z&(1<<i)) {
  				A[x][z]^=A[x][z^(1<<i)];
  			}
  		}
  	}
  }
  
	for (int i=0;i<xlog;i++) {
		for (int z=0;z<(1<<xlog);z++) {
			if (z&(1<<i)) {
				for (int y=0;y<(1<<ylog);y++) {
  				A[z][y]^=A[z^(1<<i)][y];
  			}
  		}
  	}
  }
}
int xmsk,ymsk;
int query(int K) {
	int kx=K&xmsk;
	int ky=K&ymsk;
	int ans=A[kx][ky];
	return ans;
}
int main() {
    int N, M, Q; 
    SplitMix64 rng;
    
    cin >> N >> M >> Q >> rng.x;
    bool sw=0;
    if (N>M) {swap(N,M); sw=1;}
    while((1<<xlog)<N) ++xlog;
    while((1<<ylog)<M) ++ylog;
    xmsk=((1<<xlog)-1);
    ymsk=((1<<ylog)-1);
    A.resize((1<<xlog), vector<int>((1<<ylog)));
    if (!sw) {
    	for (int i = 0; i < N; i++) {
    	    for (int j = 0; j < M; j++) {
    	        A[i][j] = rng.random();
    	    }
    	}
    }
    else {
    	for (int i = 0; i < M; i++) {
    	    for (int j = 0; j < N; j++) {
    	        A[j][i] = rng.random();
    	    }
    	}
    }
    
    init();
    
    unsigned long long hashSol = 0;
    
    for (int i = 1; i <= Q; i++) {
        hashSol ^= (unsigned long long)i * query(rng.random());
    }
    
    cout << hashSol << endl;
}

