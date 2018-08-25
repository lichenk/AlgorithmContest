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
vector<ll> fib;
vector<int> ifib;
const ll LIM=1e18+4;
const int mn=61000000;
short dp[mn];//{1, 1, 1, 2, 1, 2, 2, 1, 3, 2, 2, 3, 1, 3, 3, 2, 4, 2, 3, 3, 1, 4, 3, 3, 5, 2, 4, 4, 2, 5, 3, 3, 4, 1, 4, 4, 3, 6, 3, 5, 5, 2, 6, 4, 4, 6, 2, 5, 5, 3, 6, 3, 4, 4, 1, 5, 4, 4, 7, 3, 6, 6, 3, 8, 5, 5, 7, 2, 6, 6, 4, 8, 4, 6, 6, 2, 7, 5, 5, 8, 3, 6, 6, 3, 7, 4, 4, 5, 1, 5, 5, 4, 8, 4, 7, 7, 3, 9, 6, 6, 9, 3, 8, 8, 5};
inline int Rfib(int mn1) {
  return (mn1>=3)?(mn1/2):1;
}

int Rint(int inp, int upper) {
  if (inp<mn) {
    int dpval=dp[inp];
    if (dpval!=-1) return dpval;
  }
  int m=0;
  for (int i=upper;i>=1;i--) {
    if (fib[i]<=inp) {m=i; break;}
  }
  //if (inp==fib[m+1]-1) return 1;
  int N=inp-fib[m];
  if (N<=2) {return Rfib(m-N);}
  else if (N==3) return m-3;
  else if (N==4) return Rfib(m-3);
  else if (N==5||N==6) return m-4;
  //else if (N==7) return Rfib(m-4);
  int n=0;
  for (int i=m-2;i>=1;i--) {
    if (fib[i]<=N) {n=i;break;}
  }
  int Rfmn1 = Rfib(m-n+1);
  int r=0;
  if (((m-n)&1)==0) {
    int other=fib[n+1]-2-N;
    if (other>=0) {
      r=Rint(fib[n+1]-2-N,n-1);
    }
  }
  int ans=Rfmn1*Rint(N,n)+r;
  if (inp<mn) dp[inp]=ans;
  return ans;
}


int R(ll inp, int upper) {
  if (inp<=INT_MAX) return Rint(inp,min((int)(ifib.size())-1,upper));
  int m=0;
  for (int i=upper;i>=1;i--) {
    if (fib[i]<=inp) {m=i; break;}
  }
  //if (inp==fib[m+1]-1) return 1;
  ll N=inp-fib[m];
  if (N<=2) {return Rfib(m-N);}
  else if (N==3) return m-3;
  else if (N==4) return Rfib(m-3);
  //else if (N==5||N==6) return m-4;
  //else if (N==7) return Rfib(m-4);
  int n=0;
  for (int i=m-2;i>=1;i--) {
    if (fib[i]<=N) {n=i;break;}
  }
  int Rfmn1 = Rfib(m-n+1);
  int r=0;
  if (((m-n)&1)==0) {
    ll other=fib[n+1]-2-N;
    if (other>=0) {
      r=R(fib[n+1]-2-N,n-1);
    }
  }
  int ans=Rfmn1*R(N,n)+r;
  return ans;
}
const int mk=64;
ll prevv[mk];
int pans[mk];
int go(ll n, int t) {
  for (int i=0;i<mk;i++) {
    if (prevv[i]==n) {
      return pans[i];
    }
  }
  int upper=fib.size()-1;
  int ans=R(n,upper);
  prevv[t&(mk-1)]=n;
  pans[t&(mk-1)]=ans;
  //printf("n:%lld ans:%d\n",n,ans);
  return ans;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  memset(dp,-1,sizeof dp);
  fib.PB(0); fib.PB(1);
  ifib.PB(0); ifib.PB(1);
  while(1) {
    int sz=fib.size();
    ll x=fib[sz-1]+fib[sz-2];
    if (x>LIM) break;
    fib.PB(x);
    if (x<=INT_MAX) ifib.PB(x);
  }

  int numt=rint();
  for (int tt=0;tt<numt;tt++) {
    ll n=rlong();
    printf("%d\n",go(n,tt));
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