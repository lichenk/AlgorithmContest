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
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

int rint()
{
  int x; scanf("%d",&x); return x;
}
const int mn=1e5+4;
int p[mn];
int psz[mn];
int ffind(int x) {
  if(p[x]!=x) {
    p[x]=ffind(p[x]);
  }
  return p[x];
}
ll gc2=0;
ll c2(ll x) {
  return (x*(x-1))/2;
}
void funion(int x, int y) {
  if (rand()&1) swap(x,y);
  int xr=ffind(x),yr=ffind(y);
  if (xr==yr) return;
  p[yr]=xr;
  gc2-=c2(psz[xr])+c2(psz[yr]);
  psz[xr]+=psz[yr];
  gc2+=c2(psz[xr]);
}
int a[mn];
vector<int> va2idx[mn];
vector<int> g[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  ll n=rint(); int m=rint();
	for (int i=1;i<=n;i++) {
    int x=rint();
    a[i]=x;
    va2idx[a[i]].PB(i);
  }
  for (int i=0;i<m;i++) {
    int x=rint(),y=rint();
    g[x].PB(y); g[y].PB(x);
  }
  for (int x=1;x<=n;x++) {p[x]=x; psz[x]=1;}
  ll final=0;
  for (int v=mn-1;v>=0;v--) {
    ll ogc2=gc2;
    for (auto &x:va2idx[v]) {
      for (auto &y:g[x]) {
        if (a[y]<v) continue;
        funion(x,y);
      }
    }
    ll diff=gc2-ogc2;
    //if (diff) printf("v:%d diff:%lld ogc2:%lld gc2:%lld\n",v,diff,ogc2,gc2);
    final+=diff*v;
  }
  assert(gc2==(n*(n-1))/2);
  double finalans=((ld)final)/((n*(n-1))/2);
  printf("%.10f\n",finalans);
}

