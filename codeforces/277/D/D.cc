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
const ld EPS=1e-16;
struct Node {
  int ss,sl,ts,tl;
  ld p;
  Node(int ss,int sl,int ts,int tl,ld p): ss(s),sl(sl),ts(ts),tl(tl),p(p) {};
  bool operator < (Node b) const {
    ld ans1=b.p*(t+b.t)+(1-b.p)*p*t;
    ld ans2=p*(t+b.t)+(1-p)*b.p*b.t;
    if (fabs(ans1-ans2)<EPS) return false; // equal
    return ans1<ans2;
  }
}
const int mn=1002;
const int mt=1562;
Node a[mn];
typedef pair<ld,ld> pld;
pld f[2][mt];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n,tlim; cin>>n>>tlim;
  for (int i=0;i<n;i++) {
    cin>>a[i].ss>>a[i].sl>>a[i].ts>>a[i].tl>>a[i].p;
  }
  sort(a,a+n);
  int cur=0,nxt=1;
  for (int i=0;i<n;i++) {
    memcpy(f[nxt],f[cur],sizeof f[0]);
    int ts=a[i].ts,ss=a[i].ss,tl=a[i].tl,sl=a[i].sl;
    ld p=a[i].p;
    for (int t=0;t<=tlim;t++) {
      pld now=f[cur][t];
      if (t+ts<=tlim) chkmax(f[nxt][t+ts],MP(now.fst+ss,now.snd-ts));
      if (t+ts+tl<=tlim) {
        ld old=now.snd;
        ld nnew=now.snd-
        chkmax(f[nxt][t+ts+tl], MP(now.fst+ss+p*sl, now.snd-ts-));
      }
    }
    swap(cur,nxt);
  }
}

