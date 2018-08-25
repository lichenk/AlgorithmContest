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
bool used[mn];
bool cmp(const pair<pll,int> &x, const pair<pll,int> &y) {
  ll a=x.fst.fst,b=x.fst.snd,c=y.fst.fst,d=y.fst.snd;
  ll lhs=a*d,rhs=b*c;
  if (lhs==rhs) {
    return x.snd<y.snd;
  }
  else return lhs<rhs;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint(),b=rint();
  for (int i=1;i<=n;i++) {
    c[i]=rint(); d[i]=rint();
    if (i>=2) t[i]=rint();
  }
  int final=0;
  while(b>0) {
    vector<pair<pll,int> > v;
    for (int i=1;i<=n;i++) {
      if (used[i]) continue;
      ll sum=0;
      int denom=0;
      int x=i;
      while(1) {
        if (used[x]) break;
        denom++;
        sum+=c[x]-d[x];
        if (x==1) break;
        x=t[x];
      }
      v.PB(MP(MP(sum,(ll)denom),i));
    }
    sort(v.begin(),v.end(), cmp);
    bool change=0;
    for (auto &w:v) {
      ll sum=w.fst.fst;
      if (sum<=b) {
        b-=sum;
        change=true;
        final+=w.fst.snd;
        int x=w.snd;
        while(1) {
          if (used[x]) break;
          used[x]=true;
          if (x==1||used[x]) break;
          x=t[x];
        }
        break;
      }
    }
    if (!change) break;
  }
  printf("%d\n",final);
}
