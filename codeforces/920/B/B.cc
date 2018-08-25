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
const int mn=1002;
int vl[mn],vr[mn];
int s[mn];
int vans[mn];

inline bool cmp(const int &x, const int &y) {
  int vlx=vl[x],vly=vl[y];
  if (vlx==vly) return x<y;
  return vlx<vly;
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int tlim=rint();
  for (int ti=0;ti<tlim;ti++) {
    int n=rint();
    for (int x=0;x<n;x++) {
      vl[x]=rint(); vr[x]=rint();
    }
    for (int x=0;x<n;x++) s[x]=x;
    sort(s,s+n,cmp);
    int t=0;
    for (int i=0;i<n;i++) {
      int x=s[i];
      if (t<=vr[x]) {
        chkmax(t,vl[x]);
        vans[x]=t;
        ++t;
      }
      else vans[x]=0;
    }
    for (int x=0;x<n;x++) printf("%d ",vans[x]);
    printf("\n");
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