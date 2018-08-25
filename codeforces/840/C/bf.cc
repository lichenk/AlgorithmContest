#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
//const int MOD=1000000007;
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#ifdef ONLINE_JUDGE
#define assert(XXX) XXX
#else
#define DEBUG_CAT
#endif
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

const int K = 14;
const int N = 1 << 20;
const int MOD = 1000000007;
const int R = 3;

int k, n;
vector<int> ans;
vector<int> adj[K];
int dp[K][1 << K], f[1 << K][K + 1], g[N], fact[N];

class HamiltonianPaths {
public:
    __inline void add(int &a, int b) {
        if ((a += b) >= MOD) {
            a -= MOD;
        }
    }
    
    int power(int a, int n) {
        int ret = 1;
        for (int i = 1; i <= n; i <<= 1) {
            if (n & i) {
                ret = 1LL * ret * a % MOD;
            }
            a = 1LL * a * a % MOD;
        }
        return ret;
    }
    
    int inverse(int x) {
        return power(x, MOD - 2);
    }
    
    void prepare() {
        fact[0] = 1;
        for (int i = 1; i < N; i++) {
            fact[i] = 1LL * fact[i - 1] * i % MOD;
        }
        
    }
    void NFT(int P[], int n, int oper) {
        for (int i = 1, j = 0; i < n - 1; ++i) {
            for (int s = n; j ^= s >>= 1, ~j & s;);
            if (i < j) {
                swap(P[i], P[j]);
            }
        }
        for (int d = 0; (1 << d) < n; ++d) {
            int m = 1 << d, m2 = m * 2;
            int unit_p0 = power(R, (MOD - 1) / m2);
            if (oper < 0) {
                unit_p0 = inverse(unit_p0); 
            }
            for (int i = 0; i < n; i += m2) {
                int unit = 1;
                for (int j = 0; j < m; ++j) {
                    int &P1 = P[i + j + m], 
                        &P2 = P[i + j];
                    int t = (long long)unit * P1 % MOD;
                    P1 = P2 - t; if (P1 < 0) P1 += MOD;
                    P2 = P2 + t; if (P2 >= MOD) P2 -= MOD;
                    unit = (long long)unit * unit_p0 % MOD;
                }
            }
        }
    }

    
    int countPaths(int _k, vector <int> a, vector <int> b, int _n) {
        prepare();
        k = _k, n = _n;
        for (int i = 0; i < k; i++) adj[i].clear();
        for (int i = 0; i < a.size(); i++) {
            adj[a[i]].push_back(b[i]);
            adj[b[i]].push_back(a[i]);
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < k; i++) {
            dp[i][1 << i] = 1;
        }
        for (int mask = 1; mask < (1 << k); mask++) {
            for (int u = 0; u < k; u++) {
                if (dp[u][mask] == 0) continue;
                for (int v : adj[u]) {
                    if (mask >> v & 1) continue;
                    add(dp[v][mask | (1 << v)], dp[u][mask]);
                }
            }
        }
        for (int mask = 0; mask < (1 << k); mask++) {
            for (int v = 1; v < k; v++) {
                add(dp[0][mask], dp[v][mask]);
            }
            if (__builtin_parity(mask) == 0) dp[0][mask] = (MOD - dp[0][mask]) % MOD;
        }
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int mask = 0; mask < (1 << k); mask++) {
            for (int t = 1; t <= k; t++) {
                for (int sub = mask; sub; sub = (sub - 1) & mask) {
                    add(f[mask][t], 1LL * f[mask ^ sub][t - 1] * dp[0][sub] % MOD);
                }
            }
        }
        memset(g, 0, sizeof(g));
        for (int t = 0; t <= k; t++) {
            g[t] = 1LL * f[(1 << k) - 1][t] * inverse(fact[t]) % MOD;
            printf("t:%d g:%d\n",t,g[t]);
            if (g[t] < 0) g[t] += MOD;
        }
        int nn = 1 << 20;
        NFT(g, nn, 1);
        for (int i = 0; i < nn; i++) g[i] = power(g[i], n);
        NFT(g, nn, -1);
        int ans = 0, invn = inverse(nn);
        for (int i = 0; i < nn; i++) {
            add(ans, 1LL * g[i] * invn % MOD * fact[i] % MOD);
        }
        return ans;
    }
};
HamiltonianPaths h;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  for (int k=1;k<=5;k++) {
    int n=0;
    vi a,b;
    printf("k:%d\n",k);
    for (int x=0;x<k;x++) {
        for (int y=0;y<x;y++) {
            a.PB(x); b.PB(y);
        }
    }
    h.countPaths(k,a,b,n);
  }
}





int rint()
{
  int x; scanf("%d",&x); return x;
}
char rch()
{
  char x; scanf("%c",&x); return x;
}
long long rlong()
{
  long long x; scanf("%lld",&x); return x;
}