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
const ll INF=1LL<<61;
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
long long rlong()
{
  long long x; scanf("%lld",&x); return x;
}

ll hquery(map<int,ll> &h, int key) {
  //Queries the largest (k,v) pair where k<=key
  auto it=h.upper_bound(key);
  if (it==h.begin()) {
    return -INF;
  }
  --it;
  return it->snd;
}

void hins(map<int,ll> &h, int key, ll val) {
  //Inserts (key,val) into h.
  //Maintains the invariant that if key1<key2, then val1<val2.
  auto it=h.upper_bound(key);
  if (it==h.begin()) {
    it=h.insert(MP(key,val)).fst;
  }
  else {
    --it;
    if (it->snd >= val) return;
    if (it->fst==key) it->snd = val;
    else it=h.insert(MP(key,val)).fst;
  }
  ++it;
  while(it!=h.end()) {
    if (it->snd <= val) it=h.erase(it);
    else return;
  }
}
void hinsdbgslow(map<int,ll> &h, int key, ll val) {
  hins(h,key,val);
  /* Checker FOR DEBUGGING ONLY */
  ll best=-INF-1;
  for (auto it=h.begin();it!=h.end();++it) {
    if (!(it->snd > best)) {
      printf("it->fst:%d it->snd:%lld best:%lld\n",it->fst,it->snd,best);
      exit(1);
    }
    best=it->snd;
  }
  assert(hquery(h,key)>=val);
  /* End checker*/
}
const int mn=2004;
ll f[2][2004];
int a[mn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint(),klim=n-rint();
  for (int i=0;i<n;i++) a[i]=rint();
  int cur=0,nxt=1;
  for (int k=1;k<klim;k++) {
    for (int x=0;x<n;x++) f[nxt][x]=INF;
    map<int,ll> hg,hl;
    for (int x=0;x<n;x++) {
      ll ansl=-hquery(hl, a[x])+a[x];
      ll ansr=-hquery(hg,-a[x])-a[x];
      printf("k:%d x:%d ansl:%lld ansr:%lld ans:%lld\n",k+1,x,ansl,ansr,min(ansl,ansr));
      f[nxt][x]=min(ansl,ansr);
      ll now=f[cur][x];
      hins(hl,a[x],-(now-a[x]));
      hins(hg,-a[x],-(now+a[x]));
    }
    swap(cur,nxt);
  }
  ll ans=INF;
  for (int x=0;x<n;x++) {
    chkmin(ans,f[cur][x]);
  }
  printf("%lld\n",ans);
}

