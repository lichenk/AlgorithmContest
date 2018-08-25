#include <bits/stdc++.h>
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
long long rlong()
{
  long long x; scanf("%lld",&x); return x;
}
const int mn=1e2+4;
int p[mn],vl[mn],vr[mn];
bool rmed[mn];
void rm(int x) {
  rmed[x]=true;
  int L=vl[x],R=vr[x];
  vr[L]=R;
  vl[R]=L;
}
int vans[mn];

bool f(int n) {
  stack<int> S;
  for (int x=1;x<=n;x++) {
    if (p[x]>0) S.push(p[x]);
    else {
      if (S.empty()) return 0;
      int got=S.top(); S.pop();
      if (abs(got)!=abs(p[x])) return 0;
    }
  }
  return S.empty();
}

  queue<int> qhi;
  queue<int> qlo;
void gopush(int x) {
  int lx=vl[x];
  if (rmed[x]||rmed[lx]) return;
  //if (x==8) printf("x:%d p[lx]:%d p[x]:%d\n",x,p[lx],p[x]);
  if (p[x]<0&&p[lx]==-p[x]) qhi.push(x);
  else if (p[x]>0&&p[lx]==p[x]) qlo.push(x);
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint();
  for (int x=1;x<=n;x++) {
    vl[x]=x-1;
    vr[x]=x+1;
  }
  for (int x=1;x<=n;x++) p[x]=rint();
  int t=rint();
  for (int i=0;i<t;i++) {
    int x=rint();
    p[x]=-p[x];
  }

  for (int x=2;x<=n;x++) {
    gopush(x);
  }
  rmed[0]=true;
  rmed[n+1]=true;
  while(1) {
    int x;
    if (!qhi.empty()) {
      x=qhi.front(); qhi.pop();
    }
    else if (!qlo.empty()) {
      x=qlo.front(); qlo.pop();
    }
    else break;
    int lx=vl[x];
    if (rmed[x]||rmed[lx]) continue;
    if (abs(p[x])!=p[lx]) continue;
    printf("x:%d lx:%d col:%d\n",x,lx,abs(p[x]));
    int rx=vr[x];
    vans[x]=-abs(p[x]);
    vans[lx]=p[lx];
    rm(lx);
    rm(x);
    gopush(rx);
  }
  for (int x=1;x<=n;x++) if (vans[x]==0) {
    printf("NO\n"); return 0;
  }
  printf("YES\n");
  memcpy(p, vans, sizeof vans);
  bool got=f(n);
  assert(got);
  //for (int x=1;x<=n;x++) printf("%d ",vans[x]);
  //printf("\n");
}

