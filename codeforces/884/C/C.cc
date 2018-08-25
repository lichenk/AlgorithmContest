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
int p[mn];
bool seen[mn];
int f(int x) {
  if (seen[x]) return 0;
  seen[x]=1;
  return f(p[x])+1;
}
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  vector<int> a;
  int n=rint();
  for (int i=1;i<=n;i++) p[i]=rint();
  vector<int> v;
  for (int x=1;x<=n;x++) {
    if (!seen[x]) {
      int got=f(x);
      v.PB(got);
    }
  }
  sort(v.begin(),v.end(),greater<int>());
  ll ans=0;
  if (v.size()>=2) {
    int vsz=v.size();
    ll y=v[0]+v[1];
    ans+=y*y;
    for (int i=2;i<vsz;i++) {
      ans+=v[i]*(ll)v[i];
    }
  }
  else {
    ans+=v[0]*(ll)v[0];
  }
  printf("%lld\n",ans);
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