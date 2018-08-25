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

const int mn=1e5+4;
int a[mn],b[mn],inva[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=0;i<n;i++) a[i]=rint()-1;
  for (int i=0;i<n;i++) inva[a[i]]=i;
  for (int i=0;i<n;i++) b[i]=rint()-1;
  set<pii> sr,sl;
  for (int bi=0;bi<n;bi++) {
    int got=bi-inva[b[bi]];
    if (got>0) sr.insert(MP(got,bi));
    else sl.insert(MP(got,bi));
  }
  for (int c=0;c<n;c++) {
    int preb=c-inva[b[c]];
    while(!sr.empty()) {
      auto got=*(sr.begin());
      if (got.fst>c) break;
      sr.erase(sr.begin());
      sl.insert(got);
    }
    int ans=1e9;
    if (!sr.empty()) chkmin(ans,(sr.begin())->fst-c);
    if (!sl.empty()) chkmin(ans,c-(sl.rbegin())->fst);
    printf("%d\n",ans);
    pii thing=MP(preb,c);
    sl.erase(thing);
    sr.insert(MP(preb+n,c));
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