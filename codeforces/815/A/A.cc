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
const int mn=102;
int n,m;
int a[mn][mn];
vector<pii> vans;
bool dorow() {
  for (int x=0;x<n;x++) {
    bool ok=1;
    for (int y=0;y<m;y++) {
      if (a[x][y]==0) {ok=0; break;}
    }
    if (ok) {
      for (int y=0;y<m;y++) a[x][y]--;
      vans.PB(MP(0,x));
      return 1;
    }
  }
  return 0;
}
bool docol() {
  for (int y=0;y<m;y++) {
    bool ok=1;
    for (int x=0;x<n;x++) {
      if (a[x][y]==0) {ok=0; break;}
    }
    if (ok) {
      for (int x=0;x<n;x++) a[x][y]--;
      vans.PB(MP(1,y));
      return 1;
    }
  }
  return 0;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	n=rint(),m=rint();
  for (int x=0;x<n;x++) for (int y=0;y<m;y++) {
    a[x][y]=rint();
  }
  while(1) {
    bool ok=0;
    if (m>=n) {
      ok=dorow();
      if (!ok) ok=docol();
    }
    else {
      ok=docol();
      if (!ok) ok=dorow();
    }
    if (!ok) break;
  }
  bool final=1;
  for (int x=0;x<n;x++) for (int y=0;y<m;y++) {
    if (a[x][y]) final=0;
  }
  if (!final) {
    printf("-1\n");
  }
  else {
    printf("%d\n",(int)vans.size());
    for (auto &w:vans) {
      w.snd++;
      if (w.fst==0) printf("row %d\n",w.snd);
      else printf("col %d\n",w.snd);
    }
  }
}

