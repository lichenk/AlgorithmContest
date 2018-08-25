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
int rint();char rch();long long rlong();
const int mn=20+4;
int a[mn];
int b[mn];
int c[mn];
ll go(int n, int k) {
  memcpy(b,a,sizeof a);
  memset(c,0,sizeof c);
  srand(clock());
  int lft=n;
  int iter=0;
  ll ans=0;
  while(lft>1) {
    if (iter>2000) return INF;
    int x=rand()%n;
    int y=rand()%n;
    if (c[x]!=-1&&c[y]!=-1&&x!=y&&c[y]<k) {
      c[x]=-1;
      c[y]++;
      ans+=b[x];
      b[y]+=b[x];
      lft--;
    }
    iter++;
  }
  return ans;
}
ll solve(int n, int k) {
  ll ans=INF;
  for (int i=0;i<50000;i++) {
    chkmin(ans,go(n,k));
  }
  return ans;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=0;i<n;i++) a[i]=rint();
  int q=rint();
  for (int i=0;i<q;i++) {
    int k=rint();
    ll got=solve(n,k);
    printf("%lld ",got);
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