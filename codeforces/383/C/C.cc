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

inline int rint()
{
  int x; scanf("%d",&x); return x;
}
char rch()
{
  char x; scanf("%c",&x); return x;
}

const int mn=2e5+4;

const int MAXSEG = 2*mn;  // limit for array size
int segn;  // array size
typedef int S;
S t[2 * MAXSEG];
S identity = 0;
S combine(const S& lefts, const S& rights) {
  return lefts+rights;
}

void modify(int l, int r, const S& value) {
  r++;
  int n=segn;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) {
      t[l] = combine(t[l], value);
      l++;
    }
    if (r&1) {
      --r;
      t[r] = combine(t[r], value);
    }
  }
}

S query(int p) {
  int n=segn;
  S res = identity;
  for (p += n; p > 0; p >>= 1) res = combine(res, t[p]);
  return res;
}

vector<int> g[mn];
int origv[mn];
int gts=0;
int venter[mn],vexit[mn],vdepth[mn];
void dfs(int x, int p, int d) {
  vdepth[x]=d;
  venter[x]=gts++;
  for (auto &y:g[x]) {
    if (y==p) continue;
    dfs(y,x,d+1);
  }
  vexit[x]=gts++;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint(),m=rint();
  for (int x=1;x<=n;x++) origv[x]=rint();
  for (int i=0;i<n-1;i++) {
    int x=rint(),y=rint();
    g[x].PB(y); g[y].PB(x);
  }
  dfs(1,-1,0);
  segn=gts;
  for (int i=0;i<m;i++) {
    int t=rint(),x=rint();
    if (t==1) {
      int val=rint();
      if (vdepth[x]&1) val=-val;
      modify(venter[x],vexit[x],val);
    }
    else {
      int got=query(venter[x]);
      if (vdepth[x]&1) got=-got;
      int ans=got+origv[x];
      printf("%d\n",ans);
    }
  }
  
}

