#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

int rint()
{
  int x; scanf("%d",&x); return x;
}
char rch()
{
  char x; scanf("%c",&x); return x;
}
const ll mn=1e6+4;
ll a[mn];
ll t2i[mn];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll n=rint();
  for (ll i=1;i<=n;i++) a[i]=rint();
  pair<ll,ll> best=MP(INF,0);
  //printf("Initdev:%lld\n",dev);
  for (ll t=0;t<n;t++) {
    ll dev=0;
    for (ll i=1;i<=n;i++) {
      dev+=abs(a[(i+t-1)%n+1]-i);
    }
    chkmin(best,MP(dev,t));
  }
  best.snd=(n-best.snd)%n;
  assert(best.snd>=0);
  assert(best.snd<n);
  printf("%lld %lld\n",best.fst,best.snd);
}
