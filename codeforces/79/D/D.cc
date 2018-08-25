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
const int INF=1e9;
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
int inp[101],vc[101];
int knap[10000+1];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),k=rint(),l=rint();
  for (int i=0;i<k;i++) {
    inp[i]=rint();
  }
  for (int i=0;i<l;i++) {
    vc[i]=rint();
  }
  for (int x=0;x<=n;x++) knap[x]=INF;
  knap[0]=0;
  for (int i=0;i<l;i++) {
    int c=vc[i];
    for (int x=0;x<=n-c;x++) {
      if (knap[x]<INF) chkmin(knap[x+c],knap[x]+1);
    }
  }
  vector<pair<int,pii> > vp;
  int last=1;
  for (int i=0;i<k;i++) {
    int x=inp[i];
    if (last<=x-1) vp.PB(MP(0,MP(last,x-1)));
    vp.PB(MP(1,MP(x,x)));
    last=x+1;
  }
  if (last<=n) vp.PB(MP(0,MP(last,n)));
  int ps=vp.size();
  int final=INF;
  for (int z=0;z<(1<<ps);z++) {
    
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