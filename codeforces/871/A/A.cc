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
const int INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
const int MAXN=1e2+4;
const int MAXP=MAXN;
bool sieve_array[MAXP+1];
int ap[MAXP+1];
vector<int> gpv;

void sieve() {
  for (int i = 0; i <= MAXP; i++) {
    sieve_array[i] = true;
    ap[i]=1<<30;
  }
  sieve_array[0] = false; sieve_array[1] = false;
  int lim = (int)(ceil(sqrt(MAXP)))+2;
  for (int i = 2; i <= lim; i++) {
    if(sieve_array[i]) {
      for (int j = i*i; j <= MAXP; j+=i) {
        sieve_array[j] = false;
        ap[j]=i;
      }
    }
  }
  for (int i = 2; i <= MAXP; i++) {
    if(sieve_array[i]) {
      gpv.PB(i);
      ap[i]=i;
    }
  }
}
const int mn=1e2+1;
int dp[mn];
int f(int n) {
  //printf("f:%d\n",n);
  if (dp[n]!=-1) return dp[n];
  int ans=-INF;
  for (int x=1;x<=n;x++) {
    if (!sieve_array[x]) {
      chkmax(ans, 1 + f(n - x));
    }
    //if (n==6) printf("x:%d ans:%d\n",x,ans);
  }
  return dp[n]=ans;
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  sieve();
  sieve_array[1]=true;
  memset(dp,-1,sizeof dp);
  dp[0]=0;
  int n=rint();
  for (int i=0;i<n;i++) {
    int inp=rint();
    int lo=max(0,inp-100);
    int ans=-INF;
    for (int x=0;x<=100;x++) {
      int diff=inp-x;
      if (diff<0) break;
      if (diff%4==0) {
        int cand = f(x) + diff / 4;
        chkmax(ans, cand);
      }
    }
    if (ans<=-INF+5) ans=-1;
    printf("%d\n",ans);
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