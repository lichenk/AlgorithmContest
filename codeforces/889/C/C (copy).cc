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
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
const int mn=1e6+4;
int mod_pow(int a, int n) {
  const int mod=MOD;
  int ret = 1; int p = a % mod; while (n) { if (n & 1) ret = (ret *(ll) p) % mod; p = (p *(ll) p) % mod; n >>= 1; } return ret;
}
inline int mod_inv(int a) {
  return mod_pow(a,MOD-2);
}
inline int add(int a, int b) {
  int res=a+b;
  if (res>=MOD) res-=MOD;
  return res;
}
inline int mul(int a, int b) {
  return (a*(ll)b)%MOD;
}
int fact[mn];

int fast_max(vector<int> a, int k) { 
  int n=a.size();
  int ans = 0;
  int offset = 0;
  for (int i = 0; i < n; ++i)
      if (ans < a[i]) {
          ans = a[i];
          offset = 0;
      } else {
          offset = offset + 1;
          if (offset == k)
              return ans;
      }
  return ans;
}

bool isgood(vector<int> a, int k) { 
  int n=a.size();
  int ans = 0;
  int offset = 0;
  for (int i = 0; i < n; ++i)
      if (ans < a[i]) {
          ans = a[i];
          offset = 0;
      } else {
          offset = offset + 1;
          if (offset == k)
              return false;
      }
  return true;
}


int bf(int n, int k) {
  vector<int> v;
  for (int x=1;x<=n;x++) v.PB(x);
  int ans=0;
  do {
    if (isgood(v,k)) ans++;
    else printf("")
  } while(next_permutation(v.begin(),v.end()));
  return ans;
}

int g0[mn];
int g1[mn];
int g[mn];
int makeg(int lim, int k) {
  for (int n=0;n<=lim;n++) {
    int gn;
    if (n==0) gn=1;
    else {
      int sum0=(n-k>=0)?g0[n-k]:0;
      int sum1=0;//(n-k-1>=0)?g1[n-k-1]:0;
      //printf("n:%d sum0:%d sum1:%d\n",n,mul(fact[n],sum0),mul(fact[n],sum1));
      int sum2=add(sum0,sum1);
      int sum3=1+(MOD-sum2);
      gn=mul(fact[n],sum3);
    }
    g[n]=gn;
    /*printf("n:%d gn:%d add0:%d add1:%d\n",
      n,
      gn,
      mul(gn, mod_inv(mul(n+k, fact[n-1]))),
      mul(gn, mod_inv(mul(n+k+1, fact[n])))
      );*/
    if (n>=1) g0[n]=add(n>0?g0[n-1]:0, mul(gn, mod_inv(mul(n+k, fact[n-1]))));
    //if (n>=1) g1[n]=add(n>0?g1[n-1]:0, mul(gn, mod_inv(mul(n+k+1, fact[n]))));
    //printf("n:%d g0n:%d g1n:%d\n",n,g0[n],g1[n]);
  }
  return g[lim];
}


int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  fact[0]=1;
  for (int x=1;x<mn;x++) fact[x]=mul(fact[x-1],x);
  for (int n=4;n<=4;n++) {
    for (int k=2;k<=2;k++) {
      memset(g0,0,sizeof g0);
      memset(g1,0,sizeof g1);
      int bff=bf(n,k);
      int smart=makeg(n,k);
      if (bff!=smart) {
        printf("MISMATCH n:%d k:%d bff:%d smart:%d\n",n,k,bff,smart);
      }
    }
  }
}
