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

bool islucky(ll x) {
  while(x>0) {
    ll r=x%10;
    if (r!=4&&r!=7) return false;
    x/=10;
  }
  return true;
}

vector<ll> g;
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  for (int l=1;l<=10;l++) {
    for (int z=0;z<(1<<l);z++) {
      ll x=0;
      for (int i=0;i<l;i++) {
        x*=10;
        if (z&(1<<i)) x+=7;
        else x+=4;
      }
      g.PB(x);
    }
  }
  sort(g.begin(),g.end());
  ll n,k; cin>>n>>k;
  vector<ll> v;
  --k;
  for (ll x=1;x<=n;x++) {
    if (k==0) break;
    v.PB(k%x); k/=x;
  }
  if (k!=0) {printf("-1\n"); exit(0);}
  reverse(v.begin(),v.end());
  ll pre=n-v.size();
  ll sufstart=n-v.size()+1;
  ll ans=0;
  for (auto &w:g) {
    if (w<=pre) {
      ans++;
    }
  }
  vector<ll> s;
  for (int x=sufstart;x<=n;x++) s.PB(x);
  for (int x=sufstart;x<=n;x++) {
    int f=v[x-sufstart];
    ll got=s[f];
    if (islucky(x)&&islucky(got)) ans++;
    s.erase(s.begin()+f);
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