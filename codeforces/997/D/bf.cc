#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=998244353;
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const int INF=1<<30;
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
int rint();char rch();long long rlong();
const int mn=4001;
const int mk=75+1;

int mod_pow(int a, int n, int mod) { int ret = 1; int p = a % mod; while (n) { if (n & 1) ret = (ret *(ll) p) % mod; p = (p *(ll) p) % mod; n >>= 1; } return ret; }
const int MAXFACT=75+1;
int fact[MAXFACT+1],invfact[MAXFACT+1];
inline int mul(int x,int y) {return (x*(ll)y)%MOD;}
void init() {
  int got=1;
  for (int x=0;x<=MAXFACT;x++) {
    fact[x]=got;
    got=mul(got,x+1);
  }
  got=mod_pow(got,MOD-2,MOD);
  for (int x=MAXFACT;x>=0;x--) {
    got=mul(got,x+1);
    invfact[x]=got;
  }
}
int binom(int n,int k) {
  if (n<k) return 0;
  if (n<0||k<0) return 0;
  return mul(fact[n],mul(invfact[k],invfact[n-k]));
}


int vn[2];
int f[2][mn];
int h[2][mk];
int vx[mn],vy[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  init();
  vn[0]=rint();vn[1]=rint(); int k=rint();
  if (k&1) {
  	printf("0\n"); exit(0);
  }
  for (int t=0;t<2;t++) {
  	int n=vn[t];
  	for (int i=0;i<n-1;i++) {vx[i]=rint()-1; vy[i]=rint()-1;}
  	for (int init=0;init<n;init++) {
  		memset(f[0],0,sizeof f[0]);
  		f[0][init]=1;
  		h[t][0]++;
  		int cur=0,nxt=1;
  		for (int l=1;l<=k;l++) {
  			memset(f[nxt],0,sizeof f[0]);
  			for (int i=0;i<n-1;i++) {
  				int x=vx[i],y=vy[i];
  				f[nxt][x]+=f[cur][y]; if (f[nxt][x]>=MOD) f[nxt][x]-=MOD;
  				f[nxt][y]+=f[cur][x]; if (f[nxt][y]>=MOD) f[nxt][y]-=MOD;
  			}
				h[t][l]+=f[nxt][init];
        if (t==1) {
          printf("init:%d l:%d contrib:%d\n",init,l,f[nxt][init]);
        }
				if (h[t][l]>=MOD) h[t][l]-=MOD;
  			swap(cur,nxt);
  		}
  	}
  }
  int ans=0;
  for (int l0=0;l0<=k;l0++) {
  	int l1=k-l0;
  	int got=mul(h[0][l0],h[1][l1]);
  	if (got) {
  		//printf("l0:%d h:%d l1:%d h:%d\n",l0,h[0][l0],l1,h[1][l1]);
  		int bin=binom(k,l0);
  		ans=(ans+bin*((ll)got))%MOD;
  	}
  }
  printf("%d\n",ans);
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