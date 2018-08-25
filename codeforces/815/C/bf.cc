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
const int mn=5002;
int c[mn],d[mn],t[mn];
vector<int> graph[mn];
int maxb;
void setmin(map<int,int> &h, int key, int val) {
  if (val>maxb) return;
  auto it=h.find(key);
  if (it==h.end()) h[key]=val;
  if (it->snd > val) it->snd=val;
}
pair<map<int,int>, map<int,int> > dfs(int x) {
  map<int,int> fx[2],gx[2];
  if (c[x]-d[x]<=maxb) fx[0][1]=c[x]-d[x];
  gx[0][0]=0;
  if (c[x]<=maxb) gx[0][1]=c[x];
  int cur=0,nxt=1;
  for (auto &y:graph[x]) {
    auto got=dfs(y);
    fx[nxt]=fx[cur];
    for (auto wx:fx[cur]) {
      for (auto &wy:got.fst) setmin(fx[nxt],wx.fst+wy.fst, wx.snd+wy.snd);
      for (auto &wy:got.snd) setmin(fx[nxt],wx.fst+wy.fst, wx.snd+wy.snd);
    }
    gx[nxt]=gx[cur];
    for (auto wx:gx[cur]) {
      for (auto &wy:got.snd) setmin(gx[nxt],wx.fst+wy.fst, wx.snd+wy.snd);
    }
    swap(cur,nxt);
  }
  return MP(fx[cur],gx[cur]);
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint(); maxb=rint();
  for (int i=1;i<=n;i++) {
    c[i]=rint(); d[i]=rint();
    if (i>=2) {
      t[i]=rint();
      graph[t[i]].PB(i);
    }
  }
  int final=0;
  auto got=dfs(1);
  for (auto &w:got.fst) if (w.snd<=maxb) chkmax(final,w.fst);
  for (auto &w:got.snd) if (w.snd<=maxb) chkmax(final,w.fst);
  printf("%d\n",final);
}
