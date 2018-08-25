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
const int mn=3e5+2;
vector<int> g[mn];
const int MAXSEG = 2*mn;  // limit for array size
int segn;  // array size
typedef pair<int,int> S;
S t[2 * MAXSEG];
S identity = MP(0,0);
S combine(const S& lefts, const S& rights) {
  //S res;
  /* Custom code */
  int x=lefts.fst+rights.fst; if (x>=MOD) x-=MOD;
  int y=lefts.snd+rights.snd; if (y>=MOD) y-=MOD;
  return MP(x,y);
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

int git=0;
int venter[mn],vexit[mn],lvl[mn];
void dfs(int x) {
  venter[x]=git;
  git++;
  for (auto &y:g[x]) {
    lvl[y]=lvl[x]+1;
    dfs(y);
  }
  vexit[x]=git;
  git++;
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint();
  for (int x=2;x<=n;x++) {
    int p=rint();
    g[p].PB(x);
  }
  dfs(1);
  segn=git;
  int q=rint();
  for (int jj=0;jj<q;jj++) {
    int t=rint(),v=rint();
    if (t==1) {
      ll x=rint(),k=rint();
      x+=k*lvl[v];
      x%=MOD;
      if (x<0) x+=MOD;
      if (k<0) k+=MOD;
      int l=venter[v],r=vexit[v];
      S val=MP(x,k);
      modify(l,r,val);
    }
    else {
      S got=query(venter[v]);
      ll x=got.fst,k=got.snd;
      ll ans=x-k*lvl[v];
      ans%=MOD; if (ans<0) ans+=MOD;
      printf("%d\n",(int)ans);
    }
  }
}

