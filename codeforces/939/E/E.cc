#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef __float128 ld;
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

const int mn=5e5+4;
ll presum[mn];

ld f(int inp, int k) {
  return (ld)(presum[k]+inp)/(ld)(k+1);
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int qlim=rint();
  int r=1;
  int inp;
  int k=0;
  for (int q=1;q<=qlim;q++) {
    int t=rint();
    if (t==1) {
      inp=rint();
      k++;
      presum[k]=presum[k-1]+inp;
    }
    else {
      ld oldval=f(inp,r);
      while(r<k-1) {
        ld newval=f(inp,r+1);
        if (newval<oldval) {
          oldval=newval;
          r++;
        }
        else break;
      }
      ld ans=inp-oldval;
      printf("%.8f\n",(double)ans);
    }
    

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